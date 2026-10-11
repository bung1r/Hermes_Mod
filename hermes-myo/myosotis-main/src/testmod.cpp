#include "testmod.hpp"
#include "hook.hpp"
#include "il2cpp.hpp"
#include "log.hpp"
#include "il2cpp_names.hpp"
#include "hermesUtils.hpp"
#include "hermesStatic.hpp"
#include "hermesBuff.hpp"
#include "hermesStage.hpp"
#include "hermesJson.hpp"
#include "hermesBattleUnit.hpp"
#include "hermesLocalization.hpp"
#include "hermesUnity.hpp"

#include <windows.h>
#include <string>
#include <string_view>
#include <cstdio>
#include <iostream>
#include <codecvt>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>


namespace myosotis::testmod {
namespace {

    il2cpp::Il2CppImage* img = nullptr;
    il2cpp::Il2CppImage* jsonImg = nullptr;
    il2cpp::Il2CppImage* unityCoreImg = nullptr;
    il2cpp::Il2CppImage* mscorlibImg = nullptr;
    il2cpp::Il2CppImage* unityUIImg = nullptr;

    il2cpp::Il2CppClass* cSharpListClass = nullptr;
   
    
    il2cpp::Il2CppClass* int32List = nullptr;
    il2cpp::Il2CppClass* cSharpList_Add = nullptr;

    // COIN MODEL STUFF
    
    using BaseMethodTypeFloat = void(*)(il2cpp::Il2CppObject*, float);
    using CoinModelBasicRollFn = void(*)(il2cpp::Il2CppObject*, float, void*);
    using CoinModelParryFn = void(*)(il2cpp::Il2CppObject*, float, void*, void*);
    using CoinModelBattleFn = void(*)(il2cpp::Il2CppObject*, float, void*, void*, int32_t);

    il2cpp::Il2CppMethod* coinModel_Roll = nullptr;
    il2cpp::Il2CppMethod* coinModel_RollOnParrying = nullptr;
    il2cpp::Il2CppMethod* coinModel_RollOnBattle = nullptr;
    il2cpp::Il2CppMethod* coinModel_RollOnEvent = nullptr;
    il2cpp::Il2CppMethod* coinModel_RollOnAction = nullptr;
    
    CoinModelBasicRollFn original_CoinModel_Roll = nullptr;
    CoinModelParryFn original_CoinModel_RollOnParrying = nullptr;
    CoinModelBattleFn original_CoinModel_RollOnBattle = nullptr;
    BaseMethodTypeFloat original_CoinModel_RollOnEvent = nullptr;
    CoinModelBasicRollFn original_CoinModel_RollOnAction = nullptr;

    // Helper Methods 

    std::string ObjectIntoJsonString(il2cpp::Il2CppObject* obj) {
        void* params[2];
        params[0] = obj;
        params[1] = nullptr;
        il2cpp::Il2CppString* jsonStringObj = il2cpp::runtime_invoke(jsonSerializer_Serialize, nullptr, params, nullptr);
        if (jsonStringObj) MYO_LOG("testmod", "jsonStringObj exosts");
        if (jsonSerializer_Serialize) MYO_LOG("testmod", "serialize exist");
        std::string jsonString = unbox_string(jsonStringObj);
        return jsonString;
    }
    
    // is this the greatest rigging of all time?
    void hooked_CoinModel_Roll(il2cpp::Il2CppObject* __this, float prob, void* action) {
        // MYO_LOG("testmod", "Roll");
        original_CoinModel_Roll(__this, prob, action); 
    }
    void hooked_CoinModel_RollOnParrying(il2cpp::Il2CppObject* __this, float prob, void* action, void* oppoAction) {
        MYO_LOG("testmod", "RollParry");
        original_CoinModel_RollOnParrying(__this, 100.00F, action, oppoAction); 
    }
    void hooked_CoinModel_RollOnBattle(il2cpp::Il2CppObject* __this, float prob, void* action, void* oppoAction, int32_t timing) {
        // MYO_LOG("testmod", "RollBattle");
        original_CoinModel_RollOnBattle(__this, prob, action, oppoAction, timing); 
    }

    // BUFF STUFF I GUESS

    template <typename Fn>
    Fn install_hook(il2cpp::MethodInfo* method, Fn hook_fn) {
        return reinterpret_cast<Fn>(
            hook::install_inline(
                method,
                reinterpret_cast<void*>(hook_fn)
            )
        );
    }
} 



void init_coin_model(il2cpp::Il2CppImage* img, const char* namespaze) {
    il2cpp::Il2CppClass* coinModelClass = il2cpp::class_from_name(img, namespaze, "CoinModel");
    
    // get fields
    // nothing yet!

    // get methods
    coinModel_Roll = il2cpp::class_get_method_from_name(coinModelClass, "Roll", 2);
    coinModel_RollOnParrying = il2cpp::class_get_method_from_name(coinModelClass, "RollOnParrying", 3);
    coinModel_RollOnBattle = il2cpp::class_get_method_from_name(coinModelClass, "RollOnBattle", 4);
    coinModel_RollOnEvent = il2cpp::class_get_method_from_name(coinModelClass, "RollOnEvent", 1);
    coinModel_RollOnAction = il2cpp::class_get_method_from_name(coinModelClass, "RollOnAction", 2);

    // hook and get originals
    original_CoinModel_Roll = reinterpret_cast<CoinModelBasicRollFn>(
        hook::install_inline(coinModel_Roll, reinterpret_cast<void*>(&hooked_CoinModel_Roll)));

    original_CoinModel_RollOnParrying = reinterpret_cast<CoinModelParryFn>(
        hook::install_inline(coinModel_RollOnParrying, reinterpret_cast<void*>(&hooked_CoinModel_RollOnParrying)));

    original_CoinModel_RollOnBattle = reinterpret_cast<CoinModelBattleFn>(
        hook::install_inline(coinModel_RollOnBattle, reinterpret_cast<void*>(&hooked_CoinModel_RollOnBattle)));
}

void init_all() { 
    size_t asm_count = 0; 
    il2cpp::Il2CppAssembly** asms = il2cpp::domain_get_assemblies(&asm_count); 
    if (!asms) { 
        MYO_LOG_ERROR(
            "testmod",
            "domain_get_assemblies returned null"
        ); 
        return; 
    } 

    // Get Assembly-CSharp Img (Basically the class with all the Limbus stuff) 
    const int ASSEMBLY_C_SHARP_INDEX = 0; 
    const int MSCORLIB_INDEX = 1;
    const int UNITYCORE_INDEX = 3;
    const int JSON_INDEX = 18;
    const int UNITYUI_INDEX = 22;
    img = il2cpp::assembly_get_image(asms[ASSEMBLY_C_SHARP_INDEX]); 
    mscorlibImg = il2cpp::assembly_get_image(asms[MSCORLIB_INDEX]); 
    unityCoreImg = il2cpp::assembly_get_image(asms[UNITYCORE_INDEX]); 
    jsonImg = il2cpp::assembly_get_image(asms[JSON_INDEX]);
    unityUIImg = il2cpp::assembly_get_image(asms[UNITYUI_INDEX]);
    const char* img_name = il2cpp::image_get_name(img); 
    const char* jsonImg_name = il2cpp::image_get_name(jsonImg);
    MYO_LOG("testmod", "Test Mod has loaded {}, {}!", img_name, jsonImg_name); 


    // MYO_LOG("testmod", "{} successfully loaded.", classname); 
    const char* namespaze = ""; 

    // initialize the necessary stuffs
    init_coin_model(img, namespaze);

    // stuff in their own files (w organization!)
    init_utils(asms);
    init_static(img, namespaze);
    init_localization(img, namespaze, mscorlibImg);
    init_json(img, namespaze, jsonImg);
    init_battle_models(img, namespaze);
    init_buff_stuff(img, namespaze);
    init_unity_objects(img, namespaze, unityCoreImg, mscorlibImg, unityUIImg);

    std::filesystem::path my_path = std::filesystem::current_path();
    std::string path_string = my_path.string();     

    MYO_LOG("testmod", "testmod successfully loaded."); 

    MYO_LOG("testmod", "path: {}", path_string); 
} 

}

