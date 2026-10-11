#include "il2cpp.hpp"
#include "hermesStatic.hpp"
#include "hermesUtils.hpp"
#include "hermesJson.hpp"
#include "hook.hpp"
#include "log.hpp"
#include "hermesUnity.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace myosotis::testmod {


// injected into nodeList directly, call the original func after

void hooked_PersonalityStaticDataList_Init(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* nodeList) {
    MYO_LOG("testmod", "STEP 1 hooked_PersonalityStaticDataList_Init");
    
    // call the method, now with our modified json nodes. 
    original_PersonalityStaticDataList_Init(__this, nodeList);
}

il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetNormalProfileSprite(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung) {
    il2cpp::Il2CppObject* returnGameObject = original_PlayerUnitSpriteList_GetNormalProfileSprite(__this, personalityId, gacksung);

    il2cpp::Il2CppObject* texture = il2cpp::runtime_invoke(sprite_getTexture, returnGameObject, nullptr, nullptr);
    if (!texture) {
        MYO_LOG("testmod", "Texture does not exist");
    } else {

        // ModifyTexture2D(texture, "hermesMod/assets/MoFullBody.png");
        // il2cpp::Il2CppObject* coolsprite = CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");

        // if (!coolsprite) {
        //     MYO_LOG("testmod", "coolsprite don't exist");
        // }
        
        // return spriteMo;
        // return CreateSpriteFromTexture2D(texture2DMo);
    }
    

    MYO_LOG("testmod", "GetNormalProfileSprite: Personality ID: {}, Gacksung: {}", personalityId, gacksung);
    return returnGameObject;
}
il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetInfoSprite(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung) {
    il2cpp::Il2CppObject* returnGameObject = original_PlayerUnitSpriteList_GetInfoSprite(__this, personalityId, gacksung);
    
    return CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");
    return returnGameObject;
}
il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_GetCGData(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung, il2cpp::Il2CppString* releaseKey) {
    il2cpp::Il2CppObject* returnGameObject = original_PlayerUnitSpriteList_GetCGData(__this, personalityId, gacksung, releaseKey);
    
    il2cpp::Il2CppObject* texture = il2cpp::runtime_invoke(sprite_getTexture, returnGameObject, nullptr, nullptr);
    if (!texture) {
        MYO_LOG("testmod", "Texture does not exist");
    } else {
        // ModifyTexture2D(texture, "hermesMod/assets/MoFullBody.png");
        // return CreateSpriteFromTexture2D(texture2DMo);

        

        // il2cpp::Il2CppObject* coolsprite = CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");

        // if (!coolsprite) {
        //     MYO_LOG("testmod", "coolsprite don't exist");
        // }
        // CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");
        // return spriteMo;
    }
    


    MYO_LOG("testmod", "GetCGData: Personality ID: {}, Gacksung: {}", personalityId, gacksung);

    return returnGameObject;
}

il2cpp::Il2CppObject* hooked_PlayerUnitSpriteList_SetCGData(il2cpp::Il2CppObject* __this, int32_t personalityId, bool gacksung, il2cpp::Il2CppObject* img_illust, int32_t uiLocation, int32_t orderInLayer, void* optionFxMask, il2cpp::Il2CppString* sortingLayerName) {
    il2cpp::Il2CppObject* obj= original_PlayerUnitSpriteList_SetCGData(__this, personalityId, gacksung, img_illust, uiLocation, orderInLayer, optionFxMask, sortingLayerName);
    
    MYO_LOG("testmod", "SetCGDATA -- id: {}, gacksung: {}, uiLocation: {}", personalityId, gacksung, uiLocation);

    if (img_illust) {
        il2cpp::Il2CppObject* lolangSprite = CreateSpriteFromImg("hermesMod/assets/lolang.jpg");
        void* params[1]; params[0] = lolangSprite;
        void* exc = nullptr;
        il2cpp::runtime_invoke(uiImage_setSprite, img_illust, params, &exc);

        if (exc) {
            MYO_LOG("testmod", "Oh no!");
        }
    }

    return obj;
}

void init_static(il2cpp::Il2CppImage* img, const char* namespaze) {

    // PERSONALITY STATIC STUFF
    personalityStaticDataListClass = il2cpp::class_from_name(img, namespaze, "PersonalityStaticDataList");

    personalityStaticDataList_Init = il2cpp::class_get_method_from_name(personalityStaticDataListClass, "Init", 1);

    il2cpp::Il2CppMethod* csPersonalityStaticDataListMethod = il2cpp::class_get_method_from_name(personalityStaticDataListClass, "GetList", 0);
    csPersonalityStaticDataListClass =  get_return_class_from_method(csPersonalityStaticDataListMethod);

    
    csPersonalityStaticDataList_Add = il2cpp::class_get_method_from_name(csPersonalityStaticDataListClass, "Add", 1);

    original_PersonalityStaticDataList_Init = reinterpret_cast<personalityStaticDataListInitFn>(
        hook::install_inline(personalityStaticDataList_Init, reinterpret_cast<void*>(&hooked_PersonalityStaticDataList_Init)));
    
    // ------------------- PlayerUnitSpriteList ------------------------------

    playerUnitSpriteListClass = il2cpp::class_from_name(img, namespaze, "PlayerUnitSpriteList");
    playerUnitSpriteList_GetNormalProfileSprite = il2cpp::class_get_method_from_name(playerUnitSpriteListClass, "GetNormalProfileSprite", 2);
    playerUnitSpriteList_GetInfoSprite= il2cpp::class_get_method_from_name(playerUnitSpriteListClass, "GetInfoSprite", 2);
    playerUnitSpriteList_GetCGData = il2cpp::class_get_method_from_name(playerUnitSpriteListClass, "GetCGData", 3);
    playerUnitSpriteList_SetCGData = il2cpp::class_get_method_from_name(playerUnitSpriteListClass, "SetCGData", 7);
    
    original_PlayerUnitSpriteList_GetNormalProfileSprite = reinterpret_cast<playerUnitSpriteListGetNormalProfileSprite>(
        hook::install_inline(playerUnitSpriteList_GetNormalProfileSprite, reinterpret_cast<void*>(&hooked_PlayerUnitSpriteList_GetNormalProfileSprite)));
    original_PlayerUnitSpriteList_GetInfoSprite = reinterpret_cast<playerUnitSpriteListGetNormalProfileSprite>(
        hook::install_inline(playerUnitSpriteList_GetInfoSprite, reinterpret_cast<void*>(&hooked_PlayerUnitSpriteList_GetInfoSprite)));
    original_PlayerUnitSpriteList_GetCGData = reinterpret_cast<playerUnitSpriteListGetCGDataFn>(
        hook::install_inline(playerUnitSpriteList_GetCGData, reinterpret_cast<void*>(&hooked_PlayerUnitSpriteList_GetCGData)));
    original_PlayerUnitSpriteList_SetCGData = reinterpret_cast<playerUnitSpriteListSetCGDataFn>(
        hook::install_inline(playerUnitSpriteList_SetCGData, reinterpret_cast<void*>(&hooked_PlayerUnitSpriteList_SetCGData)));
}

}