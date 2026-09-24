#include "hermesLocalization.hpp"
#include "il2cpp.hpp"
#include "hermesStatic.hpp"
#include "hermesUtils.hpp"
#include "hermesUnity.hpp"
#include "hook.hpp"
#include "log.hpp"



namespace myosotis::testmod {

void hooked_JsonDataListPersonality_ctor(il2cpp::Il2CppObject* __this) {
    

    original_jsonDataListPersonality_ctor(__this);

    il2cpp::Il2CppType* objType = il2cpp::class_get_type(il2cpp::object_get_class(__this));
    
    if (objType == jsonDataListPersonalityType) {
        init_unity_main_thread(); // stupidest shit i've ever done btw. 
    }
    // MYO_LOG("testmod", "successfully initialized JsonDataListPersonality");
    il2cpp::Il2CppObject* personalityDict = nullptr;
    
    
}
void hooked_JsonDataListPersonality_InitLocal(il2cpp::Il2CppObject* __this, void* a, void* b) {
    original_jsonDataListPersonality_InitLocal(__this, a, b);
    // MYO_LOG("testmod", "Init Local");
}
void hooked_JsonDataListPersonality_InitRemote(il2cpp::Il2CppObject* __this, void* a, void* b, void* c, void* d) {
    MYO_LOG("testmod", "Init Remote 1");
    original_jsonDataListPersonality_InitRemote(__this, a, b, c, d);
    MYO_LOG("testmod", "Init Remote 2");
}
void hooked_JsonDataListPersonality_SetDictionary(il2cpp::Il2CppObject* __this, void* a, void* b) {
    original_jsonDataListPersonality_SetDictionary(__this, a, b);
    // MYO_LOG("testmod", "Set Dictionary 2");
    // MYO_LOG("testmod", "STEP 1 E");
    il2cpp::Il2CppType* objType = il2cpp::class_get_type(il2cpp::object_get_class(__this));
    
    if (objType == jsonDataListPersonalityType) {
        MYO_LOG("testmod", "Found a match: the type: {} jsonDataListPersonalityType: {}", type_name(objType), type_name(jsonDataListPersonalityType));
        il2cpp::Il2CppObject* dictObj = nullptr;
        
        il2cpp::field_get_value(__this, jsonDataListPersonality__dict, &dictObj);

        il2cpp::Il2CppClass* dictClass = il2cpp::object_get_class(dictObj);

        il2cpp::Il2CppMethod* dictAdd = il2cpp::class_get_method_from_name(dictClass, "Add", 2);

        if (dictObj) {
            il2cpp::Il2CppObject* textDataPersonalityObj = il2cpp::object_new(textDataPersonalityClass);
            il2cpp::runtime_invoke(il2cpp::class_get_method_from_name(textDataPersonalityClass, ".ctor", 0), textDataPersonalityObj, nullptr, nullptr);
            // SetFieldInObj(textDataPersonalityObj, "name", ToIl2CppStr("Faust"));

            SetFieldInObj(textDataPersonalityObj, textDataPersonalityClass, "id", ToIl2CppStr("10299"));
            std::string setIdString = GetFieldInObjStr(textDataPersonalityObj, textDataPersonalityClass, "id");
            MYO_LOG("testmod", "Id value: {}", setIdString);
            SetFieldInObj(textDataPersonalityObj, "name", ToIl2CppStr("Gregor"));
            SetFieldInObj(textDataPersonalityObj, "title", ToIl2CppStr("Brotherhood\nof Iron"));
            SetFieldInObj(textDataPersonalityObj, "desc", ToIl2CppStr("Gregor's forbidden ID"));
            SetFieldInObj(textDataPersonalityObj, "acquisitionMethod", ToIl2CppStr("Come to diddy's house and attend the party"));
            SetFieldInObj(textDataPersonalityObj, "skinItemTitle", ToIl2CppStr(""));
            SetFieldInObj(textDataPersonalityObj, "skinItemDesc", ToIl2CppStr(""));

            void* addParams[2];
            addParams[0] = ToIl2CppStr("10299");
            addParams[1] = textDataPersonalityObj;
            il2cpp::runtime_invoke(dictAdd, dictObj, addParams, nullptr);

            // MYO_LOG("testmod", "Please for the love of god 4");
        }


        int32_t id = 10101;
        void* testParams[1];
        testParams[0] = &id;

        il2cpp::Il2CppType* jsonDataListPersonality_GetDataParamType = il2cpp::method_get_param(jsonDataListPersonality_GetDataInt, 0);
        MYO_LOG("testmod", "type: {}", type_name(jsonDataListPersonality_GetDataParamType));
        

        il2cpp::Il2CppObject* textDataObj = il2cpp::runtime_invoke(jsonDataListPersonality_GetDataInt, __this, testParams, nullptr);

        il2cpp::Il2CppString* objName = il2cpp::runtime_invoke(textDataPersonality_GetNameWithTitle, textDataObj, nullptr, nullptr);

        std::string objNameStr = unbox_string(objName);

        MYO_LOG("testmod", "Obj Name: {}", objNameStr);
        MYO_LOG("testmod", "Name: {}", GetFieldInObjStr(textDataObj, textDataPersonalityClass, "name"));
        MYO_LOG("testmod", "Id: {}", GetFieldInObjStr(textDataObj, textDataPersonalityClass, "id"));
        MYO_LOG("testmod", "Desc: {}", GetFieldInObjStr(textDataObj, textDataPersonalityClass, "desc"));
        
    }
}

void init_localization(il2cpp::Il2CppImage* img, const char* namespaze) {
    // define all classes
    
    il2cpp::Il2CppClass* textDataSetClass = il2cpp::class_from_name(img, namespaze, "TextDataSet");

    // PERSONALITY 
    jsonDataListPersonalityClass = get_return_class_from_method(textDataSetClass, "get_PersonalityList", 0);
    MYO_LOG("testmod", "Type: {}", type_name(il2cpp::class_get_type(jsonDataListPersonalityClass)));
    MYO_LOG("testmod", "ClassName1: {}", il2cpp::class_get_name(il2cpp::type_get_class_or_element_class(il2cpp::class_get_type(jsonDataListPersonalityClass))));
    MYO_LOG("testmod", "ClassName2: {}", il2cpp::class_get_name(jsonDataListPersonalityClass));
    
    jsonDataListPersonalityType = il2cpp::class_get_type(jsonDataListPersonalityClass);
    jsonDataListPersonality__dict = il2cpp::class_get_field_from_name(jsonDataListPersonalityClass, "_dic");
    jsonDataListPersonality_GetList = il2cpp::class_get_method_from_name(jsonDataListPersonalityClass, "GetList", 0);
    jsonDataListPersonality_ctor = il2cpp::class_get_method_from_name(jsonDataListPersonalityClass, ".ctor", 0);
    jsonDataListPersonality_InitLocal = il2cpp::class_get_method_from_name(jsonDataListPersonalityClass, "InitLocal", 2);
    jsonDataListPersonality_InitRemote = il2cpp::class_get_method_from_name(jsonDataListPersonalityClass, "InitRemote", 4);
    jsonDataListPersonality_SetDictionary = il2cpp::class_get_method_from_name(jsonDataListPersonalityClass, "SetDictionary", 2);
    // if (!jsonDataListPersonality__dict) MYO_LOG("testmod", "the dihh doesn't exist");
    textDataPersonalityClass = il2cpp::class_from_name(img, namespaze, "TextData_Personality");
    textDataPersonality_GetName = il2cpp::class_get_method_from_name(textDataPersonalityClass, "GetName", 0);
    textDataPersonality_GetNameWithTitle = il2cpp::class_get_method_from_name(textDataPersonalityClass, "GetNameWithTitle", 0);
    
    int mIndex = 0;
    void* mIter = nullptr;
    while (auto* m = il2cpp::class_get_methods(jsonDataListPersonalityClass, &mIter)) {

        if (mIndex == 6) {
            jsonDataListPersonality_GetDataInt = m;
        } else if (mIndex == 7) {
            jsonDataListPersonality_GetDataStr = m;
        }

        mIndex++;
    }

    original_jsonDataListPersonality_ctor = reinterpret_cast<BaseMethodType>(
        hook::install_inline(jsonDataListPersonality_ctor, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_ctor)));
    original_jsonDataListPersonality_InitLocal = reinterpret_cast<BaseMethod2Void>(
        hook::install_inline(jsonDataListPersonality_InitLocal, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_InitLocal)));
    // original_jsonDataListPersonality_InitRemote = reinterpret_cast<BaseMethod4Void>(
    //     hook::install_inline(jsonDataListPersonality_InitRemote, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_InitRemote)));
    original_jsonDataListPersonality_SetDictionary = reinterpret_cast<BaseMethod2Void>(
        hook::install_inline(jsonDataListPersonality_SetDictionary, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_SetDictionary)));
    
    // EGO

    // ENEMIES


}

}