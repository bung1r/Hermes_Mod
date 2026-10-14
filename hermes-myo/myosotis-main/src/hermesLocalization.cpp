#include "hermesLocalization.hpp"
#include "il2cpp.hpp"
#include "hermesStatic.hpp"
#include "hermesUtils.hpp"
#include "hermesUnity.hpp"
#include "hook.hpp"
#include "log.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <filesystem>


namespace fs = std::filesystem;
namespace myosotis::testmod {

std::string extractLowerSuffix(const std::string& input)
{
    const std::string prefix = "TextData_";

    size_t start = input.find(prefix);
    if (start == std::string::npos)
        return {};

    start += prefix.size();

    size_t end = input.find('>', start);
    if (end == std::string::npos)
        return {};

    std::string result = input.substr(start, end - start);

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return result;
}
std::string get_text_between_brackets(const std::string& str) {
    // Find the positions of the opening and closing brackets
    size_t start = str.find('<');
    size_t end = str.find('>');

    // Validate that both brackets exist and are in the correct order
    if (start == std::string::npos || end == std::string::npos || start >= end) {
        return "";
    }

    // Calculate the start position of the inner text and its length
    size_t text_start = start + 1;
    size_t length = end - text_start;

    return str.substr(text_start, length);
}

template <typename T>
T ProcessNodeInNode(il2cpp::Il2CppObject* node, const char* field) {
    if (!node) {
        MYO_LOG("HermesLocal", "Node cannot be processed");
        return {};
    }
    MYO_LOG("HermesLocal", "ProcessNodeInNode 1");
    ClassCache& JsonNodeC = GetClassRef("JsonNode");
    ClassCache& JsonObjectC = GetClassRef("JsonObject");
    bool hasField = JsonObjectC.InvokeUnbox<bool>("HasKey", node, ToIl2CppStr(field));
    if (hasField) {
        MYO_LOG("HermesLocal", "ProcessNodeInNodeField Exists");
    } else {
        MYO_LOG("HermesLocal", "ProcessNodeInNode No Exist");
    }
    il2cpp::Il2CppObject* fieldNode = JsonObjectC.Invoke("get_Item", node, ToIl2CppStr(field));
    
    MYO_LOG("HermesLocal", "ProcessNodeInNode 2 {}", fieldNode);
    if constexpr (std::is_same_v<T, std::string>) {
        ClassCache& JsonStringC = GetClassRef("JsonString");
        il2cpp::Il2CppString* str = JsonStringC.Invoke("get_Value", fieldNode, nullptr);
        return unbox_string(str);
    } else if constexpr (std::is_same_v<T, int32_t> || std::is_same_v<T, int>) {
        ClassCache& JsonNumberC = GetClassRef("JsonNumber");
        return JsonNumberC.InvokeUnbox<T>("get_AsInt", fieldNode);
    } else if constexpr (std::is_same_v<T, bool>) {
        ClassCache& JsonBooleanC = GetClassRef("JsonBoolean");
        return JsonBooleanC.InvokeUnbox<T>("get_AsBool", fieldNode);
    } else if constexpr (std::is_same_v<T, double>) {
        ClassCache& JsonNumberC = GetClassRef("JsonNumber");
        return JsonNumberC.InvokeUnbox<T>("get_AsDouble", fieldNode);
    } else if constexpr (std::is_same_v<T, float>) {
        ClassCache& JsonNumberC = GetClassRef("JsonNumber");
        return JsonNumberC.InvokeUnbox<T>("get_AsFloat", fieldNode);
    } else if constexpr (std::is_same_v<T, long>) {
        ClassCache& JsonNumberC = GetClassRef("JsonNumber");
        return JsonNumberC.InvokeUnbox<T>("get_AsLong", fieldNode);
    } else if constexpr (std::is_same_v<T, il2cpp::Il2CppString*>) {
        ClassCache& JsonStringC = GetClassRef("JsonString");
        il2cpp::Il2CppString* stringValue = JsonStringC.Invoke("get_Value", fieldNode);
        MYO_LOG("HermesLocal", "ProcessNodeInNode 3 {}", stringValue);
        return JsonStringC.Invoke("get_Value", fieldNode);
    }
}

il2cpp::Il2CppObject* hooked_ctorQuick(il2cpp::Il2CppObject* __this) {  
    return original_ctorQuick(__this);
}

il2cpp::Il2CppObject* hooked_IConverter_GetLocalInitializer(il2cpp::Il2CppObject* __this, il2cpp::Il2CppString* localizeFolderPath, il2cpp::Il2CppObject* list, il2cpp::Il2CppString* lang) {
    il2cpp::Il2CppObject* root = original_IConverter_GetLocalInit(__this, localizeFolderPath, list, lang);
    MYO_LOG("HermesLocal", "I hope to god that this root exists, man");
    return root;
}

void hooked_JsonDataListPersonality_ctor(il2cpp::Il2CppObject* __this) {
    

    original_jsonDataListPersonality_ctor(__this);

    il2cpp::Il2CppType* objType = il2cpp::class_get_type(il2cpp::object_get_class(__this));
    
    if (objType == jsonDataListPersonalityType) {
        init_unity_main_thread(); // stupidest shit i've ever done btw. 
        ClassCache& IConverterUtils = GetClassRef("IConverterUtils");
        ClassCache& TextData_Personality = GetClassRef("TextData_Personality");

        il2cpp::Il2CppMethod* GetLocal_TextDataPersonality = InflateGenericMethod(
        IConverterUtils.GetMethod("GetLocalJsonPath"),  {TextData_Personality.klass});
        IConverterUtils.AddMethod(GetLocal_TextDataPersonality, "GetLocal_TextDataPersonality");
        MYO_LOG("HermesLocal", "Inflated method return type: {}", type_name(il2cpp::method_get_return_type(GetLocal_TextDataPersonality)));
        il2cpp::Il2CppObject* rootObj = nullptr;
        rootObj = IConverterUtils.Invoke("GetLocal_TextDataPersonality", nullptr, ToIl2CppStr("Assets/Resources_moved/Localize/en/EN_Personalities.json"));
        MYO_LOG("HermesLocal", "rootObj: {}", rootObj);
        rootObj = IConverterUtils.Invoke("GetLocal_TextDataPersonality", nullptr, ToIl2CppStr("Personalities"));
        MYO_LOG("HermesLocal", "rootObj: {}", rootObj);
        rootObj = IConverterUtils.Invoke("GetLocal_TextDataPersonality", nullptr, ToIl2CppStr("diddy/ilovediddy/diddymansion"));
        MYO_LOG("HermesLocal", "rootObj: {}", rootObj);
        rootObj = IConverterUtils.Invoke("GetLocal_TextDataPersonality", nullptr, ToIl2CppStr("Limbus Company/LimbusCompany_Data/Assets/Resources_moved/Localize/en/EN_Personalities.json"));
        MYO_LOG("HermesLocal", "rootObj: {}", rootObj);
        rootObj = IConverterUtils.Invoke("GetLocal_TextDataPersonality", nullptr, ToIl2CppStr("C:/Program Files (x86)/Steam/steamapps/common/Limbus Company/LimbusCompany_Data/Assets/Resources_moved/Localize/en/EN_Personalities.json"));
        MYO_LOG("HermesLocal", "rootObj: {}", rootObj);


    }
    // MYO_LOG("testmod", "successfully initialized JsonDataListPersonality");
    il2cpp::Il2CppObject* personalityDict = nullptr;
    
    
}
void hooked_JsonDataListPersonality_InitLocal(il2cpp::Il2CppObject* __this, void* a, void* b) {
    original_jsonDataListPersonality_InitLocal(__this, a, b);
    // MYO_LOG("testmod", "Init Local");
}
void hooked_JsonDataListPersonality_InitRemote(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* dataList, il2cpp::Il2CppString* subFolderPath, int32_t lang, il2cpp::Il2CppObject* del) {
    MYO_LOG("testmod", "Remote 1");
    MYO_LOG("testmod", "arg type 0: {}", il2cpp::class_get_name(il2cpp::object_get_class(__this)));
    MYO_LOG("testmod", "arg type 1: {}", il2cpp::class_get_name(il2cpp::object_get_class(dataList)));
    MYO_LOG("testmod", "arg type 2: {}", il2cpp::class_get_name(il2cpp::object_get_class(subFolderPath)));
    MYO_LOG("testmod", "arg type 3: {}", lang);
    // MYO_LOG("testmod", "arg type 4: {}", il2cpp::class_get_name(il2cpp::object_get_class(del)));
    
    MYO_LOG("testmod", "");
    original_jsonDataListPersonality_InitRemote(__this, dataList, subFolderPath, lang, del);
}
void hooked_JsonDataListPersonality_SetDictionary(il2cpp::Il2CppObject* __this, void* a, void* b) {
    original_jsonDataListPersonality_SetDictionary(__this, a, b);
    MYO_LOG("testmod", "Set Dictionary 2, {}, {}, {}, {}", a, b, il2cpp::class_get_name(il2cpp::object_get_class(a)), type_name(il2cpp::class_get_type(il2cpp::object_get_class(a))));
}
il2cpp::Il2CppObject* hooked_RomoteList_getPersonalityFilePaths(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* strListObj = original_RomoteList_getPersonalityFilePaths(__this);

    // const char* className = il2cpp::class_get_name(il2cpp::object_get_class(strListObj));

    // // int32_t zero = 0;
    // // int32_t count = stringListC.InvokeUnbox<int32_t>("get_Count", strListObj);
    // std::string filePath = "chigga";
    // // filePath = unbox_string(strListObj);
    // // if (className == "String") {
    // //     MYO_LOG("HermesLocal", "herro?");
    // //     filePath = unbox_string(strListObj);
    // // }

    
    // // if (count > 0) {
    // //     filePath = stringListC.InvokeUnbox<std::string>("get_Item", strListObj, &zero);
    // // }

    // MYO_LOG("HermesLocal", "Object: {}, File Path[0]: {}, class name: {}", strListObj, filePath, className);
    return strListObj;
}

void hooked_TextDataConverter_ctor(il2cpp::Il2CppObject* __this, il2cpp::Il2CppString* a, il2cpp::Il2CppString* b, il2cpp::Il2CppString* c) {
    
    MYO_LOG("HermesLocal", "a: {}, {}, {} ", a, il2cpp::class_get_name(il2cpp::object_get_class(a)), unbox_string(a));
    MYO_LOG("HermesLocal", "b: {}, {}, {} ", b, il2cpp::class_get_name(il2cpp::object_get_class(b)), unbox_string(b));
    MYO_LOG("HermesLocal", "c: {}, {}, {} ", c, il2cpp::class_get_name(il2cpp::object_get_class(c)), unbox_string(c));
    original_TextDataConverter_ctor(__this, a, b, c);
}

il2cpp::Il2CppObject* hooked_TextDataConverter_GetCustomLocals(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a) {
    MYO_LOG("HermesLocal", "GetCustomLocals");
    return original_TextDataConverter_GetCustomLocals(__this, a);
}

il2cpp::Il2CppObject* hooked_TextDataConverter_GetLocalInitializer(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b, il2cpp::Il2CppObject* c) {
    MYO_LOG("HermesLocal", "GetLocalInitializer");
    return original_TextDataConverter_GetCustomInitializer(__this, a, b, c);
}

il2cpp::Il2CppObject* hooked_TextDataConverter_GetJsonFilePathList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppString* b, int32_t c, bool d) {
    MYO_LOG("HermesLocal", "this: {}, a: {}, b: {}, c: {}, d: {}", __this, a, unbox_string(b), c, d);
    il2cpp::Il2CppObject* stringList = original_TextDataConverter_GetJsonFilePathList(__this, a, b, c, d);

    std::string lang = "";
    if (c == 0) {
        lang = "kr";
    } else if (c== 1) {
        lang = "en";
    } else if (c == 2) {
        lang = "jp";
    } 

    std::string languageFolder = std::format("C:/Program Files (x86)/Steam/steamapps/common/Limbus Company/hermesMod/Localize/{}", lang);
    ClassCache& StringListClass = GetClassRef("List_String");
    int32_t listCount = StringListClass.InvokeUnbox<int32_t>("get_Count", a);
    if (listCount > 0) {
        int32_t zero = 0;
        il2cpp::Il2CppString* strObj = StringListClass.Invoke("get_Item", a, &zero);
        std::string strStr = unbox_string(strObj);

        // dynamically check folders and such
        std::string localizeFolderPath = std::format("{}/{}", languageFolder, strStr);
        if (fs::exists(localizeFolderPath) && fs::is_directory(localizeFolderPath)) {
            // iterate through the directory for all files 
            MYO_LOG("HermesLocal", "Iterating through directory {}", localizeFolderPath);
            for (const auto& entry : fs::directory_iterator(localizeFolderPath)) {
                // Filter to only display regular files (skip directories, symlinks, etc.)
                if (fs::is_regular_file(entry.status()) && entry.path().extension().string() == ".json") {
                    std::string filePath = std::format("{}/{}", localizeFolderPath, entry.path().filename().string());
                    StringListClass.Invoke("Add", stringList, ToIl2CppStr(filePath.c_str()));
                    MYO_LOG("HermesLocal", "Found file {} in directory", filePath);
                }
            }
        } else {
            MYO_LOG("HermesLocal", "Expected folder with name {} in {}", strStr, lang);
        }
    }

    for (int32_t i = 0; i < listCount; i++) {
        il2cpp::Il2CppString* strObj = StringListClass.Invoke("get_Item", a, &i);
        std::string strStr = unbox_string(strObj);
        MYO_LOG("HermesLocal", "String: {}", unbox_string(strObj));
    }
    
    listCount = StringListClass.InvokeUnbox<int32_t>("get_Count", stringList);
    for (int32_t i = 0; i < listCount; i++) {
        il2cpp::Il2CppString* strObj = StringListClass.Invoke("get_Item", stringList, &i);
        std::string strStr = unbox_string(strObj);
        MYO_LOG("HermesLocal", "String: {}", unbox_string(strObj));
    }


    return stringList;
}


void init_localization(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* mscorlibImg) {
    // define all classes
    
    il2cpp::Il2CppClass* textDataSetClass = il2cpp::class_from_name(img, namespaze, "TextDataSet");

    // PERSONALITY 
    // jsonDataListPersonalityClass = RegisterClassFull("JsonDataList", img, namespaze, "JsonDataList`1").klass;
    
    jsonDataListPersonalityClass = get_return_class_from_method(textDataSetClass, "get_PersonalityList", 0);
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

    classes["fallback"] = ClassCache(
        nullptr,
        false,
        {},
        {}
    );

    ClassCache TextDataConverter = RegisterClassFull("TextDataConverter", img, "TextLibrary", "TextDataConverter");
    ClassCache LocalizeTextData = RegisterClassFull("LocalizeTextData", img, "", "LocalizeTextData");
    // original_TextDataConverter_ctor = 
    //     InstallHook<BaseMethod3String>(TextDataConverter.GetMethod(".ctor"), &hooked_TextDataConverter_ctor);
    original_TextDataConverter_GetCustomInitializer = 
        InstallHook<GetLocalInitializer>(TextDataConverter.GetMethod("GetLocalInitializer"), &hooked_TextDataConverter_GetLocalInitializer);
    original_TextDataConverter_GetCustomLocals = 
        InstallHook<GetCustomLocals>(TextDataConverter.GetMethod("GetCustomLocals"), &hooked_TextDataConverter_GetCustomLocals);
    original_TextDataConverter_GetJsonFilePathList = 
        InstallHook<GetJsonFilePathListFn>(TextDataConverter.GetMethod("GetJsonFilePathList"), &hooked_TextDataConverter_GetJsonFilePathList);

    ClassCache TextData_Personality = RegisterClassFull("TextData_Personality", img, "", "TextData_Personality");
    ClassCache TextData_EGO = RegisterClassFull("TextData_Ego", img, "", "TextData_Ego");
    ClassCache TextData_Enemy = RegisterClassFull("TextData_Enemy", img, "", "TextData_Enemy");
    ClassCache TextData_Skill = RegisterClassFull("TextData_Skill", img, "", "TextData_Skill");
    ClassCache TextData_SkillPerLevel = RegisterClassFull("TextData_SkillPerLevel", img, "", "TextData_SkillPerLevel");
    ClassCache TextData_Skill_Coins = RegisterClassFull("TextData_Skill_Coins", img, "", "TextData_Skill_Coins");
    ClassCache TextData_Skill_CoinDesc = RegisterClassFull("TextData_Skill_CoinDesc", img, "", "TextData_Skill_CoinDesc");

    ClassCache IConverterUtils = RegisterClassFull("IConverterUtils", img, "TextLibrary", "IConverterUtils");
    // IT WORKED! I LOVE INFLATION!
    


    // ClassCache RomoteFileList = RegisterClassFull("RemoteLocalizeFileList", img, "", "RomoteLocalizeFileList");

    il2cpp::Il2CppClass* romoteFileListClass = get_return_class_from_method(TextDataConverter.GetMethod("GetRemoteLocalizeFileList"));
    ClassCache RomoteFileListCache = RegisterClassFull(romoteFileListClass, "RomoteFileList");
    ClassCache GenericList_String = RegisterClassFull(get_return_class_from_method(RomoteFileListCache.GetMethod("get_PersonalityFilePaths")), "List_String");



    original_RomoteList_getPersonalityFilePaths = 
    InstallHook<BaseMethodReturnObj>(RomoteFileListCache.GetMethod("get_PersonalityFilePaths"), &hooked_RomoteList_getPersonalityFilePaths);



    // original_jsonDataListPersonality_InitRemote = reinterpret_cast<InitRemoteFn>(
    //     hook::install_inline(jsonDataListPersonality_InitRemote, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_InitRemote)));
    il2cpp::Il2CppMethod* initRemoteConverter = il2cpp::class_get_method_from_name(TextDataConverter.klass, "InitRemote", 4);
    if (initRemoteConverter) {
        MYO_LOG("HermesLocal", "exist congrat");
    }
    original_jsonDataListPersonality_InitRemote = reinterpret_cast<InitRemoteFn>(
        hook::install_inline(initRemoteConverter, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_InitRemote)));
    original_IConverter_GetLocalInit = reinterpret_cast<ConverterGetLocalInitFn>(
        hook::install_inline(TextDataConverter.GetMethod("GetLocalInitializer"), reinterpret_cast<void*>(&hooked_IConverter_GetLocalInitializer)));
    // original_ctorQuick = reinterpret_cast<CtorQuickFn>(
    //     hook::install_inline(RomoteFileListCache.GetMethod("get_SkillFilePaths"), reinterpret_cast<void*>(&hooked_ctorQuick)));
    if (!original_jsonDataListPersonality_InitRemote) MYO_LOG("HermesLocal", "original does NOT exist. wow. just incredible");

    MYO_LOG("HermesLocal", "InitRemote hooked");

    original_jsonDataListPersonality_ctor = reinterpret_cast<BaseMethodType>(
        hook::install_inline(jsonDataListPersonality_ctor, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_ctor)));
    original_jsonDataListPersonality_InitLocal = reinterpret_cast<BaseMethod2Void>(
        hook::install_inline(jsonDataListPersonality_InitLocal, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_InitLocal)));
   
    original_jsonDataListPersonality_SetDictionary = reinterpret_cast<BaseMethod2Void>(
        hook::install_inline(jsonDataListPersonality_SetDictionary, reinterpret_cast<void*>(&hooked_JsonDataListPersonality_SetDictionary)));
    
    // EGO

    // ENEMIES


}

}


