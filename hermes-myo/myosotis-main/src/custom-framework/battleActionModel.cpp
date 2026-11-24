#include <cstdint>
#include <iostream>
#include <functional>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "il2cpp.hpp"
#include "hermesUtils.hpp"
#include "custom-framework/battleActionModel.hpp"


namespace myosotis::testmod {

// =============================================================================
// PassiveBase default behaviour: void -> do nothing, non-void -> return returnValue untouched.
// =============================================================================

#pragma region

// C#: UnitSinModel get_Sin()
il2cpp::Il2CppObject* BattleActionModel::get_Sin(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: BattleUnitModel get_Model()
il2cpp::Il2CppObject* BattleActionModel::get_Model(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: SkillModel get_Skill()
il2cpp::Il2CppObject* BattleActionModel::get_Skill(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Boolean get_IsDone()
bool BattleActionModel::get_IsDone(bool returnValue) { return returnValue; }

// C#: System.Boolean get_isDoneWithAction()
bool BattleActionModel::get_isDoneWithAction(bool returnValue) { return returnValue; }

// C#: System.Int32 get_skillPowerResultValue()
int32_t BattleActionModel::get_skillPowerResultValue(int32_t returnValue) { return returnValue; }

// C#: System.Int32 get_ReusedTimes()
int32_t BattleActionModel::get_ReusedTimes(int32_t returnValue) { return returnValue; }

// C#: SinActionModel get_SinAction()
il2cpp::Il2CppObject* BattleActionModel::get_SinAction(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Int32 get_ActionInstanceID()
int32_t BattleActionModel::get_ActionInstanceID(int32_t returnValue) { return returnValue; }

// C#: System.Int32 get_CommanderInstanceID()
int32_t BattleActionModel::get_CommanderInstanceID(int32_t returnValue) { return returnValue; }

// C#: System.Int32 get_OrderedActionInstanceId()
int32_t BattleActionModel::get_OrderedActionInstanceId(int32_t returnValue) { return returnValue; }

// C#: System.Int32 get_OrderedActionActorInstanceId()
int32_t BattleActionModel::get_OrderedActionActorInstanceId(int32_t returnValue) { return returnValue; }

// C#: System.Boolean get_IsExtracted()
bool BattleActionModel::get_IsExtracted(bool returnValue) { return returnValue; }

// C#: BattleUnitModel get_Commander()
il2cpp::Il2CppObject* BattleActionModel::get_Commander(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: ABILITY_SOURCE_TYPE get_OrderSourceType()
int32_t BattleActionModel::get_OrderSourceType(int32_t returnValue) { return returnValue; }

// C#: System.Void SetTargetDetailType(BattleUnitModel model, System.Boolean isReuseAction)
void BattleActionModel::SetTargetDetailType(il2cpp::Il2CppObject* model, bool isReuseAction) {}

// C#: System.Void InitCoins()
void BattleActionModel::InitCoins() {}

// C#: System.Void InitCoinResults()
void BattleActionModel::InitCoinResults() {}

// C#: System.Void InitStaticData()
void BattleActionModel::InitStaticData() {}

// C#: System.Boolean IsActivatedSupportiveProtectByThisAction()
bool BattleActionModel::IsActivatedSupportiveProtectByThisAction(bool returnValue) { return returnValue; }

// C#: System.Void CheckActivationOfSupportiveProtect()
void BattleActionModel::CheckActivationOfSupportiveProtect() {}

// C#: System.Boolean IsSupportiveDefense_Old()
bool BattleActionModel::IsSupportiveDefense_Old(bool returnValue) { return returnValue; }

// C#: System.Boolean IsSupportiveDefense()
bool BattleActionModel::IsSupportiveDefense(bool returnValue) { return returnValue; }

// C#: System.Void RemoveTargetData(System.Boolean returnPrevTarget)
void BattleActionModel::RemoveTargetData(bool returnPrevTarget) {}

// C#: System.Collections.Generic.List<SinActionModel> GetOriginTargetSinActionsData(System.Boolean isOverlap)
il2cpp::Il2CppObject* BattleActionModel::GetOriginTargetSinActionsData(il2cpp::Il2CppObject* returnValue, bool isOverlap) { return returnValue; }

// C#: BattleUnitModel GetOriginMainTarget()
il2cpp::Il2CppObject* BattleActionModel::GetOriginMainTarget(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Boolean HasOriginTarget()
bool BattleActionModel::HasOriginTarget(bool returnValue) { return returnValue; }

// C#: System.Boolean HasMainTarget()
bool BattleActionModel::HasMainTarget(bool returnValue) { return returnValue; }

// C#: System.Boolean HasSubTarget()
bool BattleActionModel::HasSubTarget(bool returnValue) { return returnValue; }

// C#: SinActionModel GetMainTargetSinAction()
il2cpp::Il2CppObject* BattleActionModel::GetMainTargetSinAction(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<SinActionModel> GetSubTargetSinActionList()
il2cpp::Il2CppObject* BattleActionModel::GetSubTargetSinActionList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<SinActionModel> GetTargetSinActionList()
il2cpp::Il2CppObject* BattleActionModel::GetTargetSinActionList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: BattleUnitModel GetMainTarget()
il2cpp::Il2CppObject* BattleActionModel::GetMainTarget(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetUnitModelList()
il2cpp::Il2CppObject* BattleActionModel::GetTargetUnitModelList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<BattleUnitModel> GetAliveTargetUnitModelList()
il2cpp::Il2CppObject* BattleActionModel::GetAliveTargetUnitModelList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Void SetOriginTargetSinActions(System.Collections.Generic.List<SinActionModel> originTargetSinActions)
void BattleActionModel::SetOriginTargetSinActions(il2cpp::Il2CppObject* originTargetSinActions) {}

// C#: System.Void ReadyOriginTargeting()
void BattleActionModel::ReadyOriginTargeting() {}

// C#: System.Void AddTarget(SinActionModel targetSinAction)
void BattleActionModel::AddTarget(il2cpp::Il2CppObject* targetSinAction) {}

// C#: System.Void SetTargetAfterBattleStart(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void BattleActionModel::SetTargetAfterBattleStart(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {}

// C#: System.Void RedirectTarget(System.Boolean mainTargetAlive)
void BattleActionModel::RedirectTarget(bool mainTargetAlive) {}

// C#: System.Void SetTargetAuto(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void BattleActionModel::SetTargetAuto(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {}

// C#: System.Void SetTargetBySortedTargetableSinActionList(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
void BattleActionModel::SetTargetBySortedTargetableSinActionList(bool canDuel, bool attackEnemyOnly, int32_t targetType) {}

// C#: System.Void SetTargetAfterBattleStart_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void BattleActionModel::SetTargetAfterBattleStart_CutIn(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {}

// C#: System.Void SetTargetAuto_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void BattleActionModel::SetTargetAuto_CutIn(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {}

// C#: System.Void SetTargetBySortedTargetableSinActionList_CutIn(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
void BattleActionModel::SetTargetBySortedTargetableSinActionList_CutIn(bool canDuel, bool attackEnemyOnly, int32_t targetType) {}

// C#: System.Void RemoveOneTargetSet(BattleActionModel otherAction)
void BattleActionModel::RemoveOneTargetSet(il2cpp::Il2CppObject* otherAction) {}

// C#: System.Boolean CanDuelWithSameFaction()
bool BattleActionModel::CanDuelWithSameFaction(bool returnValue) { return returnValue; }

// C#: System.Void SetTarget(System.Collections.Generic.List<SinActionModel> sortedTargetSinActions, System.Boolean canDuel)
void BattleActionModel::SetTarget(il2cpp::Il2CppObject* sortedTargetSinActions, bool canDuel) {}

// C#: System.Void RecheckTargetList()
void BattleActionModel::RecheckTargetList() {}

// C#: System.Void AfterRecheckTargetList(System.Boolean valid, System.Boolean mainTargetAlive)
void BattleActionModel::AfterRecheckTargetList(bool valid, bool mainTargetAlive) {}

// C#: System.Void ChangeAllTargetOnCompleteCommand(System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void BattleActionModel::ChangeAllTargetOnCompleteCommand(bool attackEnemyOnly, int32_t overwritedTargetType) {}

// C#: System.Void ChangeMainTargetSinAction(SinActionModel changeTargetSinAction, BattleActionModel oppositeAction, System.Boolean forcely)
void BattleActionModel::ChangeMainTargetSinAction(il2cpp::Il2CppObject* changeTargetSinAction, il2cpp::Il2CppObject* oppositeAction, bool forcely) {}

// C#: System.Boolean HasBeenChangedCurrentTargetBy(BattleActionModel oppositeAction)
bool BattleActionModel::HasBeenChangedCurrentTargetBy(bool returnValue, il2cpp::Il2CppObject* oppositeAction) { return returnValue; }

// C#: System.Void ChangeAllSubTarget()
void BattleActionModel::ChangeAllSubTarget() {}

// C#: System.Void RecheckSubTargetWhenChangeTargetNum(System.Nullable<System.Boolean> overwriteAttackEnemyOnly, SKILL_TARGET_TYPE overwriteTargetType)
void BattleActionModel::RecheckSubTargetWhenChangeTargetNum(il2cpp::Il2CppObject* overwriteAttackEnemyOnly, int32_t overwriteTargetType) {}

// C#: System.Void RemoveAllTargetExceptMainTarget()
void BattleActionModel::RemoveAllTargetExceptMainTarget() {}

// C#: System.Void RemoveUntargetableTarget()
void BattleActionModel::RemoveUntargetableTarget() {}

// C#: System.Int32 GetCurrentOccupiedWeight()
int32_t BattleActionModel::GetCurrentOccupiedWeight_P0(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetCurrentOccupiedWeight(SinActionModel targetSinAction)
int32_t BattleActionModel::GetCurrentOccupiedWeight_P1(int32_t returnValue, il2cpp::Il2CppObject* targetSinAction) { return returnValue; }

// C#: System.Void AddPrimeTargets(System.Boolean canDuel)
void BattleActionModel::AddPrimeTargets(bool canDuel) {}

// C#: System.Boolean GetPrimeTargetSinActions(System.Collections.Generic.List<TargetSinActionData>& primeTargetSinActions, System.Int32& remainedSlotNum)
bool BattleActionModel::GetPrimeTargetSinActions(bool returnValue, il2cpp::Il2CppObject** primeTargetSinActions, int32_t* remainedSlotNum) { return returnValue; }

// C#: System.Collections.Generic.List<SinActionModel> GetSatisfiedPrimeTargetSinActions()
il2cpp::Il2CppObject* BattleActionModel::GetSatisfiedPrimeTargetSinActions(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<SinActionModel> ExtractSortedPrimeTargetSinActionList(System.Collections.Generic.List<PrimeTargetData> primeTargetDatas)
il2cpp::Il2CppObject* BattleActionModel::ExtractSortedPrimeTargetSinActionList(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* primeTargetDatas) { return returnValue; }

// C#: System.Collections.Generic.List<SinActionModel> GetCollapsedTargetableSinActionList(System.Collections.Generic.List<SinActionModel> addedTargetSinActions, System.Nullable<System.Boolean> attackEnemyOnly, SKILL_TARGET_TYPE targetType, System.Boolean canAttackAllyAssist)
il2cpp::Il2CppObject* BattleActionModel::GetCollapsedTargetableSinActionList(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* addedTargetSinActions, il2cpp::Il2CppObject* attackEnemyOnly, int32_t targetType, bool canAttackAllyAssist) { return returnValue; }

// C#: System.Void SortSinActionList(System.Collections.Generic.List<SinActionModel> list, SKILL_TARGET_TYPE targetType)
void BattleActionModel::SortSinActionList(il2cpp::Il2CppObject* list, int32_t targetType) {}

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetableUnitList(System.Boolean canAttackAllyAssist)
il2cpp::Il2CppObject* BattleActionModel::GetTargetableUnitList(il2cpp::Il2CppObject* returnValue, bool canAttackAllyAssist) { return returnValue; }

// C#: System.Void SortTargetSlots(System.Collections.Generic.List<SinActionModel> targetSinActions, SKILL_TARGET_TYPE targetType)
void BattleActionModel::SortTargetSlots(il2cpp::Il2CppObject* targetSinActions, int32_t targetType) {}

// C#: System.Single GetExpectedEgoErodeRate(BattleEgoModel egoModel)
float BattleActionModel::GetExpectedEgoErodeRate(float returnValue, il2cpp::Il2CppObject* egoModel) { return returnValue; }

// C#: System.Boolean IsConsumeBuffSkill(BUFF_UNIQUE_KEYWORD buff)
bool BattleActionModel::IsConsumeBuffSkill(bool returnValue, int32_t buff) { return returnValue; }

// C#: System.Boolean IsConsumeBullet()
bool BattleActionModel::IsConsumeBullet(bool returnValue) { return returnValue; }

// C#: System.Boolean IsUseBuff(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool BattleActionModel::IsUseBuff(bool returnValue, int32_t buff, int32_t targetType) { return returnValue; }

// C#: System.Boolean IsUseBuffStack(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool BattleActionModel::IsUseBuffStack(bool returnValue, int32_t buff, int32_t targetType) { return returnValue; }

// C#: System.Boolean IsUseBuffTurn(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool BattleActionModel::IsUseBuffTurn(bool returnValue, int32_t buff, int32_t targetType) { return returnValue; }

// C#: System.Boolean IsAddBloodDinner()
bool BattleActionModel::IsAddBloodDinner(bool returnValue) { return returnValue; }

// C#: PairWithTargetUnitSinSet GetExpectedAllCalculationOnlyAbnormalityBattle()
il2cpp::Il2CppObject* BattleActionModel::GetExpectedAllCalculationOnlyAbnormalityBattle(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Void MakeReusable()
void BattleActionModel::MakeReusable() {}

// C#: System.Void ResetAllTargetData()
void BattleActionModel::ResetAllTargetData() {}

// C#: System.Void ResetCoinState()
void BattleActionModel::ResetCoinState() {}

// C#: System.Void ResetDataWIthOutTargetData()
void BattleActionModel::ResetDataWIthOutTargetData() {}

// C#: System.Void AddAttackedTarget(BattleUnitModel target)
void BattleActionModel::AddAttackedTarget(il2cpp::Il2CppObject* target) {}

// C#: System.Collections.Generic.List<BattleUnitModel> GetAttackedTargetList()
il2cpp::Il2CppObject* BattleActionModel::GetAttackedTargetList(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Void CheckCoinDestroy(BattleActionModel winnerAction)
void BattleActionModel::CheckCoinDestroy(il2cpp::Il2CppObject* winnerAction) {}

// C#: CoinModel GetHighestCoin()
il2cpp::Il2CppObject* BattleActionModel::GetHighestCoin(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: CoinModel GetDestroyTargetCoin()
il2cpp::Il2CppObject* BattleActionModel::GetDestroyTargetCoin(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Int32 GetSkillID()
int32_t BattleActionModel::GetSkillID(int32_t returnValue) { return returnValue; }

// C#: SKILL_TARGET_TYPE GetSkillTargetType()
int32_t BattleActionModel::GetSkillTargetType(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetAttackWeight()
int32_t BattleActionModel::GetAttackWeight(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetOriginAttackWeight()
int32_t BattleActionModel::GetOriginAttackWeight(int32_t returnValue) { return returnValue; }

// C#: DEFENSE_TYPE GetDefenseType()
int32_t BattleActionModel::GetDefenseType(int32_t returnValue) { return returnValue; }

// C#: ATK_BEHAVIOUR GetSkillAtkType()
int32_t BattleActionModel::GetSkillAtkType(int32_t returnValue) { return returnValue; }

// C#: System.Boolean TryGetOverwriteAtkBehaviour(CoinModel coin, ATK_BEHAVIOUR& atkBehaviour)
bool BattleActionModel::TryGetOverwriteAtkBehaviour(bool returnValue, il2cpp::Il2CppObject* coin, int32_t* atkBehaviour) { return returnValue; }

// C#: System.Boolean IsSkillAtkType(ATK_BEHAVIOUR type)
bool BattleActionModel::IsSkillAtkType(bool returnValue, int32_t type) { return returnValue; }

// C#: ATTRIBUTE_TYPE GetSkillAttributeType()
int32_t BattleActionModel::GetSkillAttributeType(int32_t returnValue) { return returnValue; }

// C#: System.Boolean IsSkillAttributeType(ATTRIBUTE_TYPE type)
bool BattleActionModel::IsSkillAttributeType(bool returnValue, int32_t type) { return returnValue; }

// C#: System.Boolean IsAttack()
bool BattleActionModel::IsAttack(bool returnValue) { return returnValue; }

// C#: System.Boolean IsDefense()
bool BattleActionModel::IsDefense(bool returnValue) { return returnValue; }

// C#: System.Boolean IsDefenseNotCounter()
bool BattleActionModel::IsDefenseNotCounter(bool returnValue) { return returnValue; }

// C#: System.Boolean IsGuard()
bool BattleActionModel::IsGuard(bool returnValue) { return returnValue; }

// C#: System.Boolean IsCounter()
bool BattleActionModel::IsCounter(bool returnValue) { return returnValue; }

// C#: System.Boolean IsCanDuelDefense()
bool BattleActionModel::IsCanDuelDefense(bool returnValue) { return returnValue; }

// C#: System.Boolean IsEvade()
bool BattleActionModel::IsEvade(bool returnValue) { return returnValue; }

// C#: System.Boolean IgnoreDefenseSkill(BattleUnitModel target)
bool BattleActionModel::IgnoreDefenseSkill(bool returnValue, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Boolean IgnoreSupportiveDefense(BattleUnitModel originTarget, BattleUnitModel supportiveDefender)
bool BattleActionModel::IgnoreSupportiveDefense(bool returnValue, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* supportiveDefender) { return returnValue; }

// C#: System.Boolean IsActionable()
bool BattleActionModel::IsActionable(bool returnValue) { return returnValue; }

// C#: System.Void OnAttackCanceledByAbility(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnAttackCanceledByAbility(int32_t timing) {}

// C#: System.Boolean CanBeChangedTarget(BattleActionModel oppoAction)
bool BattleActionModel::CanBeChangedTarget(bool returnValue, il2cpp::Il2CppObject* oppoAction) { return returnValue; }

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleActionModel otherAction)
bool BattleActionModel::CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* otherAction) { return returnValue; }

// C#: System.Boolean CanBeChangedTargetIgnoreSpeed(BattleActionModel otherAction)
bool BattleActionModel::CanBeChangedTargetIgnoreSpeed(bool returnValue, il2cpp::Il2CppObject* otherAction) { return returnValue; }

// C#: System.Void ChangeEgoSkill(System.Boolean isOverClock)
void BattleActionModel::ChangeEgoSkill(bool isOverClock) {}

// C#: System.Boolean TryChangeSkill(System.Int32 skillID)
bool BattleActionModel::TryChangeSkill(bool returnValue, int32_t skillID) { return returnValue; }

// C#: System.Boolean ChangeSkill(SkillModel skill, System.Boolean saveOriginSkill)
bool BattleActionModel::ChangeSkill(bool returnValue, il2cpp::Il2CppObject* skill, bool saveOriginSkill) { return returnValue; }

// C#: System.Void ReturnPreviousSkill()
void BattleActionModel::ReturnPreviousSkill() {}

// C#: System.Int32 GetResonanceIndexOrStack()
int32_t BattleActionModel::GetResonanceIndexOrStack(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetExpectedResonanceIndexOrStack()
int32_t BattleActionModel::GetExpectedResonanceIndexOrStack_P0(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetExpectedResonanceIndexOrStack(System.Collections.Generic.List<System.Int32> indexes)
int32_t BattleActionModel::GetExpectedResonanceIndexOrStack_P1(int32_t returnValue, il2cpp::Il2CppObject* indexes) { return returnValue; }

// C#: System.Int32 GetAttributeResonanceIndex()
int32_t BattleActionModel::GetAttributeResonanceIndex(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetPerfectResonanceStack()
int32_t BattleActionModel::GetPerfectResonanceStack(int32_t returnValue) { return returnValue; }

// C#: System.Void CheckResonancePassive()
void BattleActionModel::CheckResonancePassive() {}

// C#: System.Void OnAttributeResonance()
void BattleActionModel::OnAttributeResonance() {}

// C#: System.Boolean HasCommander(System.Int32& commander)
bool BattleActionModel::HasCommander(bool returnValue, int32_t* commander) { return returnValue; }

// C#: System.Void SetDefenseLevel_After_UseSkill()
void BattleActionModel::SetDefenseLevel_After_UseSkill() {}

// C#: System.Void ModifySpeedByParrying(System.Int32 speed)
void BattleActionModel::ModifySpeedByParrying(int32_t speed) {}

// C#: System.Void ResetSpeedByParrying()
void BattleActionModel::ResetSpeedByParrying() {}

// C#: System.Int32 RollSkillPower(CoinModel coin, OneCoinLog oneCoinLog, System.Int32 idx, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, System.Nullable<System.Boolean> isWinDuel, System.Boolean calculateSystemAdder)
int32_t BattleActionModel::RollSkillPower(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oneCoinLog, int32_t idx, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* isWinDuel, bool calculateSystemAdder) { return returnValue; }

// C#: ParryingData RollSkillPowerParrying(BattleActionModel oppoAction, BattleLog_Parrying parryingLog, ParryingStatus parryingStatus)
il2cpp::Il2CppObject* BattleActionModel::RollSkillPowerParrying(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* parryingLog, il2cpp::Il2CppObject* parryingStatus) { return returnValue; }

// C#: SkillPowerData CreateSkillPowerData(System.Boolean isValid, BATTLE_EVENT_TIMING timing, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, CoinModel coinOrNull)
il2cpp::Il2CppObject* BattleActionModel::CreateSkillPowerData(il2cpp::Il2CppObject* returnValue, bool isValid, int32_t timing, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* coinOrNull) { return returnValue; }

// C#: ParryingData CreateParryingData(System.Boolean isValid)
il2cpp::Il2CppObject* BattleActionModel::CreateParryingData(il2cpp::Il2CppObject* returnValue, bool isValid) { return returnValue; }

// C#: System.Boolean CanRollAllCoinForUI(System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs)
bool BattleActionModel::CanRollAllCoinForUI(bool returnValue, il2cpp::Il2CppObject** lackOfBuffs) { return returnValue; }

// C#: System.Boolean IsRetreatSkill()
bool BattleActionModel::IsRetreatSkill(bool returnValue) { return returnValue; }

// C#: System.Boolean IsCommandRetreatSkill()
bool BattleActionModel::IsCommandRetreatSkill(bool returnValue) { return returnValue; }

// C#: System.Boolean CanRollCoin(CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs, System.Boolean& forceToEndSkill)
bool BattleActionModel::CanRollCoin(bool returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** lackOfBuffs, bool* forceToEndSkill) { return returnValue; }

// C#: System.Void Behave(BattleRunLog runLog, BattleLog actionLog, BattleActionModel attackerActionOrNull, System.Boolean isLoserAttackExpected, BattleActionModel loserActionOrNull)
void BattleActionModel::Behave(il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull, bool isLoserAttackExpected, il2cpp::Il2CppObject* loserActionOrNull) {}

// C#: System.Boolean BeforeCompleteCommand(BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
bool BattleActionModel::BeforeCompleteCommand(bool returnValue, int32_t timing, int32_t* newSkillID) { return returnValue; }

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnChangeSkillBeforeCompleteCommand(int32_t timing) {}

// C#: System.Void ActivateGuard(BattleRunLog runLog, BattleLog_Guard actionLog, BattleActionModel attackerActionOrNull)
void BattleActionModel::ActivateGuard(il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull) {}

// C#: System.Void CheckOneOnOneDuelState()
void BattleActionModel::CheckOneOnOneDuelState() {}

// C#: System.Boolean IsOneOnOneDuel(BattleActionModel opponentAction)
bool BattleActionModel::IsOneOnOneDuel(bool returnValue, il2cpp::Il2CppObject* opponentAction) { return returnValue; }

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnCompleteCommand(int32_t timing) {}

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnBattleStart(int32_t timing) {}

// C#: System.Boolean CanAttackTargets()
bool BattleActionModel::CanAttackTargets(bool returnValue) { return returnValue; }

// C#: System.Boolean CheckTargetableTarget()
bool BattleActionModel::CheckTargetableTarget(bool returnValue) { return returnValue; }

// C#: System.Void OnEndBehave_Refresh(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnEndBehave_Refresh(int32_t timing) {}

// C#: System.Void AffectToReturnUnit(System.Collections.Generic.List<OnReleaseStandByOrOnReturnData> list)
void BattleActionModel::AffectToReturnUnit(il2cpp::Il2CppObject* list) {}

// C#: System.Void CallTargetDefenseActionsByAttack(BattleRunLog runLog, DEFENSE_TYPE type, System.Boolean isDuelExpected, System.Boolean canDuel, BATTLE_EVENT_TIMING timing, OneCoinLog_Attack oneCoinLog, BattleUnitModel specificTarget, System.Boolean mainTargetExclusive)
void BattleActionModel::CallTargetDefenseActionsByAttack(il2cpp::Il2CppObject* runLog, int32_t type, bool isDuelExpected, bool canDuel, int32_t timing, il2cpp::Il2CppObject* oneCoinLog, il2cpp::Il2CppObject* specificTarget, bool mainTargetExclusive) {}

// C#: System.Void OnRoundStart_After()
void BattleActionModel::OnRoundStart_After() {}

// C#: System.Void OnBeforeTurn(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnBeforeTurn(int32_t timing) {}

// C#: System.Void OnCancelAction()
void BattleActionModel::OnCancelAction() {}

// C#: System.Void OnBeforeDefense(BattleActionModel attackerActionOrNull)
void BattleActionModel::OnBeforeDefense(il2cpp::Il2CppObject* attackerActionOrNull) {}

// C#: System.Void OnStartTurn_BeforeLog(BATTLE_EVENT_TIMING timing, System.Boolean isDuelExpected)
void BattleActionModel::OnStartTurn_BeforeLog(int32_t timing, bool isDuelExpected) {}

// C#: System.Void OnStartTurn_AfterLog(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnStartTurn_AfterLog(int32_t timing) {}

// C#: System.Void OnTryEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnTryEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing) {}

// C#: System.Void OnStartDuel(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnStartDuel(il2cpp::Il2CppObject* opponentAction, int32_t timing) {}

// C#: System.Void OnBeforeParryingOnce(BattleActionModel oppoAction)
void BattleActionModel::OnBeforeParryingOnce(il2cpp::Il2CppObject* oppoAction) {}

// C#: System.Void OnBeforeParryingOnce_AfterLog(BattleActionModel oppoAction)
void BattleActionModel::OnBeforeParryingOnce_AfterLog(il2cpp::Il2CppObject* oppoAction) {}

// C#: System.Void OnDuelAfter_BeforeLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 parryingCount, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void BattleActionModel::OnDuelAfter_BeforeLog(int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {}

// C#: System.Void OnDuelAfter_AfterLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnDuelAfter_AfterLog(int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing) {}

// C#: System.Void OnAfterParryingOnce_BeforeLog(BattleActionModel opponentAction, PARRYING_RESULT reuslt, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* opponentAction, int32_t reuslt, int32_t parryingCnt, int32_t timing) {}

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void BattleActionModel::OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {}

// C#: System.Void OnWinParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnWinParrying(il2cpp::Il2CppObject* opponentAction, int32_t timing) {}

// C#: System.Void OnLoseParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnLoseParrying(il2cpp::Il2CppObject* opponentAction, int32_t timing) {}

// C#: System.Void OnWinDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void BattleActionModel::OnWinDuel(il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {}

// C#: System.Void CheckExtractAbility(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::CheckExtractAbility(il2cpp::Il2CppObject* opponentAction, int32_t timing) {}

// C#: System.Void FirstBsGaugeUpWithDuelableGuard(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLog)
void BattleActionModel::FirstBsGaugeUpWithDuelableGuard(il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLog) {}

// C#: System.Void OnLoseDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnLoseDuel(il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing) {}

// C#: System.Void BeforeBehaviour(BATTLE_EVENT_TIMING timing)
void BattleActionModel::BeforeBehaviour(int32_t timing) {}

// C#: System.Void OnStartBehaviour(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnStartBehaviour(int32_t timing) {}

// C#: System.Void OnCriticalIsActivated(CoinModel coin, BATTLE_EVENT_TIMING timing, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
void BattleActionModel::OnCriticalIsActivated(il2cpp::Il2CppObject* coin, int32_t timing, il2cpp::Il2CppObject* affectKeywords) {}

// C#: System.Void OnAttackConfirmed(CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
void BattleActionModel::OnAttackConfirmed(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing, bool isCritical) {}

// C#: System.Void BeforeGiveAttackDamage(CoinModel coin, BattleUnitModel target, System.Nullable<System.Boolean> isWinDuel, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
void BattleActionModel::BeforeGiveAttackDamage(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* isWinDuel, bool isCritical, int32_t timing) {}

// C#: System.Void OnSucceedAttack(CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnSucceedAttack(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {}

// C#: System.Boolean CanGiveConcentratedAttack()
bool BattleActionModel::CanGiveConcentratedAttack(bool returnValue) { return returnValue; }

// C#: System.Void OnSucceedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnSucceedEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing) {}

// C#: System.Void OnFailedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnFailedEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing) {}

// C#: System.Void OnStartCoin(CoinModel coin, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnStartCoin(il2cpp::Il2CppObject* coin, int32_t timing) {}

// C#: System.Void OnEndCoin_BeforeLog(CoinModel coin, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnEndCoin_BeforeLog(il2cpp::Il2CppObject* coin, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {}

// C#: System.Void OnEndCoin_AfterLog(CoinModel coin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnEndCoin_AfterLog(il2cpp::Il2CppObject* coin, bool isCritical, int32_t timing) {}

// C#: System.Void OnEndAttack(System.Int32 accumulatedDmg, System.Int32 accumulatedHpDmg, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing, BattleLog_Duel duelLogOrNull)
void BattleActionModel::OnEndAttack(int32_t accumulatedDmg, int32_t accumulatedHpDmg, il2cpp::Il2CppObject* isWinDuel, int32_t timing, il2cpp::Il2CppObject* duelLogOrNull) {}

// C#: System.Void OnEndBehaviour(BattleRunLog runLog, BATTLE_EVENT_TIMING timing, System.Boolean isLoserAttackExpected)
void BattleActionModel::OnEndBehaviour(il2cpp::Il2CppObject* runLog, int32_t timing, bool isLoserAttackExpected) {}

// C#: System.Void OnGiveBsGaugeUp(CoinModel coinOrNull, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion)
void BattleActionModel::OnGiveBsGaugeUp(il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion) {}

// C#: System.Void OnEndTurn(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnEndTurn(int32_t timing) {}

// C#: System.Void OnDiscarded(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnDiscarded(int32_t timing) {}

// C#: System.Void OnKillTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnKillTarget(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {}

// C#: System.Void OnBreakTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnBreakTarget(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {}

// C#: System.Void OnDestroyTargetPart(BattleUnitModel_Abnormality_Part target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnDestroyTargetPart(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {}

// C#: System.Void Done()
void BattleActionModel::Done() {}

// C#: System.Void DoneWithAction(BATTLE_EVENT_TIMING timing)
void BattleActionModel::DoneWithAction(int32_t timing) {}

// C#: System.Void AddSinStock()
void BattleActionModel::AddSinStock() {}

// C#: System.Int32 GetExpectedMinCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
int32_t BattleActionModel::GetExpectedMinCoinValue_P2_1(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetExpectedMaxCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
int32_t BattleActionModel::GetExpectedMaxCoinValue_P2_1(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetExpectedMinCoinValue(UnitSinModel oppoSin, System.Int32& adder)
int32_t BattleActionModel::GetExpectedMinCoinValue_P2_2(int32_t returnValue, il2cpp::Il2CppObject* oppoSin, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetExpectedMaxCoinValue(UnitSinModel oppoSin, System.Int32& adder)
int32_t BattleActionModel::GetExpectedMaxCoinValue_P2_2(int32_t returnValue, il2cpp::Il2CppObject* oppoSin, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetExpectedCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
int32_t BattleActionModel::GetExpectedCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamage()
int32_t BattleActionModel::GetExpectedRateOfIncreaseAndDecreaseDamage(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(SinActionModel targetSinActionOrNull, BattleActionModel targetActionOrNull)
int32_t BattleActionModel::GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(int32_t returnValue, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedDamage(CalculationType type, System.Collections.Generic.List<System.Int32> indexes, SinActionModel targetSinActionOrNull, BattleActionModel oppoActionOrNull)
int32_t BattleActionModel::GetExpectedDamage(int32_t returnValue, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedDamageByTarget(CalculationType type, SinActionModel targetSinAction, BattleActionModel targetActionOrNull, System.Collections.Generic.List<System.Int32> indexes)
int32_t BattleActionModel::GetExpectedDamageByTarget(int32_t returnValue, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* targetActionOrNull, il2cpp::Il2CppObject* indexes) { return returnValue; }

// C#: System.Boolean IsDuelExpcted(BattleActionModel oppoAction)
bool BattleActionModel::IsDuelExpcted(bool returnValue, il2cpp::Il2CppObject* oppoAction) { return returnValue; }

// C#: System.Int32 GetParryingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
int32_t BattleActionModel::GetParryingCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetDamageCalculation(SinActionModel targetSinActionOrNull, BattleActionModel targetActionModelOrNull, System.Boolean isMin, System.Int32& adder)
int32_t BattleActionModel::GetDamageCalculation(int32_t returnValue, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionModelOrNull, bool isMin, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetSnowBallingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Boolean isOpponentEvade, System.Int32& adder)
int32_t BattleActionModel::GetSnowBallingCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, bool isOpponentEvade, int32_t* adder) { return returnValue; }

// C#: System.Int32 GetDefaultAllCoinCalculation(System.Boolean isMin, System.Boolean isParrying, System.Boolean isOpponentEvade)
int32_t BattleActionModel::GetDefaultAllCoinCalculation(int32_t returnValue, bool isMin, bool isParrying, bool isOpponentEvade) { return returnValue; }

// C#: System.Int32 GetParryingAdder(BattleActionModel oppoActionOrNull)
int32_t BattleActionModel::GetParryingAdder(int32_t returnValue, il2cpp::Il2CppObject* oppoActionOrNull) { return returnValue; }

// C#: System.Int32 GetMinExpectedDamage(SinActionModel targetSinAction, System.Collections.Generic.List<System.Int32> selectedIndexes)
int32_t BattleActionModel::GetMinExpectedDamage(int32_t returnValue, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* selectedIndexes) { return returnValue; }

// C#: System.Single GetCriticalChance(CoinModel coin, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single>& affectKeywords)
float BattleActionModel::GetCriticalChance(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** affectKeywords) { return returnValue; }

// C#: System.Boolean CanTeamKill()
bool BattleActionModel::CanTeamKill(bool returnValue) { return returnValue; }

// C#: System.Int32 GetSkillLevel(System.Int32 resonanceIndex, System.Int32& allCorrectionValue, System.Int32& effectCorrectionValue)
int32_t BattleActionModel::GetSkillLevel(int32_t returnValue, int32_t resonanceIndex, int32_t* allCorrectionValue, int32_t* effectCorrectionValue) { return returnValue; }

// C#: System.Int32 GetSkillPower(COIN_ROLL_TYPE rollType, BATTLE_EVENT_TIMING timing, System.Collections.Generic.List<CoinModel> coinList, BattleActionModel attackerActionOrNull)
int32_t BattleActionModel::GetSkillPower(int32_t returnValue, int32_t rollType, int32_t timing, il2cpp::Il2CppObject* coinList, il2cpp::Il2CppObject* attackerActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull, BattleActionModel attackerActionOrNull)
int32_t BattleActionModel::GetExpectedSkillPower_P3_1(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, System.Collections.Generic.List<System.Int32> indexes, SinActionModel expectedTargetSinActionOrNull)
int32_t BattleActionModel::GetExpectedSkillPower_P3_2(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetCoinScale(CoinModel coin, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
int32_t BattleActionModel::GetCoinScale(int32_t returnValue, il2cpp::Il2CppObject* coin, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) { return returnValue; }

// C#: System.Nullable<System.Int32> OverrideCoinScale(CoinModel coin, System.Int32 originScaleAdder)
il2cpp::Il2CppObject* BattleActionModel::OverrideCoinScale(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* coin, int32_t originScaleAdder) { return returnValue; }

// C#: System.Int32 GetExpectedCoinScale(CoinModel coin, COIN_ROLL_TYPE rollType, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
int32_t BattleActionModel::GetExpectedCoinScale(int32_t returnValue, il2cpp::Il2CppObject* coin, int32_t rollType, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
int32_t BattleActionModel::GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Int32 GetExpectedAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
int32_t BattleActionModel::GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Int32 GetCoinScaleAdder(CoinModel coin, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
int32_t BattleActionModel::GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedCoinScaleAdder(CoinModel coin, COIN_ROLL_TYPE rollType, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
int32_t BattleActionModel::GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, int32_t rollType, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetSkillPowerResultAdder(BATTLE_EVENT_TIMING timing, BattleActionModel attackerActionOrNull, System.Boolean calculateSystemAdder, CoinModel coinOrNull)
int32_t BattleActionModel::GetSkillPowerResultAdder(int32_t returnValue, int32_t timing, il2cpp::Il2CppObject* attackerActionOrNull, bool calculateSystemAdder, il2cpp::Il2CppObject* coinOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPowerAdder(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
int32_t BattleActionModel::GetExpectedSkillPowerAdder(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetExpectedSkillPowerResultAdder(System.Collections.Generic.List<System.Int32> indexes, SinActionModel opppoSinActionOrNull, BattleActionModel oppoActionOrNull)
int32_t BattleActionModel::GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* opppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull) { return returnValue; }

// C#: System.Single GetAttackDmgMultiplier(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical, System.Boolean isOneSideAttack, OneCoinLog_Attack forEditorItCanBeNull)
float BattleActionModel::GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical, bool isOneSideAttack, il2cpp::Il2CppObject* forEditorItCanBeNull) { return returnValue; }

// C#: System.Single GetExpectedAttackDmgMultiplier(CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
float BattleActionModel::GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) { return returnValue; }

// C#: System.Int32 GetAttackDmgAdder(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel)
int32_t BattleActionModel::GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel) { return returnValue; }

// C#: System.Int32 GetExpectedAttackDmgAdder(CoinModel coin, BattleUnitModel targetOrNull)
int32_t BattleActionModel::GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull) { return returnValue; }

// C#: System.Int32 GetOppoSkillPowerResultAdderOnTakeAtkDmg()
int32_t BattleActionModel::GetOppoSkillPowerResultAdderOnTakeAtkDmg(int32_t returnValue) { return returnValue; }

// C#: static System.Boolean BothCanDuelAndAttackSkill(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* BattleActionModel::BothCanDuelAndAttackSkill(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) { return returnValue; }

// C#: static System.Boolean BothCanDuelAndAtLeastOneAttackSkill(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* BattleActionModel::BothCanDuelAndAtLeastOneAttackSkill(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) { return returnValue; }

// C#: static System.Boolean CanDuelBoth(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* BattleActionModel::CanDuelBoth(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) { return returnValue; }

// C#: System.Boolean CanDuel(BattleActionModel opponentAction)
bool BattleActionModel::CanDuel(bool returnValue, il2cpp::Il2CppObject* opponentAction) { return returnValue; }

// C#: System.Boolean CanDuelWithoutCheckNull(BattleActionModel opponentAction)
bool BattleActionModel::CanDuelWithoutCheckNull(bool returnValue, il2cpp::Il2CppObject* opponentAction) { return returnValue; }

// C#: System.Boolean IsPanicBlock()
bool BattleActionModel::IsPanicBlock(bool returnValue) { return returnValue; }

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action, BattleUnitModel target)
il2cpp::Il2CppObject* BattleActionModel::GetDescArgs_P2(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action)
il2cpp::Il2CppObject* BattleActionModel::GetDescArgs_P1(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action) { return returnValue; }

// C#: System.Boolean IsAllCoinHead()
bool BattleActionModel::IsAllCoinHead(bool returnValue) { return returnValue; }

// C#: System.Boolean IsAllCoinHit()
bool BattleActionModel::IsAllCoinHit(bool returnValue) { return returnValue; }

// C#: System.Int32 GetHeadCoinNum()
int32_t BattleActionModel::GetHeadCoinNum(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetTailCoinNum()
int32_t BattleActionModel::GetTailCoinNum(int32_t returnValue) { return returnValue; }

// C#: System.Int32 GetUsableInDuelCoinNum()
int32_t BattleActionModel::GetUsableInDuelCoinNum(int32_t returnValue) { return returnValue; }

// C#: System.Boolean IsFirstCoin(CoinModel coin)
bool BattleActionModel::IsFirstCoin(bool returnValue, il2cpp::Il2CppObject* coin) { return returnValue; }

// C#: System.Boolean IsLastCoin(CoinModel coin)
bool BattleActionModel::IsLastCoin(bool returnValue, il2cpp::Il2CppObject* coin) { return returnValue; }

// C#: System.Boolean CheckPersonalitySkillSpecificType(SKILL_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool BattleActionModel::CheckPersonalitySkillSpecificType(bool returnValue, int32_t keyword, int32_t targetType) { return returnValue; }

// C#: System.Boolean CheckSkillGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool BattleActionModel::CheckSkillGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Boolean CheckSkillGivingBuff(BUFF_UNIQUE_KEYWORD buffKeyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool BattleActionModel::CheckSkillGivingBuff(bool returnValue, int32_t buffKeyword, int32_t targetType, bool* stackGiver, bool* turnGiver) { return returnValue; }

// C#: System.Boolean IsGainBullet()
bool BattleActionModel::IsGainBullet(bool returnValue) { return returnValue; }

// C#: CoinModel GetCoin(System.Int32 i)
il2cpp::Il2CppObject* BattleActionModel::GetCoin(il2cpp::Il2CppObject* returnValue, int32_t i) { return returnValue; }

// C#: CoinModel GetFirstCoin()
il2cpp::Il2CppObject* BattleActionModel::GetFirstCoin(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: CoinModel GetLastCoin()
il2cpp::Il2CppObject* BattleActionModel::GetLastCoin(il2cpp::Il2CppObject* returnValue) { return returnValue; }

// C#: System.Int32 GetMpUsage(System.Boolean isErodeSkill)
int32_t BattleActionModel::GetMpUsage(int32_t returnValue, bool isErodeSkill) { return returnValue; }

// C#: System.Boolean IsMultiTarget()
bool BattleActionModel::IsMultiTarget(bool returnValue) { return returnValue; }

// C#: System.Boolean IsReusedAction()
bool BattleActionModel::IsReusedAction(bool returnValue) { return returnValue; }

// C#: System.Void BeforeAttack(BATTLE_EVENT_TIMING timing)
void BattleActionModel::BeforeAttack(int32_t timing) {}

// C#: System.Int32 GetFinalSkillPowerResult(BATTLE_EVENT_TIMING timing)
int32_t BattleActionModel::GetFinalSkillPowerResult(int32_t returnValue, int32_t timing) { return returnValue; }

// C#: System.Int32 GetParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
int32_t BattleActionModel::GetParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) { return returnValue; }

// C#: System.Int32 GetExpectedParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
int32_t BattleActionModel::GetExpectedParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) { return returnValue; }

// C#: System.Int32 GetOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t BattleActionModel::GetOpponentParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) { return returnValue; }

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t BattleActionModel::GetExpectedOpponentParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) { return returnValue; }

// C#: System.Void OverWriteSkill(System.Int32 defaultValue, System.Int32 coinNum, System.Int32 coinScale, OPERATOR_TYPE operatorType)
void BattleActionModel::OverWriteSkill(int32_t defaultValue, int32_t coinNum, int32_t coinScale, int32_t operatorType) {}

// C#: System.Boolean IsRandomTarget()
bool BattleActionModel::IsRandomTarget(bool returnValue) { return returnValue; }

// C#: System.Boolean IsTargetableSlot(SinActionModel attackerSinAction)
bool BattleActionModel::IsTargetableSlot(bool returnValue, il2cpp::Il2CppObject* attackerSinAction) { return returnValue; }

// C#: System.Boolean IsSkillAbsorbingThisDamage()
bool BattleActionModel::IsSkillAbsorbingThisDamage(bool returnValue) { return returnValue; }

// C#: System.Boolean IsDefenseSkillForOther(BattleUnitModel originTarget, BattleActionModel opponentActionOrNull)
bool BattleActionModel::IsDefenseSkillForOther(bool returnValue, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* opponentActionOrNull) { return returnValue; }

// C#: System.Boolean AttackByMpDmgRatherThanHpDmg(CoinModel coin, System.Int32 resultDmg, BattleUnitModel target)
bool BattleActionModel::AttackByMpDmgRatherThanHpDmg(bool returnValue, il2cpp::Il2CppObject* coin, int32_t resultDmg, il2cpp::Il2CppObject* target) { return returnValue; }

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool BattleActionModel::BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* target, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Int32 ChangeAttackDamage(CoinModel coin, BattleUnitModel target, System.Int32 resultDmg, System.Boolean& isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
int32_t BattleActionModel::ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t resultDmg, bool* isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) { return returnValue; }

// C#: System.Void OnSkillChangedEgo(System.Boolean isOverClock, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnSkillChangedEgo(bool isOverClock, int32_t timing) {}

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnRoundEnd(int32_t timing) {}

// C#: System.Void OnRoundEnd_After()
void BattleActionModel::OnRoundEnd_After() {}

// C#: System.Void OnAddCoinByAbility(CoinModel newCoin, BATTLE_EVENT_TIMING timing)
void BattleActionModel::OnAddCoinByAbility(il2cpp::Il2CppObject* newCoin, int32_t timing) {}

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
float BattleActionModel::GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull) { return returnValue; }

// C#: System.Int32 GetGiveBsGaugeUpAdder(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
int32_t BattleActionModel::GetGiveBsGaugeUpAdder(int32_t returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull) { return returnValue; }

// C#: System.Boolean HasCoinOperatorType(OPERATOR_TYPE type)
bool BattleActionModel::HasCoinOperatorType(bool returnValue, int32_t type) { return returnValue; }

// C#: System.Boolean HasSuperCoin()
bool BattleActionModel::HasSuperCoin(bool returnValue) { return returnValue; }

// C#: System.Void StackNextTurnAggroAdder()
void BattleActionModel::StackNextTurnAggroAdder() {}

// C#: System.Void OnUseStageBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
void BattleActionModel::OnUseStageBuffBySkill(int32_t keyword, int32_t stack) {}

// C#: System.Int32 GetUsedStageBuffStack(BUFF_UNIQUE_KEYWORD keyword)
int32_t BattleActionModel::GetUsedStageBuffStack(int32_t returnValue, int32_t keyword) { return returnValue; }

// C#: System.Void OnUseBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
void BattleActionModel::OnUseBuffBySkill(int32_t keyword, int32_t stack, int32_t turn) {}

// C#: System.Boolean UsedBuffStack(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
bool BattleActionModel::UsedBuffStack(bool returnValue, int32_t keyword, int32_t stack) { return returnValue; }

// C#: System.Boolean UsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword, System.Int32 turn)
bool BattleActionModel::UsedBuffTurn(bool returnValue, int32_t keyword, int32_t turn) { return returnValue; }

// C#: System.Int32 GetUsedBuffStack(BUFF_UNIQUE_KEYWORD keyword)
int32_t BattleActionModel::GetUsedBuffStack(int32_t returnValue, int32_t keyword) { return returnValue; }

// C#: System.Int32 GetUsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
int32_t BattleActionModel::GetUsedBuffTurn(int32_t returnValue, int32_t keyword) { return returnValue; }

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, CoinModel coinOrNull, System.Single& prob)
bool BattleActionModel::OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, float* prob) { return returnValue; }

// C#: System.Boolean OverwriteCriticalResult(CoinModel coin, System.Boolean tempCritical, System.Nullable<System.Boolean>& overwriteCriticalResult)
bool BattleActionModel::OverwriteCriticalResult(bool returnValue, il2cpp::Il2CppObject* coin, bool tempCritical, il2cpp::Il2CppObject** overwriteCriticalResult) { return returnValue; }

// C#: System.Boolean IgnoreCheckCritical(CoinModel coin)
bool BattleActionModel::IgnoreCheckCritical(bool returnValue, il2cpp::Il2CppObject* coin) { return returnValue; }

// C#: System.Boolean CanDealTarget(BattleUnitModel target, CoinModel coin)
bool BattleActionModel::CanDealTarget(bool returnValue, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin) { return returnValue; }

// C#: System.Boolean BlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool BattleActionModel::BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Boolean ExpectedBlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool BattleActionModel::ExpectedBlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) { return returnValue; }

// C#: System.Void RightBeforeGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void BattleActionModel::RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) {}

// C#: System.Void RightAfterGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, CoinModel coinOrNull)
void BattleActionModel::RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical, il2cpp::Il2CppObject* coinOrNull) {}

// C#: System.Boolean IsReusable()
bool BattleActionModel::IsReusable(bool returnValue) { return returnValue; }

// C#: System.Boolean IsSupportSkill()
bool BattleActionModel::IsSupportSkill(bool returnValue) { return returnValue; }

// C#: System.Boolean IsChangeable()
bool BattleActionModel::IsChangeable(bool returnValue) { return returnValue; }

// C#: System.Void OnOrderCutInAction(BattleActionModel newAction)
void BattleActionModel::OnOrderCutInAction(il2cpp::Il2CppObject* newAction) {}

// C#: System.Void AddTemporarySkillAbilityToSkill(SkillAbility tempSkillAbility, System.String scriptName, System.Single jsonValue, System.Int32 idx, System.Int32 turnLimit, BuffReferenceData info)
void BattleActionModel::AddTemporarySkillAbilityToSkill(il2cpp::Il2CppObject* tempSkillAbility, il2cpp::Il2CppObject* scriptName, float jsonValue, int32_t idx, int32_t turnLimit, il2cpp::Il2CppObject* info) {}

// C#: System.Void RemoveAllSpecificSkillAbility(System.Type targetSkillAbility)
void BattleActionModel::RemoveAllSpecificSkillAbility(il2cpp::Il2CppObject* targetSkillAbility) {}

// C#: System.Void AddCoinIgnoredTiming(BATTLE_EVENT_TIMING timing)
void BattleActionModel::AddCoinIgnoredTiming(int32_t timing) {}

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool BattleActionModel::IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool BattleActionModel::IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) { return returnValue; }

// C#: System.Boolean OverwriteParryingResult(System.Int32 tempActorResult, BattleActionModel oppoAction, System.Int32 tempOppoResult, System.Nullable<System.Int32>& overwriteResult)
bool BattleActionModel::OverwriteParryingResult(bool returnValue, int32_t tempActorResult, il2cpp::Il2CppObject* oppoAction, int32_t tempOppoResult, il2cpp::Il2CppObject** overwriteResult) { return returnValue; }

// C#: System.Boolean TryGetForcedCoinResult(System.Nullable<System.Boolean> isParrying, COIN_RESULT& result, BattleActionModel oppoActionOrNull)
bool BattleActionModel::TryGetForcedCoinResult(bool returnValue, il2cpp::Il2CppObject* isParrying, int32_t* result, il2cpp::Il2CppObject* oppoActionOrNull) { return returnValue; }

// C#: COIN_RESULT GetForcedCoinResult(System.Nullable<System.Boolean> isParrying)
int32_t BattleActionModel::GetForcedCoinResult(int32_t returnValue, il2cpp::Il2CppObject* isParrying) { return returnValue; }

// C#: BattleActionSystemAbility AddAbilityThisRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
il2cpp::Il2CppObject* BattleActionModel::AddAbilityThisRound(il2cpp::Il2CppObject* returnValue, int32_t keyword, int32_t stack, int32_t turn) { return returnValue; }

// C#: BattleActionSystemAbility AddAbilityNextRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
il2cpp::Il2CppObject* BattleActionModel::AddAbilityNextRound(il2cpp::Il2CppObject* returnValue, int32_t keyword, int32_t stack, int32_t turn) { return returnValue; }

// C#: System.Boolean HasSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
bool BattleActionModel::HasSystemAbility(bool returnValue, int32_t keyword) { return returnValue; }

// C#: BattleActionSystemAbility GetSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
il2cpp::Il2CppObject* BattleActionModel::GetSystemAbility(il2cpp::Il2CppObject* returnValue, int32_t keyword) { return returnValue; }

// C#: System.Void DestroySystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
void BattleActionModel::DestroySystemAbility(int32_t keyword) {}

// C#: System.Void MarkAsExtracted()
void BattleActionModel::MarkAsExtracted() {}

// C#: System.Void OnAddBattleAction(SinActionModel targetSinActionNullable)
void BattleActionModel::OnAddBattleAction(il2cpp::Il2CppObject* targetSinActionNullable) {}

// C#: System.Void OnRemoveBattleAction()
void BattleActionModel::OnRemoveBattleAction() {}

// C#: System.Void OnSetExpectedTarget(BattleActionModel targetAction)
void BattleActionModel::OnSetExpectedTarget(il2cpp::Il2CppObject* targetAction) {}

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel mainAction, BattleActionModel oppoActionNullable)
bool BattleActionModel::IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionNullable) { return returnValue; }

// C#: System.Boolean IsEgoSkill()
bool BattleActionModel::IsEgoSkill(bool returnValue) { return returnValue; }

// C#: System.Boolean HasEgoKeyword(EGO_KEYWORD keyword)
bool BattleActionModel::HasEgoKeyword(bool returnValue, int32_t keyword) { return returnValue; }


#pragma endregion

// =============================================================================
// Hooks: call the original first, then hand the result to the C++ handler (if this
// BattleActionModel instance has one) so it can inspect / modify it.
// =============================================================================

#pragma region

// C#: UnitSinModel get_Sin()
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Sin(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_get_Sin(__this);
    MYO_LOG("BattleActionModel", "get_Sin returns {}", returnValue);
    return returnValue;
}

// C#: BattleUnitModel get_Model()
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Model(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_get_Model(__this);
    MYO_LOG("BattleActionModel", "get_Model returns {}", returnValue);
    return returnValue;
}

// C#: SkillModel get_Skill()
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Skill(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_get_Skill(__this);
    MYO_LOG("BattleActionModel", "get_Skill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean get_IsDone()
bool hooked_BattleActionModel_get_IsDone(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_get_IsDone(__this);
    MYO_LOG("BattleActionModel", "get_IsDone returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean get_isDoneWithAction()
bool hooked_BattleActionModel_get_isDoneWithAction(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_get_isDoneWithAction(__this);
    MYO_LOG("BattleActionModel", "get_isDoneWithAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_skillPowerResultValue()
int32_t hooked_BattleActionModel_get_skillPowerResultValue(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_skillPowerResultValue(__this);
    MYO_LOG("BattleActionModel", "get_skillPowerResultValue returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_ReusedTimes()
int32_t hooked_BattleActionModel_get_ReusedTimes(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_ReusedTimes(__this);
    MYO_LOG("BattleActionModel", "get_ReusedTimes returns {}", returnValue);
    return returnValue;
}

// C#: SinActionModel get_SinAction()
il2cpp::Il2CppObject* hooked_BattleActionModel_get_SinAction(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_get_SinAction(__this);
    MYO_LOG("BattleActionModel", "get_SinAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_ActionInstanceID()
int32_t hooked_BattleActionModel_get_ActionInstanceID(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_ActionInstanceID(__this);
    MYO_LOG("BattleActionModel", "get_ActionInstanceID returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_CommanderInstanceID()
int32_t hooked_BattleActionModel_get_CommanderInstanceID(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_CommanderInstanceID(__this);
    MYO_LOG("BattleActionModel", "get_CommanderInstanceID returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_OrderedActionInstanceId()
int32_t hooked_BattleActionModel_get_OrderedActionInstanceId(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_OrderedActionInstanceId(__this);
    MYO_LOG("BattleActionModel", "get_OrderedActionInstanceId returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 get_OrderedActionActorInstanceId()
int32_t hooked_BattleActionModel_get_OrderedActionActorInstanceId(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_OrderedActionActorInstanceId(__this);
    MYO_LOG("BattleActionModel", "get_OrderedActionActorInstanceId returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean get_IsExtracted()
bool hooked_BattleActionModel_get_IsExtracted(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_get_IsExtracted(__this);
    MYO_LOG("BattleActionModel", "get_IsExtracted returns {}", returnValue);
    return returnValue;
}

// C#: BattleUnitModel get_Commander()
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Commander(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_get_Commander(__this);
    MYO_LOG("BattleActionModel", "get_Commander returns {}", returnValue);
    return returnValue;
}

// C#: ABILITY_SOURCE_TYPE get_OrderSourceType()
int32_t hooked_BattleActionModel_get_OrderSourceType(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_get_OrderSourceType(__this);
    MYO_LOG("BattleActionModel", "get_OrderSourceType returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SetTargetDetailType(BattleUnitModel model, System.Boolean isReuseAction)
void hooked_BattleActionModel_SetTargetDetailType(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* model, bool isReuseAction) {
    original_BattleActionModel_SetTargetDetailType(__this, model, isReuseAction);
}

// C#: System.Void InitCoins()
void hooked_BattleActionModel_InitCoins(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_InitCoins(__this);
}

// C#: System.Void InitCoinResults()
void hooked_BattleActionModel_InitCoinResults(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_InitCoinResults(__this);
}

// C#: System.Void InitStaticData()
void hooked_BattleActionModel_InitStaticData(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_InitStaticData(__this);
}

// C#: System.Boolean IsActivatedSupportiveProtectByThisAction()
bool hooked_BattleActionModel_IsActivatedSupportiveProtectByThisAction(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsActivatedSupportiveProtectByThisAction(__this);
    MYO_LOG("BattleActionModel", "IsActivatedSupportiveProtectByThisAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Void CheckActivationOfSupportiveProtect()
void hooked_BattleActionModel_CheckActivationOfSupportiveProtect(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_CheckActivationOfSupportiveProtect(__this);
}

// C#: System.Boolean IsSupportiveDefense_Old()
bool hooked_BattleActionModel_IsSupportiveDefense_Old(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsSupportiveDefense_Old(__this);
    MYO_LOG("BattleActionModel", "IsSupportiveDefense_Old returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsSupportiveDefense()
bool hooked_BattleActionModel_IsSupportiveDefense(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsSupportiveDefense(__this);
    MYO_LOG("BattleActionModel", "IsSupportiveDefense returns {}", returnValue);
    return returnValue;
}

// C#: System.Void RemoveTargetData(System.Boolean returnPrevTarget)
void hooked_BattleActionModel_RemoveTargetData(il2cpp::Il2CppObject* __this, bool returnPrevTarget) {
    original_BattleActionModel_RemoveTargetData(__this, returnPrevTarget);
}

// C#: System.Collections.Generic.List<SinActionModel> GetOriginTargetSinActionsData(System.Boolean isOverlap)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetOriginTargetSinActionsData(il2cpp::Il2CppObject* __this, bool isOverlap) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetOriginTargetSinActionsData(__this, isOverlap);
    MYO_LOG("BattleActionModel", "GetOriginTargetSinActionsData returns {}", returnValue);
    return returnValue;
}

// C#: BattleUnitModel GetOriginMainTarget()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetOriginMainTarget(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetOriginMainTarget(__this);
    MYO_LOG("BattleActionModel", "GetOriginMainTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasOriginTarget()
bool hooked_BattleActionModel_HasOriginTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_HasOriginTarget(__this);
    MYO_LOG("BattleActionModel", "HasOriginTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasMainTarget()
bool hooked_BattleActionModel_HasMainTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_HasMainTarget(__this);
    MYO_LOG("BattleActionModel", "HasMainTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasSubTarget()
bool hooked_BattleActionModel_HasSubTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_HasSubTarget(__this);
    MYO_LOG("BattleActionModel", "HasSubTarget returns {}", returnValue);
    return returnValue;
}

// C#: SinActionModel GetMainTargetSinAction()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetMainTargetSinAction(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetMainTargetSinAction(__this);
    MYO_LOG("BattleActionModel", "GetMainTargetSinAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<SinActionModel> GetSubTargetSinActionList()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSubTargetSinActionList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetSubTargetSinActionList(__this);
    MYO_LOG("BattleActionModel", "GetSubTargetSinActionList returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<SinActionModel> GetTargetSinActionList()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetSinActionList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetTargetSinActionList(__this);
    MYO_LOG("BattleActionModel", "GetTargetSinActionList returns {}", returnValue);
    return returnValue;
}

// C#: BattleUnitModel GetMainTarget()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetMainTarget(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetMainTarget(__this);
    MYO_LOG("BattleActionModel", "GetMainTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetUnitModelList()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetUnitModelList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetTargetUnitModelList(__this);
    MYO_LOG("BattleActionModel", "GetTargetUnitModelList returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<BattleUnitModel> GetAliveTargetUnitModelList()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetAliveTargetUnitModelList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetAliveTargetUnitModelList(__this);
    MYO_LOG("BattleActionModel", "GetAliveTargetUnitModelList returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SetOriginTargetSinActions(System.Collections.Generic.List<SinActionModel> originTargetSinActions)
void hooked_BattleActionModel_SetOriginTargetSinActions(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTargetSinActions) {
    original_BattleActionModel_SetOriginTargetSinActions(__this, originTargetSinActions);
}

// C#: System.Void ReadyOriginTargeting()
void hooked_BattleActionModel_ReadyOriginTargeting(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ReadyOriginTargeting(__this);
}

// C#: System.Void AddTarget(SinActionModel targetSinAction)
void hooked_BattleActionModel_AddTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction) {
    original_BattleActionModel_AddTarget(__this, targetSinAction);
}

// C#: System.Void SetTargetAfterBattleStart(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void hooked_BattleActionModel_SetTargetAfterBattleStart(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {
    original_BattleActionModel_SetTargetAfterBattleStart(__this, canDuel, attackEenemyOnly, overwritedTargetType);
}

// C#: System.Void RedirectTarget(System.Boolean mainTargetAlive)
void hooked_BattleActionModel_RedirectTarget(il2cpp::Il2CppObject* __this, bool mainTargetAlive) {
    original_BattleActionModel_RedirectTarget(__this, mainTargetAlive);
}

// C#: System.Void SetTargetAuto(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void hooked_BattleActionModel_SetTargetAuto(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {
    original_BattleActionModel_SetTargetAuto(__this, canDuel, attackEenemyOnly, overwritedTargetType);
}

// C#: System.Void SetTargetBySortedTargetableSinActionList(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
void hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEnemyOnly, int32_t targetType) {
    original_BattleActionModel_SetTargetBySortedTargetableSinActionList(__this, canDuel, attackEnemyOnly, targetType);
}

// C#: System.Void SetTargetAfterBattleStart_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void hooked_BattleActionModel_SetTargetAfterBattleStart_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {
    original_BattleActionModel_SetTargetAfterBattleStart_CutIn(__this, canDuel, attackEenemyOnly, overwritedTargetType);
}

// C#: System.Void SetTargetAuto_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void hooked_BattleActionModel_SetTargetAuto_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType) {
    original_BattleActionModel_SetTargetAuto_CutIn(__this, canDuel, attackEenemyOnly, overwritedTargetType);
}

// C#: System.Void SetTargetBySortedTargetableSinActionList_CutIn(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
void hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEnemyOnly, int32_t targetType) {
    original_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn(__this, canDuel, attackEnemyOnly, targetType);
}

// C#: System.Void RemoveOneTargetSet(BattleActionModel otherAction)
void hooked_BattleActionModel_RemoveOneTargetSet(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction) {
    original_BattleActionModel_RemoveOneTargetSet(__this, otherAction);
}

// C#: System.Boolean CanDuelWithSameFaction()
bool hooked_BattleActionModel_CanDuelWithSameFaction(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_CanDuelWithSameFaction(__this);
    MYO_LOG("BattleActionModel", "CanDuelWithSameFaction returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SetTarget(System.Collections.Generic.List<SinActionModel> sortedTargetSinActions, System.Boolean canDuel)
void hooked_BattleActionModel_SetTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sortedTargetSinActions, bool canDuel) {
    original_BattleActionModel_SetTarget(__this, sortedTargetSinActions, canDuel);
}

// C#: System.Void RecheckTargetList()
void hooked_BattleActionModel_RecheckTargetList(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_RecheckTargetList(__this);
}

// C#: System.Void AfterRecheckTargetList(System.Boolean valid, System.Boolean mainTargetAlive)
void hooked_BattleActionModel_AfterRecheckTargetList(il2cpp::Il2CppObject* __this, bool valid, bool mainTargetAlive) {
    original_BattleActionModel_AfterRecheckTargetList(__this, valid, mainTargetAlive);
}

// C#: System.Void ChangeAllTargetOnCompleteCommand(System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
void hooked_BattleActionModel_ChangeAllTargetOnCompleteCommand(il2cpp::Il2CppObject* __this, bool attackEnemyOnly, int32_t overwritedTargetType) {
    original_BattleActionModel_ChangeAllTargetOnCompleteCommand(__this, attackEnemyOnly, overwritedTargetType);
}

// C#: System.Void ChangeMainTargetSinAction(SinActionModel changeTargetSinAction, BattleActionModel oppositeAction, System.Boolean forcely)
void hooked_BattleActionModel_ChangeMainTargetSinAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* changeTargetSinAction, il2cpp::Il2CppObject* oppositeAction, bool forcely) {
    original_BattleActionModel_ChangeMainTargetSinAction(__this, changeTargetSinAction, oppositeAction, forcely);
}

// C#: System.Boolean HasBeenChangedCurrentTargetBy(BattleActionModel oppositeAction)
bool hooked_BattleActionModel_HasBeenChangedCurrentTargetBy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppositeAction) {
    bool returnValue = original_BattleActionModel_HasBeenChangedCurrentTargetBy(__this, oppositeAction);
    MYO_LOG("BattleActionModel", "HasBeenChangedCurrentTargetBy returns {}", returnValue);
    return returnValue;
}

// C#: System.Void ChangeAllSubTarget()
void hooked_BattleActionModel_ChangeAllSubTarget(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ChangeAllSubTarget(__this);
}

// C#: System.Void RecheckSubTargetWhenChangeTargetNum(System.Nullable<System.Boolean> overwriteAttackEnemyOnly, SKILL_TARGET_TYPE overwriteTargetType)
void hooked_BattleActionModel_RecheckSubTargetWhenChangeTargetNum(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* overwriteAttackEnemyOnly, int32_t overwriteTargetType) {
    original_BattleActionModel_RecheckSubTargetWhenChangeTargetNum(__this, overwriteAttackEnemyOnly, overwriteTargetType);
}

// C#: System.Void RemoveAllTargetExceptMainTarget()
void hooked_BattleActionModel_RemoveAllTargetExceptMainTarget(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_RemoveAllTargetExceptMainTarget(__this);
}

// C#: System.Void RemoveUntargetableTarget()
void hooked_BattleActionModel_RemoveUntargetableTarget(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_RemoveUntargetableTarget(__this);
}

// C#: System.Int32 GetCurrentOccupiedWeight()
int32_t hooked_BattleActionModel_GetCurrentOccupiedWeight_P0(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetCurrentOccupiedWeight_P0(__this);
    MYO_LOG("BattleActionModel", "GetCurrentOccupiedWeight_P0 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetCurrentOccupiedWeight(SinActionModel targetSinAction)
int32_t hooked_BattleActionModel_GetCurrentOccupiedWeight_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction) {
    int32_t returnValue = original_BattleActionModel_GetCurrentOccupiedWeight_P1(__this, targetSinAction);
    MYO_LOG("BattleActionModel", "GetCurrentOccupiedWeight_P1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Void AddPrimeTargets(System.Boolean canDuel)
void hooked_BattleActionModel_AddPrimeTargets(il2cpp::Il2CppObject* __this, bool canDuel) {
    original_BattleActionModel_AddPrimeTargets(__this, canDuel);
}

// C#: System.Boolean GetPrimeTargetSinActions(System.Collections.Generic.List<TargetSinActionData>& primeTargetSinActions, System.Int32& remainedSlotNum)
bool hooked_BattleActionModel_GetPrimeTargetSinActions(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject** primeTargetSinActions, int32_t* remainedSlotNum) {
    bool returnValue = original_BattleActionModel_GetPrimeTargetSinActions(__this, primeTargetSinActions, remainedSlotNum);
    MYO_LOG("BattleActionModel", "GetPrimeTargetSinActions returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<SinActionModel> GetSatisfiedPrimeTargetSinActions()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSatisfiedPrimeTargetSinActions(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetSatisfiedPrimeTargetSinActions(__this);
    MYO_LOG("BattleActionModel", "GetSatisfiedPrimeTargetSinActions returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<SinActionModel> ExtractSortedPrimeTargetSinActionList(System.Collections.Generic.List<PrimeTargetData> primeTargetDatas)
il2cpp::Il2CppObject* hooked_BattleActionModel_ExtractSortedPrimeTargetSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* primeTargetDatas) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_ExtractSortedPrimeTargetSinActionList(__this, primeTargetDatas);
    MYO_LOG("BattleActionModel", "ExtractSortedPrimeTargetSinActionList returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<SinActionModel> GetCollapsedTargetableSinActionList(System.Collections.Generic.List<SinActionModel> addedTargetSinActions, System.Nullable<System.Boolean> attackEnemyOnly, SKILL_TARGET_TYPE targetType, System.Boolean canAttackAllyAssist)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetCollapsedTargetableSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedTargetSinActions, il2cpp::Il2CppObject* attackEnemyOnly, int32_t targetType, bool canAttackAllyAssist) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetCollapsedTargetableSinActionList(__this, addedTargetSinActions, attackEnemyOnly, targetType, canAttackAllyAssist);
    MYO_LOG("BattleActionModel", "GetCollapsedTargetableSinActionList returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SortSinActionList(System.Collections.Generic.List<SinActionModel> list, SKILL_TARGET_TYPE targetType)
void hooked_BattleActionModel_SortSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* list, int32_t targetType) {
    original_BattleActionModel_SortSinActionList(__this, list, targetType);
}

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetableUnitList(System.Boolean canAttackAllyAssist)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetableUnitList(il2cpp::Il2CppObject* __this, bool canAttackAllyAssist) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetTargetableUnitList(__this, canAttackAllyAssist);
    MYO_LOG("BattleActionModel", "GetTargetableUnitList returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SortTargetSlots(System.Collections.Generic.List<SinActionModel> targetSinActions, SKILL_TARGET_TYPE targetType)
void hooked_BattleActionModel_SortTargetSlots(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActions, int32_t targetType) {
    original_BattleActionModel_SortTargetSlots(__this, targetSinActions, targetType);
}

// C#: System.Single GetExpectedEgoErodeRate(BattleEgoModel egoModel)
float hooked_BattleActionModel_GetExpectedEgoErodeRate(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* egoModel) {
    float returnValue = original_BattleActionModel_GetExpectedEgoErodeRate(__this, egoModel);
    MYO_LOG("BattleActionModel", "GetExpectedEgoErodeRate returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsConsumeBuffSkill(BUFF_UNIQUE_KEYWORD buff)
bool hooked_BattleActionModel_IsConsumeBuffSkill(il2cpp::Il2CppObject* __this, int32_t buff) {
    bool returnValue = original_BattleActionModel_IsConsumeBuffSkill(__this, buff);
    MYO_LOG("BattleActionModel", "IsConsumeBuffSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsConsumeBullet()
bool hooked_BattleActionModel_IsConsumeBullet(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsConsumeBullet(__this);
    MYO_LOG("BattleActionModel", "IsConsumeBullet returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsUseBuff(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool hooked_BattleActionModel_IsUseBuff(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType) {
    bool returnValue = original_BattleActionModel_IsUseBuff(__this, buff, targetType);
    MYO_LOG("BattleActionModel", "IsUseBuff returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsUseBuffStack(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool hooked_BattleActionModel_IsUseBuffStack(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType) {
    bool returnValue = original_BattleActionModel_IsUseBuffStack(__this, buff, targetType);
    MYO_LOG("BattleActionModel", "IsUseBuffStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsUseBuffTurn(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool hooked_BattleActionModel_IsUseBuffTurn(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType) {
    bool returnValue = original_BattleActionModel_IsUseBuffTurn(__this, buff, targetType);
    MYO_LOG("BattleActionModel", "IsUseBuffTurn returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsAddBloodDinner()
bool hooked_BattleActionModel_IsAddBloodDinner(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsAddBloodDinner(__this);
    MYO_LOG("BattleActionModel", "IsAddBloodDinner returns {}", returnValue);
    return returnValue;
}

// C#: PairWithTargetUnitSinSet GetExpectedAllCalculationOnlyAbnormalityBattle()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle(__this);
    MYO_LOG("BattleActionModel", "GetExpectedAllCalculationOnlyAbnormalityBattle returns {}", returnValue);
    return returnValue;
}

// C#: System.Void MakeReusable()
void hooked_BattleActionModel_MakeReusable(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_MakeReusable(__this);
}

// C#: System.Void ResetAllTargetData()
void hooked_BattleActionModel_ResetAllTargetData(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ResetAllTargetData(__this);
}

// C#: System.Void ResetCoinState()
void hooked_BattleActionModel_ResetCoinState(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ResetCoinState(__this);
}

// C#: System.Void ResetDataWIthOutTargetData()
void hooked_BattleActionModel_ResetDataWIthOutTargetData(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ResetDataWIthOutTargetData(__this);
}

// C#: System.Void AddAttackedTarget(BattleUnitModel target)
void hooked_BattleActionModel_AddAttackedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target) {
    original_BattleActionModel_AddAttackedTarget(__this, target);
}

// C#: System.Collections.Generic.List<BattleUnitModel> GetAttackedTargetList()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetAttackedTargetList(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetAttackedTargetList(__this);
    MYO_LOG("BattleActionModel", "GetAttackedTargetList returns {}", returnValue);
    return returnValue;
}

// C#: System.Void CheckCoinDestroy(BattleActionModel winnerAction)
void hooked_BattleActionModel_CheckCoinDestroy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* winnerAction) {
    original_BattleActionModel_CheckCoinDestroy(__this, winnerAction);
}

// C#: CoinModel GetHighestCoin()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetHighestCoin(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetHighestCoin(__this);
    MYO_LOG("BattleActionModel", "GetHighestCoin returns {}", returnValue);
    return returnValue;
}

// C#: CoinModel GetDestroyTargetCoin()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDestroyTargetCoin(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetDestroyTargetCoin(__this);
    MYO_LOG("BattleActionModel", "GetDestroyTargetCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetSkillID()
int32_t hooked_BattleActionModel_GetSkillID(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetSkillID(__this);
    MYO_LOG("BattleActionModel", "GetSkillID returns {}", returnValue);
    return returnValue;
}

// C#: SKILL_TARGET_TYPE GetSkillTargetType()
int32_t hooked_BattleActionModel_GetSkillTargetType(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetSkillTargetType(__this);
    MYO_LOG("BattleActionModel", "GetSkillTargetType returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetAttackWeight()
int32_t hooked_BattleActionModel_GetAttackWeight(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetAttackWeight(__this);
    MYO_LOG("BattleActionModel", "GetAttackWeight returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetOriginAttackWeight()
int32_t hooked_BattleActionModel_GetOriginAttackWeight(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetOriginAttackWeight(__this);
    MYO_LOG("BattleActionModel", "GetOriginAttackWeight returns {}", returnValue);
    return returnValue;
}

// C#: DEFENSE_TYPE GetDefenseType()
int32_t hooked_BattleActionModel_GetDefenseType(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetDefenseType(__this);
    MYO_LOG("BattleActionModel", "GetDefenseType returns {}", returnValue);
    return returnValue;
}

// C#: ATK_BEHAVIOUR GetSkillAtkType()
int32_t hooked_BattleActionModel_GetSkillAtkType(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetSkillAtkType(__this);
    MYO_LOG("BattleActionModel", "GetSkillAtkType returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean TryGetOverwriteAtkBehaviour(CoinModel coin, ATK_BEHAVIOUR& atkBehaviour)
bool hooked_BattleActionModel_TryGetOverwriteAtkBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t* atkBehaviour) {
    bool returnValue = original_BattleActionModel_TryGetOverwriteAtkBehaviour(__this, coin, atkBehaviour);
    MYO_LOG("BattleActionModel", "TryGetOverwriteAtkBehaviour returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsSkillAtkType(ATK_BEHAVIOUR type)
bool hooked_BattleActionModel_IsSkillAtkType(il2cpp::Il2CppObject* __this, int32_t type) {
    bool returnValue = original_BattleActionModel_IsSkillAtkType(__this, type);
    MYO_LOG("BattleActionModel", "IsSkillAtkType returns {}", returnValue);
    return returnValue;
}

// C#: ATTRIBUTE_TYPE GetSkillAttributeType()
int32_t hooked_BattleActionModel_GetSkillAttributeType(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetSkillAttributeType(__this);
    MYO_LOG("BattleActionModel", "GetSkillAttributeType returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsSkillAttributeType(ATTRIBUTE_TYPE type)
bool hooked_BattleActionModel_IsSkillAttributeType(il2cpp::Il2CppObject* __this, int32_t type) {
    bool returnValue = original_BattleActionModel_IsSkillAttributeType(__this, type);
    MYO_LOG("BattleActionModel", "IsSkillAttributeType returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsAttack()
bool hooked_BattleActionModel_IsAttack(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsAttack(__this);
    MYO_LOG("BattleActionModel", "IsAttack returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsDefense()
bool hooked_BattleActionModel_IsDefense(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsDefense(__this);
    MYO_LOG("BattleActionModel", "IsDefense returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsDefenseNotCounter()
bool hooked_BattleActionModel_IsDefenseNotCounter(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsDefenseNotCounter(__this);
    MYO_LOG("BattleActionModel", "IsDefenseNotCounter returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsGuard()
bool hooked_BattleActionModel_IsGuard(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsGuard(__this);
    MYO_LOG("BattleActionModel", "IsGuard returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsCounter()
bool hooked_BattleActionModel_IsCounter(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsCounter(__this);
    MYO_LOG("BattleActionModel", "IsCounter returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsCanDuelDefense()
bool hooked_BattleActionModel_IsCanDuelDefense(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsCanDuelDefense(__this);
    MYO_LOG("BattleActionModel", "IsCanDuelDefense returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsEvade()
bool hooked_BattleActionModel_IsEvade(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsEvade(__this);
    MYO_LOG("BattleActionModel", "IsEvade returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IgnoreDefenseSkill(BattleUnitModel target)
bool hooked_BattleActionModel_IgnoreDefenseSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target) {
    bool returnValue = original_BattleActionModel_IgnoreDefenseSkill(__this, target);
    MYO_LOG("BattleActionModel", "IgnoreDefenseSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IgnoreSupportiveDefense(BattleUnitModel originTarget, BattleUnitModel supportiveDefender)
bool hooked_BattleActionModel_IgnoreSupportiveDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* supportiveDefender) {
    bool returnValue = original_BattleActionModel_IgnoreSupportiveDefense(__this, originTarget, supportiveDefender);
    MYO_LOG("BattleActionModel", "IgnoreSupportiveDefense returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsActionable()
bool hooked_BattleActionModel_IsActionable(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsActionable(__this);
    MYO_LOG("BattleActionModel", "IsActionable returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnAttackCanceledByAbility(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnAttackCanceledByAbility(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnAttackCanceledByAbility(__this, timing);
}

// C#: System.Boolean CanBeChangedTarget(BattleActionModel oppoAction)
bool hooked_BattleActionModel_CanBeChangedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction) {
    bool returnValue = original_BattleActionModel_CanBeChangedTarget(__this, oppoAction);
    MYO_LOG("BattleActionModel", "CanBeChangedTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleActionModel otherAction)
bool hooked_BattleActionModel_CanChangeMainTargetRegardlessSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction) {
    bool returnValue = original_BattleActionModel_CanChangeMainTargetRegardlessSpeed(__this, otherAction);
    MYO_LOG("BattleActionModel", "CanChangeMainTargetRegardlessSpeed returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanBeChangedTargetIgnoreSpeed(BattleActionModel otherAction)
bool hooked_BattleActionModel_CanBeChangedTargetIgnoreSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction) {
    bool returnValue = original_BattleActionModel_CanBeChangedTargetIgnoreSpeed(__this, otherAction);
    MYO_LOG("BattleActionModel", "CanBeChangedTargetIgnoreSpeed returns {}", returnValue);
    return returnValue;
}

// C#: System.Void ChangeEgoSkill(System.Boolean isOverClock)
void hooked_BattleActionModel_ChangeEgoSkill(il2cpp::Il2CppObject* __this, bool isOverClock) {
    original_BattleActionModel_ChangeEgoSkill(__this, isOverClock);
}

// C#: System.Boolean TryChangeSkill(System.Int32 skillID)
bool hooked_BattleActionModel_TryChangeSkill(il2cpp::Il2CppObject* __this, int32_t skillID) {
    bool returnValue = original_BattleActionModel_TryChangeSkill(__this, skillID);
    MYO_LOG("BattleActionModel", "TryChangeSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean ChangeSkill(SkillModel skill, System.Boolean saveOriginSkill)
bool hooked_BattleActionModel_ChangeSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, bool saveOriginSkill) {
    bool returnValue = original_BattleActionModel_ChangeSkill(__this, skill, saveOriginSkill);
    MYO_LOG("BattleActionModel", "ChangeSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Void ReturnPreviousSkill()
void hooked_BattleActionModel_ReturnPreviousSkill(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ReturnPreviousSkill(__this);
}

// C#: System.Int32 GetResonanceIndexOrStack()
int32_t hooked_BattleActionModel_GetResonanceIndexOrStack(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetResonanceIndexOrStack(__this);
    MYO_LOG("BattleActionModel", "GetResonanceIndexOrStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedResonanceIndexOrStack()
int32_t hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P0(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetExpectedResonanceIndexOrStack_P0(__this);
    MYO_LOG("BattleActionModel", "GetExpectedResonanceIndexOrStack_P0 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedResonanceIndexOrStack(System.Collections.Generic.List<System.Int32> indexes)
int32_t hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* indexes) {
    int32_t returnValue = original_BattleActionModel_GetExpectedResonanceIndexOrStack_P1(__this, indexes);
    MYO_LOG("BattleActionModel", "GetExpectedResonanceIndexOrStack_P1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetAttributeResonanceIndex()
int32_t hooked_BattleActionModel_GetAttributeResonanceIndex(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetAttributeResonanceIndex(__this);
    MYO_LOG("BattleActionModel", "GetAttributeResonanceIndex returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetPerfectResonanceStack()
int32_t hooked_BattleActionModel_GetPerfectResonanceStack(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetPerfectResonanceStack(__this);
    MYO_LOG("BattleActionModel", "GetPerfectResonanceStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Void CheckResonancePassive()
void hooked_BattleActionModel_CheckResonancePassive(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_CheckResonancePassive(__this);
}

// C#: System.Void OnAttributeResonance()
void hooked_BattleActionModel_OnAttributeResonance(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_OnAttributeResonance(__this);
}

// C#: System.Boolean HasCommander(System.Int32& commander)
bool hooked_BattleActionModel_HasCommander(il2cpp::Il2CppObject* __this, int32_t* commander) {
    bool returnValue = original_BattleActionModel_HasCommander(__this, commander);
    MYO_LOG("BattleActionModel", "HasCommander returns {}", returnValue);
    return returnValue;
}

// C#: System.Void SetDefenseLevel_After_UseSkill()
void hooked_BattleActionModel_SetDefenseLevel_After_UseSkill(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_SetDefenseLevel_After_UseSkill(__this);
}

// C#: System.Void ModifySpeedByParrying(System.Int32 speed)
void hooked_BattleActionModel_ModifySpeedByParrying(il2cpp::Il2CppObject* __this, int32_t speed) {
    original_BattleActionModel_ModifySpeedByParrying(__this, speed);
}

// C#: System.Void ResetSpeedByParrying()
void hooked_BattleActionModel_ResetSpeedByParrying(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_ResetSpeedByParrying(__this);
}

// C#: System.Int32 RollSkillPower(CoinModel coin, OneCoinLog oneCoinLog, System.Int32 idx, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, System.Nullable<System.Boolean> isWinDuel, System.Boolean calculateSystemAdder)
int32_t hooked_BattleActionModel_RollSkillPower(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oneCoinLog, int32_t idx, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* isWinDuel, bool calculateSystemAdder) {
    int32_t returnValue = original_BattleActionModel_RollSkillPower(__this, coin, oneCoinLog, idx, rollType, attackerActionOrNull, isWinDuel, calculateSystemAdder);
    MYO_LOG("BattleActionModel", "RollSkillPower returns {}", returnValue);
    return returnValue;
}

// C#: ParryingData RollSkillPowerParrying(BattleActionModel oppoAction, BattleLog_Parrying parryingLog, ParryingStatus parryingStatus)
il2cpp::Il2CppObject* hooked_BattleActionModel_RollSkillPowerParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* parryingLog, il2cpp::Il2CppObject* parryingStatus) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_RollSkillPowerParrying(__this, oppoAction, parryingLog, parryingStatus);
    MYO_LOG("BattleActionModel", "RollSkillPowerParrying returns {}", returnValue);
    return returnValue;
}

// C#: SkillPowerData CreateSkillPowerData(System.Boolean isValid, BATTLE_EVENT_TIMING timing, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, CoinModel coinOrNull)
il2cpp::Il2CppObject* hooked_BattleActionModel_CreateSkillPowerData(il2cpp::Il2CppObject* __this, bool isValid, int32_t timing, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* coinOrNull) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_CreateSkillPowerData(__this, isValid, timing, rollType, attackerActionOrNull, coinOrNull);
    MYO_LOG("BattleActionModel", "CreateSkillPowerData returns {}", returnValue);
    return returnValue;
}

// C#: ParryingData CreateParryingData(System.Boolean isValid)
il2cpp::Il2CppObject* hooked_BattleActionModel_CreateParryingData(il2cpp::Il2CppObject* __this, bool isValid) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_CreateParryingData(__this, isValid);
    MYO_LOG("BattleActionModel", "CreateParryingData returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanRollAllCoinForUI(System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs)
bool hooked_BattleActionModel_CanRollAllCoinForUI(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject** lackOfBuffs) {
    bool returnValue = original_BattleActionModel_CanRollAllCoinForUI(__this, lackOfBuffs);
    MYO_LOG("BattleActionModel", "CanRollAllCoinForUI returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsRetreatSkill()
bool hooked_BattleActionModel_IsRetreatSkill(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsRetreatSkill(__this);
    MYO_LOG("BattleActionModel", "IsRetreatSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsCommandRetreatSkill()
bool hooked_BattleActionModel_IsCommandRetreatSkill(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsCommandRetreatSkill(__this);
    MYO_LOG("BattleActionModel", "IsCommandRetreatSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanRollCoin(CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs, System.Boolean& forceToEndSkill)
bool hooked_BattleActionModel_CanRollCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** lackOfBuffs, bool* forceToEndSkill) {
    bool returnValue = original_BattleActionModel_CanRollCoin(__this, coin, lackOfBuffs, forceToEndSkill);
    MYO_LOG("BattleActionModel", "CanRollCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Void Behave(BattleRunLog runLog, BattleLog actionLog, BattleActionModel attackerActionOrNull, System.Boolean isLoserAttackExpected, BattleActionModel loserActionOrNull)
void hooked_BattleActionModel_Behave(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull, bool isLoserAttackExpected, il2cpp::Il2CppObject* loserActionOrNull) {
    original_BattleActionModel_Behave(__this, runLog, actionLog, attackerActionOrNull, isLoserAttackExpected, loserActionOrNull);
}

// C#: System.Boolean BeforeCompleteCommand(BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
bool hooked_BattleActionModel_BeforeCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing, int32_t* newSkillID) {
    bool returnValue = original_BattleActionModel_BeforeCompleteCommand(__this, timing, newSkillID);
    MYO_LOG("BattleActionModel", "BeforeCompleteCommand returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnChangeSkillBeforeCompleteCommand(__this, timing);
}

// C#: System.Void ActivateGuard(BattleRunLog runLog, BattleLog_Guard actionLog, BattleActionModel attackerActionOrNull)
void hooked_BattleActionModel_ActivateGuard(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull) {
    original_BattleActionModel_ActivateGuard(__this, runLog, actionLog, attackerActionOrNull);
}

// C#: System.Void CheckOneOnOneDuelState()
void hooked_BattleActionModel_CheckOneOnOneDuelState(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_CheckOneOnOneDuelState(__this);
}

// C#: System.Boolean IsOneOnOneDuel(BattleActionModel opponentAction)
bool hooked_BattleActionModel_IsOneOnOneDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction) {
    bool returnValue = original_BattleActionModel_IsOneOnOneDuel(__this, opponentAction);
    MYO_LOG("BattleActionModel", "IsOneOnOneDuel returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnCompleteCommand(__this, timing);
}

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnBattleStart(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnBattleStart(__this, timing);
}

// C#: System.Boolean CanAttackTargets()
bool hooked_BattleActionModel_CanAttackTargets(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_CanAttackTargets(__this);
    MYO_LOG("BattleActionModel", "CanAttackTargets returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CheckTargetableTarget()
bool hooked_BattleActionModel_CheckTargetableTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_CheckTargetableTarget(__this);
    MYO_LOG("BattleActionModel", "CheckTargetableTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnEndBehave_Refresh(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnEndBehave_Refresh(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnEndBehave_Refresh(__this, timing);
}

// C#: System.Void AffectToReturnUnit(System.Collections.Generic.List<OnReleaseStandByOrOnReturnData> list)
void hooked_BattleActionModel_AffectToReturnUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* list) {
    original_BattleActionModel_AffectToReturnUnit(__this, list);
}

// C#: System.Void CallTargetDefenseActionsByAttack(BattleRunLog runLog, DEFENSE_TYPE type, System.Boolean isDuelExpected, System.Boolean canDuel, BATTLE_EVENT_TIMING timing, OneCoinLog_Attack oneCoinLog, BattleUnitModel specificTarget, System.Boolean mainTargetExclusive)
void hooked_BattleActionModel_CallTargetDefenseActionsByAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, int32_t type, bool isDuelExpected, bool canDuel, int32_t timing, il2cpp::Il2CppObject* oneCoinLog, il2cpp::Il2CppObject* specificTarget, bool mainTargetExclusive) {
    original_BattleActionModel_CallTargetDefenseActionsByAttack(__this, runLog, type, isDuelExpected, canDuel, timing, oneCoinLog, specificTarget, mainTargetExclusive);
}

// C#: System.Void OnRoundStart_After()
void hooked_BattleActionModel_OnRoundStart_After(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_OnRoundStart_After(__this);
}

// C#: System.Void OnBeforeTurn(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnBeforeTurn(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnBeforeTurn(__this, timing);
}

// C#: System.Void OnCancelAction()
void hooked_BattleActionModel_OnCancelAction(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_OnCancelAction(__this);
}

// C#: System.Void OnBeforeDefense(BattleActionModel attackerActionOrNull)
void hooked_BattleActionModel_OnBeforeDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerActionOrNull) {
    original_BattleActionModel_OnBeforeDefense(__this, attackerActionOrNull);
}

// C#: System.Void OnStartTurn_BeforeLog(BATTLE_EVENT_TIMING timing, System.Boolean isDuelExpected)
void hooked_BattleActionModel_OnStartTurn_BeforeLog(il2cpp::Il2CppObject* __this, int32_t timing, bool isDuelExpected) {
    original_BattleActionModel_OnStartTurn_BeforeLog(__this, timing, isDuelExpected);
}

// C#: System.Void OnStartTurn_AfterLog(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnStartTurn_AfterLog(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnStartTurn_AfterLog(__this, timing);
}

// C#: System.Void OnTryEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnTryEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing) {
    original_BattleActionModel_OnTryEvade(__this, attackerAction, timing);
}

// C#: System.Void OnStartDuel(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnStartDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    original_BattleActionModel_OnStartDuel(__this, opponentAction, timing);
}

// C#: System.Void OnBeforeParryingOnce(BattleActionModel oppoAction)
void hooked_BattleActionModel_OnBeforeParryingOnce(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction) {
    original_BattleActionModel_OnBeforeParryingOnce(__this, oppoAction);
}

// C#: System.Void OnBeforeParryingOnce_AfterLog(BattleActionModel oppoAction)
void hooked_BattleActionModel_OnBeforeParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction) {
    original_BattleActionModel_OnBeforeParryingOnce_AfterLog(__this, oppoAction);
}

// C#: System.Void OnDuelAfter_BeforeLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 parryingCount, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void hooked_BattleActionModel_OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {
    original_BattleActionModel_OnDuelAfter_BeforeLog(__this, result, oppoAction, parryingCount, selfRemainedCoin, oppoRemainedCoin, timing, lastLogOrNull);
}

// C#: System.Void OnDuelAfter_AfterLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnDuelAfter_AfterLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing) {
    original_BattleActionModel_OnDuelAfter_AfterLog(__this, result, oppoAction, selfRemainedCoin, oppoRemainedCoin, timing);
}

// C#: System.Void OnAfterParryingOnce_BeforeLog(BattleActionModel opponentAction, PARRYING_RESULT reuslt, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t reuslt, int32_t parryingCnt, int32_t timing) {
    original_BattleActionModel_OnAfterParryingOnce_BeforeLog(__this, opponentAction, reuslt, parryingCnt, timing);
}

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void hooked_BattleActionModel_OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {
    original_BattleActionModel_OnAfterParryingOnce_AfterLog(__this, opponentAction, timing, lastLogOrNull);
}

// C#: System.Void OnWinParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnWinParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    original_BattleActionModel_OnWinParrying(__this, opponentAction, timing);
}

// C#: System.Void OnLoseParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnLoseParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    original_BattleActionModel_OnLoseParrying(__this, opponentAction, timing);
}

// C#: System.Void OnWinDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
void hooked_BattleActionModel_OnWinDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull) {
    original_BattleActionModel_OnWinDuel(__this, opponentAction, parryingCount, remainedOwenrCoin, remainedOpponentCoin, timing, lastLogOrNull);
}

// C#: System.Void CheckExtractAbility(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_CheckExtractAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing) {
    original_BattleActionModel_CheckExtractAbility(__this, opponentAction, timing);
}

// C#: System.Void FirstBsGaugeUpWithDuelableGuard(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLog)
void hooked_BattleActionModel_FirstBsGaugeUpWithDuelableGuard(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLog) {
    original_BattleActionModel_FirstBsGaugeUpWithDuelableGuard(__this, opponentAction, timing, lastLog);
}

// C#: System.Void OnLoseDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnLoseDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing) {
    original_BattleActionModel_OnLoseDuel(__this, opponentAction, parryingCount, remainedOwenrCoin, remainedOpponentCoin, timing);
}

// C#: System.Void BeforeBehaviour(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_BeforeBehaviour(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_BeforeBehaviour(__this, timing);
}

// C#: System.Void OnStartBehaviour(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnStartBehaviour(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnStartBehaviour(__this, timing);
}

// C#: System.Void OnCriticalIsActivated(CoinModel coin, BATTLE_EVENT_TIMING timing, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
void hooked_BattleActionModel_OnCriticalIsActivated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t timing, il2cpp::Il2CppObject* affectKeywords) {
    original_BattleActionModel_OnCriticalIsActivated(__this, coin, timing, affectKeywords);
}

// C#: System.Void OnAttackConfirmed(CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
void hooked_BattleActionModel_OnAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing, bool isCritical) {
    original_BattleActionModel_OnAttackConfirmed(__this, coin, target, timing, isCritical);
}

// C#: System.Void BeforeGiveAttackDamage(CoinModel coin, BattleUnitModel target, System.Nullable<System.Boolean> isWinDuel, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_BeforeGiveAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* isWinDuel, bool isCritical, int32_t timing) {
    original_BattleActionModel_BeforeGiveAttackDamage(__this, coin, target, isWinDuel, isCritical, timing);
}

// C#: System.Void OnSucceedAttack(CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnSucceedAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    original_BattleActionModel_OnSucceedAttack(__this, coin, target, finalDmg, realDmg, realHpDmg, isCritical, isWinDuel, timing);
}

// C#: System.Boolean CanGiveConcentratedAttack()
bool hooked_BattleActionModel_CanGiveConcentratedAttack(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_CanGiveConcentratedAttack(__this);
    MYO_LOG("BattleActionModel", "CanGiveConcentratedAttack returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnSucceedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnSucceedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing) {
    original_BattleActionModel_OnSucceedEvade(__this, attackerAction, timing);
}

// C#: System.Void OnFailedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnFailedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing) {
    original_BattleActionModel_OnFailedEvade(__this, attackerAction, timing);
}

// C#: System.Void OnStartCoin(CoinModel coin, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t timing) {
    original_BattleActionModel_OnStartCoin(__this, coin, timing);
}

// C#: System.Void OnEndCoin_BeforeLog(CoinModel coin, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnEndCoin_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    original_BattleActionModel_OnEndCoin_BeforeLog(__this, coin, isCritical, isWinDuel, timing);
}

// C#: System.Void OnEndCoin_AfterLog(CoinModel coin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnEndCoin_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isCritical, int32_t timing) {
    original_BattleActionModel_OnEndCoin_AfterLog(__this, coin, isCritical, timing);
}

// C#: System.Void OnEndAttack(System.Int32 accumulatedDmg, System.Int32 accumulatedHpDmg, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing, BattleLog_Duel duelLogOrNull)
void hooked_BattleActionModel_OnEndAttack(il2cpp::Il2CppObject* __this, int32_t accumulatedDmg, int32_t accumulatedHpDmg, il2cpp::Il2CppObject* isWinDuel, int32_t timing, il2cpp::Il2CppObject* duelLogOrNull) {
    original_BattleActionModel_OnEndAttack(__this, accumulatedDmg, accumulatedHpDmg, isWinDuel, timing, duelLogOrNull);
}

// C#: System.Void OnEndBehaviour(BattleRunLog runLog, BATTLE_EVENT_TIMING timing, System.Boolean isLoserAttackExpected)
void hooked_BattleActionModel_OnEndBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, int32_t timing, bool isLoserAttackExpected) {
    original_BattleActionModel_OnEndBehaviour(__this, runLog, timing, isLoserAttackExpected);
}

// C#: System.Void OnGiveBsGaugeUp(CoinModel coinOrNull, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion)
void hooked_BattleActionModel_OnGiveBsGaugeUp(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion) {
    original_BattleActionModel_OnGiveBsGaugeUp(__this, coinOrNull, target, value, timing, onExplosion);
}

// C#: System.Void OnEndTurn(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnEndTurn(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnEndTurn(__this, timing);
}

// C#: System.Void OnDiscarded(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnDiscarded(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnDiscarded(__this, timing);
}

// C#: System.Void OnKillTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnKillTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {
    original_BattleActionModel_OnKillTarget(__this, target, coinOrNull, dmgSrcType, timing);
}

// C#: System.Void OnBreakTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnBreakTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {
    original_BattleActionModel_OnBreakTarget(__this, target, coinOrNull, dmgSrcType, timing);
}

// C#: System.Void OnDestroyTargetPart(BattleUnitModel_Abnormality_Part target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnDestroyTargetPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing) {
    original_BattleActionModel_OnDestroyTargetPart(__this, target, coinOrNull, dmgSrcType, timing);
}

// C#: System.Void Done()
void hooked_BattleActionModel_Done(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_Done(__this);
}

// C#: System.Void DoneWithAction(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_DoneWithAction(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_DoneWithAction(__this, timing);
}

// C#: System.Void AddSinStock()
void hooked_BattleActionModel_AddSinStock(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_AddSinStock(__this);
}

// C#: System.Int32 GetExpectedMinCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
int32_t hooked_BattleActionModel_GetExpectedMinCoinValue_P2_1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetExpectedMinCoinValue_P2_1(__this, oppoSinActionOrNull, adder);
    MYO_LOG("BattleActionModel", "GetExpectedMinCoinValue_P2_1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedMaxCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
int32_t hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetExpectedMaxCoinValue_P2_1(__this, oppoSinActionOrNull, adder);
    MYO_LOG("BattleActionModel", "GetExpectedMaxCoinValue_P2_1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedMinCoinValue(UnitSinModel oppoSin, System.Int32& adder)
int32_t hooked_BattleActionModel_GetExpectedMinCoinValue_P2_2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSin, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetExpectedMinCoinValue_P2_2(__this, oppoSin, adder);
    MYO_LOG("BattleActionModel", "GetExpectedMinCoinValue_P2_2 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedMaxCoinValue(UnitSinModel oppoSin, System.Int32& adder)
int32_t hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSin, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetExpectedMaxCoinValue_P2_2(__this, oppoSin, adder);
    MYO_LOG("BattleActionModel", "GetExpectedMaxCoinValue_P2_2 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
int32_t hooked_BattleActionModel_GetExpectedCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetExpectedCalculation(__this, oppoSinActionOrNull, oppoActionOrNull, isMin, adder);
    MYO_LOG("BattleActionModel", "GetExpectedCalculation returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamage()
int32_t hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage(__this);
    MYO_LOG("BattleActionModel", "GetExpectedRateOfIncreaseAndDecreaseDamage returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(SinActionModel targetSinActionOrNull, BattleActionModel targetActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(__this, targetSinActionOrNull, targetActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedRateOfIncreaseAndDecreaseDamageByTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedDamage(CalculationType type, System.Collections.Generic.List<System.Int32> indexes, SinActionModel targetSinActionOrNull, BattleActionModel oppoActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedDamage(__this, type, indexes, targetSinActionOrNull, oppoActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedDamage returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedDamageByTarget(CalculationType type, SinActionModel targetSinAction, BattleActionModel targetActionOrNull, System.Collections.Generic.List<System.Int32> indexes)
int32_t hooked_BattleActionModel_GetExpectedDamageByTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* targetActionOrNull, il2cpp::Il2CppObject* indexes) {
    int32_t returnValue = original_BattleActionModel_GetExpectedDamageByTarget(__this, type, targetSinAction, targetActionOrNull, indexes);
    MYO_LOG("BattleActionModel", "GetExpectedDamageByTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsDuelExpcted(BattleActionModel oppoAction)
bool hooked_BattleActionModel_IsDuelExpcted(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction) {
    bool returnValue = original_BattleActionModel_IsDuelExpcted(__this, oppoAction);
    MYO_LOG("BattleActionModel", "IsDuelExpcted returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetParryingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
int32_t hooked_BattleActionModel_GetParryingCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetParryingCalculation(__this, oppoSinActionOrNull, oppoActionOrNull, isMin, adder);
    MYO_LOG("BattleActionModel", "GetParryingCalculation returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetDamageCalculation(SinActionModel targetSinActionOrNull, BattleActionModel targetActionModelOrNull, System.Boolean isMin, System.Int32& adder)
int32_t hooked_BattleActionModel_GetDamageCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionModelOrNull, bool isMin, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetDamageCalculation(__this, targetSinActionOrNull, targetActionModelOrNull, isMin, adder);
    MYO_LOG("BattleActionModel", "GetDamageCalculation returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetSnowBallingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Boolean isOpponentEvade, System.Int32& adder)
int32_t hooked_BattleActionModel_GetSnowBallingCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, bool isOpponentEvade, int32_t* adder) {
    int32_t returnValue = original_BattleActionModel_GetSnowBallingCalculation(__this, oppoSinActionOrNull, oppoActionOrNull, isMin, isOpponentEvade, adder);
    MYO_LOG("BattleActionModel", "GetSnowBallingCalculation returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetDefaultAllCoinCalculation(System.Boolean isMin, System.Boolean isParrying, System.Boolean isOpponentEvade)
int32_t hooked_BattleActionModel_GetDefaultAllCoinCalculation(il2cpp::Il2CppObject* __this, bool isMin, bool isParrying, bool isOpponentEvade) {
    int32_t returnValue = original_BattleActionModel_GetDefaultAllCoinCalculation(__this, isMin, isParrying, isOpponentEvade);
    MYO_LOG("BattleActionModel", "GetDefaultAllCoinCalculation returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetParryingAdder(BattleActionModel oppoActionOrNull)
int32_t hooked_BattleActionModel_GetParryingAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetParryingAdder(__this, oppoActionOrNull);
    MYO_LOG("BattleActionModel", "GetParryingAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetMinExpectedDamage(SinActionModel targetSinAction, System.Collections.Generic.List<System.Int32> selectedIndexes)
int32_t hooked_BattleActionModel_GetMinExpectedDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* selectedIndexes) {
    int32_t returnValue = original_BattleActionModel_GetMinExpectedDamage(__this, targetSinAction, selectedIndexes);
    MYO_LOG("BattleActionModel", "GetMinExpectedDamage returns {}", returnValue);
    return returnValue;
}

// C#: System.Single GetCriticalChance(CoinModel coin, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single>& affectKeywords)
float hooked_BattleActionModel_GetCriticalChance(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** affectKeywords) {
    float returnValue = original_BattleActionModel_GetCriticalChance(__this, coin, affectKeywords);
    MYO_LOG("BattleActionModel", "GetCriticalChance returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanTeamKill()
bool hooked_BattleActionModel_CanTeamKill(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_CanTeamKill(__this);
    MYO_LOG("BattleActionModel", "CanTeamKill returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetSkillLevel(System.Int32 resonanceIndex, System.Int32& allCorrectionValue, System.Int32& effectCorrectionValue)
int32_t hooked_BattleActionModel_GetSkillLevel(il2cpp::Il2CppObject* __this, int32_t resonanceIndex, int32_t* allCorrectionValue, int32_t* effectCorrectionValue) {
    int32_t returnValue = original_BattleActionModel_GetSkillLevel(__this, resonanceIndex, allCorrectionValue, effectCorrectionValue);
    MYO_LOG("BattleActionModel", "GetSkillLevel returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetSkillPower(COIN_ROLL_TYPE rollType, BATTLE_EVENT_TIMING timing, System.Collections.Generic.List<CoinModel> coinList, BattleActionModel attackerActionOrNull)
int32_t hooked_BattleActionModel_GetSkillPower(il2cpp::Il2CppObject* __this, int32_t rollType, int32_t timing, il2cpp::Il2CppObject* coinList, il2cpp::Il2CppObject* attackerActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetSkillPower(__this, rollType, timing, coinList, attackerActionOrNull);
    MYO_LOG("BattleActionModel", "GetSkillPower returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull, BattleActionModel attackerActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedSkillPower_P3_1(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedSkillPower_P3_1(__this, rollType, expectedTargetSinActionOrNull, attackerActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedSkillPower_P3_1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, System.Collections.Generic.List<System.Int32> indexes, SinActionModel expectedTargetSinActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedSkillPower_P3_2(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedSkillPower_P3_2(__this, rollType, indexes, expectedTargetSinActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedSkillPower_P3_2 returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetCoinScale(CoinModel coin, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
int32_t hooked_BattleActionModel_GetCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetCoinScale(__this, coin, includeAdder, oppoActionOrNull, attackerActionOrNull);
    MYO_LOG("BattleActionModel", "GetCoinScale returns {}", returnValue);
    return returnValue;
}

// C#: System.Nullable<System.Int32> OverrideCoinScale(CoinModel coin, System.Int32 originScaleAdder)
il2cpp::Il2CppObject* hooked_BattleActionModel_OverrideCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t originScaleAdder) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_OverrideCoinScale(__this, coin, originScaleAdder);
    MYO_LOG("BattleActionModel", "OverrideCoinScale returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedCoinScale(CoinModel coin, COIN_ROLL_TYPE rollType, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t rollType, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedCoinScale(__this, coin, rollType, includeAdder, oppoActionOrNull, targetSinActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedCoinScale returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
int32_t hooked_BattleActionModel_GetAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target) {
    int32_t returnValue = original_BattleActionModel_GetAttackHpDmgAdder(__this, coin, isWinDuel, target);
    MYO_LOG("BattleActionModel", "GetAttackHpDmgAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
int32_t hooked_BattleActionModel_GetExpectedAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target) {
    int32_t returnValue = original_BattleActionModel_GetExpectedAttackHpDmgAdder(__this, coin, isWinDuel, target);
    MYO_LOG("BattleActionModel", "GetExpectedAttackHpDmgAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetCoinScaleAdder(CoinModel coin, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
int32_t hooked_BattleActionModel_GetCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetCoinScaleAdder(__this, coin, oppoActionOrNull, attackerActionOrNull);
    MYO_LOG("BattleActionModel", "GetCoinScaleAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedCoinScaleAdder(CoinModel coin, COIN_ROLL_TYPE rollType, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t rollType, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedCoinScaleAdder(__this, coin, rollType, oppoActionOrNull, targetSinActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedCoinScaleAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetSkillPowerResultAdder(BATTLE_EVENT_TIMING timing, BattleActionModel attackerActionOrNull, System.Boolean calculateSystemAdder, CoinModel coinOrNull)
int32_t hooked_BattleActionModel_GetSkillPowerResultAdder(il2cpp::Il2CppObject* __this, int32_t timing, il2cpp::Il2CppObject* attackerActionOrNull, bool calculateSystemAdder, il2cpp::Il2CppObject* coinOrNull) {
    int32_t returnValue = original_BattleActionModel_GetSkillPowerResultAdder(__this, timing, attackerActionOrNull, calculateSystemAdder, coinOrNull);
    MYO_LOG("BattleActionModel", "GetSkillPowerResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerAdder(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedSkillPowerAdder(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedSkillPowerAdder(__this, rollType, expectedTargetSinActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedSkillPowerAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedSkillPowerResultAdder(System.Collections.Generic.List<System.Int32> indexes, SinActionModel opppoSinActionOrNull, BattleActionModel oppoActionOrNull)
int32_t hooked_BattleActionModel_GetExpectedSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* opppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedSkillPowerResultAdder(__this, indexes, opppoSinActionOrNull, oppoActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedSkillPowerResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Single GetAttackDmgMultiplier(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical, System.Boolean isOneSideAttack, OneCoinLog_Attack forEditorItCanBeNull)
float hooked_BattleActionModel_GetAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical, bool isOneSideAttack, il2cpp::Il2CppObject* forEditorItCanBeNull) {
    float returnValue = original_BattleActionModel_GetAttackDmgMultiplier(__this, coin, target, isWinDuel, isCritical, isOneSideAttack, forEditorItCanBeNull);
    MYO_LOG("BattleActionModel", "GetAttackDmgMultiplier returns {}", returnValue);
    return 10.0f;
}

// C#: System.Single GetExpectedAttackDmgMultiplier(CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
float hooked_BattleActionModel_GetExpectedAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    float returnValue = original_BattleActionModel_GetExpectedAttackDmgMultiplier(__this, coin, targetOrNull, targetSinActionOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedAttackDmgMultiplier returns {}", returnValue);
    return 99999.9f;
}

// C#: System.Int32 GetAttackDmgAdder(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel)
int32_t hooked_BattleActionModel_GetAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel) {
    int32_t returnValue = original_BattleActionModel_GetAttackDmgAdder(__this, coin, target, isWinDuel);
    MYO_LOG("BattleActionModel", "GetAttackDmgAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedAttackDmgAdder(CoinModel coin, BattleUnitModel targetOrNull)
int32_t hooked_BattleActionModel_GetExpectedAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull) {
    int32_t returnValue = original_BattleActionModel_GetExpectedAttackDmgAdder(__this, coin, targetOrNull);
    MYO_LOG("BattleActionModel", "GetExpectedAttackDmgAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetOppoSkillPowerResultAdderOnTakeAtkDmg()
int32_t hooked_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg(__this);
    MYO_LOG("BattleActionModel", "GetOppoSkillPowerResultAdderOnTakeAtkDmg returns {}", returnValue);
    return returnValue;
}

// C#: static System.Boolean BothCanDuelAndAttackSkill(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* hooked_BattleActionModel_BothCanDuelAndAttackSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_BothCanDuelAndAttackSkill(__this, a, b);
    MYO_LOG("BattleActionModel", "BothCanDuelAndAttackSkill returns {}", returnValue);
    return returnValue;
}

// C#: static System.Boolean BothCanDuelAndAtLeastOneAttackSkill(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* hooked_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill(__this, a, b);
    MYO_LOG("BattleActionModel", "BothCanDuelAndAtLeastOneAttackSkill returns {}", returnValue);
    return returnValue;
}

// C#: static System.Boolean CanDuelBoth(BattleActionModel a, BattleActionModel b)
il2cpp::Il2CppObject* hooked_BattleActionModel_CanDuelBoth(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_CanDuelBoth(__this, a, b);
    MYO_LOG("BattleActionModel", "CanDuelBoth returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanDuel(BattleActionModel opponentAction)
bool hooked_BattleActionModel_CanDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction) {
    bool returnValue = original_BattleActionModel_CanDuel(__this, opponentAction);
    MYO_LOG("BattleActionModel", "CanDuel returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanDuelWithoutCheckNull(BattleActionModel opponentAction)
bool hooked_BattleActionModel_CanDuelWithoutCheckNull(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction) {
    bool returnValue = original_BattleActionModel_CanDuelWithoutCheckNull(__this, opponentAction);
    MYO_LOG("BattleActionModel", "CanDuelWithoutCheckNull returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsPanicBlock()
bool hooked_BattleActionModel_IsPanicBlock(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsPanicBlock(__this);
    MYO_LOG("BattleActionModel", "IsPanicBlock returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action, BattleUnitModel target)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDescArgs_P2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetDescArgs_P2(__this, action, target);
    MYO_LOG("BattleActionModel", "GetDescArgs_P2 returns {}", returnValue);
    return returnValue;
}

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDescArgs_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetDescArgs_P1(__this, action);
    MYO_LOG("BattleActionModel", "GetDescArgs_P1 returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsAllCoinHead()
bool hooked_BattleActionModel_IsAllCoinHead(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsAllCoinHead(__this);
    MYO_LOG("BattleActionModel", "IsAllCoinHead returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsAllCoinHit()
bool hooked_BattleActionModel_IsAllCoinHit(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsAllCoinHit(__this);
    MYO_LOG("BattleActionModel", "IsAllCoinHit returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetHeadCoinNum()
int32_t hooked_BattleActionModel_GetHeadCoinNum(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetHeadCoinNum(__this);
    MYO_LOG("BattleActionModel", "GetHeadCoinNum returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetTailCoinNum()
int32_t hooked_BattleActionModel_GetTailCoinNum(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetTailCoinNum(__this);
    MYO_LOG("BattleActionModel", "GetTailCoinNum returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetUsableInDuelCoinNum()
int32_t hooked_BattleActionModel_GetUsableInDuelCoinNum(il2cpp::Il2CppObject* __this) {
    int32_t returnValue = original_BattleActionModel_GetUsableInDuelCoinNum(__this);
    MYO_LOG("BattleActionModel", "GetUsableInDuelCoinNum returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsFirstCoin(CoinModel coin)
bool hooked_BattleActionModel_IsFirstCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin) {
    bool returnValue = original_BattleActionModel_IsFirstCoin(__this, coin);
    MYO_LOG("BattleActionModel", "IsFirstCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsLastCoin(CoinModel coin)
bool hooked_BattleActionModel_IsLastCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin) {
    bool returnValue = original_BattleActionModel_IsLastCoin(__this, coin);
    MYO_LOG("BattleActionModel", "IsLastCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CheckPersonalitySkillSpecificType(SKILL_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
bool hooked_BattleActionModel_CheckPersonalitySkillSpecificType(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t targetType) {
    bool returnValue = original_BattleActionModel_CheckPersonalitySkillSpecificType(__this, keyword, targetType);
    MYO_LOG("BattleActionModel", "CheckPersonalitySkillSpecificType returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_BattleActionModel_CheckSkillGivingBuffCategory(il2cpp::Il2CppObject* __this, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_BattleActionModel_CheckSkillGivingBuffCategory(__this, category, targetType, stackGiver, turnGiver);
    MYO_LOG("BattleActionModel", "CheckSkillGivingBuffCategory returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CheckSkillGivingBuff(BUFF_UNIQUE_KEYWORD buffKeyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
bool hooked_BattleActionModel_CheckSkillGivingBuff(il2cpp::Il2CppObject* __this, int32_t buffKeyword, int32_t targetType, bool* stackGiver, bool* turnGiver) {
    bool returnValue = original_BattleActionModel_CheckSkillGivingBuff(__this, buffKeyword, targetType, stackGiver, turnGiver);
    MYO_LOG("BattleActionModel", "CheckSkillGivingBuff returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsGainBullet()
bool hooked_BattleActionModel_IsGainBullet(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsGainBullet(__this);
    MYO_LOG("BattleActionModel", "IsGainBullet returns {}", returnValue);
    return returnValue;
}

// C#: CoinModel GetCoin(System.Int32 i)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetCoin(il2cpp::Il2CppObject* __this, int32_t i) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetCoin(__this, i);
    MYO_LOG("BattleActionModel", "GetCoin returns {}", returnValue);
    return returnValue;
}

// C#: CoinModel GetFirstCoin()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetFirstCoin(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetFirstCoin(__this);
    MYO_LOG("BattleActionModel", "GetFirstCoin returns {}", returnValue);
    return returnValue;
}

// C#: CoinModel GetLastCoin()
il2cpp::Il2CppObject* hooked_BattleActionModel_GetLastCoin(il2cpp::Il2CppObject* __this) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetLastCoin(__this);
    MYO_LOG("BattleActionModel", "GetLastCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetMpUsage(System.Boolean isErodeSkill)
int32_t hooked_BattleActionModel_GetMpUsage(il2cpp::Il2CppObject* __this, bool isErodeSkill) {
    int32_t returnValue = original_BattleActionModel_GetMpUsage(__this, isErodeSkill);
    MYO_LOG("BattleActionModel", "GetMpUsage returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsMultiTarget()
bool hooked_BattleActionModel_IsMultiTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsMultiTarget(__this);
    MYO_LOG("BattleActionModel", "IsMultiTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsReusedAction()
bool hooked_BattleActionModel_IsReusedAction(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsReusedAction(__this);
    MYO_LOG("BattleActionModel", "IsReusedAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Void BeforeAttack(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_BeforeAttack(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_BeforeAttack(__this, timing);
}

// C#: System.Int32 GetFinalSkillPowerResult(BATTLE_EVENT_TIMING timing)
int32_t hooked_BattleActionModel_GetFinalSkillPowerResult(il2cpp::Il2CppObject* __this, int32_t timing) {
    int32_t returnValue = original_BattleActionModel_GetFinalSkillPowerResult(__this, timing);
    MYO_LOG("BattleActionModel", "GetFinalSkillPowerResult returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
int32_t hooked_BattleActionModel_GetParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) {
    int32_t returnValue = original_BattleActionModel_GetParryingResultAdder(__this, actorResult, oppoAction, oppoResult, parryingCount);
    MYO_LOG("BattleActionModel", "GetParryingResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
int32_t hooked_BattleActionModel_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
    int32_t returnValue = original_BattleActionModel_GetExpectedParryingResultAdder(__this, actorResult, oppoActionOrNull, oppoResult);
    MYO_LOG("BattleActionModel", "GetExpectedParryingResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t hooked_BattleActionModel_GetOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    int32_t returnValue = original_BattleActionModel_GetOpponentParryingResultAdder(__this, actorResult, oppoAction, oppoResult);
    MYO_LOG("BattleActionModel", "GetOpponentParryingResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
int32_t hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    int32_t returnValue = original_BattleActionModel_GetExpectedOpponentParryingResultAdder(__this, actorResult, oppoAction, oppoResult);
    MYO_LOG("BattleActionModel", "GetExpectedOpponentParryingResultAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OverWriteSkill(System.Int32 defaultValue, System.Int32 coinNum, System.Int32 coinScale, OPERATOR_TYPE operatorType)
void hooked_BattleActionModel_OverWriteSkill(il2cpp::Il2CppObject* __this, int32_t defaultValue, int32_t coinNum, int32_t coinScale, int32_t operatorType) {
    original_BattleActionModel_OverWriteSkill(__this, defaultValue, coinNum, coinScale, operatorType);
}

// C#: System.Boolean IsRandomTarget()
bool hooked_BattleActionModel_IsRandomTarget(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsRandomTarget(__this);
    MYO_LOG("BattleActionModel", "IsRandomTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsTargetableSlot(SinActionModel attackerSinAction)
bool hooked_BattleActionModel_IsTargetableSlot(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerSinAction) {
    bool returnValue = original_BattleActionModel_IsTargetableSlot(__this, attackerSinAction);
    MYO_LOG("BattleActionModel", "IsTargetableSlot returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsSkillAbsorbingThisDamage()
bool hooked_BattleActionModel_IsSkillAbsorbingThisDamage(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsSkillAbsorbingThisDamage(__this);
    MYO_LOG("BattleActionModel", "IsSkillAbsorbingThisDamage returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsDefenseSkillForOther(BattleUnitModel originTarget, BattleActionModel opponentActionOrNull)
bool hooked_BattleActionModel_IsDefenseSkillForOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* opponentActionOrNull) {
    bool returnValue = original_BattleActionModel_IsDefenseSkillForOther(__this, originTarget, opponentActionOrNull);
    MYO_LOG("BattleActionModel", "IsDefenseSkillForOther returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean AttackByMpDmgRatherThanHpDmg(CoinModel coin, System.Int32 resultDmg, BattleUnitModel target)
bool hooked_BattleActionModel_AttackByMpDmgRatherThanHpDmg(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t resultDmg, il2cpp::Il2CppObject* target) {
    bool returnValue = original_BattleActionModel_AttackByMpDmgRatherThanHpDmg(__this, coin, resultDmg, target);
    MYO_LOG("BattleActionModel", "AttackByMpDmgRatherThanHpDmg returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool hooked_BattleActionModel_BlockLoseBuffByReactWithAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) {
    bool returnValue = original_BattleActionModel_BlockLoseBuffByReactWithAction(__this, target, keyword, coinOrNull, isCritical);
    MYO_LOG("BattleActionModel", "BlockLoseBuffByReactWithAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 ChangeAttackDamage(CoinModel coin, BattleUnitModel target, System.Int32 resultDmg, System.Boolean& isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
int32_t hooked_BattleActionModel_ChangeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t resultDmg, bool* isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing) {
    int32_t returnValue = original_BattleActionModel_ChangeAttackDamage(__this, coin, target, resultDmg, isCritical, isWinDuel, timing);
    MYO_LOG("BattleActionModel", "ChangeAttackDamage returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnSkillChangedEgo(System.Boolean isOverClock, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnSkillChangedEgo(il2cpp::Il2CppObject* __this, bool isOverClock, int32_t timing) {
    original_BattleActionModel_OnSkillChangedEgo(__this, isOverClock, timing);
}

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_OnRoundEnd(__this, timing);
}

// C#: System.Void OnRoundEnd_After()
void hooked_BattleActionModel_OnRoundEnd_After(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_OnRoundEnd_After(__this);
}

// C#: System.Void OnAddCoinByAbility(CoinModel newCoin, BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_OnAddCoinByAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* newCoin, int32_t timing) {
    original_BattleActionModel_OnAddCoinByAbility(__this, newCoin, timing);
}

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
float hooked_BattleActionModel_GetGiveBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull) {
    float returnValue = original_BattleActionModel_GetGiveBsGaugeUpMultiplier(__this, onGiveExplosion, target, coinOrNull);
    MYO_LOG("BattleActionModel", "GetGiveBsGaugeUpMultiplier returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetGiveBsGaugeUpAdder(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
int32_t hooked_BattleActionModel_GetGiveBsGaugeUpAdder(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull) {
    int32_t returnValue = original_BattleActionModel_GetGiveBsGaugeUpAdder(__this, onGiveExplosion, target, coinOrNull);
    MYO_LOG("BattleActionModel", "GetGiveBsGaugeUpAdder returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasCoinOperatorType(OPERATOR_TYPE type)
bool hooked_BattleActionModel_HasCoinOperatorType(il2cpp::Il2CppObject* __this, int32_t type) {
    bool returnValue = original_BattleActionModel_HasCoinOperatorType(__this, type);
    MYO_LOG("BattleActionModel", "HasCoinOperatorType returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasSuperCoin()
bool hooked_BattleActionModel_HasSuperCoin(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_HasSuperCoin(__this);
    MYO_LOG("BattleActionModel", "HasSuperCoin returns {}", returnValue);
    return returnValue;
}

// C#: System.Void StackNextTurnAggroAdder()
void hooked_BattleActionModel_StackNextTurnAggroAdder(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_StackNextTurnAggroAdder(__this);
}

// C#: System.Void OnUseStageBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
void hooked_BattleActionModel_OnUseStageBuffBySkill(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack) {
    original_BattleActionModel_OnUseStageBuffBySkill(__this, keyword, stack);
}

// C#: System.Int32 GetUsedStageBuffStack(BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_BattleActionModel_GetUsedStageBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword) {
    int32_t returnValue = original_BattleActionModel_GetUsedStageBuffStack(__this, keyword);
    MYO_LOG("BattleActionModel", "GetUsedStageBuffStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnUseBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
void hooked_BattleActionModel_OnUseBuffBySkill(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn) {
    original_BattleActionModel_OnUseBuffBySkill(__this, keyword, stack, turn);
}

// C#: System.Boolean UsedBuffStack(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
bool hooked_BattleActionModel_UsedBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack) {
    bool returnValue = original_BattleActionModel_UsedBuffStack(__this, keyword, stack);
    MYO_LOG("BattleActionModel", "UsedBuffStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean UsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword, System.Int32 turn)
bool hooked_BattleActionModel_UsedBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t turn) {
    bool returnValue = original_BattleActionModel_UsedBuffTurn(__this, keyword, turn);
    MYO_LOG("BattleActionModel", "UsedBuffTurn returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetUsedBuffStack(BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_BattleActionModel_GetUsedBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword) {
    int32_t returnValue = original_BattleActionModel_GetUsedBuffStack(__this, keyword);
    MYO_LOG("BattleActionModel", "GetUsedBuffStack returns {}", returnValue);
    return returnValue;
}

// C#: System.Int32 GetUsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
int32_t hooked_BattleActionModel_GetUsedBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword) {
    int32_t returnValue = original_BattleActionModel_GetUsedBuffTurn(__this, keyword);
    MYO_LOG("BattleActionModel", "GetUsedBuffTurn returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, CoinModel coinOrNull, System.Single& prob)
bool hooked_BattleActionModel_OverwriteCoinProb(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, float* prob) {
    bool returnValue = original_BattleActionModel_OverwriteCoinProb(__this, unit, skill, coinOrNull, prob);
    MYO_LOG("BattleActionModel", "OverwriteCoinProb returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean OverwriteCriticalResult(CoinModel coin, System.Boolean tempCritical, System.Nullable<System.Boolean>& overwriteCriticalResult)
bool hooked_BattleActionModel_OverwriteCriticalResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool tempCritical, il2cpp::Il2CppObject** overwriteCriticalResult) {
    bool returnValue = original_BattleActionModel_OverwriteCriticalResult(__this, coin, tempCritical, overwriteCriticalResult);
    MYO_LOG("BattleActionModel", "OverwriteCriticalResult returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IgnoreCheckCritical(CoinModel coin)
bool hooked_BattleActionModel_IgnoreCheckCritical(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin) {
    bool returnValue = original_BattleActionModel_IgnoreCheckCritical(__this, coin);
    MYO_LOG("BattleActionModel", "IgnoreCheckCritical returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean CanDealTarget(BattleUnitModel target, CoinModel coin)
bool hooked_BattleActionModel_CanDealTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin) {
    bool returnValue = original_BattleActionModel_CanDealTarget(__this, target, coin);
    MYO_LOG("BattleActionModel", "CanDealTarget returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean BlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool hooked_BattleActionModel_BlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) {
    bool returnValue = original_BattleActionModel_BlockGivingBuff(__this, buffTarget, keyword, activeRound, coinOrNull, isCritical);
    MYO_LOG("BattleActionModel", "BlockGivingBuff returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean ExpectedBlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
bool hooked_BattleActionModel_ExpectedBlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical) {
    bool returnValue = original_BattleActionModel_ExpectedBlockGivingBuff(__this, buffTarget, keyword, coinOrNull, isCritical);
    MYO_LOG("BattleActionModel", "ExpectedBlockGivingBuff returns {}", returnValue);
    return returnValue;
}

// C#: System.Void RightBeforeGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
void hooked_BattleActionModel_RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical) {
    original_BattleActionModel_RightBeforeGiveBuffBySkill(__this, target, bufKeyword, originalStack, originalTurn, activeRound, timing, isCritical);
}

// C#: System.Void RightAfterGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, CoinModel coinOrNull)
void hooked_BattleActionModel_RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical, il2cpp::Il2CppObject* coinOrNull) {
    original_BattleActionModel_RightAfterGiveBuffBySkill(__this, target, bufKeyword, originalStack, originalTurn, resultStack, resultTurn, activeRound, timing, isCritical, coinOrNull);
}

// C#: System.Boolean IsReusable()
bool hooked_BattleActionModel_IsReusable(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsReusable(__this);
    MYO_LOG("BattleActionModel", "IsReusable returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsSupportSkill()
bool hooked_BattleActionModel_IsSupportSkill(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsSupportSkill(__this);
    MYO_LOG("BattleActionModel", "IsSupportSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsChangeable()
bool hooked_BattleActionModel_IsChangeable(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsChangeable(__this);
    MYO_LOG("BattleActionModel", "IsChangeable returns {}", returnValue);
    return returnValue;
}

// C#: System.Void OnOrderCutInAction(BattleActionModel newAction)
void hooked_BattleActionModel_OnOrderCutInAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* newAction) {
    original_BattleActionModel_OnOrderCutInAction(__this, newAction);
}

// C#: System.Void AddTemporarySkillAbilityToSkill(SkillAbility tempSkillAbility, System.String scriptName, System.Single jsonValue, System.Int32 idx, System.Int32 turnLimit, BuffReferenceData info)
void hooked_BattleActionModel_AddTemporarySkillAbilityToSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* tempSkillAbility, il2cpp::Il2CppObject* scriptName, float jsonValue, int32_t idx, int32_t turnLimit, il2cpp::Il2CppObject* info) {
    original_BattleActionModel_AddTemporarySkillAbilityToSkill(__this, tempSkillAbility, scriptName, jsonValue, idx, turnLimit, info);
}

// C#: System.Void RemoveAllSpecificSkillAbility(System.Type targetSkillAbility)
void hooked_BattleActionModel_RemoveAllSpecificSkillAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSkillAbility) {
    original_BattleActionModel_RemoveAllSpecificSkillAbility(__this, targetSkillAbility);
}

// C#: System.Void AddCoinIgnoredTiming(BATTLE_EVENT_TIMING timing)
void hooked_BattleActionModel_AddCoinIgnoredTiming(il2cpp::Il2CppObject* __this, int32_t timing) {
    original_BattleActionModel_AddCoinIgnoredTiming(__this, timing);
}

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_BattleActionModel_IsBlockingTargetBurstBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    bool returnValue = original_BattleActionModel_IsBlockingTargetBurstBuffEffectReact(__this, target, stack, turn, selfCoin, isCritical, timing);
    MYO_LOG("BattleActionModel", "IsBlockingTargetBurstBuffEffectReact returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
bool hooked_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing) {
    bool returnValue = original_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact(__this, target, stack, turn, selfCoin, isCritical, timing);
    MYO_LOG("BattleActionModel", "IsBlockingTargetSinkingBuffEffectReact returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean OverwriteParryingResult(System.Int32 tempActorResult, BattleActionModel oppoAction, System.Int32 tempOppoResult, System.Nullable<System.Int32>& overwriteResult)
bool hooked_BattleActionModel_OverwriteParryingResult(il2cpp::Il2CppObject* __this, int32_t tempActorResult, il2cpp::Il2CppObject* oppoAction, int32_t tempOppoResult, il2cpp::Il2CppObject** overwriteResult) {
    bool returnValue = original_BattleActionModel_OverwriteParryingResult(__this, tempActorResult, oppoAction, tempOppoResult, overwriteResult);
    MYO_LOG("BattleActionModel", "OverwriteParryingResult returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean TryGetForcedCoinResult(System.Nullable<System.Boolean> isParrying, COIN_RESULT& result, BattleActionModel oppoActionOrNull)
bool hooked_BattleActionModel_TryGetForcedCoinResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* isParrying, int32_t* result, il2cpp::Il2CppObject* oppoActionOrNull) {
    bool returnValue = original_BattleActionModel_TryGetForcedCoinResult(__this, isParrying, result, oppoActionOrNull);
    MYO_LOG("BattleActionModel", "TryGetForcedCoinResult returns {}", returnValue);
    return returnValue;
}

// C#: COIN_RESULT GetForcedCoinResult(System.Nullable<System.Boolean> isParrying)
int32_t hooked_BattleActionModel_GetForcedCoinResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* isParrying) {
    int32_t returnValue = original_BattleActionModel_GetForcedCoinResult(__this, isParrying);
    MYO_LOG("BattleActionModel", "GetForcedCoinResult returns {}", returnValue);
    return returnValue;
}

// C#: BattleActionSystemAbility AddAbilityThisRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
il2cpp::Il2CppObject* hooked_BattleActionModel_AddAbilityThisRound(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_AddAbilityThisRound(__this, keyword, stack, turn);
    MYO_LOG("BattleActionModel", "AddAbilityThisRound returns {}", returnValue);
    return returnValue;
}

// C#: BattleActionSystemAbility AddAbilityNextRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
il2cpp::Il2CppObject* hooked_BattleActionModel_AddAbilityNextRound(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_AddAbilityNextRound(__this, keyword, stack, turn);
    MYO_LOG("BattleActionModel", "AddAbilityNextRound returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
bool hooked_BattleActionModel_HasSystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword) {
    bool returnValue = original_BattleActionModel_HasSystemAbility(__this, keyword);
    MYO_LOG("BattleActionModel", "HasSystemAbility returns {}", returnValue);
    return returnValue;
}

// C#: BattleActionSystemAbility GetSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword) {
    il2cpp::Il2CppObject* returnValue = original_BattleActionModel_GetSystemAbility(__this, keyword);
    MYO_LOG("BattleActionModel", "GetSystemAbility returns {}", returnValue);
    return returnValue;
}

// C#: System.Void DestroySystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
void hooked_BattleActionModel_DestroySystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword) {
    original_BattleActionModel_DestroySystemAbility(__this, keyword);
}

// C#: System.Void MarkAsExtracted()
void hooked_BattleActionModel_MarkAsExtracted(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_MarkAsExtracted(__this);
}

// C#: System.Void OnAddBattleAction(SinActionModel targetSinActionNullable)
void hooked_BattleActionModel_OnAddBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionNullable) {
    original_BattleActionModel_OnAddBattleAction(__this, targetSinActionNullable);
}

// C#: System.Void OnRemoveBattleAction()
void hooked_BattleActionModel_OnRemoveBattleAction(il2cpp::Il2CppObject* __this) {
    original_BattleActionModel_OnRemoveBattleAction(__this);
}

// C#: System.Void OnSetExpectedTarget(BattleActionModel targetAction)
void hooked_BattleActionModel_OnSetExpectedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetAction) {
    original_BattleActionModel_OnSetExpectedTarget(__this, targetAction);
}

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel mainAction, BattleActionModel oppoActionNullable)
bool hooked_BattleActionModel_IsRunUniqueAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionNullable) {
    bool returnValue = original_BattleActionModel_IsRunUniqueAction(__this, uniqueTiming, mainAction, oppoActionNullable);
    MYO_LOG("BattleActionModel", "IsRunUniqueAction returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean IsEgoSkill()
bool hooked_BattleActionModel_IsEgoSkill(il2cpp::Il2CppObject* __this) {
    bool returnValue = original_BattleActionModel_IsEgoSkill(__this);
    MYO_LOG("BattleActionModel", "IsEgoSkill returns {}", returnValue);
    return returnValue;
}

// C#: System.Boolean HasEgoKeyword(EGO_KEYWORD keyword)
bool hooked_BattleActionModel_HasEgoKeyword(il2cpp::Il2CppObject* __this, int32_t keyword) {
    bool returnValue = original_BattleActionModel_HasEgoKeyword(__this, keyword);
    MYO_LOG("BattleActionModel", "HasEgoKeyword returns {}", returnValue);
    return returnValue;
}


#pragma endregion

void init_BattleActionModel_framework() {

    // Hook PassiveBase. Lines that are commented out are buff-container plumbing / queries / UI helpers
    // that a passive has no reason to override (matching the commented-out overrides in PassiveDetail).

    ClassCache BAMC = RegisterClassFull("BattleActionModel", IMG_MAIN, "", "BattleActionModel");

    // original_BattleActionModel_get_Sin = InstallHook<BattleActionModelget_SinFn>(BAMC.GetMethod("get_Sin"), &hooked_BattleActionModel_get_Sin);
    // original_BattleActionModel_get_Model = InstallHook<BattleActionModelget_ModelFn>(BAMC.GetMethod("get_Model"), &hooked_BattleActionModel_get_Model);
    // original_BattleActionModel_get_Skill = InstallHook<BattleActionModelget_SkillFn>(BAMC.GetMethod("get_Skill"), &hooked_BattleActionModel_get_Skill);
    // original_BattleActionModel_get_IsDone = InstallHook<BattleActionModelget_IsDoneFn>(BAMC.GetMethod("get_IsDone"), &hooked_BattleActionModel_get_IsDone);
    // original_BattleActionModel_get_isDoneWithAction = InstallHook<BattleActionModelget_isDoneWithActionFn>(BAMC.GetMethod("get_isDoneWithAction"), &hooked_BattleActionModel_get_isDoneWithAction);
    // original_BattleActionModel_get_skillPowerResultValue = InstallHook<BattleActionModelget_skillPowerResultValueFn>(BAMC.GetMethod("get_skillPowerResultValue"), &hooked_BattleActionModel_get_skillPowerResultValue);
    // original_BattleActionModel_get_ReusedTimes = InstallHook<BattleActionModelget_ReusedTimesFn>(BAMC.GetMethod("get_ReusedTimes"), &hooked_BattleActionModel_get_ReusedTimes);
    // original_BattleActionModel_get_SinAction = InstallHook<BattleActionModelget_SinActionFn>(BAMC.GetMethod("get_SinAction"), &hooked_BattleActionModel_get_SinAction);
    // original_BattleActionModel_get_ActionInstanceID = InstallHook<BattleActionModelget_ActionInstanceIDFn>(BAMC.GetMethod("get_ActionInstanceID"), &hooked_BattleActionModel_get_ActionInstanceID);
    // original_BattleActionModel_get_CommanderInstanceID = InstallHook<BattleActionModelget_CommanderInstanceIDFn>(BAMC.GetMethod("get_CommanderInstanceID"), &hooked_BattleActionModel_get_CommanderInstanceID);
    // original_BattleActionModel_get_OrderedActionInstanceId = InstallHook<BattleActionModelget_OrderedActionInstanceIdFn>(BAMC.GetMethod("get_OrderedActionInstanceId"), &hooked_BattleActionModel_get_OrderedActionInstanceId);
    // original_BattleActionModel_get_OrderedActionActorInstanceId = InstallHook<BattleActionModelget_OrderedActionActorInstanceIdFn>(BAMC.GetMethod("get_OrderedActionActorInstanceId"), &hooked_BattleActionModel_get_OrderedActionActorInstanceId);
    // original_BattleActionModel_get_IsExtracted = InstallHook<BattleActionModelget_IsExtractedFn>(BAMC.GetMethod("get_IsExtracted"), &hooked_BattleActionModel_get_IsExtracted);
    // original_BattleActionModel_get_Commander = InstallHook<BattleActionModelget_CommanderFn>(BAMC.GetMethod("get_Commander"), &hooked_BattleActionModel_get_Commander);
    // original_BattleActionModel_get_OrderSourceType = InstallHook<BattleActionModelget_OrderSourceTypeFn>(BAMC.GetMethod("get_OrderSourceType"), &hooked_BattleActionModel_get_OrderSourceType);
    // original_BattleActionModel_SetTargetDetailType = InstallHook<BattleActionModelSetTargetDetailTypeFn>(BAMC.GetMethod("SetTargetDetailType"), &hooked_BattleActionModel_SetTargetDetailType);
    // original_BattleActionModel_InitCoins = InstallHook<BattleActionModelInitCoinsFn>(BAMC.GetMethod("InitCoins"), &hooked_BattleActionModel_InitCoins);
    // original_BattleActionModel_InitCoinResults = InstallHook<BattleActionModelInitCoinResultsFn>(BAMC.GetMethod("InitCoinResults"), &hooked_BattleActionModel_InitCoinResults);
    // original_BattleActionModel_InitStaticData = InstallHook<BattleActionModelInitStaticDataFn>(BAMC.GetMethod("InitStaticData"), &hooked_BattleActionModel_InitStaticData);
    // original_BattleActionModel_IsActivatedSupportiveProtectByThisAction = InstallHook<BattleActionModelIsActivatedSupportiveProtectByThisActionFn>(BAMC.GetMethod("IsActivatedSupportiveProtectByThisAction"), &hooked_BattleActionModel_IsActivatedSupportiveProtectByThisAction);
    // original_BattleActionModel_CheckActivationOfSupportiveProtect = InstallHook<BattleActionModelCheckActivationOfSupportiveProtectFn>(BAMC.GetMethod("CheckActivationOfSupportiveProtect"), &hooked_BattleActionModel_CheckActivationOfSupportiveProtect);
    // original_BattleActionModel_IsSupportiveDefense_Old = InstallHook<BattleActionModelIsSupportiveDefense_OldFn>(BAMC.GetMethod("IsSupportiveDefense_Old"), &hooked_BattleActionModel_IsSupportiveDefense_Old);
    // original_BattleActionModel_IsSupportiveDefense = InstallHook<BattleActionModelIsSupportiveDefenseFn>(BAMC.GetMethod("IsSupportiveDefense"), &hooked_BattleActionModel_IsSupportiveDefense);
    // original_BattleActionModel_RemoveTargetData = InstallHook<BattleActionModelRemoveTargetDataFn>(BAMC.GetMethod("RemoveTargetData"), &hooked_BattleActionModel_RemoveTargetData);
    // original_BattleActionModel_GetOriginTargetSinActionsData = InstallHook<BattleActionModelGetOriginTargetSinActionsDataFn>(BAMC.GetMethod("GetOriginTargetSinActionsData"), &hooked_BattleActionModel_GetOriginTargetSinActionsData);
    // original_BattleActionModel_GetOriginMainTarget = InstallHook<BattleActionModelGetOriginMainTargetFn>(BAMC.GetMethod("GetOriginMainTarget"), &hooked_BattleActionModel_GetOriginMainTarget);
    // original_BattleActionModel_HasOriginTarget = InstallHook<BattleActionModelHasOriginTargetFn>(BAMC.GetMethod("HasOriginTarget"), &hooked_BattleActionModel_HasOriginTarget);
    // original_BattleActionModel_HasMainTarget = InstallHook<BattleActionModelHasMainTargetFn>(BAMC.GetMethod("HasMainTarget"), &hooked_BattleActionModel_HasMainTarget);
    // original_BattleActionModel_HasSubTarget = InstallHook<BattleActionModelHasSubTargetFn>(BAMC.GetMethod("HasSubTarget"), &hooked_BattleActionModel_HasSubTarget);
    // original_BattleActionModel_GetMainTargetSinAction = InstallHook<BattleActionModelGetMainTargetSinActionFn>(BAMC.GetMethod("GetMainTargetSinAction"), &hooked_BattleActionModel_GetMainTargetSinAction);
    // original_BattleActionModel_GetSubTargetSinActionList = InstallHook<BattleActionModelGetSubTargetSinActionListFn>(BAMC.GetMethod("GetSubTargetSinActionList"), &hooked_BattleActionModel_GetSubTargetSinActionList);
    // original_BattleActionModel_GetTargetSinActionList = InstallHook<BattleActionModelGetTargetSinActionListFn>(BAMC.GetMethod("GetTargetSinActionList"), &hooked_BattleActionModel_GetTargetSinActionList);
    // original_BattleActionModel_GetMainTarget = InstallHook<BattleActionModelGetMainTargetFn>(BAMC.GetMethod("GetMainTarget"), &hooked_BattleActionModel_GetMainTarget);
    // original_BattleActionModel_GetTargetUnitModelList = InstallHook<BattleActionModelGetTargetUnitModelListFn>(BAMC.GetMethod("GetTargetUnitModelList"), &hooked_BattleActionModel_GetTargetUnitModelList);
    // original_BattleActionModel_GetAliveTargetUnitModelList = InstallHook<BattleActionModelGetAliveTargetUnitModelListFn>(BAMC.GetMethod("GetAliveTargetUnitModelList"), &hooked_BattleActionModel_GetAliveTargetUnitModelList);
    // original_BattleActionModel_SetOriginTargetSinActions = InstallHook<BattleActionModelSetOriginTargetSinActionsFn>(BAMC.GetMethod("SetOriginTargetSinActions"), &hooked_BattleActionModel_SetOriginTargetSinActions);
    // original_BattleActionModel_ReadyOriginTargeting = InstallHook<BattleActionModelReadyOriginTargetingFn>(BAMC.GetMethod("ReadyOriginTargeting"), &hooked_BattleActionModel_ReadyOriginTargeting);
    // original_BattleActionModel_AddTarget = InstallHook<BattleActionModelAddTargetFn>(BAMC.GetMethod("AddTarget"), &hooked_BattleActionModel_AddTarget);
    // original_BattleActionModel_SetTargetAfterBattleStart = InstallHook<BattleActionModelSetTargetAfterBattleStartFn>(BAMC.GetMethod("SetTargetAfterBattleStart"), &hooked_BattleActionModel_SetTargetAfterBattleStart);
    // original_BattleActionModel_RedirectTarget = InstallHook<BattleActionModelRedirectTargetFn>(BAMC.GetMethod("RedirectTarget"), &hooked_BattleActionModel_RedirectTarget);
    // original_BattleActionModel_SetTargetAuto = InstallHook<BattleActionModelSetTargetAutoFn>(BAMC.GetMethod("SetTargetAuto"), &hooked_BattleActionModel_SetTargetAuto);
    // original_BattleActionModel_SetTargetBySortedTargetableSinActionList = InstallHook<BattleActionModelSetTargetBySortedTargetableSinActionListFn>(BAMC.GetMethod("SetTargetBySortedTargetableSinActionList"), &hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList);
    // original_BattleActionModel_SetTargetAfterBattleStart_CutIn = InstallHook<BattleActionModelSetTargetAfterBattleStart_CutInFn>(BAMC.GetMethod("SetTargetAfterBattleStart_CutIn"), &hooked_BattleActionModel_SetTargetAfterBattleStart_CutIn);
    // original_BattleActionModel_SetTargetAuto_CutIn = InstallHook<BattleActionModelSetTargetAuto_CutInFn>(BAMC.GetMethod("SetTargetAuto_CutIn"), &hooked_BattleActionModel_SetTargetAuto_CutIn);
    // original_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn = InstallHook<BattleActionModelSetTargetBySortedTargetableSinActionList_CutInFn>(BAMC.GetMethod("SetTargetBySortedTargetableSinActionList_CutIn"), &hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn);
    // original_BattleActionModel_RemoveOneTargetSet = InstallHook<BattleActionModelRemoveOneTargetSetFn>(BAMC.GetMethod("RemoveOneTargetSet"), &hooked_BattleActionModel_RemoveOneTargetSet);
    // original_BattleActionModel_CanDuelWithSameFaction = InstallHook<BattleActionModelCanDuelWithSameFactionFn>(BAMC.GetMethod("CanDuelWithSameFaction"), &hooked_BattleActionModel_CanDuelWithSameFaction);
    // original_BattleActionModel_SetTarget = InstallHook<BattleActionModelSetTargetFn>(BAMC.GetMethod("SetTarget"), &hooked_BattleActionModel_SetTarget);
    // original_BattleActionModel_RecheckTargetList = InstallHook<BattleActionModelRecheckTargetListFn>(BAMC.GetMethod("RecheckTargetList"), &hooked_BattleActionModel_RecheckTargetList);
    // original_BattleActionModel_AfterRecheckTargetList = InstallHook<BattleActionModelAfterRecheckTargetListFn>(BAMC.GetMethod("AfterRecheckTargetList"), &hooked_BattleActionModel_AfterRecheckTargetList);
    // original_BattleActionModel_ChangeAllTargetOnCompleteCommand = InstallHook<BattleActionModelChangeAllTargetOnCompleteCommandFn>(BAMC.GetMethod("ChangeAllTargetOnCompleteCommand"), &hooked_BattleActionModel_ChangeAllTargetOnCompleteCommand);
    // original_BattleActionModel_ChangeMainTargetSinAction = InstallHook<BattleActionModelChangeMainTargetSinActionFn>(BAMC.GetMethod("ChangeMainTargetSinAction"), &hooked_BattleActionModel_ChangeMainTargetSinAction);
    // original_BattleActionModel_HasBeenChangedCurrentTargetBy = InstallHook<BattleActionModelHasBeenChangedCurrentTargetByFn>(BAMC.GetMethod("HasBeenChangedCurrentTargetBy"), &hooked_BattleActionModel_HasBeenChangedCurrentTargetBy);
    // original_BattleActionModel_ChangeAllSubTarget = InstallHook<BattleActionModelChangeAllSubTargetFn>(BAMC.GetMethod("ChangeAllSubTarget"), &hooked_BattleActionModel_ChangeAllSubTarget);
    // original_BattleActionModel_RecheckSubTargetWhenChangeTargetNum = InstallHook<BattleActionModelRecheckSubTargetWhenChangeTargetNumFn>(BAMC.GetMethod("RecheckSubTargetWhenChangeTargetNum"), &hooked_BattleActionModel_RecheckSubTargetWhenChangeTargetNum);
    // original_BattleActionModel_RemoveAllTargetExceptMainTarget = InstallHook<BattleActionModelRemoveAllTargetExceptMainTargetFn>(BAMC.GetMethod("RemoveAllTargetExceptMainTarget"), &hooked_BattleActionModel_RemoveAllTargetExceptMainTarget);
    // original_BattleActionModel_RemoveUntargetableTarget = InstallHook<BattleActionModelRemoveUntargetableTargetFn>(BAMC.GetMethod("RemoveUntargetableTarget"), &hooked_BattleActionModel_RemoveUntargetableTarget);
    // original_BattleActionModel_GetCurrentOccupiedWeight_P0 = InstallHook<BattleActionModelGetCurrentOccupiedWeight_P0Fn>(BAMC.GetMethod("GetCurrentOccupiedWeight_P0"), &hooked_BattleActionModel_GetCurrentOccupiedWeight_P0);
    // original_BattleActionModel_GetCurrentOccupiedWeight_P1 = InstallHook<BattleActionModelGetCurrentOccupiedWeight_P1Fn>(BAMC.GetMethod("GetCurrentOccupiedWeight_P1"), &hooked_BattleActionModel_GetCurrentOccupiedWeight_P1);
    // original_BattleActionModel_AddPrimeTargets = InstallHook<BattleActionModelAddPrimeTargetsFn>(BAMC.GetMethod("AddPrimeTargets"), &hooked_BattleActionModel_AddPrimeTargets);
    // original_BattleActionModel_GetPrimeTargetSinActions = InstallHook<BattleActionModelGetPrimeTargetSinActionsFn>(BAMC.GetMethod("GetPrimeTargetSinActions"), &hooked_BattleActionModel_GetPrimeTargetSinActions);
    // original_BattleActionModel_GetSatisfiedPrimeTargetSinActions = InstallHook<BattleActionModelGetSatisfiedPrimeTargetSinActionsFn>(BAMC.GetMethod("GetSatisfiedPrimeTargetSinActions"), &hooked_BattleActionModel_GetSatisfiedPrimeTargetSinActions);
    // original_BattleActionModel_ExtractSortedPrimeTargetSinActionList = InstallHook<BattleActionModelExtractSortedPrimeTargetSinActionListFn>(BAMC.GetMethod("ExtractSortedPrimeTargetSinActionList"), &hooked_BattleActionModel_ExtractSortedPrimeTargetSinActionList);
    // original_BattleActionModel_GetCollapsedTargetableSinActionList = InstallHook<BattleActionModelGetCollapsedTargetableSinActionListFn>(BAMC.GetMethod("GetCollapsedTargetableSinActionList"), &hooked_BattleActionModel_GetCollapsedTargetableSinActionList);
    // original_BattleActionModel_SortSinActionList = InstallHook<BattleActionModelSortSinActionListFn>(BAMC.GetMethod("SortSinActionList"), &hooked_BattleActionModel_SortSinActionList);
    // original_BattleActionModel_GetTargetableUnitList = InstallHook<BattleActionModelGetTargetableUnitListFn>(BAMC.GetMethod("GetTargetableUnitList"), &hooked_BattleActionModel_GetTargetableUnitList);
    // original_BattleActionModel_SortTargetSlots = InstallHook<BattleActionModelSortTargetSlotsFn>(BAMC.GetMethod("SortTargetSlots"), &hooked_BattleActionModel_SortTargetSlots);
    // original_BattleActionModel_GetExpectedEgoErodeRate = InstallHook<BattleActionModelGetExpectedEgoErodeRateFn>(BAMC.GetMethod("GetExpectedEgoErodeRate"), &hooked_BattleActionModel_GetExpectedEgoErodeRate);
    // original_BattleActionModel_IsConsumeBuffSkill = InstallHook<BattleActionModelIsConsumeBuffSkillFn>(BAMC.GetMethod("IsConsumeBuffSkill"), &hooked_BattleActionModel_IsConsumeBuffSkill);
    // original_BattleActionModel_IsConsumeBullet = InstallHook<BattleActionModelIsConsumeBulletFn>(BAMC.GetMethod("IsConsumeBullet"), &hooked_BattleActionModel_IsConsumeBullet);
    // original_BattleActionModel_IsUseBuff = InstallHook<BattleActionModelIsUseBuffFn>(BAMC.GetMethod("IsUseBuff"), &hooked_BattleActionModel_IsUseBuff);
    // original_BattleActionModel_IsUseBuffStack = InstallHook<BattleActionModelIsUseBuffStackFn>(BAMC.GetMethod("IsUseBuffStack"), &hooked_BattleActionModel_IsUseBuffStack);
    // original_BattleActionModel_IsUseBuffTurn = InstallHook<BattleActionModelIsUseBuffTurnFn>(BAMC.GetMethod("IsUseBuffTurn"), &hooked_BattleActionModel_IsUseBuffTurn);
    // original_BattleActionModel_IsAddBloodDinner = InstallHook<BattleActionModelIsAddBloodDinnerFn>(BAMC.GetMethod("IsAddBloodDinner"), &hooked_BattleActionModel_IsAddBloodDinner);
    // original_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle = InstallHook<BattleActionModelGetExpectedAllCalculationOnlyAbnormalityBattleFn>(BAMC.GetMethod("GetExpectedAllCalculationOnlyAbnormalityBattle"), &hooked_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle);
    // original_BattleActionModel_MakeReusable = InstallHook<BattleActionModelMakeReusableFn>(BAMC.GetMethod("MakeReusable"), &hooked_BattleActionModel_MakeReusable);
    // original_BattleActionModel_ResetAllTargetData = InstallHook<BattleActionModelResetAllTargetDataFn>(BAMC.GetMethod("ResetAllTargetData"), &hooked_BattleActionModel_ResetAllTargetData);
    // original_BattleActionModel_ResetCoinState = InstallHook<BattleActionModelResetCoinStateFn>(BAMC.GetMethod("ResetCoinState"), &hooked_BattleActionModel_ResetCoinState);
    // original_BattleActionModel_ResetDataWIthOutTargetData = InstallHook<BattleActionModelResetDataWIthOutTargetDataFn>(BAMC.GetMethod("ResetDataWIthOutTargetData"), &hooked_BattleActionModel_ResetDataWIthOutTargetData);
    // original_BattleActionModel_AddAttackedTarget = InstallHook<BattleActionModelAddAttackedTargetFn>(BAMC.GetMethod("AddAttackedTarget"), &hooked_BattleActionModel_AddAttackedTarget);
    // original_BattleActionModel_GetAttackedTargetList = InstallHook<BattleActionModelGetAttackedTargetListFn>(BAMC.GetMethod("GetAttackedTargetList"), &hooked_BattleActionModel_GetAttackedTargetList);
    // original_BattleActionModel_CheckCoinDestroy = InstallHook<BattleActionModelCheckCoinDestroyFn>(BAMC.GetMethod("CheckCoinDestroy"), &hooked_BattleActionModel_CheckCoinDestroy);
    // original_BattleActionModel_GetHighestCoin = InstallHook<BattleActionModelGetHighestCoinFn>(BAMC.GetMethod("GetHighestCoin"), &hooked_BattleActionModel_GetHighestCoin);
    // original_BattleActionModel_GetDestroyTargetCoin = InstallHook<BattleActionModelGetDestroyTargetCoinFn>(BAMC.GetMethod("GetDestroyTargetCoin"), &hooked_BattleActionModel_GetDestroyTargetCoin);
    // original_BattleActionModel_GetSkillID = InstallHook<BattleActionModelGetSkillIDFn>(BAMC.GetMethod("GetSkillID"), &hooked_BattleActionModel_GetSkillID);
    // original_BattleActionModel_GetSkillTargetType = InstallHook<BattleActionModelGetSkillTargetTypeFn>(BAMC.GetMethod("GetSkillTargetType"), &hooked_BattleActionModel_GetSkillTargetType);
    // original_BattleActionModel_GetAttackWeight = InstallHook<BattleActionModelGetAttackWeightFn>(BAMC.GetMethod("GetAttackWeight"), &hooked_BattleActionModel_GetAttackWeight);
    // original_BattleActionModel_GetOriginAttackWeight = InstallHook<BattleActionModelGetOriginAttackWeightFn>(BAMC.GetMethod("GetOriginAttackWeight"), &hooked_BattleActionModel_GetOriginAttackWeight);
    // original_BattleActionModel_GetDefenseType = InstallHook<BattleActionModelGetDefenseTypeFn>(BAMC.GetMethod("GetDefenseType"), &hooked_BattleActionModel_GetDefenseType);
    // original_BattleActionModel_GetSkillAtkType = InstallHook<BattleActionModelGetSkillAtkTypeFn>(BAMC.GetMethod("GetSkillAtkType"), &hooked_BattleActionModel_GetSkillAtkType);
    // original_BattleActionModel_TryGetOverwriteAtkBehaviour = InstallHook<BattleActionModelTryGetOverwriteAtkBehaviourFn>(BAMC.GetMethod("TryGetOverwriteAtkBehaviour"), &hooked_BattleActionModel_TryGetOverwriteAtkBehaviour);
    // original_BattleActionModel_IsSkillAtkType = InstallHook<BattleActionModelIsSkillAtkTypeFn>(BAMC.GetMethod("IsSkillAtkType"), &hooked_BattleActionModel_IsSkillAtkType);
    // original_BattleActionModel_GetSkillAttributeType = InstallHook<BattleActionModelGetSkillAttributeTypeFn>(BAMC.GetMethod("GetSkillAttributeType"), &hooked_BattleActionModel_GetSkillAttributeType);
    // original_BattleActionModel_IsSkillAttributeType = InstallHook<BattleActionModelIsSkillAttributeTypeFn>(BAMC.GetMethod("IsSkillAttributeType"), &hooked_BattleActionModel_IsSkillAttributeType);
    // original_BattleActionModel_IsAttack = InstallHook<BattleActionModelIsAttackFn>(BAMC.GetMethod("IsAttack"), &hooked_BattleActionModel_IsAttack);
    // original_BattleActionModel_IsDefense = InstallHook<BattleActionModelIsDefenseFn>(BAMC.GetMethod("IsDefense"), &hooked_BattleActionModel_IsDefense);
    // original_BattleActionModel_IsDefenseNotCounter = InstallHook<BattleActionModelIsDefenseNotCounterFn>(BAMC.GetMethod("IsDefenseNotCounter"), &hooked_BattleActionModel_IsDefenseNotCounter);
    // original_BattleActionModel_IsGuard = InstallHook<BattleActionModelIsGuardFn>(BAMC.GetMethod("IsGuard"), &hooked_BattleActionModel_IsGuard);
    // original_BattleActionModel_IsCounter = InstallHook<BattleActionModelIsCounterFn>(BAMC.GetMethod("IsCounter"), &hooked_BattleActionModel_IsCounter);
    // original_BattleActionModel_IsCanDuelDefense = InstallHook<BattleActionModelIsCanDuelDefenseFn>(BAMC.GetMethod("IsCanDuelDefense"), &hooked_BattleActionModel_IsCanDuelDefense);
    // original_BattleActionModel_IsEvade = InstallHook<BattleActionModelIsEvadeFn>(BAMC.GetMethod("IsEvade"), &hooked_BattleActionModel_IsEvade);
    // original_BattleActionModel_IgnoreDefenseSkill = InstallHook<BattleActionModelIgnoreDefenseSkillFn>(BAMC.GetMethod("IgnoreDefenseSkill"), &hooked_BattleActionModel_IgnoreDefenseSkill);
    // original_BattleActionModel_IgnoreSupportiveDefense = InstallHook<BattleActionModelIgnoreSupportiveDefenseFn>(BAMC.GetMethod("IgnoreSupportiveDefense"), &hooked_BattleActionModel_IgnoreSupportiveDefense);
    // original_BattleActionModel_IsActionable = InstallHook<BattleActionModelIsActionableFn>(BAMC.GetMethod("IsActionable"), &hooked_BattleActionModel_IsActionable);
    // original_BattleActionModel_OnAttackCanceledByAbility = InstallHook<BattleActionModelOnAttackCanceledByAbilityFn>(BAMC.GetMethod("OnAttackCanceledByAbility"), &hooked_BattleActionModel_OnAttackCanceledByAbility);
    // original_BattleActionModel_CanBeChangedTarget = InstallHook<BattleActionModelCanBeChangedTargetFn>(BAMC.GetMethod("CanBeChangedTarget"), &hooked_BattleActionModel_CanBeChangedTarget);
    // original_BattleActionModel_CanChangeMainTargetRegardlessSpeed = InstallHook<BattleActionModelCanChangeMainTargetRegardlessSpeedFn>(BAMC.GetMethod("CanChangeMainTargetRegardlessSpeed"), &hooked_BattleActionModel_CanChangeMainTargetRegardlessSpeed);
    // original_BattleActionModel_CanBeChangedTargetIgnoreSpeed = InstallHook<BattleActionModelCanBeChangedTargetIgnoreSpeedFn>(BAMC.GetMethod("CanBeChangedTargetIgnoreSpeed"), &hooked_BattleActionModel_CanBeChangedTargetIgnoreSpeed);
    // original_BattleActionModel_ChangeEgoSkill = InstallHook<BattleActionModelChangeEgoSkillFn>(BAMC.GetMethod("ChangeEgoSkill"), &hooked_BattleActionModel_ChangeEgoSkill);
    // original_BattleActionModel_TryChangeSkill = InstallHook<BattleActionModelTryChangeSkillFn>(BAMC.GetMethod("TryChangeSkill"), &hooked_BattleActionModel_TryChangeSkill);
    // original_BattleActionModel_ChangeSkill = InstallHook<BattleActionModelChangeSkillFn>(BAMC.GetMethod("ChangeSkill"), &hooked_BattleActionModel_ChangeSkill);
    // original_BattleActionModel_ReturnPreviousSkill = InstallHook<BattleActionModelReturnPreviousSkillFn>(BAMC.GetMethod("ReturnPreviousSkill"), &hooked_BattleActionModel_ReturnPreviousSkill);
    // original_BattleActionModel_GetResonanceIndexOrStack = InstallHook<BattleActionModelGetResonanceIndexOrStackFn>(BAMC.GetMethod("GetResonanceIndexOrStack"), &hooked_BattleActionModel_GetResonanceIndexOrStack);
    // original_BattleActionModel_GetExpectedResonanceIndexOrStack_P0 = InstallHook<BattleActionModelGetExpectedResonanceIndexOrStack_P0Fn>(BAMC.GetMethod("GetExpectedResonanceIndexOrStack_P0"), &hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P0);
    // original_BattleActionModel_GetExpectedResonanceIndexOrStack_P1 = InstallHook<BattleActionModelGetExpectedResonanceIndexOrStack_P1Fn>(BAMC.GetMethod("GetExpectedResonanceIndexOrStack_P1"), &hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P1);
    // original_BattleActionModel_GetAttributeResonanceIndex = InstallHook<BattleActionModelGetAttributeResonanceIndexFn>(BAMC.GetMethod("GetAttributeResonanceIndex"), &hooked_BattleActionModel_GetAttributeResonanceIndex);
    // original_BattleActionModel_GetPerfectResonanceStack = InstallHook<BattleActionModelGetPerfectResonanceStackFn>(BAMC.GetMethod("GetPerfectResonanceStack"), &hooked_BattleActionModel_GetPerfectResonanceStack);
    // original_BattleActionModel_CheckResonancePassive = InstallHook<BattleActionModelCheckResonancePassiveFn>(BAMC.GetMethod("CheckResonancePassive"), &hooked_BattleActionModel_CheckResonancePassive);
    // original_BattleActionModel_OnAttributeResonance = InstallHook<BattleActionModelOnAttributeResonanceFn>(BAMC.GetMethod("OnAttributeResonance"), &hooked_BattleActionModel_OnAttributeResonance);
    // original_BattleActionModel_HasCommander = InstallHook<BattleActionModelHasCommanderFn>(BAMC.GetMethod("HasCommander"), &hooked_BattleActionModel_HasCommander);
    // original_BattleActionModel_SetDefenseLevel_After_UseSkill = InstallHook<BattleActionModelSetDefenseLevel_After_UseSkillFn>(BAMC.GetMethod("SetDefenseLevel_After_UseSkill"), &hooked_BattleActionModel_SetDefenseLevel_After_UseSkill);
    // original_BattleActionModel_ModifySpeedByParrying = InstallHook<BattleActionModelModifySpeedByParryingFn>(BAMC.GetMethod("ModifySpeedByParrying"), &hooked_BattleActionModel_ModifySpeedByParrying);
    // original_BattleActionModel_ResetSpeedByParrying = InstallHook<BattleActionModelResetSpeedByParryingFn>(BAMC.GetMethod("ResetSpeedByParrying"), &hooked_BattleActionModel_ResetSpeedByParrying);
    // original_BattleActionModel_RollSkillPower = InstallHook<BattleActionModelRollSkillPowerFn>(BAMC.GetMethod("RollSkillPower"), &hooked_BattleActionModel_RollSkillPower);
    // original_BattleActionModel_RollSkillPowerParrying = InstallHook<BattleActionModelRollSkillPowerParryingFn>(BAMC.GetMethod("RollSkillPowerParrying"), &hooked_BattleActionModel_RollSkillPowerParrying);
    // original_BattleActionModel_CreateSkillPowerData = InstallHook<BattleActionModelCreateSkillPowerDataFn>(BAMC.GetMethod("CreateSkillPowerData"), &hooked_BattleActionModel_CreateSkillPowerData);
    // original_BattleActionModel_CreateParryingData = InstallHook<BattleActionModelCreateParryingDataFn>(BAMC.GetMethod("CreateParryingData"), &hooked_BattleActionModel_CreateParryingData);
    // original_BattleActionModel_CanRollAllCoinForUI = InstallHook<BattleActionModelCanRollAllCoinForUIFn>(BAMC.GetMethod("CanRollAllCoinForUI"), &hooked_BattleActionModel_CanRollAllCoinForUI);
    // original_BattleActionModel_IsRetreatSkill = InstallHook<BattleActionModelIsRetreatSkillFn>(BAMC.GetMethod("IsRetreatSkill"), &hooked_BattleActionModel_IsRetreatSkill);
    // original_BattleActionModel_IsCommandRetreatSkill = InstallHook<BattleActionModelIsCommandRetreatSkillFn>(BAMC.GetMethod("IsCommandRetreatSkill"), &hooked_BattleActionModel_IsCommandRetreatSkill);
    // original_BattleActionModel_CanRollCoin = InstallHook<BattleActionModelCanRollCoinFn>(BAMC.GetMethod("CanRollCoin"), &hooked_BattleActionModel_CanRollCoin);
    // original_BattleActionModel_Behave = InstallHook<BattleActionModelBehaveFn>(BAMC.GetMethod("Behave"), &hooked_BattleActionModel_Behave);
    // original_BattleActionModel_BeforeCompleteCommand = InstallHook<BattleActionModelBeforeCompleteCommandFn>(BAMC.GetMethod("BeforeCompleteCommand"), &hooked_BattleActionModel_BeforeCompleteCommand);
    // original_BattleActionModel_OnChangeSkillBeforeCompleteCommand = InstallHook<BattleActionModelOnChangeSkillBeforeCompleteCommandFn>(BAMC.GetMethod("OnChangeSkillBeforeCompleteCommand"), &hooked_BattleActionModel_OnChangeSkillBeforeCompleteCommand);
    // original_BattleActionModel_ActivateGuard = InstallHook<BattleActionModelActivateGuardFn>(BAMC.GetMethod("ActivateGuard"), &hooked_BattleActionModel_ActivateGuard);
    // original_BattleActionModel_CheckOneOnOneDuelState = InstallHook<BattleActionModelCheckOneOnOneDuelStateFn>(BAMC.GetMethod("CheckOneOnOneDuelState"), &hooked_BattleActionModel_CheckOneOnOneDuelState);
    // original_BattleActionModel_IsOneOnOneDuel = InstallHook<BattleActionModelIsOneOnOneDuelFn>(BAMC.GetMethod("IsOneOnOneDuel"), &hooked_BattleActionModel_IsOneOnOneDuel);
    original_BattleActionModel_OnCompleteCommand = InstallHook<BattleActionModelOnCompleteCommandFn>(BAMC.GetMethod("OnCompleteCommand"), &hooked_BattleActionModel_OnCompleteCommand);
    original_BattleActionModel_OnBattleStart = InstallHook<BattleActionModelOnBattleStartFn>(BAMC.GetMethod("OnBattleStart"), &hooked_BattleActionModel_OnBattleStart);
    original_BattleActionModel_CanAttackTargets = InstallHook<BattleActionModelCanAttackTargetsFn>(BAMC.GetMethod("CanAttackTargets"), &hooked_BattleActionModel_CanAttackTargets);
    original_BattleActionModel_CheckTargetableTarget = InstallHook<BattleActionModelCheckTargetableTargetFn>(BAMC.GetMethod("CheckTargetableTarget"), &hooked_BattleActionModel_CheckTargetableTarget);
    original_BattleActionModel_OnEndBehave_Refresh = InstallHook<BattleActionModelOnEndBehave_RefreshFn>(BAMC.GetMethod("OnEndBehave_Refresh"), &hooked_BattleActionModel_OnEndBehave_Refresh);
    original_BattleActionModel_AffectToReturnUnit = InstallHook<BattleActionModelAffectToReturnUnitFn>(BAMC.GetMethod("AffectToReturnUnit"), &hooked_BattleActionModel_AffectToReturnUnit);
    original_BattleActionModel_CallTargetDefenseActionsByAttack = InstallHook<BattleActionModelCallTargetDefenseActionsByAttackFn>(BAMC.GetMethod("CallTargetDefenseActionsByAttack"), &hooked_BattleActionModel_CallTargetDefenseActionsByAttack);
    original_BattleActionModel_OnRoundStart_After = InstallHook<BattleActionModelOnRoundStart_AfterFn>(BAMC.GetMethod("OnRoundStart_After"), &hooked_BattleActionModel_OnRoundStart_After);
    original_BattleActionModel_OnBeforeTurn = InstallHook<BattleActionModelOnBeforeTurnFn>(BAMC.GetMethod("OnBeforeTurn"), &hooked_BattleActionModel_OnBeforeTurn);
    original_BattleActionModel_OnCancelAction = InstallHook<BattleActionModelOnCancelActionFn>(BAMC.GetMethod("OnCancelAction"), &hooked_BattleActionModel_OnCancelAction);
    original_BattleActionModel_OnBeforeDefense = InstallHook<BattleActionModelOnBeforeDefenseFn>(BAMC.GetMethod("OnBeforeDefense"), &hooked_BattleActionModel_OnBeforeDefense);
    original_BattleActionModel_OnStartTurn_BeforeLog = InstallHook<BattleActionModelOnStartTurn_BeforeLogFn>(BAMC.GetMethod("OnStartTurn_BeforeLog"), &hooked_BattleActionModel_OnStartTurn_BeforeLog);
    original_BattleActionModel_OnStartTurn_AfterLog = InstallHook<BattleActionModelOnStartTurn_AfterLogFn>(BAMC.GetMethod("OnStartTurn_AfterLog"), &hooked_BattleActionModel_OnStartTurn_AfterLog);
    original_BattleActionModel_OnTryEvade = InstallHook<BattleActionModelOnTryEvadeFn>(BAMC.GetMethod("OnTryEvade"), &hooked_BattleActionModel_OnTryEvade);
    original_BattleActionModel_OnStartDuel = InstallHook<BattleActionModelOnStartDuelFn>(BAMC.GetMethod("OnStartDuel"), &hooked_BattleActionModel_OnStartDuel);
    original_BattleActionModel_OnBeforeParryingOnce = InstallHook<BattleActionModelOnBeforeParryingOnceFn>(BAMC.GetMethod("OnBeforeParryingOnce"), &hooked_BattleActionModel_OnBeforeParryingOnce);
    original_BattleActionModel_OnBeforeParryingOnce_AfterLog = InstallHook<BattleActionModelOnBeforeParryingOnce_AfterLogFn>(BAMC.GetMethod("OnBeforeParryingOnce_AfterLog"), &hooked_BattleActionModel_OnBeforeParryingOnce_AfterLog);
    original_BattleActionModel_OnDuelAfter_BeforeLog = InstallHook<BattleActionModelOnDuelAfter_BeforeLogFn>(BAMC.GetMethod("OnDuelAfter_BeforeLog"), &hooked_BattleActionModel_OnDuelAfter_BeforeLog);
    original_BattleActionModel_OnDuelAfter_AfterLog = InstallHook<BattleActionModelOnDuelAfter_AfterLogFn>(BAMC.GetMethod("OnDuelAfter_AfterLog"), &hooked_BattleActionModel_OnDuelAfter_AfterLog);
    original_BattleActionModel_OnAfterParryingOnce_BeforeLog = InstallHook<BattleActionModelOnAfterParryingOnce_BeforeLogFn>(BAMC.GetMethod("OnAfterParryingOnce_BeforeLog"), &hooked_BattleActionModel_OnAfterParryingOnce_BeforeLog);
    original_BattleActionModel_OnAfterParryingOnce_AfterLog = InstallHook<BattleActionModelOnAfterParryingOnce_AfterLogFn>(BAMC.GetMethod("OnAfterParryingOnce_AfterLog"), &hooked_BattleActionModel_OnAfterParryingOnce_AfterLog);
    original_BattleActionModel_OnWinParrying = InstallHook<BattleActionModelOnWinParryingFn>(BAMC.GetMethod("OnWinParrying"), &hooked_BattleActionModel_OnWinParrying);
    original_BattleActionModel_OnLoseParrying = InstallHook<BattleActionModelOnLoseParryingFn>(BAMC.GetMethod("OnLoseParrying"), &hooked_BattleActionModel_OnLoseParrying);
    original_BattleActionModel_OnWinDuel = InstallHook<BattleActionModelOnWinDuelFn>(BAMC.GetMethod("OnWinDuel"), &hooked_BattleActionModel_OnWinDuel);
    original_BattleActionModel_CheckExtractAbility = InstallHook<BattleActionModelCheckExtractAbilityFn>(BAMC.GetMethod("CheckExtractAbility"), &hooked_BattleActionModel_CheckExtractAbility);
    original_BattleActionModel_FirstBsGaugeUpWithDuelableGuard = InstallHook<BattleActionModelFirstBsGaugeUpWithDuelableGuardFn>(BAMC.GetMethod("FirstBsGaugeUpWithDuelableGuard"), &hooked_BattleActionModel_FirstBsGaugeUpWithDuelableGuard);
    original_BattleActionModel_OnLoseDuel = InstallHook<BattleActionModelOnLoseDuelFn>(BAMC.GetMethod("OnLoseDuel"), &hooked_BattleActionModel_OnLoseDuel);
    original_BattleActionModel_BeforeBehaviour = InstallHook<BattleActionModelBeforeBehaviourFn>(BAMC.GetMethod("BeforeBehaviour"), &hooked_BattleActionModel_BeforeBehaviour);
    original_BattleActionModel_OnStartBehaviour = InstallHook<BattleActionModelOnStartBehaviourFn>(BAMC.GetMethod("OnStartBehaviour"), &hooked_BattleActionModel_OnStartBehaviour);
    original_BattleActionModel_OnCriticalIsActivated = InstallHook<BattleActionModelOnCriticalIsActivatedFn>(BAMC.GetMethod("OnCriticalIsActivated"), &hooked_BattleActionModel_OnCriticalIsActivated);
    original_BattleActionModel_OnAttackConfirmed = InstallHook<BattleActionModelOnAttackConfirmedFn>(BAMC.GetMethod("OnAttackConfirmed"), &hooked_BattleActionModel_OnAttackConfirmed);
    original_BattleActionModel_BeforeGiveAttackDamage = InstallHook<BattleActionModelBeforeGiveAttackDamageFn>(BAMC.GetMethod("BeforeGiveAttackDamage"), &hooked_BattleActionModel_BeforeGiveAttackDamage);
    original_BattleActionModel_OnSucceedAttack = InstallHook<BattleActionModelOnSucceedAttackFn>(BAMC.GetMethod("OnSucceedAttack"), &hooked_BattleActionModel_OnSucceedAttack);
    original_BattleActionModel_CanGiveConcentratedAttack = InstallHook<BattleActionModelCanGiveConcentratedAttackFn>(BAMC.GetMethod("CanGiveConcentratedAttack"), &hooked_BattleActionModel_CanGiveConcentratedAttack);
    original_BattleActionModel_OnSucceedEvade = InstallHook<BattleActionModelOnSucceedEvadeFn>(BAMC.GetMethod("OnSucceedEvade"), &hooked_BattleActionModel_OnSucceedEvade);
    original_BattleActionModel_OnFailedEvade = InstallHook<BattleActionModelOnFailedEvadeFn>(BAMC.GetMethod("OnFailedEvade"), &hooked_BattleActionModel_OnFailedEvade);
    original_BattleActionModel_OnStartCoin = InstallHook<BattleActionModelOnStartCoinFn>(BAMC.GetMethod("OnStartCoin"), &hooked_BattleActionModel_OnStartCoin);
    original_BattleActionModel_OnEndCoin_BeforeLog = InstallHook<BattleActionModelOnEndCoin_BeforeLogFn>(BAMC.GetMethod("OnEndCoin_BeforeLog"), &hooked_BattleActionModel_OnEndCoin_BeforeLog);
    original_BattleActionModel_OnEndCoin_AfterLog = InstallHook<BattleActionModelOnEndCoin_AfterLogFn>(BAMC.GetMethod("OnEndCoin_AfterLog"), &hooked_BattleActionModel_OnEndCoin_AfterLog);
    original_BattleActionModel_OnEndAttack = InstallHook<BattleActionModelOnEndAttackFn>(BAMC.GetMethod("OnEndAttack"), &hooked_BattleActionModel_OnEndAttack);
    original_BattleActionModel_OnEndBehaviour = InstallHook<BattleActionModelOnEndBehaviourFn>(BAMC.GetMethod("OnEndBehaviour"), &hooked_BattleActionModel_OnEndBehaviour);
    original_BattleActionModel_OnGiveBsGaugeUp = InstallHook<BattleActionModelOnGiveBsGaugeUpFn>(BAMC.GetMethod("OnGiveBsGaugeUp"), &hooked_BattleActionModel_OnGiveBsGaugeUp);
    original_BattleActionModel_OnEndTurn = InstallHook<BattleActionModelOnEndTurnFn>(BAMC.GetMethod("OnEndTurn"), &hooked_BattleActionModel_OnEndTurn);
    original_BattleActionModel_OnDiscarded = InstallHook<BattleActionModelOnDiscardedFn>(BAMC.GetMethod("OnDiscarded"), &hooked_BattleActionModel_OnDiscarded);
    original_BattleActionModel_OnKillTarget = InstallHook<BattleActionModelOnKillTargetFn>(BAMC.GetMethod("OnKillTarget"), &hooked_BattleActionModel_OnKillTarget);
    original_BattleActionModel_OnBreakTarget = InstallHook<BattleActionModelOnBreakTargetFn>(BAMC.GetMethod("OnBreakTarget"), &hooked_BattleActionModel_OnBreakTarget);
    original_BattleActionModel_OnDestroyTargetPart = InstallHook<BattleActionModelOnDestroyTargetPartFn>(BAMC.GetMethod("OnDestroyTargetPart"), &hooked_BattleActionModel_OnDestroyTargetPart);
    original_BattleActionModel_Done = InstallHook<BattleActionModelDoneFn>(BAMC.GetMethod("Done"), &hooked_BattleActionModel_Done);
    original_BattleActionModel_DoneWithAction = InstallHook<BattleActionModelDoneWithActionFn>(BAMC.GetMethod("DoneWithAction"), &hooked_BattleActionModel_DoneWithAction);
    original_BattleActionModel_AddSinStock = InstallHook<BattleActionModelAddSinStockFn>(BAMC.GetMethod("AddSinStock"), &hooked_BattleActionModel_AddSinStock);
    // TODO ambiguous overload (another GetExpectedMinCoinValue has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedMinCoinValue_P2_1 = InstallHook<BattleActionModelGetExpectedMinCoinValue_P2_1Fn>(BAMC.GetMethod("GetExpectedMinCoinValue_P2"), &hooked_BattleActionModel_GetExpectedMinCoinValue_P2_1);
    // TODO ambiguous overload (another GetExpectedMaxCoinValue has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedMaxCoinValue_P2_1 = InstallHook<BattleActionModelGetExpectedMaxCoinValue_P2_1Fn>(BAMC.GetMethod("GetExpectedMaxCoinValue_P2"), &hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_1);
    // TODO ambiguous overload (another GetExpectedMinCoinValue has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedMinCoinValue_P2_2 = InstallHook<BattleActionModelGetExpectedMinCoinValue_P2_2Fn>(BAMC.GetMethod("GetExpectedMinCoinValue_P2"), &hooked_BattleActionModel_GetExpectedMinCoinValue_P2_2);
    // TODO ambiguous overload (another GetExpectedMaxCoinValue has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedMaxCoinValue_P2_2 = InstallHook<BattleActionModelGetExpectedMaxCoinValue_P2_2Fn>(BAMC.GetMethod("GetExpectedMaxCoinValue_P2"), &hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_2);
    original_BattleActionModel_GetExpectedCalculation = InstallHook<BattleActionModelGetExpectedCalculationFn>(BAMC.GetMethod("GetExpectedCalculation"), &hooked_BattleActionModel_GetExpectedCalculation);
    original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage = InstallHook<BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageFn>(BAMC.GetMethod("GetExpectedRateOfIncreaseAndDecreaseDamage"), &hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage);
    original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget = InstallHook<BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageByTargetFn>(BAMC.GetMethod("GetExpectedRateOfIncreaseAndDecreaseDamageByTarget"), &hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget);
    original_BattleActionModel_GetExpectedDamage = InstallHook<BattleActionModelGetExpectedDamageFn>(BAMC.GetMethod("GetExpectedDamage"), &hooked_BattleActionModel_GetExpectedDamage);
    original_BattleActionModel_GetExpectedDamageByTarget = InstallHook<BattleActionModelGetExpectedDamageByTargetFn>(BAMC.GetMethod("GetExpectedDamageByTarget"), &hooked_BattleActionModel_GetExpectedDamageByTarget);
    original_BattleActionModel_IsDuelExpcted = InstallHook<BattleActionModelIsDuelExpctedFn>(BAMC.GetMethod("IsDuelExpcted"), &hooked_BattleActionModel_IsDuelExpcted);
    original_BattleActionModel_GetParryingCalculation = InstallHook<BattleActionModelGetParryingCalculationFn>(BAMC.GetMethod("GetParryingCalculation"), &hooked_BattleActionModel_GetParryingCalculation);
    original_BattleActionModel_GetDamageCalculation = InstallHook<BattleActionModelGetDamageCalculationFn>(BAMC.GetMethod("GetDamageCalculation"), &hooked_BattleActionModel_GetDamageCalculation);
    original_BattleActionModel_GetSnowBallingCalculation = InstallHook<BattleActionModelGetSnowBallingCalculationFn>(BAMC.GetMethod("GetSnowBallingCalculation"), &hooked_BattleActionModel_GetSnowBallingCalculation);
    original_BattleActionModel_GetDefaultAllCoinCalculation = InstallHook<BattleActionModelGetDefaultAllCoinCalculationFn>(BAMC.GetMethod("GetDefaultAllCoinCalculation"), &hooked_BattleActionModel_GetDefaultAllCoinCalculation);
    original_BattleActionModel_GetParryingAdder = InstallHook<BattleActionModelGetParryingAdderFn>(BAMC.GetMethod("GetParryingAdder"), &hooked_BattleActionModel_GetParryingAdder);
    original_BattleActionModel_GetMinExpectedDamage = InstallHook<BattleActionModelGetMinExpectedDamageFn>(BAMC.GetMethod("GetMinExpectedDamage"), &hooked_BattleActionModel_GetMinExpectedDamage);
    original_BattleActionModel_GetCriticalChance = InstallHook<BattleActionModelGetCriticalChanceFn>(BAMC.GetMethod("GetCriticalChance"), &hooked_BattleActionModel_GetCriticalChance);
    original_BattleActionModel_CanTeamKill = InstallHook<BattleActionModelCanTeamKillFn>(BAMC.GetMethod("CanTeamKill"), &hooked_BattleActionModel_CanTeamKill);
    original_BattleActionModel_GetSkillLevel = InstallHook<BattleActionModelGetSkillLevelFn>(BAMC.GetMethod("GetSkillLevel"), &hooked_BattleActionModel_GetSkillLevel);
    original_BattleActionModel_GetSkillPower = InstallHook<BattleActionModelGetSkillPowerFn>(BAMC.GetMethod("GetSkillPower"), &hooked_BattleActionModel_GetSkillPower);
    // TODO ambiguous overload (another GetExpectedSkillPower has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedSkillPower_P3_1 = InstallHook<BattleActionModelGetExpectedSkillPower_P3_1Fn>(BAMC.GetMethod("GetExpectedSkillPower_P3"), &hooked_BattleActionModel_GetExpectedSkillPower_P3_1);
    // TODO ambiguous overload (another GetExpectedSkillPower has the same param count; GetMethod can't pick yet):
    // original_BattleActionModel_GetExpectedSkillPower_P3_2 = InstallHook<BattleActionModelGetExpectedSkillPower_P3_2Fn>(BAMC.GetMethod("GetExpectedSkillPower_P3"), &hooked_BattleActionModel_GetExpectedSkillPower_P3_2);
    original_BattleActionModel_GetCoinScale = InstallHook<BattleActionModelGetCoinScaleFn>(BAMC.GetMethod("GetCoinScale"), &hooked_BattleActionModel_GetCoinScale);
    original_BattleActionModel_OverrideCoinScale = InstallHook<BattleActionModelOverrideCoinScaleFn>(BAMC.GetMethod("OverrideCoinScale"), &hooked_BattleActionModel_OverrideCoinScale);
    original_BattleActionModel_GetExpectedCoinScale = InstallHook<BattleActionModelGetExpectedCoinScaleFn>(BAMC.GetMethod("GetExpectedCoinScale"), &hooked_BattleActionModel_GetExpectedCoinScale);
    original_BattleActionModel_GetAttackHpDmgAdder = InstallHook<BattleActionModelGetAttackHpDmgAdderFn>(BAMC.GetMethod("GetAttackHpDmgAdder"), &hooked_BattleActionModel_GetAttackHpDmgAdder);
    original_BattleActionModel_GetExpectedAttackHpDmgAdder = InstallHook<BattleActionModelGetExpectedAttackHpDmgAdderFn>(BAMC.GetMethod("GetExpectedAttackHpDmgAdder"), &hooked_BattleActionModel_GetExpectedAttackHpDmgAdder);
    original_BattleActionModel_GetCoinScaleAdder = InstallHook<BattleActionModelGetCoinScaleAdderFn>(BAMC.GetMethod("GetCoinScaleAdder"), &hooked_BattleActionModel_GetCoinScaleAdder);
    original_BattleActionModel_GetExpectedCoinScaleAdder = InstallHook<BattleActionModelGetExpectedCoinScaleAdderFn>(BAMC.GetMethod("GetExpectedCoinScaleAdder"), &hooked_BattleActionModel_GetExpectedCoinScaleAdder);
    original_BattleActionModel_GetSkillPowerResultAdder = InstallHook<BattleActionModelGetSkillPowerResultAdderFn>(BAMC.GetMethod("GetSkillPowerResultAdder"), &hooked_BattleActionModel_GetSkillPowerResultAdder);
    original_BattleActionModel_GetExpectedSkillPowerAdder = InstallHook<BattleActionModelGetExpectedSkillPowerAdderFn>(BAMC.GetMethod("GetExpectedSkillPowerAdder"), &hooked_BattleActionModel_GetExpectedSkillPowerAdder);
    original_BattleActionModel_GetExpectedSkillPowerResultAdder = InstallHook<BattleActionModelGetExpectedSkillPowerResultAdderFn>(BAMC.GetMethod("GetExpectedSkillPowerResultAdder"), &hooked_BattleActionModel_GetExpectedSkillPowerResultAdder);
    original_BattleActionModel_GetAttackDmgMultiplier = InstallHook<BattleActionModelGetAttackDmgMultiplierFn>(BAMC.GetMethod("GetAttackDmgMultiplier"), &hooked_BattleActionModel_GetAttackDmgMultiplier);
    original_BattleActionModel_GetExpectedAttackDmgMultiplier = InstallHook<BattleActionModelGetExpectedAttackDmgMultiplierFn>(BAMC.GetMethod("GetExpectedAttackDmgMultiplier"), &hooked_BattleActionModel_GetExpectedAttackDmgMultiplier);
    original_BattleActionModel_GetAttackDmgAdder = InstallHook<BattleActionModelGetAttackDmgAdderFn>(BAMC.GetMethod("GetAttackDmgAdder"), &hooked_BattleActionModel_GetAttackDmgAdder);
    original_BattleActionModel_GetExpectedAttackDmgAdder = InstallHook<BattleActionModelGetExpectedAttackDmgAdderFn>(BAMC.GetMethod("GetExpectedAttackDmgAdder"), &hooked_BattleActionModel_GetExpectedAttackDmgAdder);
    original_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg = InstallHook<BattleActionModelGetOppoSkillPowerResultAdderOnTakeAtkDmgFn>(BAMC.GetMethod("GetOppoSkillPowerResultAdderOnTakeAtkDmg"), &hooked_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg);
    original_BattleActionModel_BothCanDuelAndAttackSkill = InstallHook<BattleActionModelBothCanDuelAndAttackSkillFn>(BAMC.GetMethod("BothCanDuelAndAttackSkill"), &hooked_BattleActionModel_BothCanDuelAndAttackSkill);
    original_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill = InstallHook<BattleActionModelBothCanDuelAndAtLeastOneAttackSkillFn>(BAMC.GetMethod("BothCanDuelAndAtLeastOneAttackSkill"), &hooked_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill);
    original_BattleActionModel_CanDuelBoth = InstallHook<BattleActionModelCanDuelBothFn>(BAMC.GetMethod("CanDuelBoth"), &hooked_BattleActionModel_CanDuelBoth);
    original_BattleActionModel_CanDuel = InstallHook<BattleActionModelCanDuelFn>(BAMC.GetMethod("CanDuel"), &hooked_BattleActionModel_CanDuel);
    original_BattleActionModel_CanDuelWithoutCheckNull = InstallHook<BattleActionModelCanDuelWithoutCheckNullFn>(BAMC.GetMethod("CanDuelWithoutCheckNull"), &hooked_BattleActionModel_CanDuelWithoutCheckNull);
    original_BattleActionModel_IsPanicBlock = InstallHook<BattleActionModelIsPanicBlockFn>(BAMC.GetMethod("IsPanicBlock"), &hooked_BattleActionModel_IsPanicBlock);
    original_BattleActionModel_GetDescArgs_P2 = InstallHook<BattleActionModelGetDescArgs_P2Fn>(BAMC.GetMethod("GetDescArgs_P2"), &hooked_BattleActionModel_GetDescArgs_P2);
    original_BattleActionModel_GetDescArgs_P1 = InstallHook<BattleActionModelGetDescArgs_P1Fn>(BAMC.GetMethod("GetDescArgs_P1"), &hooked_BattleActionModel_GetDescArgs_P1);
    original_BattleActionModel_IsAllCoinHead = InstallHook<BattleActionModelIsAllCoinHeadFn>(BAMC.GetMethod("IsAllCoinHead"), &hooked_BattleActionModel_IsAllCoinHead);
    original_BattleActionModel_IsAllCoinHit = InstallHook<BattleActionModelIsAllCoinHitFn>(BAMC.GetMethod("IsAllCoinHit"), &hooked_BattleActionModel_IsAllCoinHit);
    original_BattleActionModel_GetHeadCoinNum = InstallHook<BattleActionModelGetHeadCoinNumFn>(BAMC.GetMethod("GetHeadCoinNum"), &hooked_BattleActionModel_GetHeadCoinNum);
    original_BattleActionModel_GetTailCoinNum = InstallHook<BattleActionModelGetTailCoinNumFn>(BAMC.GetMethod("GetTailCoinNum"), &hooked_BattleActionModel_GetTailCoinNum);
    original_BattleActionModel_GetUsableInDuelCoinNum = InstallHook<BattleActionModelGetUsableInDuelCoinNumFn>(BAMC.GetMethod("GetUsableInDuelCoinNum"), &hooked_BattleActionModel_GetUsableInDuelCoinNum);
    original_BattleActionModel_IsFirstCoin = InstallHook<BattleActionModelIsFirstCoinFn>(BAMC.GetMethod("IsFirstCoin"), &hooked_BattleActionModel_IsFirstCoin);
    original_BattleActionModel_IsLastCoin = InstallHook<BattleActionModelIsLastCoinFn>(BAMC.GetMethod("IsLastCoin"), &hooked_BattleActionModel_IsLastCoin);
    original_BattleActionModel_CheckPersonalitySkillSpecificType = InstallHook<BattleActionModelCheckPersonalitySkillSpecificTypeFn>(BAMC.GetMethod("CheckPersonalitySkillSpecificType"), &hooked_BattleActionModel_CheckPersonalitySkillSpecificType);
    original_BattleActionModel_CheckSkillGivingBuffCategory = InstallHook<BattleActionModelCheckSkillGivingBuffCategoryFn>(BAMC.GetMethod("CheckSkillGivingBuffCategory"), &hooked_BattleActionModel_CheckSkillGivingBuffCategory);
    original_BattleActionModel_CheckSkillGivingBuff = InstallHook<BattleActionModelCheckSkillGivingBuffFn>(BAMC.GetMethod("CheckSkillGivingBuff"), &hooked_BattleActionModel_CheckSkillGivingBuff);
    original_BattleActionModel_IsGainBullet = InstallHook<BattleActionModelIsGainBulletFn>(BAMC.GetMethod("IsGainBullet"), &hooked_BattleActionModel_IsGainBullet);
    original_BattleActionModel_GetCoin = InstallHook<BattleActionModelGetCoinFn>(BAMC.GetMethod("GetCoin"), &hooked_BattleActionModel_GetCoin);
    original_BattleActionModel_GetFirstCoin = InstallHook<BattleActionModelGetFirstCoinFn>(BAMC.GetMethod("GetFirstCoin"), &hooked_BattleActionModel_GetFirstCoin);
    original_BattleActionModel_GetLastCoin = InstallHook<BattleActionModelGetLastCoinFn>(BAMC.GetMethod("GetLastCoin"), &hooked_BattleActionModel_GetLastCoin);
    original_BattleActionModel_GetMpUsage = InstallHook<BattleActionModelGetMpUsageFn>(BAMC.GetMethod("GetMpUsage"), &hooked_BattleActionModel_GetMpUsage);
    original_BattleActionModel_IsMultiTarget = InstallHook<BattleActionModelIsMultiTargetFn>(BAMC.GetMethod("IsMultiTarget"), &hooked_BattleActionModel_IsMultiTarget);
    original_BattleActionModel_IsReusedAction = InstallHook<BattleActionModelIsReusedActionFn>(BAMC.GetMethod("IsReusedAction"), &hooked_BattleActionModel_IsReusedAction);
    original_BattleActionModel_BeforeAttack = InstallHook<BattleActionModelBeforeAttackFn>(BAMC.GetMethod("BeforeAttack"), &hooked_BattleActionModel_BeforeAttack);
    original_BattleActionModel_GetFinalSkillPowerResult = InstallHook<BattleActionModelGetFinalSkillPowerResultFn>(BAMC.GetMethod("GetFinalSkillPowerResult"), &hooked_BattleActionModel_GetFinalSkillPowerResult);
    original_BattleActionModel_GetParryingResultAdder = InstallHook<BattleActionModelGetParryingResultAdderFn>(BAMC.GetMethod("GetParryingResultAdder"), &hooked_BattleActionModel_GetParryingResultAdder);
    original_BattleActionModel_GetExpectedParryingResultAdder = InstallHook<BattleActionModelGetExpectedParryingResultAdderFn>(BAMC.GetMethod("GetExpectedParryingResultAdder"), &hooked_BattleActionModel_GetExpectedParryingResultAdder);
    original_BattleActionModel_GetOpponentParryingResultAdder = InstallHook<BattleActionModelGetOpponentParryingResultAdderFn>(BAMC.GetMethod("GetOpponentParryingResultAdder"), &hooked_BattleActionModel_GetOpponentParryingResultAdder);
    original_BattleActionModel_GetExpectedOpponentParryingResultAdder = InstallHook<BattleActionModelGetExpectedOpponentParryingResultAdderFn>(BAMC.GetMethod("GetExpectedOpponentParryingResultAdder"), &hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder);
    original_BattleActionModel_OverWriteSkill = InstallHook<BattleActionModelOverWriteSkillFn>(BAMC.GetMethod("OverWriteSkill"), &hooked_BattleActionModel_OverWriteSkill);
    original_BattleActionModel_IsRandomTarget = InstallHook<BattleActionModelIsRandomTargetFn>(BAMC.GetMethod("IsRandomTarget"), &hooked_BattleActionModel_IsRandomTarget);
    original_BattleActionModel_IsTargetableSlot = InstallHook<BattleActionModelIsTargetableSlotFn>(BAMC.GetMethod("IsTargetableSlot"), &hooked_BattleActionModel_IsTargetableSlot);
    original_BattleActionModel_IsSkillAbsorbingThisDamage = InstallHook<BattleActionModelIsSkillAbsorbingThisDamageFn>(BAMC.GetMethod("IsSkillAbsorbingThisDamage"), &hooked_BattleActionModel_IsSkillAbsorbingThisDamage);
    original_BattleActionModel_IsDefenseSkillForOther = InstallHook<BattleActionModelIsDefenseSkillForOtherFn>(BAMC.GetMethod("IsDefenseSkillForOther"), &hooked_BattleActionModel_IsDefenseSkillForOther);
    original_BattleActionModel_AttackByMpDmgRatherThanHpDmg = InstallHook<BattleActionModelAttackByMpDmgRatherThanHpDmgFn>(BAMC.GetMethod("AttackByMpDmgRatherThanHpDmg"), &hooked_BattleActionModel_AttackByMpDmgRatherThanHpDmg);
    original_BattleActionModel_BlockLoseBuffByReactWithAction = InstallHook<BattleActionModelBlockLoseBuffByReactWithActionFn>(BAMC.GetMethod("BlockLoseBuffByReactWithAction"), &hooked_BattleActionModel_BlockLoseBuffByReactWithAction);
    original_BattleActionModel_ChangeAttackDamage = InstallHook<BattleActionModelChangeAttackDamageFn>(BAMC.GetMethod("ChangeAttackDamage"), &hooked_BattleActionModel_ChangeAttackDamage);
    original_BattleActionModel_OnSkillChangedEgo = InstallHook<BattleActionModelOnSkillChangedEgoFn>(BAMC.GetMethod("OnSkillChangedEgo"), &hooked_BattleActionModel_OnSkillChangedEgo);
    original_BattleActionModel_OnRoundEnd = InstallHook<BattleActionModelOnRoundEndFn>(BAMC.GetMethod("OnRoundEnd"), &hooked_BattleActionModel_OnRoundEnd);
    original_BattleActionModel_OnRoundEnd_After = InstallHook<BattleActionModelOnRoundEnd_AfterFn>(BAMC.GetMethod("OnRoundEnd_After"), &hooked_BattleActionModel_OnRoundEnd_After);
    original_BattleActionModel_OnAddCoinByAbility = InstallHook<BattleActionModelOnAddCoinByAbilityFn>(BAMC.GetMethod("OnAddCoinByAbility"), &hooked_BattleActionModel_OnAddCoinByAbility);
    original_BattleActionModel_GetGiveBsGaugeUpMultiplier = InstallHook<BattleActionModelGetGiveBsGaugeUpMultiplierFn>(BAMC.GetMethod("GetGiveBsGaugeUpMultiplier"), &hooked_BattleActionModel_GetGiveBsGaugeUpMultiplier);
    original_BattleActionModel_GetGiveBsGaugeUpAdder = InstallHook<BattleActionModelGetGiveBsGaugeUpAdderFn>(BAMC.GetMethod("GetGiveBsGaugeUpAdder"), &hooked_BattleActionModel_GetGiveBsGaugeUpAdder);
    original_BattleActionModel_HasCoinOperatorType = InstallHook<BattleActionModelHasCoinOperatorTypeFn>(BAMC.GetMethod("HasCoinOperatorType"), &hooked_BattleActionModel_HasCoinOperatorType);
    original_BattleActionModel_HasSuperCoin = InstallHook<BattleActionModelHasSuperCoinFn>(BAMC.GetMethod("HasSuperCoin"), &hooked_BattleActionModel_HasSuperCoin);
    original_BattleActionModel_StackNextTurnAggroAdder = InstallHook<BattleActionModelStackNextTurnAggroAdderFn>(BAMC.GetMethod("StackNextTurnAggroAdder"), &hooked_BattleActionModel_StackNextTurnAggroAdder);
    original_BattleActionModel_OnUseStageBuffBySkill = InstallHook<BattleActionModelOnUseStageBuffBySkillFn>(BAMC.GetMethod("OnUseStageBuffBySkill"), &hooked_BattleActionModel_OnUseStageBuffBySkill);
    original_BattleActionModel_GetUsedStageBuffStack = InstallHook<BattleActionModelGetUsedStageBuffStackFn>(BAMC.GetMethod("GetUsedStageBuffStack"), &hooked_BattleActionModel_GetUsedStageBuffStack);
    original_BattleActionModel_OnUseBuffBySkill = InstallHook<BattleActionModelOnUseBuffBySkillFn>(BAMC.GetMethod("OnUseBuffBySkill"), &hooked_BattleActionModel_OnUseBuffBySkill);
    original_BattleActionModel_UsedBuffStack = InstallHook<BattleActionModelUsedBuffStackFn>(BAMC.GetMethod("UsedBuffStack"), &hooked_BattleActionModel_UsedBuffStack);
    original_BattleActionModel_UsedBuffTurn = InstallHook<BattleActionModelUsedBuffTurnFn>(BAMC.GetMethod("UsedBuffTurn"), &hooked_BattleActionModel_UsedBuffTurn);
    original_BattleActionModel_GetUsedBuffStack = InstallHook<BattleActionModelGetUsedBuffStackFn>(BAMC.GetMethod("GetUsedBuffStack"), &hooked_BattleActionModel_GetUsedBuffStack);
    original_BattleActionModel_GetUsedBuffTurn = InstallHook<BattleActionModelGetUsedBuffTurnFn>(BAMC.GetMethod("GetUsedBuffTurn"), &hooked_BattleActionModel_GetUsedBuffTurn);
    original_BattleActionModel_OverwriteCoinProb = InstallHook<BattleActionModelOverwriteCoinProbFn>(BAMC.GetMethod("OverwriteCoinProb"), &hooked_BattleActionModel_OverwriteCoinProb);
    original_BattleActionModel_OverwriteCriticalResult = InstallHook<BattleActionModelOverwriteCriticalResultFn>(BAMC.GetMethod("OverwriteCriticalResult"), &hooked_BattleActionModel_OverwriteCriticalResult);
    original_BattleActionModel_IgnoreCheckCritical = InstallHook<BattleActionModelIgnoreCheckCriticalFn>(BAMC.GetMethod("IgnoreCheckCritical"), &hooked_BattleActionModel_IgnoreCheckCritical);
    original_BattleActionModel_CanDealTarget = InstallHook<BattleActionModelCanDealTargetFn>(BAMC.GetMethod("CanDealTarget"), &hooked_BattleActionModel_CanDealTarget);
    original_BattleActionModel_BlockGivingBuff = InstallHook<BattleActionModelBlockGivingBuffFn>(BAMC.GetMethod("BlockGivingBuff"), &hooked_BattleActionModel_BlockGivingBuff);
    original_BattleActionModel_ExpectedBlockGivingBuff = InstallHook<BattleActionModelExpectedBlockGivingBuffFn>(BAMC.GetMethod("ExpectedBlockGivingBuff"), &hooked_BattleActionModel_ExpectedBlockGivingBuff);
    original_BattleActionModel_RightBeforeGiveBuffBySkill = InstallHook<BattleActionModelRightBeforeGiveBuffBySkillFn>(BAMC.GetMethod("RightBeforeGiveBuffBySkill"), &hooked_BattleActionModel_RightBeforeGiveBuffBySkill);
    original_BattleActionModel_RightAfterGiveBuffBySkill = InstallHook<BattleActionModelRightAfterGiveBuffBySkillFn>(BAMC.GetMethod("RightAfterGiveBuffBySkill"), &hooked_BattleActionModel_RightAfterGiveBuffBySkill);
    original_BattleActionModel_IsReusable = InstallHook<BattleActionModelIsReusableFn>(BAMC.GetMethod("IsReusable"), &hooked_BattleActionModel_IsReusable);
    original_BattleActionModel_IsSupportSkill = InstallHook<BattleActionModelIsSupportSkillFn>(BAMC.GetMethod("IsSupportSkill"), &hooked_BattleActionModel_IsSupportSkill);
    original_BattleActionModel_IsChangeable = InstallHook<BattleActionModelIsChangeableFn>(BAMC.GetMethod("IsChangeable"), &hooked_BattleActionModel_IsChangeable);
    original_BattleActionModel_OnOrderCutInAction = InstallHook<BattleActionModelOnOrderCutInActionFn>(BAMC.GetMethod("OnOrderCutInAction"), &hooked_BattleActionModel_OnOrderCutInAction);
    original_BattleActionModel_AddTemporarySkillAbilityToSkill = InstallHook<BattleActionModelAddTemporarySkillAbilityToSkillFn>(BAMC.GetMethod("AddTemporarySkillAbilityToSkill"), &hooked_BattleActionModel_AddTemporarySkillAbilityToSkill);
    original_BattleActionModel_RemoveAllSpecificSkillAbility = InstallHook<BattleActionModelRemoveAllSpecificSkillAbilityFn>(BAMC.GetMethod("RemoveAllSpecificSkillAbility"), &hooked_BattleActionModel_RemoveAllSpecificSkillAbility);
    original_BattleActionModel_AddCoinIgnoredTiming = InstallHook<BattleActionModelAddCoinIgnoredTimingFn>(BAMC.GetMethod("AddCoinIgnoredTiming"), &hooked_BattleActionModel_AddCoinIgnoredTiming);
    original_BattleActionModel_IsBlockingTargetBurstBuffEffectReact = InstallHook<BattleActionModelIsBlockingTargetBurstBuffEffectReactFn>(BAMC.GetMethod("IsBlockingTargetBurstBuffEffectReact"), &hooked_BattleActionModel_IsBlockingTargetBurstBuffEffectReact);
    original_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact = InstallHook<BattleActionModelIsBlockingTargetSinkingBuffEffectReactFn>(BAMC.GetMethod("IsBlockingTargetSinkingBuffEffectReact"), &hooked_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact);
    original_BattleActionModel_OverwriteParryingResult = InstallHook<BattleActionModelOverwriteParryingResultFn>(BAMC.GetMethod("OverwriteParryingResult"), &hooked_BattleActionModel_OverwriteParryingResult);
    original_BattleActionModel_TryGetForcedCoinResult = InstallHook<BattleActionModelTryGetForcedCoinResultFn>(BAMC.GetMethod("TryGetForcedCoinResult"), &hooked_BattleActionModel_TryGetForcedCoinResult);
    original_BattleActionModel_GetForcedCoinResult = InstallHook<BattleActionModelGetForcedCoinResultFn>(BAMC.GetMethod("GetForcedCoinResult"), &hooked_BattleActionModel_GetForcedCoinResult);
    original_BattleActionModel_AddAbilityThisRound = InstallHook<BattleActionModelAddAbilityThisRoundFn>(BAMC.GetMethod("AddAbilityThisRound"), &hooked_BattleActionModel_AddAbilityThisRound);
    original_BattleActionModel_AddAbilityNextRound = InstallHook<BattleActionModelAddAbilityNextRoundFn>(BAMC.GetMethod("AddAbilityNextRound"), &hooked_BattleActionModel_AddAbilityNextRound);
    original_BattleActionModel_HasSystemAbility = InstallHook<BattleActionModelHasSystemAbilityFn>(BAMC.GetMethod("HasSystemAbility"), &hooked_BattleActionModel_HasSystemAbility);
    original_BattleActionModel_GetSystemAbility = InstallHook<BattleActionModelGetSystemAbilityFn>(BAMC.GetMethod("GetSystemAbility"), &hooked_BattleActionModel_GetSystemAbility);
    original_BattleActionModel_DestroySystemAbility = InstallHook<BattleActionModelDestroySystemAbilityFn>(BAMC.GetMethod("DestroySystemAbility"), &hooked_BattleActionModel_DestroySystemAbility);
    original_BattleActionModel_MarkAsExtracted = InstallHook<BattleActionModelMarkAsExtractedFn>(BAMC.GetMethod("MarkAsExtracted"), &hooked_BattleActionModel_MarkAsExtracted);
    original_BattleActionModel_OnAddBattleAction = InstallHook<BattleActionModelOnAddBattleActionFn>(BAMC.GetMethod("OnAddBattleAction"), &hooked_BattleActionModel_OnAddBattleAction);
    original_BattleActionModel_OnRemoveBattleAction = InstallHook<BattleActionModelOnRemoveBattleActionFn>(BAMC.GetMethod("OnRemoveBattleAction"), &hooked_BattleActionModel_OnRemoveBattleAction);
    original_BattleActionModel_OnSetExpectedTarget = InstallHook<BattleActionModelOnSetExpectedTargetFn>(BAMC.GetMethod("OnSetExpectedTarget"), &hooked_BattleActionModel_OnSetExpectedTarget);
    original_BattleActionModel_IsRunUniqueAction = InstallHook<BattleActionModelIsRunUniqueActionFn>(BAMC.GetMethod("IsRunUniqueAction"), &hooked_BattleActionModel_IsRunUniqueAction);
    original_BattleActionModel_IsEgoSkill = InstallHook<BattleActionModelIsEgoSkillFn>(BAMC.GetMethod("IsEgoSkill"), &hooked_BattleActionModel_IsEgoSkill);
    original_BattleActionModel_HasEgoKeyword = InstallHook<BattleActionModelHasEgoKeywordFn>(BAMC.GetMethod("HasEgoKeyword"), &hooked_BattleActionModel_HasEgoKeyword);
}

} // myosotis::testmod
