#pragma once
#include "il2cpp.hpp"

namespace myosotis::testmod {

// -------------------- PERSONALITY STATIC DATA ----------------------------
// The StaticDataList class from Limbus, not the C# one
using personalityStaticDataListInitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline il2cpp::Il2CppClass* personalityStaticDataListClass = nullptr;
inline il2cpp::Il2CppMethod* personalityStaticDataList_Init = nullptr;
inline personalityStaticDataListInitFn original_PersonalityStaticDataList_Init = nullptr;

inline il2cpp::Il2CppClass* csPersonalityStaticDataListClass = nullptr;
inline il2cpp::Il2CppMethod* csPersonalityStaticDataList_Add = nullptr;

// -------------------- SKILL STATIC DATA --------------------------------

void hooked_PersonalityStaticDataList_Init(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* nodeList);
void init_static(il2cpp::Il2CppImage* img, const char* namespaze);



// ------------------- PlayerUnitSpriteList ------------------------------
// I'm not sure why it has its own thing, so I'm trying to find out 
using playerUnitSpriteListSetCGDataFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, bool, il2cpp::Il2CppObject*, int32_t, int32_t, void*, il2cpp::Il2CppString*);
using playerUnitSpriteListGetNormalProfileSprite = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, bool);
using playerUnitSpriteListGetCGDataFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, bool, il2cpp::Il2CppString*);
inline il2cpp::Il2CppClass* playerUnitSpriteListClass = nullptr;
inline il2cpp::Il2CppMethod* playerUnitSpriteList_GetNormalProfileSprite = nullptr;
inline il2cpp::Il2CppMethod* playerUnitSpriteList_GetInfoSprite = nullptr;
inline il2cpp::Il2CppMethod* playerUnitSpriteList_GetCGData = nullptr;
inline il2cpp::Il2CppMethod* playerUnitSpriteList_SetCGData = nullptr;

inline playerUnitSpriteListGetNormalProfileSprite original_PlayerUnitSpriteList_GetNormalProfileSprite = nullptr;
inline playerUnitSpriteListGetNormalProfileSprite original_PlayerUnitSpriteList_GetInfoSprite = nullptr;
inline playerUnitSpriteListGetCGDataFn original_PlayerUnitSpriteList_GetCGData = nullptr;
inline playerUnitSpriteListSetCGDataFn original_PlayerUnitSpriteList_SetCGData = nullptr;

il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetNormalProfileSprite(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung);
il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetInfoSprite(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung);
il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetCGData(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung, il2cpp::Il2CppString* releaseKey);
il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_SetCGData(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung, il2cpp::Il2CppObject* img_illust, int32_t uiLocation, int32_t orderInLayer, void* optionFxMask, il2cpp::Il2CppString* sortingLayerName);

}