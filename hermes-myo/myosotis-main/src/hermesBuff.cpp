#include "il2cpp.hpp"
#include "log.hpp"
#include "hermesBuff.hpp"
#include "hermesBattleUnit.hpp"
#include "hermesStage.hpp"

#include "hook.hpp"

namespace myosotis::testmod {

void hooked_BuffDetail_ctor(il2cpp::Il2CppObject* __this) {
    MYO_LOG("testmod", "ctor called on BuffDetail");
    original_BuffDetail_ctor(__this);
}
void hooked_BuffDetail_AddBuff(il2cpp::Il2CppObject* __this, void* unit, void* buffData, void* history, int32_t timing) {
    // BattleUnitModel unit, MediatedBuffData buffData, BuffHistory history, BATTLE_EVENT_TIMING timing
    MYO_LOG("testmod", "Buff Detail 1");
    original_BuffDetail_AddBuff(__this, unit, buffData, history, timing);
}
void hooked_BuffDetail_AddBuff2(il2cpp::Il2CppObject* __this, void* unit, int32_t newKeyword, void* historyList, int32_t activeRound, int32_t abilitySrcType, int32_t timing, void* actionOrNull, int32_t* addedStack, int32_t* addedTurn, int32_t* overStack, int32_t* overTurn, bool mainKeywordOnly) {
    // BattleUnitModel unit, BUFF_UNIQUE_KEYWORD newKeyword, System.Collections.Generic.List<BuffHistory> historyList, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, System.Int32& addedStack, System.Int32& addedTurn, System.Int32& overStack, System.Int32& overTurn, System.Boolean mainKeywordOnly

    original_BuffDetail_AddBuff2(__this, unit, newKeyword, historyList, activeRound, abilitySrcType, timing, actionOrNull, addedStack, addedTurn, overStack, overTurn, mainKeywordOnly);
    
    il2cpp::Il2CppObject* unitDataModel = il2cpp::runtime_invoke(battleUnitModel_GetUnitDataModel, unit, nullptr, nullptr);
    il2cpp::Il2CppObject* victimNameObj = il2cpp::runtime_invoke(unitDataModel_getName, unitDataModel, nullptr, nullptr);
    std::string victimName = unbox_string(victimNameObj); 

    std::string victimDetails = std::format("[Name: {}]", victimName);

    // unbox the list and iterate
    std::vector<il2cpp::Il2CppObject*> historyVector = unbox_list_obj(historyList);
    size_t historyVSize = historyVector.size();
    std::string historyStr = "";
    for (size_t i = 0; i < historyVSize; i++) {
        il2cpp::Il2CppObject* obj = historyVector[i]; // obj will be BuffHistory
        
        // get stack + count and unbox values
        il2cpp::Il2CppObject* stackObj = il2cpp::runtime_invoke(buffHistory_GetStack, obj, nullptr, nullptr);
        il2cpp::Il2CppObject* countObj = il2cpp::runtime_invoke(buffHistory_GetTurn, obj, nullptr, nullptr);
        int32_t stack = unbox<int32_t>(stackObj);
        int32_t count = unbox<int32_t>(countObj);

        // format the values for printing
        historyStr += std::format("[Stack: {}, Count: {}]", stack, count);
    }

    // MYO_LOG("testmod", "BuffDetail2 - Victim: {}, Keyword: {}, History: {}, activeRound: {}, abilitySrcType: {}, Timing: {}, mainKeywordOnly: {}, addedStack: {}, addedTurn: {}, overStack: {}, overTurn: {}",
    //     victimDetails, newKeyword, historyStr, activeRound, abilitySrcType, timing, mainKeywordOnly, *addedStack, *addedTurn, *overStack, *overTurn);

}

void AddBuff(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t count, int32_t activeRound, int32_t src, int32_t timing) {
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
    il2cpp::Il2CppObject* buffDetailObj = nullptr;

    il2cpp::field_get_value(unit, battleUnitModel__buffDetail, &buffDetailObj);

    // initialize the buff history
    il2cpp::Il2CppObject* buffHistory = il2cpp::object_new(buffHistoryClass);

    void* params[3];
    params[0] = &stack;
    params[1] = &count;
    params[2] = &src;

    il2cpp::runtime_invoke(buffHistory_ctor, buffHistory, params, nullptr);

    // initialize the list and put buff history in it
    void* listParams[1];
    listParams[0] = buffHistory;

    il2cpp::Il2CppObject* historyList = il2cpp::object_new(csBuffHistoryListClass);
    il2cpp::runtime_invoke(buffHistoryList_ctor, historyList, nullptr, nullptr);
    il2cpp::runtime_invoke(buffHistoryList_Add, historyList, listParams, nullptr);

    int32_t overstack = 0;
    int32_t overturn = 0;
    hooked_BuffDetail_AddBuff2(
        buffDetailObj, unit, keyword, historyList, activeRound, src, timing, nullptr, &stack, &count, &overstack, &overturn, false);
}

void init_buff_stuff(il2cpp::Il2CppImage* img, const char* namespaze) {

    ClassCache BuffDetailC = RegisterClassFull("BuffDetail", img, "", "BuffDetail");

    il2cpp::Il2CppClass* buffDetailClass = il2cpp::class_from_name(img, namespaze, "BuffDetail");
    il2cpp::Il2CppClass* mediatedBuffDataClass = il2cpp::class_from_name(img, namespaze, "MediatedBuffData");
    buffHistoryClass = il2cpp::class_from_name(img, namespaze, "BuffHistory");
    
    // get methods
    il2cpp::Il2CppMethod* buffDetail_ctor = il2cpp::class_get_method_from_name(buffDetailClass, ".ctor", 0);
    buffDetail_AddBuff = il2cpp::class_get_method_from_name(buffDetailClass, "AddBuff", 4);
    buffDetail_AddBuff2 = il2cpp::class_get_method_from_name(buffDetailClass, "AddBuff", 12);

    il2cpp::Il2CppType* buffHistListType = il2cpp::method_get_param(buffDetail_AddBuff2, 2);
    csBuffHistoryListClass = il2cpp::class_from_type(buffHistListType);

    buffHistoryList_ctor = il2cpp::class_get_method_from_name(csBuffHistoryListClass, ".ctor", 0);
    buffHistoryList_Add = il2cpp::class_get_method_from_name(csBuffHistoryListClass, "Add", 1);
    
    mediatedBuffData_GetKeyword = il2cpp::class_get_method_from_name(mediatedBuffDataClass, "GetKeyword", 0);
    buffHistory_ctor = il2cpp::class_get_method_from_name(buffHistoryClass, ".ctor", 3);
    buffHistory_GetStack = il2cpp::class_get_method_from_name(buffHistoryClass, "GetStack", 0);
    buffHistory_GetTurn = il2cpp::class_get_method_from_name(buffHistoryClass, "GetTurn", 0);

    // if (buffHistoryClass) MYO_LOG("testmod", "buffHistoryClass exists");
    // if (buffHistory_GetStack) MYO_LOG("testmod", "buffHistoryClass_GetStack exists");
    // if (buffHistory_GetTurn) MYO_LOG("testmod", "buffHistoryClass exists");
    
    original_BuffDetail_ctor = reinterpret_cast<BaseMethodType>(
        hook::install_inline(buffDetail_ctor, reinterpret_cast<void*>(&hooked_BuffDetail_ctor)));
    original_BuffDetail_AddBuff = reinterpret_cast<BuffDetailAddBuffFn>(
        hook::install_inline(buffDetail_AddBuff, reinterpret_cast<void*>(&hooked_BuffDetail_AddBuff)));
    original_BuffDetail_AddBuff2 = reinterpret_cast<BuffDetailAddBuffFn2>(
        hook::install_inline(buffDetail_AddBuff2, reinterpret_cast<void*>(&hooked_BuffDetail_AddBuff2)));
}

}