#pragma once
#include "il2cpp.hpp"
#include "hermesUtils.hpp"


namespace myosotis::testmod {

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

inline BaseMethodType original_jsonDataListPersonality_ctor = nullptr;
inline BaseMethod2Void original_jsonDataListPersonality_InitLocal = nullptr;
inline BaseMethod4Void original_jsonDataListPersonality_InitRemote = nullptr;
inline BaseMethod2Void original_jsonDataListPersonality_SetDictionary = nullptr;

inline il2cpp::Il2CppClass* textDataPersonalityClass = nullptr;
inline il2cpp::Il2CppMethod* textDataPersonality_GetName = nullptr;
inline il2cpp::Il2CppMethod* textDataPersonality_GetNameWithTitle = nullptr;

void hooked_JsonDataListPersonality_ctor(il2cpp::Il2CppObject* __this);
void hooked_JsonDataListPersonality_InitLocal(il2cpp::Il2CppObject* __this, void* a, void* b);
void hooked_JsonDataListPersonality_InitRemote(il2cpp::Il2CppObject* __this, void* a, void* b, void* c, void* d);
void hooked_JsonDataListPersonality_SetDictionary(il2cpp::Il2CppObject* __this, void* a, void* b);
void init_localization(il2cpp::Il2CppImage* img, const char* namespaze);

}