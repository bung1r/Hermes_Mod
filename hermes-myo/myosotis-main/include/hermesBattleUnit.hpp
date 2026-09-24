#pragma once

#include "il2cpp.hpp"

namespace myosotis::testmod {
using BattleUnitAddBuffNonGiverFn = bool(*)(
    il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, void*, int32_t*, int32_t*, int32_t*, int32_t*);
using BattleUnitCtorFn = void(*)(
    il2cpp::Il2CppObject*, void*, int32_t, int32_t);
//il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t participateOrder, int32_t firstTurnSpeed, void* dungeonUnit, void* egos, void* battleLogger
using BattleUnitPlayerCtorFn = void(*)(
    il2cpp::Il2CppObject*, void*, int32_t, int32_t, int32_t, void*, void*, void*);
//il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t firstTurnSpeed, int32_t position, int32_t waveIndex
using BattleUnitOpponentCtorFn = void(*)(
    il2cpp::Il2CppObject*, void*, int32_t, int32_t, int32_t, int32_t);

inline il2cpp::Il2CppField* battleUnitModel__buffDetail = nullptr;

inline il2cpp::Il2CppMethod* battleUnitModel_GetDefaultMaxHP = nullptr; // for ctor
inline il2cpp::Il2CppMethod* battleUnitModel_GetUnitDataModel = nullptr;
inline il2cpp::Il2CppMethod* battleUnit_AddBuffNonGiver = nullptr;

inline BattleUnitCtorFn original_BattleUnitModel_ctor = nullptr; 
inline BattleUnitPlayerCtorFn original_BattleUnitModelPlayer_ctor = nullptr;
inline BattleUnitOpponentCtorFn original_BattleUnitModelOpponent_ctor = nullptr;
inline BattleUnitAddBuffNonGiverFn originalAddBuffNonGiver = nullptr;




void hooked_BattleUnit_ctor(il2cpp::Il2CppObject* __this, void* datamodel, int32_t instanceID, int32_t firstTurnSpeed);
void hooked_BattleUnitPlayer_ctor(il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t participateOrder, int32_t firstTurnSpeed, void* dungeonUnit, void* egos, void* battleLogger);
void hooked_BattleUnitOpponent_ctor(il2cpp::Il2CppObject* __this, void* unitmodel, int32_t instanceID, int32_t firstTurnSpeed, int32_t position, int32_t waveIndex);
void hooked_BattleUnit_AddBuffNonGiver(
    il2cpp::Il2CppObject* __this, int32_t newKeyword, int32_t stack, int32_t turn, int32_t activeRound, 
    int32_t abilitySrcType, int32_t timing, void* actionOrNull, int32_t* addedStack, 
    int32_t* addedTurn, int32_t* overStack, int32_t* overturn
);

void init_battle_models(il2cpp::Il2CppImage* img, const char* namespaze);

inline il2cpp::Il2CppMethod* unitDataModel_getName = nullptr;
inline il2cpp::Il2CppMethod* unitDataModel_getLevel = nullptr;
}