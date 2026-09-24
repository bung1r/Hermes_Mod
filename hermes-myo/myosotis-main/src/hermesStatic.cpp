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
void injectJsonNodeData(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* nodeList, const char* filePath) {
    return;
    
    MYO_LOG("testmod", "STEP 1 injectJsonNodeData");
    
    std::ifstream file(filePath);
    if (!file.is_open()) MYO_LOG("testmod", "Failed to open file. Oops!");

    // Read all characters into a stringstream buffer
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonStr = buffer.str();

    MYO_LOG("testmod", "STEP 2 injectJsonNodeData");

    // create the JSON Node 
    il2cpp::Il2CppString* jsonStrObj = il2cpp::string_new(jsonStr.c_str());
    void* jsonNodeParams[1];
    jsonNodeParams[0] = jsonStrObj;
    
    il2cpp::Il2CppObject* jsonNode = il2cpp::runtime_invoke(jsonNode_Parse, nullptr, jsonNodeParams, nullptr);
    MYO_LOG("testmod", "STEP 3 injectJsonNodeData");
    il2cpp::Il2CppString* jsonNodeToString = il2cpp::runtime_invoke(jsonNode_ToString, jsonNode, nullptr, nullptr);
    // std::string s = unbox_string(jsonNodeToString);
    
    MYO_LOG("testmod", "STEP 4 injectJsonNodeData");
    // get our custom list 
    il2cpp::Il2CppString* listKeyObj = il2cpp::string_new("list");
    void* jsonListNodeParams[1];
    jsonListNodeParams[0] = listKeyObj;

    MYO_LOG("testmod", "STEP 5 injectJsonNodeData");

    il2cpp::Il2CppObject* jsonListNode = il2cpp::runtime_invoke(jsonNode_getItemKey, jsonNode, jsonListNodeParams, nullptr);

    MYO_LOG("testmod", "STEP 6 injectJsonNodeData");
    il2cpp::Il2CppObject* jsonListCount = il2cpp::runtime_invoke(jsonNode_getCount, jsonListNode, nullptr, nullptr);

    MYO_LOG("testmod", "STEP 7 injectJsonNodeData");
    if (!jsonListCount) MYO_LOG("testmod", "no jsonListCount");
    int32_t customListCount = unbox<int32_t>(jsonListCount);
    MYO_LOG("testmod", "customListCount: {}", customListCount);

    MYO_LOG("testmod", "STEP 7.5 injectJsonNodeData");
    
    // il2cpp::Il2CppObject* nodeListCount = il2cpp::runtime_invoke(csJsonNodeList_getCount, nodeList, nullptr, nullptr);
    // iterate through the list in personality.json, then append the sinner data to one of 12 lists.
    
    if (!nodeList) MYO_LOG("testmod", "node list does not exist");
    if (!csJsonNodeList_getCount) MYO_LOG("testmod", "csJsonNodeList_getCount does not exist");

    for (int32_t i = 0; i < customListCount; i++) {

        MYO_LOG("testmod", "STEP 8 injectJsonNodeData");
        // Get the JsonNode item from the list in the json. 
        void* indexParams[1]; indexParams[0] = &i;
        il2cpp::Il2CppObject* sinnerItem = il2cpp::runtime_invoke(jsonNode_getItemIndex, jsonListNode, indexParams, nullptr);
        
        
        // void* targetSinnerParams[1]; targetSinnerParams[0] = targetSinnerStrObj;
        // il2cpp::Il2CppObject* targetSinnerNodeObj = il2cpp::runtime_invoke(jsonNode_getItemKey, sinnerItem, targetSinnerParams, nullptr);
        // il2cpp::Il2CppObject* targetSinnerIndexObj = il2cpp::runtime_invoke(jsonNode_getAsInt, targetSinnerNodeObj, nullptr, nullptr);
        // int32_t targetSinnerIndex = unbox<int32_t>(targetSinnerIndexObj);
        int32_t targetIndex = 0; // 0 for now. 

        MYO_LOG("testmod", "STEP 9 injectJsonNodeData");
        // get the list of the static sinner list, then append our stuff to the first nodelist
        void* staticSinnerListNodeParams[1]; staticSinnerListNodeParams[0] = &targetIndex;
        il2cpp::Il2CppObject* staticSinnerFullListNode = il2cpp::runtime_invoke(csJsonNodeList_getItem, nodeList, staticSinnerListNodeParams, nullptr);
        il2cpp::Il2CppObject* staticSinnerListNode = il2cpp::runtime_invoke(jsonNode_getItemKey, staticSinnerFullListNode, jsonListNodeParams, nullptr);
        
        MYO_LOG("testmod", "STEP 10 injectJsonNodeData");
        void* addListParams[1]; addListParams[0] = sinnerItem;

        MYO_LOG("testmod", "STEP 11 injectJsonNodeData");

        il2cpp::runtime_invoke(jsonNode_Add1, staticSinnerListNode, addListParams, nullptr);
    }
}

void hooked_PersonalityStaticDataList_Init(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* nodeList) {
    MYO_LOG("testmod", "STEP 1 hooked_PersonalityStaticDataList_Init");
    
    // inject our json data
    injectJsonNodeData(__this, nodeList, "hermesMod/data/personality.json");

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


    // il2cpp::Il2CppObject* texture = il2cpp::runtime_invoke(sprite_getTexture, returnGameObject, nullptr, nullptr);
    // if (!texture) {
    //     MYO_LOG("testmod", "Texture does not exist");
    // } else {
    //     il2cpp::Il2CppObject* width = il2cpp::runtime_invoke(texture2D_getWidth, texture, nullptr, nullptr);
    //     il2cpp::Il2CppObject* height = il2cpp::runtime_invoke(texture2D_getHeight, texture, nullptr, nullptr);
    //     if (!width) {
    //         MYO_LOG("testmod", "width no exist");
    //     } else {
    //         MYO_LOG("testmod", "width: {}", unbox<int32_t>(width));
    //         // widthValue = unbox<int32_t>(width);
    //     }

    //     if (!height) {
    //         MYO_LOG("testmod", "height no exist");
    //     } else {
    //         MYO_LOG("testmod", "height: {}", unbox<int32_t>(height));
    //         // heightValue = unbox<int32_t>(height);
    //     }

    //     il2cpp::Il2CppObject* rect = il2cpp::runtime_invoke(sprite_getRect, returnGameObject, nullptr, nullptr);
    //     float rectCoolWidth = unbox<float>(il2cpp::runtime_invoke(rect_getWidth, rect, nullptr, nullptr));
    //     float rectCoolHeight = unbox<float>(il2cpp::runtime_invoke(rect_getHeight, rect, nullptr, nullptr));
    //     float rectXLog = unbox<float>(il2cpp::runtime_invoke(rect_getX, rect, nullptr, nullptr));
    //     float rectYLog = unbox<float>(il2cpp::runtime_invoke(rect_getY, rect, nullptr, nullptr));
    //     MYO_LOG("testmod", "rect cooler width: {}", rectCoolWidth);
    //     MYO_LOG("testmod", "rect cooler height: {}", rectCoolHeight);
    //     MYO_LOG("testmod", "x: {}", rectXLog);
    //     MYO_LOG("testmod", "y: {}", rectYLog);

    //     il2cpp::Il2CppObject* checkPivot = il2cpp::runtime_invoke(sprite_getPivot, returnGameObject, nullptr, nullptr);
    //     float pivotLogX = GetFieldInObj<float>(checkPivot, vector2Class, "x");
    //     float pivotLogY = GetFieldInObj<float>(checkPivot, vector2Class, "y");
    //     MYO_LOG("testmod", "pivotX US: {}, pivotY US: {}", pivotLogX, pivotLogY);

        

    //     // il2cpp::Il2CppObject* pivot = il2cpp::runtime_invoke(sprite_getPivot, returnGameObject, nullptr, nullptr);

    //     // il2cpp::Il2CppObject* coolsprite = CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");

    //     // if (!coolsprite) {
    //     //     MYO_LOG("testmod", "coolsprite don't exist");
    //     // }

    //     // ModifyTexture2D(texture, "hermesMod/assets/MoFullBody.png");
    //     // CreateTexture2D("hermesMod/assets/MoFullBody.png");
    //     // return CreateSpriteFromTexture2D(texture2DMo);

    //     il2cpp::Il2CppObject* lolangTexture = CreateWhiteTexture2D();
    //     il2cpp::Il2CppObject* lolangSprite = CreateSpriteFromTexture2D(lolangTexture);

    //     // il2cpp::Il2CppObject* lolangSprite = CreateSpriteFromImg("hermesMod/assets/lolang.jpg", pivotLogX, pivotLogY);
    //     il2cpp::Il2CppObject* lolangSpritePivot = il2cpp::runtime_invoke(sprite_getPivot, lolangSprite, nullptr, nullptr);
    //     // SetFieldInObj<float>(lolangSpritePivot, spriteClass, "x", &pivotLogX);

    //     // void* lolangSpritePivotObj = il2cpp::object_unbox(lolangSpritePivot);
    //     // SetFieldInObj(lolangSpritePivotObj, lolangSprite, "x", &pivotLogX);
    //     // SetFieldInObj(lolangSpritePivotObj, lolangSprite, "y", &pivotLogY);

    //     float pivotLogXLol = GetFieldInObj<float>(lolangSpritePivot, vector2Class, "x");
    //     float pivotLogYLol = GetFieldInObj<float>(lolangSpritePivot, vector2Class, "y");
    //     MYO_LOG("testmod", "pivotXLol: {}, pivotYLol: {}", pivotLogXLol, pivotLogYLol);


    //     return lolangSprite;
        
        
    // }
    
    // // MYO_LOG("testmod", "yes or no yes");
    // if (!texture2DMo) {
    //     MYO_LOG("testmod", "texture has passed away");
    // }

    // if (!spriteMo) {
    //     MYO_LOG("testmod", "sprite has passed away");
    // }

    // // if (texture2DMo) {
    // //     return CreateSpriteFromTexture2D(texture2DMo);
    // // }


    
    
    // // return spriteMo;

    // MYO_LOG("testmod", "Get Info Sprite: Personality ID: {}, Gacksung: {}", personalityId, gacksung);
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