#pragma once

#include <string>
#include <vector>
#include "il2cpp.hpp"
#include "log.hpp"
#include "hook.hpp"
#include <unordered_map>
#include <unordered_set>
#include <any>

namespace myosotis::testmod {

// UNBOXING STUFF
template <typename T>
T unbox(::myosotis::il2cpp::Il2CppObject* obj) {
    return *(T*)il2cpp::object_unbox(obj);
}
std::string unbox_string(::myosotis::il2cpp::Il2CppObject* obj);

il2cpp::Il2CppObject* runtime_invoke(il2cpp::Il2CppMethod* method, il2cpp::Il2CppObject* obj, void** params);

template<typename CastType, typename HookedFn>
CastType InstallHook(void* method, HookedFn hookedFn) {
    return reinterpret_cast<CastType>(
        hook::install_inline(method, reinterpret_cast<void*>(hookedFn))
    );
}

template <typename T> // use for structs, for il2cpp::Il2CppObjects in classes
T GetFieldInObj(il2cpp::Il2CppObject* obj, il2cpp::Il2CppClass* objClass, const char* name) {
    il2cpp::Il2CppField* objField = il2cpp::class_get_field_from_name(objClass, name);
    T getObj;
    il2cpp::field_get_value(obj, objField, &getObj);
    return getObj;
}

template <typename T>
T GetFieldInObjDirect(il2cpp::Il2CppObject* obj, il2cpp::Il2CppClass* objField) {
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

template <typename T> // use for classes
T GetFieldInObjUnbox(il2cpp::Il2CppObject* obj, il2cpp::Il2CppField* objField) {
    il2cpp::Il2CppObject* getObj = nullptr;
    il2cpp::field_get_value(obj, objField, &getObj);
    return unbox<T>(getObj);
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

template <typename T>
void SetFieldInObj(il2cpp::Il2CppObject* obj, il2cpp::Il2CppField* objField, T value) {
    il2cpp::field_set_value(obj, objField, value);
}


// the GOAT by the way
struct ClassCache {
    il2cpp::Il2CppClass* klass;
    bool isStruct;
    std::unordered_map<std::string, il2cpp::Il2CppMethod*> methods;
    std::unordered_map<std::string, il2cpp::Il2CppField*> fields;
    std::unordered_map<std::string, std::any> original_methods; // when hooked, original methods are stored here.

    il2cpp::Il2CppMethod* GetMethod(std::string methodName) {
        if (methods.contains(methodName)) {
            return methods[methodName];
        }

        MYO_LOG("HermesUtils", "Could not find method of class {} with name {}", il2cpp::class_get_name(klass), methodName);
        return nullptr;
    }

    il2cpp::Il2CppMethod* GetField(std::string fieldName) {
        if (fields.contains(fieldName)) {
            return fields[fieldName];
        }

        MYO_LOG("HermesUtils", "Could not find field of class {} with name {} for GetField", il2cpp::class_get_name(klass), fieldName);
        return nullptr;
    }

    template<typename... Args>
    il2cpp::Il2CppObject* Invoke(const char* methodName, il2cpp::Il2CppObject* obj, Args... args) {
        if (!methods.contains(methodName)) {
            MYO_LOG("HermesUtils", "Could not find method of class {} with name {} for Invoke", il2cpp::class_get_name(klass), methodName);
            return nullptr;
        }

        // get the method and process params
        il2cpp::Il2CppMethod* method = GetMethod(methodName);
        size_t argCount = sizeof...(Args);
        int paramIndex = 0;
        void* params[] = { args... };

        // Structs need to be unboxed before runtime_invoke
        if (isStruct) {
            il2cpp::Il2CppObject* unboxedStruct = nullptr;
            if (obj) unboxedStruct = il2cpp::object_unbox(obj);
            return runtime_invoke(method, unboxedStruct, params);
        } else {
            return runtime_invoke(method, obj, params);
        }
    }

    template<typename T, typename... Args>
    T InvokeUnbox(const char* methodName, il2cpp::Il2CppObject* obj, Args... args) {
        il2cpp::Il2CppObject* newObj = Invoke(methodName, obj, args...);
        return unbox<T>(newObj);
    }

    template<typename T>
    void Set(il2cpp::Il2CppObject* obj, const char* fieldName, T value) {
        if (isStruct) {
            il2cpp::Il2CppObject* unboxedStruct = nullptr;
            if (obj) unboxedStruct = il2cpp::object_unbox(obj);
            SetFieldInObj(unboxedStruct, GetField(fieldName), value);
        } else {
            MYO_LOG("HermesUtils", "Set 1");
            SetFieldInObj(obj, GetField(fieldName), value);
        }
    }
    
    template<typename T>
    T Get(il2cpp::Il2CppObject* obj, const char* fieldName) {
        if (isStruct) {
            return GetFieldInObjDirect<T>(obj, GetField(fieldName));
        } else {
            // since it's il2cpp object, do not unbox it. 
            if constexpr (std::is_same_v<T, il2cpp::Il2CppObject*>) {
                return GetFieldInObjDirect<T>(obj, GetField(fieldName));
            } else if constexpr (std::is_same_v<T, std::string>) {
                il2cpp::Il2CppString* strObj = GetFieldInObjDirect<il2cpp::Il2CppString*>(obj, GetField(fieldName));
                return unbox_string(strObj);
            } else {
                return GetFieldInObjUnbox<T>(obj, GetField(fieldName));
            }
        }
    }



    template<typename CastType, typename HookedFn>
    CastType InstallHook(const char* methodName, HookedFn hookedFn) {
        il2cpp::Il2CppMethod* method = GetMethod(methodName);
        CastType orig =  reinterpret_cast<CastType>(
            hook::install_inline(method, reinterpret_cast<void*>(hookedFn))
        );
        original_methods[methodName] = orig; // add the pointer to original method here
        return orig;
    }

    template<typename CastType>
    CastType GetOrigMethod(const char* methodName) {
        if (original_methods.contains(methodName)) return original_methods[methodName];
        MYO_LOG("HermesUtils", "Could not field orig method of {}. Check if you have hooked {} yet.", methodName, methodName);
        return nullptr;
    }

    void AddMethod(il2cpp::Il2CppMethod* method, std::string accessName) {
        methods[accessName] = method;
    }
};

inline std::unordered_map<std::string, ClassCache> classes;

// custom ids for ids egos and skills
inline std::unordered_set<int32_t> customIDs;
inline std::unordered_set<int32_t> customEGOs;
inline std::unordered_set<int32_t> customSkills;

ClassCache GetClass(std::string accessName);

ClassCache GetOrRegisterClass(std::string accessName, bool registerFully=false);

ClassCache& GetClassRef(std::string accessName);


il2cpp::Il2CppMethod* GetMethod(std::string methodName);



ClassCache RegisterClassOnly(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name);

ClassCache RegisterClassOnly(il2cpp::Il2CppClass* klass, std::string accessName);

ClassCache* RegisterClassOnlyPtr(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name);

ClassCache* RegisterClassOnlyPtr(il2cpp::Il2CppClass* klass, std::string accessName);

ClassCache RegisterClassFull(std::string accessName, il2cpp::Il2CppImage* img, const char* namespaze, const char* name);

ClassCache RegisterClassFull(il2cpp::Il2CppClass* klass, std::string accessName);

void CheckForSameParamDuplicates(std::unordered_map<std::string, il2cpp::Il2CppMethod*> &methods, std::unordered_map<std::string, int> &dupeSameParamMethods, std::string key, il2cpp::Il2CppMethod* method);
void RegisterAllMethods(ClassCache &classCache, int& mIndex);
void RegisterAllFields(ClassCache &classCache, int& fIndex);
void RegisterMethod(std::string className, const char* methodName, int argsCount, int index = 0);
void RegisterField(std::string className, const char* fieldName);

// BASIC TYPES 

using BaseMethodType = void(*)(il2cpp::Il2CppObject*);
using BaseMethod1Void = void(*)(il2cpp::Il2CppObject*, void*);
using BaseMethod2Void = void(*)(il2cpp::Il2CppObject*, void*, void*);
using BaseMethod3Void = void(*)(il2cpp::Il2CppObject*, void*, void*, void*);
using BaseMethod4Void = void(*)(il2cpp::Il2CppObject*, void*, void*, void*, void*);

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
std::vector<::myosotis::il2cpp::Il2CppObject*> unbox_array_obj(::myosotis::il2cpp::Il2CppObject* obj);
std::vector<::myosotis::il2cpp::Il2CppObject*> unbox_list_obj(::myosotis::il2cpp::Il2CppObject* listObj);
  

std::string type_name(::myosotis::il2cpp::Il2CppType* t);


// QOL STUFF
::myosotis::il2cpp::Il2CppClass* get_return_class_from_method(::myosotis::il2cpp::Il2CppClass* klass, const char* name, int params);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_method(::myosotis::il2cpp::Il2CppMethod* method);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_field(::myosotis::il2cpp::Il2CppClass* klass, const char* name);
::myosotis::il2cpp::Il2CppClass* get_return_class_from_field(::myosotis::il2cpp::Il2CppField* field);

il2cpp::Il2CppString* ToIl2CppStr(const char* str);
template <typename T>
void SetArrayElements(il2cpp::Il2CppArray* array, const std::vector<T*>& elements, size_t dataOffset) {
    if (!array) {
        MYO_LOG("HermesUtils", "Array does not exist");
        return;
    }

    auto* data = reinterpret_cast<std::byte*>(array) + dataOffset;
    
    for (size_t i = 0; i < elements.size(); ++i) {
        *reinterpret_cast<T**>(
            data + i * sizeof(T*)
        ) = elements[i];
    }
}
il2cpp::Il2CppMethod* InflateGenericMethod(il2cpp::Il2CppMethod* genericMethod, const std::vector<il2cpp::Il2CppClass*>& genericArguments);

std::string GetFieldInObjStr(il2cpp::Il2CppObject* obj, il2cpp::Il2CppObject* objClass, const char* name);

void init_utils(il2cpp::Il2CppAssembly** asms);

}
