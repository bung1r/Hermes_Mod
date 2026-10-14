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
    // if (!obj) {
    //     MYO_LOG("HermesUtils", "Obj cannot be found");
    //     return nullptr;
    // } // I forget static functions exist.

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

    return {};
}

ClassCache& GetClassRef(std::string accessName) {
    if (classes.contains(accessName)) {
        return classes[accessName];
    }

    MYO_LOG("HermesUtils", "Could not find ClassCache with access name {}", accessName);

    return classes["fallback"];
}

ClassCache* GetClassPtr(std::string accessName) {
    if (classes.contains(accessName)) {
        return &classes[accessName];
    }

    MYO_LOG("HermesUtils", "Could not find ClassCache with access name {}", accessName);

    return nullptr;
}

ClassCache RegisterClassOnly(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name) {
    il2cpp::Il2CppClass* klass = il2cpp::class_from_name(img, namespaze, name);
    if (!klass) {
        MYO_LOG("HermesUtils", "Class of {}.{}, with access name {} does not exist", namespaze, name, accessName);
        return {};
    }
    classes[accessName] = ClassCache(
        klass,
        il2cpp::class_is_valuetype(klass),
        {},
        {}
    );

    return classes[accessName];
}

ClassCache RegisterClassOnly(il2cpp::Il2CppClass* klass, std::string accessName) {
    if (!klass) {
        MYO_LOG("HermesUtils", "Class with access name {} does not exist", accessName);
        return {};
    }
    classes[accessName] = ClassCache(
        klass,
        il2cpp::class_is_valuetype(klass),
        {},
        {}
    );

    return classes[accessName];
}

ClassCache* RegisterClassOnlyPtr(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name) {
    il2cpp::Il2CppClass* klass = il2cpp::class_from_name(img, namespaze, name);
    if (!klass) {
        MYO_LOG("HermesUtils", "Class of {}.{}, with access name {} does not exist", namespaze, name, accessName);
        return nullptr;
    }
    classes[accessName] = ClassCache(
        klass,
        il2cpp::class_is_valuetype(klass),
        {},
        {}
    );

    return &(classes[accessName]);
}

ClassCache* RegisterClassOnlyPtr(il2cpp::Il2CppClass* klass, std::string accessName) {
    if (!klass) {
        MYO_LOG("HermesUtils", "Class with access name {} does not exist", accessName);
        return nullptr;
    }
    classes[accessName] = ClassCache(
        klass,
        il2cpp::class_is_valuetype(klass),
        {},
        {}
    );

    return &(classes[accessName]);
}

ClassCache RegisterClassFull(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name) {
    ClassCache* classCache = RegisterClassOnlyPtr(accessName, img, namespaze, name);
    if (!classCache) {
        MYO_LOG("HermesUtils", "Could not register class fully");
        return ClassCache();
    }
    int totalMethods = 0; int totalFields = 0;
    RegisterAllMethods(*classCache, totalMethods);
    RegisterAllFields(*classCache, totalFields);
    MYO_LOG("HermesUtils", "Registered Class {}, Access Name: {}, Methods: {}, Fields: {}", name, accessName, totalMethods, totalFields);
    return *classCache;
}

ClassCache RegisterClassFull(il2cpp::Il2CppClass* klass, std::string accessName) {
    ClassCache* classCache = RegisterClassOnlyPtr(klass, accessName);
    if (!classCache) {
        MYO_LOG("HermesUtils", "Could not register class fully");
        return ClassCache();
    }
    int totalMethods = 0; int totalFields = 0;
    RegisterAllMethods(*classCache, totalMethods);
    RegisterAllFields(*classCache, totalFields);
    MYO_LOG("HermesUtils", "Access Name: {}, Methods: {}, Fields: {}", accessName, totalMethods, totalFields);
    return *classCache;
}

// Too lazy to implement this right now
void RegisterMethod(std::string className, const char* methodName, int argsCount, int index) {
    if (!classes.contains(className)) {
        MYO_LOG("HermesUtils", "Could not find className of {}", className);
    }


    ClassCache* classC = GetClassPtr(className);
    std::string accessName = methodName;
    il2cpp::Il2CppMethod* method = nullptr;
    if (index == 0) {
        method = il2cpp::class_get_method_from_name(classC->klass, methodName, argsCount);
        if (classC->methods.contains(accessName)) accessName = std::format("{}_P{}", accessName, argsCount);
        if (classC->methods.contains(accessName)) accessName = std::format("{}I{}", accessName, index);
        classC->methods[accessName] = method;
    } else {
        ClassCache* classC = GetClassPtr(className);
        int mIndex = 0;
        int currentIndex = 0;
        void* mIter = nullptr;
        while (auto* m = il2cpp::class_get_methods(classC->klass, &mIter)) {
            const char* mName = il2cpp::method_get_name(m);
            std::string mNameStr = mName;
            if (mNameStr == methodName) {
                if (currentIndex == index) {
                    
                }
                currentIndex++;
            }
        }   
            
    }


}
void RegisterField(std::string className, const char* fieldName) {

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
    // MYO_LOG("HermesUtils", "length = {}", length);
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

il2cpp::Il2CppMethod* InflateGenericMethod(il2cpp::Il2CppMethod* genericMethod, const std::vector<il2cpp::Il2CppClass*>& genericArguments) {
    // Get the managed reflection method.
    il2cpp::Il2CppObject* reflectionMethod =
        il2cpp::method_get_object(genericMethod, nullptr);

    // Resolve System.Type.
    ClassCache& SystemType = GetClassRef("System.Type");
    il2cpp::Il2CppClass* systemTypeClass = SystemType.klass;
        /* Resolve System.Type */;

    // Populate generic arguments.
    std::vector<il2cpp::Il2CppObject*> typeObjects;

    for (il2cpp::Il2CppClass* genericArgument : genericArguments) {
        typeObjects.push_back(
            il2cpp::type_get_object(
                il2cpp::class_get_type(genericArgument)
            )
        );
    }

    il2cpp::Il2CppArray* typeArgs = il2cpp::array_new(systemTypeClass, typeObjects.size());
    SetArrayElements(typeArgs, typeObjects, 0x20);

    // Resolve MethodInfo.MakeGenericMethod(Type[]).
    ClassCache& methodInfoClassC = GetClassRef("Reflection.MethodInfo");
    il2cpp::Il2CppObject* constructedMethod = methodInfoClassC.Invoke("MakeGenericMethod", reflectionMethod, typeArgs);

    if (!constructedMethod) {
        MYO_LOG("HermesUtils", "Method unsuccesfully constructed");
        return nullptr;
    }

    // Convert back to native method metadata.
    il2cpp::Il2CppMethod* inflatedMethod = il2cpp::method_get_from_reflection(constructedMethod);
    MYO_LOG("HermesUtils", "Method {} successfully inflated", il2cpp::method_get_name(inflatedMethod));
    return inflatedMethod;
}

void init_utils(il2cpp::Il2CppAssembly** asms) {
    classes["fallback"] = {};

    const int ASSEMBLY_C_SHARP_INDEX = 0; 
    const int MSCORLIB_INDEX = 1;
    const int UNITYCORE_INDEX = 3;
    const int JSON_INDEX = 18;
    const int UNITYUI_INDEX = 22;
    il2cpp::Il2CppImage* img = il2cpp::assembly_get_image(asms[ASSEMBLY_C_SHARP_INDEX]); 
    il2cpp::Il2CppImage* mscorlibImg = il2cpp::assembly_get_image(asms[MSCORLIB_INDEX]); 
    il2cpp::Il2CppImage* unityCoreImg = il2cpp::assembly_get_image(asms[UNITYCORE_INDEX]); 
    il2cpp::Il2CppImage* jsonImg = il2cpp::assembly_get_image(asms[JSON_INDEX]);
    il2cpp::Il2CppImage* unityUIImg = il2cpp::assembly_get_image(asms[UNITYUI_INDEX]);

    RegisterClassFull("System.Type", mscorlibImg, "System", "Type");
    ClassCache ReflectionMethodInfo = RegisterClassFull("Reflection.MethodInfo", mscorlibImg, "System.Reflection", "RuntimeMethodInfo");
    // MakeGenericMethodObj = il2cpp::object_new(ReflectionMethodInfo.klass);
    // ReflectionMethodInfo.Invoke(".ctor", MakeGenericMethodObj);
}

}