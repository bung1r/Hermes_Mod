#pragma once
// PassiveDetail hooks + C++ mirror classes.
//
//   PassiveDetail    - C++ mirror of the game's PassiveDetail. Every event/modifier is virtual.
//                   void methods default to doing nothing; non-void methods default to returning
//                   `returnValue` (the value the ORIGINAL game method produced), so a subclass only
//                   overrides what it cares about and can modify the result.
//   PassiveBase   - base class for your custom passives (MoPassive1, ...). Override what you need.
//   PassiveDetail - per-unit dispatcher: it overrides the battle-relevant PassiveDetail virtuals and
//                   forwards each one to every custom passive that is currently active.
//
// Type mapping: Int32->int32_t, Boolean->bool, Single->float, Void->void, enums->int32_t,
//               T& -> T*, everything else -> il2cpp::Il2CppObject*
// Overloads: methods sharing a name are suffixed _P<paramCount> (matches your GetMethod("Name_P4") style);
//            if two overloads share a param count they get _P<count>_<n> and need manual GetMethod handling.
#include <cstdint>
#include <iostream>
#include <functional>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "il2cpp.hpp"

namespace myosotis::testmod {

class PassiveBase {
public:
    virtual ~PassiveBase() = default;

    // the game-side PassiveBase instance this object is paired with
    il2cpp::Il2CppObject* PassiveBaseObj = nullptr;
    il2cpp::Il2CppObject* passiveObj = nullptr;

    // C#: System.Void OnStartBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnStartBehaviour(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnSucceedAttack(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual void OnSucceedAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Void OnRollOneCoin_AfterAttack(BattleActionModel action, CoinModel coin)
    virtual void OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

    // C#: System.Void OnEndAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnEndAttack(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnEndAttackOtherUnit(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
    virtual void OnEndAttackOtherUnit(il2cpp::Il2CppObject* attackerAction, int32_t timing);

    // C#: System.Void OnStartEnemyAttack(BattleUnitModel unit, BattleActionModel opponentAction, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual void OnStartEnemyAttack(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Void OnEndEnemyAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnEndEnemyAttack(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnEndAttackPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnEndAttackPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnDuelAfter_BeforeLog(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
    virtual void OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing);

    // C#: System.Void OnAfterParryingOnce_BeforeLog(PARRYING_RESULT result, BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterParryingOnce_BeforeLog(int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing);

    // C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

    // C#: System.Void OnWinParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
    virtual void OnWinParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

    // C#: System.Void OnLoseParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
    virtual void OnLoseParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

    // C#: System.Void OnWinDuel(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
    virtual void OnWinDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing);

    // C#: System.Void OnLoseDuel(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
    virtual void OnLoseDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

    // C#: System.Void OnLoseDuelOtherUnit(BattleActionModel loserAction, BattleActionModel winnerAction, BATTLE_EVENT_TIMING timing)
    virtual void OnLoseDuelOtherUnit(il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing);

    // C#: System.Void RightBeforeGiveBuffBySkill(SkillModel skill, CoinModel coinOrNull, BUFF_UNIQUE_KEYWORD buf, System.Int32 stack, System.Int32 turn, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
    virtual void RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical);

    // C#: System.Void RightAfterGiveBuffBySkill(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
    virtual void RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical);

    // C#: System.Void RightAfterTakeBuffBySkill(BattleUnitModel unit, BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, BattleUnitModel giver, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, System.Int32 afterAdderStack, System.Int32 afterAdderTurn)
    virtual void RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn);

    // C#: System.Void RightBeforeOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
    virtual void RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing);

    // C#: System.Void RightAfterOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
    virtual void RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing);

    // C#: System.Void RightAfterAnyUnitGetAnyBuff(BattleUnitModel receiver, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, BattleUnitModel giverOrNull, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, System.Int32 overStack, System.Int32 overTurn)
    virtual void RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn);

    // C#: System.Void RightAfterLosingBuff(System.Int32 loseStack, System.Int32 loseTurn, BuffInfo loseBuffInfo, BATTLE_EVENT_TIMING timing)
    virtual void RightAfterLosingBuff(int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing);

    // C#: System.Void OnSucceedToGiveSwitchToSpecialVibration(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 prevStack, System.Int32 prevTurn, System.Int32 afterStack, System.Int32 afterTurn, System.Boolean isPileUp, BATTLE_EVENT_TIMING timing, ABILITY_SOURCE_TYPE abilitySourceType)
    virtual void OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType);

    // C#: System.Void RightAfterGetAnyBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
    virtual void RightAfterGetAnyBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn);

    // C#: System.Void RightAfterGetAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull)
    virtual void RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void RightAfterDestroyAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
    virtual void RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing);

    // C#: System.Int32 GetAggroAdder(SinActionModel sinaction)
    virtual int32_t GetAggroAdder(int32_t returnValue, il2cpp::Il2CppObject* sinaction);

    // C#: System.Int32 GetAttackWeightAdder(BattleActionModel action)
    virtual int32_t GetAttackWeightAdder(int32_t returnValue, il2cpp::Il2CppObject* action);

    // C#: System.Int32 GetMentalSystemResultIncreaseAdder()
    virtual int32_t GetMentalSystemResultIncreaseAdder(int32_t returnValue);

    // C#: System.Int32 GetMentalSystemResultDecreaseAdder()
    virtual int32_t GetMentalSystemResultDecreaseAdder(int32_t returnValue);

    // C#: System.Int32 GetInitBuffMaxStackAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetInitBuffMaxStackAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword);

    // C#: System.Int32 GetInitBuffMaxTurnAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetInitBuffMaxTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword);

    // C#: System.Int32 GetTakeBuffTurnAdderOtherUnit(BattleUnitModel taker, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
    virtual int32_t GetTakeBuffTurnAdderOtherUnit(int32_t returnValue, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing);

    // C#: System.Int32 GetTakeBuffStackAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originStack, BATTLE_EVENT_TIMING timing)
    virtual int32_t GetTakeBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing);

    // C#: System.Int32 GetTakeBuffTurnAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
    virtual int32_t GetTakeBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing);

    // C#: System.Int32 GetGiveBuffTurnAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, BATTLE_EVENT_TIMING timing)
    virtual int32_t GetGiveBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing);

    // C#: System.Int32 GetGiveBuffStackAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
    virtual int32_t GetGiveBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical);

    // C#: System.Int32 GetUseBuffTurnAdder(BattleActionModel action, SkillModel skill, System.Int32 turn, BUFF_UNIQUE_KEYWORD buf)
    virtual int32_t GetUseBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf);

    // C#: System.Single GetTakeBuffStackMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
    virtual float GetTakeBuffStackMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf);

    // C#: System.Single GetTakeBuffTurnMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
    virtual float GetTakeBuffTurnMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf);

    // C#: System.Void OnActivateSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 takeDmg, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced, System.Nullable<System.Boolean> isCritical)
    virtual void OnActivateSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical);

    // C#: System.Void OnActivateOtherUnitSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, System.Int32 takeDmg, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced)
    virtual void OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced);

    // C#: System.Boolean IgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
    virtual bool IgnoreSinBuffHpDamage(bool returnValue, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

    // C#: System.Boolean IgnoreSinBuffHpDamagePart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
    virtual bool IgnoreSinBuffHpDamagePart(bool returnValue, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

    // C#: System.Void OnIgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
    virtual void OnIgnoreSinBuffHpDamage(int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

    // C#: System.Int32 GetSinBuffDamageAdder(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg)
    virtual int32_t GetSinBuffDamageAdder(int32_t returnValue, int32_t keyword, int32_t dmg);

    // C#: System.Single GetSinBuffDamageMultiplier(BUFF_UNIQUE_KEYWORD keyword)
    virtual float GetSinBuffDamageMultiplier(float returnValue, int32_t keyword);

    // C#: System.Int32 GetMaxBuffStackAdder(BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetMaxBuffStackAdder(int32_t returnValue, int32_t keyword);

    // C#: System.Int32 GetMaxBuffTurnAdder(BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetMaxBuffTurnAdder(int32_t returnValue, int32_t keyword);

    // C#: System.Int32 GetUnitStatLevelAdder()
    virtual int32_t GetUnitStatLevelAdder(int32_t returnValue);

    // C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull, BattleUnitModel target)
    virtual float GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target);

    // C#: System.Single GetTakeBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull)
    virtual float GetTakeBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull);

    // C#: System.Int32 GetSkillPoolCountAdder(System.Int32 index, UnitAttribute attribute)
    virtual int32_t GetSkillPoolCountAdder(int32_t returnValue, int32_t index, il2cpp::Il2CppObject* attribute);

    // C#: System.Void OnDestroy(BattleUnitModel destroyerOrNull, BATTLE_EVENT_TIMING timing)
    virtual void OnDestroy(il2cpp::Il2CppObject* destroyerOrNull, int32_t timing);

    // C#: System.Void OnOtherPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart)
    virtual void OnOtherPartDestroyed(il2cpp::Il2CppObject* destroyedPart);

    // C#: System.Void OnPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart, BATTLE_EVENT_TIMING timing)
    virtual void OnPartDestroyed(il2cpp::Il2CppObject* destroyedPart, int32_t timing);

    // C#: System.Void OnPartBreaked(BattleUnitModel_Abnormality_Part breakedPart, BATTLE_EVENT_TIMING timing)
    virtual void OnPartBreaked(il2cpp::Il2CppObject* breakedPart, int32_t timing);

    // C#: System.Void OnPartRecoverBreak(BattleUnitModel_Abnormality_Part recoveredPart, BATTLE_EVENT_TIMING timing)
    virtual void OnPartRecoverBreak(il2cpp::Il2CppObject* recoveredPart, int32_t timing);

    // C#: System.Void OnRegenerate(BATTLE_EVENT_TIMING timing)
    virtual void OnRegenerate(int32_t timing);

    // C#: System.Void OnPartRegenerate(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing)
    virtual void OnPartRegenerate(il2cpp::Il2CppObject* part, int32_t timing);

    // C#: System.Boolean CheckUnitGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckUnitGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Boolean CheckUnitGivingBuffKeyword(BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckUnitGivingBuffKeyword(bool returnValue, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Boolean CheckSkillGivingBuffCategory(BattleActionModel action, BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckSkillGivingBuffCategory(bool returnValue, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Boolean CheckSkillGivingBuff(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckSkillGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Void CheckLoseBuffStackAndTurn(BuffInfo info, System.Int32& loseStack, System.Int32& loseTurn, BATTLE_EVENT_TIMING timing)
    virtual void CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing);

    // C#: System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin)
    virtual int32_t GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin);

    // C#: System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, SinActionModel expectedTargetSinActionOrNull)
    virtual int32_t GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

    // C#: System.Int32 GetSkillPowerResultAdder(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual int32_t GetSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Int32 GetTakeHpDmgAdder()
    virtual int32_t GetTakeHpDmgAdder(int32_t returnValue);

    // C#: System.Int32 GetExpectedTakeHpDmgAdder()
    virtual int32_t GetExpectedTakeHpDmgAdder(int32_t returnValue);

    // C#: System.Int32 GetMinSpeedAdder()
    virtual int32_t GetMinSpeedAdder(int32_t returnValue);

    // C#: System.Int32 GetMaxSpeedAdder()
    virtual int32_t GetMaxSpeedAdder(int32_t returnValue);

    // C#: System.Int32 GetSpeedAdder()
    virtual int32_t GetSpeedAdder(int32_t returnValue);

    // C#: System.Boolean UseOnlyDefaultMinSpeed()
    virtual bool UseOnlyDefaultMinSpeed(bool returnValue);

    // C#: System.Boolean UseOnlyDefaultMaxSpeed()
    virtual bool UseOnlyDefaultMaxSpeed(bool returnValue);

    // C#: System.Int32 ChangeAttackDamage(BattleActionModel action, BattleUnitModel target, CoinModel coin, System.Int32 resultDmg, System.Boolean& isCritical, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged)
    virtual int32_t ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged);

    // C#: System.Int32 ChangeTakeDamage(BattleActionModel action, CoinModel coinOrNull, System.Int32 resultDmg, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged, System.Int32 preCalculatedDmg)
    virtual int32_t ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg);

    // C#: System.Int32 ChangeMpDamage(System.Int32 resultDmg, BattleActionModel actionOrNull, BASE_MENTAL_CONDITION mentalConditionOrNone, BUFF_UNIQUE_KEYWORD keywordOrNone, AbilityBase abilityOrNull, System.Boolean& isChanged, BATTLE_EVENT_TIMING timing)
    virtual int32_t ChangeMpDamage(int32_t returnValue, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing);

    // C#: System.Int32 GetAttackHpDmgAdder(BattleUnitModel target)
    virtual int32_t GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target);

    // C#: System.Int32 GetExpectedAttackHpDmgAdder(BattleUnitModel target)
    virtual int32_t GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target);

    // C#: System.Int32 GetAttackDmgAdder(BattleActionModel action, BattleUnitModel target)
    virtual int32_t GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target);

    // C#: System.Int32 GetExpectedAttackDmgAdder(BattleActionModel action, BattleUnitModel targetOrNull)
    virtual int32_t GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull);

    // C#: System.Single GetAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical)
    virtual float GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical);

    // C#: System.Single GetExpectedAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
    virtual float GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

    // C#: System.Int32 GetTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
    virtual int32_t GetTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

    // C#: System.Int32 GetExpectedTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
    virtual int32_t GetExpectedTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

    // C#: System.Single GetTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker, System.Boolean isCritical)
    virtual float GetTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical);

    // C#: System.Single GetExpectedTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker)
    virtual float GetExpectedTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

    // C#: System.Int32 GetAttackAdder(BattleActionModel actionOrNull)
    virtual int32_t GetAttackAdder(int32_t returnValue, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Int32 GetUnitDefaultLevelAdder()
    virtual int32_t GetUnitDefaultLevelAdder(int32_t returnValue);

    // C#: System.Int32 GetDefenseAdder()
    virtual int32_t GetDefenseAdder(int32_t returnValue);

    // C#: System.Int32 GetUnitDefenseAdder()
    virtual int32_t GetUnitDefenseAdder(int32_t returnValue);

    // C#: System.Single GetDefenseMultiplier()
    virtual float GetDefenseMultiplier(float returnValue);

    // C#: System.Single GetHpHealMultiplier(BattleUnitModel target)
    virtual float GetHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* target);

    // C#: System.Single GetAtkResistMultiplier(ATK_BEHAVIOUR type)
    virtual float GetAtkResistMultiplier(float returnValue, int32_t type);

    // C#: System.Single GetAtkResistAdder(ATK_BEHAVIOUR type)
    virtual float GetAtkResistAdder(float returnValue, int32_t type);

    // C#: System.Single GetAttributeResistMultiplier(ATTRIBUTE_TYPE type)
    virtual float GetAttributeResistMultiplier(float returnValue, int32_t type);

    // C#: System.Single GetAttributeResistAdder(ATTRIBUTE_TYPE type)
    virtual float GetAttributeResistAdder(float returnValue, int32_t type);

    // C#: System.Void OnDie(BattleUnitModel killer, BattleActionModel actionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
    virtual void OnDie(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing);

    // C#: System.Void OnBreak(BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
    virtual void OnBreak(il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely);

    // C#: System.Void OnEnemyBrokenByAttacker(BattleActionModel actionOrNull, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
    virtual void OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing);

    // C#: System.Void OnDieOtherUnit(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnDieOtherUnit(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

    // C#: System.Void OnDieOtherUnit_Retreated(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

    // C#: System.Void OnDieOtherUnit_Disappeared(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

    // C#: System.Void OnRetreatOtherUnit(BattleUnitModel retreatUnit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
    virtual void OnRetreatOtherUnit(il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing);

    // C#: System.Void OnRetreatOtherUnit_Retreated(BattleUnitModel retreatUnit, BATTLE_EVENT_TIMING timing)
    virtual void OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* retreatUnit, int32_t timing);

    // C#: System.Void OnDiscardSinOtherUnit(BattleUnitModel discardUnit, UnitSinModel sin, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
    virtual void OnDiscardSinOtherUnit(il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnDiscardSin(UnitSinModel sin, BATTLE_EVENT_TIMING timing)
    virtual void OnDiscardSin(il2cpp::Il2CppObject* sin, int32_t timing);

    // C#: System.Void OnDisappeared(BATTLE_EVENT_TIMING timing)
    virtual void OnDisappeared(int32_t timing);

    // C#: System.Void OnReturnFromDisappeared(BATTLE_EVENT_TIMING timing)
    virtual void OnReturnFromDisappeared(int32_t timing);

    // C#: System.Void OnBreakOtherUnit(BattleUnitModel breakedUnit, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
    virtual void OnBreakOtherUnit(il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely);

    // C#: System.Void OnCheckBreak(System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
    virtual void OnCheckBreak(il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType);

    // C#: System.Void OnCheckPartBreak(BattleUnitModel_Abnormality_Part breakedPart, System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
    virtual void OnCheckPartBreak(il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType);

    // C#: System.Void OnVibrationExplosion(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
    virtual void OnVibrationExplosion(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing);

    // C#: System.Void OnVibrationExplosionOtherUnit(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
    virtual void OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing);

    // C#: System.Void OnTakeAttackDamageOtherUnit(BattleActionModel action, System.Int32 realDmg, System.Int32 hpDmg, BattleUnitModel attackedUnit, BATTLE_EVENT_TIMING timing)
    virtual void OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing);

    // C#: System.Void OnUseBuffStackBySkill(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, BATTLE_EVENT_TIMING timing)
    virtual void OnUseBuffStackBySkill(il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing);

    // C#: System.Void OnUseBloodDinnerUnit(BattleUnitModel usedUnit, System.Int32 stack, BATTLE_EVENT_TIMING timing)
    virtual void OnUseBloodDinnerUnit(il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing);

    // C#: System.Void OnAddUnit(BATTLE_EVENT_TIMING timing)
    virtual void OnAddUnit(int32_t timing);

    // C#: System.Void OnAddUnit_After(BATTLE_EVENT_TIMING timing)
    virtual void OnAddUnit_After(int32_t timing);

    // C#: System.Void OnAddUnitPart(BattleUnitModel part, BATTLE_EVENT_TIMING timing)
    virtual void OnAddUnitPart(il2cpp::Il2CppObject* part, int32_t timing);

    // C#: System.Void Init_After()
    virtual void Init_After();

    // C#: System.Void OnAddUnitView(BattleUnitView view)
    virtual void OnAddUnitView(il2cpp::Il2CppObject* view);

    // C#: System.Void OnStageStart(BATTLE_EVENT_TIMING timing)
    virtual void OnStageStart(int32_t timing);

    // C#: System.Void OnWaveStart(BATTLE_EVENT_TIMING timing)
    virtual void OnWaveStart(int32_t timing);

    // C#: System.Void OnPanicOrLowMorale(PANIC_LEVEL level, BATTLE_EVENT_TIMING timing)
    virtual void OnPanicOrLowMorale(int32_t level, int32_t timing);

    // C#: System.Void OnRoundStart_Before()
    virtual void OnRoundStart_Before();

    // C#: System.Void OnRoundStart()
    virtual void OnRoundStart();

    // C#: System.Void OnRoundStart_After_Event(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundStart_After_Event(int32_t timing);

    // C#: System.Void OnRoundStart_After_Event_DeadOrRetreated(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundStart_After_Event_DeadOrRetreated(int32_t timing);

    // C#: System.Void OnRoundStart_After_RelatedSlotState(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundStart_After_RelatedSlotState(int32_t timing);

    // C#: System.Void OnReturnToField(System.Int32 retreatTurn, BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
    virtual void OnReturnToField(int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing);

    // C#: System.Void OnReturnToFieldOtherUnit(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
    virtual void OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing);

    // C#: System.Void OnReturnToFieldOtherUnit_DeadOrRetreated(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
    virtual void OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing);

    // C#: System.Void OnReleaseStandByOtherUnit_DeadOrRetreated(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
    virtual void OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList);

    // C#: System.Void OnReleaseStandByOtherUnit(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
    virtual void OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList);

    // C#: System.Void OnReleaseStandBy(BATTLE_EVENT_TIMING timing)
    virtual void OnReleaseStandBy(int32_t timing);

    // C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
    virtual void OnCompleteCommand(int32_t timing);

    // C#: System.Boolean BeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
    virtual bool BeforeCompleteCommand(bool returnValue, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID);

    // C#: System.Void OnChangeSkillBeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundEnd(int32_t timing);

    // C#: System.Void OnRoundEnd_Disappeared(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundEnd_Disappeared(int32_t timing);

    // C#: System.Void OnRetreat(BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
    virtual void OnRetreat(il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing);

    // C#: System.Void OnRoundEnd_After()
    virtual void OnRoundEnd_After();

    // C#: System.Void OnStageEnd()
    virtual void OnStageEnd();

    // C#: System.Void OnBeforeDefense(BattleActionModel action)
    virtual void OnBeforeDefense(il2cpp::Il2CppObject* action);

    // C#: System.Void OnStartRunBattle()
    virtual void OnStartRunBattle();

    // C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
    virtual void OnBattleStart(int32_t timing);

    // C#: System.Void OnBattleEnd(BATTLE_EVENT_TIMING timing)
    virtual void OnBattleEnd(int32_t timing);

    // C#: System.Void OnBeforeTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnBeforeTurn(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnStartTurn_BeforeLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnStartTurn_BeforeLog(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnStartTurn_AfterLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnStartTurn_AfterLog(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnStartDuel(BattleActionModel ownerAction, BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
    virtual void OnStartDuel(il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing);

    // C#: System.Void BeforeGiveAttackDamage(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual void BeforeGiveAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Void BeforeTakeAttackDamage(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void BeforeTakeAttackDamage(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void BeforePartTakeAttackDamage(BattleUnitModel_Abnormality abnormality, BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void BeforePartTakeAttackDamage(il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnTakeAttackDamage(BattleActionModel action, CoinModel coin, System.Int32 totalDmg, System.Int32 hpDmg, BATTLE_EVENT_TIMING timing)
    virtual void OnTakeAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing);

    // C#: System.Void OnTakeAttackDamagePart(BattleUnitModel_Abnormality_Part part, BattleActionModel attackerAction, CoinModel coin, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
    virtual void OnTakeAttackDamagePart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical);

    // C#: System.Void OnGiveHpDamage(BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing)
    virtual void OnGiveHpDamage(il2cpp::Il2CppObject* target, int32_t value, int32_t timing);

    // C#: System.Void OnGiveMpDamage(BattleUnitModel target, System.Int32 value)
    virtual void OnGiveMpDamage(il2cpp::Il2CppObject* target, int32_t value);

    // C#: System.Void OnTakeMpDmg_SinBuff(System.Int32 value, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnTakeMpDmg_SinBuff(int32_t value, int32_t timing, int32_t keyword);

    // C#: System.Void OnKillTarget(BattleActionModel actionOrNull, BattleUnitModel target, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
    virtual void OnKillTarget(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing);

    // C#: System.Void OnEndTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnEndTurn(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnBeforeStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
    virtual void OnBeforeStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

    // C#: System.Void OnStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
    virtual void OnStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

    // C#: System.Void OnEndCoin_BeforeLog(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
    virtual void OnEndCoin_BeforeLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

    // C#: System.Void OnEndCoin_AfterLog(BattleActionModel action, CoinModel coin)
    virtual void OnEndCoin_AfterLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

    // C#: System.Void OnEndBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void OnEndBehaviour(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnEndBehave_Refresh(BattleActionModel action)
    virtual void OnEndBehave_Refresh(il2cpp::Il2CppObject* action);

    // C#: System.Void OnCriticalActivated(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
    virtual void OnCriticalActivated(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

    // C#: System.Void BeforeAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
    virtual void BeforeAttack(il2cpp::Il2CppObject* action, int32_t timing);

    // C#: System.Void OnAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
    virtual void OnAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing);

    // C#: System.Boolean CanTeamKill(BattleActionModel action)
    virtual bool CanTeamKill(bool returnValue, il2cpp::Il2CppObject* action);

    // C#: System.Collections.Generic.List<PrimeTargetData> GetPrimeTargets(BattleActionModel action)
    virtual il2cpp::Il2CppObject* GetPrimeTargets(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action);

    // C#: System.Int32 GetSkillPowerAdder(BattleActionModel action, COIN_ROLL_TYPE rollType)
    virtual int32_t GetSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t rollType);

    // C#: System.Int32 GetExpectedSkillPowerResultAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, BattleUnitModel expectedTarget)
    virtual int32_t GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget);

    // C#: System.Int32 GetExpectedSkillPowerAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
    virtual int32_t GetExpectedSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

    // C#: System.Boolean HasPassive(System.Int32 passiveID)
    virtual bool HasPassive(bool returnValue, int32_t passiveID);

    // C#: System.Void OnStartPhase(PHASE phase, BATTLE_EVENT_TIMING timing)
    virtual void OnStartPhase(int32_t phase, int32_t timing);

    // C#: System.Boolean HasFakeDead()
    virtual bool HasFakeDead(bool returnValue);

    // C#: System.Nullable<System.Single> OverwriteAtkResist_Default(ATK_BEHAVIOUR type)
    virtual il2cpp::Il2CppObject* OverwriteAtkResist_Default(il2cpp::Il2CppObject* returnValue, int32_t type);

    // C#: System.Nullable<System.Single> OverwriteAtkResist_Result(ATK_BEHAVIOUR type)
    virtual il2cpp::Il2CppObject* OverwriteAtkResist_Result(il2cpp::Il2CppObject* returnValue, int32_t type);

    // C#: System.Nullable<System.Single> OverwriteAttributeDefaultResist(ATTRIBUTE_TYPE type)
    virtual il2cpp::Il2CppObject* OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* returnValue, int32_t type);

    // C#: System.Nullable<System.Single> OverwriteAttributeResist(ATTRIBUTE_TYPE type)
    virtual il2cpp::Il2CppObject* OverwriteAttributeResist(il2cpp::Il2CppObject* returnValue, int32_t type);

    // C#: System.Nullable<System.Int32> OverwriteMaxBuffStack(BUFF_UNIQUE_KEYWORD keyword)
    virtual il2cpp::Il2CppObject* OverwriteMaxBuffStack(il2cpp::Il2CppObject* returnValue, int32_t keyword);

    // C#: System.Nullable<System.Int32> OverwriteMaxBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
    virtual il2cpp::Il2CppObject* OverwriteMaxBuffTurn(il2cpp::Il2CppObject* returnValue, int32_t keyword);

    // C#: System.Nullable<System.Int32> OverwriteSkillID(System.Int32 originID)
    virtual il2cpp::Il2CppObject* OverwriteSkillID(il2cpp::Il2CppObject* returnValue, int32_t originID);

    // C#: System.Nullable<System.Int32> OverwriteSpeed(System.Int32 speed)
    virtual il2cpp::Il2CppObject* OverwriteSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed);

    // C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleUnitModel unit, BattleActionModel selfAction, BattleActionModel oppoAction)
    virtual bool CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction);

    // C#: System.Void OnZeroHp()
    virtual void OnZeroHp();

    // C#: System.Int32 GetParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
    virtual int32_t GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount);

    // C#: System.Int32 GetExpectedParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
    virtual int32_t GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);

    // C#: System.Int32 GetOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
    virtual int32_t GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

    // C#: System.Int32 GetExpectedOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
    virtual int32_t GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

    // C#: System.Void ActivateEgoPassive(System.Int32 egoId)
    virtual void ActivateEgoPassive(int32_t egoId);

    // C#: System.Void ActivateEquipEgoPassives()
    virtual void ActivateEquipEgoPassives();

    // C#: System.Void ActivateEgoPassives(BattleEgoModel ego, System.Collections.Generic.List<System.Int32> passiveIdList, System.Boolean isEquipEgoPassive)
    virtual void ActivateEgoPassives(il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive);

    // C#: System.Collections.Generic.List<BattleEgoModel> GetOwnerEgoModelList()
    virtual il2cpp::Il2CppObject* GetOwnerEgoModelList(il2cpp::Il2CppObject* returnValue);

    // C#: BattleEgoModel FindEgoModel(System.Int32 egoId)
    virtual il2cpp::Il2CppObject* FindEgoModel(il2cpp::Il2CppObject* returnValue, int32_t egoId);

    // C#: System.Void AddReadyEgoPassive(System.Int32 egoId)
    virtual void AddReadyEgoPassive(int32_t egoId);

    // C#: System.Boolean CanAddEgoPassive(System.Int32 egoId)
    virtual bool CanAddEgoPassive(bool returnValue, int32_t egoId);

    // C#: System.Boolean PassesCondition(PassiveStaticData passiveData, BattleEgoModel ego)
    virtual bool PassesCondition(bool returnValue, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego);

    // C#: System.Void OnResult_OnAction(BattleActionModel action, CoinModel coin)
    virtual void OnResult_OnAction(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

    // C#: System.Void OnResult_OnParrying(BattleActionModel action, BattleActionModel oppoAction, CoinModel coin)
    virtual void OnResult_OnParrying(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin);

    // C#: System.Void AddPassive(PassiveModel passiveModel)
    virtual void AddPassive(il2cpp::Il2CppObject* passiveModel);

    // C#: System.Boolean IsRegeneratable()
    virtual bool IsRegeneratable(bool returnValue);

    // C#: System.Boolean SpreadHpDmgToAbnormality(System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
    virtual bool SpreadHpDmgToAbnormality(bool returnValue, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword);

    // C#: System.Boolean SpreadHpDmgFromAbnormalityPart(AB_PART_TYPE partType, System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
    virtual bool SpreadHpDmgFromAbnormalityPart(bool returnValue, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword);

    // C#: System.Void OnSucceedEvade(BattleActionModel evadeAction, BattleActionModel attackAction, BATTLE_EVENT_TIMING timing)
    virtual void OnSucceedEvade(il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing);

    // C#: System.Void OnGiveBuffTrigger(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
    virtual void OnGiveBuffTrigger(il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing);

    // C#: System.Void RightBeforeLosingBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
    virtual void RightBeforeLosingBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

    // C#: System.Boolean CanCreateEmptySlot()
    virtual bool CanCreateEmptySlot(bool returnValue);

    // C#: System.Boolean CanCreateEmptySlotPart(BattleUnitModel_Abnormality_Part part)
    virtual bool CanCreateEmptySlotPart(bool returnValue, il2cpp::Il2CppObject* part);

    // C#: System.Int32 GetActionSlotAdder()
    virtual int32_t GetActionSlotAdder(int32_t returnValue);

    // C#: System.Int32 GetMaxHpAdder()
    virtual int32_t GetMaxHpAdder(int32_t returnValue);

    // C#: System.Single GetMaxHpMultiplier()
    virtual float GetMaxHpMultiplier(float returnValue);

    // C#: System.Single GetMaxHpMultiplierPartToAbnormality()
    virtual float GetMaxHpMultiplierPartToAbnormality(float returnValue);

    // C#: System.Single GetMaxHpMultiplierContributionToAbnormality()
    virtual float GetMaxHpMultiplierContributionToAbnormality(float returnValue);

    // C#: System.Boolean CanTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 mp, ABILITY_SOURCE_TYPE srcType)
    virtual bool CanTakeMpHeal(bool returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType);

    // C#: System.Void OnAfterTryTakeHpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

    // C#: System.Void OnBeforeTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
    virtual void OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

    // C#: System.Void OnAfterTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

    // C#: System.Boolean CheckImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
    virtual bool CheckImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Boolean CheckImmortalOtherUnit(BattleUnitModel checkTarget, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buf)
    virtual bool CheckImmortalOtherUnit(bool returnValue, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf);

    // C#: System.Void OnGiveImmortalState(BattleUnitModel immortalTaker, BATTLE_EVENT_TIMING timing)
    virtual void OnGiveImmortalState(il2cpp::Il2CppObject* immortalTaker, int32_t timing);

    // C#: System.Void OnBeforeActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
    virtual void OnBeforeActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
    virtual void OnActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnActivateAbnormalityImmortality(BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
    virtual void OnActivateAbnormalityImmortality(int32_t timing, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnActivateOtherUnitBurstReactive(BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing)
    virtual void OnActivateOtherUnitBurstReactive(int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing);

    // C#: System.Void OnBurstReactiveActivatedAnyUnit(BattleUnitModel buffOwner, BUFF_UNIQUE_KEYWORD keyword, System.Int32 loseStack, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, BattleUnitModel giverOrNull)
    virtual void OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull);

    // C#: System.Void OnAddShield(BATTLE_EVENT_TIMING timing, System.Int32 value)
    virtual void OnAddShield(int32_t timing, int32_t value);

    // C#: System.Void OnReduceShield(BATTLE_EVENT_TIMING timing, System.Int32 old, System.Int32 value, BattleUnitModel attackerOrNull)
    virtual void OnReduceShield(int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull);

    // C#: System.Void OnDestroyShield(BATTLE_EVENT_TIMING timing)
    virtual void OnDestroyShield(int32_t timing);

    // C#: System.Void OnDestoryShieldPart(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull)
    virtual void OnDestoryShieldPart(il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull);

    // C#: System.Void OnRecoverBreak(BATTLE_EVENT_TIMING timing)
    virtual void OnRecoverBreak(int32_t timing);

    // C#: System.Void OnGiveBsGaugeUp(BattleUnitModel giver, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion, ABILITY_SOURCE_TYPE abilitySrc, BattleActionModel actionOrNull)
    virtual void OnGiveBsGaugeUp(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnTakeHpDamage(int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

    // C#: System.Void OnTakeHpDamagePart(BattleUnitModel_Abnormality_Part part, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnTakeHpDamagePart(il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

    // C#: System.Void OnTakeHpDamageOtherUnit(BattleUnitModel damaged, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, System.Collections.Generic.List<BattleUnitModel> relatedUnitsOrNull, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword);

    // C#: System.Void OnTryTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BattleActionModel actionOrNull, BattleUnitModel attackerOrNull, BATTLE_EVENT_TIMING timing)
    virtual void OnTryTakeHpDamage(int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing);

    // C#: System.Single GetTakeHpHealMultiplier(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
    virtual float GetTakeHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

    // C#: System.Void OnTakeAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel attacker, BATTLE_EVENT_TIMING timing)
    virtual void OnTakeAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing);

    // C#: System.Int32 GetMaxHpAdderPart(BattleUnitModel_Abnormality_Part part)
    virtual int32_t GetMaxHpAdderPart(int32_t returnValue, il2cpp::Il2CppObject* part);

    // C#: System.Single GetTakeHpHealMultiplierPart(BattleUnitModel_Abnormality_Part part, BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
    virtual float GetTakeHpHealMultiplierPart(float returnValue, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

    // C#: System.Int32 GetTakeHpHealAdder(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
    virtual int32_t GetTakeHpHealAdder(int32_t returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

    // C#: System.Void OverwriteTargetableList(System.Collections.Generic.List<SinActionModel> targetableSlotListOrNull, System.Collections.Generic.List<BattleUnitModel> origianlTargetList)
    virtual void OverwriteTargetableList(il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList);

    // C#: System.Nullable<System.Single> OverwriteAtkResistWhenDestroyed(ATK_BEHAVIOUR type)
    virtual il2cpp::Il2CppObject* OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* returnValue, int32_t type);

    // C#: System.Void OnChangeHp(System.Int32 oldHp, System.Int32 newHp, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
    virtual void OnChangeHp(int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

    // C#: System.Void OnChangeMp(System.Int32 oldMp, System.Int32 newMp)
    virtual void OnChangeMp(int32_t oldMp, int32_t newMp);

    // C#: System.Void OnChangeMpOther(BattleUnitModel mpChangeUnit, System.Int32 oldMp, System.Int32 newMp)
    virtual void OnChangeMpOther(il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp);

    // C#: System.Void OnTakeMpDamage(BattleUnitModel attacker, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleActionModel actionOrNull)
    virtual void OnTakeMpDamage(il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnTakeMpDamageOther(BattleUnitModel mpDmgUnit, BattleUnitModel attackerOrNull, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BUFF_UNIQUE_KEYWORD buffKeyword, BattleActionModel actionOrNull)
    virtual void OnTakeMpDamageOther(il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnAfterTryTakeMpHealOther(BattleUnitModel mpHealUnit, BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

    // C#: System.Void UnlockAllPassives()
    virtual void UnlockAllPassives();

    // C#: System.Void OnUseBuffTurnBySkill(SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 turn, BATTLE_EVENT_TIMING timing)
    virtual void OnUseBuffTurnBySkill(il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing);

    // C#: System.Void OnUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
    virtual void OnUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

    // C#: System.Void BeforeUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
    virtual void BeforeUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

    // C#: System.Single GetCoinProbAdder()
    virtual float GetCoinProbAdder(float returnValue);

    // C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, System.Single& prob)
    virtual bool OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob);

    // C#: System.Boolean IsEgoSkillFree(BattleEgoModel ego)
    virtual bool IsEgoSkillFree(bool returnValue, il2cpp::Il2CppObject* ego);

    // C#: System.Void OnPickSkills()
    virtual void OnPickSkills();

    // C#: System.Void OnAddActionToPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action)
    virtual void OnAddActionToPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action);

    // C#: System.Void OnAddCoinByAbility(BattleActionModel action, CoinModel newCoin, BATTLE_EVENT_TIMING timing)
    virtual void OnAddCoinByAbility(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing);

    // C#: System.Boolean CanOverwritePanicType()
    virtual bool CanOverwritePanicType(bool returnValue);

    // C#: System.Single GetCriticalChanceAdder(System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
    virtual float GetCriticalChanceAdder(float returnValue, il2cpp::Il2CppObject* affectKeywords);

    // C#: System.Single GetCriticalDamageRatioResultMultiplier(BattleActionModel action)
    virtual float GetCriticalDamageRatioResultMultiplier(float returnValue, il2cpp::Il2CppObject* action);

    // C#: System.Void RightAfterDestroyAnyBuff(BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
    virtual void RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing);

    // C#: System.Boolean IsAbnormalityImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
    virtual bool IsAbnormalityImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Boolean CheckIfTurnToCorpesOnDie()
    virtual bool CheckIfTurnToCorpesOnDie(bool returnValue);

    // C#: System.Void OnCanceledByLackOfBuffsAtStartCoin(BattleActionModel action, CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD> lackOfBuffs, BATTLE_EVENT_TIMING timing)
    virtual void OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing);

    // C#: System.Void CheckOverwriteGettingBuff(ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BUFF_UNIQUE_KEYWORD& keyword, System.Int32& stack, System.Int32& turn, System.Int32& activeRound)
    virtual void CheckOverwriteGettingBuff(int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound);

    // C#: System.Boolean IsAllowedToGiveBuff(BUFF_UNIQUE_KEYWORD keyword)
    virtual bool IsAllowedToGiveBuff(bool returnValue, int32_t keyword);

    // C#: System.Void OnFailedToGetBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel giverActionOrNull)
    virtual void OnFailedToGetBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull);

    // C#: System.Void RightAfterFailingGetAnyBuff(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
    virtual void RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn);

    // C#: System.Void OnFailedToGiveBuff(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
    virtual void OnFailedToGiveBuff(il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

    // C#: System.Void OnUseCoinConsume(BattleUnitModel owner, BattleActionModel action, CoinModel coin, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
    virtual void OnUseCoinConsume(il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

    // C#: System.Boolean BlockGivingBuff(BattleActionModel action, BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
    virtual bool BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

    // C#: System.Nullable<System.Int32> OverwritePartSpeed(System.Int32 speed, BattleUnitModel_Abnormality_Part part)
    virtual il2cpp::Il2CppObject* OverwritePartSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed, il2cpp::Il2CppObject* part);

    // C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel unit, BattleUnitModel target, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Boolean> isCritical)
    virtual bool BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical);

    // C#: System.Boolean BlockLoseBuffStack(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
    virtual bool BlockLoseBuffStack(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing);

    // C#: System.Boolean BlockLoseBuffTurn(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
    virtual bool BlockLoseBuffTurn(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing);

    // C#: System.Boolean IsBlockingSinkingBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerAction, CoinModel attackerCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingSinkingBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing);

    // C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

    // C#: System.Nullable<System.Boolean> OverwriteCanDuel(BattleActionModel selfAction, BattleActionModel opponentAction)
    virtual il2cpp::Il2CppObject* OverwriteCanDuel(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction);

    // C#: System.Boolean IsBlockingBurstBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingBurstBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing);

    // C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

    // C#: System.Boolean ModifyMpChangeValue(System.Int32 oldMp, System.Int32 newMp, System.Int32& changedNewMp)
    virtual bool ModifyMpChangeValue(bool returnValue, int32_t oldMp, int32_t newMp, int32_t* changedNewMp);

    // C#: System.Void OnAddBattleAction(SinActionModel actorAction, SinActionModel targetAction)
    virtual void OnAddBattleAction(il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction);

    // C#: System.Void OnRemoveBattleAction(SinActionModel actorAction)
    virtual void OnRemoveBattleAction(il2cpp::Il2CppObject* actorAction);

    // C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel thisAction, BattleActionModel mainAction, BattleActionModel oppoActionOrNull)
    virtual bool IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull);

};

// Base class for custom passives. Override the PassiveBase virtuals you need, e.g.
//   void OnStageStart(il2cpp::Il2CppObject* unit, int32_t timing) override;
class CustomPassiveBase : public PassiveBase {
public:
    ~CustomPassiveBase() override = default;

    // game-side object this custom passive is bound to
    
};

// One per unit. Overrides the battle-relevant PassiveBase virtuals and forwards them to the
// custom passives that are in activePassiveList.
class PassiveDetail : public PassiveBase {
public:
    ~PassiveDetail() override = default;

    il2cpp::Il2CppObject* passiveDetailObj = nullptr;
    il2cpp::Il2CppObject* allPassiveList = nullptr;     // List<PassiveModel>, ALL passives
    il2cpp::Il2CppObject* activePassiveList = nullptr;  // List<PassiveModel>, only active passives
    std::vector<il2cpp::Il2CppObject*> customPassiveList = {};  // our custom passives (game PassiveModel objects)
    std::unordered_map<il2cpp::Il2CppObject*, PassiveBase*> customPassiveMap = {};  // game PassiveModel -> custom passive
    

    // returns the custom passive for `passive` only if it exists AND is currently in activePassiveList
    PassiveBase* activeCustomPassive(il2cpp::Il2CppObject* passive);
    void tryAddCustomPassive(il2cpp::Il2CppObject* passiveModel, int32_t id);

    void testmethod(il2cpp::Il2CppObject* test);
    
    void OnStartBehaviour(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnSucceedAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) override;
    void OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) override;
    void OnEndAttack(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnEndAttackOtherUnit(il2cpp::Il2CppObject* attackerAction, int32_t timing) override;
    void OnStartEnemyAttack(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing) override;
    void OnEndEnemyAttack(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnEndAttackPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) override;
    void OnAfterParryingOnce_BeforeLog(int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing) override;
    void OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) override;
    void OnWinParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) override;
    void OnLoseParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) override;
    void OnWinDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) override;
    void OnLoseDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) override;
    void OnLoseDuelOtherUnit(il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing) override;
    void RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) override;
    void RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) override;
    void RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn) override;
    void RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) override;
    void RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) override;
    void RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn) override;
    void RightAfterLosingBuff(int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing) override;
    void OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType) override;
    void RightAfterGetAnyBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) override;
    void RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull) override;
    void RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) override;
    int32_t GetAggroAdder(int32_t returnValue, il2cpp::Il2CppObject* sinaction) override;
    int32_t GetAttackWeightAdder(int32_t returnValue, il2cpp::Il2CppObject* action) override;
    int32_t GetMentalSystemResultIncreaseAdder(int32_t returnValue) override;
    int32_t GetMentalSystemResultDecreaseAdder(int32_t returnValue) override;
    int32_t GetInitBuffMaxStackAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) override;
    int32_t GetInitBuffMaxTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) override;
    int32_t GetTakeBuffTurnAdderOtherUnit(int32_t returnValue, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing) override;
    int32_t GetTakeBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing) override;
    int32_t GetTakeBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing) override;
    int32_t GetGiveBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing) override;
    int32_t GetGiveBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) override;
    int32_t GetUseBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf) override;
    float GetTakeBuffStackMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) override;
    float GetTakeBuffTurnMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) override;
    void OnActivateSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical) override;
    void OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced) override;
    bool IgnoreSinBuffHpDamage(bool returnValue, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) override;
    bool IgnoreSinBuffHpDamagePart(bool returnValue, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) override;
    void OnIgnoreSinBuffHpDamage(int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) override;
    int32_t GetSinBuffDamageAdder(int32_t returnValue, int32_t keyword, int32_t dmg) override;
    float GetSinBuffDamageMultiplier(float returnValue, int32_t keyword) override;
    int32_t GetMaxBuffStackAdder(int32_t returnValue, int32_t keyword) override;
    int32_t GetMaxBuffTurnAdder(int32_t returnValue, int32_t keyword) override;
    int32_t GetUnitStatLevelAdder(int32_t returnValue) override;
    float GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target) override;
    float GetTakeBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull) override;
    int32_t GetSkillPoolCountAdder(int32_t returnValue, int32_t index, il2cpp::Il2CppObject* attribute) override;
    void OnDestroy(il2cpp::Il2CppObject* destroyerOrNull, int32_t timing) override;
    void OnOtherPartDestroyed(il2cpp::Il2CppObject* destroyedPart) override;
    void OnPartDestroyed(il2cpp::Il2CppObject* destroyedPart, int32_t timing) override;
    void OnPartBreaked(il2cpp::Il2CppObject* breakedPart, int32_t timing) override;
    void OnPartRecoverBreak(il2cpp::Il2CppObject* recoveredPart, int32_t timing) override;
    void OnRegenerate(int32_t timing) override;
    void OnPartRegenerate(il2cpp::Il2CppObject* part, int32_t timing) override;
    bool CheckUnitGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) override;
    bool CheckUnitGivingBuffKeyword(bool returnValue, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) override;
    bool CheckSkillGivingBuffCategory(bool returnValue, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) override;
    bool CheckSkillGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) override;
    void CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing) override;
    int32_t GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin) override;
    int32_t GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) override;
    int32_t GetSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t timing) override;
    int32_t GetTakeHpDmgAdder(int32_t returnValue) override;
    int32_t GetExpectedTakeHpDmgAdder(int32_t returnValue) override;
    int32_t GetMinSpeedAdder(int32_t returnValue) override;
    int32_t GetMaxSpeedAdder(int32_t returnValue) override;
    int32_t GetSpeedAdder(int32_t returnValue) override;
    bool UseOnlyDefaultMinSpeed(bool returnValue) override;
    bool UseOnlyDefaultMaxSpeed(bool returnValue) override;
    int32_t ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged) override;
    int32_t ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg) override;
    int32_t ChangeMpDamage(int32_t returnValue, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing) override;
    int32_t GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) override;
    int32_t GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) override;
    int32_t GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) override;
    int32_t GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull) override;
    float GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical) override;
    float GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) override;
    int32_t GetTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) override;
    int32_t GetExpectedTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) override;
    float GetTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical) override;
    float GetExpectedTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) override;
    int32_t GetAttackAdder(int32_t returnValue, il2cpp::Il2CppObject* actionOrNull) override;
    int32_t GetUnitDefaultLevelAdder(int32_t returnValue) override;
    int32_t GetDefenseAdder(int32_t returnValue) override;
    int32_t GetUnitDefenseAdder(int32_t returnValue) override;
    float GetDefenseMultiplier(float returnValue) override;
    float GetHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* target) override;
    float GetAtkResistMultiplier(float returnValue, int32_t type) override;
    float GetAtkResistAdder(float returnValue, int32_t type) override;
    float GetAttributeResistMultiplier(float returnValue, int32_t type) override;
    float GetAttributeResistAdder(float returnValue, int32_t type) override;
    void OnDie(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing) override;
    void OnBreak(il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely) override;
    void OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing) override;
    void OnDieOtherUnit(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) override;
    void OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) override;
    void OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) override;
    void OnRetreatOtherUnit(il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing) override;
    void OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* retreatUnit, int32_t timing) override;
    void OnDiscardSinOtherUnit(il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull) override;
    void OnDiscardSin(il2cpp::Il2CppObject* sin, int32_t timing) override;
    void OnDisappeared(int32_t timing) override;
    void OnReturnFromDisappeared(int32_t timing) override;
    void OnBreakOtherUnit(il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely) override;
    void OnCheckBreak(il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) override;
    void OnCheckPartBreak(il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) override;
    void OnVibrationExplosion(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) override;
    void OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) override;
    void OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing) override;
    void OnUseBuffStackBySkill(il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing) override;
    void OnUseBloodDinnerUnit(il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing) override;
    void OnAddUnit(int32_t timing) override;
    void OnAddUnit_After(int32_t timing) override;
    void OnAddUnitPart(il2cpp::Il2CppObject* part, int32_t timing) override;
    void Init_After() override;
    void OnAddUnitView(il2cpp::Il2CppObject* view) override;
    void OnStageStart(int32_t timing) override;
    void OnWaveStart(int32_t timing) override;
    void OnPanicOrLowMorale(int32_t level, int32_t timing) override;
    void OnRoundStart_Before() override;
    void OnRoundStart() override;
    void OnRoundStart_After_Event(int32_t timing) override;
    void OnRoundStart_After_Event_DeadOrRetreated(int32_t timing) override;
    void OnRoundStart_After_RelatedSlotState(int32_t timing) override;
    void OnReturnToField(int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) override;
    void OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) override;
    void OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) override;
    void OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) override;
    void OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) override;
    void OnReleaseStandBy(int32_t timing) override;
    void OnCompleteCommand(int32_t timing) override;
    bool BeforeCompleteCommand(bool returnValue, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID) override;
    void OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnRoundEnd(int32_t timing) override;
    void OnRoundEnd_Disappeared(int32_t timing) override;
    void OnRetreat(il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) override;
    void OnRoundEnd_After() override;
    void OnStageEnd() override;
    void OnBeforeDefense(il2cpp::Il2CppObject* action) override;
    void OnStartRunBattle() override;
    void OnBattleStart(int32_t timing) override;
    void OnBattleEnd(int32_t timing) override;
    void OnBeforeTurn(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnStartTurn_BeforeLog(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnStartTurn_AfterLog(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnStartDuel(il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing) override;
    void BeforeGiveAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) override;
    void BeforeTakeAttackDamage(il2cpp::Il2CppObject* action, int32_t timing) override;
    void BeforePartTakeAttackDamage(il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnTakeAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing) override;
    void OnTakeAttackDamagePart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical) override;
    void OnGiveHpDamage(il2cpp::Il2CppObject* target, int32_t value, int32_t timing) override;
    void OnGiveMpDamage(il2cpp::Il2CppObject* target, int32_t value) override;
    void OnTakeMpDmg_SinBuff(int32_t value, int32_t timing, int32_t keyword) override;
    void OnKillTarget(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing) override;
    void OnEndTurn(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnBeforeStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) override;
    void OnStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) override;
    void OnEndCoin_BeforeLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) override;
    void OnEndCoin_AfterLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) override;
    void OnEndBehaviour(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnEndBehave_Refresh(il2cpp::Il2CppObject* action) override;
    void OnCriticalActivated(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) override;
    void BeforeAttack(il2cpp::Il2CppObject* action, int32_t timing) override;
    void OnAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing) override;
    bool CanTeamKill(bool returnValue, il2cpp::Il2CppObject* action) override;
    il2cpp::Il2CppObject* GetPrimeTargets(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action) override;
    int32_t GetSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t rollType) override;
    int32_t GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget) override;
    int32_t GetExpectedSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) override;
    bool HasPassive(bool returnValue, int32_t passiveID) override;
    void OnStartPhase(int32_t phase, int32_t timing) override;
    bool HasFakeDead(bool returnValue) override;
    il2cpp::Il2CppObject* OverwriteAtkResist_Default(il2cpp::Il2CppObject* returnValue, int32_t type) override;
    il2cpp::Il2CppObject* OverwriteAtkResist_Result(il2cpp::Il2CppObject* returnValue, int32_t type) override;
    il2cpp::Il2CppObject* OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* returnValue, int32_t type) override;
    il2cpp::Il2CppObject* OverwriteAttributeResist(il2cpp::Il2CppObject* returnValue, int32_t type) override;
    il2cpp::Il2CppObject* OverwriteMaxBuffStack(il2cpp::Il2CppObject* returnValue, int32_t keyword) override;
    il2cpp::Il2CppObject* OverwriteMaxBuffTurn(il2cpp::Il2CppObject* returnValue, int32_t keyword) override;
    il2cpp::Il2CppObject* OverwriteSkillID(il2cpp::Il2CppObject* returnValue, int32_t originID) override;
    il2cpp::Il2CppObject* OverwriteSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed) override;
    bool CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction) override;
    void OnZeroHp() override;
    int32_t GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) override;
    int32_t GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) override;
    int32_t GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) override;
    int32_t GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) override;
    void ActivateEgoPassive(int32_t egoId) override;
    void ActivateEquipEgoPassives() override;
    void ActivateEgoPassives(il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive) override;
    il2cpp::Il2CppObject* GetOwnerEgoModelList(il2cpp::Il2CppObject* returnValue) override;
    il2cpp::Il2CppObject* FindEgoModel(il2cpp::Il2CppObject* returnValue, int32_t egoId) override;
    void AddReadyEgoPassive(int32_t egoId) override;
    bool CanAddEgoPassive(bool returnValue, int32_t egoId) override;
    bool PassesCondition(bool returnValue, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego) override;
    void OnResult_OnAction(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) override;
    void OnResult_OnParrying(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin) override;
    void AddPassive(il2cpp::Il2CppObject* passiveModel) override;
    bool IsRegeneratable(bool returnValue) override;
    bool SpreadHpDmgToAbnormality(bool returnValue, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) override;
    bool SpreadHpDmgFromAbnormalityPart(bool returnValue, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) override;
    void OnSucceedEvade(il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing) override;
    void OnGiveBuffTrigger(il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing) override;
    void RightBeforeLosingBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) override;
    bool CanCreateEmptySlot(bool returnValue) override;
    bool CanCreateEmptySlotPart(bool returnValue, il2cpp::Il2CppObject* part) override;
    int32_t GetActionSlotAdder(int32_t returnValue) override;
    int32_t GetMaxHpAdder(int32_t returnValue) override;
    float GetMaxHpMultiplier(float returnValue) override;
    float GetMaxHpMultiplierPartToAbnormality(float returnValue) override;
    float GetMaxHpMultiplierContributionToAbnormality(float returnValue) override;
    bool CanTakeMpHeal(bool returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType) override;
    void OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) override;
    void OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) override;
    void OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) override;
    bool CheckImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) override;
    bool CheckImmortalOtherUnit(bool returnValue, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf) override;
    void OnGiveImmortalState(il2cpp::Il2CppObject* immortalTaker, int32_t timing) override;
    void OnBeforeActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) override;
    void OnActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) override;
    void OnActivateAbnormalityImmortality(int32_t timing, il2cpp::Il2CppObject* actionOrNull) override;
    void OnActivateOtherUnitBurstReactive(int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing) override;
    void OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull) override;
    void OnAddShield(int32_t timing, int32_t value) override;
    void OnReduceShield(int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull) override;
    void OnDestroyShield(int32_t timing) override;
    void OnDestoryShieldPart(il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull) override;
    void OnRecoverBreak(int32_t timing) override;
    void OnGiveBsGaugeUp(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull) override;
    void OnTakeHpDamage(int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) override;
    void OnTakeHpDamagePart(il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) override;
    void OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword) override;
    void OnTryTakeHpDamage(int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing) override;
    float GetTakeHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) override;
    void OnTakeAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing) override;
    int32_t GetMaxHpAdderPart(int32_t returnValue, il2cpp::Il2CppObject* part) override;
    float GetTakeHpHealMultiplierPart(float returnValue, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) override;
    int32_t GetTakeHpHealAdder(int32_t returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) override;
    void OverwriteTargetableList(il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList) override;
    il2cpp::Il2CppObject* OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* returnValue, int32_t type) override;
    void OnChangeHp(int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) override;
    void OnChangeMp(int32_t oldMp, int32_t newMp) override;
    void OnChangeMpOther(il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp) override;
    void OnTakeMpDamage(il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull) override;
    void OnTakeMpDamageOther(il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull) override;
    void OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) override;
    void UnlockAllPassives() override;
    void OnUseBuffTurnBySkill(il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing) override;
    void OnUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) override;
    void BeforeUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) override;
    float GetCoinProbAdder(float returnValue) override;
    bool OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob) override;
    bool IsEgoSkillFree(bool returnValue, il2cpp::Il2CppObject* ego) override;
    void OnPickSkills() override;
    void OnAddActionToPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action) override;
    void OnAddCoinByAbility(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing) override;
    bool CanOverwritePanicType(bool returnValue) override;
    float GetCriticalChanceAdder(float returnValue, il2cpp::Il2CppObject* affectKeywords) override;
    float GetCriticalDamageRatioResultMultiplier(float returnValue, il2cpp::Il2CppObject* action) override;
    void RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) override;
    bool IsAbnormalityImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) override;
    bool CheckIfTurnToCorpesOnDie(bool returnValue) override;
    void OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing) override;
    void CheckOverwriteGettingBuff(int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound) override;
    bool IsAllowedToGiveBuff(bool returnValue, int32_t keyword) override;
    void OnFailedToGetBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull) override;
    void RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) override;
    void OnFailedToGiveBuff(il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull) override;
    void OnUseCoinConsume(il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) override;
    bool BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) override;
    il2cpp::Il2CppObject* OverwritePartSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed, il2cpp::Il2CppObject* part) override;
    bool BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical) override;
    bool BlockLoseBuffStack(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) override;
    bool BlockLoseBuffTurn(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) override;
    bool IsBlockingSinkingBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing) override;
    bool IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) override;
    il2cpp::Il2CppObject* OverwriteCanDuel(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction) override;
    bool IsBlockingBurstBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing) override;
    bool IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) override;
    bool ModifyMpChangeValue(bool returnValue, int32_t oldMp, int32_t newMp, int32_t* changedNewMp) override;
    void OnAddBattleAction(il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction) override;
    void OnRemoveBattleAction(il2cpp::Il2CppObject* actorAction) override;
    bool IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull) override;
};

using PassiveFactory = std::function<std::unique_ptr<PassiveBase>()>;

inline std::unordered_set<int32_t> allCustomPassiveIDs = {};

inline std::unordered_map<int32_t, PassiveFactory>& passiveRegistry() {
    static std::unordered_map<int32_t, PassiveFactory> reg;  // function-local static avoids init-order problems
    return reg;
}

// Register a class by type. T must derive from PassiveBase and be default-constructible.
template <typename T>
void registerPassive(int32_t id) {
    static_assert(std::is_base_of_v<PassiveBase, T>, "T must derive from PassiveBase");
    allCustomPassiveIDs.insert(id);
    passiveRegistry()[id] = [] { return std::make_unique<T>(); };
}

// game PassiveBase instance -> C++ handler (normally a PassiveDetail). Filled by hooked_PassiveBase_ctor.
inline std::unordered_map<il2cpp::Il2CppObject*, PassiveBase*> PassiveBaseMap;

void init_PassiveBase(il2cpp::Il2CppImage* img);


// ---- hook blueprints: Fn type, original_ pointer (set by InstallHook), hooked_ replacement ----

// C#: System.Void OnStartBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartBehaviourFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartBehaviourFn original_PassiveBase_OnStartBehaviour = nullptr;
void hooked_PassiveBase_OnStartBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnSucceedAttack(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnSucceedAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, bool, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnSucceedAttackFn original_PassiveBase_OnSucceedAttack = nullptr;
void hooked_PassiveBase_OnSucceedAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Void OnRollOneCoin_AfterAttack(BattleActionModel action, CoinModel coin)
using PassiveBaseOnRollOneCoin_AfterAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnRollOneCoin_AfterAttackFn original_PassiveBase_OnRollOneCoin_AfterAttack = nullptr;
void hooked_PassiveBase_OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

// C#: System.Void OnEndAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndAttackFn original_PassiveBase_OnEndAttack = nullptr;
void hooked_PassiveBase_OnEndAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnEndAttackOtherUnit(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndAttackOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndAttackOtherUnitFn original_PassiveBase_OnEndAttackOtherUnit = nullptr;
void hooked_PassiveBase_OnEndAttackOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing);

// C#: System.Void OnStartEnemyAttack(BattleUnitModel unit, BattleActionModel opponentAction, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartEnemyAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartEnemyAttackFn original_PassiveBase_OnStartEnemyAttack = nullptr;
void hooked_PassiveBase_OnStartEnemyAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Void OnEndEnemyAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndEnemyAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndEnemyAttackFn original_PassiveBase_OnEndEnemyAttack = nullptr;
void hooked_PassiveBase_OnEndEnemyAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnEndAttackPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndAttackPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndAttackPartFn original_PassiveBase_OnEndAttackPart = nullptr;
void hooked_PassiveBase_OnEndAttackPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnDuelAfter_BeforeLog(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDuelAfter_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnDuelAfter_BeforeLogFn original_PassiveBase_OnDuelAfter_BeforeLog = nullptr;
void hooked_PassiveBase_OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing);

// C#: System.Void OnAfterParryingOnce_BeforeLog(PARRYING_RESULT result, BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAfterParryingOnce_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnAfterParryingOnce_BeforeLogFn original_PassiveBase_OnAfterParryingOnce_BeforeLog = nullptr;
void hooked_PassiveBase_OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing);

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAfterParryingOnce_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAfterParryingOnce_AfterLogFn original_PassiveBase_OnAfterParryingOnce_AfterLog = nullptr;
void hooked_PassiveBase_OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

// C#: System.Void OnWinParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnWinParryingFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnWinParryingFn original_PassiveBase_OnWinParrying = nullptr;
void hooked_PassiveBase_OnWinParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

// C#: System.Void OnLoseParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnLoseParryingFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnLoseParryingFn original_PassiveBase_OnLoseParrying = nullptr;
void hooked_PassiveBase_OnLoseParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

// C#: System.Void OnWinDuel(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnWinDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnWinDuelFn original_PassiveBase_OnWinDuel = nullptr;
void hooked_PassiveBase_OnWinDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing);

// C#: System.Void OnLoseDuel(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnLoseDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnLoseDuelFn original_PassiveBase_OnLoseDuel = nullptr;
void hooked_PassiveBase_OnLoseDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing);

// C#: System.Void OnLoseDuelOtherUnit(BattleActionModel loserAction, BattleActionModel winnerAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnLoseDuelOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnLoseDuelOtherUnitFn original_PassiveBase_OnLoseDuelOtherUnit = nullptr;
void hooked_PassiveBase_OnLoseDuelOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing);

// C#: System.Void RightBeforeGiveBuffBySkill(SkillModel skill, CoinModel coinOrNull, BUFF_UNIQUE_KEYWORD buf, System.Int32 stack, System.Int32 turn, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
using PassiveBaseRightBeforeGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseRightBeforeGiveBuffBySkillFn original_PassiveBase_RightBeforeGiveBuffBySkill = nullptr;
void hooked_PassiveBase_RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical);

// C#: System.Void RightAfterGiveBuffBySkill(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
using PassiveBaseRightAfterGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseRightAfterGiveBuffBySkillFn original_PassiveBase_RightAfterGiveBuffBySkill = nullptr;
void hooked_PassiveBase_RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical);

// C#: System.Void RightAfterTakeBuffBySkill(BattleUnitModel unit, BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, BattleUnitModel giver, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, System.Int32 afterAdderStack, System.Int32 afterAdderTurn)
using PassiveBaseRightAfterTakeBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseRightAfterTakeBuffBySkillFn original_PassiveBase_RightAfterTakeBuffBySkill = nullptr;
void hooked_PassiveBase_RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn);

// C#: System.Void RightBeforeOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightBeforeOtherUnitGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseRightBeforeOtherUnitGiveBuffBySkillFn original_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill = nullptr;
void hooked_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing);

// C#: System.Void RightAfterOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightAfterOtherUnitGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseRightAfterOtherUnitGiveBuffBySkillFn original_PassiveBase_RightAfterOtherUnitGiveBuffBySkill = nullptr;
void hooked_PassiveBase_RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing);

// C#: System.Void RightAfterAnyUnitGetAnyBuff(BattleUnitModel receiver, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, BattleUnitModel giverOrNull, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, System.Int32 overStack, System.Int32 overTurn)
using PassiveBaseRightAfterAnyUnitGetAnyBuffFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseRightAfterAnyUnitGetAnyBuffFn original_PassiveBase_RightAfterAnyUnitGetAnyBuff = nullptr;
void hooked_PassiveBase_RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn);

// C#: System.Void RightAfterLosingBuff(System.Int32 loseStack, System.Int32 loseTurn, BuffInfo loseBuffInfo, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightAfterLosingBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseRightAfterLosingBuffFn original_PassiveBase_RightAfterLosingBuff = nullptr;
void hooked_PassiveBase_RightAfterLosingBuff(il2cpp::Il2CppObject* __this, int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing);

// C#: System.Void OnSucceedToGiveSwitchToSpecialVibration(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 prevStack, System.Int32 prevTurn, System.Int32 afterStack, System.Int32 afterTurn, System.Boolean isPileUp, BATTLE_EVENT_TIMING timing, ABILITY_SOURCE_TYPE abilitySourceType)
using PassiveBaseOnSucceedToGiveSwitchToSpecialVibrationFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, bool, int32_t, int32_t);
inline PassiveBaseOnSucceedToGiveSwitchToSpecialVibrationFn original_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration = nullptr;
void hooked_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType);

// C#: System.Void RightAfterGetAnyBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
using PassiveBaseRightAfterGetAnyBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseRightAfterGetAnyBuffFn original_PassiveBase_RightAfterGetAnyBuff = nullptr;
void hooked_PassiveBase_RightAfterGetAnyBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn);

// C#: System.Void RightAfterGetAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull)
using PassiveBaseRightAfterGetAnyBuffAtPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseRightAfterGetAnyBuffAtPartFn original_PassiveBase_RightAfterGetAnyBuffAtPart = nullptr;
void hooked_PassiveBase_RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void RightAfterDestroyAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightAfterDestroyAnyBuffAtPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseRightAfterDestroyAnyBuffAtPartFn original_PassiveBase_RightAfterDestroyAnyBuffAtPart = nullptr;
void hooked_PassiveBase_RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing);

// C#: System.Int32 GetAggroAdder(SinActionModel sinaction)
using PassiveBaseGetAggroAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetAggroAdderFn original_PassiveBase_GetAggroAdder = nullptr;
int32_t hooked_PassiveBase_GetAggroAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sinaction);

// C#: System.Int32 GetAttackWeightAdder(BattleActionModel action)
using PassiveBaseGetAttackWeightAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetAttackWeightAdderFn original_PassiveBase_GetAttackWeightAdder = nullptr;
int32_t hooked_PassiveBase_GetAttackWeightAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Int32 GetMentalSystemResultIncreaseAdder()
using PassiveBaseGetMentalSystemResultIncreaseAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMentalSystemResultIncreaseAdderFn original_PassiveBase_GetMentalSystemResultIncreaseAdder = nullptr;
int32_t hooked_PassiveBase_GetMentalSystemResultIncreaseAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetMentalSystemResultDecreaseAdder()
using PassiveBaseGetMentalSystemResultDecreaseAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMentalSystemResultDecreaseAdderFn original_PassiveBase_GetMentalSystemResultDecreaseAdder = nullptr;
int32_t hooked_PassiveBase_GetMentalSystemResultDecreaseAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetInitBuffMaxStackAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseGetInitBuffMaxStackAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetInitBuffMaxStackAdderFn original_PassiveBase_GetInitBuffMaxStackAdder = nullptr;
int32_t hooked_PassiveBase_GetInitBuffMaxStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword);

// C#: System.Int32 GetInitBuffMaxTurnAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseGetInitBuffMaxTurnAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetInitBuffMaxTurnAdderFn original_PassiveBase_GetInitBuffMaxTurnAdder = nullptr;
int32_t hooked_PassiveBase_GetInitBuffMaxTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword);

// C#: System.Int32 GetTakeBuffTurnAdderOtherUnit(BattleUnitModel taker, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseGetTakeBuffTurnAdderOtherUnitFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseGetTakeBuffTurnAdderOtherUnitFn original_PassiveBase_GetTakeBuffTurnAdderOtherUnit = nullptr;
int32_t hooked_PassiveBase_GetTakeBuffTurnAdderOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing);

// C#: System.Int32 GetTakeBuffStackAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originStack, BATTLE_EVENT_TIMING timing)
using PassiveBaseGetTakeBuffStackAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseGetTakeBuffStackAdderFn original_PassiveBase_GetTakeBuffStackAdder = nullptr;
int32_t hooked_PassiveBase_GetTakeBuffStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing);

// C#: System.Int32 GetTakeBuffTurnAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseGetTakeBuffTurnAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseGetTakeBuffTurnAdderFn original_PassiveBase_GetTakeBuffTurnAdder = nullptr;
int32_t hooked_PassiveBase_GetTakeBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing);

// C#: System.Int32 GetGiveBuffTurnAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseGetGiveBuffTurnAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseGetGiveBuffTurnAdderFn original_PassiveBase_GetGiveBuffTurnAdder = nullptr;
int32_t hooked_PassiveBase_GetGiveBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing);

// C#: System.Int32 GetGiveBuffStackAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
using PassiveBaseGetGiveBuffStackAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseGetGiveBuffStackAdderFn original_PassiveBase_GetGiveBuffStackAdder = nullptr;
int32_t hooked_PassiveBase_GetGiveBuffStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical);

// C#: System.Int32 GetUseBuffTurnAdder(BattleActionModel action, SkillModel skill, System.Int32 turn, BUFF_UNIQUE_KEYWORD buf)
using PassiveBaseGetUseBuffTurnAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseGetUseBuffTurnAdderFn original_PassiveBase_GetUseBuffTurnAdder = nullptr;
int32_t hooked_PassiveBase_GetUseBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf);

// C#: System.Single GetTakeBuffStackMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
using PassiveBaseGetTakeBuffStackMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetTakeBuffStackMultiplierFn original_PassiveBase_GetTakeBuffStackMultiplier = nullptr;
float hooked_PassiveBase_GetTakeBuffStackMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t buf);

// C#: System.Single GetTakeBuffTurnMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
using PassiveBaseGetTakeBuffTurnMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetTakeBuffTurnMultiplierFn original_PassiveBase_GetTakeBuffTurnMultiplier = nullptr;
float hooked_PassiveBase_GetTakeBuffTurnMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t buf);

// C#: System.Void OnActivateSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 takeDmg, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced, System.Nullable<System.Boolean> isCritical)
using PassiveBaseOnActivateSinBuffEffectFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool, il2cpp::Il2CppObject*);
inline PassiveBaseOnActivateSinBuffEffectFn original_PassiveBase_OnActivateSinBuffEffect = nullptr;
void hooked_PassiveBase_OnActivateSinBuffEffect(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical);

// C#: System.Void OnActivateOtherUnitSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, System.Int32 takeDmg, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced)
using PassiveBaseOnActivateOtherUnitSinBuffEffectFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, bool);
inline PassiveBaseOnActivateOtherUnitSinBuffEffectFn original_PassiveBase_OnActivateOtherUnitSinBuffEffect = nullptr;
void hooked_PassiveBase_OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced);

// C#: System.Boolean IgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
using PassiveBaseIgnoreSinBuffHpDamageFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t);
inline PassiveBaseIgnoreSinBuffHpDamageFn original_PassiveBase_IgnoreSinBuffHpDamage = nullptr;
bool hooked_PassiveBase_IgnoreSinBuffHpDamage(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

// C#: System.Boolean IgnoreSinBuffHpDamagePart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
using PassiveBaseIgnoreSinBuffHpDamagePartFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t);
inline PassiveBaseIgnoreSinBuffHpDamagePartFn original_PassiveBase_IgnoreSinBuffHpDamagePart = nullptr;
bool hooked_PassiveBase_IgnoreSinBuffHpDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

// C#: System.Void OnIgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnIgnoreSinBuffHpDamageFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t);
inline PassiveBaseOnIgnoreSinBuffHpDamageFn original_PassiveBase_OnIgnoreSinBuffHpDamage = nullptr;
void hooked_PassiveBase_OnIgnoreSinBuffHpDamage(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing);

// C#: System.Int32 GetSinBuffDamageAdder(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg)
using PassiveBaseGetSinBuffDamageAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseGetSinBuffDamageAdderFn original_PassiveBase_GetSinBuffDamageAdder = nullptr;
int32_t hooked_PassiveBase_GetSinBuffDamageAdder(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg);

// C#: System.Single GetSinBuffDamageMultiplier(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseGetSinBuffDamageMultiplierFn = float(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetSinBuffDamageMultiplierFn original_PassiveBase_GetSinBuffDamageMultiplier = nullptr;
float hooked_PassiveBase_GetSinBuffDamageMultiplier(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Int32 GetMaxBuffStackAdder(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseGetMaxBuffStackAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetMaxBuffStackAdderFn original_PassiveBase_GetMaxBuffStackAdder = nullptr;
int32_t hooked_PassiveBase_GetMaxBuffStackAdder(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Int32 GetMaxBuffTurnAdder(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseGetMaxBuffTurnAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetMaxBuffTurnAdderFn original_PassiveBase_GetMaxBuffTurnAdder = nullptr;
int32_t hooked_PassiveBase_GetMaxBuffTurnAdder(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Int32 GetUnitStatLevelAdder()
using PassiveBaseGetUnitStatLevelAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetUnitStatLevelAdderFn original_PassiveBase_GetUnitStatLevelAdder = nullptr;
int32_t hooked_PassiveBase_GetUnitStatLevelAdder(il2cpp::Il2CppObject* __this);

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull, BattleUnitModel target)
using PassiveBaseGetGiveBsGaugeUpMultiplierFn = float(*)(il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetGiveBsGaugeUpMultiplierFn original_PassiveBase_GetGiveBsGaugeUpMultiplier = nullptr;
float hooked_PassiveBase_GetGiveBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target);

// C#: System.Single GetTakeBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull)
using PassiveBaseGetTakeBsGaugeUpMultiplierFn = float(*)(il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetTakeBsGaugeUpMultiplierFn original_PassiveBase_GetTakeBsGaugeUpMultiplier = nullptr;
float hooked_PassiveBase_GetTakeBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull);

// C#: System.Int32 GetSkillPoolCountAdder(System.Int32 index, UnitAttribute attribute)
using PassiveBaseGetSkillPoolCountAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseGetSkillPoolCountAdderFn original_PassiveBase_GetSkillPoolCountAdder = nullptr;
int32_t hooked_PassiveBase_GetSkillPoolCountAdder(il2cpp::Il2CppObject* __this, int32_t index, il2cpp::Il2CppObject* attribute);

// C#: System.Void OnDestroy(BattleUnitModel destroyerOrNull, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDestroyFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnDestroyFn original_PassiveBase_OnDestroy = nullptr;
void hooked_PassiveBase_OnDestroy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyerOrNull, int32_t timing);

// C#: System.Void OnOtherPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart)
using PassiveBaseOnOtherPartDestroyedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnOtherPartDestroyedFn original_PassiveBase_OnOtherPartDestroyed = nullptr;
void hooked_PassiveBase_OnOtherPartDestroyed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedPart);

// C#: System.Void OnPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnPartDestroyedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnPartDestroyedFn original_PassiveBase_OnPartDestroyed = nullptr;
void hooked_PassiveBase_OnPartDestroyed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedPart, int32_t timing);

// C#: System.Void OnPartBreaked(BattleUnitModel_Abnormality_Part breakedPart, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnPartBreakedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnPartBreakedFn original_PassiveBase_OnPartBreaked = nullptr;
void hooked_PassiveBase_OnPartBreaked(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedPart, int32_t timing);

// C#: System.Void OnPartRecoverBreak(BattleUnitModel_Abnormality_Part recoveredPart, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnPartRecoverBreakFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnPartRecoverBreakFn original_PassiveBase_OnPartRecoverBreak = nullptr;
void hooked_PassiveBase_OnPartRecoverBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* recoveredPart, int32_t timing);

// C#: System.Void OnRegenerate(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRegenerateFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRegenerateFn original_PassiveBase_OnRegenerate = nullptr;
void hooked_PassiveBase_OnRegenerate(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnPartRegenerate(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnPartRegenerateFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnPartRegenerateFn original_PassiveBase_OnPartRegenerate = nullptr;
void hooked_PassiveBase_OnPartRegenerate(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing);

// C#: System.Boolean CheckUnitGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using PassiveBaseCheckUnitGivingBuffCategoryFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline PassiveBaseCheckUnitGivingBuffCategoryFn original_PassiveBase_CheckUnitGivingBuffCategory = nullptr;
bool hooked_PassiveBase_CheckUnitGivingBuffCategory(il2cpp::Il2CppObject* __this, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Boolean CheckUnitGivingBuffKeyword(BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using PassiveBaseCheckUnitGivingBuffKeywordFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline PassiveBaseCheckUnitGivingBuffKeywordFn original_PassiveBase_CheckUnitGivingBuffKeyword = nullptr;
bool hooked_PassiveBase_CheckUnitGivingBuffKeyword(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Boolean CheckSkillGivingBuffCategory(BattleActionModel action, BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using PassiveBaseCheckSkillGivingBuffCategoryFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline PassiveBaseCheckSkillGivingBuffCategoryFn original_PassiveBase_CheckSkillGivingBuffCategory = nullptr;
bool hooked_PassiveBase_CheckSkillGivingBuffCategory(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Boolean CheckSkillGivingBuff(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using PassiveBaseCheckSkillGivingBuffFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline PassiveBaseCheckSkillGivingBuffFn original_PassiveBase_CheckSkillGivingBuff = nullptr;
bool hooked_PassiveBase_CheckSkillGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Void CheckLoseBuffStackAndTurn(BuffInfo info, System.Int32& loseStack, System.Int32& loseTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseCheckLoseBuffStackAndTurnFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*, int32_t*, int32_t);
inline PassiveBaseCheckLoseBuffStackAndTurnFn original_PassiveBase_CheckLoseBuffStackAndTurn = nullptr;
void hooked_PassiveBase_CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing);

// C#: System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin)
using PassiveBaseGetCoinScaleAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetCoinScaleAdderFn original_PassiveBase_GetCoinScaleAdder = nullptr;
int32_t hooked_PassiveBase_GetCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin);

// C#: System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, SinActionModel expectedTargetSinActionOrNull)
using PassiveBaseGetExpectedCoinScaleAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedCoinScaleAdderFn original_PassiveBase_GetExpectedCoinScaleAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

// C#: System.Int32 GetSkillPowerResultAdder(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseGetSkillPowerResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetSkillPowerResultAdderFn original_PassiveBase_GetSkillPowerResultAdder = nullptr;
int32_t hooked_PassiveBase_GetSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Int32 GetTakeHpDmgAdder()
using PassiveBaseGetTakeHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetTakeHpDmgAdderFn original_PassiveBase_GetTakeHpDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetTakeHpDmgAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetExpectedTakeHpDmgAdder()
using PassiveBaseGetExpectedTakeHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedTakeHpDmgAdderFn original_PassiveBase_GetExpectedTakeHpDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedTakeHpDmgAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetMinSpeedAdder()
using PassiveBaseGetMinSpeedAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMinSpeedAdderFn original_PassiveBase_GetMinSpeedAdder = nullptr;
int32_t hooked_PassiveBase_GetMinSpeedAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetMaxSpeedAdder()
using PassiveBaseGetMaxSpeedAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxSpeedAdderFn original_PassiveBase_GetMaxSpeedAdder = nullptr;
int32_t hooked_PassiveBase_GetMaxSpeedAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetSpeedAdder()
using PassiveBaseGetSpeedAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetSpeedAdderFn original_PassiveBase_GetSpeedAdder = nullptr;
int32_t hooked_PassiveBase_GetSpeedAdder(il2cpp::Il2CppObject* __this);

// C#: System.Boolean UseOnlyDefaultMinSpeed()
using PassiveBaseUseOnlyDefaultMinSpeedFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseUseOnlyDefaultMinSpeedFn original_PassiveBase_UseOnlyDefaultMinSpeed = nullptr;
bool hooked_PassiveBase_UseOnlyDefaultMinSpeed(il2cpp::Il2CppObject* __this);

// C#: System.Boolean UseOnlyDefaultMaxSpeed()
using PassiveBaseUseOnlyDefaultMaxSpeedFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseUseOnlyDefaultMaxSpeedFn original_PassiveBase_UseOnlyDefaultMaxSpeed = nullptr;
bool hooked_PassiveBase_UseOnlyDefaultMaxSpeed(il2cpp::Il2CppObject* __this);

// C#: System.Int32 ChangeAttackDamage(BattleActionModel action, BattleUnitModel target, CoinModel coin, System.Int32 resultDmg, System.Boolean& isCritical, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged)
using PassiveBaseChangeAttackDamageFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool*, int32_t, bool*);
inline PassiveBaseChangeAttackDamageFn original_PassiveBase_ChangeAttackDamage = nullptr;
int32_t hooked_PassiveBase_ChangeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged);

// C#: System.Int32 ChangeTakeDamage(BattleActionModel action, CoinModel coinOrNull, System.Int32 resultDmg, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged, System.Int32 preCalculatedDmg)
using PassiveBaseChangeTakeDamageFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, bool*, int32_t);
inline PassiveBaseChangeTakeDamageFn original_PassiveBase_ChangeTakeDamage = nullptr;
int32_t hooked_PassiveBase_ChangeTakeDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg);

// C#: System.Int32 ChangeMpDamage(System.Int32 resultDmg, BattleActionModel actionOrNull, BASE_MENTAL_CONDITION mentalConditionOrNone, BUFF_UNIQUE_KEYWORD keywordOrNone, AbilityBase abilityOrNull, System.Boolean& isChanged, BATTLE_EVENT_TIMING timing)
using PassiveBaseChangeMpDamageFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, bool*, int32_t);
inline PassiveBaseChangeMpDamageFn original_PassiveBase_ChangeMpDamage = nullptr;
int32_t hooked_PassiveBase_ChangeMpDamage(il2cpp::Il2CppObject* __this, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing);

// C#: System.Int32 GetAttackHpDmgAdder(BattleUnitModel target)
using PassiveBaseGetAttackHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetAttackHpDmgAdderFn original_PassiveBase_GetAttackHpDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target);

// C#: System.Int32 GetExpectedAttackHpDmgAdder(BattleUnitModel target)
using PassiveBaseGetExpectedAttackHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedAttackHpDmgAdderFn original_PassiveBase_GetExpectedAttackHpDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target);

// C#: System.Int32 GetAttackDmgAdder(BattleActionModel action, BattleUnitModel target)
using PassiveBaseGetAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetAttackDmgAdderFn original_PassiveBase_GetAttackDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target);

// C#: System.Int32 GetExpectedAttackDmgAdder(BattleActionModel action, BattleUnitModel targetOrNull)
using PassiveBaseGetExpectedAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedAttackDmgAdderFn original_PassiveBase_GetExpectedAttackDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull);

// C#: System.Single GetAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical)
using PassiveBaseGetAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, bool);
inline PassiveBaseGetAttackDmgMultiplierFn original_PassiveBase_GetAttackDmgMultiplier = nullptr;
float hooked_PassiveBase_GetAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical);

// C#: System.Single GetExpectedAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
using PassiveBaseGetExpectedAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedAttackDmgMultiplierFn original_PassiveBase_GetExpectedAttackDmgMultiplier = nullptr;
float hooked_PassiveBase_GetExpectedAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

// C#: System.Int32 GetTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
using PassiveBaseGetTakeAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetTakeAttackDmgAdderFn original_PassiveBase_GetTakeAttackDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetTakeAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

// C#: System.Int32 GetExpectedTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
using PassiveBaseGetExpectedTakeAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedTakeAttackDmgAdderFn original_PassiveBase_GetExpectedTakeAttackDmgAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedTakeAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

// C#: System.Single GetTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker, System.Boolean isCritical)
using PassiveBaseGetTakeAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline PassiveBaseGetTakeAttackDmgMultiplierFn original_PassiveBase_GetTakeAttackDmgMultiplier = nullptr;
float hooked_PassiveBase_GetTakeAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical);

// C#: System.Single GetExpectedTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker)
using PassiveBaseGetExpectedTakeAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedTakeAttackDmgMultiplierFn original_PassiveBase_GetExpectedTakeAttackDmgMultiplier = nullptr;
float hooked_PassiveBase_GetExpectedTakeAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker);

// C#: System.Int32 GetAttackAdder(BattleActionModel actionOrNull)
using PassiveBaseGetAttackAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetAttackAdderFn original_PassiveBase_GetAttackAdder = nullptr;
int32_t hooked_PassiveBase_GetAttackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Int32 GetUnitDefaultLevelAdder()
using PassiveBaseGetUnitDefaultLevelAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetUnitDefaultLevelAdderFn original_PassiveBase_GetUnitDefaultLevelAdder = nullptr;
int32_t hooked_PassiveBase_GetUnitDefaultLevelAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetDefenseAdder()
using PassiveBaseGetDefenseAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetDefenseAdderFn original_PassiveBase_GetDefenseAdder = nullptr;
int32_t hooked_PassiveBase_GetDefenseAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetUnitDefenseAdder()
using PassiveBaseGetUnitDefenseAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetUnitDefenseAdderFn original_PassiveBase_GetUnitDefenseAdder = nullptr;
int32_t hooked_PassiveBase_GetUnitDefenseAdder(il2cpp::Il2CppObject* __this);

// C#: System.Single GetDefenseMultiplier()
using PassiveBaseGetDefenseMultiplierFn = float(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetDefenseMultiplierFn original_PassiveBase_GetDefenseMultiplier = nullptr;
float hooked_PassiveBase_GetDefenseMultiplier(il2cpp::Il2CppObject* __this);

// C#: System.Single GetHpHealMultiplier(BattleUnitModel target)
using PassiveBaseGetHpHealMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetHpHealMultiplierFn original_PassiveBase_GetHpHealMultiplier = nullptr;
float hooked_PassiveBase_GetHpHealMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target);

// C#: System.Single GetAtkResistMultiplier(ATK_BEHAVIOUR type)
using PassiveBaseGetAtkResistMultiplierFn = float(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetAtkResistMultiplierFn original_PassiveBase_GetAtkResistMultiplier = nullptr;
float hooked_PassiveBase_GetAtkResistMultiplier(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Single GetAtkResistAdder(ATK_BEHAVIOUR type)
using PassiveBaseGetAtkResistAdderFn = float(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetAtkResistAdderFn original_PassiveBase_GetAtkResistAdder = nullptr;
float hooked_PassiveBase_GetAtkResistAdder(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Single GetAttributeResistMultiplier(ATTRIBUTE_TYPE type)
using PassiveBaseGetAttributeResistMultiplierFn = float(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetAttributeResistMultiplierFn original_PassiveBase_GetAttributeResistMultiplier = nullptr;
float hooked_PassiveBase_GetAttributeResistMultiplier(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Single GetAttributeResistAdder(ATTRIBUTE_TYPE type)
using PassiveBaseGetAttributeResistAdderFn = float(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetAttributeResistAdderFn original_PassiveBase_GetAttributeResistAdder = nullptr;
float hooked_PassiveBase_GetAttributeResistAdder(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Void OnDie(BattleUnitModel killer, BattleActionModel actionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDieFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnDieFn original_PassiveBase_OnDie = nullptr;
void hooked_PassiveBase_OnDie(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing);

// C#: System.Void OnBreak(BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
using PassiveBaseOnBreakFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool);
inline PassiveBaseOnBreakFn original_PassiveBase_OnBreak = nullptr;
void hooked_PassiveBase_OnBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely);

// C#: System.Void OnEnemyBrokenByAttacker(BattleActionModel actionOrNull, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEnemyBrokenByAttackerFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEnemyBrokenByAttackerFn original_PassiveBase_OnEnemyBrokenByAttacker = nullptr;
void hooked_PassiveBase_OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing);

// C#: System.Void OnDieOtherUnit(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnDieOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnDieOtherUnitFn original_PassiveBase_OnDieOtherUnit = nullptr;
void hooked_PassiveBase_OnDieOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

// C#: System.Void OnDieOtherUnit_Retreated(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnDieOtherUnit_RetreatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnDieOtherUnit_RetreatedFn original_PassiveBase_OnDieOtherUnit_Retreated = nullptr;
void hooked_PassiveBase_OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

// C#: System.Void OnDieOtherUnit_Disappeared(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnDieOtherUnit_DisappearedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnDieOtherUnit_DisappearedFn original_PassiveBase_OnDieOtherUnit_Disappeared = nullptr;
void hooked_PassiveBase_OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword);

// C#: System.Void OnRetreatOtherUnit(BattleUnitModel retreatUnit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRetreatOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnRetreatOtherUnitFn original_PassiveBase_OnRetreatOtherUnit = nullptr;
void hooked_PassiveBase_OnRetreatOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing);

// C#: System.Void OnRetreatOtherUnit_Retreated(BattleUnitModel retreatUnit, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRetreatOtherUnit_RetreatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRetreatOtherUnit_RetreatedFn original_PassiveBase_OnRetreatOtherUnit_Retreated = nullptr;
void hooked_PassiveBase_OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* retreatUnit, int32_t timing);

// C#: System.Void OnDiscardSinOtherUnit(BattleUnitModel discardUnit, UnitSinModel sin, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
using PassiveBaseOnDiscardSinOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnDiscardSinOtherUnitFn original_PassiveBase_OnDiscardSinOtherUnit = nullptr;
void hooked_PassiveBase_OnDiscardSinOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnDiscardSin(UnitSinModel sin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDiscardSinFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnDiscardSinFn original_PassiveBase_OnDiscardSin = nullptr;
void hooked_PassiveBase_OnDiscardSin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sin, int32_t timing);

// C#: System.Void OnDisappeared(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDisappearedFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnDisappearedFn original_PassiveBase_OnDisappeared = nullptr;
void hooked_PassiveBase_OnDisappeared(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnReturnFromDisappeared(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnReturnFromDisappearedFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnReturnFromDisappearedFn original_PassiveBase_OnReturnFromDisappeared = nullptr;
void hooked_PassiveBase_OnReturnFromDisappeared(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnBreakOtherUnit(BattleUnitModel breakedUnit, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
using PassiveBaseOnBreakOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool);
inline PassiveBaseOnBreakOtherUnitFn original_PassiveBase_OnBreakOtherUnit = nullptr;
void hooked_PassiveBase_OnBreakOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely);

// C#: System.Void OnCheckBreak(System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
using PassiveBaseOnCheckBreakFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnCheckBreakFn original_PassiveBase_OnCheckBreak = nullptr;
void hooked_PassiveBase_OnCheckBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType);

// C#: System.Void OnCheckPartBreak(BattleUnitModel_Abnormality_Part breakedPart, System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
using PassiveBaseOnCheckPartBreakFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnCheckPartBreakFn original_PassiveBase_OnCheckPartBreak = nullptr;
void hooked_PassiveBase_OnCheckPartBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType);

// C#: System.Void OnVibrationExplosion(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnVibrationExplosionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnVibrationExplosionFn original_PassiveBase_OnVibrationExplosion = nullptr;
void hooked_PassiveBase_OnVibrationExplosion(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing);

// C#: System.Void OnVibrationExplosionOtherUnit(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnVibrationExplosionOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnVibrationExplosionOtherUnitFn original_PassiveBase_OnVibrationExplosionOtherUnit = nullptr;
void hooked_PassiveBase_OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing);

// C#: System.Void OnTakeAttackDamageOtherUnit(BattleActionModel action, System.Int32 realDmg, System.Int32 hpDmg, BattleUnitModel attackedUnit, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnTakeAttackDamageOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTakeAttackDamageOtherUnitFn original_PassiveBase_OnTakeAttackDamageOtherUnit = nullptr;
void hooked_PassiveBase_OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing);

// C#: System.Void OnUseBuffStackBySkill(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnUseBuffStackBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnUseBuffStackBySkillFn original_PassiveBase_OnUseBuffStackBySkill = nullptr;
void hooked_PassiveBase_OnUseBuffStackBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing);

// C#: System.Void OnUseBloodDinnerUnit(BattleUnitModel usedUnit, System.Int32 stack, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnUseBloodDinnerUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnUseBloodDinnerUnitFn original_PassiveBase_OnUseBloodDinnerUnit = nullptr;
void hooked_PassiveBase_OnUseBloodDinnerUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing);

// C#: System.Void OnAddUnit(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAddUnitFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAddUnitFn original_PassiveBase_OnAddUnit = nullptr;
void hooked_PassiveBase_OnAddUnit(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnAddUnit_After(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAddUnit_AfterFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAddUnit_AfterFn original_PassiveBase_OnAddUnit_After = nullptr;
void hooked_PassiveBase_OnAddUnit_After(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnAddUnitPart(BattleUnitModel part, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAddUnitPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAddUnitPartFn original_PassiveBase_OnAddUnitPart = nullptr;
void hooked_PassiveBase_OnAddUnitPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing);

// C#: System.Void Init_After()
using PassiveBaseInit_AfterFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseInit_AfterFn original_PassiveBase_Init_After = nullptr;
void hooked_PassiveBase_Init_After(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAddUnitView(BattleUnitView view)
using PassiveBaseOnAddUnitViewFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnAddUnitViewFn original_PassiveBase_OnAddUnitView = nullptr;
void hooked_PassiveBase_OnAddUnitView(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* view);

// C#: System.Void OnStageStart(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStageStartFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStageStartFn original_PassiveBase_OnStageStart = nullptr;
void hooked_PassiveBase_OnStageStart(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnWaveStart(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnWaveStartFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnWaveStartFn original_PassiveBase_OnWaveStart = nullptr;
void hooked_PassiveBase_OnWaveStart(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnPanicOrLowMorale(PANIC_LEVEL level, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnPanicOrLowMoraleFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnPanicOrLowMoraleFn original_PassiveBase_OnPanicOrLowMorale = nullptr;
void hooked_PassiveBase_OnPanicOrLowMorale(il2cpp::Il2CppObject* __this, int32_t level, int32_t timing);

// C#: System.Void OnRoundStart_Before()
using PassiveBaseOnRoundStart_BeforeFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnRoundStart_BeforeFn original_PassiveBase_OnRoundStart_Before = nullptr;
void hooked_PassiveBase_OnRoundStart_Before(il2cpp::Il2CppObject* __this);

// C#: System.Void OnRoundStart()
using PassiveBaseOnRoundStartFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnRoundStartFn original_PassiveBase_OnRoundStart = nullptr;
void hooked_PassiveBase_OnRoundStart(il2cpp::Il2CppObject* __this);

// C#: System.Void OnRoundStart_After_Event(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRoundStart_After_EventFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRoundStart_After_EventFn original_PassiveBase_OnRoundStart_After_Event = nullptr;
void hooked_PassiveBase_OnRoundStart_After_Event(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnRoundStart_After_Event_DeadOrRetreated(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRoundStart_After_Event_DeadOrRetreatedFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRoundStart_After_Event_DeadOrRetreatedFn original_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated = nullptr;
void hooked_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnRoundStart_After_RelatedSlotState(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRoundStart_After_RelatedSlotStateFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRoundStart_After_RelatedSlotStateFn original_PassiveBase_OnRoundStart_After_RelatedSlotState = nullptr;
void hooked_PassiveBase_OnRoundStart_After_RelatedSlotState(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnReturnToField(System.Int32 retreatTurn, BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnReturnToFieldFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnReturnToFieldFn original_PassiveBase_OnReturnToField = nullptr;
void hooked_PassiveBase_OnReturnToField(il2cpp::Il2CppObject* __this, int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing);

// C#: System.Void OnReturnToFieldOtherUnit(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnReturnToFieldOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnReturnToFieldOtherUnitFn original_PassiveBase_OnReturnToFieldOtherUnit = nullptr;
void hooked_PassiveBase_OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing);

// C#: System.Void OnReturnToFieldOtherUnit_DeadOrRetreated(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnReturnToFieldOtherUnit_DeadOrRetreatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnReturnToFieldOtherUnit_DeadOrRetreatedFn original_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated = nullptr;
void hooked_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing);

// C#: System.Void OnReleaseStandByOtherUnit_DeadOrRetreated(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
using PassiveBaseOnReleaseStandByOtherUnit_DeadOrRetreatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnReleaseStandByOtherUnit_DeadOrRetreatedFn original_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated = nullptr;
void hooked_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList);

// C#: System.Void OnReleaseStandByOtherUnit(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
using PassiveBaseOnReleaseStandByOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnReleaseStandByOtherUnitFn original_PassiveBase_OnReleaseStandByOtherUnit = nullptr;
void hooked_PassiveBase_OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList);

// C#: System.Void OnReleaseStandBy(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnReleaseStandByFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnReleaseStandByFn original_PassiveBase_OnReleaseStandBy = nullptr;
void hooked_PassiveBase_OnReleaseStandBy(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnCompleteCommandFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnCompleteCommandFn original_PassiveBase_OnCompleteCommand = nullptr;
void hooked_PassiveBase_OnCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Boolean BeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
using PassiveBaseBeforeCompleteCommandFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t*);
inline PassiveBaseBeforeCompleteCommandFn original_PassiveBase_BeforeCompleteCommand = nullptr;
bool hooked_PassiveBase_BeforeCompleteCommand(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID);

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnChangeSkillBeforeCompleteCommandFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnChangeSkillBeforeCompleteCommandFn original_PassiveBase_OnChangeSkillBeforeCompleteCommand = nullptr;
void hooked_PassiveBase_OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRoundEndFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRoundEndFn original_PassiveBase_OnRoundEnd = nullptr;
void hooked_PassiveBase_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnRoundEnd_Disappeared(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRoundEnd_DisappearedFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRoundEnd_DisappearedFn original_PassiveBase_OnRoundEnd_Disappeared = nullptr;
void hooked_PassiveBase_OnRoundEnd_Disappeared(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnRetreat(BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRetreatFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnRetreatFn original_PassiveBase_OnRetreat = nullptr;
void hooked_PassiveBase_OnRetreat(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing);

// C#: System.Void OnRoundEnd_After()
using PassiveBaseOnRoundEnd_AfterFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnRoundEnd_AfterFn original_PassiveBase_OnRoundEnd_After = nullptr;
void hooked_PassiveBase_OnRoundEnd_After(il2cpp::Il2CppObject* __this);

// C#: System.Void OnStageEnd()
using PassiveBaseOnStageEndFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnStageEndFn original_PassiveBase_OnStageEnd = nullptr;
void hooked_PassiveBase_OnStageEnd(il2cpp::Il2CppObject* __this);

// C#: System.Void OnBeforeDefense(BattleActionModel action)
using PassiveBaseOnBeforeDefenseFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnBeforeDefenseFn original_PassiveBase_OnBeforeDefense = nullptr;
void hooked_PassiveBase_OnBeforeDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Void OnStartRunBattle()
using PassiveBaseOnStartRunBattleFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnStartRunBattleFn original_PassiveBase_OnStartRunBattle = nullptr;
void hooked_PassiveBase_OnStartRunBattle(il2cpp::Il2CppObject* __this);

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnBattleStartFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnBattleStartFn original_PassiveBase_OnBattleStart = nullptr;
void hooked_PassiveBase_OnBattleStart(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnBattleEnd(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnBattleEndFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnBattleEndFn original_PassiveBase_OnBattleEnd = nullptr;
void hooked_PassiveBase_OnBattleEnd(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnBeforeTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnBeforeTurnFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnBeforeTurnFn original_PassiveBase_OnBeforeTurn = nullptr;
void hooked_PassiveBase_OnBeforeTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnStartTurn_BeforeLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartTurn_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartTurn_BeforeLogFn original_PassiveBase_OnStartTurn_BeforeLog = nullptr;
void hooked_PassiveBase_OnStartTurn_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnStartTurn_AfterLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartTurn_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartTurn_AfterLogFn original_PassiveBase_OnStartTurn_AfterLog = nullptr;
void hooked_PassiveBase_OnStartTurn_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnStartDuel(BattleActionModel ownerAction, BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartDuelFn original_PassiveBase_OnStartDuel = nullptr;
void hooked_PassiveBase_OnStartDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing);

// C#: System.Void BeforeGiveAttackDamage(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using PassiveBaseBeforeGiveAttackDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseBeforeGiveAttackDamageFn original_PassiveBase_BeforeGiveAttackDamage = nullptr;
void hooked_PassiveBase_BeforeGiveAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Void BeforeTakeAttackDamage(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseBeforeTakeAttackDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseBeforeTakeAttackDamageFn original_PassiveBase_BeforeTakeAttackDamage = nullptr;
void hooked_PassiveBase_BeforeTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void BeforePartTakeAttackDamage(BattleUnitModel_Abnormality abnormality, BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseBeforePartTakeAttackDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseBeforePartTakeAttackDamageFn original_PassiveBase_BeforePartTakeAttackDamage = nullptr;
void hooked_PassiveBase_BeforePartTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnTakeAttackDamage(BattleActionModel action, CoinModel coin, System.Int32 totalDmg, System.Int32 hpDmg, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnTakeAttackDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnTakeAttackDamageFn original_PassiveBase_OnTakeAttackDamage = nullptr;
void hooked_PassiveBase_OnTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing);

// C#: System.Void OnTakeAttackDamagePart(BattleUnitModel_Abnormality_Part part, BattleActionModel attackerAction, CoinModel coin, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
using PassiveBaseOnTakeAttackDamagePartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool);
inline PassiveBaseOnTakeAttackDamagePartFn original_PassiveBase_OnTakeAttackDamagePart = nullptr;
void hooked_PassiveBase_OnTakeAttackDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical);

// C#: System.Void OnGiveHpDamage(BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnGiveHpDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnGiveHpDamageFn original_PassiveBase_OnGiveHpDamage = nullptr;
void hooked_PassiveBase_OnGiveHpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t value, int32_t timing);

// C#: System.Void OnGiveMpDamage(BattleUnitModel target, System.Int32 value)
using PassiveBaseOnGiveMpDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnGiveMpDamageFn original_PassiveBase_OnGiveMpDamage = nullptr;
void hooked_PassiveBase_OnGiveMpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t value);

// C#: System.Void OnTakeMpDmg_SinBuff(System.Int32 value, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnTakeMpDmg_SinBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnTakeMpDmg_SinBuffFn original_PassiveBase_OnTakeMpDmg_SinBuff = nullptr;
void hooked_PassiveBase_OnTakeMpDmg_SinBuff(il2cpp::Il2CppObject* __this, int32_t value, int32_t timing, int32_t keyword);

// C#: System.Void OnKillTarget(BattleActionModel actionOrNull, BattleUnitModel target, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnKillTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnKillTargetFn original_PassiveBase_OnKillTarget = nullptr;
void hooked_PassiveBase_OnKillTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing);

// C#: System.Void OnEndTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndTurnFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndTurnFn original_PassiveBase_OnEndTurn = nullptr;
void hooked_PassiveBase_OnEndTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnBeforeStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnBeforeStartCoinFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnBeforeStartCoinFn original_PassiveBase_OnBeforeStartCoin = nullptr;
void hooked_PassiveBase_OnBeforeStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

// C#: System.Void OnStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartCoinFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnStartCoinFn original_PassiveBase_OnStartCoin = nullptr;
void hooked_PassiveBase_OnStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

// C#: System.Void OnEndCoin_BeforeLog(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndCoin_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndCoin_BeforeLogFn original_PassiveBase_OnEndCoin_BeforeLog = nullptr;
void hooked_PassiveBase_OnEndCoin_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

// C#: System.Void OnEndCoin_AfterLog(BattleActionModel action, CoinModel coin)
using PassiveBaseOnEndCoin_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnEndCoin_AfterLogFn original_PassiveBase_OnEndCoin_AfterLog = nullptr;
void hooked_PassiveBase_OnEndCoin_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

// C#: System.Void OnEndBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnEndBehaviourFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnEndBehaviourFn original_PassiveBase_OnEndBehaviour = nullptr;
void hooked_PassiveBase_OnEndBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnEndBehave_Refresh(BattleActionModel action)
using PassiveBaseOnEndBehave_RefreshFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnEndBehave_RefreshFn original_PassiveBase_OnEndBehave_Refresh = nullptr;
void hooked_PassiveBase_OnEndBehave_Refresh(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Void OnCriticalActivated(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnCriticalActivatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnCriticalActivatedFn original_PassiveBase_OnCriticalActivated = nullptr;
void hooked_PassiveBase_OnCriticalActivated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing);

// C#: System.Void BeforeAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
using PassiveBaseBeforeAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseBeforeAttackFn original_PassiveBase_BeforeAttack = nullptr;
void hooked_PassiveBase_BeforeAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing);

// C#: System.Void OnAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAttackConfirmedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAttackConfirmedFn original_PassiveBase_OnAttackConfirmed = nullptr;
void hooked_PassiveBase_OnAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing);

// C#: System.Boolean CanTeamKill(BattleActionModel action)
using PassiveBaseCanTeamKillFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseCanTeamKillFn original_PassiveBase_CanTeamKill = nullptr;
bool hooked_PassiveBase_CanTeamKill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Collections.Generic.List<PrimeTargetData> GetPrimeTargets(BattleActionModel action)
using PassiveBaseGetPrimeTargetsFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetPrimeTargetsFn original_PassiveBase_GetPrimeTargets = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_GetPrimeTargets(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Int32 GetSkillPowerAdder(BattleActionModel action, COIN_ROLL_TYPE rollType)
using PassiveBaseGetSkillPowerAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetSkillPowerAdderFn original_PassiveBase_GetSkillPowerAdder = nullptr;
int32_t hooked_PassiveBase_GetSkillPowerAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t rollType);

// C#: System.Int32 GetExpectedSkillPowerResultAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, BattleUnitModel expectedTarget)
using PassiveBaseGetExpectedSkillPowerResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedSkillPowerResultAdderFn original_PassiveBase_GetExpectedSkillPowerResultAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget);

// C#: System.Int32 GetExpectedSkillPowerAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
using PassiveBaseGetExpectedSkillPowerAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseGetExpectedSkillPowerAdderFn original_PassiveBase_GetExpectedSkillPowerAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedSkillPowerAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

// C#: System.Boolean HasPassive(System.Int32 passiveID)
using PassiveBaseHasPassiveFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseHasPassiveFn original_PassiveBase_HasPassive = nullptr;
bool hooked_PassiveBase_HasPassive(il2cpp::Il2CppObject* __this, int32_t passiveID);

// C#: System.Void OnStartPhase(PHASE phase, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnStartPhaseFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnStartPhaseFn original_PassiveBase_OnStartPhase = nullptr;
void hooked_PassiveBase_OnStartPhase(il2cpp::Il2CppObject* __this, int32_t phase, int32_t timing);

// C#: System.Boolean HasFakeDead()
using PassiveBaseHasFakeDeadFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseHasFakeDeadFn original_PassiveBase_HasFakeDead = nullptr;
bool hooked_PassiveBase_HasFakeDead(il2cpp::Il2CppObject* __this);

// C#: System.Nullable<System.Single> OverwriteAtkResist_Default(ATK_BEHAVIOUR type)
using PassiveBaseOverwriteAtkResist_DefaultFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteAtkResist_DefaultFn original_PassiveBase_OverwriteAtkResist_Default = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResist_Default(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Nullable<System.Single> OverwriteAtkResist_Result(ATK_BEHAVIOUR type)
using PassiveBaseOverwriteAtkResist_ResultFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteAtkResist_ResultFn original_PassiveBase_OverwriteAtkResist_Result = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResist_Result(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Nullable<System.Single> OverwriteAttributeDefaultResist(ATTRIBUTE_TYPE type)
using PassiveBaseOverwriteAttributeDefaultResistFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteAttributeDefaultResistFn original_PassiveBase_OverwriteAttributeDefaultResist = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Nullable<System.Single> OverwriteAttributeResist(ATTRIBUTE_TYPE type)
using PassiveBaseOverwriteAttributeResistFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteAttributeResistFn original_PassiveBase_OverwriteAttributeResist = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAttributeResist(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Nullable<System.Int32> OverwriteMaxBuffStack(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOverwriteMaxBuffStackFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteMaxBuffStackFn original_PassiveBase_OverwriteMaxBuffStack = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteMaxBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Nullable<System.Int32> OverwriteMaxBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOverwriteMaxBuffTurnFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteMaxBuffTurnFn original_PassiveBase_OverwriteMaxBuffTurn = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteMaxBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Nullable<System.Int32> OverwriteSkillID(System.Int32 originID)
using PassiveBaseOverwriteSkillIDFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteSkillIDFn original_PassiveBase_OverwriteSkillID = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteSkillID(il2cpp::Il2CppObject* __this, int32_t originID);

// C#: System.Nullable<System.Int32> OverwriteSpeed(System.Int32 speed)
using PassiveBaseOverwriteSpeedFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteSpeedFn original_PassiveBase_OverwriteSpeed = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteSpeed(il2cpp::Il2CppObject* __this, int32_t speed);

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleUnitModel unit, BattleActionModel selfAction, BattleActionModel oppoAction)
using PassiveBaseCanChangeMainTargetRegardlessSpeedFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseCanChangeMainTargetRegardlessSpeedFn original_PassiveBase_CanChangeMainTargetRegardlessSpeed = nullptr;
bool hooked_PassiveBase_CanChangeMainTargetRegardlessSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction);

// C#: System.Void OnZeroHp()
using PassiveBaseOnZeroHpFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnZeroHpFn original_PassiveBase_OnZeroHp = nullptr;
void hooked_PassiveBase_OnZeroHp(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
using PassiveBaseGetParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseGetParryingResultAdderFn original_PassiveBase_GetParryingResultAdder = nullptr;
int32_t hooked_PassiveBase_GetParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount);

// C#: System.Int32 GetExpectedParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
using PassiveBaseGetExpectedParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetExpectedParryingResultAdderFn original_PassiveBase_GetExpectedParryingResultAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);

// C#: System.Int32 GetOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
using PassiveBaseGetOpponentParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetOpponentParryingResultAdderFn original_PassiveBase_GetOpponentParryingResultAdder = nullptr;
int32_t hooked_PassiveBase_GetOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
using PassiveBaseGetExpectedOpponentParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetExpectedOpponentParryingResultAdderFn original_PassiveBase_GetExpectedOpponentParryingResultAdder = nullptr;
int32_t hooked_PassiveBase_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

// C#: System.Void ActivateEgoPassive(System.Int32 egoId)
using PassiveBaseActivateEgoPassiveFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseActivateEgoPassiveFn original_PassiveBase_ActivateEgoPassive = nullptr;
void hooked_PassiveBase_ActivateEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId);

// C#: System.Void ActivateEquipEgoPassives()
using PassiveBaseActivateEquipEgoPassivesFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseActivateEquipEgoPassivesFn original_PassiveBase_ActivateEquipEgoPassives = nullptr;
void hooked_PassiveBase_ActivateEquipEgoPassives(il2cpp::Il2CppObject* __this);

// C#: System.Void ActivateEgoPassives(BattleEgoModel ego, System.Collections.Generic.List<System.Int32> passiveIdList, System.Boolean isEquipEgoPassive)
using PassiveBaseActivateEgoPassivesFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline PassiveBaseActivateEgoPassivesFn original_PassiveBase_ActivateEgoPassives = nullptr;
void hooked_PassiveBase_ActivateEgoPassives(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive);

// C#: System.Collections.Generic.List<BattleEgoModel> GetOwnerEgoModelList()
using PassiveBaseGetOwnerEgoModelListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetOwnerEgoModelListFn original_PassiveBase_GetOwnerEgoModelList = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_GetOwnerEgoModelList(il2cpp::Il2CppObject* __this);

// C#: BattleEgoModel FindEgoModel(System.Int32 egoId)
using PassiveBaseFindEgoModelFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseFindEgoModelFn original_PassiveBase_FindEgoModel = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_FindEgoModel(il2cpp::Il2CppObject* __this, int32_t egoId);

// C#: System.Void AddReadyEgoPassive(System.Int32 egoId)
using PassiveBaseAddReadyEgoPassiveFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseAddReadyEgoPassiveFn original_PassiveBase_AddReadyEgoPassive = nullptr;
void hooked_PassiveBase_AddReadyEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId);

// C#: System.Boolean CanAddEgoPassive(System.Int32 egoId)
using PassiveBaseCanAddEgoPassiveFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseCanAddEgoPassiveFn original_PassiveBase_CanAddEgoPassive = nullptr;
bool hooked_PassiveBase_CanAddEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId);

// C#: System.Boolean PassesCondition(PassiveStaticData passiveData, BattleEgoModel ego)
using PassiveBasePassesConditionFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBasePassesConditionFn original_PassiveBase_PassesCondition = nullptr;
bool hooked_PassiveBase_PassesCondition(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego);

// C#: System.Void OnResult_OnAction(BattleActionModel action, CoinModel coin)
using PassiveBaseOnResult_OnActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnResult_OnActionFn original_PassiveBase_OnResult_OnAction = nullptr;
void hooked_PassiveBase_OnResult_OnAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin);

// C#: System.Void OnResult_OnParrying(BattleActionModel action, BattleActionModel oppoAction, CoinModel coin)
using PassiveBaseOnResult_OnParryingFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnResult_OnParryingFn original_PassiveBase_OnResult_OnParrying = nullptr;
void hooked_PassiveBase_OnResult_OnParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin);

// C#: System.Void AddPassive(PassiveModel passiveModel)
using PassiveBaseAddPassiveFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseAddPassiveFn original_PassiveBase_AddPassive = nullptr;
void hooked_PassiveBase_AddPassive(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* passiveModel);

// C#: System.Boolean IsRegeneratable()
using PassiveBaseIsRegeneratableFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseIsRegeneratableFn original_PassiveBase_IsRegeneratable = nullptr;
bool hooked_PassiveBase_IsRegeneratable(il2cpp::Il2CppObject* __this);

// C#: System.Boolean SpreadHpDmgToAbnormality(System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseSpreadHpDmgToAbnormalityFn = bool(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseSpreadHpDmgToAbnormalityFn original_PassiveBase_SpreadHpDmgToAbnormality = nullptr;
bool hooked_PassiveBase_SpreadHpDmgToAbnormality(il2cpp::Il2CppObject* __this, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword);

// C#: System.Boolean SpreadHpDmgFromAbnormalityPart(AB_PART_TYPE partType, System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseSpreadHpDmgFromAbnormalityPartFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseSpreadHpDmgFromAbnormalityPartFn original_PassiveBase_SpreadHpDmgFromAbnormalityPart = nullptr;
bool hooked_PassiveBase_SpreadHpDmgFromAbnormalityPart(il2cpp::Il2CppObject* __this, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword);

// C#: System.Void OnSucceedEvade(BattleActionModel evadeAction, BattleActionModel attackAction, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnSucceedEvadeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnSucceedEvadeFn original_PassiveBase_OnSucceedEvade = nullptr;
void hooked_PassiveBase_OnSucceedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing);

// C#: System.Void OnGiveBuffTrigger(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnGiveBuffTriggerFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnGiveBuffTriggerFn original_PassiveBase_OnGiveBuffTrigger = nullptr;
void hooked_PassiveBase_OnGiveBuffTrigger(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing);

// C#: System.Void RightBeforeLosingBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightBeforeLosingBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseRightBeforeLosingBuffFn original_PassiveBase_RightBeforeLosingBuff = nullptr;
void hooked_PassiveBase_RightBeforeLosingBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

// C#: System.Boolean CanCreateEmptySlot()
using PassiveBaseCanCreateEmptySlotFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseCanCreateEmptySlotFn original_PassiveBase_CanCreateEmptySlot = nullptr;
bool hooked_PassiveBase_CanCreateEmptySlot(il2cpp::Il2CppObject* __this);

// C#: System.Boolean CanCreateEmptySlotPart(BattleUnitModel_Abnormality_Part part)
using PassiveBaseCanCreateEmptySlotPartFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseCanCreateEmptySlotPartFn original_PassiveBase_CanCreateEmptySlotPart = nullptr;
bool hooked_PassiveBase_CanCreateEmptySlotPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part);

// C#: System.Int32 GetActionSlotAdder()
using PassiveBaseGetActionSlotAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetActionSlotAdderFn original_PassiveBase_GetActionSlotAdder = nullptr;
int32_t hooked_PassiveBase_GetActionSlotAdder(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetMaxHpAdder()
using PassiveBaseGetMaxHpAdderFn = int32_t(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxHpAdderFn original_PassiveBase_GetMaxHpAdder = nullptr;
int32_t hooked_PassiveBase_GetMaxHpAdder(il2cpp::Il2CppObject* __this);

// C#: System.Single GetMaxHpMultiplier()
using PassiveBaseGetMaxHpMultiplierFn = float(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxHpMultiplierFn original_PassiveBase_GetMaxHpMultiplier = nullptr;
float hooked_PassiveBase_GetMaxHpMultiplier(il2cpp::Il2CppObject* __this);

// C#: System.Single GetMaxHpMultiplierPartToAbnormality()
using PassiveBaseGetMaxHpMultiplierPartToAbnormalityFn = float(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxHpMultiplierPartToAbnormalityFn original_PassiveBase_GetMaxHpMultiplierPartToAbnormality = nullptr;
float hooked_PassiveBase_GetMaxHpMultiplierPartToAbnormality(il2cpp::Il2CppObject* __this);

// C#: System.Single GetMaxHpMultiplierContributionToAbnormality()
using PassiveBaseGetMaxHpMultiplierContributionToAbnormalityFn = float(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxHpMultiplierContributionToAbnormalityFn original_PassiveBase_GetMaxHpMultiplierContributionToAbnormality = nullptr;
float hooked_PassiveBase_GetMaxHpMultiplierContributionToAbnormality(il2cpp::Il2CppObject* __this);

// C#: System.Boolean CanTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 mp, ABILITY_SOURCE_TYPE srcType)
using PassiveBaseCanTakeMpHealFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseCanTakeMpHealFn original_PassiveBase_CanTakeMpHeal = nullptr;
bool hooked_PassiveBase_CanTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType);

// C#: System.Void OnAfterTryTakeHpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAfterTryTakeHpHealFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnAfterTryTakeHpHealFn original_PassiveBase_OnAfterTryTakeHpHeal = nullptr;
void hooked_PassiveBase_OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

// C#: System.Void OnBeforeTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnBeforeTryTakeMpHealFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnBeforeTryTakeMpHealFn original_PassiveBase_OnBeforeTryTakeMpHeal = nullptr;
void hooked_PassiveBase_OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

// C#: System.Void OnAfterTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAfterTryTakeMpHealFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnAfterTryTakeMpHealFn original_PassiveBase_OnAfterTryTakeMpHeal = nullptr;
void hooked_PassiveBase_OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

// C#: System.Boolean CheckImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
using PassiveBaseCheckImmortalFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseCheckImmortalFn original_PassiveBase_CheckImmortal = nullptr;
bool hooked_PassiveBase_CheckImmortal(il2cpp::Il2CppObject* __this, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Boolean CheckImmortalOtherUnit(BattleUnitModel checkTarget, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buf)
using PassiveBaseCheckImmortalOtherUnitFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool, int32_t);
inline PassiveBaseCheckImmortalOtherUnitFn original_PassiveBase_CheckImmortalOtherUnit = nullptr;
bool hooked_PassiveBase_CheckImmortalOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf);

// C#: System.Void OnGiveImmortalState(BattleUnitModel immortalTaker, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnGiveImmortalStateFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnGiveImmortalStateFn original_PassiveBase_OnGiveImmortalState = nullptr;
void hooked_PassiveBase_OnGiveImmortalState(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalTaker, int32_t timing);

// C#: System.Void OnBeforeActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
using PassiveBaseOnBeforeActivateImmortalityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnBeforeActivateImmortalityFn original_PassiveBase_OnBeforeActivateImmortality = nullptr;
void hooked_PassiveBase_OnBeforeActivateImmortality(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
using PassiveBaseOnActivateImmortalityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnActivateImmortalityFn original_PassiveBase_OnActivateImmortality = nullptr;
void hooked_PassiveBase_OnActivateImmortality(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnActivateAbnormalityImmortality(BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
using PassiveBaseOnActivateAbnormalityImmortalityFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnActivateAbnormalityImmortalityFn original_PassiveBase_OnActivateAbnormalityImmortality = nullptr;
void hooked_PassiveBase_OnActivateAbnormalityImmortality(il2cpp::Il2CppObject* __this, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnActivateOtherUnitBurstReactive(BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnActivateOtherUnitBurstReactiveFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnActivateOtherUnitBurstReactiveFn original_PassiveBase_OnActivateOtherUnitBurstReactive = nullptr;
void hooked_PassiveBase_OnActivateOtherUnitBurstReactive(il2cpp::Il2CppObject* __this, int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing);

// C#: System.Void OnBurstReactiveActivatedAnyUnit(BattleUnitModel buffOwner, BUFF_UNIQUE_KEYWORD keyword, System.Int32 loseStack, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, BattleUnitModel giverOrNull)
using PassiveBaseOnBurstReactiveActivatedAnyUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnBurstReactiveActivatedAnyUnitFn original_PassiveBase_OnBurstReactiveActivatedAnyUnit = nullptr;
void hooked_PassiveBase_OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull);

// C#: System.Void OnAddShield(BATTLE_EVENT_TIMING timing, System.Int32 value)
using PassiveBaseOnAddShieldFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnAddShieldFn original_PassiveBase_OnAddShield = nullptr;
void hooked_PassiveBase_OnAddShield(il2cpp::Il2CppObject* __this, int32_t timing, int32_t value);

// C#: System.Void OnReduceShield(BATTLE_EVENT_TIMING timing, System.Int32 old, System.Int32 value, BattleUnitModel attackerOrNull)
using PassiveBaseOnReduceShieldFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnReduceShieldFn original_PassiveBase_OnReduceShield = nullptr;
void hooked_PassiveBase_OnReduceShield(il2cpp::Il2CppObject* __this, int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull);

// C#: System.Void OnDestroyShield(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnDestroyShieldFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnDestroyShieldFn original_PassiveBase_OnDestroyShield = nullptr;
void hooked_PassiveBase_OnDestroyShield(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnDestoryShieldPart(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull)
using PassiveBaseOnDestoryShieldPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnDestoryShieldPartFn original_PassiveBase_OnDestoryShieldPart = nullptr;
void hooked_PassiveBase_OnDestoryShieldPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull);

// C#: System.Void OnRecoverBreak(BATTLE_EVENT_TIMING timing)
using PassiveBaseOnRecoverBreakFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnRecoverBreakFn original_PassiveBase_OnRecoverBreak = nullptr;
void hooked_PassiveBase_OnRecoverBreak(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnGiveBsGaugeUp(BattleUnitModel giver, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion, ABILITY_SOURCE_TYPE abilitySrc, BattleActionModel actionOrNull)
using PassiveBaseOnGiveBsGaugeUpFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnGiveBsGaugeUpFn original_PassiveBase_OnGiveBsGaugeUp = nullptr;
void hooked_PassiveBase_OnGiveBsGaugeUp(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnTakeHpDamageFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTakeHpDamageFn original_PassiveBase_OnTakeHpDamage = nullptr;
void hooked_PassiveBase_OnTakeHpDamage(il2cpp::Il2CppObject* __this, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

// C#: System.Void OnTakeHpDamagePart(BattleUnitModel_Abnormality_Part part, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnTakeHpDamagePartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTakeHpDamagePartFn original_PassiveBase_OnTakeHpDamagePart = nullptr;
void hooked_PassiveBase_OnTakeHpDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

// C#: System.Void OnTakeHpDamageOtherUnit(BattleUnitModel damaged, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, System.Collections.Generic.List<BattleUnitModel> relatedUnitsOrNull, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnTakeHpDamageOtherUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTakeHpDamageOtherUnitFn original_PassiveBase_OnTakeHpDamageOtherUnit = nullptr;
void hooked_PassiveBase_OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword);

// C#: System.Void OnTryTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BattleActionModel actionOrNull, BattleUnitModel attackerOrNull, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnTryTakeHpDamageFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTryTakeHpDamageFn original_PassiveBase_OnTryTakeHpDamage = nullptr;
void hooked_PassiveBase_OnTryTakeHpDamage(il2cpp::Il2CppObject* __this, int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing);

// C#: System.Single GetTakeHpHealMultiplier(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
using PassiveBaseGetTakeHpHealMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetTakeHpHealMultiplierFn original_PassiveBase_GetTakeHpHealMultiplier = nullptr;
float hooked_PassiveBase_GetTakeHpHealMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

// C#: System.Void OnTakeAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel attacker, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnTakeAttackConfirmedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnTakeAttackConfirmedFn original_PassiveBase_OnTakeAttackConfirmed = nullptr;
void hooked_PassiveBase_OnTakeAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing);

// C#: System.Int32 GetMaxHpAdderPart(BattleUnitModel_Abnormality_Part part)
using PassiveBaseGetMaxHpAdderPartFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetMaxHpAdderPartFn original_PassiveBase_GetMaxHpAdderPart = nullptr;
int32_t hooked_PassiveBase_GetMaxHpAdderPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part);

// C#: System.Single GetTakeHpHealMultiplierPart(BattleUnitModel_Abnormality_Part part, BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
using PassiveBaseGetTakeHpHealMultiplierPartFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetTakeHpHealMultiplierPartFn original_PassiveBase_GetTakeHpHealMultiplierPart = nullptr;
float hooked_PassiveBase_GetTakeHpHealMultiplierPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

// C#: System.Int32 GetTakeHpHealAdder(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
using PassiveBaseGetTakeHpHealAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseGetTakeHpHealAdderFn original_PassiveBase_GetTakeHpHealAdder = nullptr;
int32_t hooked_PassiveBase_GetTakeHpHealAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t srcType);

// C#: System.Void OverwriteTargetableList(System.Collections.Generic.List<SinActionModel> targetableSlotListOrNull, System.Collections.Generic.List<BattleUnitModel> origianlTargetList)
using PassiveBaseOverwriteTargetableListFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOverwriteTargetableListFn original_PassiveBase_OverwriteTargetableList = nullptr;
void hooked_PassiveBase_OverwriteTargetableList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList);

// C#: System.Nullable<System.Single> OverwriteAtkResistWhenDestroyed(ATK_BEHAVIOUR type)
using PassiveBaseOverwriteAtkResistWhenDestroyedFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOverwriteAtkResistWhenDestroyedFn original_PassiveBase_OverwriteAtkResistWhenDestroyed = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Void OnChangeHp(System.Int32 oldHp, System.Int32 newHp, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseOnChangeHpFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnChangeHpFn original_PassiveBase_OnChangeHp = nullptr;
void hooked_PassiveBase_OnChangeHp(il2cpp::Il2CppObject* __this, int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword);

// C#: System.Void OnChangeMp(System.Int32 oldMp, System.Int32 newMp)
using PassiveBaseOnChangeMpFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnChangeMpFn original_PassiveBase_OnChangeMp = nullptr;
void hooked_PassiveBase_OnChangeMp(il2cpp::Il2CppObject* __this, int32_t oldMp, int32_t newMp);

// C#: System.Void OnChangeMpOther(BattleUnitModel mpChangeUnit, System.Int32 oldMp, System.Int32 newMp)
using PassiveBaseOnChangeMpOtherFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseOnChangeMpOtherFn original_PassiveBase_OnChangeMpOther = nullptr;
void hooked_PassiveBase_OnChangeMpOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp);

// C#: System.Void OnTakeMpDamage(BattleUnitModel attacker, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleActionModel actionOrNull)
using PassiveBaseOnTakeMpDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnTakeMpDamageFn original_PassiveBase_OnTakeMpDamage = nullptr;
void hooked_PassiveBase_OnTakeMpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnTakeMpDamageOther(BattleUnitModel mpDmgUnit, BattleUnitModel attackerOrNull, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BUFF_UNIQUE_KEYWORD buffKeyword, BattleActionModel actionOrNull)
using PassiveBaseOnTakeMpDamageOtherFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnTakeMpDamageOtherFn original_PassiveBase_OnTakeMpDamageOther = nullptr;
void hooked_PassiveBase_OnTakeMpDamageOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnAfterTryTakeMpHealOther(BattleUnitModel mpHealUnit, BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAfterTryTakeMpHealOtherFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnAfterTryTakeMpHealOtherFn original_PassiveBase_OnAfterTryTakeMpHealOther = nullptr;
void hooked_PassiveBase_OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing);

// C#: System.Void UnlockAllPassives()
using PassiveBaseUnlockAllPassivesFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseUnlockAllPassivesFn original_PassiveBase_UnlockAllPassives = nullptr;
void hooked_PassiveBase_UnlockAllPassives(il2cpp::Il2CppObject* __this);

// C#: System.Void OnUseBuffTurnBySkill(SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 turn, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnUseBuffTurnBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline PassiveBaseOnUseBuffTurnBySkillFn original_PassiveBase_OnUseBuffTurnBySkill = nullptr;
void hooked_PassiveBase_OnUseBuffTurnBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing);

// C#: System.Void OnUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnUseBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnUseBuffFn original_PassiveBase_OnUseBuff = nullptr;
void hooked_PassiveBase_OnUseBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

// C#: System.Void BeforeUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
using PassiveBaseBeforeUseBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseBeforeUseBuffFn original_PassiveBase_BeforeUseBuff = nullptr;
void hooked_PassiveBase_BeforeUseBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

// C#: System.Single GetCoinProbAdder()
using PassiveBaseGetCoinProbAdderFn = float(*)(il2cpp::Il2CppObject*);
inline PassiveBaseGetCoinProbAdderFn original_PassiveBase_GetCoinProbAdder = nullptr;
float hooked_PassiveBase_GetCoinProbAdder(il2cpp::Il2CppObject* __this);

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, System.Single& prob)
using PassiveBaseOverwriteCoinProbFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, float*);
inline PassiveBaseOverwriteCoinProbFn original_PassiveBase_OverwriteCoinProb = nullptr;
bool hooked_PassiveBase_OverwriteCoinProb(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob);

// C#: System.Boolean IsEgoSkillFree(BattleEgoModel ego)
using PassiveBaseIsEgoSkillFreeFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseIsEgoSkillFreeFn original_PassiveBase_IsEgoSkillFree = nullptr;
bool hooked_PassiveBase_IsEgoSkillFree(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ego);

// C#: System.Void OnPickSkills()
using PassiveBaseOnPickSkillsFn = void(*)(il2cpp::Il2CppObject*);
inline PassiveBaseOnPickSkillsFn original_PassiveBase_OnPickSkills = nullptr;
void hooked_PassiveBase_OnPickSkills(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAddActionToPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action)
using PassiveBaseOnAddActionToPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnAddActionToPartFn original_PassiveBase_OnAddActionToPart = nullptr;
void hooked_PassiveBase_OnAddActionToPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action);

// C#: System.Void OnAddCoinByAbility(BattleActionModel action, CoinModel newCoin, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnAddCoinByAbilityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnAddCoinByAbilityFn original_PassiveBase_OnAddCoinByAbility = nullptr;
void hooked_PassiveBase_OnAddCoinByAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing);

// C#: System.Boolean CanOverwritePanicType()
using PassiveBaseCanOverwritePanicTypeFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseCanOverwritePanicTypeFn original_PassiveBase_CanOverwritePanicType = nullptr;
bool hooked_PassiveBase_CanOverwritePanicType(il2cpp::Il2CppObject* __this);

// C#: System.Single GetCriticalChanceAdder(System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
using PassiveBaseGetCriticalChanceAdderFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetCriticalChanceAdderFn original_PassiveBase_GetCriticalChanceAdder = nullptr;
float hooked_PassiveBase_GetCriticalChanceAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* affectKeywords);

// C#: System.Single GetCriticalDamageRatioResultMultiplier(BattleActionModel action)
using PassiveBaseGetCriticalDamageRatioResultMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseGetCriticalDamageRatioResultMultiplierFn original_PassiveBase_GetCriticalDamageRatioResultMultiplier = nullptr;
float hooked_PassiveBase_GetCriticalDamageRatioResultMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Void RightAfterDestroyAnyBuff(BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
using PassiveBaseRightAfterDestroyAnyBuffFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseRightAfterDestroyAnyBuffFn original_PassiveBase_RightAfterDestroyAnyBuff = nullptr;
void hooked_PassiveBase_RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing);

// C#: System.Boolean IsAbnormalityImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
using PassiveBaseIsAbnormalityImmortalFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseIsAbnormalityImmortalFn original_PassiveBase_IsAbnormalityImmortal = nullptr;
bool hooked_PassiveBase_IsAbnormalityImmortal(il2cpp::Il2CppObject* __this, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Boolean CheckIfTurnToCorpesOnDie()
using PassiveBaseCheckIfTurnToCorpesOnDieFn = bool(*)(il2cpp::Il2CppObject*);
inline PassiveBaseCheckIfTurnToCorpesOnDieFn original_PassiveBase_CheckIfTurnToCorpesOnDie = nullptr;
bool hooked_PassiveBase_CheckIfTurnToCorpesOnDie(il2cpp::Il2CppObject* __this);

// C#: System.Void OnCanceledByLackOfBuffsAtStartCoin(BattleActionModel action, CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD> lackOfBuffs, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnCanceledByLackOfBuffsAtStartCoinFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseOnCanceledByLackOfBuffsAtStartCoinFn original_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin = nullptr;
void hooked_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing);

// C#: System.Void CheckOverwriteGettingBuff(ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BUFF_UNIQUE_KEYWORD& keyword, System.Int32& stack, System.Int32& turn, System.Int32& activeRound)
using PassiveBaseCheckOverwriteGettingBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t*, int32_t*, int32_t*, int32_t*);
inline PassiveBaseCheckOverwriteGettingBuffFn original_PassiveBase_CheckOverwriteGettingBuff = nullptr;
void hooked_PassiveBase_CheckOverwriteGettingBuff(il2cpp::Il2CppObject* __this, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound);

// C#: System.Boolean IsAllowedToGiveBuff(BUFF_UNIQUE_KEYWORD keyword)
using PassiveBaseIsAllowedToGiveBuffFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline PassiveBaseIsAllowedToGiveBuffFn original_PassiveBase_IsAllowedToGiveBuff = nullptr;
bool hooked_PassiveBase_IsAllowedToGiveBuff(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Void OnFailedToGetBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel giverActionOrNull)
using PassiveBaseOnFailedToGetBuffFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnFailedToGetBuffFn original_PassiveBase_OnFailedToGetBuff = nullptr;
void hooked_PassiveBase_OnFailedToGetBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull);

// C#: System.Void RightAfterFailingGetAnyBuff(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
using PassiveBaseRightAfterFailingGetAnyBuffFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseRightAfterFailingGetAnyBuffFn original_PassiveBase_RightAfterFailingGetAnyBuff = nullptr;
void hooked_PassiveBase_RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn);

// C#: System.Void OnFailedToGiveBuff(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
using PassiveBaseOnFailedToGiveBuffFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOnFailedToGiveBuffFn original_PassiveBase_OnFailedToGiveBuff = nullptr;
void hooked_PassiveBase_OnFailedToGiveBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull);

// C#: System.Void OnUseCoinConsume(BattleUnitModel owner, BattleActionModel action, CoinModel coin, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
using PassiveBaseOnUseCoinConsumeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline PassiveBaseOnUseCoinConsumeFn original_PassiveBase_OnUseCoinConsume = nullptr;
void hooked_PassiveBase_OnUseCoinConsume(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing);

// C#: System.Boolean BlockGivingBuff(BattleActionModel action, BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
using PassiveBaseBlockGivingBuffFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseBlockGivingBuffFn original_PassiveBase_BlockGivingBuff = nullptr;
bool hooked_PassiveBase_BlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

// C#: System.Nullable<System.Int32> OverwritePartSpeed(System.Int32 speed, BattleUnitModel_Abnormality_Part part)
using PassiveBaseOverwritePartSpeedFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseOverwritePartSpeedFn original_PassiveBase_OverwritePartSpeed = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwritePartSpeed(il2cpp::Il2CppObject* __this, int32_t speed, il2cpp::Il2CppObject* part);

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel unit, BattleUnitModel target, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Boolean> isCritical)
using PassiveBaseBlockLoseBuffByReactWithActionFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline PassiveBaseBlockLoseBuffByReactWithActionFn original_PassiveBase_BlockLoseBuffByReactWithAction = nullptr;
bool hooked_PassiveBase_BlockLoseBuffByReactWithAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical);

// C#: System.Boolean BlockLoseBuffStack(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseBlockLoseBuffStackFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseBlockLoseBuffStackFn original_PassiveBase_BlockLoseBuffStack = nullptr;
bool hooked_PassiveBase_BlockLoseBuffStack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing);

// C#: System.Boolean BlockLoseBuffTurn(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
using PassiveBaseBlockLoseBuffTurnFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline PassiveBaseBlockLoseBuffTurnFn original_PassiveBase_BlockLoseBuffTurn = nullptr;
bool hooked_PassiveBase_BlockLoseBuffTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing);

// C#: System.Boolean IsBlockingSinkingBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerAction, CoinModel attackerCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using PassiveBaseIsBlockingSinkingBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline PassiveBaseIsBlockingSinkingBuffEffectReactFn original_PassiveBase_IsBlockingSinkingBuffEffectReact = nullptr;
bool hooked_PassiveBase_IsBlockingSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing);

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using PassiveBaseIsBlockingTargetSinkingBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline PassiveBaseIsBlockingTargetSinkingBuffEffectReactFn original_PassiveBase_IsBlockingTargetSinkingBuffEffectReact = nullptr;
bool hooked_PassiveBase_IsBlockingTargetSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

// C#: System.Nullable<System.Boolean> OverwriteCanDuel(BattleActionModel selfAction, BattleActionModel opponentAction)
using PassiveBaseOverwriteCanDuelFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOverwriteCanDuelFn original_PassiveBase_OverwriteCanDuel = nullptr;
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteCanDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction);

// C#: System.Boolean IsBlockingBurstBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using PassiveBaseIsBlockingBurstBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline PassiveBaseIsBlockingBurstBuffEffectReactFn original_PassiveBase_IsBlockingBurstBuffEffectReact = nullptr;
bool hooked_PassiveBase_IsBlockingBurstBuffEffectReact(il2cpp::Il2CppObject* __this, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing);

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using PassiveBaseIsBlockingTargetBurstBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline PassiveBaseIsBlockingTargetBurstBuffEffectReactFn original_PassiveBase_IsBlockingTargetBurstBuffEffectReact = nullptr;
bool hooked_PassiveBase_IsBlockingTargetBurstBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

// C#: System.Boolean ModifyMpChangeValue(System.Int32 oldMp, System.Int32 newMp, System.Int32& changedNewMp)
using PassiveBaseModifyMpChangeValueFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t*);
inline PassiveBaseModifyMpChangeValueFn original_PassiveBase_ModifyMpChangeValue = nullptr;
bool hooked_PassiveBase_ModifyMpChangeValue(il2cpp::Il2CppObject* __this, int32_t oldMp, int32_t newMp, int32_t* changedNewMp);

// C#: System.Void OnAddBattleAction(SinActionModel actorAction, SinActionModel targetAction)
using PassiveBaseOnAddBattleActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnAddBattleActionFn original_PassiveBase_OnAddBattleAction = nullptr;
void hooked_PassiveBase_OnAddBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction);

// C#: System.Void OnRemoveBattleAction(SinActionModel actorAction)
using PassiveBaseOnRemoveBattleActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseOnRemoveBattleActionFn original_PassiveBase_OnRemoveBattleAction = nullptr;
void hooked_PassiveBase_OnRemoveBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actorAction);

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel thisAction, BattleActionModel mainAction, BattleActionModel oppoActionOrNull)
using PassiveBaseIsRunUniqueActionFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBaseIsRunUniqueActionFn original_PassiveBase_IsRunUniqueAction = nullptr;
bool hooked_PassiveBase_IsRunUniqueAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull);

// C#: System.Void .ctor(BattleUnitModel model, UnitDataModel rawDataModel)
using PassiveBasectorFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline PassiveBasectorFn original_PassiveBase_ctor = nullptr;
void hooked_PassiveBase_ctor(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* model, il2cpp::Il2CppObject* rawDataModel);


// System.Int32 GetExpectedParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult) {}//

using BattleActionModelGetExpectedParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetExpectedParryingResultAdderFn original_BattleActionModel_GetExpectedParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);

// System.Int32 GetExpectedOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult) {}//
using BattleActionModelGetExpectedOpponentParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetExpectedOpponentParryingResultAdderFn original_BattleActionModel_GetExpectedOpponentParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);


// System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin) {}//
// System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, COIN_ROLL_TYPE rollType, SinActionModel targetSinActionOrNull) {}//
} // myosotis::testmod
