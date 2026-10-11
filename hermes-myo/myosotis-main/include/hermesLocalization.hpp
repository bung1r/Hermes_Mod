#pragma once
#include "il2cpp.hpp"
#include "hermesUtils.hpp"


namespace myosotis::testmod {


std::string extractLowerSuffix(const std::string& input);

inline il2cpp::Il2CppClass* jsonDataListPersonalityClass = nullptr;
inline il2cpp::Il2CppType* jsonDataListPersonalityType = nullptr;
inline il2cpp::Il2CppClass* jsonDataListEGOClass = nullptr;

inline il2cpp::Il2CppField* jsonDataListPersonality__dict = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_GetList = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_GetDataInt = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_GetDataStr = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_ctor = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_InitLocal = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_InitRemote = nullptr;
inline il2cpp::Il2CppMethod* jsonDataListPersonality_SetDictionary = nullptr;

using InitRemoteFn = void(*)(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* dataList, il2cpp::Il2CppString* subFolderPath, int32_t lang, il2cpp::Il2CppObject* del);
using CtorQuickFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BaseMethodType original_jsonDataListPersonality_ctor = nullptr;
inline BaseMethod2Void original_jsonDataListPersonality_InitLocal = nullptr;
inline InitRemoteFn original_jsonDataListPersonality_InitRemote = nullptr;
inline BaseMethod2Void original_jsonDataListPersonality_SetDictionary = nullptr;
inline CtorQuickFn original_ctorQuick = nullptr;

inline il2cpp::Il2CppClass* textDataPersonalityClass = nullptr;
inline il2cpp::Il2CppMethod* textDataPersonality_GetName = nullptr;
inline il2cpp::Il2CppMethod* textDataPersonality_GetNameWithTitle = nullptr;

void hooked_JsonDataListPersonality_ctor(il2cpp::Il2CppObject* __this);
void hooked_JsonDataListPersonality_InitLocal(il2cpp::Il2CppObject* __this, void* a, void* b);
void hooked_JsonDataListPersonality_InitRemote(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* dataList, il2cpp::Il2CppString* subFolderPath, int32_t lang, il2cpp::Il2CppObject* del);
void hooked_JsonDataListPersonality_SetDictionary(il2cpp::Il2CppObject* __this, void* a, void* b);


il2cpp::Il2CppObject* hooked_RomoteList_getPersonalityFilePaths(il2cpp::Il2CppObject* __this);
using BaseMethodReturnObj = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BaseMethodReturnObj original_RomoteList_getPersonalityFilePaths = nullptr;

void hooked_TextDataConverter_ctor(il2cpp::Il2CppObject* __this, il2cpp::Il2CppString* a, il2cpp::Il2CppString* b, il2cpp::Il2CppString* c);
using BaseMethod3String = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppString*, il2cpp::Il2CppString*, il2cpp::Il2CppString*);
inline BaseMethod3String original_TextDataConverter_ctor = nullptr;

il2cpp::Il2CppObject* hooked_TextDataConverter_GetCustomLocals(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a);
using GetCustomLocals = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline GetCustomLocals original_TextDataConverter_GetCustomLocals = nullptr;

il2cpp::Il2CppObject* hooked_TextDataConverter_GetLocalInitializer(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b, il2cpp::Il2CppObject* c);
using GetLocalInitializer = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline GetLocalInitializer original_TextDataConverter_GetCustomInitializer = nullptr;

//System.Collections.Generic.List<System.String> GetJsonFilePathList(System.Collections.Generic.List<System.String> dataList, System.String subFolderPath, LOCALIZE_LANGUAGE lang, System.Boolean isCustomFont) {}
il2cpp::Il2CppObject* hooked_TextDataConverter_GetJsonFilePathList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppString* b, int32_t c, bool d);
using GetJsonFilePathListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppString*, int32_t, bool);
inline GetJsonFilePathListFn original_TextDataConverter_GetJsonFilePathList;




using ConverterGetLocalInitFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppString*, il2cpp::Il2CppObject*, il2cpp::Il2CppString*);
il2cpp::Il2CppObject* hooked_ctorQuick(il2cpp::Il2CppObject* __this);
inline ConverterGetLocalInitFn original_IConverter_GetLocalInit = nullptr;
il2cpp::Il2CppObject* hooked_IConverter_GetLocalInitializer(il2cpp::Il2CppObject* __this, il2cpp::Il2CppString* localizeFolderPath, il2cpp::Il2CppObject* list, il2cpp::Il2CppString* lang);
void init_localization(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* mscorlibImg);

//System.Collections.Generic.List<System.String> GetJsonFilePathList(System.Collections.Generic.List<System.String> dataList, System.String subFolderPath, LOCALIZE_LANGUAGE lang, System.Boolean isCustomFont) {}


}