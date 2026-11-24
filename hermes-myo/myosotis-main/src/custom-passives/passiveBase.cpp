#include <iostream>
#include <unordered_map>
#include "il2cpp.hpp"
#include "passiveBase.hpp"
#include "hermesUtils.hpp"
#include "hook.hpp"
#include "custom-passives/moPassives.hpp"

namespace myosotis::testmod {

// =============================================================================
// PassiveBase default behaviour: void -> do nothing, non-void -> return returnValue untouched.
// =============================================================================

// C#: System.Void OnStartBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartBehaviour(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnSucceedAttack(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnSucceedAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {}

// C#: System.Void OnRollOneCoin_AfterAttack(BattleActionModel action, CoinModel coin)
void PassiveBase::OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {}

// C#: System.Void OnEndAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndAttack(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnEndAttackOtherUnit(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndAttackOtherUnit(il2cpp::Il2CppObject* attackerAction, int32_t timing) {}

// C#: System.Void OnStartEnemyAttack(BattleUnitModel unit, BattleActionModel opponentAction, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartEnemyAttack(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {}

// C#: System.Void OnEndEnemyAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndEnemyAttack(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnEndAttackPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndAttackPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnDuelAfter_BeforeLog(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {}

// C#: System.Void OnAfterParryingOnce_BeforeLog(PARRYING_RESULT result, BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAfterParryingOnce_BeforeLog(int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing) {}

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {}

// C#: System.Void OnWinParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnWinParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {}

// C#: System.Void OnLoseParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnLoseParrying(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {}

// C#: System.Void OnWinDuel(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnWinDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {}

// C#: System.Void OnLoseDuel(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnLoseDuel(il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {}

// C#: System.Void OnLoseDuelOtherUnit(BattleActionModel loserAction, BattleActionModel winnerAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnLoseDuelOtherUnit(il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing) {}

// C#: System.Void RightBeforeGiveBuffBySkill(SkillModel skill, CoinModel coinOrNull, BUFF_UNIQUE_KEYWORD buf, System.Int32 stack, System.Int32 turn, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void PassiveBase::RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {}

// C#: System.Void RightAfterGiveBuffBySkill(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void PassiveBase::RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {}

// C#: System.Void RightAfterTakeBuffBySkill(BattleUnitModel unit, BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, BattleUnitModel giver, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, System.Int32 afterAdderStack, System.Int32 afterAdderTurn)
void PassiveBase::RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn) {}

// C#: System.Void RightBeforeOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {}

// C#: System.Void RightAfterOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {}

// C#: System.Void RightAfterAnyUnitGetAnyBuff(BattleUnitModel receiver, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, BattleUnitModel giverOrNull, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, System.Int32 overStack, System.Int32 overTurn)
void PassiveBase::RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn) {}

// C#: System.Void RightAfterLosingBuff(System.Int32 loseStack, System.Int32 loseTurn, BuffInfo loseBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightAfterLosingBuff(int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing) {}

// C#: System.Void OnSucceedToGiveSwitchToSpecialVibration(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 prevStack, System.Int32 prevTurn, System.Int32 afterStack, System.Int32 afterTurn, System.Boolean isPileUp, BATTLE_EVENT_TIMING timing, ABILITY_SOURCE_TYPE abilitySourceType)
void PassiveBase::OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType) {}

// C#: System.Void RightAfterGetAnyBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void PassiveBase::RightAfterGetAnyBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {}

// C#: System.Void RightAfterGetAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull)
void PassiveBase::RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void RightAfterDestroyAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {}

// C#: System.Int32 GetAggroAdder(SinActionModel sinaction)
int32_t PassiveBase::GetAggroAdder(int32_t returnValue, il2cpp::Il2CppObject* sinaction) { return returnValue; }

// C#: System.Int32 GetAttackWeightAdder(BattleActionModel action)
int32_t PassiveBase::GetAttackWeightAdder(int32_t returnValue, il2cpp::Il2CppObject* action) { return returnValue; }

// C#: System.Int32 GetMentalSystemResultIncreaseAdder()
int32_t PassiveBase::GetMentalSystemResultIncreaseAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetMentalSystemResultDecreaseAdder()
int32_t PassiveBase::GetMentalSystemResultDecreaseAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetInitBuffMaxStackAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveBase::GetInitBuffMaxStackAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetInitBuffMaxTurnAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveBase::GetInitBuffMaxTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* unit, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetTakeBuffTurnAdderOtherUnit(BattleUnitModel taker, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::GetTakeBuffTurnAdderOtherUnit(int32_t returnValue, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing) { return returnValue; }

// C#: System.Int32 GetTakeBuffStackAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originStack, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::GetTakeBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing) { return returnValue; }

// C#: System.Int32 GetTakeBuffTurnAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::GetTakeBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing) { return returnValue; }

// C#: System.Int32 GetGiveBuffTurnAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::GetGiveBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing) { return returnValue; }

// C#: System.Int32 GetGiveBuffStackAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
int32_t PassiveBase::GetGiveBuffStackAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Int32 GetUseBuffTurnAdder(BattleActionModel action, SkillModel skill, System.Int32 turn, BUFF_UNIQUE_KEYWORD buf)
int32_t PassiveBase::GetUseBuffTurnAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf) { return returnValue; }

// C#: System.Single GetTakeBuffStackMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float PassiveBase::GetTakeBuffStackMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) { return returnValue; }

// C#: System.Single GetTakeBuffTurnMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float PassiveBase::GetTakeBuffTurnMultiplier(float returnValue, il2cpp::Il2CppObject* skill, int32_t buf) { return returnValue; }

// C#: System.Void OnActivateSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 takeDmg, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced, System.Nullable<System.Boolean> isCritical)
void PassiveBase::OnActivateSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical) {}

// C#: System.Void OnActivateOtherUnitSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, System.Int32 takeDmg, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced)
void PassiveBase::OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced) {}

// C#: System.Boolean IgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IgnoreSinBuffHpDamage(bool returnValue, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) { return returnValue; }

// C#: System.Boolean IgnoreSinBuffHpDamagePart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IgnoreSinBuffHpDamagePart(bool returnValue, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) { return returnValue; }

// C#: System.Void OnIgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnIgnoreSinBuffHpDamage(int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {}

// C#: System.Int32 GetSinBuffDamageAdder(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg)
int32_t PassiveBase::GetSinBuffDamageAdder(int32_t returnValue, int32_t keyword, int32_t dmg) { return returnValue; }

// C#: System.Single GetSinBuffDamageMultiplier(BUFF_UNIQUE_KEYWORD keyword)
float PassiveBase::GetSinBuffDamageMultiplier(float returnValue, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetMaxBuffStackAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveBase::GetMaxBuffStackAdder(int32_t returnValue, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetMaxBuffTurnAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t PassiveBase::GetMaxBuffTurnAdder(int32_t returnValue, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetUnitStatLevelAdder()
int32_t PassiveBase::GetUnitStatLevelAdder(int32_t returnValue) { return returnValue; }

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull, BattleUnitModel target)
float PassiveBase::GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Single GetTakeBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull)
float PassiveBase::GetTakeBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull) { return returnValue; }

// C#: System.Int32 GetSkillPoolCountAdder(System.Int32 index, UnitAttribute attribute)
int32_t PassiveBase::GetSkillPoolCountAdder(int32_t returnValue, int32_t index, il2cpp::Il2CppObject* attribute) { return returnValue; }

// C#: System.Void OnDestroy(BattleUnitModel destroyerOrNull, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDestroy(il2cpp::Il2CppObject* destroyerOrNull, int32_t timing) {}

// C#: System.Void OnOtherPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart)
void PassiveBase::OnOtherPartDestroyed(il2cpp::Il2CppObject* destroyedPart) {}

// C#: System.Void OnPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnPartDestroyed(il2cpp::Il2CppObject* destroyedPart, int32_t timing) {}

// C#: System.Void OnPartBreaked(BattleUnitModel_Abnormality_Part breakedPart, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnPartBreaked(il2cpp::Il2CppObject* breakedPart, int32_t timing) {}

// C#: System.Void OnPartRecoverBreak(BattleUnitModel_Abnormality_Part recoveredPart, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnPartRecoverBreak(il2cpp::Il2CppObject* recoveredPart, int32_t timing) {}

// C#: System.Void OnRegenerate(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRegenerate(int32_t timing) {}

// C#: System.Void OnPartRegenerate(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnPartRegenerate(il2cpp::Il2CppObject* part, int32_t timing) {}

// C#: System.Boolean CheckUnitGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveBase::CheckUnitGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Boolean CheckUnitGivingBuffKeyword(BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveBase::CheckUnitGivingBuffKeyword(bool returnValue, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Boolean CheckSkillGivingBuffCategory(BattleActionModel action, BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveBase::CheckSkillGivingBuffCategory(bool returnValue, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Boolean CheckSkillGivingBuff(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool PassiveBase::CheckSkillGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Void CheckLoseBuffStackAndTurn(BuffInfo info, System.Int32& loseStack, System.Int32& loseTurn, BATTLE_EVENT_TIMING timing)
void PassiveBase::CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing) {}

// C#: System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin)
int32_t PassiveBase::GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin) { return returnValue; }

// C#: System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, SinActionModel expectedTargetSinActionOrNull)
int32_t PassiveBase::GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetSkillPowerResultAdder(BattleActionModel action, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::GetSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t timing) { return returnValue; }

// C#: System.Int32 GetTakeHpDmgAdder()
int32_t PassiveBase::GetTakeHpDmgAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetExpectedTakeHpDmgAdder()
int32_t PassiveBase::GetExpectedTakeHpDmgAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetMinSpeedAdder()
int32_t PassiveBase::GetMinSpeedAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetMaxSpeedAdder()
int32_t PassiveBase::GetMaxSpeedAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetSpeedAdder()
int32_t PassiveBase::GetSpeedAdder(int32_t returnValue) { return returnValue; }

// C#: System.Boolean UseOnlyDefaultMinSpeed()
bool PassiveBase::UseOnlyDefaultMinSpeed(bool returnValue) { return returnValue; }

// C#: System.Boolean UseOnlyDefaultMaxSpeed()
bool PassiveBase::UseOnlyDefaultMaxSpeed(bool returnValue) { return returnValue; }

// C#: System.Int32 ChangeAttackDamage(BattleActionModel action, BattleUnitModel target, CoinModel coin, System.Int32 resultDmg, System.Boolean& isCritical, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged)
int32_t PassiveBase::ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged) { return returnValue; }

// C#: System.Int32 ChangeTakeDamage(BattleActionModel action, CoinModel coinOrNull, System.Int32 resultDmg, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged, System.Int32 preCalculatedDmg)
int32_t PassiveBase::ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg) { return returnValue; }

// C#: System.Int32 ChangeMpDamage(System.Int32 resultDmg, BattleActionModel actionOrNull, BASE_MENTAL_CONDITION mentalConditionOrNone, BUFF_UNIQUE_KEYWORD keywordOrNone, AbilityBase abilityOrNull, System.Boolean& isChanged, BATTLE_EVENT_TIMING timing)
int32_t PassiveBase::ChangeMpDamage(int32_t returnValue, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing) { return returnValue; }

// C#: System.Int32 GetAttackHpDmgAdder(BattleUnitModel target)
int32_t PassiveBase::GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Int32 GetExpectedAttackHpDmgAdder(BattleUnitModel target)
int32_t PassiveBase::GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Int32 GetAttackDmgAdder(BattleActionModel action, BattleUnitModel target)
int32_t PassiveBase::GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Int32 GetExpectedAttackDmgAdder(BattleActionModel action, BattleUnitModel targetOrNull)
int32_t PassiveBase::GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull) { return returnValue; }

// C#: System.Single GetAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical)
float PassiveBase::GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical) { return returnValue; }

// C#: System.Single GetExpectedAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
float PassiveBase::GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t PassiveBase::GetTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) { return returnValue; }

// C#: System.Int32 GetExpectedTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t PassiveBase::GetExpectedTakeAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) { return returnValue; }

// C#: System.Single GetTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker, System.Boolean isCritical)
float PassiveBase::GetTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical) { return returnValue; }

// C#: System.Single GetExpectedTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker)
float PassiveBase::GetExpectedTakeAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) { return returnValue; }

// C#: System.Int32 GetAttackAdder(BattleActionModel actionOrNull)
int32_t PassiveBase::GetAttackAdder(int32_t returnValue, il2cpp::Il2CppObject* actionOrNull) { return returnValue; }

// C#: System.Int32 GetUnitDefaultLevelAdder()
int32_t PassiveBase::GetUnitDefaultLevelAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetDefenseAdder()
int32_t PassiveBase::GetDefenseAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetUnitDefenseAdder()
int32_t PassiveBase::GetUnitDefenseAdder(int32_t returnValue) { return returnValue; }

// C#: System.Single GetDefenseMultiplier()
float PassiveBase::GetDefenseMultiplier(float returnValue) { return returnValue; }

// C#: System.Single GetHpHealMultiplier(BattleUnitModel target)
float PassiveBase::GetHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Single GetAtkResistMultiplier(ATK_BEHAVIOUR type)
float PassiveBase::GetAtkResistMultiplier(float returnValue, int32_t type) { return returnValue; }

// C#: System.Single GetAtkResistAdder(ATK_BEHAVIOUR type)
float PassiveBase::GetAtkResistAdder(float returnValue, int32_t type) { return returnValue; }

// C#: System.Single GetAttributeResistMultiplier(ATTRIBUTE_TYPE type)
float PassiveBase::GetAttributeResistMultiplier(float returnValue, int32_t type) { return returnValue; }

// C#: System.Single GetAttributeResistAdder(ATTRIBUTE_TYPE type)
float PassiveBase::GetAttributeResistAdder(float returnValue, int32_t type) { return returnValue; }

// C#: System.Void OnDie(BattleUnitModel killer, BattleActionModel actionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDie(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing) {}

// C#: System.Void OnBreak(BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void PassiveBase::OnBreak(il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely) {}

// C#: System.Void OnEnemyBrokenByAttacker(BattleActionModel actionOrNull, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing) {}

// C#: System.Void OnDieOtherUnit(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnDieOtherUnit(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {}

// C#: System.Void OnDieOtherUnit_Retreated(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {}

// C#: System.Void OnDieOtherUnit_Disappeared(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {}

// C#: System.Void OnRetreatOtherUnit(BattleUnitModel retreatUnit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRetreatOtherUnit(il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing) {}

// C#: System.Void OnRetreatOtherUnit_Retreated(BattleUnitModel retreatUnit, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* retreatUnit, int32_t timing) {}

// C#: System.Void OnDiscardSinOtherUnit(BattleUnitModel discardUnit, UnitSinModel sin, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveBase::OnDiscardSinOtherUnit(il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnDiscardSin(UnitSinModel sin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDiscardSin(il2cpp::Il2CppObject* sin, int32_t timing) {}

// C#: System.Void OnDisappeared(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDisappeared(int32_t timing) {}

// C#: System.Void OnReturnFromDisappeared(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnReturnFromDisappeared(int32_t timing) {}

// C#: System.Void OnBreakOtherUnit(BattleUnitModel breakedUnit, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void PassiveBase::OnBreakOtherUnit(il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely) {}

// C#: System.Void OnCheckBreak(System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void PassiveBase::OnCheckBreak(il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {}

// C#: System.Void OnCheckPartBreak(BattleUnitModel_Abnormality_Part breakedPart, System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void PassiveBase::OnCheckPartBreak(il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {}

// C#: System.Void OnVibrationExplosion(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnVibrationExplosion(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {}

// C#: System.Void OnVibrationExplosionOtherUnit(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {}

// C#: System.Void OnTakeAttackDamageOtherUnit(BattleActionModel action, System.Int32 realDmg, System.Int32 hpDmg, BattleUnitModel attackedUnit, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing) {}

// C#: System.Void OnUseBuffStackBySkill(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnUseBuffStackBySkill(il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing) {}

// C#: System.Void OnUseBloodDinnerUnit(BattleUnitModel usedUnit, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnUseBloodDinnerUnit(il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing) {}

// C#: System.Void OnAddUnit(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAddUnit(int32_t timing) {}

// C#: System.Void OnAddUnit_After(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAddUnit_After(int32_t timing) {}

// C#: System.Void OnAddUnitPart(BattleUnitModel part, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAddUnitPart(il2cpp::Il2CppObject* part, int32_t timing) {}

// C#: System.Void Init_After()
void PassiveBase::Init_After() {}

// C#: System.Void OnAddUnitView(BattleUnitView view)
void PassiveBase::OnAddUnitView(il2cpp::Il2CppObject* view) {}

// C#: System.Void OnStageStart(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStageStart(int32_t timing) {}

// C#: System.Void OnWaveStart(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnWaveStart(int32_t timing) {}

// C#: System.Void OnPanicOrLowMorale(PANIC_LEVEL level, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnPanicOrLowMorale(int32_t level, int32_t timing) {}

// C#: System.Void OnRoundStart_Before()
void PassiveBase::OnRoundStart_Before() {}

// C#: System.Void OnRoundStart()
void PassiveBase::OnRoundStart() {}

// C#: System.Void OnRoundStart_After_Event(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRoundStart_After_Event(int32_t timing) {}

// C#: System.Void OnRoundStart_After_Event_DeadOrRetreated(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRoundStart_After_Event_DeadOrRetreated(int32_t timing) {}

// C#: System.Void OnRoundStart_After_RelatedSlotState(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRoundStart_After_RelatedSlotState(int32_t timing) {}

// C#: System.Void OnReturnToField(System.Int32 retreatTurn, BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnReturnToField(int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {}

// C#: System.Void OnReturnToFieldOtherUnit(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {}

// C#: System.Void OnReturnToFieldOtherUnit_DeadOrRetreated(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {}

// C#: System.Void OnReleaseStandByOtherUnit_DeadOrRetreated(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void PassiveBase::OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {}

// C#: System.Void OnReleaseStandByOtherUnit(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void PassiveBase::OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {}

// C#: System.Void OnReleaseStandBy(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnReleaseStandBy(int32_t timing) {}

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnCompleteCommand(int32_t timing) {}

// C#: System.Boolean BeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
bool PassiveBase::BeforeCompleteCommand(bool returnValue, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID) { return returnValue; }

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRoundEnd(int32_t timing) {}

// C#: System.Void OnRoundEnd_Disappeared(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRoundEnd_Disappeared(int32_t timing) {}

// C#: System.Void OnRetreat(BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRetreat(il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {}

// C#: System.Void OnRoundEnd_After()
void PassiveBase::OnRoundEnd_After() {}

// C#: System.Void OnStageEnd()
void PassiveBase::OnStageEnd() {}

// C#: System.Void OnBeforeDefense(BattleActionModel action)
void PassiveBase::OnBeforeDefense(il2cpp::Il2CppObject* action) {}

// C#: System.Void OnStartRunBattle()
void PassiveBase::OnStartRunBattle() {}

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnBattleStart(int32_t timing) {}

// C#: System.Void OnBattleEnd(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnBattleEnd(int32_t timing) {}

// C#: System.Void OnBeforeTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnBeforeTurn(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnStartTurn_BeforeLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartTurn_BeforeLog(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnStartTurn_AfterLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartTurn_AfterLog(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnStartDuel(BattleActionModel ownerAction, BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartDuel(il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing) {}

// C#: System.Void BeforeGiveAttackDamage(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void PassiveBase::BeforeGiveAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {}

// C#: System.Void BeforeTakeAttackDamage(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::BeforeTakeAttackDamage(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void BeforePartTakeAttackDamage(BattleUnitModel_Abnormality abnormality, BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::BeforePartTakeAttackDamage(il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnTakeAttackDamage(BattleActionModel action, CoinModel coin, System.Int32 totalDmg, System.Int32 hpDmg, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnTakeAttackDamage(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing) {}

// C#: System.Void OnTakeAttackDamagePart(BattleUnitModel_Abnormality_Part part, BattleActionModel attackerAction, CoinModel coin, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
void PassiveBase::OnTakeAttackDamagePart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical) {}

// C#: System.Void OnGiveHpDamage(BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnGiveHpDamage(il2cpp::Il2CppObject* target, int32_t value, int32_t timing) {}

// C#: System.Void OnGiveMpDamage(BattleUnitModel target, System.Int32 value)
void PassiveBase::OnGiveMpDamage(il2cpp::Il2CppObject* target, int32_t value) {}

// C#: System.Void OnTakeMpDmg_SinBuff(System.Int32 value, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnTakeMpDmg_SinBuff(int32_t value, int32_t timing, int32_t keyword) {}

// C#: System.Void OnKillTarget(BattleActionModel actionOrNull, BattleUnitModel target, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnKillTarget(il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing) {}

// C#: System.Void OnEndTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndTurn(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnBeforeStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnBeforeStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {}

// C#: System.Void OnStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {}

// C#: System.Void OnEndCoin_BeforeLog(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndCoin_BeforeLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {}

// C#: System.Void OnEndCoin_AfterLog(BattleActionModel action, CoinModel coin)
void PassiveBase::OnEndCoin_AfterLog(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {}

// C#: System.Void OnEndBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnEndBehaviour(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnEndBehave_Refresh(BattleActionModel action)
void PassiveBase::OnEndBehave_Refresh(il2cpp::Il2CppObject* action) {}

// C#: System.Void OnCriticalActivated(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnCriticalActivated(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {}

// C#: System.Void BeforeAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void PassiveBase::BeforeAttack(il2cpp::Il2CppObject* action, int32_t timing) {}

// C#: System.Void OnAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing) {}

// C#: System.Boolean CanTeamKill(BattleActionModel action)
bool PassiveBase::CanTeamKill(bool returnValue, il2cpp::Il2CppObject* action) { return returnValue; }

// C#: System.Collections.Generic.List<PrimeTargetData> GetPrimeTargets(BattleActionModel action)
il2cpp::Il2CppObject* PassiveBase::GetPrimeTargets(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action) { return returnValue; }

// C#: System.Int32 GetSkillPowerAdder(BattleActionModel action, COIN_ROLL_TYPE rollType)
int32_t PassiveBase::GetSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t rollType) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPowerResultAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, BattleUnitModel expectedTarget)
int32_t PassiveBase::GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPowerAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
int32_t PassiveBase::GetExpectedSkillPowerAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) { return returnValue; }

// C#: System.Boolean HasPassive(System.Int32 passiveID)
bool PassiveBase::HasPassive(bool returnValue, int32_t passiveID) { return returnValue; }

// C#: System.Void OnStartPhase(PHASE phase, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnStartPhase(int32_t phase, int32_t timing) {}

// C#: System.Boolean HasFakeDead()
bool PassiveBase::HasFakeDead(bool returnValue) { return returnValue; }

// C#: System.Nullable<System.Single> OverwriteAtkResist_Default(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveBase::OverwriteAtkResist_Default(il2cpp::Il2CppObject* returnValue, int32_t type) { return returnValue; }

// C#: System.Nullable<System.Single> OverwriteAtkResist_Result(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveBase::OverwriteAtkResist_Result(il2cpp::Il2CppObject* returnValue, int32_t type) { return returnValue; }

// C#: System.Nullable<System.Single> OverwriteAttributeDefaultResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* PassiveBase::OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* returnValue, int32_t type) { return returnValue; }

// C#: System.Nullable<System.Single> OverwriteAttributeResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* PassiveBase::OverwriteAttributeResist(il2cpp::Il2CppObject* returnValue, int32_t type) { return returnValue; }

// C#: System.Nullable<System.Int32> OverwriteMaxBuffStack(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* PassiveBase::OverwriteMaxBuffStack(il2cpp::Il2CppObject* returnValue, int32_t keyword) { return returnValue; }

// C#: System.Nullable<System.Int32> OverwriteMaxBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* PassiveBase::OverwriteMaxBuffTurn(il2cpp::Il2CppObject* returnValue, int32_t keyword) { return returnValue; }

// C#: System.Nullable<System.Int32> OverwriteSkillID(System.Int32 originID)
il2cpp::Il2CppObject* PassiveBase::OverwriteSkillID(il2cpp::Il2CppObject* returnValue, int32_t originID) { return returnValue; }

// C#: System.Nullable<System.Int32> OverwriteSpeed(System.Int32 speed)
il2cpp::Il2CppObject* PassiveBase::OverwriteSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed) { return returnValue; }

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleUnitModel unit, BattleActionModel selfAction, BattleActionModel oppoAction)
bool PassiveBase::CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction) { return returnValue; }

// C#: System.Void OnZeroHp()
void PassiveBase::OnZeroHp() {}

// C#: System.Int32 GetParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
int32_t PassiveBase::GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) { return returnValue; }

// C#: System.Int32 GetExpectedParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
int32_t PassiveBase::GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) { return returnValue; }

// C#: System.Int32 GetOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t PassiveBase::GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) { return returnValue; }

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t PassiveBase::GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) { return returnValue; }

// C#: System.Void ActivateEgoPassive(System.Int32 egoId)
void PassiveBase::ActivateEgoPassive(int32_t egoId) {}

// C#: System.Void ActivateEquipEgoPassives()
void PassiveBase::ActivateEquipEgoPassives() {}

// C#: System.Void ActivateEgoPassives(BattleEgoModel ego, System.Collections.Generic.List<System.Int32> passiveIdList, System.Boolean isEquipEgoPassive)
void PassiveBase::ActivateEgoPassives(il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive) {}

// C#: System.Collections.Generic.List<BattleEgoModel> GetOwnerEgoModelList()
il2cpp::Il2CppObject* PassiveBase::GetOwnerEgoModelList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: BattleEgoModel FindEgoModel(System.Int32 egoId)
il2cpp::Il2CppObject* PassiveBase::FindEgoModel(il2cpp::Il2CppObject* returnValue, int32_t egoId) { return returnValue; }

// C#: System.Void AddReadyEgoPassive(System.Int32 egoId)
void PassiveBase::AddReadyEgoPassive(int32_t egoId) {}

// C#: System.Boolean CanAddEgoPassive(System.Int32 egoId)
bool PassiveBase::CanAddEgoPassive(bool returnValue, int32_t egoId) { return returnValue; }

// C#: System.Boolean PassesCondition(PassiveStaticData passiveData, BattleEgoModel ego)
bool PassiveBase::PassesCondition(bool returnValue, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego) { return returnValue; }

// C#: System.Void OnResult_OnAction(BattleActionModel action, CoinModel coin)
void PassiveBase::OnResult_OnAction(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {}

// C#: System.Void OnResult_OnParrying(BattleActionModel action, BattleActionModel oppoAction, CoinModel coin)
void PassiveBase::OnResult_OnParrying(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin) {}

// C#: System.Void AddPassive(PassiveModel passiveModel)
void PassiveBase::AddPassive(il2cpp::Il2CppObject* passiveModel) {}

// C#: System.Boolean IsRegeneratable()
bool PassiveBase::IsRegeneratable(bool returnValue) { return returnValue; }

// C#: System.Boolean SpreadHpDmgToAbnormality(System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool PassiveBase::SpreadHpDmgToAbnormality(bool returnValue, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) { return returnValue; }

// C#: System.Boolean SpreadHpDmgFromAbnormalityPart(AB_PART_TYPE partType, System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool PassiveBase::SpreadHpDmgFromAbnormalityPart(bool returnValue, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) { return returnValue; }

// C#: System.Void OnSucceedEvade(BattleActionModel evadeAction, BattleActionModel attackAction, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnSucceedEvade(il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing) {}

// C#: System.Void OnGiveBuffTrigger(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnGiveBuffTrigger(il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing) {}

// C#: System.Void RightBeforeLosingBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightBeforeLosingBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {}

// C#: System.Boolean CanCreateEmptySlot()
bool PassiveBase::CanCreateEmptySlot(bool returnValue) { return returnValue; }

// C#: System.Boolean CanCreateEmptySlotPart(BattleUnitModel_Abnormality_Part part)
bool PassiveBase::CanCreateEmptySlotPart(bool returnValue, il2cpp::Il2CppObject* part) { return returnValue; }

// C#: System.Int32 GetActionSlotAdder()
int32_t PassiveBase::GetActionSlotAdder(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetMaxHpAdder()
int32_t PassiveBase::GetMaxHpAdder(int32_t returnValue) { return returnValue; }

// C#: System.Single GetMaxHpMultiplier()
float PassiveBase::GetMaxHpMultiplier(float returnValue) { return returnValue; }

// C#: System.Single GetMaxHpMultiplierPartToAbnormality()
float PassiveBase::GetMaxHpMultiplierPartToAbnormality(float returnValue) { return returnValue; }

// C#: System.Single GetMaxHpMultiplierContributionToAbnormality()
float PassiveBase::GetMaxHpMultiplierContributionToAbnormality(float returnValue) { return returnValue; }

// C#: System.Boolean CanTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 mp, ABILITY_SOURCE_TYPE srcType)
bool PassiveBase::CanTakeMpHeal(bool returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType) { return returnValue; }

// C#: System.Void OnAfterTryTakeHpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {}

// C#: System.Void OnBeforeTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {}

// C#: System.Void OnAfterTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {}

// C#: System.Boolean CheckImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool PassiveBase::CheckImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) { return returnValue; }

// C#: System.Boolean CheckImmortalOtherUnit(BattleUnitModel checkTarget, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buf)
bool PassiveBase::CheckImmortalOtherUnit(bool returnValue, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf) { return returnValue; }

// C#: System.Void OnGiveImmortalState(BattleUnitModel immortalTaker, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnGiveImmortalState(il2cpp::Il2CppObject* immortalTaker, int32_t timing) {}

// C#: System.Void OnBeforeActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveBase::OnBeforeActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveBase::OnActivateImmortality(il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnActivateAbnormalityImmortality(BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveBase::OnActivateAbnormalityImmortality(int32_t timing, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnActivateOtherUnitBurstReactive(BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnActivateOtherUnitBurstReactive(int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing) {}

// C#: System.Void OnBurstReactiveActivatedAnyUnit(BattleUnitModel buffOwner, BUFF_UNIQUE_KEYWORD keyword, System.Int32 loseStack, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, BattleUnitModel giverOrNull)
void PassiveBase::OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull) {}

// C#: System.Void OnAddShield(BATTLE_EVENT_TIMING timing, System.Int32 value)
void PassiveBase::OnAddShield(int32_t timing, int32_t value) {}

// C#: System.Void OnReduceShield(BATTLE_EVENT_TIMING timing, System.Int32 old, System.Int32 value, BattleUnitModel attackerOrNull)
void PassiveBase::OnReduceShield(int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull) {}

// C#: System.Void OnDestroyShield(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnDestroyShield(int32_t timing) {}

// C#: System.Void OnDestoryShieldPart(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull)
void PassiveBase::OnDestoryShieldPart(il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull) {}

// C#: System.Void OnRecoverBreak(BATTLE_EVENT_TIMING timing)
void PassiveBase::OnRecoverBreak(int32_t timing) {}

// C#: System.Void OnGiveBsGaugeUp(BattleUnitModel giver, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion, ABILITY_SOURCE_TYPE abilitySrc, BattleActionModel actionOrNull)
void PassiveBase::OnGiveBsGaugeUp(il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnTakeHpDamage(int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {}

// C#: System.Void OnTakeHpDamagePart(BattleUnitModel_Abnormality_Part part, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnTakeHpDamagePart(il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {}

// C#: System.Void OnTakeHpDamageOtherUnit(BattleUnitModel damaged, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, System.Collections.Generic.List<BattleUnitModel> relatedUnitsOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword) {}

// C#: System.Void OnTryTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BattleActionModel actionOrNull, BattleUnitModel attackerOrNull, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnTryTakeHpDamage(int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing) {}

// C#: System.Single GetTakeHpHealMultiplier(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float PassiveBase::GetTakeHpHealMultiplier(float returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) { return returnValue; }

// C#: System.Void OnTakeAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel attacker, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnTakeAttackConfirmed(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing) {}

// C#: System.Int32 GetMaxHpAdderPart(BattleUnitModel_Abnormality_Part part)
int32_t PassiveBase::GetMaxHpAdderPart(int32_t returnValue, il2cpp::Il2CppObject* part) { return returnValue; }

// C#: System.Single GetTakeHpHealMultiplierPart(BattleUnitModel_Abnormality_Part part, BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float PassiveBase::GetTakeHpHealMultiplierPart(float returnValue, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) { return returnValue; }

// C#: System.Int32 GetTakeHpHealAdder(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
int32_t PassiveBase::GetTakeHpHealAdder(int32_t returnValue, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) { return returnValue; }

// C#: System.Void OverwriteTargetableList(System.Collections.Generic.List<SinActionModel> targetableSlotListOrNull, System.Collections.Generic.List<BattleUnitModel> origianlTargetList)
void PassiveBase::OverwriteTargetableList(il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList) {}

// C#: System.Nullable<System.Single> OverwriteAtkResistWhenDestroyed(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* PassiveBase::OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* returnValue, int32_t type) { return returnValue; }

// C#: System.Void OnChangeHp(System.Int32 oldHp, System.Int32 newHp, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void PassiveBase::OnChangeHp(int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {}

// C#: System.Void OnChangeMp(System.Int32 oldMp, System.Int32 newMp)
void PassiveBase::OnChangeMp(int32_t oldMp, int32_t newMp) {}

// C#: System.Void OnChangeMpOther(BattleUnitModel mpChangeUnit, System.Int32 oldMp, System.Int32 newMp)
void PassiveBase::OnChangeMpOther(il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp) {}

// C#: System.Void OnTakeMpDamage(BattleUnitModel attacker, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleActionModel actionOrNull)
void PassiveBase::OnTakeMpDamage(il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnTakeMpDamageOther(BattleUnitModel mpDmgUnit, BattleUnitModel attackerOrNull, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BUFF_UNIQUE_KEYWORD buffKeyword, BattleActionModel actionOrNull)
void PassiveBase::OnTakeMpDamageOther(il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnAfterTryTakeMpHealOther(BattleUnitModel mpHealUnit, BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {}

// C#: System.Void UnlockAllPassives()
void PassiveBase::UnlockAllPassives() {}

// C#: System.Void OnUseBuffTurnBySkill(SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnUseBuffTurnBySkill(il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing) {}

// C#: System.Void OnUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {}

// C#: System.Void BeforeUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveBase::BeforeUseBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {}

// C#: System.Single GetCoinProbAdder()
float PassiveBase::GetCoinProbAdder(float returnValue) { return returnValue; }

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, System.Single& prob)
bool PassiveBase::OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob) { return returnValue; }

// C#: System.Boolean IsEgoSkillFree(BattleEgoModel ego)
bool PassiveBase::IsEgoSkillFree(bool returnValue, il2cpp::Il2CppObject* ego) { return returnValue; }

// C#: System.Void OnPickSkills()
void PassiveBase::OnPickSkills() {}

// C#: System.Void OnAddActionToPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action)
void PassiveBase::OnAddActionToPart(il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action) {}

// C#: System.Void OnAddCoinByAbility(BattleActionModel action, CoinModel newCoin, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnAddCoinByAbility(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing) {}

// C#: System.Boolean CanOverwritePanicType()
bool PassiveBase::CanOverwritePanicType(bool returnValue) { return returnValue; }

// C#: System.Single GetCriticalChanceAdder(System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
float PassiveBase::GetCriticalChanceAdder(float returnValue, il2cpp::Il2CppObject* affectKeywords) { return returnValue; }

// C#: System.Single GetCriticalDamageRatioResultMultiplier(BattleActionModel action)
float PassiveBase::GetCriticalDamageRatioResultMultiplier(float returnValue, il2cpp::Il2CppObject* action) { return returnValue; }

// C#: System.Void RightAfterDestroyAnyBuff(BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void PassiveBase::RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {}

// C#: System.Boolean IsAbnormalityImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool PassiveBase::IsAbnormalityImmortal(bool returnValue, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) { return returnValue; }

// C#: System.Boolean CheckIfTurnToCorpesOnDie()
bool PassiveBase::CheckIfTurnToCorpesOnDie(bool returnValue) { return returnValue; }

// C#: System.Void OnCanceledByLackOfBuffsAtStartCoin(BattleActionModel action, CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD> lackOfBuffs, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing) {}

// C#: System.Void CheckOverwriteGettingBuff(ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BUFF_UNIQUE_KEYWORD& keyword, System.Int32& stack, System.Int32& turn, System.Int32& activeRound)
void PassiveBase::CheckOverwriteGettingBuff(int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound) {}

// C#: System.Boolean IsAllowedToGiveBuff(BUFF_UNIQUE_KEYWORD keyword)
bool PassiveBase::IsAllowedToGiveBuff(bool returnValue, int32_t keyword) { return returnValue; }

// C#: System.Void OnFailedToGetBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel giverActionOrNull)
void PassiveBase::OnFailedToGetBuff(int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull) {}

// C#: System.Void RightAfterFailingGetAnyBuff(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void PassiveBase::RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {}

// C#: System.Void OnFailedToGiveBuff(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void PassiveBase::OnFailedToGiveBuff(il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {}

// C#: System.Void OnUseCoinConsume(BattleUnitModel owner, BattleActionModel action, CoinModel coin, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void PassiveBase::OnUseCoinConsume(il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {}

// C#: System.Boolean BlockGivingBuff(BattleActionModel action, BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool PassiveBase::BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Nullable<System.Int32> OverwritePartSpeed(System.Int32 speed, BattleUnitModel_Abnormality_Part part)
il2cpp::Il2CppObject* PassiveBase::OverwritePartSpeed(il2cpp::Il2CppObject* returnValue, int32_t speed, il2cpp::Il2CppObject* part) { return returnValue; }

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel unit, BattleUnitModel target, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Boolean> isCritical)
bool PassiveBase::BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Boolean BlockLoseBuffStack(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool PassiveBase::BlockLoseBuffStack(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) { return returnValue; }

// C#: System.Boolean BlockLoseBuffTurn(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool PassiveBase::BlockLoseBuffTurn(bool returnValue, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) { return returnValue; }

// C#: System.Boolean IsBlockingSinkingBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerAction, CoinModel attackerCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IsBlockingSinkingBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Nullable<System.Boolean> OverwriteCanDuel(BattleActionModel selfAction, BattleActionModel opponentAction)
il2cpp::Il2CppObject* PassiveBase::OverwriteCanDuel(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction) { return returnValue; }

// C#: System.Boolean IsBlockingBurstBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IsBlockingBurstBuffEffectReact(bool returnValue, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool PassiveBase::IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Boolean ModifyMpChangeValue(System.Int32 oldMp, System.Int32 newMp, System.Int32& changedNewMp)
bool PassiveBase::ModifyMpChangeValue(bool returnValue, int32_t oldMp, int32_t newMp, int32_t* changedNewMp) { return returnValue; }

// C#: System.Void OnAddBattleAction(SinActionModel actorAction, SinActionModel targetAction)
void PassiveBase::OnAddBattleAction(il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction) {}

// C#: System.Void OnRemoveBattleAction(SinActionModel actorAction)
void PassiveBase::OnRemoveBattleAction(il2cpp::Il2CppObject* actorAction) {}

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel thisAction, BattleActionModel mainAction, BattleActionModel oppoActionOrNull)
bool PassiveBase::IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull) { return returnValue; }


// =============================================================================
// Hooks: call the original first, then hand the result to the C++ handler (if this
// PassiveBase instance has one) so it can inspect / modify it.
// =============================================================================

// C#: System.Void OnStartBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnStartBehaviour(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartBehaviour(action, timing);
    }
}

// C#: System.Void OnSucceedAttack(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnSucceedAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    original_PassiveBase_OnSucceedAttack(__this, action, coin, target, finalDmg, realDmg, realHpDmg, isCritical, isWinDuel, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnSucceedAttack(action, coin, target, finalDmg, realDmg, realHpDmg, isCritical, isWinDuel, timing);
    }
}

// C#: System.Void OnRollOneCoin_AfterAttack(BattleActionModel action, CoinModel coin)
void hooked_PassiveBase_OnRollOneCoin_AfterAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    original_PassiveBase_OnRollOneCoin_AfterAttack(__this, action, coin);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRollOneCoin_AfterAttack(action, coin);
    }
}

// C#: System.Void OnEndAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnEndAttack(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndAttack(action, timing);
    }
}

// C#: System.Void OnEndAttackOtherUnit(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndAttackOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing) {
    original_PassiveBase_OnEndAttackOtherUnit(__this, attackerAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndAttackOtherUnit(attackerAction, timing);
    }
}

// C#: System.Void OnStartEnemyAttack(BattleUnitModel unit, BattleActionModel opponentAction, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartEnemyAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* opponentAction, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    original_PassiveBase_OnStartEnemyAttack(__this, unit, opponentAction, isWinDuel, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartEnemyAttack(unit, opponentAction, isWinDuel, timing);
    }
}

// C#: System.Void OnEndEnemyAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndEnemyAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnEndEnemyAttack(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndEnemyAttack(action, timing);
    }
}

// C#: System.Void OnEndAttackPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndAttackPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnEndAttackPart(__this, part, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndAttackPart(part, action, timing);
    }
}

// C#: System.Void OnDuelAfter_BeforeLog(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {
    original_PassiveBase_OnDuelAfter_BeforeLog(__this, selfAction, oppoAction, parryingCount, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDuelAfter_BeforeLog(selfAction, oppoAction, parryingCount, timing);
    }
}

// C#: System.Void OnAfterParryingOnce_BeforeLog(PARRYING_RESULT result, BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCnt, int32_t timing) {
    original_PassiveBase_OnAfterParryingOnce_BeforeLog(__this, result, selfAction, oppoAction, parryingCnt, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAfterParryingOnce_BeforeLog(result, selfAction, oppoAction, parryingCnt, timing);
    }
}

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    original_PassiveBase_OnAfterParryingOnce_AfterLog(__this, selfAction, oppoAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAfterParryingOnce_AfterLog(selfAction, oppoAction, timing);
    }
}

// C#: System.Void OnWinParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnWinParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    original_PassiveBase_OnWinParrying(__this, selfAction, oppoAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnWinParrying(selfAction, oppoAction, timing);
    }
}

// C#: System.Void OnLoseParrying(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnLoseParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    original_PassiveBase_OnLoseParrying(__this, selfAction, oppoAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnLoseParrying(selfAction, oppoAction, timing);
    }
}

// C#: System.Void OnWinDuel(BattleActionModel selfAction, BattleActionModel oppoAction, System.Int32 parryingCount, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnWinDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t timing) {
    original_PassiveBase_OnWinDuel(__this, selfAction, oppoAction, parryingCount, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnWinDuel(selfAction, oppoAction, parryingCount, timing);
    }
}

// C#: System.Void OnLoseDuel(BattleActionModel selfAction, BattleActionModel oppoAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnLoseDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction, int32_t timing) {
    original_PassiveBase_OnLoseDuel(__this, selfAction, oppoAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnLoseDuel(selfAction, oppoAction, timing);
    }
}

// C#: System.Void OnLoseDuelOtherUnit(BattleActionModel loserAction, BattleActionModel winnerAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnLoseDuelOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* loserAction, il2cpp::Il2CppObject* winnerAction, int32_t timing) {
    original_PassiveBase_OnLoseDuelOtherUnit(__this, loserAction, winnerAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnLoseDuelOtherUnit(loserAction, winnerAction, timing);
    }
}

// C#: System.Void RightBeforeGiveBuffBySkill(SkillModel skill, CoinModel coinOrNull, BUFF_UNIQUE_KEYWORD buf, System.Int32 stack, System.Int32 turn, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void hooked_PassiveBase_RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, int32_t buf, int32_t stack, int32_t turn, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    original_PassiveBase_RightBeforeGiveBuffBySkill(__this, skill, coinOrNull, buf, stack, turn, target, timing, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightBeforeGiveBuffBySkill(skill, coinOrNull, buf, stack, turn, target, timing, isCritical);
    }
}

// C#: System.Void RightAfterGiveBuffBySkill(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void hooked_PassiveBase_RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, il2cpp::Il2CppObject* target, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    original_PassiveBase_RightAfterGiveBuffBySkill(__this, action, skill, buf, originalStack, originalTurn, resultStack, resultTurn, activeRound, target, timing, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterGiveBuffBySkill(action, skill, buf, originalStack, originalTurn, resultStack, resultTurn, activeRound, target, timing, isCritical);
    }
}

// C#: System.Void RightAfterTakeBuffBySkill(BattleUnitModel unit, BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, BattleUnitModel giver, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, System.Int32 afterAdderStack, System.Int32 afterAdderTurn)
void hooked_PassiveBase_RightAfterTakeBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* giver, int32_t timing, il2cpp::Il2CppObject* isCritical, int32_t afterAdderStack, int32_t afterAdderTurn) {
    original_PassiveBase_RightAfterTakeBuffBySkill(__this, unit, action, skill, bufKeyword, stack, turn, giver, timing, isCritical, afterAdderStack, afterAdderTurn);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterTakeBuffBySkill(unit, action, skill, bufKeyword, stack, turn, giver, timing, isCritical, afterAdderStack, afterAdderTurn);
    }
}

// C#: System.Void RightBeforeOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {
    original_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill(__this, giver, target, bufKeyword, stack, turn, skill, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightBeforeOtherUnitGiveBuffBySkill(giver, target, bufKeyword, stack, turn, skill, timing);
    }
}

// C#: System.Void RightAfterOtherUnitGiveBuffBySkill(BattleUnitModel giver, BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, SkillModel skill, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightAfterOtherUnitGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t stack, int32_t turn, il2cpp::Il2CppObject* skill, int32_t timing) {
    original_PassiveBase_RightAfterOtherUnitGiveBuffBySkill(__this, giver, target, bufKeyword, stack, turn, skill, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterOtherUnitGiveBuffBySkill(giver, target, bufKeyword, stack, turn, skill, timing);
    }
}

// C#: System.Void RightAfterAnyUnitGetAnyBuff(BattleUnitModel receiver, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, BattleUnitModel giverOrNull, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, System.Int32 overStack, System.Int32 overTurn)
void hooked_PassiveBase_RightAfterAnyUnitGetAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* receiver, int32_t bufKeyword, int32_t stack, int32_t turn, int32_t activeRound, il2cpp::Il2CppObject* giverOrNull, int32_t srcType, int32_t timing, int32_t overStack, int32_t overTurn) {
    original_PassiveBase_RightAfterAnyUnitGetAnyBuff(__this, receiver, bufKeyword, stack, turn, activeRound, giverOrNull, srcType, timing, overStack, overTurn);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterAnyUnitGetAnyBuff(receiver, bufKeyword, stack, turn, activeRound, giverOrNull, srcType, timing, overStack, overTurn);
    }
}

// C#: System.Void RightAfterLosingBuff(System.Int32 loseStack, System.Int32 loseTurn, BuffInfo loseBuffInfo, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightAfterLosingBuff(il2cpp::Il2CppObject* __this, int32_t loseStack, int32_t loseTurn, il2cpp::Il2CppObject* loseBuffInfo, int32_t timing) {
    original_PassiveBase_RightAfterLosingBuff(__this, loseStack, loseTurn, loseBuffInfo, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterLosingBuff(loseStack, loseTurn, loseBuffInfo, timing);
    }
}

// C#: System.Void OnSucceedToGiveSwitchToSpecialVibration(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 prevStack, System.Int32 prevTurn, System.Int32 afterStack, System.Int32 afterTurn, System.Boolean isPileUp, BATTLE_EVENT_TIMING timing, ABILITY_SOURCE_TYPE abilitySourceType)
void hooked_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t prevStack, int32_t prevTurn, int32_t afterStack, int32_t afterTurn, bool isPileUp, int32_t timing, int32_t abilitySourceType) {
    original_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration(__this, target, keyword, prevStack, prevTurn, afterStack, afterTurn, isPileUp, timing, abilitySourceType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnSucceedToGiveSwitchToSpecialVibration(target, keyword, prevStack, prevTurn, afterStack, afterTurn, isPileUp, timing, abilitySourceType);
    }
}

// C#: System.Void RightAfterGetAnyBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void hooked_PassiveBase_RightAfterGetAnyBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {
    original_PassiveBase_RightAfterGetAnyBuff(__this, keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterGetAnyBuff(keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
    }
}

// C#: System.Void RightAfterGetAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull)
void hooked_PassiveBase_RightAfterGetAnyBuffAtPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t keyword, int32_t stack, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_RightAfterGetAnyBuffAtPart(__this, part, keyword, stack, activeRound, srcType, timing, giverOrNull, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterGetAnyBuffAtPart(part, keyword, stack, activeRound, srcType, timing, giverOrNull, actionOrNull);
    }
}

// C#: System.Void RightAfterDestroyAnyBuffAtPart(BattleUnitModel_Abnormality_Part part, BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightAfterDestroyAnyBuffAtPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {
    original_PassiveBase_RightAfterDestroyAnyBuffAtPart(__this, part, destroyedBuffInfo, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterDestroyAnyBuffAtPart(part, destroyedBuffInfo, timing);
    }
}

// C#: System.Int32 GetAggroAdder(SinActionModel sinaction)
int32_t hooked_PassiveBase_GetAggroAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sinaction) {
    int32_t returnValue = original_PassiveBase_GetAggroAdder(__this, sinaction);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAggroAdder(returnValue, sinaction);
    }
    return returnValue;
}

// C#: System.Int32 GetAttackWeightAdder(BattleActionModel action)
int32_t hooked_PassiveBase_GetAttackWeightAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    int32_t returnValue = original_PassiveBase_GetAttackWeightAdder(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttackWeightAdder(returnValue, action);
    }
    return returnValue;
}

// C#: System.Int32 GetMentalSystemResultIncreaseAdder()
int32_t hooked_PassiveBase_GetMentalSystemResultIncreaseAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetMentalSystemResultIncreaseAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMentalSystemResultIncreaseAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetMentalSystemResultDecreaseAdder()
int32_t hooked_PassiveBase_GetMentalSystemResultDecreaseAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetMentalSystemResultDecreaseAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMentalSystemResultDecreaseAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetInitBuffMaxStackAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_PassiveBase_GetInitBuffMaxStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword) {
    int32_t returnValue = original_PassiveBase_GetInitBuffMaxStackAdder(__this, unit, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetInitBuffMaxStackAdder(returnValue, unit, keyword);
    }
    return returnValue;
}

// C#: System.Int32 GetInitBuffMaxTurnAdder(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_PassiveBase_GetInitBuffMaxTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword) {
    int32_t returnValue = original_PassiveBase_GetInitBuffMaxTurnAdder(__this, unit, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetInitBuffMaxTurnAdder(returnValue, unit, keyword);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffTurnAdderOtherUnit(BattleUnitModel taker, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_GetTakeBuffTurnAdderOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* taker, il2cpp::Il2CppObject* action, int32_t keyword, int32_t originalTurn, int32_t timing) {
    int32_t returnValue = original_PassiveBase_GetTakeBuffTurnAdderOtherUnit(__this, taker, action, keyword, originalTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBuffTurnAdderOtherUnit(returnValue, taker, action, keyword, originalTurn, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffStackAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originStack, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_GetTakeBuffStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originStack, int32_t timing) {
    int32_t returnValue = original_PassiveBase_GetTakeBuffStackAdder(__this, action, skill, buf, originStack, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBuffStackAdder(returnValue, action, skill, buf, originStack, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeBuffTurnAdder(BattleActionModel action, SkillModel skill, BUFF_UNIQUE_KEYWORD buf, System.Int32 originalTurn, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_GetTakeBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t buf, int32_t originalTurn, int32_t timing) {
    int32_t returnValue = original_PassiveBase_GetTakeBuffTurnAdder(__this, action, skill, buf, originalTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBuffTurnAdder(returnValue, action, skill, buf, originalTurn, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetGiveBuffTurnAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_GetGiveBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t timing) {
    int32_t returnValue = original_PassiveBase_GetGiveBuffTurnAdder(__this, action, skill, coinOrNull, target, buf, currentStack, currentTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetGiveBuffTurnAdder(returnValue, action, skill, coinOrNull, target, buf, currentStack, currentTurn, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetGiveBuffStackAdder(BattleActionModel action, SkillModel skill, CoinModel coinOrNull, BattleUnitModel target, BUFF_UNIQUE_KEYWORD buf, System.Int32 currentStack, System.Int32 currentTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
int32_t hooked_PassiveBase_GetGiveBuffStackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t buf, int32_t currentStack, int32_t currentTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    int32_t returnValue = original_PassiveBase_GetGiveBuffStackAdder(__this, action, skill, coinOrNull, target, buf, currentStack, currentTurn, activeRound, timing, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetGiveBuffStackAdder(returnValue, action, skill, coinOrNull, target, buf, currentStack, currentTurn, activeRound, timing, isCritical);
    }
    return returnValue;
}

// C#: System.Int32 GetUseBuffTurnAdder(BattleActionModel action, SkillModel skill, System.Int32 turn, BUFF_UNIQUE_KEYWORD buf)
int32_t hooked_PassiveBase_GetUseBuffTurnAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* skill, int32_t turn, int32_t buf) {
    int32_t returnValue = original_PassiveBase_GetUseBuffTurnAdder(__this, action, skill, turn, buf);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetUseBuffTurnAdder(returnValue, action, skill, turn, buf);
    }
    return returnValue;
}

// C#: System.Single GetTakeBuffStackMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float hooked_PassiveBase_GetTakeBuffStackMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t buf) {
    float returnValue = original_PassiveBase_GetTakeBuffStackMultiplier(__this, skill, buf);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBuffStackMultiplier(returnValue, skill, buf);
    }
    return returnValue;
}

// C#: System.Single GetTakeBuffTurnMultiplier(SkillModel skill, BUFF_UNIQUE_KEYWORD buf)
float hooked_PassiveBase_GetTakeBuffTurnMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t buf) {
    float returnValue = original_PassiveBase_GetTakeBuffTurnMultiplier(__this, skill, buf);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBuffTurnMultiplier(returnValue, skill, buf);
    }
    return returnValue;
}

// C#: System.Void OnActivateSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 takeDmg, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced, System.Nullable<System.Boolean> isCritical)
void hooked_PassiveBase_OnActivateSinBuffEffect(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t takeDmg, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced, il2cpp::Il2CppObject* isCritical) {
    original_PassiveBase_OnActivateSinBuffEffect(__this, unit, keyword, stack, turn, takeDmg, giverOrNull, actionOrNull, timing, isForced, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnActivateSinBuffEffect(unit, keyword, stack, turn, takeDmg, giverOrNull, actionOrNull, timing, isForced, isCritical);
    }
}

// C#: System.Void OnActivateOtherUnitSinBuffEffect(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, System.Int32 takeDmg, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isForced)
void hooked_PassiveBase_OnActivateOtherUnitSinBuffEffect(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, il2cpp::Il2CppObject* buffOwner, int32_t takeDmg, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isForced) {
    original_PassiveBase_OnActivateOtherUnitSinBuffEffect(__this, unit, keyword, buffOwner, takeDmg, actionOrNull, timing, isForced);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnActivateOtherUnitSinBuffEffect(unit, keyword, buffOwner, takeDmg, actionOrNull, timing, isForced);
    }
}

// C#: System.Boolean IgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IgnoreSinBuffHpDamage(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    bool returnValue = original_PassiveBase_IgnoreSinBuffHpDamage(__this, keyword, dmg, isForeced, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IgnoreSinBuffHpDamage(returnValue, keyword, dmg, isForeced, timing);
    }
    return returnValue;
}

// C#: System.Boolean IgnoreSinBuffHpDamagePart(BattleUnitModel_Abnormality_Part part, BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IgnoreSinBuffHpDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    bool returnValue = original_PassiveBase_IgnoreSinBuffHpDamagePart(__this, part, keyword, dmg, isForeced, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IgnoreSinBuffHpDamagePart(returnValue, part, keyword, dmg, isForeced, timing);
    }
    return returnValue;
}

// C#: System.Void OnIgnoreSinBuffHpDamage(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg, System.Boolean isForeced, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnIgnoreSinBuffHpDamage(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg, bool isForeced, int32_t timing) {
    original_PassiveBase_OnIgnoreSinBuffHpDamage(__this, keyword, dmg, isForeced, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnIgnoreSinBuffHpDamage(keyword, dmg, isForeced, timing);
    }
}

// C#: System.Int32 GetSinBuffDamageAdder(BUFF_UNIQUE_KEYWORD keyword, System.Int32 dmg)
int32_t hooked_PassiveBase_GetSinBuffDamageAdder(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t dmg) {
    int32_t returnValue = original_PassiveBase_GetSinBuffDamageAdder(__this, keyword, dmg);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSinBuffDamageAdder(returnValue, keyword, dmg);
    }
    return returnValue;
}

// C#: System.Single GetSinBuffDamageMultiplier(BUFF_UNIQUE_KEYWORD keyword)
float hooked_PassiveBase_GetSinBuffDamageMultiplier(il2cpp::Il2CppObject* __this, int32_t keyword) {
    float returnValue = original_PassiveBase_GetSinBuffDamageMultiplier(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSinBuffDamageMultiplier(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Int32 GetMaxBuffStackAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_PassiveBase_GetMaxBuffStackAdder(il2cpp::Il2CppObject* __this, int32_t keyword) {
    int32_t returnValue = original_PassiveBase_GetMaxBuffStackAdder(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxBuffStackAdder(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Int32 GetMaxBuffTurnAdder(BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_PassiveBase_GetMaxBuffTurnAdder(il2cpp::Il2CppObject* __this, int32_t keyword) {
    int32_t returnValue = original_PassiveBase_GetMaxBuffTurnAdder(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxBuffTurnAdder(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Int32 GetUnitStatLevelAdder()
int32_t hooked_PassiveBase_GetUnitStatLevelAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetUnitStatLevelAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetUnitStatLevelAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull, BattleUnitModel target)
float hooked_PassiveBase_GetGiveBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target) {
    float returnValue = original_PassiveBase_GetGiveBsGaugeUpMultiplier(__this, onGiveExplosion, actionOrNull, coinOrNull, target);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetGiveBsGaugeUpMultiplier(returnValue, onGiveExplosion, actionOrNull, coinOrNull, target);
    }
    return returnValue;
}

// C#: System.Single GetTakeBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleActionModel actionOrNull, CoinModel coinOrNull)
float hooked_PassiveBase_GetTakeBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* coinOrNull) {
    float returnValue = original_PassiveBase_GetTakeBsGaugeUpMultiplier(__this, onGiveExplosion, actionOrNull, coinOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeBsGaugeUpMultiplier(returnValue, onGiveExplosion, actionOrNull, coinOrNull);
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPoolCountAdder(System.Int32 index, UnitAttribute attribute)
int32_t hooked_PassiveBase_GetSkillPoolCountAdder(il2cpp::Il2CppObject* __this, int32_t index, il2cpp::Il2CppObject* attribute) {
    int32_t returnValue = original_PassiveBase_GetSkillPoolCountAdder(__this, index, attribute);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSkillPoolCountAdder(returnValue, index, attribute);
    }
    return returnValue;
}

// C#: System.Void OnDestroy(BattleUnitModel destroyerOrNull, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDestroy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyerOrNull, int32_t timing) {
    original_PassiveBase_OnDestroy(__this, destroyerOrNull, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDestroy(destroyerOrNull, timing);
    }
}

// C#: System.Void OnOtherPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart)
void hooked_PassiveBase_OnOtherPartDestroyed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedPart) {
    original_PassiveBase_OnOtherPartDestroyed(__this, destroyedPart);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnOtherPartDestroyed(destroyedPart);
    }
}

// C#: System.Void OnPartDestroyed(BattleUnitModel_Abnormality_Part destroyedPart, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnPartDestroyed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedPart, int32_t timing) {
    original_PassiveBase_OnPartDestroyed(__this, destroyedPart, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPartDestroyed(destroyedPart, timing);
    }
}

// C#: System.Void OnPartBreaked(BattleUnitModel_Abnormality_Part breakedPart, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnPartBreaked(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedPart, int32_t timing) {
    original_PassiveBase_OnPartBreaked(__this, breakedPart, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPartBreaked(breakedPart, timing);
    }
}

// C#: System.Void OnPartRecoverBreak(BattleUnitModel_Abnormality_Part recoveredPart, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnPartRecoverBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* recoveredPart, int32_t timing) {
    original_PassiveBase_OnPartRecoverBreak(__this, recoveredPart, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPartRecoverBreak(recoveredPart, timing);
    }
}

// C#: System.Void OnRegenerate(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRegenerate(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRegenerate(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRegenerate(timing);
    }
}

// C#: System.Void OnPartRegenerate(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnPartRegenerate(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing) {
    original_PassiveBase_OnPartRegenerate(__this, part, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPartRegenerate(part, timing);
    }
}

// C#: System.Boolean CheckUnitGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_PassiveBase_CheckUnitGivingBuffCategory(il2cpp::Il2CppObject* __this, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_PassiveBase_CheckUnitGivingBuffCategory(__this, category, targetType, stackGiver, turnGiver);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckUnitGivingBuffCategory(returnValue, category, targetType, stackGiver, turnGiver);
    }
    return returnValue;
}

// C#: System.Boolean CheckUnitGivingBuffKeyword(BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_PassiveBase_CheckUnitGivingBuffKeyword(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_PassiveBase_CheckUnitGivingBuffKeyword(__this, keyword, targetType, stackGiver, turnGiver);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckUnitGivingBuffKeyword(returnValue, keyword, targetType, stackGiver, turnGiver);
    }
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuffCategory(BattleActionModel action, BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_PassiveBase_CheckSkillGivingBuffCategory(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_PassiveBase_CheckSkillGivingBuffCategory(__this, action, category, targetType, stackGiver, turnGiver);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckSkillGivingBuffCategory(returnValue, action, category, targetType, stackGiver, turnGiver);
    }
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuff(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_PassiveBase_CheckSkillGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t keyword, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_PassiveBase_CheckSkillGivingBuff(__this, action, keyword, targetType, stackGiver, turnGiver);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckSkillGivingBuff(returnValue, action, keyword, targetType, stackGiver, turnGiver);
    }
    return returnValue;
}

// C#: System.Void CheckLoseBuffStackAndTurn(BuffInfo info, System.Int32& loseStack, System.Int32& loseTurn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_CheckLoseBuffStackAndTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* info, int32_t* loseStack, int32_t* loseTurn, int32_t timing) {
    original_PassiveBase_CheckLoseBuffStackAndTurn(__this, info, loseStack, loseTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->CheckLoseBuffStackAndTurn(info, loseStack, loseTurn, timing);
    }
}

// C#: System.Int32 GetCoinScaleAdder(BattleActionModel action, BattleActionModel oppoActionOrNull, CoinModel coin)
int32_t hooked_PassiveBase_GetCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin) {
    int32_t returnValue = original_PassiveBase_GetCoinScaleAdder(__this, action, oppoActionOrNull, coin);
    MYO_LOG("PassiveBase", "Does the hooked GetCoinScaleAdder exist?");
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetCoinScaleAdder(returnValue, action, oppoActionOrNull, coin);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedCoinScaleAdder(BattleActionModel action, CoinModel coin, SinActionModel expectedTargetSinActionOrNull)
int32_t hooked_PassiveBase_GetExpectedCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    int32_t returnValue = original_PassiveBase_GetExpectedCoinScaleAdder(__this, action, coin, expectedTargetSinActionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedCoinScaleAdder(returnValue, action, coin, expectedTargetSinActionOrNull);
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPowerResultAdder(BattleActionModel action, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_GetSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    int32_t returnValue = original_PassiveBase_GetSkillPowerResultAdder(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSkillPowerResultAdder(returnValue, action, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeHpDmgAdder()
int32_t hooked_PassiveBase_GetTakeHpDmgAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetTakeHpDmgAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeHpDmgAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedTakeHpDmgAdder()
int32_t hooked_PassiveBase_GetExpectedTakeHpDmgAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetExpectedTakeHpDmgAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedTakeHpDmgAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetMinSpeedAdder()
int32_t hooked_PassiveBase_GetMinSpeedAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetMinSpeedAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMinSpeedAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetMaxSpeedAdder()
int32_t hooked_PassiveBase_GetMaxSpeedAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetMaxSpeedAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxSpeedAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetSpeedAdder()
int32_t hooked_PassiveBase_GetSpeedAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetSpeedAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSpeedAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean UseOnlyDefaultMinSpeed()
bool hooked_PassiveBase_UseOnlyDefaultMinSpeed(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_UseOnlyDefaultMinSpeed(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->UseOnlyDefaultMinSpeed(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean UseOnlyDefaultMaxSpeed()
bool hooked_PassiveBase_UseOnlyDefaultMaxSpeed(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_UseOnlyDefaultMaxSpeed(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->UseOnlyDefaultMaxSpeed(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 ChangeAttackDamage(BattleActionModel action, BattleUnitModel target, CoinModel coin, System.Int32 resultDmg, System.Boolean& isCritical, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged)
int32_t hooked_PassiveBase_ChangeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged) {
    int32_t returnValue = original_PassiveBase_ChangeAttackDamage(__this, action, target, coin, resultDmg, isCritical, timing, isChanged);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->ChangeAttackDamage(returnValue, action, target, coin, resultDmg, isCritical, timing, isChanged);
    }
    return returnValue;
}

// C#: System.Int32 ChangeTakeDamage(BattleActionModel action, CoinModel coinOrNull, System.Int32 resultDmg, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing, System.Boolean& isChanged, System.Int32 preCalculatedDmg)
int32_t hooked_PassiveBase_ChangeTakeDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg) {
    int32_t returnValue = original_PassiveBase_ChangeTakeDamage(__this, action, coinOrNull, resultDmg, dmgSrcType, keyword, timing, isChanged, preCalculatedDmg);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->ChangeTakeDamage(returnValue, action, coinOrNull, resultDmg, dmgSrcType, keyword, timing, isChanged, preCalculatedDmg);
    }
    return returnValue;
}

// C#: System.Int32 ChangeMpDamage(System.Int32 resultDmg, BattleActionModel actionOrNull, BASE_MENTAL_CONDITION mentalConditionOrNone, BUFF_UNIQUE_KEYWORD keywordOrNone, AbilityBase abilityOrNull, System.Boolean& isChanged, BATTLE_EVENT_TIMING timing)
int32_t hooked_PassiveBase_ChangeMpDamage(il2cpp::Il2CppObject* __this, int32_t resultDmg, il2cpp::Il2CppObject* actionOrNull, int32_t mentalConditionOrNone, int32_t keywordOrNone, il2cpp::Il2CppObject* abilityOrNull, bool* isChanged, int32_t timing) {
    int32_t returnValue = original_PassiveBase_ChangeMpDamage(__this, resultDmg, actionOrNull, mentalConditionOrNone, keywordOrNone, abilityOrNull, isChanged, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->ChangeMpDamage(returnValue, resultDmg, actionOrNull, mentalConditionOrNone, keywordOrNone, abilityOrNull, isChanged, timing);
    }
    return returnValue;
}

// C#: System.Int32 GetAttackHpDmgAdder(BattleUnitModel target)
int32_t hooked_PassiveBase_GetAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target) {
    int32_t returnValue = original_PassiveBase_GetAttackHpDmgAdder(__this, target);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttackHpDmgAdder(returnValue, target);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackHpDmgAdder(BattleUnitModel target)
int32_t hooked_PassiveBase_GetExpectedAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target) {
    int32_t returnValue = original_PassiveBase_GetExpectedAttackHpDmgAdder(__this, target);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedAttackHpDmgAdder(returnValue, target);
    }
    return returnValue;
}

// C#: System.Int32 GetAttackDmgAdder(BattleActionModel action, BattleUnitModel target)
int32_t hooked_PassiveBase_GetAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) {
    int32_t returnValue = original_PassiveBase_GetAttackDmgAdder(__this, action, target);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttackDmgAdder(returnValue, action, target);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackDmgAdder(BattleActionModel action, BattleUnitModel targetOrNull)
int32_t hooked_PassiveBase_GetExpectedAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull) {
    int32_t returnValue = original_PassiveBase_GetExpectedAttackDmgAdder(__this, action, targetOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedAttackDmgAdder(returnValue, action, targetOrNull);
    }
    return returnValue;
}

// C#: System.Single GetAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical)
float hooked_PassiveBase_GetAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical) {
    float returnValue = original_PassiveBase_GetAttackDmgMultiplier(__this, action, coin, target, isWinDuel, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttackDmgMultiplier(returnValue, action, coin, target, isWinDuel, isCritical);
    }
    return returnValue;
}

// C#: System.Single GetExpectedAttackDmgMultiplier(BattleActionModel action, CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
float hooked_PassiveBase_GetExpectedAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    float returnValue = original_PassiveBase_GetExpectedAttackDmgMultiplier(__this, action, coin, targetOrNull, targetSinActionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedAttackDmgMultiplier(returnValue, action, coin, targetOrNull, targetSinActionOrNull);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t hooked_PassiveBase_GetTakeAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    int32_t returnValue = original_PassiveBase_GetTakeAttackDmgAdder(__this, action, attacker);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeAttackDmgAdder(returnValue, action, attacker);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedTakeAttackDmgAdder(BattleActionModel action, BattleUnitModel attacker)
int32_t hooked_PassiveBase_GetExpectedTakeAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    int32_t returnValue = original_PassiveBase_GetExpectedTakeAttackDmgAdder(__this, action, attacker);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedTakeAttackDmgAdder(returnValue, action, attacker);
    }
    return returnValue;
}

// C#: System.Single GetTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker, System.Boolean isCritical)
float hooked_PassiveBase_GetTakeAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker, bool isCritical) {
    float returnValue = original_PassiveBase_GetTakeAttackDmgMultiplier(__this, action, attacker, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeAttackDmgMultiplier(returnValue, action, attacker, isCritical);
    }
    return returnValue;
}

// C#: System.Single GetExpectedTakeAttackDmgMultiplier(BattleActionModel action, BattleUnitModel attacker)
float hooked_PassiveBase_GetExpectedTakeAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* attacker) {
    float returnValue = original_PassiveBase_GetExpectedTakeAttackDmgMultiplier(__this, action, attacker);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedTakeAttackDmgMultiplier(returnValue, action, attacker);
    }
    return returnValue;
}

// C#: System.Int32 GetAttackAdder(BattleActionModel actionOrNull)
int32_t hooked_PassiveBase_GetAttackAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull) {
    int32_t returnValue = original_PassiveBase_GetAttackAdder(__this, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttackAdder(returnValue, actionOrNull);
    }
    return returnValue;
}

// C#: System.Int32 GetUnitDefaultLevelAdder()
int32_t hooked_PassiveBase_GetUnitDefaultLevelAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetUnitDefaultLevelAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetUnitDefaultLevelAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetDefenseAdder()
int32_t hooked_PassiveBase_GetDefenseAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetDefenseAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetDefenseAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetUnitDefenseAdder()
int32_t hooked_PassiveBase_GetUnitDefenseAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetUnitDefenseAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetUnitDefenseAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetDefenseMultiplier()
float hooked_PassiveBase_GetDefenseMultiplier(il2cpp::Il2CppObject* __this) {
    float returnValue = original_PassiveBase_GetDefenseMultiplier(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetDefenseMultiplier(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetHpHealMultiplier(BattleUnitModel target)
float hooked_PassiveBase_GetHpHealMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target) {
    float returnValue = original_PassiveBase_GetHpHealMultiplier(__this, target);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetHpHealMultiplier(returnValue, target);
    }
    return returnValue;
}

// C#: System.Single GetAtkResistMultiplier(ATK_BEHAVIOUR type)
float hooked_PassiveBase_GetAtkResistMultiplier(il2cpp::Il2CppObject* __this, int32_t type) {
    float returnValue = original_PassiveBase_GetAtkResistMultiplier(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAtkResistMultiplier(returnValue, type);
    }
    return returnValue;
}

// C#: System.Single GetAtkResistAdder(ATK_BEHAVIOUR type)
float hooked_PassiveBase_GetAtkResistAdder(il2cpp::Il2CppObject* __this, int32_t type) {
    float returnValue = original_PassiveBase_GetAtkResistAdder(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAtkResistAdder(returnValue, type);
    }
    return returnValue;
}

// C#: System.Single GetAttributeResistMultiplier(ATTRIBUTE_TYPE type)
float hooked_PassiveBase_GetAttributeResistMultiplier(il2cpp::Il2CppObject* __this, int32_t type) {
    float returnValue = original_PassiveBase_GetAttributeResistMultiplier(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttributeResistMultiplier(returnValue, type);
    }
    return returnValue;
}

// C#: System.Single GetAttributeResistAdder(ATTRIBUTE_TYPE type)
float hooked_PassiveBase_GetAttributeResistAdder(il2cpp::Il2CppObject* __this, int32_t type) {
    float returnValue = original_PassiveBase_GetAttributeResistAdder(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetAttributeResistAdder(returnValue, type);
    }
    return returnValue;
}

// C#: System.Void OnDie(BattleUnitModel killer, BattleActionModel actionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDie(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* actionOrNull, int32_t dmgSrcType, int32_t keyword, int32_t timing) {
    original_PassiveBase_OnDie(__this, killer, actionOrNull, dmgSrcType, keyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDie(killer, actionOrNull, dmgSrcType, keyword, timing);
    }
}

// C#: System.Void OnBreak(BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void hooked_PassiveBase_OnBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t timing, bool isBreakForcely) {
    original_PassiveBase_OnBreak(__this, attackerOrNull, actionOrNull, timing, isBreakForcely);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBreak(attackerOrNull, actionOrNull, timing, isBreakForcely);
    }
}

// C#: System.Void OnEnemyBrokenByAttacker(BattleActionModel actionOrNull, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEnemyBrokenByAttacker(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t timing) {
    original_PassiveBase_OnEnemyBrokenByAttacker(__this, actionOrNull, target, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEnemyBrokenByAttacker(actionOrNull, target, timing);
    }
}

// C#: System.Void OnDieOtherUnit(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnDieOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    original_PassiveBase_OnDieOtherUnit(__this, killer, dead, timing, dmgSrcType, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDieOtherUnit(killer, dead, timing, dmgSrcType, keyword);
    }
}

// C#: System.Void OnDieOtherUnit_Retreated(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnDieOtherUnit_Retreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    original_PassiveBase_OnDieOtherUnit_Retreated(__this, killer, dead, timing, dmgSrcType, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDieOtherUnit_Retreated(killer, dead, timing, dmgSrcType, keyword);
    }
}

// C#: System.Void OnDieOtherUnit_Disappeared(BattleUnitModel killer, BattleUnitModel dead, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE dmgSrcType, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnDieOtherUnit_Disappeared(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* killer, il2cpp::Il2CppObject* dead, int32_t timing, int32_t dmgSrcType, int32_t keyword) {
    original_PassiveBase_OnDieOtherUnit_Disappeared(__this, killer, dead, timing, dmgSrcType, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDieOtherUnit_Disappeared(killer, dead, timing, dmgSrcType, keyword);
    }
}

// C#: System.Void OnRetreatOtherUnit(BattleUnitModel retreatUnit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRetreatOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* retreatUnit, int32_t keyword, int32_t timing) {
    original_PassiveBase_OnRetreatOtherUnit(__this, retreatUnit, keyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRetreatOtherUnit(retreatUnit, keyword, timing);
    }
}

// C#: System.Void OnRetreatOtherUnit_Retreated(BattleUnitModel retreatUnit, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRetreatOtherUnit_Retreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* retreatUnit, int32_t timing) {
    original_PassiveBase_OnRetreatOtherUnit_Retreated(__this, retreatUnit, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRetreatOtherUnit_Retreated(retreatUnit, timing);
    }
}

// C#: System.Void OnDiscardSinOtherUnit(BattleUnitModel discardUnit, UnitSinModel sin, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnDiscardSinOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* discardUnit, il2cpp::Il2CppObject* sin, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnDiscardSinOtherUnit(__this, discardUnit, sin, timing, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDiscardSinOtherUnit(discardUnit, sin, timing, actionOrNull);
    }
}

// C#: System.Void OnDiscardSin(UnitSinModel sin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDiscardSin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sin, int32_t timing) {
    original_PassiveBase_OnDiscardSin(__this, sin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDiscardSin(sin, timing);
    }
}

// C#: System.Void OnDisappeared(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDisappeared(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnDisappeared(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDisappeared(timing);
    }
}

// C#: System.Void OnReturnFromDisappeared(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnReturnFromDisappeared(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnReturnFromDisappeared(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReturnFromDisappeared(timing);
    }
}

// C#: System.Void OnBreakOtherUnit(BattleUnitModel breakedUnit, BATTLE_EVENT_TIMING timing, System.Boolean isBreakForcely)
void hooked_PassiveBase_OnBreakOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedUnit, int32_t timing, bool isBreakForcely) {
    original_PassiveBase_OnBreakOtherUnit(__this, breakedUnit, timing, isBreakForcely);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBreakOtherUnit(breakedUnit, timing, isBreakForcely);
    }
}

// C#: System.Void OnCheckBreak(System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void hooked_PassiveBase_OnCheckBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {
    original_PassiveBase_OnCheckBreak(__this, usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnCheckBreak(usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
    }
}

// C#: System.Void OnCheckPartBreak(BattleUnitModel_Abnormality_Part breakedPart, System.Collections.Generic.List<BreakSection> usedSections, BATTLE_EVENT_TIMING timing, BattleUnitModel attacker, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Int32 hpDmg, DAMAGE_SOURCE_TYPE dmgSrcType)
void hooked_PassiveBase_OnCheckPartBreak(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* breakedPart, il2cpp::Il2CppObject* usedSections, int32_t timing, il2cpp::Il2CppObject* attacker, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, int32_t hpDmg, int32_t dmgSrcType) {
    original_PassiveBase_OnCheckPartBreak(__this, breakedPart, usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnCheckPartBreak(breakedPart, usedSections, timing, attacker, attackerActionOrNull, attackerCoinOrNull, hpDmg, dmgSrcType);
    }
}

// C#: System.Void OnVibrationExplosion(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnVibrationExplosion(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {
    original_PassiveBase_OnVibrationExplosion(__this, explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnVibrationExplosion(explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
    }
}

// C#: System.Void OnVibrationExplosionOtherUnit(BattleUnitModel explodedUnit, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, ABILITY_SOURCE_TYPE abilitySrc, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnVibrationExplosionOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* explodedUnit, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t abilitySrc, int32_t timing) {
    original_PassiveBase_OnVibrationExplosionOtherUnit(__this, explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnVibrationExplosionOtherUnit(explodedUnit, giverOrNull, actionOrNull, abilitySrc, timing);
    }
}

// C#: System.Void OnTakeAttackDamageOtherUnit(BattleActionModel action, System.Int32 realDmg, System.Int32 hpDmg, BattleUnitModel attackedUnit, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnTakeAttackDamageOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t realDmg, int32_t hpDmg, il2cpp::Il2CppObject* attackedUnit, int32_t timing) {
    original_PassiveBase_OnTakeAttackDamageOtherUnit(__this, action, realDmg, hpDmg, attackedUnit, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeAttackDamageOtherUnit(action, realDmg, hpDmg, attackedUnit, timing);
    }
}

// C#: System.Void OnUseBuffStackBySkill(BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnUseBuffStackBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t keyword, int32_t stack, int32_t timing) {
    original_PassiveBase_OnUseBuffStackBySkill(__this, action, keyword, stack, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnUseBuffStackBySkill(action, keyword, stack, timing);
    }
}

// C#: System.Void OnUseBloodDinnerUnit(BattleUnitModel usedUnit, System.Int32 stack, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnUseBloodDinnerUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* usedUnit, int32_t stack, int32_t timing) {
    original_PassiveBase_OnUseBloodDinnerUnit(__this, usedUnit, stack, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnUseBloodDinnerUnit(usedUnit, stack, timing);
    }
}

// C#: System.Void OnAddUnit(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAddUnit(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnAddUnit(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddUnit(timing);
    }
}

// C#: System.Void OnAddUnit_After(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAddUnit_After(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnAddUnit_After(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddUnit_After(timing);
    }
}

// C#: System.Void OnAddUnitPart(BattleUnitModel part, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAddUnitPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing) {
    original_PassiveBase_OnAddUnitPart(__this, part, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddUnitPart(part, timing);
    }
}

// C#: System.Void Init_After()
void hooked_PassiveBase_Init_After(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_Init_After(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->Init_After();
    }
}

// C#: System.Void OnAddUnitView(BattleUnitView view)
void hooked_PassiveBase_OnAddUnitView(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* view) {
    original_PassiveBase_OnAddUnitView(__this, view);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddUnitView(view);
    }
}

// C#: System.Void OnStageStart(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStageStart(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnStageStart(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    MYO_LOG("PassiveBase", "Does this run? Address: {}, Exists: {}", __this, PassiveBaseMap.contains(__this));
    if (it != PassiveBaseMap.end()) {
        MYO_LOG("PassiveBase", "It exists. Running something or other.");
        it->second->OnStageStart(timing);
    }
}

// C#: System.Void OnWaveStart(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnWaveStart(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnWaveStart(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnWaveStart(timing);
    }
}

// C#: System.Void OnPanicOrLowMorale(PANIC_LEVEL level, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnPanicOrLowMorale(il2cpp::Il2CppObject* __this, int32_t level, int32_t timing) {
    original_PassiveBase_OnPanicOrLowMorale(__this, level, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPanicOrLowMorale(level, timing);
    }
}

// C#: System.Void OnRoundStart_Before()
void hooked_PassiveBase_OnRoundStart_Before(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnRoundStart_Before(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundStart_Before();
    }
}

// C#: System.Void OnRoundStart()
void hooked_PassiveBase_OnRoundStart(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnRoundStart(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundStart();
    }
}

// C#: System.Void OnRoundStart_After_Event(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRoundStart_After_Event(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRoundStart_After_Event(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundStart_After_Event(timing);
    }
}

// C#: System.Void OnRoundStart_After_Event_DeadOrRetreated(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundStart_After_Event_DeadOrRetreated(timing);
    }
}

// C#: System.Void OnRoundStart_After_RelatedSlotState(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRoundStart_After_RelatedSlotState(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRoundStart_After_RelatedSlotState(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundStart_After_RelatedSlotState(timing);
    }
}

// C#: System.Void OnReturnToField(System.Int32 retreatTurn, BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnReturnToField(il2cpp::Il2CppObject* __this, int32_t retreatTurn, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {
    original_PassiveBase_OnReturnToField(__this, retreatTurn, triggerUnit, retreatKeyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReturnToField(retreatTurn, triggerUnit, retreatKeyword, timing);
    }
}

// C#: System.Void OnReturnToFieldOtherUnit(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnReturnToFieldOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {
    original_PassiveBase_OnReturnToFieldOtherUnit(__this, returnUnit, retreatTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReturnToFieldOtherUnit(returnUnit, retreatTurn, timing);
    }
}

// C#: System.Void OnReturnToFieldOtherUnit_DeadOrRetreated(BattleUnitModel returnUnit, System.Int32 retreatTurn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* returnUnit, int32_t retreatTurn, int32_t timing) {
    original_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated(__this, returnUnit, retreatTurn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReturnToFieldOtherUnit_DeadOrRetreated(returnUnit, retreatTurn, timing);
    }
}

// C#: System.Void OnReleaseStandByOtherUnit_DeadOrRetreated(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void hooked_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {
    original_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated(__this, addedUnit, addedUnitList);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReleaseStandByOtherUnit_DeadOrRetreated(addedUnit, addedUnitList);
    }
}

// C#: System.Void OnReleaseStandByOtherUnit(BattleUnitModel addedUnit, System.Collections.Generic.List<BattleUnitModel> addedUnitList)
void hooked_PassiveBase_OnReleaseStandByOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedUnit, il2cpp::Il2CppObject* addedUnitList) {
    original_PassiveBase_OnReleaseStandByOtherUnit(__this, addedUnit, addedUnitList);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReleaseStandByOtherUnit(addedUnit, addedUnitList);
    }
}

// C#: System.Void OnReleaseStandBy(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnReleaseStandBy(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnReleaseStandBy(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReleaseStandBy(timing);
    }
}

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnCompleteCommand(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnCompleteCommand(timing);
    }
}

// C#: System.Boolean BeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
bool hooked_PassiveBase_BeforeCompleteCommand(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing, int32_t* newSkillID) {
    bool returnValue = original_PassiveBase_BeforeCompleteCommand(__this, action, timing, newSkillID);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->BeforeCompleteCommand(returnValue, action, timing, newSkillID);
    }
    return returnValue;
}

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnChangeSkillBeforeCompleteCommand(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnChangeSkillBeforeCompleteCommand(action, timing);
    }
}

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRoundEnd(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundEnd(timing);
    }
}

// C#: System.Void OnRoundEnd_Disappeared(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRoundEnd_Disappeared(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRoundEnd_Disappeared(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundEnd_Disappeared(timing);
    }
}

// C#: System.Void OnRetreat(BattleUnitModel triggerUnit, BUFF_UNIQUE_KEYWORD retreatKeyword, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRetreat(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* triggerUnit, int32_t retreatKeyword, int32_t timing) {
    original_PassiveBase_OnRetreat(__this, triggerUnit, retreatKeyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRetreat(triggerUnit, retreatKeyword, timing);
    }
}

// C#: System.Void OnRoundEnd_After()
void hooked_PassiveBase_OnRoundEnd_After(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnRoundEnd_After(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRoundEnd_After();
    }
}

// C#: System.Void OnStageEnd()
void hooked_PassiveBase_OnStageEnd(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnStageEnd(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStageEnd();
    }
}

// C#: System.Void OnBeforeDefense(BattleActionModel action)
void hooked_PassiveBase_OnBeforeDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    original_PassiveBase_OnBeforeDefense(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBeforeDefense(action);
    }
}

// C#: System.Void OnStartRunBattle()
void hooked_PassiveBase_OnStartRunBattle(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnStartRunBattle(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartRunBattle();
    }
}

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnBattleStart(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnBattleStart(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBattleStart(timing);
    }
}

// C#: System.Void OnBattleEnd(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnBattleEnd(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnBattleEnd(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBattleEnd(timing);
    }
}

// C#: System.Void OnBeforeTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnBeforeTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnBeforeTurn(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBeforeTurn(action, timing);
    }
}

// C#: System.Void OnStartTurn_BeforeLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartTurn_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnStartTurn_BeforeLog(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartTurn_BeforeLog(action, timing);
    }
}

// C#: System.Void OnStartTurn_AfterLog(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartTurn_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnStartTurn_AfterLog(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartTurn_AfterLog(action, timing);
    }
}

// C#: System.Void OnStartDuel(BattleActionModel ownerAction, BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ownerAction, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    original_PassiveBase_OnStartDuel(__this, ownerAction, opponentAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartDuel(ownerAction, opponentAction, timing);
    }
}

// C#: System.Void BeforeGiveAttackDamage(BattleActionModel action, CoinModel coin, BattleUnitModel target, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_BeforeGiveAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    original_PassiveBase_BeforeGiveAttackDamage(__this, action, coin, target, isCritical, isWinDuel, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->BeforeGiveAttackDamage(action, coin, target, isCritical, isWinDuel, timing);
    }
}

// C#: System.Void BeforeTakeAttackDamage(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_BeforeTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_BeforeTakeAttackDamage(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->BeforeTakeAttackDamage(action, timing);
    }
}

// C#: System.Void BeforePartTakeAttackDamage(BattleUnitModel_Abnormality abnormality, BattleUnitModel_Abnormality_Part part, BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_BeforePartTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* abnormality, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_BeforePartTakeAttackDamage(__this, abnormality, part, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->BeforePartTakeAttackDamage(abnormality, part, action, timing);
    }
}

// C#: System.Void OnTakeAttackDamage(BattleActionModel action, CoinModel coin, System.Int32 totalDmg, System.Int32 hpDmg, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnTakeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t totalDmg, int32_t hpDmg, int32_t timing) {
    original_PassiveBase_OnTakeAttackDamage(__this, action, coin, totalDmg, hpDmg, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeAttackDamage(action, coin, totalDmg, hpDmg, timing);
    }
}

// C#: System.Void OnTakeAttackDamagePart(BattleUnitModel_Abnormality_Part part, BattleActionModel attackerAction, CoinModel coin, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
void hooked_PassiveBase_OnTakeAttackDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* coin, int32_t value, int32_t timing, bool isCritical) {
    original_PassiveBase_OnTakeAttackDamagePart(__this, part, attackerAction, coin, value, timing, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeAttackDamagePart(part, attackerAction, coin, value, timing, isCritical);
    }
}

// C#: System.Void OnGiveHpDamage(BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnGiveHpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t value, int32_t timing) {
    original_PassiveBase_OnGiveHpDamage(__this, target, value, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnGiveHpDamage(target, value, timing);
    }
}

// C#: System.Void OnGiveMpDamage(BattleUnitModel target, System.Int32 value)
void hooked_PassiveBase_OnGiveMpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t value) {
    original_PassiveBase_OnGiveMpDamage(__this, target, value);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnGiveMpDamage(target, value);
    }
}

// C#: System.Void OnTakeMpDmg_SinBuff(System.Int32 value, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnTakeMpDmg_SinBuff(il2cpp::Il2CppObject* __this, int32_t value, int32_t timing, int32_t keyword) {
    original_PassiveBase_OnTakeMpDmg_SinBuff(__this, value, timing, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeMpDmg_SinBuff(value, timing, keyword);
    }
}

// C#: System.Void OnKillTarget(BattleActionModel actionOrNull, BattleUnitModel target, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnKillTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* target, int32_t dmgSrcType, int32_t timing) {
    original_PassiveBase_OnKillTarget(__this, actionOrNull, target, dmgSrcType, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnKillTarget(actionOrNull, target, dmgSrcType, timing);
    }
}

// C#: System.Void OnEndTurn(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnEndTurn(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndTurn(action, timing);
    }
}

// C#: System.Void OnBeforeStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnBeforeStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    original_PassiveBase_OnBeforeStartCoin(__this, action, coin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBeforeStartCoin(action, coin, timing);
    }
}

// C#: System.Void OnStartCoin(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    original_PassiveBase_OnStartCoin(__this, action, coin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartCoin(action, coin, timing);
    }
}

// C#: System.Void OnEndCoin_BeforeLog(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndCoin_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    original_PassiveBase_OnEndCoin_BeforeLog(__this, action, coin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndCoin_BeforeLog(action, coin, timing);
    }
}

// C#: System.Void OnEndCoin_AfterLog(BattleActionModel action, CoinModel coin)
void hooked_PassiveBase_OnEndCoin_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    original_PassiveBase_OnEndCoin_AfterLog(__this, action, coin);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndCoin_AfterLog(action, coin);
    }
}

// C#: System.Void OnEndBehaviour(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnEndBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_OnEndBehaviour(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndBehaviour(action, timing);
    }
}

// C#: System.Void OnEndBehave_Refresh(BattleActionModel action)
void hooked_PassiveBase_OnEndBehave_Refresh(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    original_PassiveBase_OnEndBehave_Refresh(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnEndBehave_Refresh(action);
    }
}

// C#: System.Void OnCriticalActivated(BattleActionModel action, CoinModel coin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnCriticalActivated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t timing) {
    original_PassiveBase_OnCriticalActivated(__this, action, coin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnCriticalActivated(action, coin, timing);
    }
}

// C#: System.Void BeforeAttack(BattleActionModel action, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_BeforeAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t timing) {
    original_PassiveBase_BeforeAttack(__this, action, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->BeforeAttack(action, timing);
    }
}

// C#: System.Void OnAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing) {
    original_PassiveBase_OnAttackConfirmed(__this, action, coin, target, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAttackConfirmed(action, coin, target, timing);
    }
}

// C#: System.Boolean CanTeamKill(BattleActionModel action)
bool hooked_PassiveBase_CanTeamKill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    bool returnValue = original_PassiveBase_CanTeamKill(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanTeamKill(returnValue, action);
    }
    return returnValue;
}

// C#: System.Collections.Generic.List<PrimeTargetData> GetPrimeTargets(BattleActionModel action)
il2cpp::Il2CppObject* hooked_PassiveBase_GetPrimeTargets(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_GetPrimeTargets(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetPrimeTargets(returnValue, action);
    }
    return returnValue;
}

// C#: System.Int32 GetSkillPowerAdder(BattleActionModel action, COIN_ROLL_TYPE rollType)
int32_t hooked_PassiveBase_GetSkillPowerAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t rollType) {
    int32_t returnValue = original_PassiveBase_GetSkillPowerAdder(__this, action, rollType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetSkillPowerAdder(returnValue, action, rollType);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerResultAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, BattleUnitModel expectedTarget)
int32_t hooked_PassiveBase_GetExpectedSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, il2cpp::Il2CppObject* expectedTarget) {
    int32_t returnValue = original_PassiveBase_GetExpectedSkillPowerResultAdder(__this, action, prevActions, expectedTarget);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedSkillPowerResultAdder(returnValue, action, prevActions, expectedTarget);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerAdder(BattleActionModel action, System.Collections.Generic.List<BattleActionModel> prevActions, COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
int32_t hooked_PassiveBase_GetExpectedSkillPowerAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* prevActions, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    int32_t returnValue = original_PassiveBase_GetExpectedSkillPowerAdder(__this, action, prevActions, rollType, expectedTargetSinActionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedSkillPowerAdder(returnValue, action, prevActions, rollType, expectedTargetSinActionOrNull);
    }
    return returnValue;
}

// C#: System.Boolean HasPassive(System.Int32 passiveID)
bool hooked_PassiveBase_HasPassive(il2cpp::Il2CppObject* __this, int32_t passiveID) {
    bool returnValue = original_PassiveBase_HasPassive(__this, passiveID);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->HasPassive(returnValue, passiveID);
    }
    return returnValue;
}

// C#: System.Void OnStartPhase(PHASE phase, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnStartPhase(il2cpp::Il2CppObject* __this, int32_t phase, int32_t timing) {
    original_PassiveBase_OnStartPhase(__this, phase, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnStartPhase(phase, timing);
    }
}

// C#: System.Boolean HasFakeDead()
bool hooked_PassiveBase_HasFakeDead(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_HasFakeDead(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->HasFakeDead(returnValue);
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAtkResist_Default(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResist_Default(il2cpp::Il2CppObject* __this, int32_t type) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteAtkResist_Default(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteAtkResist_Default(returnValue, type);
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAtkResist_Result(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResist_Result(il2cpp::Il2CppObject* __this, int32_t type) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteAtkResist_Result(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteAtkResist_Result(returnValue, type);
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAttributeDefaultResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAttributeDefaultResist(il2cpp::Il2CppObject* __this, int32_t type) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteAttributeDefaultResist(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteAttributeDefaultResist(returnValue, type);
    }
    return returnValue;
}

// C#: System.Nullable<System.Single> OverwriteAttributeResist(ATTRIBUTE_TYPE type)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAttributeResist(il2cpp::Il2CppObject* __this, int32_t type) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteAttributeResist(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteAttributeResist(returnValue, type);
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteMaxBuffStack(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteMaxBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteMaxBuffStack(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteMaxBuffStack(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteMaxBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteMaxBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteMaxBuffTurn(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteMaxBuffTurn(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteSkillID(System.Int32 originID)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteSkillID(il2cpp::Il2CppObject* __this, int32_t originID) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteSkillID(__this, originID);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteSkillID(returnValue, originID);
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwriteSpeed(System.Int32 speed)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteSpeed(il2cpp::Il2CppObject* __this, int32_t speed) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteSpeed(__this, speed);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteSpeed(returnValue, speed);
    }
    return returnValue;
}

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleUnitModel unit, BattleActionModel selfAction, BattleActionModel oppoAction)
bool hooked_PassiveBase_CanChangeMainTargetRegardlessSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* oppoAction) {
    bool returnValue = original_PassiveBase_CanChangeMainTargetRegardlessSpeed(__this, unit, selfAction, oppoAction);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanChangeMainTargetRegardlessSpeed(returnValue, unit, selfAction, oppoAction);
    }
    return returnValue;
}

// C#: System.Void OnZeroHp()
void hooked_PassiveBase_OnZeroHp(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnZeroHp(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnZeroHp();
    }
}

// C#: System.Int32 GetParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
int32_t hooked_PassiveBase_GetParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) {
    int32_t returnValue = original_PassiveBase_GetParryingResultAdder(__this, action, actorResult, oppoAction, oppoResult, parryingCount);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult, parryingCount);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
int32_t hooked_PassiveBase_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
    int32_t returnValue = original_PassiveBase_GetExpectedParryingResultAdder(__this, action, actorResult, oppoActionOrNull, oppoResult);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedParryingResultAdder(returnValue, action, actorResult, oppoActionOrNull, oppoResult);
    }
    return returnValue;
}

// C#: System.Int32 GetOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t hooked_PassiveBase_GetOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    int32_t returnValue = original_PassiveBase_GetOpponentParryingResultAdder(__this, action, actorResult, oppoAction, oppoResult);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetOpponentParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult);
    }
    return returnValue;
}

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(BattleActionModel action, System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t hooked_PassiveBase_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    int32_t returnValue = original_PassiveBase_GetExpectedOpponentParryingResultAdder(__this, action, actorResult, oppoAction, oppoResult);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetExpectedOpponentParryingResultAdder(returnValue, action, actorResult, oppoAction, oppoResult);
    }
    return returnValue;
}

// C#: System.Void ActivateEgoPassive(System.Int32 egoId)
void hooked_PassiveBase_ActivateEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId) {
    original_PassiveBase_ActivateEgoPassive(__this, egoId);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->ActivateEgoPassive(egoId);
    }
}

// C#: System.Void ActivateEquipEgoPassives()
void hooked_PassiveBase_ActivateEquipEgoPassives(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_ActivateEquipEgoPassives(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->ActivateEquipEgoPassives();
    }
}

// C#: System.Void ActivateEgoPassives(BattleEgoModel ego, System.Collections.Generic.List<System.Int32> passiveIdList, System.Boolean isEquipEgoPassive)
void hooked_PassiveBase_ActivateEgoPassives(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ego, il2cpp::Il2CppObject* passiveIdList, bool isEquipEgoPassive) {
    original_PassiveBase_ActivateEgoPassives(__this, ego, passiveIdList, isEquipEgoPassive);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->ActivateEgoPassives(ego, passiveIdList, isEquipEgoPassive);
    }
}

// C#: System.Collections.Generic.List<BattleEgoModel> GetOwnerEgoModelList()
il2cpp::Il2CppObject* hooked_PassiveBase_GetOwnerEgoModelList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_GetOwnerEgoModelList(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetOwnerEgoModelList(returnValue);
    }
    return returnValue;
}

// C#: BattleEgoModel FindEgoModel(System.Int32 egoId)
il2cpp::Il2CppObject* hooked_PassiveBase_FindEgoModel(il2cpp::Il2CppObject* __this, int32_t egoId) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_FindEgoModel(__this, egoId);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->FindEgoModel(returnValue, egoId);
    }
    return returnValue;
}

// C#: System.Void AddReadyEgoPassive(System.Int32 egoId)
void hooked_PassiveBase_AddReadyEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId) {
    original_PassiveBase_AddReadyEgoPassive(__this, egoId);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->AddReadyEgoPassive(egoId);
    }
}

// C#: System.Boolean CanAddEgoPassive(System.Int32 egoId)
bool hooked_PassiveBase_CanAddEgoPassive(il2cpp::Il2CppObject* __this, int32_t egoId) {
    bool returnValue = original_PassiveBase_CanAddEgoPassive(__this, egoId);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanAddEgoPassive(returnValue, egoId);
    }
    return returnValue;
}

// C#: System.Boolean PassesCondition(PassiveStaticData passiveData, BattleEgoModel ego)
bool hooked_PassiveBase_PassesCondition(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* passiveData, il2cpp::Il2CppObject* ego) {
    bool returnValue = original_PassiveBase_PassesCondition(__this, passiveData, ego);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->PassesCondition(returnValue, passiveData, ego);
    }
    return returnValue;
}

// C#: System.Void OnResult_OnAction(BattleActionModel action, CoinModel coin)
void hooked_PassiveBase_OnResult_OnAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin) {
    original_PassiveBase_OnResult_OnAction(__this, action, coin);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnResult_OnAction(action, coin);
    }
}

// C#: System.Void OnResult_OnParrying(BattleActionModel action, BattleActionModel oppoAction, CoinModel coin)
void hooked_PassiveBase_OnResult_OnParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* coin) {
    original_PassiveBase_OnResult_OnParrying(__this, action, oppoAction, coin);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnResult_OnParrying(action, oppoAction, coin);
    }
}

// C#: System.Void AddPassive(PassiveModel passiveModel)
void hooked_PassiveBase_AddPassive(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* passiveModel) {
    original_PassiveBase_AddPassive(__this, passiveModel);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->AddPassive(passiveModel);
    }
}

// C#: System.Boolean IsRegeneratable()
bool hooked_PassiveBase_IsRegeneratable(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_IsRegeneratable(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsRegeneratable(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean SpreadHpDmgToAbnormality(System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool hooked_PassiveBase_SpreadHpDmgToAbnormality(il2cpp::Il2CppObject* __this, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) {
    bool returnValue = original_PassiveBase_SpreadHpDmgToAbnormality(__this, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->SpreadHpDmgToAbnormality(returnValue, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
    }
    return returnValue;
}

// C#: System.Boolean SpreadHpDmgFromAbnormalityPart(AB_PART_TYPE partType, System.Int32 value, BattleUnitModel attackerOrNull, BattleActionModel attackerActionOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BUFF_UNIQUE_KEYWORD keyword)
bool hooked_PassiveBase_SpreadHpDmgFromAbnormalityPart(il2cpp::Il2CppObject* __this, int32_t partType, int32_t value, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* attackerActionOrNull, int32_t dmgSrcType, int32_t timing, int32_t keyword) {
    bool returnValue = original_PassiveBase_SpreadHpDmgFromAbnormalityPart(__this, partType, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->SpreadHpDmgFromAbnormalityPart(returnValue, partType, value, attackerOrNull, attackerActionOrNull, dmgSrcType, timing, keyword);
    }
    return returnValue;
}

// C#: System.Void OnSucceedEvade(BattleActionModel evadeAction, BattleActionModel attackAction, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnSucceedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* evadeAction, il2cpp::Il2CppObject* attackAction, int32_t timing) {
    original_PassiveBase_OnSucceedEvade(__this, evadeAction, attackAction, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnSucceedEvade(evadeAction, attackAction, timing);
    }
}

// C#: System.Void OnGiveBuffTrigger(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnGiveBuffTrigger(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t timing) {
    original_PassiveBase_OnGiveBuffTrigger(__this, target, keyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnGiveBuffTrigger(target, keyword, timing);
    }
}

// C#: System.Void RightBeforeLosingBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightBeforeLosingBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    original_PassiveBase_RightBeforeLosingBuff(__this, keyword, stack, turn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightBeforeLosingBuff(keyword, stack, turn, timing);
    }
}

// C#: System.Boolean CanCreateEmptySlot()
bool hooked_PassiveBase_CanCreateEmptySlot(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_CanCreateEmptySlot(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanCreateEmptySlot(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean CanCreateEmptySlotPart(BattleUnitModel_Abnormality_Part part)
bool hooked_PassiveBase_CanCreateEmptySlotPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part) {
    bool returnValue = original_PassiveBase_CanCreateEmptySlotPart(__this, part);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanCreateEmptySlotPart(returnValue, part);
    }
    return returnValue;
}

// C#: System.Int32 GetActionSlotAdder()
int32_t hooked_PassiveBase_GetActionSlotAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetActionSlotAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetActionSlotAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Int32 GetMaxHpAdder()
int32_t hooked_PassiveBase_GetMaxHpAdder(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_PassiveBase_GetMaxHpAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxHpAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplier()
float hooked_PassiveBase_GetMaxHpMultiplier(il2cpp::Il2CppObject* __this) {
    float returnValue = original_PassiveBase_GetMaxHpMultiplier(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxHpMultiplier(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplierPartToAbnormality()
float hooked_PassiveBase_GetMaxHpMultiplierPartToAbnormality(il2cpp::Il2CppObject* __this) {
    float returnValue = original_PassiveBase_GetMaxHpMultiplierPartToAbnormality(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxHpMultiplierPartToAbnormality(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetMaxHpMultiplierContributionToAbnormality()
float hooked_PassiveBase_GetMaxHpMultiplierContributionToAbnormality(il2cpp::Il2CppObject* __this) {
    float returnValue = original_PassiveBase_GetMaxHpMultiplierContributionToAbnormality(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxHpMultiplierContributionToAbnormality(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean CanTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 mp, ABILITY_SOURCE_TYPE srcType)
bool hooked_PassiveBase_CanTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t mp, int32_t srcType) {
    bool returnValue = original_PassiveBase_CanTakeMpHeal(__this, healerOrNull, mp, srcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanTakeMpHeal(returnValue, healerOrNull, mp, srcType);
    }
    return returnValue;
}

// C#: System.Void OnAfterTryTakeHpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAfterTryTakeHpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    original_PassiveBase_OnAfterTryTakeHpHeal(__this, healerOrNull, tryHeal, resultHeal, srcType, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAfterTryTakeHpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
    }
}

// C#: System.Void OnBeforeTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnBeforeTryTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    original_PassiveBase_OnBeforeTryTakeMpHeal(__this, healerOrNull, tryHeal, resultHeal, srcType, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBeforeTryTakeMpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
    }
}

// C#: System.Void OnAfterTryTakeMpHeal(BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAfterTryTakeMpHeal(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    original_PassiveBase_OnAfterTryTakeMpHeal(__this, healerOrNull, tryHeal, resultHeal, srcType, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAfterTryTakeMpHeal(healerOrNull, tryHeal, resultHeal, srcType, timing);
    }
}

// C#: System.Boolean CheckImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool hooked_PassiveBase_CheckImmortal(il2cpp::Il2CppObject* __this, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) {
    bool returnValue = original_PassiveBase_CheckImmortal(__this, timing, newHp, isInstantDeath, buff, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckImmortal(returnValue, timing, newHp, isInstantDeath, buff, actionOrNull);
    }
    return returnValue;
}

// C#: System.Boolean CheckImmortalOtherUnit(BattleUnitModel checkTarget, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buf)
bool hooked_PassiveBase_CheckImmortalOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* checkTarget, int32_t newHp, bool isInstantDeath, int32_t buf) {
    bool returnValue = original_PassiveBase_CheckImmortalOtherUnit(__this, checkTarget, newHp, isInstantDeath, buf);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckImmortalOtherUnit(returnValue, checkTarget, newHp, isInstantDeath, buf);
    }
    return returnValue;
}

// C#: System.Void OnGiveImmortalState(BattleUnitModel immortalTaker, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnGiveImmortalState(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalTaker, int32_t timing) {
    original_PassiveBase_OnGiveImmortalState(__this, immortalTaker, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnGiveImmortalState(immortalTaker, timing);
    }
}

// C#: System.Void OnBeforeActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnBeforeActivateImmortality(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnBeforeActivateImmortality(__this, immortalActivator, timing, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBeforeActivateImmortality(immortalActivator, timing, actionOrNull);
    }
}

// C#: System.Void OnActivateImmortality(BattleUnitModel immortalActivator, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnActivateImmortality(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* immortalActivator, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnActivateImmortality(__this, immortalActivator, timing, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnActivateImmortality(immortalActivator, timing, actionOrNull);
    }
}

// C#: System.Void OnActivateAbnormalityImmortality(BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnActivateAbnormalityImmortality(il2cpp::Il2CppObject* __this, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnActivateAbnormalityImmortality(__this, timing, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnActivateAbnormalityImmortality(timing, actionOrNull);
    }
}

// C#: System.Void OnActivateOtherUnitBurstReactive(BUFF_UNIQUE_KEYWORD keyword, BattleUnitModel buffOwner, BattleActionModel actionOrNull, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnActivateOtherUnitBurstReactive(il2cpp::Il2CppObject* __this, int32_t keyword, il2cpp::Il2CppObject* buffOwner, il2cpp::Il2CppObject* actionOrNull, int32_t timing) {
    original_PassiveBase_OnActivateOtherUnitBurstReactive(__this, keyword, buffOwner, actionOrNull, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnActivateOtherUnitBurstReactive(keyword, buffOwner, actionOrNull, timing);
    }
}

// C#: System.Void OnBurstReactiveActivatedAnyUnit(BattleUnitModel buffOwner, BUFF_UNIQUE_KEYWORD keyword, System.Int32 loseStack, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull, BattleUnitModel giverOrNull)
void hooked_PassiveBase_OnBurstReactiveActivatedAnyUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffOwner, int32_t keyword, int32_t loseStack, int32_t timing, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* giverOrNull) {
    original_PassiveBase_OnBurstReactiveActivatedAnyUnit(__this, buffOwner, keyword, loseStack, timing, actionOrNull, giverOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnBurstReactiveActivatedAnyUnit(buffOwner, keyword, loseStack, timing, actionOrNull, giverOrNull);
    }
}

// C#: System.Void OnAddShield(BATTLE_EVENT_TIMING timing, System.Int32 value)
void hooked_PassiveBase_OnAddShield(il2cpp::Il2CppObject* __this, int32_t timing, int32_t value) {
    original_PassiveBase_OnAddShield(__this, timing, value);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddShield(timing, value);
    }
}

// C#: System.Void OnReduceShield(BATTLE_EVENT_TIMING timing, System.Int32 old, System.Int32 value, BattleUnitModel attackerOrNull)
void hooked_PassiveBase_OnReduceShield(il2cpp::Il2CppObject* __this, int32_t timing, int32_t old, int32_t value, il2cpp::Il2CppObject* attackerOrNull) {
    original_PassiveBase_OnReduceShield(__this, timing, old, value, attackerOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnReduceShield(timing, old, value, attackerOrNull);
    }
}

// C#: System.Void OnDestroyShield(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnDestroyShield(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnDestroyShield(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDestroyShield(timing);
    }
}

// C#: System.Void OnDestoryShieldPart(BattleUnitModel_Abnormality_Part part, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull)
void hooked_PassiveBase_OnDestoryShieldPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t timing, il2cpp::Il2CppObject* attackerOrNull) {
    original_PassiveBase_OnDestoryShieldPart(__this, part, timing, attackerOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnDestoryShieldPart(part, timing, attackerOrNull);
    }
}

// C#: System.Void OnRecoverBreak(BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnRecoverBreak(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_PassiveBase_OnRecoverBreak(__this, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRecoverBreak(timing);
    }
}

// C#: System.Void OnGiveBsGaugeUp(BattleUnitModel giver, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion, ABILITY_SOURCE_TYPE abilitySrc, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnGiveBsGaugeUp(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* giver, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion, int32_t abilitySrc, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnGiveBsGaugeUp(__this, giver, target, value, timing, onExplosion, abilitySrc, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnGiveBsGaugeUp(giver, target, value, timing, onExplosion, abilitySrc, actionOrNull);
    }
}

// C#: System.Void OnTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnTakeHpDamage(il2cpp::Il2CppObject* __this, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    original_PassiveBase_OnTakeHpDamage(__this, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeHpDamage(finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
    }
}

// C#: System.Void OnTakeHpDamagePart(BattleUnitModel_Abnormality_Part part, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnTakeHpDamagePart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    original_PassiveBase_OnTakeHpDamagePart(__this, part, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeHpDamagePart(part, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, keyword);
    }
}

// C#: System.Void OnTakeHpDamageOtherUnit(BattleUnitModel damaged, System.Int32 finalDamage, System.Int32 hpDamage, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, System.Collections.Generic.List<BattleUnitModel> relatedUnitsOrNull, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnTakeHpDamageOtherUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* damaged, int32_t finalDamage, int32_t hpDamage, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* relatedUnitsOrNull, int32_t keyword) {
    original_PassiveBase_OnTakeHpDamageOtherUnit(__this, damaged, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, relatedUnitsOrNull, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeHpDamageOtherUnit(damaged, finalDamage, hpDamage, timing, sourceType, attackerOrNull, actionOrNull, relatedUnitsOrNull, keyword);
    }
}

// C#: System.Void OnTryTakeHpDamage(System.Int32 finalDamage, System.Int32 hpDamage, BattleActionModel actionOrNull, BattleUnitModel attackerOrNull, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnTryTakeHpDamage(il2cpp::Il2CppObject* __this, int32_t finalDamage, int32_t hpDamage, il2cpp::Il2CppObject* actionOrNull, il2cpp::Il2CppObject* attackerOrNull, int32_t timing) {
    original_PassiveBase_OnTryTakeHpDamage(__this, finalDamage, hpDamage, actionOrNull, attackerOrNull, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTryTakeHpDamage(finalDamage, hpDamage, actionOrNull, attackerOrNull, timing);
    }
}

// C#: System.Single GetTakeHpHealMultiplier(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float hooked_PassiveBase_GetTakeHpHealMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    float returnValue = original_PassiveBase_GetTakeHpHealMultiplier(__this, healerOrNull, srcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeHpHealMultiplier(returnValue, healerOrNull, srcType);
    }
    return returnValue;
}

// C#: System.Void OnTakeAttackConfirmed(BattleActionModel action, CoinModel coin, BattleUnitModel attacker, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnTakeAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* attacker, int32_t timing) {
    original_PassiveBase_OnTakeAttackConfirmed(__this, action, coin, attacker, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeAttackConfirmed(action, coin, attacker, timing);
    }
}

// C#: System.Int32 GetMaxHpAdderPart(BattleUnitModel_Abnormality_Part part)
int32_t hooked_PassiveBase_GetMaxHpAdderPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part) {
    int32_t returnValue = original_PassiveBase_GetMaxHpAdderPart(__this, part);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetMaxHpAdderPart(returnValue, part);
    }
    return returnValue;
}

// C#: System.Single GetTakeHpHealMultiplierPart(BattleUnitModel_Abnormality_Part part, BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
float hooked_PassiveBase_GetTakeHpHealMultiplierPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    float returnValue = original_PassiveBase_GetTakeHpHealMultiplierPart(__this, part, healerOrNull, srcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeHpHealMultiplierPart(returnValue, part, healerOrNull, srcType);
    }
    return returnValue;
}

// C#: System.Int32 GetTakeHpHealAdder(BattleUnitModel healerOrNull, ABILITY_SOURCE_TYPE srcType)
int32_t hooked_PassiveBase_GetTakeHpHealAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* healerOrNull, int32_t srcType) {
    int32_t returnValue = original_PassiveBase_GetTakeHpHealAdder(__this, healerOrNull, srcType);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetTakeHpHealAdder(returnValue, healerOrNull, srcType);
    }
    return returnValue;
}

// C#: System.Void OverwriteTargetableList(System.Collections.Generic.List<SinActionModel> targetableSlotListOrNull, System.Collections.Generic.List<BattleUnitModel> origianlTargetList)
void hooked_PassiveBase_OverwriteTargetableList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetableSlotListOrNull, il2cpp::Il2CppObject* origianlTargetList) {
    original_PassiveBase_OverwriteTargetableList(__this, targetableSlotListOrNull, origianlTargetList);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OverwriteTargetableList(targetableSlotListOrNull, origianlTargetList);
    }
}

// C#: System.Nullable<System.Single> OverwriteAtkResistWhenDestroyed(ATK_BEHAVIOUR type)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteAtkResistWhenDestroyed(il2cpp::Il2CppObject* __this, int32_t type) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteAtkResistWhenDestroyed(__this, type);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteAtkResistWhenDestroyed(returnValue, type);
    }
    return returnValue;
}

// C#: System.Void OnChangeHp(System.Int32 oldHp, System.Int32 newHp, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel attackerOrNull, BattleActionModel actionOrNull, BUFF_UNIQUE_KEYWORD keyword)
void hooked_PassiveBase_OnChangeHp(il2cpp::Il2CppObject* __this, int32_t oldHp, int32_t newHp, int32_t dmgSrcType, int32_t timing, il2cpp::Il2CppObject* attackerOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t keyword) {
    original_PassiveBase_OnChangeHp(__this, oldHp, newHp, dmgSrcType, timing, attackerOrNull, actionOrNull, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnChangeHp(oldHp, newHp, dmgSrcType, timing, attackerOrNull, actionOrNull, keyword);
    }
}

// C#: System.Void OnChangeMp(System.Int32 oldMp, System.Int32 newMp)
void hooked_PassiveBase_OnChangeMp(il2cpp::Il2CppObject* __this, int32_t oldMp, int32_t newMp) {
    original_PassiveBase_OnChangeMp(__this, oldMp, newMp);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnChangeMp(oldMp, newMp);
    }
}

// C#: System.Void OnChangeMpOther(BattleUnitModel mpChangeUnit, System.Int32 oldMp, System.Int32 newMp)
void hooked_PassiveBase_OnChangeMpOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpChangeUnit, int32_t oldMp, int32_t newMp) {
    original_PassiveBase_OnChangeMpOther(__this, mpChangeUnit, oldMp, newMp);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnChangeMpOther(mpChangeUnit, oldMp, newMp);
    }
}

// C#: System.Void OnTakeMpDamage(BattleUnitModel attacker, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnTakeMpDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attacker, int32_t value, int32_t timing, int32_t sourceType, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnTakeMpDamage(__this, attacker, value, timing, sourceType, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeMpDamage(attacker, value, timing, sourceType, actionOrNull);
    }
}

// C#: System.Void OnTakeMpDamageOther(BattleUnitModel mpDmgUnit, BattleUnitModel attackerOrNull, System.Int32 value, BATTLE_EVENT_TIMING timing, DAMAGE_SOURCE_TYPE sourceType, BUFF_UNIQUE_KEYWORD buffKeyword, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnTakeMpDamageOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpDmgUnit, il2cpp::Il2CppObject* attackerOrNull, int32_t value, int32_t timing, int32_t sourceType, int32_t buffKeyword, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnTakeMpDamageOther(__this, mpDmgUnit, attackerOrNull, value, timing, sourceType, buffKeyword, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnTakeMpDamageOther(mpDmgUnit, attackerOrNull, value, timing, sourceType, buffKeyword, actionOrNull);
    }
}

// C#: System.Void OnAfterTryTakeMpHealOther(BattleUnitModel mpHealUnit, BattleUnitModel healerOrNull, System.Int32 tryHeal, System.Int32 resultHeal, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAfterTryTakeMpHealOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* mpHealUnit, il2cpp::Il2CppObject* healerOrNull, int32_t tryHeal, int32_t resultHeal, int32_t srcType, int32_t timing) {
    original_PassiveBase_OnAfterTryTakeMpHealOther(__this, mpHealUnit, healerOrNull, tryHeal, resultHeal, srcType, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAfterTryTakeMpHealOther(mpHealUnit, healerOrNull, tryHeal, resultHeal, srcType, timing);
    }
}

// C#: System.Void UnlockAllPassives()
void hooked_PassiveBase_UnlockAllPassives(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_UnlockAllPassives(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->UnlockAllPassives();
    }
}

// C#: System.Void OnUseBuffTurnBySkill(SkillModel skill, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnUseBuffTurnBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, int32_t bufKeyword, int32_t turn, int32_t timing) {
    original_PassiveBase_OnUseBuffTurnBySkill(__this, skill, bufKeyword, turn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnUseBuffTurnBySkill(skill, bufKeyword, turn, timing);
    }
}

// C#: System.Void OnUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnUseBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    original_PassiveBase_OnUseBuff(__this, keyword, stack, turn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnUseBuff(keyword, stack, turn, timing);
    }
}

// C#: System.Void BeforeUseBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_BeforeUseBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    original_PassiveBase_BeforeUseBuff(__this, keyword, stack, turn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->BeforeUseBuff(keyword, stack, turn, timing);
    }
}

// C#: System.Single GetCoinProbAdder()
float hooked_PassiveBase_GetCoinProbAdder(il2cpp::Il2CppObject* __this) {
    float returnValue = original_PassiveBase_GetCoinProbAdder(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetCoinProbAdder(returnValue);
    }
    return returnValue;
}

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, System.Single& prob)
bool hooked_PassiveBase_OverwriteCoinProb(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, float* prob) {
    bool returnValue = original_PassiveBase_OverwriteCoinProb(__this, unit, skill, prob);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteCoinProb(returnValue, unit, skill, prob);
    }
    return returnValue;
}

// C#: System.Boolean IsEgoSkillFree(BattleEgoModel ego)
bool hooked_PassiveBase_IsEgoSkillFree(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* ego) {
    bool returnValue = original_PassiveBase_IsEgoSkillFree(__this, ego);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsEgoSkillFree(returnValue, ego);
    }
    return returnValue;
}

// C#: System.Void OnPickSkills()
void hooked_PassiveBase_OnPickSkills(il2cpp::Il2CppObject* __this) {
    original_PassiveBase_OnPickSkills(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnPickSkills();
    }
}

// C#: System.Void OnAddActionToPart(BattleUnitModel_Abnormality_Part part, BattleActionModel action)
void hooked_PassiveBase_OnAddActionToPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* part, il2cpp::Il2CppObject* action) {
    original_PassiveBase_OnAddActionToPart(__this, part, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddActionToPart(part, action);
    }
}

// C#: System.Void OnAddCoinByAbility(BattleActionModel action, CoinModel newCoin, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnAddCoinByAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* newCoin, int32_t timing) {
    original_PassiveBase_OnAddCoinByAbility(__this, action, newCoin, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddCoinByAbility(action, newCoin, timing);
    }
}

// C#: System.Boolean CanOverwritePanicType()
bool hooked_PassiveBase_CanOverwritePanicType(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_CanOverwritePanicType(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CanOverwritePanicType(returnValue);
    }
    return returnValue;
}

// C#: System.Single GetCriticalChanceAdder(System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
float hooked_PassiveBase_GetCriticalChanceAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* affectKeywords) {
    float returnValue = original_PassiveBase_GetCriticalChanceAdder(__this, affectKeywords);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetCriticalChanceAdder(returnValue, affectKeywords);
    }
    return returnValue;
}

// C#: System.Single GetCriticalDamageRatioResultMultiplier(BattleActionModel action)
float hooked_PassiveBase_GetCriticalDamageRatioResultMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    float returnValue = original_PassiveBase_GetCriticalDamageRatioResultMultiplier(__this, action);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->GetCriticalDamageRatioResultMultiplier(returnValue, action);
    }
    return returnValue;
}

// C#: System.Void RightAfterDestroyAnyBuff(BuffInfo destroyedBuffInfo, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_RightAfterDestroyAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* destroyedBuffInfo, int32_t timing) {
    original_PassiveBase_RightAfterDestroyAnyBuff(__this, destroyedBuffInfo, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterDestroyAnyBuff(destroyedBuffInfo, timing);
    }
}

// C#: System.Boolean IsAbnormalityImmortal(BATTLE_EVENT_TIMING timing, System.Int32 newHp, System.Boolean isInstantDeath, BUFF_UNIQUE_KEYWORD buff, BattleActionModel actionOrNull)
bool hooked_PassiveBase_IsAbnormalityImmortal(il2cpp::Il2CppObject* __this, int32_t timing, int32_t newHp, bool isInstantDeath, int32_t buff, il2cpp::Il2CppObject* actionOrNull) {
    bool returnValue = original_PassiveBase_IsAbnormalityImmortal(__this, timing, newHp, isInstantDeath, buff, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsAbnormalityImmortal(returnValue, timing, newHp, isInstantDeath, buff, actionOrNull);
    }
    return returnValue;
}

// C#: System.Boolean CheckIfTurnToCorpesOnDie()
bool hooked_PassiveBase_CheckIfTurnToCorpesOnDie(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_PassiveBase_CheckIfTurnToCorpesOnDie(__this);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->CheckIfTurnToCorpesOnDie(returnValue);
    }
    return returnValue;
}

// C#: System.Void OnCanceledByLackOfBuffsAtStartCoin(BattleActionModel action, CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD> lackOfBuffs, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* lackOfBuffs, int32_t timing) {
    original_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin(__this, action, coin, lackOfBuffs, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnCanceledByLackOfBuffsAtStartCoin(action, coin, lackOfBuffs, timing);
    }
}

// C#: System.Void CheckOverwriteGettingBuff(ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BUFF_UNIQUE_KEYWORD& keyword, System.Int32& stack, System.Int32& turn, System.Int32& activeRound)
void hooked_PassiveBase_CheckOverwriteGettingBuff(il2cpp::Il2CppObject* __this, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, int32_t* keyword, int32_t* stack, int32_t* turn, int32_t* activeRound) {
    original_PassiveBase_CheckOverwriteGettingBuff(__this, abilitySrcType, timing, giverOrNull, keyword, stack, turn, activeRound);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->CheckOverwriteGettingBuff(abilitySrcType, timing, giverOrNull, keyword, stack, turn, activeRound);
    }
}

// C#: System.Boolean IsAllowedToGiveBuff(BUFF_UNIQUE_KEYWORD keyword)
bool hooked_PassiveBase_IsAllowedToGiveBuff(il2cpp::Il2CppObject* __this, int32_t keyword) {
    bool returnValue = original_PassiveBase_IsAllowedToGiveBuff(__this, keyword);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsAllowedToGiveBuff(returnValue, keyword);
    }
    return returnValue;
}

// C#: System.Void OnFailedToGetBuff(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel giverActionOrNull)
void hooked_PassiveBase_OnFailedToGetBuff(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* giverActionOrNull) {
    original_PassiveBase_OnFailedToGetBuff(__this, keyword, stack, turn, activeRound, abilitySrcType, timing, giverOrNull, giverActionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnFailedToGetBuff(keyword, stack, turn, activeRound, abilitySrcType, timing, giverOrNull, giverActionOrNull);
    }
}

// C#: System.Void RightAfterFailingGetAnyBuff(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE srcType, BATTLE_EVENT_TIMING timing, BattleUnitModel giverOrNull, BattleActionModel actionOrNull, System.Int32 overStack, System.Int32 overTurn)
void hooked_PassiveBase_RightAfterFailingGetAnyBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t srcType, int32_t timing, il2cpp::Il2CppObject* giverOrNull, il2cpp::Il2CppObject* actionOrNull, int32_t overStack, int32_t overTurn) {
    original_PassiveBase_RightAfterFailingGetAnyBuff(__this, unit, keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->RightAfterFailingGetAnyBuff(unit, keyword, stack, turn, activeRound, srcType, timing, giverOrNull, actionOrNull, overStack, overTurn);
    }
}

// C#: System.Void OnFailedToGiveBuff(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, System.Int32 activeRound, ABILITY_SOURCE_TYPE abilitySrcType, BATTLE_EVENT_TIMING timing, BattleActionModel actionOrNull)
void hooked_PassiveBase_OnFailedToGiveBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, int32_t stack, int32_t turn, int32_t activeRound, int32_t abilitySrcType, int32_t timing, il2cpp::Il2CppObject* actionOrNull) {
    original_PassiveBase_OnFailedToGiveBuff(__this, target, keyword, stack, turn, activeRound, abilitySrcType, timing, actionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnFailedToGiveBuff(target, keyword, stack, turn, activeRound, abilitySrcType, timing, actionOrNull);
    }
}

// C#: System.Void OnUseCoinConsume(BattleUnitModel owner, BattleActionModel action, CoinModel coin, BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn, BATTLE_EVENT_TIMING timing)
void hooked_PassiveBase_OnUseCoinConsume(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* owner, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, int32_t keyword, int32_t stack, int32_t turn, int32_t timing) {
    original_PassiveBase_OnUseCoinConsume(__this, owner, action, coin, keyword, stack, turn, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnUseCoinConsume(owner, action, coin, keyword, stack, turn, timing);
    }
}

// C#: System.Boolean BlockGivingBuff(BattleActionModel action, BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool hooked_PassiveBase_BlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) {
    bool returnValue = original_PassiveBase_BlockGivingBuff(__this, action, buffTarget, keyword, activeRound, coinOrNull, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->BlockGivingBuff(returnValue, action, buffTarget, keyword, activeRound, coinOrNull, isCritical);
    }
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverwritePartSpeed(System.Int32 speed, BattleUnitModel_Abnormality_Part part)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwritePartSpeed(il2cpp::Il2CppObject* __this, int32_t speed, il2cpp::Il2CppObject* part) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwritePartSpeed(__this, speed, part);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwritePartSpeed(returnValue, speed, part);
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel unit, BattleUnitModel target, BattleActionModel action, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Boolean> isCritical)
bool hooked_PassiveBase_BlockLoseBuffByReactWithAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* action, int32_t keyword, il2cpp::Il2CppObject* isCritical) {
    bool returnValue = original_PassiveBase_BlockLoseBuffByReactWithAction(__this, unit, target, action, keyword, isCritical);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->BlockLoseBuffByReactWithAction(returnValue, unit, target, action, keyword, isCritical);
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffStack(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_BlockLoseBuffStack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) {
    bool returnValue = original_PassiveBase_BlockLoseBuffStack(__this, unit, keyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->BlockLoseBuffStack(returnValue, unit, keyword, timing);
    }
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffTurn(BattleUnitModel unit, BUFF_UNIQUE_KEYWORD keyword, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_BlockLoseBuffTurn(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, int32_t keyword, int32_t timing) {
    bool returnValue = original_PassiveBase_BlockLoseBuffTurn(__this, unit, keyword, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->BlockLoseBuffTurn(returnValue, unit, keyword, timing);
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingSinkingBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerAction, CoinModel attackerCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IsBlockingSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerAction, il2cpp::Il2CppObject* attackerCoin, bool isCritical, int32_t timing) {
    bool returnValue = original_PassiveBase_IsBlockingSinkingBuffEffectReact(__this, stack, turn, attackerAction, attackerCoin, isCritical, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsBlockingSinkingBuffEffectReact(returnValue, stack, turn, attackerAction, attackerCoin, isCritical, timing);
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IsBlockingTargetSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    bool returnValue = original_PassiveBase_IsBlockingTargetSinkingBuffEffectReact(__this, target, stack, turn, selfAction, selfCoin, isCritical, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsBlockingTargetSinkingBuffEffectReact(returnValue, target, stack, turn, selfAction, selfCoin, isCritical, timing);
    }
    return returnValue;
}

// C#: System.Nullable<System.Boolean> OverwriteCanDuel(BattleActionModel selfAction, BattleActionModel opponentAction)
il2cpp::Il2CppObject* hooked_PassiveBase_OverwriteCanDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* opponentAction) {
    il2cpp::Il2CppObject* returnValue = original_PassiveBase_OverwriteCanDuel(__this, selfAction, opponentAction);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->OverwriteCanDuel(returnValue, selfAction, opponentAction);
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingBurstBuffEffectReact(System.Int32 stack, System.Int32 turn, BattleActionModel attackerActionOrNull, CoinModel attackerCoinOrNull, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IsBlockingBurstBuffEffectReact(il2cpp::Il2CppObject* __this, int32_t stack, int32_t turn, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* attackerCoinOrNull, bool isCritical, int32_t timing) {
    bool returnValue = original_PassiveBase_IsBlockingBurstBuffEffectReact(__this, stack, turn, attackerActionOrNull, attackerCoinOrNull, isCritical, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsBlockingBurstBuffEffectReact(returnValue, stack, turn, attackerActionOrNull, attackerCoinOrNull, isCritical, timing);
    }
    return returnValue;
}

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, BattleActionModel selfAction, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_PassiveBase_IsBlockingTargetBurstBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfAction, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    bool returnValue = original_PassiveBase_IsBlockingTargetBurstBuffEffectReact(__this, target, stack, turn, selfAction, selfCoin, isCritical, timing);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsBlockingTargetBurstBuffEffectReact(returnValue, target, stack, turn, selfAction, selfCoin, isCritical, timing);
    }
    return returnValue;
}

// C#: System.Boolean ModifyMpChangeValue(System.Int32 oldMp, System.Int32 newMp, System.Int32& changedNewMp)
bool hooked_PassiveBase_ModifyMpChangeValue(il2cpp::Il2CppObject* __this, int32_t oldMp, int32_t newMp, int32_t* changedNewMp) {
    bool returnValue = original_PassiveBase_ModifyMpChangeValue(__this, oldMp, newMp, changedNewMp);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->ModifyMpChangeValue(returnValue, oldMp, newMp, changedNewMp);
    }
    return returnValue;
}

// C#: System.Void OnAddBattleAction(SinActionModel actorAction, SinActionModel targetAction)
void hooked_PassiveBase_OnAddBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actorAction, il2cpp::Il2CppObject* targetAction) {
    original_PassiveBase_OnAddBattleAction(__this, actorAction, targetAction);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnAddBattleAction(actorAction, targetAction);
    }
}

// C#: System.Void OnRemoveBattleAction(SinActionModel actorAction)
void hooked_PassiveBase_OnRemoveBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* actorAction) {
    original_PassiveBase_OnRemoveBattleAction(__this, actorAction);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        it->second->OnRemoveBattleAction(actorAction);
    }
}

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel thisAction, BattleActionModel mainAction, BattleActionModel oppoActionOrNull)
bool hooked_PassiveBase_IsRunUniqueAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* thisAction, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionOrNull) {
    bool returnValue = original_PassiveBase_IsRunUniqueAction(__this, uniqueTiming, thisAction, mainAction, oppoActionOrNull);
    auto it = PassiveBaseMap.find(__this);
    if (it != PassiveBaseMap.end()) {
        return it->second->IsRunUniqueAction(returnValue, uniqueTiming, thisAction, mainAction, oppoActionOrNull);
    }
    return returnValue;
}


// int32_t hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
//     int32_t value = original_BattleActionModel_GetExpectedOpponentParryingResultAdder(__this, actorResult, oppoActionOrNull, oppoResult);
//     MYO_LOG("PassiveBase", "GetExpectedOpponentParryingResultAdder {}", value);
//     return 50;
// }

// int32_t hooked_BattleActionModel_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
    
//     int32_t value = original_BattleActionModel_GetExpectedParryingResultAdder(__this, actorResult, oppoActionOrNull, oppoResult);
//     MYO_LOG("PassiveBase", "GetExpectedParryingResultAdder {}", value);
//     return 50;
// }
// C#: System.Void .ctor(BattleUnitModel model, UnitDataModel rawDataModel)
void hooked_PassiveBase_ctor(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* model, il2cpp::Il2CppObject* rawDataModel) {
    // call the constructor first and foremost
    original_PassiveBase_ctor(__this, model, rawDataModel);
    // MYO_LOG("HermesPassiveBase", "A PassiveBase has been constructed");

    // Get all the class cache refs necessary
    ClassCache& PassiveDetailC = GetClassRef("PassiveDetail");
    ClassCache& PassiveModelC = GetClassRef("PassiveModel");
    ClassCache& PassiveStaticDataC = GetClassRef("PassiveStaticData");
    ClassCache& List_PassiveModel = GetClassRef("List_PassiveModel");

    // get all passive list, and iterate to check if a custom passive is there
    il2cpp::Il2CppObject* allPassiveList = PassiveDetailC.Invoke("get_PassiveList", __this);
    int32_t allPassiveListCount = List_PassiveModel.InvokeUnbox<int32_t>("get_Count", allPassiveList);
    il2cpp::Il2CppObject* activatedPassivesList = PassiveDetailC.Invoke("GetAllActivatedPassives", __this);
    
    PassiveDetail* passiveDetail = nullptr;
    bool createdDetail = false;
    // MYO_LOG("PassiveBase", "Passive Total: {}", allPassiveListCount);
    for (int32_t i = 0; i < allPassiveListCount; i++) {
        
        
        // check the ids of the passive. if it matches a custom passive, create the BuffDetail. 
        il2cpp::Il2CppObject* passiveModelObj = List_PassiveModel.Invoke("get_Item", allPassiveList, &i);
        il2cpp::Il2CppObject* passiveStaticDataObj = PassiveModelC.Invoke("get_ClassInfo", passiveModelObj);
        int32_t passiveId = PassiveStaticDataC.InvokeUnbox<int32_t>("get_ID", passiveStaticDataObj);
        // MYO_LOG("PassiveBase", "Passive ID: {}", passiveId);
        if (allCustomPassiveIDs.contains(passiveId)) {

            // initilize the passive detail if it actually has a custom id (but ONCE!)
            if (!createdDetail) {
                passiveDetail = new PassiveDetail();
                createdDetail = true;
                passiveDetail->passiveDetailObj = __this;
                passiveDetail->allPassiveList = allPassiveList;
                passiveDetail->activePassiveList = activatedPassivesList;
                PassiveBaseMap[__this] = passiveDetail;
                MYO_LOG("PassiveBase", "Storing {} in PassiveBaseMap", __this);
            }
            
            passiveDetail->tryAddCustomPassive(passiveModelObj, passiveId);
            MYO_LOG("HermesPassiveBase", "Added a custom passive to an object {}", passiveModelObj);
        }
    }
    
    
}

void init_PassiveBase(il2cpp::Il2CppImage* img) {
    // Register all Passives Here
    registerPassive<MoPassive1>(1019901);
    registerPassive<MoPassive2>(1019902);
    registerPassive<MoPassive3>(1019903);

    // Hook PassiveBase. Lines that are commented out are buff-container plumbing / queries / UI helpers
    // that a passive has no reason to override (matching the commented-out overrides in PassiveDetail).
    ClassCache PassiveDetailC = RegisterClassFull("PassiveDetail", img, "", "PassiveDetail");
    ClassCache PassiveModelC = RegisterClassFull("PassiveModel", img, "", "PassiveModel");
    ClassCache PassiveStaticDataC = RegisterClassFull("PassiveStaticData", img, "", "PassiveStaticData");
    ClassCache List_PassiveModelC = RegisterClassFull(InflateGenericClass(GetClass("List").klass, {PassiveModelC.klass}), "List_PassiveModel");
    

    // ClassCache BattleActionModelC = RegisterClassFull("BattleActionModel", img, "", "BattleActionModel");
    // original_BattleActionModel_GetExpectedOpponentParryingResultAdder = 
    //     InstallHook<BattleActionModelGetExpectedOpponentParryingResultAdderFn>(BattleActionModelC.GetMethod("GetExpectedOpponentParryingResultAdder"), &hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder);
    // original_BattleActionModel_GetExpectedParryingResultAdder =
    //     InstallHook<BattleActionModelGetExpectedParryingResultAdderFn>(BattleActionModelC.GetMethod("GetExpectedParryingResultAdder"), &hooked_BattleActionModel_GetExpectedParryingResultAdder);
    hook::ONLY_LOG_HOOKS_ON_ERROR = true;

    
    
    original_PassiveBase_OnStartBehaviour = InstallHook<PassiveBaseOnStartBehaviourFn>(PassiveDetailC.GetMethod("OnStartBehaviour"), &hooked_PassiveBase_OnStartBehaviour);
    original_PassiveBase_OnSucceedAttack = InstallHook<PassiveBaseOnSucceedAttackFn>(PassiveDetailC.GetMethod("OnSucceedAttack"), &hooked_PassiveBase_OnSucceedAttack);
    original_PassiveBase_OnRollOneCoin_AfterAttack = InstallHook<PassiveBaseOnRollOneCoin_AfterAttackFn>(PassiveDetailC.GetMethod("OnRollOneCoin_AfterAttack"), &hooked_PassiveBase_OnRollOneCoin_AfterAttack);
    original_PassiveBase_OnEndAttack = InstallHook<PassiveBaseOnEndAttackFn>(PassiveDetailC.GetMethod("OnEndAttack"), &hooked_PassiveBase_OnEndAttack);
    original_PassiveBase_OnEndAttackOtherUnit = InstallHook<PassiveBaseOnEndAttackOtherUnitFn>(PassiveDetailC.GetMethod("OnEndAttackOtherUnit"), &hooked_PassiveBase_OnEndAttackOtherUnit);
    original_PassiveBase_OnStartEnemyAttack = InstallHook<PassiveBaseOnStartEnemyAttackFn>(PassiveDetailC.GetMethod("OnStartEnemyAttack"), &hooked_PassiveBase_OnStartEnemyAttack);
    original_PassiveBase_OnEndEnemyAttack = InstallHook<PassiveBaseOnEndEnemyAttackFn>(PassiveDetailC.GetMethod("OnEndEnemyAttack"), &hooked_PassiveBase_OnEndEnemyAttack);
    original_PassiveBase_OnEndAttackPart = InstallHook<PassiveBaseOnEndAttackPartFn>(PassiveDetailC.GetMethod("OnEndAttackPart"), &hooked_PassiveBase_OnEndAttackPart);
    original_PassiveBase_OnDuelAfter_BeforeLog = InstallHook<PassiveBaseOnDuelAfter_BeforeLogFn>(PassiveDetailC.GetMethod("OnDuelAfter_BeforeLog"), &hooked_PassiveBase_OnDuelAfter_BeforeLog);
    original_PassiveBase_OnAfterParryingOnce_BeforeLog = InstallHook<PassiveBaseOnAfterParryingOnce_BeforeLogFn>(PassiveDetailC.GetMethod("OnAfterParryingOnce_BeforeLog"), &hooked_PassiveBase_OnAfterParryingOnce_BeforeLog);
    original_PassiveBase_OnAfterParryingOnce_AfterLog = InstallHook<PassiveBaseOnAfterParryingOnce_AfterLogFn>(PassiveDetailC.GetMethod("OnAfterParryingOnce_AfterLog"), &hooked_PassiveBase_OnAfterParryingOnce_AfterLog);
    original_PassiveBase_OnWinParrying = InstallHook<PassiveBaseOnWinParryingFn>(PassiveDetailC.GetMethod("OnWinParrying"), &hooked_PassiveBase_OnWinParrying);
    original_PassiveBase_OnLoseParrying = InstallHook<PassiveBaseOnLoseParryingFn>(PassiveDetailC.GetMethod("OnLoseParrying"), &hooked_PassiveBase_OnLoseParrying);
    original_PassiveBase_OnWinDuel = InstallHook<PassiveBaseOnWinDuelFn>(PassiveDetailC.GetMethod("OnWinDuel"), &hooked_PassiveBase_OnWinDuel);
    original_PassiveBase_OnLoseDuel = InstallHook<PassiveBaseOnLoseDuelFn>(PassiveDetailC.GetMethod("OnLoseDuel"), &hooked_PassiveBase_OnLoseDuel);
    original_PassiveBase_OnLoseDuelOtherUnit = InstallHook<PassiveBaseOnLoseDuelOtherUnitFn>(PassiveDetailC.GetMethod("OnLoseDuelOtherUnit"), &hooked_PassiveBase_OnLoseDuelOtherUnit);
    original_PassiveBase_RightBeforeGiveBuffBySkill = InstallHook<PassiveBaseRightBeforeGiveBuffBySkillFn>(PassiveDetailC.GetMethod("RightBeforeGiveBuffBySkill"), &hooked_PassiveBase_RightBeforeGiveBuffBySkill);
    original_PassiveBase_RightAfterGiveBuffBySkill = InstallHook<PassiveBaseRightAfterGiveBuffBySkillFn>(PassiveDetailC.GetMethod("RightAfterGiveBuffBySkill"), &hooked_PassiveBase_RightAfterGiveBuffBySkill);
    original_PassiveBase_RightAfterTakeBuffBySkill = InstallHook<PassiveBaseRightAfterTakeBuffBySkillFn>(PassiveDetailC.GetMethod("RightAfterTakeBuffBySkill"), &hooked_PassiveBase_RightAfterTakeBuffBySkill);
    original_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill = InstallHook<PassiveBaseRightBeforeOtherUnitGiveBuffBySkillFn>(PassiveDetailC.GetMethod("RightBeforeOtherUnitGiveBuffBySkill"), &hooked_PassiveBase_RightBeforeOtherUnitGiveBuffBySkill);
    original_PassiveBase_RightAfterOtherUnitGiveBuffBySkill = InstallHook<PassiveBaseRightAfterOtherUnitGiveBuffBySkillFn>(PassiveDetailC.GetMethod("RightAfterOtherUnitGiveBuffBySkill"), &hooked_PassiveBase_RightAfterOtherUnitGiveBuffBySkill);
    original_PassiveBase_RightAfterAnyUnitGetAnyBuff = InstallHook<PassiveBaseRightAfterAnyUnitGetAnyBuffFn>(PassiveDetailC.GetMethod("RightAfterAnyUnitGetAnyBuff"), &hooked_PassiveBase_RightAfterAnyUnitGetAnyBuff);
    original_PassiveBase_RightAfterLosingBuff = InstallHook<PassiveBaseRightAfterLosingBuffFn>(PassiveDetailC.GetMethod("RightAfterLosingBuff"), &hooked_PassiveBase_RightAfterLosingBuff);
    original_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration = InstallHook<PassiveBaseOnSucceedToGiveSwitchToSpecialVibrationFn>(PassiveDetailC.GetMethod("OnSucceedToGiveSwitchToSpecialVibration"), &hooked_PassiveBase_OnSucceedToGiveSwitchToSpecialVibration);
    original_PassiveBase_RightAfterGetAnyBuff = InstallHook<PassiveBaseRightAfterGetAnyBuffFn>(PassiveDetailC.GetMethod("RightAfterGetAnyBuff"), &hooked_PassiveBase_RightAfterGetAnyBuff);
    original_PassiveBase_RightAfterGetAnyBuffAtPart = InstallHook<PassiveBaseRightAfterGetAnyBuffAtPartFn>(PassiveDetailC.GetMethod("RightAfterGetAnyBuffAtPart"), &hooked_PassiveBase_RightAfterGetAnyBuffAtPart);
    original_PassiveBase_RightAfterDestroyAnyBuffAtPart = InstallHook<PassiveBaseRightAfterDestroyAnyBuffAtPartFn>(PassiveDetailC.GetMethod("RightAfterDestroyAnyBuffAtPart"), &hooked_PassiveBase_RightAfterDestroyAnyBuffAtPart);
    original_PassiveBase_GetAggroAdder = InstallHook<PassiveBaseGetAggroAdderFn>(PassiveDetailC.GetMethod("GetAggroAdder"), &hooked_PassiveBase_GetAggroAdder);
    original_PassiveBase_GetAttackWeightAdder = InstallHook<PassiveBaseGetAttackWeightAdderFn>(PassiveDetailC.GetMethod("GetAttackWeightAdder"), &hooked_PassiveBase_GetAttackWeightAdder);
    original_PassiveBase_GetMentalSystemResultIncreaseAdder = InstallHook<PassiveBaseGetMentalSystemResultIncreaseAdderFn>(PassiveDetailC.GetMethod("GetMentalSystemResultIncreaseAdder"), &hooked_PassiveBase_GetMentalSystemResultIncreaseAdder);
    original_PassiveBase_GetMentalSystemResultDecreaseAdder = InstallHook<PassiveBaseGetMentalSystemResultDecreaseAdderFn>(PassiveDetailC.GetMethod("GetMentalSystemResultDecreaseAdder"), &hooked_PassiveBase_GetMentalSystemResultDecreaseAdder);
    original_PassiveBase_GetInitBuffMaxStackAdder = InstallHook<PassiveBaseGetInitBuffMaxStackAdderFn>(PassiveDetailC.GetMethod("GetInitBuffMaxStackAdder"), &hooked_PassiveBase_GetInitBuffMaxStackAdder);
    original_PassiveBase_GetInitBuffMaxTurnAdder = InstallHook<PassiveBaseGetInitBuffMaxTurnAdderFn>(PassiveDetailC.GetMethod("GetInitBuffMaxTurnAdder"), &hooked_PassiveBase_GetInitBuffMaxTurnAdder);
    original_PassiveBase_GetTakeBuffTurnAdderOtherUnit = InstallHook<PassiveBaseGetTakeBuffTurnAdderOtherUnitFn>(PassiveDetailC.GetMethod("GetTakeBuffTurnAdderOtherUnit"), &hooked_PassiveBase_GetTakeBuffTurnAdderOtherUnit);
    original_PassiveBase_GetTakeBuffStackAdder = InstallHook<PassiveBaseGetTakeBuffStackAdderFn>(PassiveDetailC.GetMethod("GetTakeBuffStackAdder"), &hooked_PassiveBase_GetTakeBuffStackAdder);
    original_PassiveBase_GetTakeBuffTurnAdder = InstallHook<PassiveBaseGetTakeBuffTurnAdderFn>(PassiveDetailC.GetMethod("GetTakeBuffTurnAdder"), &hooked_PassiveBase_GetTakeBuffTurnAdder);
    original_PassiveBase_GetGiveBuffTurnAdder = InstallHook<PassiveBaseGetGiveBuffTurnAdderFn>(PassiveDetailC.GetMethod("GetGiveBuffTurnAdder"), &hooked_PassiveBase_GetGiveBuffTurnAdder);
    original_PassiveBase_GetGiveBuffStackAdder = InstallHook<PassiveBaseGetGiveBuffStackAdderFn>(PassiveDetailC.GetMethod("GetGiveBuffStackAdder"), &hooked_PassiveBase_GetGiveBuffStackAdder);
    original_PassiveBase_GetUseBuffTurnAdder = InstallHook<PassiveBaseGetUseBuffTurnAdderFn>(PassiveDetailC.GetMethod("GetUseBuffTurnAdder"), &hooked_PassiveBase_GetUseBuffTurnAdder);
    original_PassiveBase_GetTakeBuffStackMultiplier = InstallHook<PassiveBaseGetTakeBuffStackMultiplierFn>(PassiveDetailC.GetMethod("GetTakeBuffStackMultiplier"), &hooked_PassiveBase_GetTakeBuffStackMultiplier);
    original_PassiveBase_GetTakeBuffTurnMultiplier = InstallHook<PassiveBaseGetTakeBuffTurnMultiplierFn>(PassiveDetailC.GetMethod("GetTakeBuffTurnMultiplier"), &hooked_PassiveBase_GetTakeBuffTurnMultiplier);
    original_PassiveBase_OnActivateSinBuffEffect = InstallHook<PassiveBaseOnActivateSinBuffEffectFn>(PassiveDetailC.GetMethod("OnActivateSinBuffEffect"), &hooked_PassiveBase_OnActivateSinBuffEffect);
    original_PassiveBase_OnActivateOtherUnitSinBuffEffect = InstallHook<PassiveBaseOnActivateOtherUnitSinBuffEffectFn>(PassiveDetailC.GetMethod("OnActivateOtherUnitSinBuffEffect"), &hooked_PassiveBase_OnActivateOtherUnitSinBuffEffect);
    original_PassiveBase_IgnoreSinBuffHpDamage = InstallHook<PassiveBaseIgnoreSinBuffHpDamageFn>(PassiveDetailC.GetMethod("IgnoreSinBuffHpDamage"), &hooked_PassiveBase_IgnoreSinBuffHpDamage);
    original_PassiveBase_IgnoreSinBuffHpDamagePart = InstallHook<PassiveBaseIgnoreSinBuffHpDamagePartFn>(PassiveDetailC.GetMethod("IgnoreSinBuffHpDamagePart"), &hooked_PassiveBase_IgnoreSinBuffHpDamagePart);
    original_PassiveBase_OnIgnoreSinBuffHpDamage = InstallHook<PassiveBaseOnIgnoreSinBuffHpDamageFn>(PassiveDetailC.GetMethod("OnIgnoreSinBuffHpDamage"), &hooked_PassiveBase_OnIgnoreSinBuffHpDamage);
    original_PassiveBase_GetSinBuffDamageAdder = InstallHook<PassiveBaseGetSinBuffDamageAdderFn>(PassiveDetailC.GetMethod("GetSinBuffDamageAdder"), &hooked_PassiveBase_GetSinBuffDamageAdder);
    original_PassiveBase_GetSinBuffDamageMultiplier = InstallHook<PassiveBaseGetSinBuffDamageMultiplierFn>(PassiveDetailC.GetMethod("GetSinBuffDamageMultiplier"), &hooked_PassiveBase_GetSinBuffDamageMultiplier);
    original_PassiveBase_GetMaxBuffStackAdder = InstallHook<PassiveBaseGetMaxBuffStackAdderFn>(PassiveDetailC.GetMethod("GetMaxBuffStackAdder"), &hooked_PassiveBase_GetMaxBuffStackAdder);
    original_PassiveBase_GetMaxBuffTurnAdder = InstallHook<PassiveBaseGetMaxBuffTurnAdderFn>(PassiveDetailC.GetMethod("GetMaxBuffTurnAdder"), &hooked_PassiveBase_GetMaxBuffTurnAdder);
    original_PassiveBase_GetUnitStatLevelAdder = InstallHook<PassiveBaseGetUnitStatLevelAdderFn>(PassiveDetailC.GetMethod("GetUnitStatLevelAdder"), &hooked_PassiveBase_GetUnitStatLevelAdder);
    original_PassiveBase_GetGiveBsGaugeUpMultiplier = InstallHook<PassiveBaseGetGiveBsGaugeUpMultiplierFn>(PassiveDetailC.GetMethod("GetGiveBsGaugeUpMultiplier"), &hooked_PassiveBase_GetGiveBsGaugeUpMultiplier);
    original_PassiveBase_GetTakeBsGaugeUpMultiplier = InstallHook<PassiveBaseGetTakeBsGaugeUpMultiplierFn>(PassiveDetailC.GetMethod("GetTakeBsGaugeUpMultiplier"), &hooked_PassiveBase_GetTakeBsGaugeUpMultiplier);
    original_PassiveBase_GetSkillPoolCountAdder = InstallHook<PassiveBaseGetSkillPoolCountAdderFn>(PassiveDetailC.GetMethod("GetSkillPoolCountAdder"), &hooked_PassiveBase_GetSkillPoolCountAdder);
    original_PassiveBase_OnDestroy = InstallHook<PassiveBaseOnDestroyFn>(PassiveDetailC.GetMethod("OnDestroy"), &hooked_PassiveBase_OnDestroy);
    original_PassiveBase_OnOtherPartDestroyed = InstallHook<PassiveBaseOnOtherPartDestroyedFn>(PassiveDetailC.GetMethod("OnOtherPartDestroyed"), &hooked_PassiveBase_OnOtherPartDestroyed);
    original_PassiveBase_OnPartDestroyed = InstallHook<PassiveBaseOnPartDestroyedFn>(PassiveDetailC.GetMethod("OnPartDestroyed"), &hooked_PassiveBase_OnPartDestroyed);
    original_PassiveBase_OnPartBreaked = InstallHook<PassiveBaseOnPartBreakedFn>(PassiveDetailC.GetMethod("OnPartBreaked"), &hooked_PassiveBase_OnPartBreaked);
    original_PassiveBase_OnPartRecoverBreak = InstallHook<PassiveBaseOnPartRecoverBreakFn>(PassiveDetailC.GetMethod("OnPartRecoverBreak"), &hooked_PassiveBase_OnPartRecoverBreak);
    original_PassiveBase_OnRegenerate = InstallHook<PassiveBaseOnRegenerateFn>(PassiveDetailC.GetMethod("OnRegenerate"), &hooked_PassiveBase_OnRegenerate);
    original_PassiveBase_OnPartRegenerate = InstallHook<PassiveBaseOnPartRegenerateFn>(PassiveDetailC.GetMethod("OnPartRegenerate"), &hooked_PassiveBase_OnPartRegenerate);
    original_PassiveBase_CheckUnitGivingBuffCategory = InstallHook<PassiveBaseCheckUnitGivingBuffCategoryFn>(PassiveDetailC.GetMethod("CheckUnitGivingBuffCategory"), &hooked_PassiveBase_CheckUnitGivingBuffCategory);
    original_PassiveBase_CheckUnitGivingBuffKeyword = InstallHook<PassiveBaseCheckUnitGivingBuffKeywordFn>(PassiveDetailC.GetMethod("CheckUnitGivingBuffKeyword"), &hooked_PassiveBase_CheckUnitGivingBuffKeyword);
    original_PassiveBase_CheckSkillGivingBuffCategory = InstallHook<PassiveBaseCheckSkillGivingBuffCategoryFn>(PassiveDetailC.GetMethod("CheckSkillGivingBuffCategory"), &hooked_PassiveBase_CheckSkillGivingBuffCategory);
    original_PassiveBase_CheckSkillGivingBuff = InstallHook<PassiveBaseCheckSkillGivingBuffFn>(PassiveDetailC.GetMethod("CheckSkillGivingBuff"), &hooked_PassiveBase_CheckSkillGivingBuff);
    original_PassiveBase_CheckLoseBuffStackAndTurn = InstallHook<PassiveBaseCheckLoseBuffStackAndTurnFn>(PassiveDetailC.GetMethod("CheckLoseBuffStackAndTurn"), &hooked_PassiveBase_CheckLoseBuffStackAndTurn);
    original_PassiveBase_GetCoinScaleAdder = InstallHook<PassiveBaseGetCoinScaleAdderFn>(PassiveDetailC.GetMethod("GetCoinScaleAdder"), &hooked_PassiveBase_GetCoinScaleAdder);
    original_PassiveBase_GetExpectedCoinScaleAdder = InstallHook<PassiveBaseGetExpectedCoinScaleAdderFn>(PassiveDetailC.GetMethod("GetExpectedCoinScaleAdder"), &hooked_PassiveBase_GetExpectedCoinScaleAdder);
    original_PassiveBase_GetSkillPowerResultAdder = InstallHook<PassiveBaseGetSkillPowerResultAdderFn>(PassiveDetailC.GetMethod("GetSkillPowerResultAdder"), &hooked_PassiveBase_GetSkillPowerResultAdder);
    original_PassiveBase_GetTakeHpDmgAdder = InstallHook<PassiveBaseGetTakeHpDmgAdderFn>(PassiveDetailC.GetMethod("GetTakeHpDmgAdder"), &hooked_PassiveBase_GetTakeHpDmgAdder);
    original_PassiveBase_GetExpectedTakeHpDmgAdder = InstallHook<PassiveBaseGetExpectedTakeHpDmgAdderFn>(PassiveDetailC.GetMethod("GetExpectedTakeHpDmgAdder"), &hooked_PassiveBase_GetExpectedTakeHpDmgAdder);
    original_PassiveBase_GetMinSpeedAdder = InstallHook<PassiveBaseGetMinSpeedAdderFn>(PassiveDetailC.GetMethod("GetMinSpeedAdder"), &hooked_PassiveBase_GetMinSpeedAdder);
    original_PassiveBase_GetMaxSpeedAdder = InstallHook<PassiveBaseGetMaxSpeedAdderFn>(PassiveDetailC.GetMethod("GetMaxSpeedAdder"), &hooked_PassiveBase_GetMaxSpeedAdder);
    original_PassiveBase_GetSpeedAdder = InstallHook<PassiveBaseGetSpeedAdderFn>(PassiveDetailC.GetMethod("GetSpeedAdder"), &hooked_PassiveBase_GetSpeedAdder);
    original_PassiveBase_UseOnlyDefaultMinSpeed = InstallHook<PassiveBaseUseOnlyDefaultMinSpeedFn>(PassiveDetailC.GetMethod("UseOnlyDefaultMinSpeed"), &hooked_PassiveBase_UseOnlyDefaultMinSpeed);
    original_PassiveBase_UseOnlyDefaultMaxSpeed = InstallHook<PassiveBaseUseOnlyDefaultMaxSpeedFn>(PassiveDetailC.GetMethod("UseOnlyDefaultMaxSpeed"), &hooked_PassiveBase_UseOnlyDefaultMaxSpeed);
    original_PassiveBase_ChangeAttackDamage = InstallHook<PassiveBaseChangeAttackDamageFn>(PassiveDetailC.GetMethod("ChangeAttackDamage"), &hooked_PassiveBase_ChangeAttackDamage);
    original_PassiveBase_ChangeTakeDamage = InstallHook<PassiveBaseChangeTakeDamageFn>(PassiveDetailC.GetMethod("ChangeTakeDamage"), &hooked_PassiveBase_ChangeTakeDamage);
    original_PassiveBase_ChangeMpDamage = InstallHook<PassiveBaseChangeMpDamageFn>(PassiveDetailC.GetMethod("ChangeMpDamage"), &hooked_PassiveBase_ChangeMpDamage);
    original_PassiveBase_GetAttackHpDmgAdder = InstallHook<PassiveBaseGetAttackHpDmgAdderFn>(PassiveDetailC.GetMethod("GetAttackHpDmgAdder"), &hooked_PassiveBase_GetAttackHpDmgAdder);
    original_PassiveBase_GetExpectedAttackHpDmgAdder = InstallHook<PassiveBaseGetExpectedAttackHpDmgAdderFn>(PassiveDetailC.GetMethod("GetExpectedAttackHpDmgAdder"), &hooked_PassiveBase_GetExpectedAttackHpDmgAdder);
    original_PassiveBase_GetAttackDmgAdder = InstallHook<PassiveBaseGetAttackDmgAdderFn>(PassiveDetailC.GetMethod("GetAttackDmgAdder"), &hooked_PassiveBase_GetAttackDmgAdder);
    original_PassiveBase_GetExpectedAttackDmgAdder = InstallHook<PassiveBaseGetExpectedAttackDmgAdderFn>(PassiveDetailC.GetMethod("GetExpectedAttackDmgAdder"), &hooked_PassiveBase_GetExpectedAttackDmgAdder);
    original_PassiveBase_GetAttackDmgMultiplier = InstallHook<PassiveBaseGetAttackDmgMultiplierFn>(PassiveDetailC.GetMethod("GetAttackDmgMultiplier"), &hooked_PassiveBase_GetAttackDmgMultiplier);
    original_PassiveBase_GetExpectedAttackDmgMultiplier = InstallHook<PassiveBaseGetExpectedAttackDmgMultiplierFn>(PassiveDetailC.GetMethod("GetExpectedAttackDmgMultiplier"), &hooked_PassiveBase_GetExpectedAttackDmgMultiplier);
    original_PassiveBase_GetTakeAttackDmgAdder = InstallHook<PassiveBaseGetTakeAttackDmgAdderFn>(PassiveDetailC.GetMethod("GetTakeAttackDmgAdder"), &hooked_PassiveBase_GetTakeAttackDmgAdder);
    original_PassiveBase_GetExpectedTakeAttackDmgAdder = InstallHook<PassiveBaseGetExpectedTakeAttackDmgAdderFn>(PassiveDetailC.GetMethod("GetExpectedTakeAttackDmgAdder"), &hooked_PassiveBase_GetExpectedTakeAttackDmgAdder);
    original_PassiveBase_GetTakeAttackDmgMultiplier = InstallHook<PassiveBaseGetTakeAttackDmgMultiplierFn>(PassiveDetailC.GetMethod("GetTakeAttackDmgMultiplier"), &hooked_PassiveBase_GetTakeAttackDmgMultiplier);
    original_PassiveBase_GetExpectedTakeAttackDmgMultiplier = InstallHook<PassiveBaseGetExpectedTakeAttackDmgMultiplierFn>(PassiveDetailC.GetMethod("GetExpectedTakeAttackDmgMultiplier"), &hooked_PassiveBase_GetExpectedTakeAttackDmgMultiplier);
    original_PassiveBase_GetAttackAdder = InstallHook<PassiveBaseGetAttackAdderFn>(PassiveDetailC.GetMethod("GetAttackAdder"), &hooked_PassiveBase_GetAttackAdder);
    original_PassiveBase_GetUnitDefaultLevelAdder = InstallHook<PassiveBaseGetUnitDefaultLevelAdderFn>(PassiveDetailC.GetMethod("GetUnitDefaultLevelAdder"), &hooked_PassiveBase_GetUnitDefaultLevelAdder);
    original_PassiveBase_GetDefenseAdder = InstallHook<PassiveBaseGetDefenseAdderFn>(PassiveDetailC.GetMethod("GetDefenseAdder"), &hooked_PassiveBase_GetDefenseAdder);
    original_PassiveBase_GetUnitDefenseAdder = InstallHook<PassiveBaseGetUnitDefenseAdderFn>(PassiveDetailC.GetMethod("GetUnitDefenseAdder"), &hooked_PassiveBase_GetUnitDefenseAdder);
    original_PassiveBase_GetDefenseMultiplier = InstallHook<PassiveBaseGetDefenseMultiplierFn>(PassiveDetailC.GetMethod("GetDefenseMultiplier"), &hooked_PassiveBase_GetDefenseMultiplier);
    original_PassiveBase_GetHpHealMultiplier = InstallHook<PassiveBaseGetHpHealMultiplierFn>(PassiveDetailC.GetMethod("GetHpHealMultiplier"), &hooked_PassiveBase_GetHpHealMultiplier);
    original_PassiveBase_GetAtkResistMultiplier = InstallHook<PassiveBaseGetAtkResistMultiplierFn>(PassiveDetailC.GetMethod("GetAtkResistMultiplier"), &hooked_PassiveBase_GetAtkResistMultiplier);
    original_PassiveBase_GetAtkResistAdder = InstallHook<PassiveBaseGetAtkResistAdderFn>(PassiveDetailC.GetMethod("GetAtkResistAdder"), &hooked_PassiveBase_GetAtkResistAdder);
    original_PassiveBase_GetAttributeResistMultiplier = InstallHook<PassiveBaseGetAttributeResistMultiplierFn>(PassiveDetailC.GetMethod("GetAttributeResistMultiplier"), &hooked_PassiveBase_GetAttributeResistMultiplier);
    original_PassiveBase_GetAttributeResistAdder = InstallHook<PassiveBaseGetAttributeResistAdderFn>(PassiveDetailC.GetMethod("GetAttributeResistAdder"), &hooked_PassiveBase_GetAttributeResistAdder);
    original_PassiveBase_OnDie = InstallHook<PassiveBaseOnDieFn>(PassiveDetailC.GetMethod("OnDie"), &hooked_PassiveBase_OnDie);
    original_PassiveBase_OnBreak = InstallHook<PassiveBaseOnBreakFn>(PassiveDetailC.GetMethod("OnBreak"), &hooked_PassiveBase_OnBreak);
    original_PassiveBase_OnEnemyBrokenByAttacker = InstallHook<PassiveBaseOnEnemyBrokenByAttackerFn>(PassiveDetailC.GetMethod("OnEnemyBrokenByAttacker"), &hooked_PassiveBase_OnEnemyBrokenByAttacker);
    original_PassiveBase_OnDieOtherUnit = InstallHook<PassiveBaseOnDieOtherUnitFn>(PassiveDetailC.GetMethod("OnDieOtherUnit"), &hooked_PassiveBase_OnDieOtherUnit);
    original_PassiveBase_OnDieOtherUnit_Retreated = InstallHook<PassiveBaseOnDieOtherUnit_RetreatedFn>(PassiveDetailC.GetMethod("OnDieOtherUnit_Retreated"), &hooked_PassiveBase_OnDieOtherUnit_Retreated);
    original_PassiveBase_OnDieOtherUnit_Disappeared = InstallHook<PassiveBaseOnDieOtherUnit_DisappearedFn>(PassiveDetailC.GetMethod("OnDieOtherUnit_Disappeared"), &hooked_PassiveBase_OnDieOtherUnit_Disappeared);
    original_PassiveBase_OnRetreatOtherUnit = InstallHook<PassiveBaseOnRetreatOtherUnitFn>(PassiveDetailC.GetMethod("OnRetreatOtherUnit"), &hooked_PassiveBase_OnRetreatOtherUnit);
    original_PassiveBase_OnRetreatOtherUnit_Retreated = InstallHook<PassiveBaseOnRetreatOtherUnit_RetreatedFn>(PassiveDetailC.GetMethod("OnRetreatOtherUnit_Retreated"), &hooked_PassiveBase_OnRetreatOtherUnit_Retreated);
    original_PassiveBase_OnDiscardSinOtherUnit = InstallHook<PassiveBaseOnDiscardSinOtherUnitFn>(PassiveDetailC.GetMethod("OnDiscardSinOtherUnit"), &hooked_PassiveBase_OnDiscardSinOtherUnit);
    original_PassiveBase_OnDiscardSin = InstallHook<PassiveBaseOnDiscardSinFn>(PassiveDetailC.GetMethod("OnDiscardSin"), &hooked_PassiveBase_OnDiscardSin);
    original_PassiveBase_OnDisappeared = InstallHook<PassiveBaseOnDisappearedFn>(PassiveDetailC.GetMethod("OnDisappeared"), &hooked_PassiveBase_OnDisappeared);
    original_PassiveBase_OnReturnFromDisappeared = InstallHook<PassiveBaseOnReturnFromDisappearedFn>(PassiveDetailC.GetMethod("OnReturnFromDisappeared"), &hooked_PassiveBase_OnReturnFromDisappeared);
    original_PassiveBase_OnBreakOtherUnit = InstallHook<PassiveBaseOnBreakOtherUnitFn>(PassiveDetailC.GetMethod("OnBreakOtherUnit"), &hooked_PassiveBase_OnBreakOtherUnit);
    original_PassiveBase_OnCheckBreak = InstallHook<PassiveBaseOnCheckBreakFn>(PassiveDetailC.GetMethod("OnCheckBreak"), &hooked_PassiveBase_OnCheckBreak);
    original_PassiveBase_OnCheckPartBreak = InstallHook<PassiveBaseOnCheckPartBreakFn>(PassiveDetailC.GetMethod("OnCheckPartBreak"), &hooked_PassiveBase_OnCheckPartBreak);
    original_PassiveBase_OnVibrationExplosion = InstallHook<PassiveBaseOnVibrationExplosionFn>(PassiveDetailC.GetMethod("OnVibrationExplosion"), &hooked_PassiveBase_OnVibrationExplosion);
    original_PassiveBase_OnVibrationExplosionOtherUnit = InstallHook<PassiveBaseOnVibrationExplosionOtherUnitFn>(PassiveDetailC.GetMethod("OnVibrationExplosionOtherUnit"), &hooked_PassiveBase_OnVibrationExplosionOtherUnit);
    original_PassiveBase_OnTakeAttackDamageOtherUnit = InstallHook<PassiveBaseOnTakeAttackDamageOtherUnitFn>(PassiveDetailC.GetMethod("OnTakeAttackDamageOtherUnit"), &hooked_PassiveBase_OnTakeAttackDamageOtherUnit);
    original_PassiveBase_OnUseBuffStackBySkill = InstallHook<PassiveBaseOnUseBuffStackBySkillFn>(PassiveDetailC.GetMethod("OnUseBuffStackBySkill"), &hooked_PassiveBase_OnUseBuffStackBySkill);
    original_PassiveBase_OnUseBloodDinnerUnit = InstallHook<PassiveBaseOnUseBloodDinnerUnitFn>(PassiveDetailC.GetMethod("OnUseBloodDinnerUnit"), &hooked_PassiveBase_OnUseBloodDinnerUnit);
    original_PassiveBase_OnAddUnit = InstallHook<PassiveBaseOnAddUnitFn>(PassiveDetailC.GetMethod("OnAddUnit"), &hooked_PassiveBase_OnAddUnit);
    original_PassiveBase_OnAddUnit_After = InstallHook<PassiveBaseOnAddUnit_AfterFn>(PassiveDetailC.GetMethod("OnAddUnit_After"), &hooked_PassiveBase_OnAddUnit_After);
    original_PassiveBase_OnAddUnitPart = InstallHook<PassiveBaseOnAddUnitPartFn>(PassiveDetailC.GetMethod("OnAddUnitPart"), &hooked_PassiveBase_OnAddUnitPart);
    original_PassiveBase_Init_After = InstallHook<PassiveBaseInit_AfterFn>(PassiveDetailC.GetMethod("Init_After"), &hooked_PassiveBase_Init_After);
    original_PassiveBase_OnAddUnitView = InstallHook<PassiveBaseOnAddUnitViewFn>(PassiveDetailC.GetMethod("OnAddUnitView"), &hooked_PassiveBase_OnAddUnitView);
    original_PassiveBase_OnStageStart = InstallHook<PassiveBaseOnStageStartFn>(PassiveDetailC.GetMethod("OnStageStart"), &hooked_PassiveBase_OnStageStart);
    original_PassiveBase_OnWaveStart = InstallHook<PassiveBaseOnWaveStartFn>(PassiveDetailC.GetMethod("OnWaveStart"), &hooked_PassiveBase_OnWaveStart);
    original_PassiveBase_OnPanicOrLowMorale = InstallHook<PassiveBaseOnPanicOrLowMoraleFn>(PassiveDetailC.GetMethod("OnPanicOrLowMorale"), &hooked_PassiveBase_OnPanicOrLowMorale);
    original_PassiveBase_OnRoundStart_Before = InstallHook<PassiveBaseOnRoundStart_BeforeFn>(PassiveDetailC.GetMethod("OnRoundStart_Before"), &hooked_PassiveBase_OnRoundStart_Before);
    original_PassiveBase_OnRoundStart = InstallHook<PassiveBaseOnRoundStartFn>(PassiveDetailC.GetMethod("OnRoundStart"), &hooked_PassiveBase_OnRoundStart);
    original_PassiveBase_OnRoundStart_After_Event = InstallHook<PassiveBaseOnRoundStart_After_EventFn>(PassiveDetailC.GetMethod("OnRoundStart_After_Event"), &hooked_PassiveBase_OnRoundStart_After_Event);
    original_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated = InstallHook<PassiveBaseOnRoundStart_After_Event_DeadOrRetreatedFn>(PassiveDetailC.GetMethod("OnRoundStart_After_Event_DeadOrRetreated"), &hooked_PassiveBase_OnRoundStart_After_Event_DeadOrRetreated);
    original_PassiveBase_OnRoundStart_After_RelatedSlotState = InstallHook<PassiveBaseOnRoundStart_After_RelatedSlotStateFn>(PassiveDetailC.GetMethod("OnRoundStart_After_RelatedSlotState"), &hooked_PassiveBase_OnRoundStart_After_RelatedSlotState);
    original_PassiveBase_OnReturnToField = InstallHook<PassiveBaseOnReturnToFieldFn>(PassiveDetailC.GetMethod("OnReturnToField"), &hooked_PassiveBase_OnReturnToField);
    original_PassiveBase_OnReturnToFieldOtherUnit = InstallHook<PassiveBaseOnReturnToFieldOtherUnitFn>(PassiveDetailC.GetMethod("OnReturnToFieldOtherUnit"), &hooked_PassiveBase_OnReturnToFieldOtherUnit);
    original_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated = InstallHook<PassiveBaseOnReturnToFieldOtherUnit_DeadOrRetreatedFn>(PassiveDetailC.GetMethod("OnReturnToFieldOtherUnit_DeadOrRetreated"), &hooked_PassiveBase_OnReturnToFieldOtherUnit_DeadOrRetreated);
    original_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated = InstallHook<PassiveBaseOnReleaseStandByOtherUnit_DeadOrRetreatedFn>(PassiveDetailC.GetMethod("OnReleaseStandByOtherUnit_DeadOrRetreated"), &hooked_PassiveBase_OnReleaseStandByOtherUnit_DeadOrRetreated);
    original_PassiveBase_OnReleaseStandByOtherUnit = InstallHook<PassiveBaseOnReleaseStandByOtherUnitFn>(PassiveDetailC.GetMethod("OnReleaseStandByOtherUnit"), &hooked_PassiveBase_OnReleaseStandByOtherUnit);
    original_PassiveBase_OnReleaseStandBy = InstallHook<PassiveBaseOnReleaseStandByFn>(PassiveDetailC.GetMethod("OnReleaseStandBy"), &hooked_PassiveBase_OnReleaseStandBy);
    original_PassiveBase_OnCompleteCommand = InstallHook<PassiveBaseOnCompleteCommandFn>(PassiveDetailC.GetMethod("OnCompleteCommand"), &hooked_PassiveBase_OnCompleteCommand);
    original_PassiveBase_BeforeCompleteCommand = InstallHook<PassiveBaseBeforeCompleteCommandFn>(PassiveDetailC.GetMethod("BeforeCompleteCommand"), &hooked_PassiveBase_BeforeCompleteCommand);
    original_PassiveBase_OnChangeSkillBeforeCompleteCommand = InstallHook<PassiveBaseOnChangeSkillBeforeCompleteCommandFn>(PassiveDetailC.GetMethod("OnChangeSkillBeforeCompleteCommand"), &hooked_PassiveBase_OnChangeSkillBeforeCompleteCommand);
    original_PassiveBase_OnRoundEnd = InstallHook<PassiveBaseOnRoundEndFn>(PassiveDetailC.GetMethod("OnRoundEnd"), &hooked_PassiveBase_OnRoundEnd);
    original_PassiveBase_OnRoundEnd_Disappeared = InstallHook<PassiveBaseOnRoundEnd_DisappearedFn>(PassiveDetailC.GetMethod("OnRoundEnd_Disappeared"), &hooked_PassiveBase_OnRoundEnd_Disappeared);
    original_PassiveBase_OnRetreat = InstallHook<PassiveBaseOnRetreatFn>(PassiveDetailC.GetMethod("OnRetreat"), &hooked_PassiveBase_OnRetreat);
    original_PassiveBase_OnRoundEnd_After = InstallHook<PassiveBaseOnRoundEnd_AfterFn>(PassiveDetailC.GetMethod("OnRoundEnd_After"), &hooked_PassiveBase_OnRoundEnd_After);
    original_PassiveBase_OnStageEnd = InstallHook<PassiveBaseOnStageEndFn>(PassiveDetailC.GetMethod("OnStageEnd"), &hooked_PassiveBase_OnStageEnd);
    original_PassiveBase_OnBeforeDefense = InstallHook<PassiveBaseOnBeforeDefenseFn>(PassiveDetailC.GetMethod("OnBeforeDefense"), &hooked_PassiveBase_OnBeforeDefense);
    original_PassiveBase_OnStartRunBattle = InstallHook<PassiveBaseOnStartRunBattleFn>(PassiveDetailC.GetMethod("OnStartRunBattle"), &hooked_PassiveBase_OnStartRunBattle);
    original_PassiveBase_OnBattleStart = InstallHook<PassiveBaseOnBattleStartFn>(PassiveDetailC.GetMethod("OnBattleStart"), &hooked_PassiveBase_OnBattleStart);
    original_PassiveBase_OnBattleEnd = InstallHook<PassiveBaseOnBattleEndFn>(PassiveDetailC.GetMethod("OnBattleEnd"), &hooked_PassiveBase_OnBattleEnd);
    original_PassiveBase_OnBeforeTurn = InstallHook<PassiveBaseOnBeforeTurnFn>(PassiveDetailC.GetMethod("OnBeforeTurn"), &hooked_PassiveBase_OnBeforeTurn);
    original_PassiveBase_OnStartTurn_BeforeLog = InstallHook<PassiveBaseOnStartTurn_BeforeLogFn>(PassiveDetailC.GetMethod("OnStartTurn_BeforeLog"), &hooked_PassiveBase_OnStartTurn_BeforeLog);
    original_PassiveBase_OnStartTurn_AfterLog = InstallHook<PassiveBaseOnStartTurn_AfterLogFn>(PassiveDetailC.GetMethod("OnStartTurn_AfterLog"), &hooked_PassiveBase_OnStartTurn_AfterLog);
    original_PassiveBase_OnStartDuel = InstallHook<PassiveBaseOnStartDuelFn>(PassiveDetailC.GetMethod("OnStartDuel"), &hooked_PassiveBase_OnStartDuel);
    original_PassiveBase_BeforeGiveAttackDamage = InstallHook<PassiveBaseBeforeGiveAttackDamageFn>(PassiveDetailC.GetMethod("BeforeGiveAttackDamage"), &hooked_PassiveBase_BeforeGiveAttackDamage);
    original_PassiveBase_BeforeTakeAttackDamage = InstallHook<PassiveBaseBeforeTakeAttackDamageFn>(PassiveDetailC.GetMethod("BeforeTakeAttackDamage"), &hooked_PassiveBase_BeforeTakeAttackDamage);
    original_PassiveBase_BeforePartTakeAttackDamage = InstallHook<PassiveBaseBeforePartTakeAttackDamageFn>(PassiveDetailC.GetMethod("BeforePartTakeAttackDamage"), &hooked_PassiveBase_BeforePartTakeAttackDamage);
    original_PassiveBase_OnTakeAttackDamage = InstallHook<PassiveBaseOnTakeAttackDamageFn>(PassiveDetailC.GetMethod("OnTakeAttackDamage"), &hooked_PassiveBase_OnTakeAttackDamage);
    original_PassiveBase_OnTakeAttackDamagePart = InstallHook<PassiveBaseOnTakeAttackDamagePartFn>(PassiveDetailC.GetMethod("OnTakeAttackDamagePart"), &hooked_PassiveBase_OnTakeAttackDamagePart);
    original_PassiveBase_OnGiveHpDamage = InstallHook<PassiveBaseOnGiveHpDamageFn>(PassiveDetailC.GetMethod("OnGiveHpDamage"), &hooked_PassiveBase_OnGiveHpDamage);
    original_PassiveBase_OnGiveMpDamage = InstallHook<PassiveBaseOnGiveMpDamageFn>(PassiveDetailC.GetMethod("OnGiveMpDamage"), &hooked_PassiveBase_OnGiveMpDamage);
    original_PassiveBase_OnTakeMpDmg_SinBuff = InstallHook<PassiveBaseOnTakeMpDmg_SinBuffFn>(PassiveDetailC.GetMethod("OnTakeMpDmg_SinBuff"), &hooked_PassiveBase_OnTakeMpDmg_SinBuff);
    original_PassiveBase_OnKillTarget = InstallHook<PassiveBaseOnKillTargetFn>(PassiveDetailC.GetMethod("OnKillTarget"), &hooked_PassiveBase_OnKillTarget);
    original_PassiveBase_OnEndTurn = InstallHook<PassiveBaseOnEndTurnFn>(PassiveDetailC.GetMethod("OnEndTurn"), &hooked_PassiveBase_OnEndTurn);
    original_PassiveBase_OnBeforeStartCoin = InstallHook<PassiveBaseOnBeforeStartCoinFn>(PassiveDetailC.GetMethod("OnBeforeStartCoin"), &hooked_PassiveBase_OnBeforeStartCoin);
    original_PassiveBase_OnStartCoin = InstallHook<PassiveBaseOnStartCoinFn>(PassiveDetailC.GetMethod("OnStartCoin"), &hooked_PassiveBase_OnStartCoin);
    original_PassiveBase_OnEndCoin_BeforeLog = InstallHook<PassiveBaseOnEndCoin_BeforeLogFn>(PassiveDetailC.GetMethod("OnEndCoin_BeforeLog"), &hooked_PassiveBase_OnEndCoin_BeforeLog);
    original_PassiveBase_OnEndCoin_AfterLog = InstallHook<PassiveBaseOnEndCoin_AfterLogFn>(PassiveDetailC.GetMethod("OnEndCoin_AfterLog"), &hooked_PassiveBase_OnEndCoin_AfterLog);
    original_PassiveBase_OnEndBehaviour = InstallHook<PassiveBaseOnEndBehaviourFn>(PassiveDetailC.GetMethod("OnEndBehaviour"), &hooked_PassiveBase_OnEndBehaviour);
    original_PassiveBase_OnEndBehave_Refresh = InstallHook<PassiveBaseOnEndBehave_RefreshFn>(PassiveDetailC.GetMethod("OnEndBehave_Refresh"), &hooked_PassiveBase_OnEndBehave_Refresh);
    original_PassiveBase_OnCriticalActivated = InstallHook<PassiveBaseOnCriticalActivatedFn>(PassiveDetailC.GetMethod("OnCriticalActivated"), &hooked_PassiveBase_OnCriticalActivated);
    original_PassiveBase_BeforeAttack = InstallHook<PassiveBaseBeforeAttackFn>(PassiveDetailC.GetMethod("BeforeAttack"), &hooked_PassiveBase_BeforeAttack);
    original_PassiveBase_OnAttackConfirmed = InstallHook<PassiveBaseOnAttackConfirmedFn>(PassiveDetailC.GetMethod("OnAttackConfirmed"), &hooked_PassiveBase_OnAttackConfirmed);
    original_PassiveBase_CanTeamKill = InstallHook<PassiveBaseCanTeamKillFn>(PassiveDetailC.GetMethod("CanTeamKill"), &hooked_PassiveBase_CanTeamKill);
    original_PassiveBase_GetPrimeTargets = InstallHook<PassiveBaseGetPrimeTargetsFn>(PassiveDetailC.GetMethod("GetPrimeTargets"), &hooked_PassiveBase_GetPrimeTargets);
    original_PassiveBase_GetSkillPowerAdder = InstallHook<PassiveBaseGetSkillPowerAdderFn>(PassiveDetailC.GetMethod("GetSkillPowerAdder"), &hooked_PassiveBase_GetSkillPowerAdder);
    original_PassiveBase_GetExpectedSkillPowerResultAdder = InstallHook<PassiveBaseGetExpectedSkillPowerResultAdderFn>(PassiveDetailC.GetMethod("GetExpectedSkillPowerResultAdder"), &hooked_PassiveBase_GetExpectedSkillPowerResultAdder);
    original_PassiveBase_GetExpectedSkillPowerAdder = InstallHook<PassiveBaseGetExpectedSkillPowerAdderFn>(PassiveDetailC.GetMethod("GetExpectedSkillPowerAdder"), &hooked_PassiveBase_GetExpectedSkillPowerAdder);
    original_PassiveBase_HasPassive = InstallHook<PassiveBaseHasPassiveFn>(PassiveDetailC.GetMethod("HasPassive"), &hooked_PassiveBase_HasPassive);
    original_PassiveBase_OnStartPhase = InstallHook<PassiveBaseOnStartPhaseFn>(PassiveDetailC.GetMethod("OnStartPhase"), &hooked_PassiveBase_OnStartPhase);
    original_PassiveBase_HasFakeDead = InstallHook<PassiveBaseHasFakeDeadFn>(PassiveDetailC.GetMethod("HasFakeDead"), &hooked_PassiveBase_HasFakeDead);
    original_PassiveBase_OverwriteAtkResist_Default = InstallHook<PassiveBaseOverwriteAtkResist_DefaultFn>(PassiveDetailC.GetMethod("OverwriteAtkResist_Default"), &hooked_PassiveBase_OverwriteAtkResist_Default);
    original_PassiveBase_OverwriteAtkResist_Result = InstallHook<PassiveBaseOverwriteAtkResist_ResultFn>(PassiveDetailC.GetMethod("OverwriteAtkResist_Result"), &hooked_PassiveBase_OverwriteAtkResist_Result);
    original_PassiveBase_OverwriteAttributeDefaultResist = InstallHook<PassiveBaseOverwriteAttributeDefaultResistFn>(PassiveDetailC.GetMethod("OverwriteAttributeDefaultResist"), &hooked_PassiveBase_OverwriteAttributeDefaultResist);
    original_PassiveBase_OverwriteAttributeResist = InstallHook<PassiveBaseOverwriteAttributeResistFn>(PassiveDetailC.GetMethod("OverwriteAttributeResist"), &hooked_PassiveBase_OverwriteAttributeResist);
    original_PassiveBase_OverwriteMaxBuffStack = InstallHook<PassiveBaseOverwriteMaxBuffStackFn>(PassiveDetailC.GetMethod("OverwriteMaxBuffStack"), &hooked_PassiveBase_OverwriteMaxBuffStack);
    original_PassiveBase_OverwriteMaxBuffTurn = InstallHook<PassiveBaseOverwriteMaxBuffTurnFn>(PassiveDetailC.GetMethod("OverwriteMaxBuffTurn"), &hooked_PassiveBase_OverwriteMaxBuffTurn);
    original_PassiveBase_OverwriteSkillID = InstallHook<PassiveBaseOverwriteSkillIDFn>(PassiveDetailC.GetMethod("OverwriteSkillID"), &hooked_PassiveBase_OverwriteSkillID);
    original_PassiveBase_OverwriteSpeed = InstallHook<PassiveBaseOverwriteSpeedFn>(PassiveDetailC.GetMethod("OverwriteSpeed"), &hooked_PassiveBase_OverwriteSpeed);
    original_PassiveBase_CanChangeMainTargetRegardlessSpeed = InstallHook<PassiveBaseCanChangeMainTargetRegardlessSpeedFn>(PassiveDetailC.GetMethod("CanChangeMainTargetRegardlessSpeed"), &hooked_PassiveBase_CanChangeMainTargetRegardlessSpeed);
    original_PassiveBase_OnZeroHp = InstallHook<PassiveBaseOnZeroHpFn>(PassiveDetailC.GetMethod("OnZeroHp"), &hooked_PassiveBase_OnZeroHp);
    original_PassiveBase_GetParryingResultAdder = InstallHook<PassiveBaseGetParryingResultAdderFn>(PassiveDetailC.GetMethod("GetParryingResultAdder"), &hooked_PassiveBase_GetParryingResultAdder);
    original_PassiveBase_GetExpectedParryingResultAdder = InstallHook<PassiveBaseGetExpectedParryingResultAdderFn>(PassiveDetailC.GetMethod("GetExpectedParryingResultAdder"), &hooked_PassiveBase_GetExpectedParryingResultAdder);
    original_PassiveBase_GetOpponentParryingResultAdder = InstallHook<PassiveBaseGetOpponentParryingResultAdderFn>(PassiveDetailC.GetMethod("GetOpponentParryingResultAdder"), &hooked_PassiveBase_GetOpponentParryingResultAdder);
    original_PassiveBase_GetExpectedOpponentParryingResultAdder = InstallHook<PassiveBaseGetExpectedOpponentParryingResultAdderFn>(PassiveDetailC.GetMethod("GetExpectedOpponentParryingResultAdder"), &hooked_PassiveBase_GetExpectedOpponentParryingResultAdder);
    original_PassiveBase_ActivateEgoPassive = InstallHook<PassiveBaseActivateEgoPassiveFn>(PassiveDetailC.GetMethod("ActivateEgoPassive"), &hooked_PassiveBase_ActivateEgoPassive);
    original_PassiveBase_ActivateEquipEgoPassives = InstallHook<PassiveBaseActivateEquipEgoPassivesFn>(PassiveDetailC.GetMethod("ActivateEquipEgoPassives"), &hooked_PassiveBase_ActivateEquipEgoPassives);
    original_PassiveBase_ActivateEgoPassives = InstallHook<PassiveBaseActivateEgoPassivesFn>(PassiveDetailC.GetMethod("ActivateEgoPassives"), &hooked_PassiveBase_ActivateEgoPassives);
    original_PassiveBase_GetOwnerEgoModelList = InstallHook<PassiveBaseGetOwnerEgoModelListFn>(PassiveDetailC.GetMethod("GetOwnerEgoModelList"), &hooked_PassiveBase_GetOwnerEgoModelList);
    original_PassiveBase_FindEgoModel = InstallHook<PassiveBaseFindEgoModelFn>(PassiveDetailC.GetMethod("FindEgoModel"), &hooked_PassiveBase_FindEgoModel);
    original_PassiveBase_AddReadyEgoPassive = InstallHook<PassiveBaseAddReadyEgoPassiveFn>(PassiveDetailC.GetMethod("AddReadyEgoPassive"), &hooked_PassiveBase_AddReadyEgoPassive);
    original_PassiveBase_CanAddEgoPassive = InstallHook<PassiveBaseCanAddEgoPassiveFn>(PassiveDetailC.GetMethod("CanAddEgoPassive"), &hooked_PassiveBase_CanAddEgoPassive);
    original_PassiveBase_PassesCondition = InstallHook<PassiveBasePassesConditionFn>(PassiveDetailC.GetMethod("PassesCondition"), &hooked_PassiveBase_PassesCondition);
    original_PassiveBase_OnResult_OnAction = InstallHook<PassiveBaseOnResult_OnActionFn>(PassiveDetailC.GetMethod("OnResult_OnAction"), &hooked_PassiveBase_OnResult_OnAction);
    original_PassiveBase_OnResult_OnParrying = InstallHook<PassiveBaseOnResult_OnParryingFn>(PassiveDetailC.GetMethod("OnResult_OnParrying"), &hooked_PassiveBase_OnResult_OnParrying);
    original_PassiveBase_AddPassive = InstallHook<PassiveBaseAddPassiveFn>(PassiveDetailC.GetMethod("AddPassive"), &hooked_PassiveBase_AddPassive);
    original_PassiveBase_IsRegeneratable = InstallHook<PassiveBaseIsRegeneratableFn>(PassiveDetailC.GetMethod("IsRegeneratable"), &hooked_PassiveBase_IsRegeneratable);
    original_PassiveBase_SpreadHpDmgToAbnormality = InstallHook<PassiveBaseSpreadHpDmgToAbnormalityFn>(PassiveDetailC.GetMethod("SpreadHpDmgToAbnormality"), &hooked_PassiveBase_SpreadHpDmgToAbnormality);
    original_PassiveBase_SpreadHpDmgFromAbnormalityPart = InstallHook<PassiveBaseSpreadHpDmgFromAbnormalityPartFn>(PassiveDetailC.GetMethod("SpreadHpDmgFromAbnormalityPart"), &hooked_PassiveBase_SpreadHpDmgFromAbnormalityPart);
    original_PassiveBase_OnSucceedEvade = InstallHook<PassiveBaseOnSucceedEvadeFn>(PassiveDetailC.GetMethod("OnSucceedEvade"), &hooked_PassiveBase_OnSucceedEvade);
    original_PassiveBase_OnGiveBuffTrigger = InstallHook<PassiveBaseOnGiveBuffTriggerFn>(PassiveDetailC.GetMethod("OnGiveBuffTrigger"), &hooked_PassiveBase_OnGiveBuffTrigger);
    original_PassiveBase_RightBeforeLosingBuff = InstallHook<PassiveBaseRightBeforeLosingBuffFn>(PassiveDetailC.GetMethod("RightBeforeLosingBuff"), &hooked_PassiveBase_RightBeforeLosingBuff);
    original_PassiveBase_CanCreateEmptySlot = InstallHook<PassiveBaseCanCreateEmptySlotFn>(PassiveDetailC.GetMethod("CanCreateEmptySlot"), &hooked_PassiveBase_CanCreateEmptySlot);
    original_PassiveBase_CanCreateEmptySlotPart = InstallHook<PassiveBaseCanCreateEmptySlotPartFn>(PassiveDetailC.GetMethod("CanCreateEmptySlotPart"), &hooked_PassiveBase_CanCreateEmptySlotPart);
    original_PassiveBase_GetActionSlotAdder = InstallHook<PassiveBaseGetActionSlotAdderFn>(PassiveDetailC.GetMethod("GetActionSlotAdder"), &hooked_PassiveBase_GetActionSlotAdder);
    original_PassiveBase_GetMaxHpAdder = InstallHook<PassiveBaseGetMaxHpAdderFn>(PassiveDetailC.GetMethod("GetMaxHpAdder"), &hooked_PassiveBase_GetMaxHpAdder);
    original_PassiveBase_GetMaxHpMultiplier = InstallHook<PassiveBaseGetMaxHpMultiplierFn>(PassiveDetailC.GetMethod("GetMaxHpMultiplier"), &hooked_PassiveBase_GetMaxHpMultiplier);
    original_PassiveBase_GetMaxHpMultiplierPartToAbnormality = InstallHook<PassiveBaseGetMaxHpMultiplierPartToAbnormalityFn>(PassiveDetailC.GetMethod("GetMaxHpMultiplierPartToAbnormality"), &hooked_PassiveBase_GetMaxHpMultiplierPartToAbnormality);
    original_PassiveBase_GetMaxHpMultiplierContributionToAbnormality = InstallHook<PassiveBaseGetMaxHpMultiplierContributionToAbnormalityFn>(PassiveDetailC.GetMethod("GetMaxHpMultiplierContributionToAbnormality"), &hooked_PassiveBase_GetMaxHpMultiplierContributionToAbnormality);
    original_PassiveBase_CanTakeMpHeal = InstallHook<PassiveBaseCanTakeMpHealFn>(PassiveDetailC.GetMethod("CanTakeMpHeal"), &hooked_PassiveBase_CanTakeMpHeal);
    original_PassiveBase_OnAfterTryTakeHpHeal = InstallHook<PassiveBaseOnAfterTryTakeHpHealFn>(PassiveDetailC.GetMethod("OnAfterTryTakeHpHeal"), &hooked_PassiveBase_OnAfterTryTakeHpHeal);
    original_PassiveBase_OnBeforeTryTakeMpHeal = InstallHook<PassiveBaseOnBeforeTryTakeMpHealFn>(PassiveDetailC.GetMethod("OnBeforeTryTakeMpHeal"), &hooked_PassiveBase_OnBeforeTryTakeMpHeal);
    original_PassiveBase_OnAfterTryTakeMpHeal = InstallHook<PassiveBaseOnAfterTryTakeMpHealFn>(PassiveDetailC.GetMethod("OnAfterTryTakeMpHeal"), &hooked_PassiveBase_OnAfterTryTakeMpHeal);
    original_PassiveBase_CheckImmortal = InstallHook<PassiveBaseCheckImmortalFn>(PassiveDetailC.GetMethod("CheckImmortal"), &hooked_PassiveBase_CheckImmortal);
    original_PassiveBase_CheckImmortalOtherUnit = InstallHook<PassiveBaseCheckImmortalOtherUnitFn>(PassiveDetailC.GetMethod("CheckImmortalOtherUnit"), &hooked_PassiveBase_CheckImmortalOtherUnit);
    original_PassiveBase_OnGiveImmortalState = InstallHook<PassiveBaseOnGiveImmortalStateFn>(PassiveDetailC.GetMethod("OnGiveImmortalState"), &hooked_PassiveBase_OnGiveImmortalState);
    original_PassiveBase_OnBeforeActivateImmortality = InstallHook<PassiveBaseOnBeforeActivateImmortalityFn>(PassiveDetailC.GetMethod("OnBeforeActivateImmortality"), &hooked_PassiveBase_OnBeforeActivateImmortality);
    original_PassiveBase_OnActivateImmortality = InstallHook<PassiveBaseOnActivateImmortalityFn>(PassiveDetailC.GetMethod("OnActivateImmortality"), &hooked_PassiveBase_OnActivateImmortality);
    original_PassiveBase_OnActivateAbnormalityImmortality = InstallHook<PassiveBaseOnActivateAbnormalityImmortalityFn>(PassiveDetailC.GetMethod("OnActivateAbnormalityImmortality"), &hooked_PassiveBase_OnActivateAbnormalityImmortality);
    original_PassiveBase_OnActivateOtherUnitBurstReactive = InstallHook<PassiveBaseOnActivateOtherUnitBurstReactiveFn>(PassiveDetailC.GetMethod("OnActivateOtherUnitBurstReactive"), &hooked_PassiveBase_OnActivateOtherUnitBurstReactive);
    original_PassiveBase_OnBurstReactiveActivatedAnyUnit = InstallHook<PassiveBaseOnBurstReactiveActivatedAnyUnitFn>(PassiveDetailC.GetMethod("OnBurstReactiveActivatedAnyUnit"), &hooked_PassiveBase_OnBurstReactiveActivatedAnyUnit);
    original_PassiveBase_OnAddShield = InstallHook<PassiveBaseOnAddShieldFn>(PassiveDetailC.GetMethod("OnAddShield"), &hooked_PassiveBase_OnAddShield);
    original_PassiveBase_OnReduceShield = InstallHook<PassiveBaseOnReduceShieldFn>(PassiveDetailC.GetMethod("OnReduceShield"), &hooked_PassiveBase_OnReduceShield);
    original_PassiveBase_OnDestroyShield = InstallHook<PassiveBaseOnDestroyShieldFn>(PassiveDetailC.GetMethod("OnDestroyShield"), &hooked_PassiveBase_OnDestroyShield);
    original_PassiveBase_OnDestoryShieldPart = InstallHook<PassiveBaseOnDestoryShieldPartFn>(PassiveDetailC.GetMethod("OnDestoryShieldPart"), &hooked_PassiveBase_OnDestoryShieldPart);
    original_PassiveBase_OnRecoverBreak = InstallHook<PassiveBaseOnRecoverBreakFn>(PassiveDetailC.GetMethod("OnRecoverBreak"), &hooked_PassiveBase_OnRecoverBreak);
    original_PassiveBase_OnGiveBsGaugeUp = InstallHook<PassiveBaseOnGiveBsGaugeUpFn>(PassiveDetailC.GetMethod("OnGiveBsGaugeUp"), &hooked_PassiveBase_OnGiveBsGaugeUp);
    original_PassiveBase_OnTakeHpDamage = InstallHook<PassiveBaseOnTakeHpDamageFn>(PassiveDetailC.GetMethod("OnTakeHpDamage"), &hooked_PassiveBase_OnTakeHpDamage);
    original_PassiveBase_OnTakeHpDamagePart = InstallHook<PassiveBaseOnTakeHpDamagePartFn>(PassiveDetailC.GetMethod("OnTakeHpDamagePart"), &hooked_PassiveBase_OnTakeHpDamagePart);
    original_PassiveBase_OnTakeHpDamageOtherUnit = InstallHook<PassiveBaseOnTakeHpDamageOtherUnitFn>(PassiveDetailC.GetMethod("OnTakeHpDamageOtherUnit"), &hooked_PassiveBase_OnTakeHpDamageOtherUnit);
    original_PassiveBase_OnTryTakeHpDamage = InstallHook<PassiveBaseOnTryTakeHpDamageFn>(PassiveDetailC.GetMethod("OnTryTakeHpDamage"), &hooked_PassiveBase_OnTryTakeHpDamage);
    original_PassiveBase_GetTakeHpHealMultiplier = InstallHook<PassiveBaseGetTakeHpHealMultiplierFn>(PassiveDetailC.GetMethod("GetTakeHpHealMultiplier"), &hooked_PassiveBase_GetTakeHpHealMultiplier);
    original_PassiveBase_OnTakeAttackConfirmed = InstallHook<PassiveBaseOnTakeAttackConfirmedFn>(PassiveDetailC.GetMethod("OnTakeAttackConfirmed"), &hooked_PassiveBase_OnTakeAttackConfirmed);
    original_PassiveBase_GetMaxHpAdderPart = InstallHook<PassiveBaseGetMaxHpAdderPartFn>(PassiveDetailC.GetMethod("GetMaxHpAdderPart"), &hooked_PassiveBase_GetMaxHpAdderPart);
    original_PassiveBase_GetTakeHpHealMultiplierPart = InstallHook<PassiveBaseGetTakeHpHealMultiplierPartFn>(PassiveDetailC.GetMethod("GetTakeHpHealMultiplierPart"), &hooked_PassiveBase_GetTakeHpHealMultiplierPart);
    original_PassiveBase_GetTakeHpHealAdder = InstallHook<PassiveBaseGetTakeHpHealAdderFn>(PassiveDetailC.GetMethod("GetTakeHpHealAdder"), &hooked_PassiveBase_GetTakeHpHealAdder);
    original_PassiveBase_OverwriteTargetableList = InstallHook<PassiveBaseOverwriteTargetableListFn>(PassiveDetailC.GetMethod("OverwriteTargetableList"), &hooked_PassiveBase_OverwriteTargetableList);
    original_PassiveBase_OverwriteAtkResistWhenDestroyed = InstallHook<PassiveBaseOverwriteAtkResistWhenDestroyedFn>(PassiveDetailC.GetMethod("OverwriteAtkResistWhenDestroyed"), &hooked_PassiveBase_OverwriteAtkResistWhenDestroyed);
    original_PassiveBase_OnChangeHp = InstallHook<PassiveBaseOnChangeHpFn>(PassiveDetailC.GetMethod("OnChangeHp"), &hooked_PassiveBase_OnChangeHp);
    original_PassiveBase_OnChangeMp = InstallHook<PassiveBaseOnChangeMpFn>(PassiveDetailC.GetMethod("OnChangeMp"), &hooked_PassiveBase_OnChangeMp);
    original_PassiveBase_OnChangeMpOther = InstallHook<PassiveBaseOnChangeMpOtherFn>(PassiveDetailC.GetMethod("OnChangeMpOther"), &hooked_PassiveBase_OnChangeMpOther);
    original_PassiveBase_OnTakeMpDamage = InstallHook<PassiveBaseOnTakeMpDamageFn>(PassiveDetailC.GetMethod("OnTakeMpDamage"), &hooked_PassiveBase_OnTakeMpDamage);
    original_PassiveBase_OnTakeMpDamageOther = InstallHook<PassiveBaseOnTakeMpDamageOtherFn>(PassiveDetailC.GetMethod("OnTakeMpDamageOther"), &hooked_PassiveBase_OnTakeMpDamageOther);
    original_PassiveBase_OnAfterTryTakeMpHealOther = InstallHook<PassiveBaseOnAfterTryTakeMpHealOtherFn>(PassiveDetailC.GetMethod("OnAfterTryTakeMpHealOther"), &hooked_PassiveBase_OnAfterTryTakeMpHealOther);
    original_PassiveBase_UnlockAllPassives = InstallHook<PassiveBaseUnlockAllPassivesFn>(PassiveDetailC.GetMethod("UnlockAllPassives"), &hooked_PassiveBase_UnlockAllPassives);
    original_PassiveBase_OnUseBuffTurnBySkill = InstallHook<PassiveBaseOnUseBuffTurnBySkillFn>(PassiveDetailC.GetMethod("OnUseBuffTurnBySkill"), &hooked_PassiveBase_OnUseBuffTurnBySkill);
    original_PassiveBase_OnUseBuff = InstallHook<PassiveBaseOnUseBuffFn>(PassiveDetailC.GetMethod("OnUseBuff"), &hooked_PassiveBase_OnUseBuff);
    original_PassiveBase_BeforeUseBuff = InstallHook<PassiveBaseBeforeUseBuffFn>(PassiveDetailC.GetMethod("BeforeUseBuff"), &hooked_PassiveBase_BeforeUseBuff);
    original_PassiveBase_GetCoinProbAdder = InstallHook<PassiveBaseGetCoinProbAdderFn>(PassiveDetailC.GetMethod("GetCoinProbAdder"), &hooked_PassiveBase_GetCoinProbAdder);
    original_PassiveBase_OverwriteCoinProb = InstallHook<PassiveBaseOverwriteCoinProbFn>(PassiveDetailC.GetMethod("OverwriteCoinProb"), &hooked_PassiveBase_OverwriteCoinProb);
    original_PassiveBase_IsEgoSkillFree = InstallHook<PassiveBaseIsEgoSkillFreeFn>(PassiveDetailC.GetMethod("IsEgoSkillFree"), &hooked_PassiveBase_IsEgoSkillFree);
    original_PassiveBase_OnPickSkills = InstallHook<PassiveBaseOnPickSkillsFn>(PassiveDetailC.GetMethod("OnPickSkills"), &hooked_PassiveBase_OnPickSkills);
    original_PassiveBase_OnAddActionToPart = InstallHook<PassiveBaseOnAddActionToPartFn>(PassiveDetailC.GetMethod("OnAddActionToPart"), &hooked_PassiveBase_OnAddActionToPart);
    original_PassiveBase_OnAddCoinByAbility = InstallHook<PassiveBaseOnAddCoinByAbilityFn>(PassiveDetailC.GetMethod("OnAddCoinByAbility"), &hooked_PassiveBase_OnAddCoinByAbility);
    original_PassiveBase_CanOverwritePanicType = InstallHook<PassiveBaseCanOverwritePanicTypeFn>(PassiveDetailC.GetMethod("CanOverwritePanicType"), &hooked_PassiveBase_CanOverwritePanicType);
    original_PassiveBase_GetCriticalChanceAdder = InstallHook<PassiveBaseGetCriticalChanceAdderFn>(PassiveDetailC.GetMethod("GetCriticalChanceAdder"), &hooked_PassiveBase_GetCriticalChanceAdder);
    original_PassiveBase_GetCriticalDamageRatioResultMultiplier = InstallHook<PassiveBaseGetCriticalDamageRatioResultMultiplierFn>(PassiveDetailC.GetMethod("GetCriticalDamageRatioResultMultiplier"), &hooked_PassiveBase_GetCriticalDamageRatioResultMultiplier);
    original_PassiveBase_RightAfterDestroyAnyBuff = InstallHook<PassiveBaseRightAfterDestroyAnyBuffFn>(PassiveDetailC.GetMethod("RightAfterDestroyAnyBuff"), &hooked_PassiveBase_RightAfterDestroyAnyBuff);
    original_PassiveBase_IsAbnormalityImmortal = InstallHook<PassiveBaseIsAbnormalityImmortalFn>(PassiveDetailC.GetMethod("IsAbnormalityImmortal"), &hooked_PassiveBase_IsAbnormalityImmortal);
    original_PassiveBase_CheckIfTurnToCorpesOnDie = InstallHook<PassiveBaseCheckIfTurnToCorpesOnDieFn>(PassiveDetailC.GetMethod("CheckIfTurnToCorpesOnDie"), &hooked_PassiveBase_CheckIfTurnToCorpesOnDie);
    original_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin = InstallHook<PassiveBaseOnCanceledByLackOfBuffsAtStartCoinFn>(PassiveDetailC.GetMethod("OnCanceledByLackOfBuffsAtStartCoin"), &hooked_PassiveBase_OnCanceledByLackOfBuffsAtStartCoin);
    original_PassiveBase_CheckOverwriteGettingBuff = InstallHook<PassiveBaseCheckOverwriteGettingBuffFn>(PassiveDetailC.GetMethod("CheckOverwriteGettingBuff"), &hooked_PassiveBase_CheckOverwriteGettingBuff);
    original_PassiveBase_IsAllowedToGiveBuff = InstallHook<PassiveBaseIsAllowedToGiveBuffFn>(PassiveDetailC.GetMethod("IsAllowedToGiveBuff"), &hooked_PassiveBase_IsAllowedToGiveBuff);
    original_PassiveBase_OnFailedToGetBuff = InstallHook<PassiveBaseOnFailedToGetBuffFn>(PassiveDetailC.GetMethod("OnFailedToGetBuff"), &hooked_PassiveBase_OnFailedToGetBuff);
    original_PassiveBase_RightAfterFailingGetAnyBuff = InstallHook<PassiveBaseRightAfterFailingGetAnyBuffFn>(PassiveDetailC.GetMethod("RightAfterFailingGetAnyBuff"), &hooked_PassiveBase_RightAfterFailingGetAnyBuff);
    original_PassiveBase_OnFailedToGiveBuff = InstallHook<PassiveBaseOnFailedToGiveBuffFn>(PassiveDetailC.GetMethod("OnFailedToGiveBuff"), &hooked_PassiveBase_OnFailedToGiveBuff);
    original_PassiveBase_OnUseCoinConsume = InstallHook<PassiveBaseOnUseCoinConsumeFn>(PassiveDetailC.GetMethod("OnUseCoinConsume"), &hooked_PassiveBase_OnUseCoinConsume);
    original_PassiveBase_BlockGivingBuff = InstallHook<PassiveBaseBlockGivingBuffFn>(PassiveDetailC.GetMethod("BlockGivingBuff"), &hooked_PassiveBase_BlockGivingBuff);
    original_PassiveBase_OverwritePartSpeed = InstallHook<PassiveBaseOverwritePartSpeedFn>(PassiveDetailC.GetMethod("OverwritePartSpeed"), &hooked_PassiveBase_OverwritePartSpeed);
    original_PassiveBase_BlockLoseBuffByReactWithAction = InstallHook<PassiveBaseBlockLoseBuffByReactWithActionFn>(PassiveDetailC.GetMethod("BlockLoseBuffByReactWithAction"), &hooked_PassiveBase_BlockLoseBuffByReactWithAction);
    original_PassiveBase_BlockLoseBuffStack = InstallHook<PassiveBaseBlockLoseBuffStackFn>(PassiveDetailC.GetMethod("BlockLoseBuffStack"), &hooked_PassiveBase_BlockLoseBuffStack);
    original_PassiveBase_BlockLoseBuffTurn = InstallHook<PassiveBaseBlockLoseBuffTurnFn>(PassiveDetailC.GetMethod("BlockLoseBuffTurn"), &hooked_PassiveBase_BlockLoseBuffTurn);
    original_PassiveBase_IsBlockingSinkingBuffEffectReact = InstallHook<PassiveBaseIsBlockingSinkingBuffEffectReactFn>(PassiveDetailC.GetMethod("IsBlockingSinkingBuffEffectReact"), &hooked_PassiveBase_IsBlockingSinkingBuffEffectReact);
    original_PassiveBase_IsBlockingTargetSinkingBuffEffectReact = InstallHook<PassiveBaseIsBlockingTargetSinkingBuffEffectReactFn>(PassiveDetailC.GetMethod("IsBlockingTargetSinkingBuffEffectReact"), &hooked_PassiveBase_IsBlockingTargetSinkingBuffEffectReact);
    original_PassiveBase_OverwriteCanDuel = InstallHook<PassiveBaseOverwriteCanDuelFn>(PassiveDetailC.GetMethod("OverwriteCanDuel"), &hooked_PassiveBase_OverwriteCanDuel);
    original_PassiveBase_IsBlockingBurstBuffEffectReact = InstallHook<PassiveBaseIsBlockingBurstBuffEffectReactFn>(PassiveDetailC.GetMethod("IsBlockingBurstBuffEffectReact"), &hooked_PassiveBase_IsBlockingBurstBuffEffectReact);
    original_PassiveBase_IsBlockingTargetBurstBuffEffectReact = InstallHook<PassiveBaseIsBlockingTargetBurstBuffEffectReactFn>(PassiveDetailC.GetMethod("IsBlockingTargetBurstBuffEffectReact"), &hooked_PassiveBase_IsBlockingTargetBurstBuffEffectReact);
    original_PassiveBase_ModifyMpChangeValue = InstallHook<PassiveBaseModifyMpChangeValueFn>(PassiveDetailC.GetMethod("ModifyMpChangeValue"), &hooked_PassiveBase_ModifyMpChangeValue);
    original_PassiveBase_OnAddBattleAction = InstallHook<PassiveBaseOnAddBattleActionFn>(PassiveDetailC.GetMethod("OnAddBattleAction"), &hooked_PassiveBase_OnAddBattleAction);
    original_PassiveBase_OnRemoveBattleAction = InstallHook<PassiveBaseOnRemoveBattleActionFn>(PassiveDetailC.GetMethod("OnRemoveBattleAction"), &hooked_PassiveBase_OnRemoveBattleAction);
    original_PassiveBase_IsRunUniqueAction = InstallHook<PassiveBaseIsRunUniqueActionFn>(PassiveDetailC.GetMethod("IsRunUniqueAction"), &hooked_PassiveBase_IsRunUniqueAction);

    original_PassiveBase_ctor = InstallHook<PassiveBasectorFn>(PassiveDetailC.GetMethod(".ctor"), &hooked_PassiveBase_ctor);

    hook::ONLY_LOG_HOOKS_ON_ERROR = false;
}

} // myosotis::testmod
