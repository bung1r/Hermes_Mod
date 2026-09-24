#pragma once

#include <string>
#include <vector>
#include "il2cpp.hpp"
#include "log.hpp"
#include "hook.hpp"
#include <unordered_map>
#include <unordered_set>

namespace myosotis::testmod {


struct ClassCache {
    il2cpp::Il2CppClass* klass;
    std::unordered_map<std::string, il2cpp::Il2CppMethod*> methods;
    std::unordered_map<std::string, il2cpp::Il2CppField*> fields;

    il2cpp::Il2CppMethod* GetMethod(std::string methodName) {
        if (methods.contains(methodName)) {
            return methods[methodName];
        }

        MYO_LOG("HermesUtils", "Could not find method of class {} with name {}", il2cpp::class_get_name(klass), methodName);
        return nullptr;
    }

    il2cpp::Il2CppMethod* GetField(std::string fieldName) {
        if (methods.contains(fieldName)) {
            return methods[fieldName];
        }

        MYO_LOG("HermesUtils", "Could not find field of class {} with name {}", il2cpp::class_get_name(klass), fieldName);
        return nullptr;
    }

};

inline std::unordered_map<std::string, ClassCache> classes;


il2cpp::Il2CppObject* runtime_invoke(il2cpp::Il2CppMethod* method, il2cpp::Il2CppObject* obj, void** params);

ClassCache GetClass(std::string accessName);

il2cpp::Il2CppMethod* GetMethod(std::string methodName);

ClassCache* RegisterClassOnly(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name);

ClassCache RegisterClassFull(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name);

void CheckForSameParamDuplicates(std::unordered_map<std::string, il2cpp::Il2CppMethod*> &methods, std::unordered_map<std::string, int> &dupeSameParamMethods, std::string key, il2cpp::Il2CppMethod* method);
void RegisterAllMethods(ClassCache &classCache, int& mIndex);
void RegisterAllFields(ClassCache &classCache, int& fIndex);

// BASIC TYPES 

using BaseMethodType = void(*)(il2cpp::Il2CppObject*);
using BaseMethod1Void = void(*)(il2cpp::Il2CppObject*, void*);
using BaseMethod2Void = void(*)(il2cpp::Il2CppObject*, void*, void*);
using BaseMethod3Void = void(*)(il2cpp::Il2CppObject*, void*, void*, void*);
using BaseMethod4Void = void(*)(il2cpp::Il2CppObject*, void*, void*, void*, void*);

// UNBOXING STUFF
template <typename T>
T unbox(::myosotis::il2cpp::Il2CppObject* obj) {
    return *(T*)il2cpp::object_unbox(obj);
}

template <typename T>
std::vector<T> unbox_array_prim(::myosotis::il2cpp::Il2CppObject* obj) {
    if (!obj) return {};

    uintptr_t rawAddress = reinterpret_cast<uintptr_t>(obj);
    uint32_t length = *reinterpret_cast<uint32_t*>(rawAddress + 24);

    if (length == 0) return {};

    // 2. Get the pointer to where the data starts (offset 32 bytes/0x20)
    T* dataStart = reinterpret_cast<T*>(rawAddress + 32);

    // 3. Populate and return the vector
    return std::vector<T>(dataStart, dataStart + length);
}
std::string unbox_string(::myosotis::il2cpp::Il2CppObject* obj);
std::vector<::myosotis::il2cpp::Il2CppObject*> unbox_array_obj(::myosotis::il2cpp::Il2CppObject* obj);
std::vector<::myosotis::il2cpp::Il2CppObject*> unbox_list_obj(::myosotis::il2cpp::Il2CppObject* listObj);
  

std::string type_name(::myosotis::il2cpp::Il2CppType* t);


// QOL STUFF
::myosotis::il2cpp::Il2CppClass* get_return_class_from_method(::myosotis::il2cpp::Il2CppClass* klass, const char* name, int params);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_method(::myosotis::il2cpp::Il2CppMethod* method);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_field(::myosotis::il2cpp::Il2CppClass* klass, const char* name);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_field(::myosotis::il2cpp::Il2CppField* field);

il2cpp::Il2CppString* ToIl2CppStr(const char* str);

template<typename CastType, typename HookedFn>
CastType InstallHook(void* method, HookedFn hookedFn) {
    return reinterpret_cast<CastType>(
        hook::install_inline(method, reinterpret_cast<void*>(hookedFn))
    );
}

template <typename T>
void SetFieldInObj(il2cpp::Il2CppObject* obj, const char* name, T value) {
    il2cpp::Il2CppClass* objClass = il2cpp::object_get_class(obj);
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    il2cpp::field_set_value(obj, objField, value);
}

template <typename T>
void SetFieldInObj(il2cpp::Il2CppObject* obj, il2cpp::Il2CppClass* objClass, const char* name, T value) {
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    il2cpp::field_set_value(obj, objField, value);
}

template <typename T> // use for structs
T GetFieldInObj(il2cpp::Il2CppObject* obj, il2cpp::Il2CppClass* objClass, const char* name) {
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    T getObj;
    il2cpp::field_get_value(obj, objField, &getObj);
    return getObj;
}

template <typename T> // use for classes
T GetFieldInObjValue(il2cpp::Il2CppObject* obj, il2cpp::Il2CppClass* objClass, const char* name) {
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    il2cpp::Il2CppObject* getObj = nullptr;
    il2cpp::field_get_value(obj, objField, &getObj);
    return unbox<T>(getObj);
}

std::string GetFieldInObjStr(il2cpp::Il2CppObject* obj, il2cpp::Il2CppObject* objClass, const char* name);

}
