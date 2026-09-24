#pragma once

#include "il2cpp.hpp"
#include "hermesUtils.hpp"
#include "stb_image.h"

namespace myosotis::testmod {

inline il2cpp::Il2CppClass* byteClass = nullptr;

inline il2cpp::Il2CppClass* csByteListClass = nullptr;
inline il2cpp::Il2CppMethod* csByteList_ctor = nullptr;
inline il2cpp::Il2CppMethod* csByteList_Add = nullptr;
inline il2cpp::Il2CppMethod* csByteList_ToArray = nullptr;
inline il2cpp::Il2CppMethod* csByteList_getCount = nullptr;

inline il2cpp::Il2CppClass* rectClass = nullptr;
inline il2cpp::Il2CppMethod* rect_ctor = nullptr;
inline il2cpp::Il2CppMethod* rect_getWidth= nullptr;
inline il2cpp::Il2CppMethod* rect_getHeight = nullptr;
inline il2cpp::Il2CppMethod* rect_getX= nullptr;
inline il2cpp::Il2CppMethod* rect_getY = nullptr;

inline il2cpp::Il2CppClass* vector2Class = nullptr;
inline il2cpp::Il2CppMethod* vector2_ctor = nullptr;
// inline il2cpp::Il2CppField* vector2_x = nullptr;
// inline il2cpp::Il2CppMethod* vector2_y = nullptr;

inline il2cpp::Il2CppClass* colorClass = nullptr; // actually a struct but whatever
inline il2cpp::Il2CppField* color_r = nullptr;
inline il2cpp::Il2CppField* color_b = nullptr;
inline il2cpp::Il2CppField* color_g = nullptr;
inline il2cpp::Il2CppField* color_a = nullptr;

inline il2cpp::Il2CppClass* texture2DClass = nullptr;
inline il2cpp::Il2CppMethod* texture2D_ctor = nullptr; // 2 params, width height
inline il2cpp::Il2CppMethod* texture2D_LoadRawTextureData = nullptr;
inline il2cpp::Il2CppMethod* texture2D_Apply = nullptr;
inline il2cpp::Il2CppMethod* texture2D_Resize = nullptr;
inline il2cpp::Il2CppMethod* texture2D_getWidth = nullptr;
inline il2cpp::Il2CppMethod* texture2D_getHeight = nullptr;
inline il2cpp::Il2CppMethod* texture2D_GetPixel = nullptr;
inline il2cpp::Il2CppMethod* texture2D_Reinitialize = nullptr; 
inline il2cpp::Il2CppMethod* texture2D_CreateExternalTexture = nullptr;
inline il2cpp::Il2CppMethod* texture2D_getIsReadable = nullptr;

inline il2cpp::Il2CppClass* uiImageClass = nullptr;
inline il2cpp::Il2CppMethod* uiImage_setSprite = nullptr;


inline il2cpp::Il2CppObject* texture2DMo = nullptr;
inline il2cpp::Il2CppGCHandle texture2DMoHandle = nullptr;

inline il2cpp::Il2CppClass* spriteClass = nullptr;
// inline il2cpp::Il2CppMethod* sprite_ctor = nullptr;
inline il2cpp::Il2CppMethod* sprite_Create = nullptr;
inline il2cpp::Il2CppMethod* sprite_getTexture = nullptr;
inline il2cpp::Il2CppMethod* sprite_getRect = nullptr;
inline il2cpp::Il2CppMethod* sprite_getPivot = nullptr;

inline il2cpp::Il2CppObject* spriteMo = nullptr;
inline il2cpp::Il2CppGCHandle spriteMoHandle = nullptr;

void ModifyTexture2D(il2cpp::Il2CppObject* texture2D, const char* filePath);
il2cpp::Il2CppObject* CreateTexture2D(const char* filePath);
il2cpp::Il2CppObject* CreateSpriteFromTexture2D(il2cpp::Il2CppObject* texture2D, float xPivot = 0.0f, float yPivot = 0.0f);
il2cpp::Il2CppObject* CreateSpriteFromImg(const char* filePath, float xPivot = 0.0f, float yPivot = 0.0f);
il2cpp::Il2CppObject* CreateWhiteTexture2D();

using FormationPersonalityUIInitFn = void(*)(il2cpp::Il2CppObject*, int32_t, void*, void*);
inline FormationPersonalityUIInitFn original_FormationPersonalityUI_Init = nullptr;
// System.Int32 index, System.Action<System.Int32,System.Boolean,MainUI.FormationPersonalityUI,System.Boolean> panelCallback, MainUI.FormationUIEnterManager enterManager
void hooked_FormationPersonalityUI_Init(il2cpp::Il2CppObject* __this, int32_t index, void* panelCallback, void* enterManager);

inline BaseMethod1Void original_FormationPersonalityUI_SetData1 = nullptr;
// MainUI.FormationPersonalityUIParameters parameters
void hooked_FormationPersonalityUI_SetData1(il2cpp::Il2CppObject* __this, void* parameters);

using FormationPersonalityUISetData2 = void(*)(il2cpp::Il2CppObject*, void*, int32_t, int32_t, bool, void*, void*, bool, void*, int32_t);
inline FormationPersonalityUISetData2 original_FormationPersonalityUI_SetData2 = nullptr;
// PersonalityStaticData personalityStaticData, System.Int32 personalityLevel, System.Int32 personalityGacksung, System.Boolean isGacksungIllust, System.Collections.Generic.List<T> egoList, System.Collections.Generic.Dictionary<ATTRIBUTE_TYPE,System.Int32> personalitySkillDict, System.Boolean isNotCharacterUpdated, LimbusCompany.Data.Character.CharacterIconSet characterIconSet, System.Int32 skinId
void hooked_FormationPersonalityUI_SetData2(il2cpp::Il2CppObject* __this, void* personalityStaticData, int32_t personalityLevel, int32_t personalityGacksung, bool isGacksungIllust, void* egoList, void* personalitySkillDict, bool isNotCharacterUpdated, void* characterIconSet, int32_t skinId);

void init_unity_objects(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* unityImg, il2cpp::Il2CppImage* corImg, il2cpp::Il2CppImage* unityUImg);

void init_unity_main_thread();
}