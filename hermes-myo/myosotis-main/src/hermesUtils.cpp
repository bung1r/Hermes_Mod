#include "hermesUtils.hpp"

#include "log.hpp"
#include "il2cpp.hpp"


#include <windows.h>
#include <string>
#include <string_view>
#include <cstdio>
#include <iostream>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>



namespace myosotis::testmod {

il2cpp::Il2CppObject* runtime_invoke(il2cpp::Il2CppMethod* method, il2cpp::Il2CppObject* obj, void** params) {
    void* exc = nullptr;
    if (!method) {
        MYO_LOG("HermesUtils", "Method cannot be found");
        return nullptr;
    }
    if (!obj) {
        MYO_LOG("HermesUtils", "Obj cannot be found");
        return nullptr;
    }

    il2cpp::Il2CppObject* returnObj = il2cpp::runtime_invoke(method, obj, params, &exc);

    if (exc) {
        MYO_LOG("HermesUtils", "Method {} experienced an exception", il2cpp::method_get_name(method));
        return nullptr;
    }
    
    return returnObj;
}

ClassCache GetClass(std::string accessName) {
    if (classes.contains(accessName)) {
        return classes[accessName];
    }

    MYO_LOG("HermesUtils", "Could not find ClassCache with access name {}", accessName);

    return ClassCache();
}



ClassCache* RegisterClassOnly(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name) {
    classes[accessName] = ClassCache(
        il2cpp::class_from_name(img, namespaze, name),
        {}
    );

    return &(classes[accessName]);
}

ClassCache RegisterClassFull(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name) {
    ClassCache* classCache = RegisterClassOnly(accessName, img, namespaze, name);
    int totalMethods = 0; int totalFields = 0;
    RegisterAllMethods(*classCache, totalMethods);
    RegisterAllFields(*classCache, totalFields);
    MYO_LOG("HermesUtils", "Registered Class {}, Access Name: {}, Methods: {}, Fields: {}", name, accessName, totalMethods, totalFields);
    return *classCache;
}

void CheckForSameParamDuplicates(std::unordered_map<std::string, il2cpp::Il2CppMethod*> &methods, std::unordered_map<std::string, int> &dupeSameParamMethods, std::string key, il2cpp::Il2CppMethod* method) {
    if (methods.contains(key)) {
        // add the dupe same param methods to the key
        if (!dupeSameParamMethods.contains(key)) {
            dupeSameParamMethods[key] = 0;
            il2cpp::Il2CppMethod* oldMethod = methods[key]; // get the old method
            std::string modifiedOldKey = std::format("{}I{}", key, dupeSameParamMethods[key]);
            dupeSameParamMethods[key] += 1;
            methods[modifiedOldKey] = oldMethod;
            // MYO_LOG("testmod", "Method: {}", modifiedOldKey);
        }

        // get the names of the new keys
        
        std::string modifiedNewKey = std::format("{}I{}", key, dupeSameParamMethods[key]);
        dupeSameParamMethods[key] += 1;

        // add the modified keys
        
        methods[modifiedNewKey] = method;
        // MYO_LOG("testmod", "Method: {}", modifiedNewKey);
    } else {
        methods[key] = method;
        // MYO_LOG("testmod", "Method: {}", key);
    }

}

void RegisterAllMethods(ClassCache &classCache, int& mIndex) {
    il2cpp::Il2CppClass* klass = classCache.klass;
    std::unordered_map<std::string, il2cpp::Il2CppMethod*> methods = {};
    std::unordered_map<std::string, int> dupeSameParamMethods = {};

    mIndex = 0;
    void* mIter = nullptr;
    while (auto* m = il2cpp::class_get_methods(klass, &mIter)) {
        const char* mName = il2cpp::method_get_name(m);
        std::string mNameStr = mName;
        if (methods.contains(mNameStr)) {
            
            // if there is a duplicate in the method name
            il2cpp::Il2CppMethod* oldMethod = methods[mNameStr];
            uint32_t oldMethodParams = il2cpp::method_get_param_count(oldMethod);
            uint32_t newMethodParams = il2cpp::method_get_param_count(m);

            if (oldMethodParams != newMethodParams) {
                // if they don't have same params, add _P[num] to send, make sure that isn't a duplicate either
                
                if (!dupeSameParamMethods.contains(mNameStr)) {
                    std::string modifiedOldKey = std::format("{}_P{}", mNameStr, oldMethodParams);
                    CheckForSameParamDuplicates(methods, dupeSameParamMethods, modifiedOldKey, oldMethod);
                }

                std::string modifiedNewKey = std::format("{}_P{}", mNameStr, newMethodParams);
                CheckForSameParamDuplicates(methods, dupeSameParamMethods, modifiedNewKey, m);
            } else {
                // they have the same params and name, so this key works for both
                std::string modifiedDupeKey = std::format("{}_P{}", mNameStr, oldMethodParams);

                if (!dupeSameParamMethods.contains(mNameStr)) {
                    CheckForSameParamDuplicates(methods, dupeSameParamMethods, modifiedDupeKey, oldMethod);
                }
                
                CheckForSameParamDuplicates(methods, dupeSameParamMethods, modifiedDupeKey, m);
            }


            dupeSameParamMethods[mNameStr] = 0;
        } else {
            methods[mNameStr] = m;
            // MYO_LOG("testmod", "Class: {}, Method: {}", klass, mNameStr);
        }
        
        mIndex++;
    }

    classCache.methods = methods;
}

void RegisterAllFields(ClassCache &classCache, int& fIndex) {
    il2cpp::Il2CppClass* klass = classCache.klass;
    std::unordered_map<std::string, il2cpp::Il2CppField*> fields = {};
    fIndex = 0;
    void* fIter = nullptr;
    while (auto* f = il2cpp::class_get_fields(klass, &fIter)) {
        const char* fName = il2cpp::field_get_name(f);
        fields[fName] = f; // no dupes, so just directly add. 
        fIndex++;
    }

    classCache.fields = fields;
}


std::string unbox_string(il2cpp::Il2CppObject* obj) {
    if (!obj) return "";

    // Cast the generic object to an Il2Cpp string pointer
    auto il2cppStr = reinterpret_cast<il2cpp::Il2CppString*>(obj);
    
    // Get the length of the string
    int length = il2cpp::string_length(il2cppStr);
    // MYO_LOG("testmod", "length = {}", length);
    if (length == 0) return "";

    // auto charstest = il2cpp::string_chars(il2cppStr);
    // MYO_LOG("testmod", "chars = {}", static_cast<const void*>(charstest));

    // Get a pointer to the raw UTF-16 character array
    const wchar_t* chars = reinterpret_cast<const wchar_t*>(il2cpp::string_chars(il2cppStr));

    // Convert the UTF-16 (wchar_t) string into a standard UTF-8 std::string
    std::wstring wstr(chars, length);
    return std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().to_bytes(wstr);
}

std::vector<il2cpp::Il2CppObject*> unbox_array_obj(il2cpp::Il2CppObject* obj) {
    if (!obj) return {};

    // 1. Read the array length (stored at offset 24 bytes/0x18 on 64-bit)
    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(obj);
    uint32_t length = *reinterpret_cast<uint32_t*>(rawAddress + 24);
    if (length == 0) return {};

    // 2. Get the pointer to where the array data starts (offset 32 bytes/0x20).
    // Because this array holds C# objects, it is a contiguous list of pointers.
    il2cpp::Il2CppObject** dataStart = reinterpret_cast<il2cpp::Il2CppObject**>(rawAddress + 32);

    // 3. Populate and return the vector of pointers
    return std::vector<il2cpp::Il2CppObject*>(dataStart, dataStart + length);
}
std::vector<il2cpp::Il2CppObject*> unbox_list_obj(il2cpp::Il2CppObject* listObj) {
    if (!listObj) return {};

    uintptr_t base = reinterpret_cast<uintptr_t>(listObj);

    // List<T>:
    //
    // +0x10 : _items (Il2CppArray*)
    // +0x18 : _size
    // +0x1C : _version
    //
    // Note: these offsets assume the standard IL2CPP List<T> layout
    // on 64-bit.

    auto* items = *reinterpret_cast<il2cpp::Il2CppArray**>(base + 0x10);

    int32_t size = *reinterpret_cast<int32_t*>(base + 0x18);

    if (!items || size <= 0) return {};

    // Array elements begin at +0x20.
    auto** data =
        reinterpret_cast<il2cpp::Il2CppObject**>(
        reinterpret_cast<uintptr_t>(items) + 0x20);

    std::vector<il2cpp::Il2CppObject*> result;
    result.reserve(size);

    for (int32_t i = 0; i < size; ++i) {
        result.push_back(data[i]);
    }

    return result;
}

std::string type_name(il2cpp::Il2CppType* t) {
    if (!t) return "object";
    const char* n = il2cpp::type_get_name(t);
    if (!n || !n[0]) return "object";
    return n;
}

il2cpp::Il2CppClass* get_return_class_from_method(il2cpp::Il2CppClass* klass, const char* name, int params) {
    il2cpp::Il2CppMethod* method = il2cpp::class_get_method_from_name(klass, name, params);
    il2cpp::Il2CppType* type = il2cpp::method_get_return_type(method);
    return il2cpp::class_from_type(type);
}

il2cpp::Il2CppClass* get_return_class_from_method(il2cpp::Il2CppMethod* method) {
    il2cpp::Il2CppType* type = il2cpp::method_get_return_type(method);
    return il2cpp::class_from_type(type);
}

il2cpp::Il2CppClass* get_return_class_from_field(il2cpp::Il2CppClass* klass, const char* name) {
    il2cpp::Il2CppField* field = il2cpp::class_get_field_from_name(klass, name);
    il2cpp::Il2CppType* type = il2cpp::field_get_type(field);
    return il2cpp::class_from_type(type);
}

il2cpp::Il2CppClass* get_return_class_from_field(il2cpp::Il2CppField* field) {
    il2cpp::Il2CppType* type = il2cpp::field_get_type(field);
    return il2cpp::class_from_type(type);
}

il2cpp::Il2CppString* ToIl2CppStr(const char* chars) {
    return il2cpp::string_new(chars);
}

std::string GetFieldInObjStr(il2cpp::Il2CppObject* obj, il2cpp::Il2CppObject* objClass, const char* name) {
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    il2cpp::Il2CppObject* getObj = nullptr;
    il2cpp::field_get_value(obj, objField, &getObj);
    return unbox_string(getObj);
}

}