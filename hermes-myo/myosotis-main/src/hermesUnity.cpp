#include "il2cpp.hpp"
#include "log.hpp"
#include "hermesUnity.hpp"
#include "hermesUtils.hpp"
#include "hermesJson.hpp"
#include "stb_image.h"
#include <filesystem>   
#include <iostream>
namespace myosotis::testmod {

il2cpp::Il2CppObject* CreateWhiteTexture2D() {
    il2cpp::Il2CppMethod* texture_getWhiteTexture = il2cpp::class_get_method_from_name(texture2DClass, "get_redTexture", 0);
    return il2cpp::runtime_invoke(texture_getWhiteTexture, nullptr, nullptr, nullptr);
}
il2cpp::Il2CppObject* CreateTexture2D(const char* filePath) {

    ClassCache Texture2D = GetClass("Texture2D");

    std::filesystem::path path = filePath;

    // check if our file exists before doing anything else 
    if (!std::filesystem::exists(path)) {
        MYO_LOG("testmod", "ERROR: File path of {} does not exist", filePath);
        return nullptr;
    }


    // flip so that it looks normal on unity 
    stbi_set_flip_vertically_on_load(1);

    // use stbi load to get our pixels 
    int width, height, channels;
    unsigned char* pixels = stbi_load(filePath, &width, &height, &channels, 4);
    size_t size = width * height * 4;
    
    if (!pixels) {
        // MYO_LOG("testmod", "stbi_load failed: {}", stbi_failure_reason());
        return nullptr;
    }

    il2cpp::Il2CppObject* byteList = il2cpp::object_new(csByteListClass);
    il2cpp::runtime_invoke(csByteList_ctor, byteList, nullptr, nullptr);


    // Add every byte
    for (size_t i = 0; i < size; i++) {

        // List<byte>.Add(byte)
        uint8_t value = pixels[i];

        void* addParams[1];
        addParams[0] = &value;

        il2cpp::runtime_invoke(csByteList_Add, byteList, addParams, nullptr);
    }

    
    il2cpp::Il2CppException* exc = nullptr;
    il2cpp::Il2CppObject* byteArray = il2cpp::runtime_invoke(csByteList_ToArray, byteList, nullptr, &exc);
    // MYO_LOG("testmod", "cs byte array type: {}", type_name(il2cpp::class_get_type(il2cpp::object_get_class(byteArray))));

    exc = nullptr;
    int32_t count = unbox<int32_t>(il2cpp::runtime_invoke(csByteList_getCount, byteList, nullptr, &exc));
    // MYO_LOG("testmod", "cs byte list count: {}", count);

    // instantiate a byte array and copy our pixels inside 

    if (exc) {
        MYO_LOG("testmod", "i don't even know at this point");
    }

    // 1. Instantiate the object
    il2cpp::Il2CppObject* texture2D = il2cpp::object_new(texture2DClass);

    // 2. Setup arguments for Constructor: Texture2D(int width, int height, TextureFormat format, bool mipChain)
    il2cpp::Il2CppException* exception = nullptr;
    int textureFormatInt = 4; // RGBA32
    bool mipChain = false;    // No mipmaps to prevent overread exceptions

    void* constructorParams[4]; 
    constructorParams[0] = &width; 
    constructorParams[1] = &height; 
    constructorParams[2] = &textureFormatInt; 
    constructorParams[3] = &mipChain;


    // il2cpp::runtime_invoke(texture2D_ctor, texture2D, constructorParams, &exception);
    Texture2D.Invoke(".ctor_P4I1", texture2D, &width, &height, &textureFormatInt, &mipChain);
    Texture2D.Invoke("LoadRawTextureData_P1", texture2D, byteArray);


    if (exception) {
        MYO_LOG("testmod", "Exception in LoadRawTextureData! Provided size: {}", size);
        return nullptr;
    }

    // // 4. Call Apply()
    // il2cpp::runtime_invoke(texture2D_Apply, texture2D, nullptr, &exception);
    Texture2D.Invoke("Apply_P0", texture2D, nullptr);

    // // // free the pixels!! free them!!
    stbi_image_free(pixels);

    il2cpp::gchandle_new(texture2D, false);
    // return our new texture 2D! Tada!
    return texture2D;
}

il2cpp::Il2CppObject* CreateSpriteFromTexture2D(il2cpp::Il2CppObject* texture2D, float xPivot, float yPivot) {

    ClassCache texture2DCache = GetClass("Texture2D");
    ClassCache textureCache = GetClass("Texture");
    ClassCache rectCache = GetClass("Rect");
    ClassCache vector2Cache = GetClass("Vector2");
    ClassCache spriteCache = GetClass("Sprite");
    
    // get the height and width of the texture2d
    il2cpp::Il2CppObject* width = textureCache.Invoke("get_width", texture2D, nullptr);
    il2cpp::Il2CppObject* height = textureCache.Invoke("get_height", texture2D, nullptr);
    
    if (!width) MYO_LOG("testmod", "width no exist create sprite");
    if (!height) MYO_LOG("testmod", "width no exist create sprite");
   

    // create the rect 2 for the Create function
    il2cpp::Il2CppObject* rect = il2cpp::object_new(rectClass);
    float xPosRect = 0.0f; float yPosRect = 0.0f; 
    float widthRect = static_cast<float>(unbox<int32_t>(width));
    float heightRect = static_cast<float>(unbox<int32_t>(height));
    // widthRect = 0.0f;
    // heightRect = 0.0f;

    void* rectUnboxed = il2cpp::object_unbox(rect);

    // il2cpp::runtime_invoke(rect_ctor, rectUnboxed, paramsRect, nullptr);
    rectCache.Invoke(".ctor_P4", rect, &xPosRect, &yPosRect, &widthRect, &heightRect);

    // create the vector 2 for the Crea te function
    il2cpp::Il2CppObject* vector2 = il2cpp::object_new(vector2Class);
    xPivot = 0.5f; yPivot = 0.5f;
    vector2Cache.Invoke(".ctor", vector2, &xPivot, &yPivot);
    void* vector2Unboxed = il2cpp::object_unbox(vector2);

    // create the sprite and return it! hooray!

    if (!texture2D) MYO_LOG("testmod", "pardon, but texture don't exist");
    if (!rectUnboxed) MYO_LOG("testmod", "pardon, but rect don't exist");
    if (!vector2Unboxed) MYO_LOG("testmod", "pardon, but vector2 don't exist");

    void* exc = nullptr;
    // il2cpp::Il2CppObject* sprite = il2cpp::runtime_invoke(sprite_Create, nullptr, params1, &exc);
    il2cpp::Il2CppObject* sprite = GetClass("Sprite").Invoke("Create_P3I1", nullptr, texture2D, rectUnboxed, vector2Unboxed);
     
    if (exc){
        MYO_LOG("testmod", "wuh oh, an exception took place! everyone run!");
    } else {
        il2cpp::gchandle_new(sprite, false);
    }

    if (!sprite) {
        MYO_LOG("testmod", "Sprite.Create failed.");
    }

    il2cpp::Il2CppObject* checkTexture = spriteCache.Invoke("get_texture", sprite, nullptr);
    il2cpp::Il2CppObject* checkPivot = spriteCache.Invoke("get_pivot", sprite, nullptr);
    il2cpp::Il2CppObject* checkRect = spriteCache.Invoke("get_rect", sprite, nullptr);

    if (!checkTexture) MYO_LOG("testmod", "texture could not be found");
    if (!checkPivot) MYO_LOG("testmod", "pivot could not be found");
    if (!checkRect) MYO_LOG("testmod", "rect could not be found");

    return sprite; // is this it? i think so!
}

il2cpp::Il2CppObject* CreateSpriteFromImg(const char* filePath, float xPivot, float yPivot) {
    il2cpp::Il2CppObject* texture2D = CreateTexture2D(filePath);
    il2cpp::Il2CppObject* sprite = CreateSpriteFromTexture2D(texture2D, xPivot, yPivot);
    return sprite;
}

// System.Int32 index, System.Action<System.Int32,System.Boolean,MainUI.FormationPersonalityUI,System.Boolean> panelCallback, MainUI.FormationUIEnterManager enterManager
void hooked_FormationPersonalityUI_Init(il2cpp::Il2CppObject* __this, int32_t index, void* panelCallback, void* enterManager) {
    MYO_LOG("HermesUnity", "Initialize");
    original_FormationPersonalityUI_Init(__this, index, panelCallback, enterManager);
    MYO_LOG("HermesUnity", "Initialize");
}

// MainUI.FormationPersonalityUIParameters parameters
void hooked_FormationPersonalityUI_SetData1(il2cpp::Il2CppObject* __this, void* parameters) {
    MYO_LOG("HermesUnity", "SetData1");
    original_FormationPersonalityUI_SetData1(__this, parameters);
    MYO_LOG("HermesUnity", "SetData1");
    il2cpp::Il2CppObject* img = GetFieldInObj<il2cpp::Il2CppObject*>(__this, GetClass("FormationPersonalityUI").klass, "img_portrait"); // UI Image
    void* params[1]; params[0] = CreateSpriteFromImg("hermesMod/assets/MoFullBody.png");
    runtime_invoke(GetClass("Image").GetMethod("set_sprite"), img, params);
    MYO_LOG("HermesUnity", "Please tell me you worked~");

}

// PersonalityStaticData personalityStaticData, System.Int32 personalityLevel, System.Int32 personalityGacksung, System.Boolean isGacksungIllust, System.Collections.Generic.List<T> egoList, System.Collections.Generic.Dictionary<ATTRIBUTE_TYPE,System.Int32> personalitySkillDict, System.Boolean isNotCharacterUpdated, LimbusCompany.Data.Character.CharacterIconSet characterIconSet, System.Int32 skinId
void hooked_FormationPersonalityUI_SetData2(il2cpp::Il2CppObject* __this, void* personalityStaticData, int32_t personalityLevel, int32_t personalityGacksung, bool isGacksungIllust, void* egoList, void* personalitySkillDict, bool isNotCharacterUpdated, void* characterIconSet, int32_t skinId) {
    MYO_LOG("HermesUnity", "SetData2 - Level: {}, Gacksung: {}", personalityLevel, personalityGacksung);
    original_FormationPersonalityUI_SetData2(__this, personalityStaticData, personalityLevel, personalityGacksung, isGacksungIllust, egoList, personalitySkillDict, isNotCharacterUpdated, characterIconSet, skinId);
    MYO_LOG("HermesUnity", "SetData2 - Level: {}, Gacksung: {}", personalityLevel, personalityGacksung);
}


void init_unity_objects(il2cpp::Il2CppImage* img, const char* namespaze, il2cpp::Il2CppImage* unityImg, il2cpp::Il2CppImage* corImg, il2cpp::Il2CppImage* unityUImg) {
    byteClass = il2cpp::class_from_name(corImg, "System", "Byte");


    csByteListClass = get_return_class_from_method(jsonNode_getAsByteList);
    csByteList_ctor = il2cpp::class_get_method_from_name(csByteListClass, ".ctor", 0);
    csByteList_Add = il2cpp::class_get_method_from_name(csByteListClass, "Add", 1);
    csByteList_ToArray = il2cpp::class_get_method_from_name(csByteListClass, "ToArray", 0);
    csByteList_getCount = il2cpp::class_get_method_from_name(csByteListClass, "get_Count", 0);
    
    rectClass = il2cpp::class_from_name(unityImg, "UnityEngine", "Rect");
    rect_ctor = il2cpp::class_get_method_from_name(rectClass, ".ctor", 4);
    rect_getWidth = il2cpp::class_get_method_from_name(rectClass, "get_width", 0);
    rect_getHeight = il2cpp::class_get_method_from_name(rectClass, "get_height", 0);
    rect_getX = il2cpp::class_get_method_from_name(rectClass, "get_x", 0);
    rect_getY = il2cpp::class_get_method_from_name(rectClass, "get_y", 0);

    vector2Class = il2cpp::class_from_name(unityImg, "UnityEngine", "Vector2");
    vector2_ctor = il2cpp::class_get_method_from_name(vector2Class, ".ctor", 2);

    colorClass = il2cpp::class_from_name(unityImg, "UnityEngine", "Color");
    color_r = il2cpp::class_get_field_from_name(colorClass, "r");
    color_g = il2cpp::class_get_field_from_name(colorClass, "g");
    color_b = il2cpp::class_get_field_from_name(colorClass, "b");
    color_a = il2cpp::class_get_field_from_name(colorClass, "a");
    
    texture2DClass = il2cpp::class_from_name(unityImg, "UnityEngine", "Texture2D");
    texture2D_Apply = il2cpp::class_get_method_from_name(texture2DClass, "Apply", 0);
    texture2D_LoadRawTextureData = il2cpp::class_get_method_from_name(texture2DClass, "LoadRawTextureData", 1);
    texture2D_Resize = il2cpp::class_get_method_from_name(texture2DClass, "Resize", 2);
    texture2D_getWidth = il2cpp::class_get_method_from_name(texture2DClass, "get_width", 0);
    texture2D_getHeight = il2cpp::class_get_method_from_name(texture2DClass, "get_height", 0);
    texture2D_GetPixel = il2cpp::class_get_method_from_name(texture2DClass, "GetPixel", 2);
    texture2D_Reinitialize = il2cpp::class_get_method_from_name(texture2DClass, "Resize", 4);
    texture2D_CreateExternalTexture = il2cpp::class_get_method_from_name(texture2DClass, "CreateExternalTexture", 6);
    texture2D_getIsReadable = il2cpp::class_get_method_from_name(texture2DClass, "get_isReadable", 0);

    

    int mIndex = 0;
    void* m2Iter = nullptr;
    while (auto* m = il2cpp::class_get_methods(texture2DClass, &m2Iter)) {
        if (mIndex == 81) {
            texture2D_ctor = m;
            const char* mpn = il2cpp::method_get_name(m);
        }
        mIndex++;
    }

    spriteClass = il2cpp::class_from_name(unityImg, "UnityEngine", "Sprite");
    sprite_getTexture = il2cpp::class_get_method_from_name(spriteClass, "get_texture", 0);
    sprite_getPivot = il2cpp::class_get_method_from_name(spriteClass, "get_pivot", 0);
    sprite_getRect = il2cpp::class_get_method_from_name(spriteClass, "get_rect", 0);
    sprite_Create = il2cpp::class_get_method_from_name(spriteClass, "Create", 3);

    mIndex = 0;
    m2Iter = nullptr;
    while (auto* m = il2cpp::class_get_methods(spriteClass, &m2Iter)) {
        if (mIndex == 55) {
            sprite_Create = m;
            const char* mpn = il2cpp::method_get_name(m);
            MYO_LOG("testmod", "m = {}", mpn);
        }
        mIndex++;
    }

    uiImageClass = il2cpp::class_from_name(unityImg, "UnityEngine.UI", "Image");
    uiImage_setSprite = il2cpp::class_get_method_from_name(spriteClass, "set_sprite", 1);

    // REgister necessary classes for MY purposes. 
    ClassCache texture2dcache = RegisterClassFull("Texture2D", unityImg, "UnityEngine", "Texture2D");
    ClassCache textureCache = RegisterClassFull("Texture", unityImg, "UnityEngine", "Texture");
    RegisterClassFull("Sprite", unityImg, "UnityEngine", "Sprite");
    RegisterClassFull("Rect", unityImg, "UnityEngine", "Rect");
    RegisterClassFull("Vector2", unityImg, "UnityEngine", "Vector2");
    RegisterClassFull("Image", unityUImg, "UnityEngine.UI", "Image");

    
    // Main UI things
    ClassCache formationUI = RegisterClassFull("FormationPersonalityUI", img, "MainUI", "FormationPersonalityUI");
    // ClassCache formationParam = RegisterClassFull("")

    // original_FormationPersonalityUI_Init = InstallHook<FormationPersonalityUIInitFn>(formationUI.GetMethod("Initialize"), &hooked_FormationPersonalityUI_Init);
    // original_FormationPersonalityUI_SetData1 = InstallHook<BaseMethod1Void>(formationUI.GetMethod("SetData_P1"), &hooked_FormationPersonalityUI_SetData1);
    // original_FormationPersonalityUI_SetData2 = InstallHook<FormationPersonalityUISetData2>(formationUI.GetMethod("SetData_P9"), &hooked_FormationPersonalityUI_SetData2);
    
    // texture2DMo = CreateTexture2D("hermesMod/assets/MoFullBody.png");
    // spriteMo = CreateSpriteFromTexture2D(texture2DMo);
    
}   


// run this on the unity main thread ONCE!! ONLY ONE TIME!!
void init_unity_main_thread() {
    texture2DMo = CreateTexture2D("hermesMod/assets/MoFullBody.png");
    spriteMo = CreateSpriteFromTexture2D(texture2DMo);
    if (!spriteMo) {
        MYO_LOG("testmod", "Sprite Mo was not successfully created, bc flip you");
    }
}


}