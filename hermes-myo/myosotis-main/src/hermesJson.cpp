#include "il2cpp.hpp"
#include "hermesJson.hpp"
#include "log.hpp"
#include "hook.hpp"
#include "hermesStatic.hpp"
#include "hermesUtils.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>



namespace myosotis::testmod {

BaseMethod1Void original_StringStaticDataJson_ctor = nullptr;
BaseMethod1Void original_StringStaticDataJson_AddData = nullptr;

void hooked_StringStaticDataJson_AddData(il2cpp::Il2CppObject* __this, void* text) {
    original_StringStaticDataJson_AddData(__this, text);
    std::string dataClassStr = unbox_string(il2cpp::runtime_invoke(stringStaticDataJson_GetDataClass, __this, nullptr, nullptr));
    if (dataClassStr == "personality") {
        // MYO_LOG("testmod", "String: {}", unbox_string(text));
    }
}

void hooked_StringStaticDataJson_ctor(il2cpp::Il2CppObject* __this, void* dataClass) {
    original_StringStaticDataJson_ctor(__this, dataClass);

    std::string dataClassStr = unbox_string(il2cpp::runtime_invoke(stringStaticDataJson_GetDataClass, __this, nullptr, nullptr));
    int32_t count = unbox<int32_t>(il2cpp::runtime_invoke(stringStaticDataJson_GetCount, __this, nullptr, nullptr));

    if (dataClassStr == "personality") {
        std::ifstream file("hermesMod/data/personality.json");
        if (!file.is_open()) MYO_LOG("testmod", "Failed to open file. Oops!");

        // Read all characters into a stringstream buffer
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string jsonStr = buffer.str();

        hooked_StringStaticDataJson_AddData(__this, ToIl2CppStr(jsonStr.c_str()));
        MYO_LOG("testmod", "data class: {}, count: {}", dataClassStr, count);

    }
}
void init_json(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* jsonImg) {
    // init lists


    // THEY FUCKING CHANGED IT WHY WHY WHY??!?!?!??!

    il2cpp::Il2CppType* csJsonNodeListType = il2cpp::method_get_param(personalityStaticDataList_Init, 0);
    csJsonNodeListClass = il2cpp::class_from_type(csJsonNodeListType);
    csJsonNodeList_Add = il2cpp::class_get_method_from_name(csJsonNodeListClass, "Add", 1);
    csJsonNodeList_getItem = il2cpp::class_get_method_from_name(csJsonNodeListClass, "get_Item", 1);
    csJsonNodeList_getCount = il2cpp::class_get_method_from_name(csJsonNodeListClass, "get_Count", 0);

    stringStaticDataJsonClass = il2cpp::class_from_name(img, "LimbusCompany.StaticDataLibs", "StringStaticDataJson");
    if (!stringStaticDataJsonClass) MYO_LOG("testmod", "could not find stringstaticdatajson");

    stringStaticDataJson_ctor = il2cpp::class_get_method_from_name(stringStaticDataJsonClass, ".ctor", 1);
    stringStaticDataJson_GetDataClass = il2cpp::class_get_method_from_name(stringStaticDataJsonClass, "GetDataClass", 0);
    stringStaticDataJson_GetCount = il2cpp::class_get_method_from_name(stringStaticDataJsonClass, "GetCount", 0);
    stringStaticDataJson_AddData = il2cpp::class_get_method_from_name(stringStaticDataJsonClass, "AddData", 1);

    original_StringStaticDataJson_ctor = reinterpret_cast<BaseMethod1Void>(
        hook::install_inline(stringStaticDataJson_ctor, reinterpret_cast<void*>(&hooked_StringStaticDataJson_ctor)));
    original_StringStaticDataJson_AddData = reinterpret_cast<BaseMethod1Void>(
        hook::install_inline(stringStaticDataJson_AddData, reinterpret_cast<void*>(&hooked_StringStaticDataJson_AddData)));
    
    
    // MYO_LOG("testmod", "type: {} param name: {}", type_name(csJsonNodeListType), il2cpp::method_get_param_name(personalityStaticDataList_Init, 0));
    // if (!csJsonNodeListType) MYO_LOG("testmod", "csJsonNodeListType not existt");
    // if (!csJsonNodeListClass) MYO_LOG("testmod", "csJsonNodeListClass not existt");
    // if (!csJsonNodeList_Add) MYO_LOG("testmod", "csJsonNodeList_Add not existt");
    // if (!csJsonNodeList_getItem) MYO_LOG("testmod", "csJsonNodeList_getItem not existt");
    // if (!csJsonNodeList_getCount) MYO_LOG("testmod", "csJsonNodeList_getCount not existt");

    MYO_LOG("testmod", "eee");
    
    // init JSON node (the world is pain and suffering)
    
    il2cpp::Il2CppClass* getJsonNodeClass = il2cpp::class_from_name(img, namespaze, "LoginModel");
    il2cpp::Il2CppMethod* getJsonNodeMethod = il2cpp::class_get_method_from_name(getJsonNodeClass, "GetJsonData", 0);
    il2cpp::Il2CppType* jsonNodeType = il2cpp::method_get_return_type(getJsonNodeMethod);
    jsonNodeClass = il2cpp::class_from_type(jsonNodeType);
    jsonNode_Parse = il2cpp::class_get_method_from_name(jsonNodeClass, "Parse", 1);
    jsonNode_Add1 = il2cpp::class_get_method_from_name(jsonNodeClass, "Add", 1);
    jsonNode_Add2 = il2cpp::class_get_method_from_name(jsonNodeClass, "Add", 2);
    jsonNode_ToString = il2cpp::class_get_method_from_name(jsonNodeClass, "ToString", 0);
    jsonNode_getAsByteList = il2cpp::class_get_method_from_name(jsonNodeClass, "get_AsByteList", 0);
    
    il2cpp::Il2CppMethod* jsonNode_getAsArray = il2cpp::class_get_method_from_name(jsonNodeClass, "get_AsArray", 0);
    il2cpp::Il2CppType* jsonArrayType = il2cpp::method_get_return_type(jsonNode_getAsArray);
    jsonArrayClass = il2cpp::class_from_type(jsonArrayType);

    il2cpp::Il2CppMethod* jsonNode_getAsObject = il2cpp::class_get_method_from_name(jsonNodeClass, "get_AsObject", 0);
    il2cpp::Il2CppType* jsonObjectType = il2cpp::method_get_return_type(jsonNode_getAsObject);
    jsonObjectClass = il2cpp::class_from_type(jsonObjectType);

    int mIndex = 0;
    void* mIter = nullptr;
    while (auto* m = il2cpp::class_get_methods(jsonArrayClass, &mIter)) {
        if (mIndex == 5) {
            jsonNode_getItemIndex = m;
            const char* mpn = il2cpp::method_get_name(m);
            MYO_LOG("testmod", "m = {}", mpn);
        } else if (mIndex == 9) {
            jsonNode_getCount = m;
            const char* mpn = il2cpp::method_get_name(m);
            MYO_LOG("testmod", "m = {}", mpn);
        }

        mIndex++;
    }

    mIndex = 0;
    void* m2Iter = nullptr;
    while (auto* m = il2cpp::class_get_methods(jsonObjectClass, &m2Iter)) {
        if (mIndex == 5) {
            jsonNode_getItemKey = m;
            const char* mpn = il2cpp::method_get_name(m);
            MYO_LOG("testmod", "m = {}", mpn);
        }

        

        mIndex++;
    }

    // jsonNode_getCount = il2cpp::class_get_method_from_name(jsonNodeClass, "get_Count", 0);
    jsonNode_getAsInt = il2cpp::class_get_method_from_name(jsonNodeClass, "get_AsInt", 0);
    
    // INIT JSON SERIALIZER
    jsonSerializerClass = il2cpp::class_from_name(jsonImg, "System.Text.Json", "JsonSerializer");
    jsonSerializer_Serialize = il2cpp::class_get_method_from_name(jsonSerializerClass, "Serialize", 2);
}

}