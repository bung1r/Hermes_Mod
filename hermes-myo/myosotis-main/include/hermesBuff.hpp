#pragma once

#include "il2cpp.hpp"
#include "hermesUtils.hpp"

// BUFF STUFF I GUESS

namespace myosotis::testmod {
inline il2cpp::Il2CppClass* csBuffHistoryListClass = nullptr;
inline il2cpp::Il2CppMethod* buffHistoryList_ctor = nullptr;
inline il2cpp::Il2CppMethod* buffHistoryList_Add = nullptr;

inline il2cpp::Il2CppClass* buffHistoryClass = nullptr;

using BuffDetailAddBuffFn = bool(*)(il2cpp::Il2CppObject*, void*, void*, void*, int32_t);
// BattleUnitModel unit, BUFF_UNIQUE_KEYWORD newKeyword, System.Collections.Generic.List<BuffHistory> historyList, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, System.Int32& addedStack, System.Int32& addedTurn, System.Int32& overStack, System.Int32& overTurn, System.Boolean mainKeywordOnly
using BuffDetailAddBuffFn2 = bool(*)(il2cpp::Il2CppObject*, void*, int32_t, void*, int32_t, int32_t, int32_t, void*, int32_t*, int32_t*, int32_t*, int32_t*, bool);

inline il2cpp::Il2CppMethod* buffHistory_ctor = nullptr;
inline il2cpp::Il2CppMethod* buffHistory_GetStack = nullptr;
inline il2cpp::Il2CppMethod* buffHistory_GetTurn = nullptr;
inline il2cpp::Il2CppMethod* mediatedBuffData_GetKeyword = nullptr;
inline il2cpp::Il2CppMethod* buffDetail_AddBuff = nullptr;
inline il2cpp::Il2CppMethod* buffDetail_AddBuff2 = nullptr;

inline BaseMethodType original_BuffDetail_ctor = nullptr; 
inline BuffDetailAddBuffFn original_BuffDetail_AddBuff = nullptr;
inline BuffDetailAddBuffFn2 original_BuffDetail_AddBuff2 = nullptr;

void hooked_BuffDetail_ctor(il2cpp::Il2CppObject* __this);
void hooked_BuffDetail_AddBuff(il2cpp::Il2CppObject* __this, void* unit, void* buffData, void* history, int32_t timing);
void hooked_BuffDetail_AddBuff2(il2cpp::Il2CppObject* __this, void* unit, int32_t newKeyword, void* historyList, int32_t activeRound, int32_t abilitySrcType, int32_t timing, void* actionOrNull, int32_t* addedStack, int32_t* addedTurn, int32_t* overStack, int32_t* overTurn, bool mainKeywordOnly);

void init_buff_stuff(il2cpp::Il2CppImage* img, const char* namespaze);

}