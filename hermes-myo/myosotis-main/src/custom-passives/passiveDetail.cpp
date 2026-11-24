#include "passiveBase.hpp"

#include "hermesUtils.hpp"

// passiveDetail.cpp
// PassiveDetail overrides the battle-relevant PassiveBase virtuals. Each one walks our custom passives,
// skips the ones that are not in activePassiveList, and forwards the call. Non-void overrides chain
// returnValue through every active passive and return the final value.
namespace myosotis::testmod {

PassiveBase* PassiveDetail::activeCustomPassive(il2cpp::Il2CppObject* passive) {
    // MYO_LOG("PassiveDetail", "Passive: {}, ActivePassiveList: {}", passive, activePassiveList);
    if (!passive || !activePassiveList) return nullptr;
    auto it = customPassiveMap.find(passive);
    if (it == customPassiveMap.end() || !it->second) return nullptr;

    ClassCache& List_PassiveModel = GetClassRef("List_PassiveModel"); // List<PassiveModel>
    ClassCache& PassiveDetailC = GetClassRef("PassiveDetail");

    // il2cpp::Il2CppObject* listFromMethod = PassiveDetailC.Invoke("GetAllActivatedPassives", passiveDetailObj);
    bool containsPassive = List_PassiveModel.InvokeUnbox<bool>("Contains", allPassiveList, passive);
    // int32_t passiveCount = List_PassiveModel.InvokeUnbox<int32_t>("get_Count", activePassiveList);
    // int32_t allPassiveCount = List_PassiveModel.InvokeUnbox<int32_t>("get_Count", allPassiveList);
    // MYO_LOG("PassiveDetail", "Contains Passive {}: {}, {}, {}", passive, containsPassive, passiveCount, allPassiveCount);
    return containsPassive ? it->second : nullptr;
}


void PassiveDetail::tryAddCustomPassive(il2cpp::Il2CppObject* passiveModel, int32_t id) {
    auto it = passiveRegistry().find(id);
    if (it == passiveRegistry().end()) return;              // not one of our custom passives
    if (customPassiveMap.contains(passiveModel)) return;    // already created, don't duplicate

    std::unique_ptr<PassiveBase> p = it->second();          // calls the lambda -> new MoPassiveN
    p->passiveObj = passiveModel;                           // bind it to the game-side object

    customPassiveList.push_back(passiveModel);
    customPassiveMap[passiveModel] = p.release();           // PassiveDetail owns it from here
    MYO_LOG("PassiveDetail", "Got PassiveModel {} of ID {}", passiveModel, id);
} // 


// C#: System.Void OnStartBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartBehaviour(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartBehaviour(action, timing);
        }
    }
}

// C#: System.Void OnSucceedAttack(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnSucceedAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnSucceedAttack(action, coin, target, finalDmg, realDmg, realHpDmg, isCritical, isWinDuel, timing);
        }
    }
}

// C#: System.Void OnRollOneCoin_AfterAttack(BattleActionModel action, CoinModel coin)
void PassiveDetail::OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRollOneCoin_AfterAttack(action, coin);
        }
    }
}

// C#: System.Void OnEndAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndAttack(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndAttack(action, timing);
        }
    }
}

// C#: System.Void OnEndAttackOtherUnit(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndAttackOtherUnit(il2cpp::Il2CppObject* attackerAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndAttackOtherUnit(attackerAction, timing);
        }
    }
}

// C#: System.Void OnStartEnemyAttack(BattleUnitModel unit, BattleActionModel opponentAction, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartEnemyAttack(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartEnemyAttack(unit, opponentAction, isWinDuel, timing);
        }
    }
}

// C#: System.Void OnEndEnemyAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndEnemyAttack(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndEnemyAttack(action, timing);
        }
    }
}

// C#: System.Void OnEndAttackPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndAttackPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndAttackPart(part, action, timing);
        }
    }
}

// C#: System.Void OnDuelAfter_BeforeLog(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDuelAfter_BeforeLog(selfAction, oppoAction, parryingCount, timing);
        }
    }
}

// C#: System.Void OnAfterParryingOnce_BeforeLog(PARRYING_RESULT result, BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAfterParryingOnce_BeforeLog(int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAfterParryingOnce_BeforeLog(result, selfAction, oppoAction, parryingCnt, timing);
        }
    }
}

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAfterParryingOnce_AfterLog(selfAction, oppoAction, timing);
        }
    }
}

// C#: System.Void OnWinParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnWinParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnWinParrying(selfAction, oppoAction, timing);
        }
    }
}

// C#: System.Void OnLoseParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnLoseParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnLoseParrying(selfAction, oppoAction, timing);
        }
    }
}

// C#: System.Void OnWinDuel(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnWinDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnWinDuel(selfAction, oppoAction, parryingCount, timing);
        }
    }
}

// C#: System.Void OnLoseDuel(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnLoseDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnLoseDuel(selfAction, oppoAction, timing);
        }
    }
}

// C#: System.Void OnLoseDuelOtherUnit(BattleActionModel loserAction, BattleActionModel winnerAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnLoseDuelOtherUnit(il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnLoseDuelOtherUnit(loserAction, winnerAction, timing);
        }
    }
}

// C#: System.Void RightBeforeGiveBuffBySkill(SkillModel skill, CoinModel coinOrNull, BUFF_UNIQUE_KEYWORD buf, System.Int32 stack, System.Int32 turn, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void PassiveDetail::RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightBeforeGiveBuffBySkill(skill, coinOrNull, buf, stack, turn, target, timing, isCritical);
        }
    }
}

// C#: System.Void RightAfterGiveBuffBySkill(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void PassiveDetail::RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterGiveBuffBySkill(action, skill, buf, originalStack, originalTurn, resultStack, resultTurn, activeRound, target, timing, isCritical);
        }
    }
}

// C#: System.Void RightAfterTakeBuffBySkill(BattleUnitModel unit, BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, BattleUnitModel giver, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, System.Int32 afterAdderStack, System.Int32 afterAdderTurn)
void PassiveDetail::RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterTakeBuffBySkill(unit, action, skill, bufKeyword, stack, turn, giver, timing, isCritical, afterAdderStack, afterAdderTurn);
        }
    }
}

// C#: System.Void RightBeforeOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightBeforeOtherUnitGiveBuffBySkill(giver, target, bufKeyword, stack, turn, skill, timing);
        }
    }
}

// C#: System.Void RightAfterOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterOtherUnitGiveBuffBySkill(giver, target, bufKeyword, stack, turn, skill, timing);
        }
    }
}

// C#: System.Void RightAfterAnyUnitGetAnyBuff(BattleUnitModel receiver, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, BattleUnitModel giverOrNull, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, System.Int32 overStack, System.Int32 overTurn)
void PassiveDetail::RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterAnyUnitGetAnyBuff(receiver, bufKeyword, stack, turn, activeRound, giverOrNull, srcType, timing, overStack, overTurn);
        }
    }
}

// C#: System.Void RightAfterLosingBuff(System.Int32 loseStack, System.Int32 loseTurn, BuffInfo loseBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightAfterLosingBuff(int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterLosingBuff(loseStack, loseTurn, loseBuffInfo, timing);
        }
    }
}

// C#: System.Void OnSucceedToGiveSwitchToSpecialVibration(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 prevStack, System.Int32 prevTurn, System.Int32 afterStack, System.Int32 afterTurn, System.Boolean isPileUp, BATTLE_EVENT_TIMING timing, ABILITY_SOURCE_TYPE abilitySourceType)
void PassiveDetail::OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnSucceedToGiveSwitchToSpecialVibration(target, keyword, prevStack, prevTurn, afterStack, afterTurn, isPileUp, timing, abilitySourceType);
        }
    }
}

// C#: System.Void RightAfterGetAnyBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void PassiveDetail::RightAfterGetAnyBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterGetAnyBuff(keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
        }
    }
}

// C#: System.Void RightAfterGetAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull)
void PassiveDetail::RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterGetAnyBuffAtPart(part, keyword, stack, activeRound, srcType, timing, giverOrNull, actionOrNull);
        }
    }
}

// C#: System.Void RightAfterDestroyAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterDestroyAnyBuffAtPart(part, destroyedBuffInfo, timing);
        }
    }
}

// C#: System.Int32 GetAggroAdder(SinActionModel sinaction)
int32_t PassiveDetail::GetAggroAdder(int32_t returnValue, il2cpp::Il2CppObject* sinaction) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAggroAdder(returnValue, sinaction);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetAttackWeightAdder(BattleActionModel action)
int32_t PassiveDetail::GetAttackWeightAdder(int32_t returnValue, il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttackWeightAdder(returnValue, action);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMentalSystemResultIncreaseAdder()
int32_t PassiveDetail::GetMentalSystemResultIncreaseAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMentalSystemResultIncreaseAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMentalSystemResultDecreaseAdder()
int32_t PassiveDetail::GetMentalSystemResultDecreaseAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMentalSystemResultDecreaseAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetInitBuffMaxStackAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveDetail::GetInitBuffMaxStackAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetInitBuffMaxStackAdder(returnValue, unit, keyword);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetInitBuffMaxTurnAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveDetail::GetInitBuffMaxTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetInitBuffMaxTurnAdder(returnValue, unit, keyword);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffTurnAdderOtherUnit(BattleUnitModel taker, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::GetTakeBuffTurnAdderOtherUnit(int32_t returnValue, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBuffTurnAdderOtherUnit(returnValue, taker, action, keyword, originalTurn, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffStackAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originStack, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::GetTakeBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBuffStackAdder(returnValue, action, skill, buf, originStack, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffTurnAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::GetTakeBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBuffTurnAdder(returnValue, action, skill, buf, originalTurn, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetGiveBuffTurnAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::GetGiveBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetGiveBuffTurnAdder(returnValue, action, skill, coinOrNull, target, buf, currentStack, currentTurn, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetGiveBuffStackAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
int32_t PassiveDetail::GetGiveBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetGiveBuffStackAdder(returnValue, action, skill, coinOrNull, target, buf, currentStack, currentTurn, activeRound, timing, isCritical);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetUseBuffTurnAdder(BattleActionModel action, SkillModel skill, System.Int32 turn, BUFF_UNIQUE_KEYWORD buf)
int32_t PassiveDetail::GetUseBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetUseBuffTurnAdder(returnValue, action, skill, turn, buf);
        }
    }
    return returnValue;
}

// C#: System.Single GetTakeBuffStackMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float PassiveDetail::GetTakeBuffStackMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBuffStackMultiplier(returnValue, skill, buf);
        }
    }
    return returnValue;
}

// C#: System.Single GetTakeBuffTurnMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float PassiveDetail::GetTakeBuffTurnMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBuffTurnMultiplier(returnValue, skill, buf);
        }
    }
    return returnValue;
}

// C#: System.Void OnActivateSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 takeDmg, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced, System.Nullable<System.Boolean> isCritical)
void PassiveDetail::OnActivateSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnActivateSinBuffEffect(unit, keyword, stack, turn, takeDmg, giverOrNull, actionOrNull, timing, isForced, isCritical);
        }
    }
}

// C#: System.Void OnActivateOtherUnitSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, System.Int32 takeDmg, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced)
void PassiveDetail::OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnActivateOtherUnitSinBuffEffect(unit, keyword, buffOwner, takeDmg, actionOrNull, timing, isForced);
        }
    }
}

// C#: System.Boolean IgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IgnoreSinBuffHpDamage(bool returnValue, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IgnoreSinBuffHpDamage(returnValue, keyword, dmg, isForeced, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean IgnoreSinBuffHpDamagePart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IgnoreSinBuffHpDamagePart(bool returnValue, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IgnoreSinBuffHpDamagePart(returnValue, part, keyword, dmg, isForeced, timing);
        }
    }
    return returnValue;
}

// C#: System.Void OnIgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnIgnoreSinBuffHpDamage(int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnIgnoreSinBuffHpDamage(keyword, dmg, isForeced, timing);
        }
    }
}

// C#: System.Int32 GetSinBuffDamageAdder(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg)
int32_t PassiveDetail::GetSinBuffDamageAdder(int32_t returnValue, int32_t keyword, int32_t dmg) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSinBuffDamageAdder(returnValue, keyword, dmg);
        }
    }
    return returnValue;
}

// C#: System.Single GetSinBuffDamageMultiplier(BUFF_UNIQUE_KEYWORD keyword)
float PassiveDetail::GetSinBuffDamageMultiplier(float returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSinBuffDamageMultiplier(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMaxBuffStackAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveDetail::GetMaxBuffStackAdder(int32_t returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxBuffStackAdder(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMaxBuffTurnAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveDetail::GetMaxBuffTurnAdder(int32_t returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxBuffTurnAdder(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetUnitStatLevelAdder()
int32_t PassiveDetail::GetUnitStatLevelAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetUnitStatLevelAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull, BattleUnitModel target)
float PassiveDetail::GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetGiveBsGaugeUpMultiplier(returnValue, onGiveExplosion, actionOrNull, coinOrNull, target);
        }
    }
    return returnValue;
}

// C#: System.Single GetTakeBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull)
float PassiveDetail::GetTakeBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeBsGaugeUpMultiplier(returnValue, onGiveExplosion, actionOrNull, coinOrNull);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPoolCountAdder(System.Int32 index, UnitAttribute attribute)
int32_t PassiveDetail::GetSkillPoolCountAdder(int32_t returnValue, int32_t index, il2cpp::Il2CppObject* attribute) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSkillPoolCountAdder(returnValue, index, attribute);
        }
    }
    return returnValue;
}

// C#: System.Void OnDestroy(BattleUnitModel destroyerOrNull, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDestroy(il2cpp::Il2CppObject* destroyerOrNull, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDestroy(destroyerOrNull, timing);
        }
    }
}

// C#: System.Void OnOtherPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart)
void PassiveDetail::OnOtherPartDestroyed(il2cpp::Il2CppObject* destroyedPart) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnOtherPartDestroyed(destroyedPart);
        }
    }
}

// C#: System.Void OnPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnPartDestroyed(il2cpp::Il2CppObject* destroyedPart, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPartDestroyed(destroyedPart, timing);
        }
    }
}

// C#: System.Void OnPartBreaked(BattleUnitModel_Abnormality_Part breakedPart, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnPartBreaked(il2cpp::Il2CppObject* breakedPart, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPartBreaked(breakedPart, timing);
        }
    }
}

// C#: System.Void OnPartRecoverBreak(BattleUnitModel_Abnormality_Part recoveredPart, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnPartRecoverBreak(il2cpp::Il2CppObject* recoveredPart, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPartRecoverBreak(recoveredPart, timing);
        }
    }
}

// C#: System.Void OnRegenerate(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRegenerate(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRegenerate(timing);
        }
    }
}

// C#: System.Void OnPartRegenerate(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnPartRegenerate(il2cpp::Il2CppObject* part, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPartRegenerate(part, timing);
        }
    }
}

// C#: System.Boolean CheckUnitGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveDetail::CheckUnitGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckUnitGivingBuffCategory(returnValue, category, targetType, stackGiver, turnGiver);
        }
    }
    return returnValue;
}

// C#: System.Boolean CheckUnitGivingBuffKeyword(BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveDetail::CheckUnitGivingBuffKeyword(bool returnValue, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckUnitGivingBuffKeyword(returnValue, keyword, targetType, stackGiver, turnGiver);
        }
    }
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuffCategory(BattleActionModel action, BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveDetail::CheckSkillGivingBuffCategory(bool returnValue, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckSkillGivingBuffCategory(returnValue, action, category, targetType, stackGiver, turnGiver);
        }
    }
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuff(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveDetail::CheckSkillGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckSkillGivingBuff(returnValue, action, keyword, targetType, stackGiver, turnGiver);
        }
    }
    return returnValue;
}

// C#: System.Void CheckLoseBuffStackAndTurn(BuffInfo info, System.Int32& loseStack, System.Int32& loseTurn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->CheckLoseBuffStackAndTurn(info, loseStack, loseTurn, timing);
        }
    }
}

// C#: System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin)
int32_t PassiveDetail::GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin) {
    MYO_LOG("PassiveDetail", "DOES GET COIN SCALE ADDER EVEN EXIST???");
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetCoinScaleAdder(returnValue, action, oppoActionOrNull, coin);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, SinActionModel expectedTargetSinActionOrNull)
int32_t PassiveDetail::GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedCoinScaleAdder(returnValue, action, coin, expectedTargetSinActionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPowerResultAdder(BattleActionModel action, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::GetSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSkillPowerResultAdder(returnValue, action, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeHpDmgAdder()
int32_t PassiveDetail::GetTakeHpDmgAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeHpDmgAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedTakeHpDmgAdder()
int32_t PassiveDetail::GetExpectedTakeHpDmgAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedTakeHpDmgAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMinSpeedAdder()
int32_t PassiveDetail::GetMinSpeedAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMinSpeedAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMaxSpeedAdder()
int32_t PassiveDetail::GetMaxSpeedAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxSpeedAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetSpeedAdder()
int32_t PassiveDetail::GetSpeedAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSpeedAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean UseOnlyDefaultMinSpeed()
bool PassiveDetail::UseOnlyDefaultMinSpeed(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->UseOnlyDefaultMinSpeed(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean UseOnlyDefaultMaxSpeed()
bool PassiveDetail::UseOnlyDefaultMaxSpeed(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->UseOnlyDefaultMaxSpeed(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 ChangeAttackDamage(BattleActionModel action, BattleUnitModel target, CoinModel coin, System.Int32 resultDmg, System.Boolean& isCritical, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged)
int32_t PassiveDetail::ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->ChangeAttackDamage(returnValue, action, target, coin, resultDmg, isCritical, timing, isChanged);
        }
    }
    return returnValue;
}

// C#: System.Int32 ChangeTakeDamage(BattleActionModel action, CoinModel coinOrNull, System.Int32 resultDmg, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged, System.Int32 preCalculatedDmg)
int32_t PassiveDetail::ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->ChangeTakeDamage(returnValue, action, coinOrNull, resultDmg, dmgSrcType, keyword, timing, isChanged, preCalculatedDmg);
        }
    }
    return returnValue;
}

// C#: System.Int32 ChangeMpDamage(System.Int32 resultDmg, BattleActionModel actionOrNull, BASE_MENTAL_CONDITION mentalConditionOrNone, BUFF_UNIQUE_KEYWORD keywordOrNone, AbilityBase abilityOrNull, System.Boolean& isChanged, BATTLE_EVENT_TIMING timing)
int32_t PassiveDetail::ChangeMpDamage(int32_t returnValue, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->ChangeMpDamage(returnValue, resultDmg, actionOrNull, mentalConditionOrNone, keywordOrNone, abilityOrNull, isChanged, timing);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetAttackHpDmgAdder(BattleUnitModel target)
int32_t PassiveDetail::GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttackHpDmgAdder(returnValue, target);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackHpDmgAdder(BattleUnitModel target)
int32_t PassiveDetail::GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedAttackHpDmgAdder(returnValue, target);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetAttackDmgAdder(BattleActionModel action, BattleUnitModel target)
int32_t PassiveDetail::GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttackDmgAdder(returnValue, action, target);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackDmgAdder(BattleActionModel action, BattleUnitModel targetOrNull)
int32_t PassiveDetail::GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedAttackDmgAdder(returnValue, action, targetOrNull);
        }
    }
    return returnValue;
}

// C#: System.Single GetAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical)
float PassiveDetail::GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttackDmgMultiplier(returnValue, action, coin, target, isWinDuel, isCritical);
        }
    }
    return returnValue;
}

// C#: System.Single GetExpectedAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
float PassiveDetail::GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedAttackDmgMultiplier(returnValue, action, coin, targetOrNull, targetSinActionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t PassiveDetail::GetTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeAttackDmgAdder(returnValue, action, attacker);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t PassiveDetail::GetExpectedTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedTakeAttackDmgAdder(returnValue, action, attacker);
        }
    }
    return returnValue;
}

// C#: System.Single GetTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker, System.Boolean isCritical)
float PassiveDetail::GetTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeAttackDmgMultiplier(returnValue, action, attacker, isCritical);
        }
    }
    return returnValue;
}

// C#: System.Single GetExpectedTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker)
float PassiveDetail::GetExpectedTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedTakeAttackDmgMultiplier(returnValue, action, attacker);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetAttackAdder(BattleActionModel actionOrNull)
int32_t PassiveDetail::GetAttackAdder(int32_t returnValue, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttackAdder(returnValue, actionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetUnitDefaultLevelAdder()
int32_t PassiveDetail::GetUnitDefaultLevelAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetUnitDefaultLevelAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetDefenseAdder()
int32_t PassiveDetail::GetDefenseAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetDefenseAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetUnitDefenseAdder()
int32_t PassiveDetail::GetUnitDefenseAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetUnitDefenseAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetDefenseMultiplier()
float PassiveDetail::GetDefenseMultiplier(float returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetDefenseMultiplier(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetHpHealMultiplier(BattleUnitModel target)
float PassiveDetail::GetHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* target) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetHpHealMultiplier(returnValue, target);
        }
    }
    return returnValue;
}

// C#: System.Single GetAtkResistMultiplier(ATK_BEHAVIOUR type)
float PassiveDetail::GetAtkResistMultiplier(float returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAtkResistMultiplier(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Single GetAtkResistAdder(ATK_BEHAVIOUR type)
float PassiveDetail::GetAtkResistAdder(float returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAtkResistAdder(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Single GetAttributeResistMultiplier(ATTRIBUTE_TYPE type)
float PassiveDetail::GetAttributeResistMultiplier(float returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttributeResistMultiplier(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Single GetAttributeResistAdder(ATTRIBUTE_TYPE type)
float PassiveDetail::GetAttributeResistAdder(float returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetAttributeResistAdder(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Void OnDie(BattleUnitModel killer, BattleActionModel actionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDie(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDie(killer, actionOrNull, dmgSrcType, keyword, timing);
        }
    }
}

// C#: System.Void OnBreak(BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void PassiveDetail::OnBreak(il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBreak(attackerOrNull, actionOrNull, timing, isBreakForcely);
        }
    }
}

// C#: System.Void OnEnemyBrokenByAttacker(BattleActionModel actionOrNull, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEnemyBrokenByAttacker(actionOrNull, target, timing);
        }
    }
}

// C#: System.Void OnDieOtherUnit(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnDieOtherUnit(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDieOtherUnit(killer, dead, timing, dmgSrcType, keyword);
        }
    }
}

// C#: System.Void OnDieOtherUnit_Retreated(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDieOtherUnit_Retreated(killer, dead, timing, dmgSrcType, keyword);
        }
    }
}

// C#: System.Void OnDieOtherUnit_Disappeared(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDieOtherUnit_Disappeared(killer, dead, timing, dmgSrcType, keyword);
        }
    }
}

// C#: System.Void OnRetreatOtherUnit(BattleUnitModel retreatUnit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRetreatOtherUnit(il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRetreatOtherUnit(retreatUnit, keyword, timing);
        }
    }
}

// C#: System.Void OnRetreatOtherUnit_Retreated(BattleUnitModel retreatUnit, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* retreatUnit, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRetreatOtherUnit_Retreated(retreatUnit, timing);
        }
    }
}

// C#: System.Void OnDiscardSinOtherUnit(BattleUnitModel discardUnit, UnitSinModel sin, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveDetail::OnDiscardSinOtherUnit(il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDiscardSinOtherUnit(discardUnit, sin, timing, actionOrNull);
        }
    }
}

// C#: System.Void OnDiscardSin(UnitSinModel sin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDiscardSin(il2cpp::Il2CppObject* sin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDiscardSin(sin, timing);
        }
    }
}

// C#: System.Void OnDisappeared(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDisappeared(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDisappeared(timing);
        }
    }
}

// C#: System.Void OnReturnFromDisappeared(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnReturnFromDisappeared(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReturnFromDisappeared(timing);
        }
    }
}

// C#: System.Void OnBreakOtherUnit(BattleUnitModel breakedUnit, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void PassiveDetail::OnBreakOtherUnit(il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBreakOtherUnit(breakedUnit, timing, isBreakForcely);
        }
    }
}

// C#: System.Void OnCheckBreak(System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void PassiveDetail::OnCheckBreak(il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnCheckBreak(usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
        }
    }
}

// C#: System.Void OnCheckPartBreak(BattleUnitModel_Abnormality_Part breakedPart, System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void PassiveDetail::OnCheckPartBreak(il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnCheckPartBreak(breakedPart, usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
        }
    }
}

// C#: System.Void OnVibrationExplosion(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnVibrationExplosion(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnVibrationExplosion(explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
        }
    }
}

// C#: System.Void OnVibrationExplosionOtherUnit(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnVibrationExplosionOtherUnit(explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
        }
    }
}

// C#: System.Void OnTakeAttackDamageOtherUnit(BattleActionModel action, System.Int32 realDmg, System.Int32 hpDmg, BattleUnitModel attackedUnit, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeAttackDamageOtherUnit(action, realDmg, hpDmg, attackedUnit, timing);
        }
    }
}

// C#: System.Void OnUseBuffStackBySkill(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnUseBuffStackBySkill(il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnUseBuffStackBySkill(action, keyword, stack, timing);
        }
    }
}

// C#: System.Void OnUseBloodDinnerUnit(BattleUnitModel usedUnit, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnUseBloodDinnerUnit(il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnUseBloodDinnerUnit(usedUnit, stack, timing);
        }
    }
}

// C#: System.Void OnAddUnit(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAddUnit(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddUnit(timing);
        }
    }
}

// C#: System.Void OnAddUnit_After(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAddUnit_After(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddUnit_After(timing);
        }
    }
}

// C#: System.Void OnAddUnitPart(BattleUnitModel part, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAddUnitPart(il2cpp::Il2CppObject* part, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddUnitPart(part, timing);
        }
    }
}

// C#: System.Void Init_After()
void PassiveDetail::Init_After() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->Init_After();
        }
    }
}

// C#: System.Void OnAddUnitView(BattleUnitView view)
void PassiveDetail::OnAddUnitView(il2cpp::Il2CppObject* view) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddUnitView(view);
        }
    }
}

// C#: System.Void OnStageStart(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStageStart(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStageStart(timing);
        }
    }
}

// C#: System.Void OnWaveStart(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnWaveStart(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnWaveStart(timing);
        }
    }
}

// C#: System.Void OnPanicOrLowMorale(PANIC_LEVEL level, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnPanicOrLowMorale(int32_t level, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPanicOrLowMorale(level, timing);
        }
    }
}

// C#: System.Void OnRoundStart_Before()
void PassiveDetail::OnRoundStart_Before() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundStart_Before();
        }
    }
}

// C#: System.Void OnRoundStart()
void PassiveDetail::OnRoundStart() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundStart();
        }
    }
}

// C#: System.Void OnRoundStart_After_Event(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRoundStart_After_Event(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundStart_After_Event(timing);
        }
    }
}

// C#: System.Void OnRoundStart_After_Event_DeadOrRetreated(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRoundStart_After_Event_DeadOrRetreated(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundStart_After_Event_DeadOrRetreated(timing);
        }
    }
}

// C#: System.Void OnRoundStart_After_RelatedSlotState(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRoundStart_After_RelatedSlotState(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundStart_After_RelatedSlotState(timing);
        }
    }
}

// C#: System.Void OnReturnToField(System.Int32 retreatTurn, BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnReturnToField(int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReturnToField(retreatTurn, triggerUnit, retreatKeyword, timing);
        }
    }
}

// C#: System.Void OnReturnToFieldOtherUnit(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReturnToFieldOtherUnit(returnUnit, retreatTurn, timing);
        }
    }
}

// C#: System.Void OnReturnToFieldOtherUnit_DeadOrRetreated(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReturnToFieldOtherUnit_DeadOrRetreated(returnUnit, retreatTurn, timing);
        }
    }
}

// C#: System.Void OnReleaseStandByOtherUnit_DeadOrRetreated(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void PassiveDetail::OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReleaseStandByOtherUnit_DeadOrRetreated(addedUnit, addedUnitList);
        }
    }
}

// C#: System.Void OnReleaseStandByOtherUnit(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void PassiveDetail::OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReleaseStandByOtherUnit(addedUnit, addedUnitList);
        }
    }
}

// C#: System.Void OnReleaseStandBy(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnReleaseStandBy(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReleaseStandBy(timing);
        }
    }
}

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnCompleteCommand(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnCompleteCommand(timing);
        }
    }
}

// C#: System.Boolean BeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
bool PassiveDetail::BeforeCompleteCommand(bool returnValue, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->BeforeCompleteCommand(returnValue, action, timing, newSkillID);
        }
    }
    return returnValue;
}

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnChangeSkillBeforeCompleteCommand(action, timing);
        }
    }
}

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRoundEnd(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundEnd(timing);
        }
    }
}

// C#: System.Void OnRoundEnd_Disappeared(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRoundEnd_Disappeared(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundEnd_Disappeared(timing);
        }
    }
}

// C#: System.Void OnRetreat(BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRetreat(il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRetreat(triggerUnit, retreatKeyword, timing);
        }
    }
}

// C#: System.Void OnRoundEnd_After()
void PassiveDetail::OnRoundEnd_After() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRoundEnd_After();
        }
    }
}

// C#: System.Void OnStageEnd()
void PassiveDetail::OnStageEnd() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStageEnd();
        }
    }
}

// C#: System.Void OnBeforeDefense(BattleActionModel action)
void PassiveDetail::OnBeforeDefense(il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBeforeDefense(action);
        }
    }
}

// C#: System.Void OnStartRunBattle()
void PassiveDetail::OnStartRunBattle() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartRunBattle();
        }
    }
}

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnBattleStart(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBattleStart(timing);
        }
    }
}

// C#: System.Void OnBattleEnd(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnBattleEnd(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBattleEnd(timing);
        }
    }
}

// C#: System.Void OnBeforeTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnBeforeTurn(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBeforeTurn(action, timing);
        }
    }
}

// C#: System.Void OnStartTurn_BeforeLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartTurn_BeforeLog(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartTurn_BeforeLog(action, timing);
        }
    }
}

// C#: System.Void OnStartTurn_AfterLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartTurn_AfterLog(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartTurn_AfterLog(action, timing);
        }
    }
}

// C#: System.Void OnStartDuel(BattleActionModel ownerAction, BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartDuel(il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartDuel(ownerAction, opponentAction, timing);
        }
    }
}

// C#: System.Void BeforeGiveAttackDamage(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveDetail::BeforeGiveAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->BeforeGiveAttackDamage(action, coin, target, isCritical, isWinDuel, timing);
        }
    }
}

// C#: System.Void BeforeTakeAttackDamage(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::BeforeTakeAttackDamage(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->BeforeTakeAttackDamage(action, timing);
        }
    }
}

// C#: System.Void BeforePartTakeAttackDamage(BattleUnitModel_Abnormality abnormality, BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::BeforePartTakeAttackDamage(il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->BeforePartTakeAttackDamage(abnormality, part, action, timing);
        }
    }
}

// C#: System.Void OnTakeAttackDamage(BattleActionModel action, CoinModel coin, System.Int32 totalDmg, System.Int32 hpDmg, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnTakeAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeAttackDamage(action, coin, totalDmg, hpDmg, timing);
        }
    }
}

// C#: System.Void OnTakeAttackDamagePart(BattleUnitModel_Abnormality_Part part, BattleActionModel attackerAction, CoinModel coin, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
void PassiveDetail::OnTakeAttackDamagePart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeAttackDamagePart(part, attackerAction, coin, value, timing, isCritical);
        }
    }
}

// C#: System.Void OnGiveHpDamage(BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnGiveHpDamage(il2cpp::Il2CppObject* target, int32_t value, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnGiveHpDamage(target, value, timing);
        }
    }
}

// C#: System.Void OnGiveMpDamage(BattleUnitModel target, System.Int32 value)
void PassiveDetail::OnGiveMpDamage(il2cpp::Il2CppObject* target, int32_t value) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnGiveMpDamage(target, value);
        }
    }
}

// C#: System.Void OnTakeMpDmg_SinBuff(System.Int32 value, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnTakeMpDmg_SinBuff(int32_t value, int32_t timing, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeMpDmg_SinBuff(value, timing, keyword);
        }
    }
}

// C#: System.Void OnKillTarget(BattleActionModel actionOrNull, BattleUnitModel target, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnKillTarget(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnKillTarget(actionOrNull, target, dmgSrcType, timing);
        }
    }
}

// C#: System.Void OnEndTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndTurn(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndTurn(action, timing);
        }
    }
}

// C#: System.Void OnBeforeStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnBeforeStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBeforeStartCoin(action, coin, timing);
        }
    }
}

// C#: System.Void OnStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartCoin(action, coin, timing);
        }
    }
}

// C#: System.Void OnEndCoin_BeforeLog(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndCoin_BeforeLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndCoin_BeforeLog(action, coin, timing);
        }
    }
}

// C#: System.Void OnEndCoin_AfterLog(BattleActionModel action, CoinModel coin)
void PassiveDetail::OnEndCoin_AfterLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndCoin_AfterLog(action, coin);
        }
    }
}

// C#: System.Void OnEndBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnEndBehaviour(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndBehaviour(action, timing);
        }
    }
}

// C#: System.Void OnEndBehave_Refresh(BattleActionModel action)
void PassiveDetail::OnEndBehave_Refresh(il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnEndBehave_Refresh(action);
        }
    }
}

// C#: System.Void OnCriticalActivated(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnCriticalActivated(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnCriticalActivated(action, coin, timing);
        }
    }
}

// C#: System.Void BeforeAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveDetail::BeforeAttack(il2cpp::Il2CppObject* action, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->BeforeAttack(action, timing);
        }
    }
}

// C#: System.Void OnAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAttackConfirmed(action, coin, target, timing);
        }
    }
}

// C#: System.Boolean CanTeamKill(BattleActionModel action)
bool PassiveDetail::CanTeamKill(bool returnValue, il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanTeamKill(returnValue, action);
        }
    }
    return returnValue;
}

// C#: System.Collections.Generic.List<PrimeTargetData> GetPrimeTargets(BattleActionModel action)
il2cpp::Il2CppObject* PassiveDetail::GetPrimeTargets(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetPrimeTargets(returnValue, action);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPowerAdder(BattleActionModel action, COIN_ROLL_TYPE rollType)
int32_t PassiveDetail::GetSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t rollType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetSkillPowerAdder(returnValue, action, rollType);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerResultAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, BattleUnitModel expectedTarget)
int32_t PassiveDetail::GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedSkillPowerResultAdder(returnValue, action, prevActions, expectedTarget);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
int32_t PassiveDetail::GetExpectedSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedSkillPowerAdder(returnValue, action, prevActions, rollType, expectedTargetSinActionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Boolean HasPassive(System.Int32 passiveID)
bool PassiveDetail::HasPassive(bool returnValue, int32_t passiveID) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->HasPassive(returnValue, passiveID);
        }
    }
    return returnValue;
}

// C#: System.Void OnStartPhase(PHASE phase, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnStartPhase(int32_t phase, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnStartPhase(phase, timing);
        }
    }
}

// C#: System.Boolean HasFakeDead()
bool PassiveDetail::HasFakeDead(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->HasFakeDead(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAtkResist_Default(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveDetail::OverwriteAtkResist_Default(il2cpp::Il2CppObject* returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteAtkResist_Default(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAtkResist_Result(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveDetail::OverwriteAtkResist_Result(il2cpp::Il2CppObject* returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteAtkResist_Result(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAttributeDefaultResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* PassiveDetail::OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteAttributeDefaultResist(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAttributeResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* PassiveDetail::OverwriteAttributeResist(il2cpp::Il2CppObject* returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteAttributeResist(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteMaxBuffStack(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* PassiveDetail::OverwriteMaxBuffStack(il2cpp::Il2CppObject* returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteMaxBuffStack(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteMaxBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* PassiveDetail::OverwriteMaxBuffTurn(il2cpp::Il2CppObject* returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteMaxBuffTurn(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteSkillID(System.Int32 originID)
il2cpp::Il2CppObject* PassiveDetail::OverwriteSkillID(il2cpp::Il2CppObject* returnValue, int32_t originID) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteSkillID(returnValue, originID);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteSpeed(System.Int32 speed)
il2cpp::Il2CppObject* PassiveDetail::OverwriteSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteSpeed(returnValue, speed);
        }
    }
    return returnValue;
}

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleUnitModel unit, BattleActionModel selfAction, BattleActionModel oppoAction)
bool PassiveDetail::CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanChangeMainTargetRegardlessSpeed(returnValue, unit, selfAction, oppoAction);
        }
    }
    return returnValue;
}

// C#: System.Void OnZeroHp()
void PassiveDetail::OnZeroHp() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnZeroHp();
        }
    }
}

// C#: System.Int32 GetParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
int32_t PassiveDetail::GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult, parryingCount);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
int32_t PassiveDetail::GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedParryingResultAdder(returnValue, action, actorResult, oppoActionOrNull, oppoResult);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t PassiveDetail::GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetOpponentParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t PassiveDetail::GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetExpectedOpponentParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult);
        }
    }
    return returnValue;
}

// C#: System.Void ActivateEgoPassive(System.Int32 egoId)
void PassiveDetail::ActivateEgoPassive(int32_t egoId) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->ActivateEgoPassive(egoId);
        }
    }
}

// C#: System.Void ActivateEquipEgoPassives()
void PassiveDetail::ActivateEquipEgoPassives() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->ActivateEquipEgoPassives();
        }
    }
}

// C#: System.Void ActivateEgoPassives(BattleEgoModel ego, System.Collections.Generic.List<System.Int32> passiveIdList, System.Boolean isEquipEgoPassive)
void PassiveDetail::ActivateEgoPassives(il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->ActivateEgoPassives(ego, passiveIdList, isEquipEgoPassive);
        }
    }
}

// C#: System.Collections.Generic.List<BattleEgoModel> GetOwnerEgoModelList()
il2cpp::Il2CppObject* PassiveDetail::GetOwnerEgoModelList(il2cpp::Il2CppObject* returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetOwnerEgoModelList(returnValue);
        }
    }
    return returnValue;
}

// C#: BattleEgoModel FindEgoModel(System.Int32 egoId)
il2cpp::Il2CppObject* PassiveDetail::FindEgoModel(il2cpp::Il2CppObject* returnValue, int32_t egoId) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->FindEgoModel(returnValue, egoId);
        }
    }
    return returnValue;
}

// C#: System.Void AddReadyEgoPassive(System.Int32 egoId)
void PassiveDetail::AddReadyEgoPassive(int32_t egoId) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->AddReadyEgoPassive(egoId);
        }
    }
}

// C#: System.Boolean CanAddEgoPassive(System.Int32 egoId)
bool PassiveDetail::CanAddEgoPassive(bool returnValue, int32_t egoId) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanAddEgoPassive(returnValue, egoId);
        }
    }
    return returnValue;
}

// C#: System.Boolean PassesCondition(PassiveStaticData passiveData, BattleEgoModel ego)
bool PassiveDetail::PassesCondition(bool returnValue, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->PassesCondition(returnValue, passiveData, ego);
        }
    }
    return returnValue;
}

// C#: System.Void OnResult_OnAction(BattleActionModel action, CoinModel coin)
void PassiveDetail::OnResult_OnAction(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnResult_OnAction(action, coin);
        }
    }
}

// C#: System.Void OnResult_OnParrying(BattleActionModel action, BattleActionModel oppoAction, CoinModel coin)
void PassiveDetail::OnResult_OnParrying(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnResult_OnParrying(action, oppoAction, coin);
        }
    }
}

// C#: System.Void AddPassive(PassiveModel passiveModel)
void PassiveDetail::AddPassive(il2cpp::Il2CppObject* passiveModel) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->AddPassive(passiveModel);
        }
    }
}

// C#: System.Boolean IsRegeneratable()
bool PassiveDetail::IsRegeneratable(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsRegeneratable(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean SpreadHpDmgToAbnormality(System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool PassiveDetail::SpreadHpDmgToAbnormality(bool returnValue, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->SpreadHpDmgToAbnormality(returnValue, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
        }
    }
    return returnValue;
}

// C#: System.Boolean SpreadHpDmgFromAbnormalityPart(AB_PART_TYPE partType, System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool PassiveDetail::SpreadHpDmgFromAbnormalityPart(bool returnValue, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->SpreadHpDmgFromAbnormalityPart(returnValue, partType, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
        }
    }
    return returnValue;
}

// C#: System.Void OnSucceedEvade(BattleActionModel evadeAction, BattleActionModel attackAction, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnSucceedEvade(il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnSucceedEvade(evadeAction, attackAction, timing);
        }
    }
}

// C#: System.Void OnGiveBuffTrigger(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnGiveBuffTrigger(il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnGiveBuffTrigger(target, keyword, timing);
        }
    }
}

// C#: System.Void RightBeforeLosingBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightBeforeLosingBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightBeforeLosingBuff(keyword, stack, turn, timing);
        }
    }
}

// C#: System.Boolean CanCreateEmptySlot()
bool PassiveDetail::CanCreateEmptySlot(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanCreateEmptySlot(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean CanCreateEmptySlotPart(BattleUnitModel_Abnormality_Part part)
bool PassiveDetail::CanCreateEmptySlotPart(bool returnValue, il2cpp::Il2CppObject* part) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanCreateEmptySlotPart(returnValue, part);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetActionSlotAdder()
int32_t PassiveDetail::GetActionSlotAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetActionSlotAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetMaxHpAdder()
int32_t PassiveDetail::GetMaxHpAdder(int32_t returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxHpAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplier()
float PassiveDetail::GetMaxHpMultiplier(float returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxHpMultiplier(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplierPartToAbnormality()
float PassiveDetail::GetMaxHpMultiplierPartToAbnormality(float returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxHpMultiplierPartToAbnormality(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplierContributionToAbnormality()
float PassiveDetail::GetMaxHpMultiplierContributionToAbnormality(float returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxHpMultiplierContributionToAbnormality(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean CanTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 mp, ABILITY_SOURCE_TYPE srcType)
bool PassiveDetail::CanTakeMpHeal(bool returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanTakeMpHeal(returnValue, healerOrNull, mp, srcType);
        }
    }
    return returnValue;
}

// C#: System.Void OnAfterTryTakeHpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAfterTryTakeHpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
        }
    }
}

// C#: System.Void OnBeforeTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBeforeTryTakeMpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
        }
    }
}

// C#: System.Void OnAfterTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAfterTryTakeMpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
        }
    }
}

// C#: System.Boolean CheckImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool PassiveDetail::CheckImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckImmortal(returnValue, timing, newHp, isInstantDeath, buff, actionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Boolean CheckImmortalOtherUnit(BattleUnitModel checkTarget, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buf)
bool PassiveDetail::CheckImmortalOtherUnit(bool returnValue, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckImmortalOtherUnit(returnValue, checkTarget, newHp, isInstantDeath, buf);
        }
    }
    return returnValue;
}

// C#: System.Void OnGiveImmortalState(BattleUnitModel immortalTaker, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnGiveImmortalState(il2cpp::Il2CppObject* immortalTaker, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnGiveImmortalState(immortalTaker, timing);
        }
    }
}

// C#: System.Void OnBeforeActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveDetail::OnBeforeActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBeforeActivateImmortality(immortalActivator, timing, actionOrNull);
        }
    }
}

// C#: System.Void OnActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveDetail::OnActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnActivateImmortality(immortalActivator, timing, actionOrNull);
        }
    }
}

// C#: System.Void OnActivateAbnormalityImmortality(BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveDetail::OnActivateAbnormalityImmortality(int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnActivateAbnormalityImmortality(timing, actionOrNull);
        }
    }
}

// C#: System.Void OnActivateOtherUnitBurstReactive(BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnActivateOtherUnitBurstReactive(int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnActivateOtherUnitBurstReactive(keyword, buffOwner, actionOrNull, timing);
        }
    }
}

// C#: System.Void OnBurstReactiveActivatedAnyUnit(BattleUnitModel buffOwner, BUFF_UNIQUE_KEYWORD keyword, System.Int32 loseStack, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, BattleUnitModel giverOrNull)
void PassiveDetail::OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnBurstReactiveActivatedAnyUnit(buffOwner, keyword, loseStack, timing, actionOrNull, giverOrNull);
        }
    }
}

// C#: System.Void OnAddShield(BATTLE_EVENT_TIMING timing, System.Int32 value)
void PassiveDetail::OnAddShield(int32_t timing, int32_t value) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddShield(timing, value);
        }
    }
}

// C#: System.Void OnReduceShield(BATTLE_EVENT_TIMING timing, System.Int32 old, System.Int32 value, BattleUnitModel attackerOrNull)
void PassiveDetail::OnReduceShield(int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnReduceShield(timing, old, value, attackerOrNull);
        }
    }
}

// C#: System.Void OnDestroyShield(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnDestroyShield(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDestroyShield(timing);
        }
    }
}

// C#: System.Void OnDestoryShieldPart(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull)
void PassiveDetail::OnDestoryShieldPart(il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnDestoryShieldPart(part, timing, attackerOrNull);
        }
    }
}

// C#: System.Void OnRecoverBreak(BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnRecoverBreak(int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRecoverBreak(timing);
        }
    }
}

// C#: System.Void OnGiveBsGaugeUp(BattleUnitModel giver, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion, ABILITY_SOURCE_TYPE abilitySrc, BattleActionModel actionOrNull)
void PassiveDetail::OnGiveBsGaugeUp(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnGiveBsGaugeUp(giver, target, value, timing, onExplosion, abilitySrc, actionOrNull);
        }
    }
}

// C#: System.Void OnTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnTakeHpDamage(int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeHpDamage(finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
        }
    }
}

// C#: System.Void OnTakeHpDamagePart(BattleUnitModel_Abnormality_Part part, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnTakeHpDamagePart(il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeHpDamagePart(part, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
        }
    }
}

// C#: System.Void OnTakeHpDamageOtherUnit(BattleUnitModel damaged, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, System.Collections.Generic.List<BattleUnitModel> relatedUnitsOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeHpDamageOtherUnit(damaged, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, relatedUnitsOrNull, keyword);
        }
    }
}

// C#: System.Void OnTryTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BattleActionModel actionOrNull, BattleUnitModel attackerOrNull, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnTryTakeHpDamage(int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTryTakeHpDamage(finalDamage, hpDamage, actionOrNull, attackerOrNull, timing);
        }
    }
}

// C#: System.Single GetTakeHpHealMultiplier(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float PassiveDetail::GetTakeHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeHpHealMultiplier(returnValue, healerOrNull, srcType);
        }
    }
    return returnValue;
}

// C#: System.Void OnTakeAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel attacker, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnTakeAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeAttackConfirmed(action, coin, attacker, timing);
        }
    }
}

// C#: System.Int32 GetMaxHpAdderPart(BattleUnitModel_Abnormality_Part part)
int32_t PassiveDetail::GetMaxHpAdderPart(int32_t returnValue, il2cpp::Il2CppObject* part) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetMaxHpAdderPart(returnValue, part);
        }
    }
    return returnValue;
}

// C#: System.Single GetTakeHpHealMultiplierPart(BattleUnitModel_Abnormality_Part part, BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float PassiveDetail::GetTakeHpHealMultiplierPart(float returnValue, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeHpHealMultiplierPart(returnValue, part, healerOrNull, srcType);
        }
    }
    return returnValue;
}

// C#: System.Int32 GetTakeHpHealAdder(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
int32_t PassiveDetail::GetTakeHpHealAdder(int32_t returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetTakeHpHealAdder(returnValue, healerOrNull, srcType);
        }
    }
    return returnValue;
}

// C#: System.Void OverwriteTargetableList(System.Collections.Generic.List<SinActionModel> targetableSlotListOrNull, System.Collections.Generic.List<BattleUnitModel> origianlTargetList)
void PassiveDetail::OverwriteTargetableList(il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OverwriteTargetableList(targetableSlotListOrNull, origianlTargetList);
        }
    }
}

// C#: System.Nullable<System.Single> OverwriteAtkResistWhenDestroyed(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveDetail::OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* returnValue, int32_t type) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteAtkResistWhenDestroyed(returnValue, type);
        }
    }
    return returnValue;
}

// C#: System.Void OnChangeHp(System.Int32 oldHp, System.Int32 newHp, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveDetail::OnChangeHp(int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnChangeHp(oldHp, newHp, dmgSrcType, timing, attackerOrNull, actionOrNull, keyword);
        }
    }
}

// C#: System.Void OnChangeMp(System.Int32 oldMp, System.Int32 newMp)
void PassiveDetail::OnChangeMp(int32_t oldMp, int32_t newMp) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnChangeMp(oldMp, newMp);
        }
    }
}

// C#: System.Void OnChangeMpOther(BattleUnitModel mpChangeUnit, System.Int32 oldMp, System.Int32 newMp)
void PassiveDetail::OnChangeMpOther(il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnChangeMpOther(mpChangeUnit, oldMp, newMp);
        }
    }
}

// C#: System.Void OnTakeMpDamage(BattleUnitModel attacker, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleActionModel actionOrNull)
void PassiveDetail::OnTakeMpDamage(il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeMpDamage(attacker, value, timing, sourceType, actionOrNull);
        }
    }
}

// C#: System.Void OnTakeMpDamageOther(BattleUnitModel mpDmgUnit, BattleUnitModel attackerOrNull, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BUFF_UNIQUE_KEYWORD buffKeyword, BattleActionModel actionOrNull)
void PassiveDetail::OnTakeMpDamageOther(il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnTakeMpDamageOther(mpDmgUnit, attackerOrNull, value, timing, sourceType, buffKeyword, actionOrNull);
        }
    }
}

// C#: System.Void OnAfterTryTakeMpHealOther(BattleUnitModel mpHealUnit, BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAfterTryTakeMpHealOther(mpHealUnit, healerOrNull, tryHeal, resultHeal, srcType, timing);
        }
    }
}

// C#: System.Void UnlockAllPassives()
void PassiveDetail::UnlockAllPassives() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->UnlockAllPassives();
        }
    }
}

// C#: System.Void OnUseBuffTurnBySkill(SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnUseBuffTurnBySkill(il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnUseBuffTurnBySkill(skill, bufKeyword, turn, timing);
        }
    }
}

// C#: System.Void OnUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnUseBuff(keyword, stack, turn, timing);
        }
    }
}

// C#: System.Void BeforeUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::BeforeUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->BeforeUseBuff(keyword, stack, turn, timing);
        }
    }
}

// C#: System.Single GetCoinProbAdder()
float PassiveDetail::GetCoinProbAdder(float returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetCoinProbAdder(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, System.Single& prob)
bool PassiveDetail::OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteCoinProb(returnValue, unit, skill, prob);
        }
    }
    return returnValue;
}

// C#: System.Boolean IsEgoSkillFree(BattleEgoModel ego)
bool PassiveDetail::IsEgoSkillFree(bool returnValue, il2cpp::Il2CppObject* ego) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsEgoSkillFree(returnValue, ego);
        }
    }
    return returnValue;
}

// C#: System.Void OnPickSkills()
void PassiveDetail::OnPickSkills() {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnPickSkills();
        }
    }
}

// C#: System.Void OnAddActionToPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action)
void PassiveDetail::OnAddActionToPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddActionToPart(part, action);
        }
    }
}

// C#: System.Void OnAddCoinByAbility(BattleActionModel action, CoinModel newCoin, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnAddCoinByAbility(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddCoinByAbility(action, newCoin, timing);
        }
    }
}

// C#: System.Boolean CanOverwritePanicType()
bool PassiveDetail::CanOverwritePanicType(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CanOverwritePanicType(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Single GetCriticalChanceAdder(System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
float PassiveDetail::GetCriticalChanceAdder(float returnValue, il2cpp::Il2CppObject* affectKeywords) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetCriticalChanceAdder(returnValue, affectKeywords);
        }
    }
    return returnValue;
}

// C#: System.Single GetCriticalDamageRatioResultMultiplier(BattleActionModel action)
float PassiveDetail::GetCriticalDamageRatioResultMultiplier(float returnValue, il2cpp::Il2CppObject* action) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->GetCriticalDamageRatioResultMultiplier(returnValue, action);
        }
    }
    return returnValue;
}

// C#: System.Void RightAfterDestroyAnyBuff(BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveDetail::RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterDestroyAnyBuff(destroyedBuffInfo, timing);
        }
    }
}

// C#: System.Boolean IsAbnormalityImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool PassiveDetail::IsAbnormalityImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsAbnormalityImmortal(returnValue, timing, newHp, isInstantDeath, buff, actionOrNull);
        }
    }
    return returnValue;
}

// C#: System.Boolean CheckIfTurnToCorpesOnDie()
bool PassiveDetail::CheckIfTurnToCorpesOnDie(bool returnValue) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->CheckIfTurnToCorpesOnDie(returnValue);
        }
    }
    return returnValue;
}

// C#: System.Void OnCanceledByLackOfBuffsAtStartCoin(BattleActionModel action, CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD> lackOfBuffs, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnCanceledByLackOfBuffsAtStartCoin(action, coin, lackOfBuffs, timing);
        }
    }
}

// C#: System.Void CheckOverwriteGettingBuff(ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BUFF_UNIQUE_KEYWORD& keyword, System.Int32& stack, System.Int32& turn, System.Int32& activeRound)
void PassiveDetail::CheckOverwriteGettingBuff(int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->CheckOverwriteGettingBuff(abilitySrcType, timing, giverOrNull, keyword, stack, turn, activeRound);
        }
    }
}

// C#: System.Boolean IsAllowedToGiveBuff(BUFF_UNIQUE_KEYWORD keyword)
bool PassiveDetail::IsAllowedToGiveBuff(bool returnValue, int32_t keyword) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsAllowedToGiveBuff(returnValue, keyword);
        }
    }
    return returnValue;
}

// C#: System.Void OnFailedToGetBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel giverActionOrNull)
void PassiveDetail::OnFailedToGetBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnFailedToGetBuff(keyword, stack, turn, activeRound, abilitySrcType, timing, giverOrNull, giverActionOrNull);
        }
    }
}

// C#: System.Void RightAfterFailingGetAnyBuff(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void PassiveDetail::RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->RightAfterFailingGetAnyBuff(unit, keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
        }
    }
}

// C#: System.Void OnFailedToGiveBuff(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveDetail::OnFailedToGiveBuff(il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnFailedToGiveBuff(target, keyword, stack, turn, activeRound, abilitySrcType, timing, actionOrNull);
        }
    }
}

// C#: System.Void OnUseCoinConsume(BattleUnitModel owner, BattleActionModel action, CoinModel coin, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveDetail::OnUseCoinConsume(il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnUseCoinConsume(owner, action, coin, keyword, stack, turn, timing);
        }
    }
}

// C#: System.Boolean BlockGivingBuff(BattleActionModel action, BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool PassiveDetail::BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->BlockGivingBuff(returnValue, action, buffTarget, keyword, activeRound, coinOrNull, isCritical);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwritePartSpeed(System.Int32 speed, BattleUnitModel_Abnormality_Part part)
il2cpp::Il2CppObject* PassiveDetail::OverwritePartSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed, il2cpp::Il2CppObject* part) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwritePartSpeed(returnValue, speed, part);
        }
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel unit, BattleUnitModel target, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Boolean> isCritical)
bool PassiveDetail::BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->BlockLoseBuffByReactWithAction(returnValue, unit, target, action, keyword, isCritical);
        }
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffStack(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::BlockLoseBuffStack(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->BlockLoseBuffStack(returnValue, unit, keyword, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffTurn(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::BlockLoseBuffTurn(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->BlockLoseBuffTurn(returnValue, unit, keyword, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingSinkingBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerAction, CoinModel attackerCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IsBlockingSinkingBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsBlockingSinkingBuffEffectReact(returnValue, stack, turn, attackerAction, attackerCoin, isCritical, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsBlockingTargetSinkingBuffEffectReact(returnValue, target, stack, turn, selfAction, selfCoin, isCritical, timing);
        }
    }
    return returnValue;
}

// C#: System.Nullable<System.Boolean> OverwriteCanDuel(BattleActionModel selfAction, BattleActionModel opponentAction)
il2cpp::Il2CppObject* PassiveDetail::OverwriteCanDuel(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->OverwriteCanDuel(returnValue, selfAction, opponentAction);
        }
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingBurstBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IsBlockingBurstBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsBlockingBurstBuffEffectReact(returnValue, stack, turn, attackerActionOrNull, attackerCoinOrNull, isCritical, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveDetail::IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsBlockingTargetBurstBuffEffectReact(returnValue, target, stack, turn, selfAction, selfCoin, isCritical, timing);
        }
    }
    return returnValue;
}

// C#: System.Boolean ModifyMpChangeValue(System.Int32 oldMp, System.Int32 newMp, System.Int32& changedNewMp)
bool PassiveDetail::ModifyMpChangeValue(bool returnValue, int32_t oldMp, int32_t newMp, int32_t* changedNewMp) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->ModifyMpChangeValue(returnValue, oldMp, newMp, changedNewMp);
        }
    }
    return returnValue;
}

// C#: System.Void OnAddBattleAction(SinActionModel actorAction, SinActionModel targetAction)
void PassiveDetail::OnAddBattleAction(il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnAddBattleAction(actorAction, targetAction);
        }
    }
}

// C#: System.Void OnRemoveBattleAction(SinActionModel actorAction)
void PassiveDetail::OnRemoveBattleAction(il2cpp::Il2CppObject* actorAction) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            customPassive->OnRemoveBattleAction(actorAction);
        }
    }
}

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel thisAction, BattleActionModel mainAction, BattleActionModel oppoActionOrNull)
bool PassiveDetail::IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull) {
    for (il2cpp::Il2CppObject* passive : customPassiveList) {
        if (PassiveBase* customPassive = activeCustomPassive(passive)) {
            returnValue = customPassive->IsRunUniqueAction(returnValue, uniqueTiming, thisAction, mainAction, oppoActionOrNull);
        }
    }
    return returnValue;
}

} // myosotis::testmod
