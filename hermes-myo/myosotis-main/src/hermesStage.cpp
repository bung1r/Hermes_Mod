
#include <windows.h>

#include "il2cpp.hpp"
#include "hermesStage.hpp"
#include "hook.hpp"
#include "log.hpp"
#include "hermesBuff.hpp"

namespace myosotis::testmod {

void ClearStageInfo() {
    playerBattleUnits.clear();
    opponentBattleUnits.clear();
}
void AddBuffToAllEnemies(int32_t keyword, int32_t stack, int32_t count, int32_t activeRound, int32_t src, int32_t timing) {
    // enum ABILITY_SOURCE_TYPE
    // {
    //     System.Int32 value__;// 0x10
    //     ABILITY_SOURCE_TYPE NONE;// 0x0
    //     ABILITY_SOURCE_TYPE SKILL;// 0x0
    //     ABILITY_SOURCE_TYPE EVENT;// 0x0
    //     ABILITY_SOURCE_TYPE BUFF;// 0x0
    //     ABILITY_SOURCE_TYPE PASSIVE;// 0x0
    //     ABILITY_SOURCE_TYPE SYSTEM_ABILITY;// 0x0
    //     ABILITY_SOURCE_TYPE EGO_GIFT;// 0x0
    //     ABILITY_SOURCE_TYPE PATTERN;// 0x0
    //     ABILITY_SOURCE_TYPE STAGE;// 0x0
    //     ABILITY_SOURCE_TYPE UNIT;// 0x0
    // }

    // enum BATTLE_EVENT_TIMING
    // {
    //     System.Int32 value__;// 0x10
    //     BATTLE_EVENT_TIMING ON_START_WAVE;// 0x0
    //     BATTLE_EVENT_TIMING ON_START_ROUND;// 0x0
    //     BATTLE_EVENT_TIMING ON_CHOICE_EVENT_EFFECT_WORK;// 0x0
    //     BATTLE_EVENT_TIMING ON_AFTER_CHOICE_EVENT;// 0x0
    //     BATTLE_EVENT_TIMING ON_BATTLE_START;// 0x0
    //     BATTLE_EVENT_TIMING ON_BEFORE_START_TURN;// 0x0
    //     BATTLE_EVENT_TIMING ON_START_TURN;// 0x0
    //     BATTLE_EVENT_TIMING ON_START_DUEL;// 0x0
    //     BATTLE_EVENT_TIMING ON_WIN_DUEL;// 0x0
    //     BATTLE_EVENT_TIMING ON_LOSE_DUEL;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_DUEL;// 0x0
    //     BATTLE_EVENT_TIMING ON_START_BEHAVIOUR;// 0x0
    //     BATTLE_EVENT_TIMING ON_START_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING ON_WIN_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING ON_LOSE_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING BEFORE_ROLL_COIN_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING AFTER_ROLL_COIN_PARRYING;// 0x0
    //     BATTLE_EVENT_TIMING BEFORE_ROLL_COIN_ACTION;// 0x0
    //     BATTLE_EVENT_TIMING AFTER_ROLL_COIN_ACTION;// 0x0
    //     BATTLE_EVENT_TIMING BEFORE_GIVE_ATTACK;// 0x0
    //     BATTLE_EVENT_TIMING BEFORE_TAKE_ATTACK;// 0x0
    //     BATTLE_EVENT_TIMING ON_SUCCESS_EVADE;// 0x0
    //     BATTLE_EVENT_TIMING ON_FAIL_EVADE;// 0x0
    //     BATTLE_EVENT_TIMING ON_SUCCESS_ATTACK;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_COIN;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_ATTACK;// 0x0
    //     BATTLE_EVENT_TIMING ON_TAKE_ATTACK_DAMAGE;// 0x0
    //     BATTLE_EVENT_TIMING ON_BREAK_SELF;// 0x0
    //     BATTLE_EVENT_TIMING ON_BREAK_TARGET;// 0x0
    //     BATTLE_EVENT_TIMING ON_KILL_TARGET;// 0x0
    //     BATTLE_EVENT_TIMING ON_KILLED_OTHER_UNIT;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_BEHAVIOUR;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_TURN;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_BATTLE;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_ROUND;// 0x0
    //     BATTLE_EVENT_TIMING ON_END_WAVE;// 0x0
    //     BATTLE_EVENT_TIMING ON_DIE;// 0x0
    //     BATTLE_EVENT_TIMING NOT_PRINT;// 0x0
    //     BATTLE_EVENT_TIMING ALL_TIMING;// 0x0
    //     BATTLE_EVENT_TIMING NONE;// 0x0
    // }
            
    // size_t oppSize = opponentBattleUnits.size();
    // for (size_t i = 0; i < oppSize; i++) {
    // il2cpp::Il2CppObject* opponentBattleUnit = opponentBattleUnits[i];
    // il2cpp::Il2CppObject* buffDetailObj = nullptr;

    // il2cpp::field_get_value(opponentBattleUnit, battleUnitModel__buffDetail, &buffDetailObj);

    // // initialize the buff history
    // il2cpp::Il2CppObject* buffHistory = il2cpp::object_new(buffHistoryClass);

    // void* params[3];
    // params[0] = &stack;
    // params[1] = &count;
    // params[2] = &src;

    // il2cpp::runtime_invoke(buffHistory_ctor, buffHistory, params, nullptr);

    // // initialize the list and put buff history in it
    // void* listParams[1];
    // listParams[0] = buffHistory;

    // il2cpp::Il2CppObject* historyList = il2cpp::object_new(csBuffHistoryListClass);
    // il2cpp::runtime_invoke(buffHistoryList_ctor, historyList, nullptr, nullptr);
    // il2cpp::runtime_invoke(buffHistoryList_Add, historyList, listParams, nullptr);

    // int32_t overstack = 0;
    // int32_t overturn = 0;
    // hooked_BuffDetail_AddBuff2(
    //     buffDetailObj, opponentBattleUnit, keyword, historyList, activeRound, src, timing, nullptr, &stack, &count, &overstack, &overturn, false);
    // }
}

void hooked_StageController_ctor(il2cpp::Il2CppObject* __this) {
    if (!__this) {
        MYO_LOG("testmod", "ctor did not make obj");
        return;
    }
    original_StageController_ctor(__this);
    MYO_LOG("testmod", "ctor successful");
}
void hooked_StageController_OnRoundStart(il2cpp::Il2CppObject* __this) {
    original_StageController_OnRoundStart(__this);
    // char* value = nullptr;
    // il2cpp::field_get_value(__this, stageController__stageName, (void*)value);
    MYO_LOG("testmod", "On Round Start");
    AddBuffToAllEnemies(48, 30, 0, 0, 8, 1); // Offense Down
    AddBuffToAllEnemies(25, 30, 0, 0, 8, 1); // Defense Down
    AddBuffToAllEnemies(5, 10, 0, 0, 8, 1); // Fragility
}
void hooked_StageController_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_StageController_OnRoundEnd(__this, timing);
    // char* value = nullptr;
    // il2cpp::field_get_value(__this, stageController__stageName, (void*)value);
    // MYO_LOG("testmod", "On Round End: {}", value);
    MYO_LOG("testmod", "On Round End");
}
void hooked_StageController_OnBattleStart(il2cpp::Il2CppObject* __this) {
    original_StageController_OnBattleStart(__this);
    // char* value = nullptr;
    // il2cpp::field_get_value(__this, stageController__stageName, (void*)value);
    MYO_LOG("testmod", "On Battle Start");
}
void hooked_StageController_OnBattleEnd(il2cpp::Il2CppObject* __this) {
    original_StageController_OnBattleEnd(__this);
    // char* value = nullptr;
    // il2cpp::field_get_value(__this, stageController__stageName, (void*)value);
    MYO_LOG("testmod", "On Battle End");
}
void hooked_StageController_OnStageStart(il2cpp::Il2CppObject* __this) {
    original_StageController_OnStageStart(__this);
    // char* value = nullptr;
    // il2cpp::field_get_value(__this, stageController__stageName, (void*)value);
    MYO_LOG("testmod", "On Stage Start");
}
void hooked_StageController_OnStageEnd(il2cpp::Il2CppObject* __this) {
    original_StageController_OnStageEnd(__this);
    ClearStageInfo();
    MYO_LOG("testmod", "On Stage End");
}
void hooked_StageController_OnCompleteCommand(il2cpp::Il2CppObject* __this) {
    original_StageController_OnCompleteCommand(__this);
} 



void init_stage_controller(il2cpp::Il2CppImage* img, const char* namespaze) {
    il2cpp::Il2CppClass* stageControllerClass = il2cpp::class_from_name(img, namespaze, "StageController");
    
    // get fields
    stageController__stageName = il2cpp::class_get_field_from_name(stageControllerClass, "_stageName");

    // get methods
    stageController_ctor = il2cpp::class_get_method_from_name(stageControllerClass, ".ctor", 0);
    stageController_OnRoundStart = il2cpp::class_get_method_from_name(stageControllerClass, "StartRound", 0);
    stageController_OnRoundEnd = il2cpp::class_get_method_from_name(stageControllerClass, "OnEndRound", 0);
    stageController_OnBattleStart = il2cpp::class_get_method_from_name(stageControllerClass, "StartBattlePhase", 0);
    stageController_OnBattleEnd = il2cpp::class_get_method_from_name(stageControllerClass, "EndBattleActionPhase", 0);
    stageController_OnStageStart = il2cpp::class_get_method_from_name(stageControllerClass, "StartStage", 0);
    stageController_OnStageEnd = il2cpp::class_get_method_from_name(stageControllerClass, "EndStage", 0);
    stageController_OnCompleteCommand = il2cpp::class_get_method_from_name(stageControllerClass, "CompleteCommand", 0);

    // hook and get originals 
    // original_StageController_ctor = reinterpret_cast<BaseMethodType>(
    //     hook::install_inline(stageController_ctor, reinterpret_cast<void*>(&hooked_StageController_ctor)));
    original_StageController_OnRoundStart = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnRoundStart, reinterpret_cast<void*>(&hooked_StageController_OnRoundStart)));
    original_StageController_OnRoundEnd = reinterpret_cast<StageControllerRoundEndFn>(
        hook::install_inline(stageController_OnRoundEnd, reinterpret_cast<void*>(&hooked_StageController_OnRoundEnd)));
    original_StageController_OnBattleStart = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnBattleStart, reinterpret_cast<void*>(&hooked_StageController_OnBattleStart)));
    original_StageController_OnBattleEnd = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnBattleEnd, reinterpret_cast<void*>(&hooked_StageController_OnBattleEnd)));
    original_StageController_OnStageStart = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnStageStart, reinterpret_cast<void*>(&hooked_StageController_OnStageStart)));
    original_StageController_OnStageEnd = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnStageEnd, reinterpret_cast<void*>(&hooked_StageController_OnStageEnd)));
    original_StageController_OnCompleteCommand = reinterpret_cast<BaseMethodType>(
        hook::install_inline(stageController_OnCompleteCommand, reinterpret_cast<void*>(&hooked_StageController_OnCompleteCommand)));
}


}