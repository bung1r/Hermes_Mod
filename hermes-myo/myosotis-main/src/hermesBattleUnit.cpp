#include "il2cpp.hpp"
#include "hermesBattleUnit.hpp"
#include "hermesUtils.hpp"
#include "hermesStage.hpp"
#include "log.hpp"
#include "hook.hpp"

namespace myosotis::testmod {

void hooked_BattleUnit_ctor(il2cpp::Il2CppObject* __this, void* datamodel, int32_t instanceID, int32_t firstTurnSpeed) { 
    if (!__this) {     
        MYO_LOG("testmod", "__this does not exist"); 
        return; 
    } 
        
    if (!battleUnitModel_GetDefaultMaxHP) { 
        MYO_LOG("testmod", "target method was not initialized"); 
        return; 
    } 

    if (!original_BattleUnitModel_ctor) {
        MYO_LOG("testmod", "original constructor was not initialized");
        return;
    }
        
    MYO_LOG("testmod", "Invoking the original constructor method"); 

    // invoke the original constructor method
    original_BattleUnitModel_ctor(__this, datamodel, instanceID, firstTurnSpeed);

    MYO_LOG("testmod", "Original constructor method: Successful"); 

    // tests for the object
    il2cpp::Il2CppException* exc2 = nullptr; 
    il2cpp::Il2CppObject* obj = il2cpp::runtime_invoke(
        battleUnitModel_GetDefaultMaxHP, __this, nullptr, &exc2); 
        
    MYO_LOG("testmod","Constructor Hook: InstanceID: {} FirstTurnSpeed: {}", instanceID, firstTurnSpeed); 
        
    if (!obj) { 
        MYO_LOG("testmod", "no obj"); 
    } 

    if (exc2) { 
        MYO_LOG("testmod", "exc generated"); 
    } 

    if (obj && !exc2) { 
        int32_t value = *(int32_t*)il2cpp::object_unbox(obj); 

        il2cpp::Il2CppObject* nameObj = il2cpp::runtime_invoke(unitDataModel_getName, datamodel, nullptr, nullptr);
        il2cpp::Il2CppObject* levelObj = il2cpp::runtime_invoke(unitDataModel_getLevel, datamodel, nullptr, nullptr);

        if (!nameObj) MYO_LOG("testmod", "nameObj does not exist");
        if (!levelObj) MYO_LOG("testmod", "levelObj does not exist");

        std::string name = unbox_string(nameObj);
        int32_t level = unbox<int32_t>(levelObj);


        MYO_LOG("testmod", "Name: {}, Level: {}, InstanceID: {}, FirstTurnSpeed: {}, Value:{},", 
            name, level, instanceID, firstTurnSpeed, value); 
    } 
} 
void hooked_BattleUnitPlayer_ctor(il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t participateOrder, int32_t firstTurnSpeed, void* dungeonUnit, void* egos, void* battleLogger) {
    //UnitDataModel unitmodel, System.Int32 instanceID, System.Int32 participateOrder, System.Int32 firstTurnSpeed, Dungeon.DungeonUnitModel dungeonUnit, System.Collections.Generic.List<Ego> egos, IBattleLoggerForServer battleLogger
    original_BattleUnitModelPlayer_ctor(__this, unitmodel, instanceID, participateOrder, firstTurnSpeed, dungeonUnit, egos, battleLogger);
    playerBattleUnits.push_back(__this);
    MYO_LOG("testmod", "Unit put in playerBattleUnits vector");
    
}
void hooked_BattleUnitOpponent_ctor(il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t firstTurnSpeed, int32_t position, int32_t waveIndex) {
    // UnitDataModel unitmodel, System.Int32 instanceID, System.Int32 firstTurnSpeed, UNIT_POSITION position, System.Int32 waveIndex
    original_BattleUnitModelOpponent_ctor(__this, unitmodel, instanceID, firstTurnSpeed, position, waveIndex);
    opponentBattleUnits.push_back(__this);
    MYO_LOG("testmod", "Unit put in opponentBattleUnits vector");

}
void hooked_BattleUnit_AddBuffNonGiver(
    il2cpp::Il2CppObject* __this, int32_t newKeyword, int32_t stack, int32_t turn, int32_t activeRound, 
    int32_t abilitySrcType, int32_t timing, void* actionOrNull, int32_t* addedStack, 
    int32_t* addedTurn, int32_t* overStack, int32_t* overturn
) {
    MYO_LOG("testmod", "Keyword: {}, Stack: {}, Count: {}", 
    newKeyword, stack, turn);

    originalAddBuffNonGiver(
        __this, newKeyword, stack, turn, activeRound,
        abilitySrcType, timing, actionOrNull, addedStack,
        addedTurn, overStack, overturn
    );
}

void init_battle_models(il2cpp::Il2CppImage* img, const char* namespaze) {
    il2cpp::Il2CppClass* battleUnitModelClass = il2cpp::class_from_name(img, namespaze, "BattleUnitModel"); 
    il2cpp::Il2CppClass* battleUnitModelPlayerClass = il2cpp::class_from_name(img, namespaze, "BattleUnitModel_Player");
    il2cpp::Il2CppClass* battleUnitModelOpponentClass = il2cpp::class_from_name(img, namespaze, "BattleUnitModel_Opponent"); 

    battleUnitModel__buffDetail = il2cpp::class_get_field_from_name(battleUnitModelClass, "_buffDetail");

    il2cpp::Il2CppMethod* battleUnitModel_ctor = il2cpp::class_get_method_from_name(battleUnitModelClass, ".ctor", 3);
    il2cpp::Il2CppMethod* battleUnitModelPlayer_ctor = il2cpp::class_get_method_from_name(battleUnitModelPlayerClass, ".ctor", 7);
    il2cpp::Il2CppMethod* battleUnitModelOpponent_ctor = il2cpp::class_get_method_from_name(battleUnitModelOpponentClass, ".ctor", 5);
    battleUnitModel_GetDefaultMaxHP = il2cpp::class_get_method_from_name(battleUnitModelClass, "GetDefaultMaxHp", 0); 
    battleUnit_AddBuffNonGiver = il2cpp::class_get_method_from_name(battleUnitModelClass, "AddBuff_NonGiver", 11);
    battleUnitModel_GetUnitDataModel = il2cpp::class_get_method_from_name(battleUnitModelClass, "get_UnitDataModel", 0);


    original_BattleUnitModel_ctor = reinterpret_cast<BattleUnitCtorFn>(
        hook::install_inline(battleUnitModel_ctor, reinterpret_cast<void*>(&hooked_BattleUnit_ctor)));
    original_BattleUnitModelPlayer_ctor = reinterpret_cast<BattleUnitPlayerCtorFn>(
        hook::install_inline(battleUnitModelPlayer_ctor, reinterpret_cast<void*>(&hooked_BattleUnitPlayer_ctor)));
    original_BattleUnitModelOpponent_ctor = reinterpret_cast<BattleUnitOpponentCtorFn>(
        hook::install_inline(battleUnitModelOpponent_ctor, reinterpret_cast<void*>(&hooked_BattleUnitOpponent_ctor)));
    originalAddBuffNonGiver = reinterpret_cast<BattleUnitAddBuffNonGiverFn>(
        hook::install_inline(battleUnit_AddBuffNonGiver, reinterpret_cast<void*>(&hooked_BattleUnit_AddBuffNonGiver)));

    // -------------------------------------------------------------------------
    // ------------------ UNIT DATA MODEL STUFF --------------------------------
    // -------------------------------------------------------------------------
    
    il2cpp::Il2CppClass* unitDataModelClass = il2cpp::class_from_name(img, namespaze, "UnitDataModel");
    
    unitDataModel_getLevel = il2cpp::class_get_method_from_name(unitDataModelClass, "get_Level", 0);
    unitDataModel_getName = il2cpp::class_get_method_from_name(unitDataModelClass, "get_Name", 0);
}

}