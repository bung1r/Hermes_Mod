#pragma once
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

class BattleActionModel {
public:
    virtual ~BattleActionModel() = default;

    // OBJs mean the actual object inside Unity. 
    il2cpp::Il2CppObject* battleActionModelObj = nullptr;
    il2cpp::Il2CppObject* coinModelListObj = nullptr;
    std::vector<il2cpp::Il2CppObject*> coinModelObjs = {}; 
    
    // std::vector<CoinModel> coinModels = {};

    // C#: UnitSinModel get_Sin()
    virtual il2cpp::Il2CppObject* get_Sin(il2cpp::Il2CppObject* returnValue);

    // C#: BattleUnitModel get_Model()
    virtual il2cpp::Il2CppObject* get_Model(il2cpp::Il2CppObject* returnValue);

    // C#: SkillModel get_Skill()
    virtual il2cpp::Il2CppObject* get_Skill(il2cpp::Il2CppObject* returnValue);

    // C#: System.Boolean get_IsDone()
    virtual bool get_IsDone(bool returnValue);

    // C#: System.Boolean get_isDoneWithAction()
    virtual bool get_isDoneWithAction(bool returnValue);

    // C#: System.Int32 get_skillPowerResultValue()
    virtual int32_t get_skillPowerResultValue(int32_t returnValue);

    // C#: System.Int32 get_ReusedTimes()
    virtual int32_t get_ReusedTimes(int32_t returnValue);

    // C#: SinActionModel get_SinAction()
    virtual il2cpp::Il2CppObject* get_SinAction(il2cpp::Il2CppObject* returnValue);

    // C#: System.Int32 get_ActionInstanceID()
    virtual int32_t get_ActionInstanceID(int32_t returnValue);

    // C#: System.Int32 get_CommanderInstanceID()
    virtual int32_t get_CommanderInstanceID(int32_t returnValue);

    // C#: System.Int32 get_OrderedActionInstanceId()
    virtual int32_t get_OrderedActionInstanceId(int32_t returnValue);

    // C#: System.Int32 get_OrderedActionActorInstanceId()
    virtual int32_t get_OrderedActionActorInstanceId(int32_t returnValue);

    // C#: System.Boolean get_IsExtracted()
    virtual bool get_IsExtracted(bool returnValue);

    // C#: BattleUnitModel get_Commander()
    virtual il2cpp::Il2CppObject* get_Commander(il2cpp::Il2CppObject* returnValue);

    // C#: ABILITY_SOURCE_TYPE get_OrderSourceType()
    virtual int32_t get_OrderSourceType(int32_t returnValue);

    // C#: System.Void SetTargetDetailType(BattleUnitModel model, System.Boolean isReuseAction)
    virtual void SetTargetDetailType(il2cpp::Il2CppObject* model, bool isReuseAction);

    // C#: System.Void InitCoins()
    virtual void InitCoins();

    // C#: System.Void InitCoinResults()
    virtual void InitCoinResults();

    // C#: System.Void InitStaticData()
    virtual void InitStaticData();

    // C#: System.Boolean IsActivatedSupportiveProtectByThisAction()
    virtual bool IsActivatedSupportiveProtectByThisAction(bool returnValue);

    // C#: System.Void CheckActivationOfSupportiveProtect()
    virtual void CheckActivationOfSupportiveProtect();

    // C#: System.Boolean IsSupportiveDefense_Old()
    virtual bool IsSupportiveDefense_Old(bool returnValue);

    // C#: System.Boolean IsSupportiveDefense()
    virtual bool IsSupportiveDefense(bool returnValue);

    // C#: System.Void RemoveTargetData(System.Boolean returnPrevTarget)
    virtual void RemoveTargetData(bool returnPrevTarget);

    // C#: System.Collections.Generic.List<SinActionModel> GetOriginTargetSinActionsData(System.Boolean isOverlap)
    virtual il2cpp::Il2CppObject* GetOriginTargetSinActionsData(il2cpp::Il2CppObject* returnValue, bool isOverlap);

    // C#: BattleUnitModel GetOriginMainTarget()
    virtual il2cpp::Il2CppObject* GetOriginMainTarget(il2cpp::Il2CppObject* returnValue);

    // C#: System.Boolean HasOriginTarget()
    virtual bool HasOriginTarget(bool returnValue);

    // C#: System.Boolean HasMainTarget()
    virtual bool HasMainTarget(bool returnValue);

    // C#: System.Boolean HasSubTarget()
    virtual bool HasSubTarget(bool returnValue);

    // C#: SinActionModel GetMainTargetSinAction()
    virtual il2cpp::Il2CppObject* GetMainTargetSinAction(il2cpp::Il2CppObject* returnValue);

    // C#: System.Collections.Generic.List<SinActionModel> GetSubTargetSinActionList()
    virtual il2cpp::Il2CppObject* GetSubTargetSinActionList(il2cpp::Il2CppObject* returnValue);

    // C#: System.Collections.Generic.List<SinActionModel> GetTargetSinActionList()
    virtual il2cpp::Il2CppObject* GetTargetSinActionList(il2cpp::Il2CppObject* returnValue);

    // C#: BattleUnitModel GetMainTarget()
    virtual il2cpp::Il2CppObject* GetMainTarget(il2cpp::Il2CppObject* returnValue);

    // C#: System.Collections.Generic.List<BattleUnitModel> GetTargetUnitModelList()
    virtual il2cpp::Il2CppObject* GetTargetUnitModelList(il2cpp::Il2CppObject* returnValue);

    // C#: System.Collections.Generic.List<BattleUnitModel> GetAliveTargetUnitModelList()
    virtual il2cpp::Il2CppObject* GetAliveTargetUnitModelList(il2cpp::Il2CppObject* returnValue);

    // C#: System.Void SetOriginTargetSinActions(System.Collections.Generic.List<SinActionModel> originTargetSinActions)
    virtual void SetOriginTargetSinActions(il2cpp::Il2CppObject* originTargetSinActions);

    // C#: System.Void ReadyOriginTargeting()
    virtual void ReadyOriginTargeting();

    // C#: System.Void AddTarget(SinActionModel targetSinAction)
    virtual void AddTarget(il2cpp::Il2CppObject* targetSinAction);

    // C#: System.Void SetTargetAfterBattleStart(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
    virtual void SetTargetAfterBattleStart(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

    // C#: System.Void RedirectTarget(System.Boolean mainTargetAlive)
    virtual void RedirectTarget(bool mainTargetAlive);

    // C#: System.Void SetTargetAuto(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
    virtual void SetTargetAuto(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

    // C#: System.Void SetTargetBySortedTargetableSinActionList(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
    virtual void SetTargetBySortedTargetableSinActionList(bool canDuel, bool attackEnemyOnly, int32_t targetType);

    // C#: System.Void SetTargetAfterBattleStart_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
    virtual void SetTargetAfterBattleStart_CutIn(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

    // C#: System.Void SetTargetAuto_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
    virtual void SetTargetAuto_CutIn(bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

    // C#: System.Void SetTargetBySortedTargetableSinActionList_CutIn(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
    virtual void SetTargetBySortedTargetableSinActionList_CutIn(bool canDuel, bool attackEnemyOnly, int32_t targetType);

    // C#: System.Void RemoveOneTargetSet(BattleActionModel otherAction)
    virtual void RemoveOneTargetSet(il2cpp::Il2CppObject* otherAction);

    // C#: System.Boolean CanDuelWithSameFaction()
    virtual bool CanDuelWithSameFaction(bool returnValue);

    // C#: System.Void SetTarget(System.Collections.Generic.List<SinActionModel> sortedTargetSinActions, System.Boolean canDuel)
    virtual void SetTarget(il2cpp::Il2CppObject* sortedTargetSinActions, bool canDuel);

    // C#: System.Void RecheckTargetList()
    virtual void RecheckTargetList();

    // C#: System.Void AfterRecheckTargetList(System.Boolean valid, System.Boolean mainTargetAlive)
    virtual void AfterRecheckTargetList(bool valid, bool mainTargetAlive);

    // C#: System.Void ChangeAllTargetOnCompleteCommand(System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
    virtual void ChangeAllTargetOnCompleteCommand(bool attackEnemyOnly, int32_t overwritedTargetType);

    // C#: System.Void ChangeMainTargetSinAction(SinActionModel changeTargetSinAction, BattleActionModel oppositeAction, System.Boolean forcely)
    virtual void ChangeMainTargetSinAction(il2cpp::Il2CppObject* changeTargetSinAction, il2cpp::Il2CppObject* oppositeAction, bool forcely);

    // C#: System.Boolean HasBeenChangedCurrentTargetBy(BattleActionModel oppositeAction)
    virtual bool HasBeenChangedCurrentTargetBy(bool returnValue, il2cpp::Il2CppObject* oppositeAction);

    // C#: System.Void ChangeAllSubTarget()
    virtual void ChangeAllSubTarget();

    // C#: System.Void RecheckSubTargetWhenChangeTargetNum(System.Nullable<System.Boolean> overwriteAttackEnemyOnly, SKILL_TARGET_TYPE overwriteTargetType)
    virtual void RecheckSubTargetWhenChangeTargetNum(il2cpp::Il2CppObject* overwriteAttackEnemyOnly, int32_t overwriteTargetType);

    // C#: System.Void RemoveAllTargetExceptMainTarget()
    virtual void RemoveAllTargetExceptMainTarget();

    // C#: System.Void RemoveUntargetableTarget()
    virtual void RemoveUntargetableTarget();

    // C#: System.Int32 GetCurrentOccupiedWeight()
    virtual int32_t GetCurrentOccupiedWeight_P0(int32_t returnValue);

    // C#: System.Int32 GetCurrentOccupiedWeight(SinActionModel targetSinAction)
    virtual int32_t GetCurrentOccupiedWeight_P1(int32_t returnValue, il2cpp::Il2CppObject* targetSinAction);

    // C#: System.Void AddPrimeTargets(System.Boolean canDuel)
    virtual void AddPrimeTargets(bool canDuel);

    // C#: System.Boolean GetPrimeTargetSinActions(System.Collections.Generic.List<TargetSinActionData>& primeTargetSinActions, System.Int32& remainedSlotNum)
    virtual bool GetPrimeTargetSinActions(bool returnValue, il2cpp::Il2CppObject** primeTargetSinActions, int32_t* remainedSlotNum);

    // C#: System.Collections.Generic.List<SinActionModel> GetSatisfiedPrimeTargetSinActions()
    virtual il2cpp::Il2CppObject* GetSatisfiedPrimeTargetSinActions(il2cpp::Il2CppObject* returnValue);

    // C#: System.Collections.Generic.List<SinActionModel> ExtractSortedPrimeTargetSinActionList(System.Collections.Generic.List<PrimeTargetData> primeTargetDatas)
    virtual il2cpp::Il2CppObject* ExtractSortedPrimeTargetSinActionList(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* primeTargetDatas);

    // C#: System.Collections.Generic.List<SinActionModel> GetCollapsedTargetableSinActionList(System.Collections.Generic.List<SinActionModel> addedTargetSinActions, System.Nullable<System.Boolean> attackEnemyOnly, SKILL_TARGET_TYPE targetType, System.Boolean canAttackAllyAssist)
    virtual il2cpp::Il2CppObject* GetCollapsedTargetableSinActionList(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* addedTargetSinActions, il2cpp::Il2CppObject* attackEnemyOnly, int32_t targetType, bool canAttackAllyAssist);

    // C#: System.Void SortSinActionList(System.Collections.Generic.List<SinActionModel> list, SKILL_TARGET_TYPE targetType)
    virtual void SortSinActionList(il2cpp::Il2CppObject* list, int32_t targetType);

    // C#: System.Collections.Generic.List<BattleUnitModel> GetTargetableUnitList(System.Boolean canAttackAllyAssist)
    virtual il2cpp::Il2CppObject* GetTargetableUnitList(il2cpp::Il2CppObject* returnValue, bool canAttackAllyAssist);

    // C#: System.Void SortTargetSlots(System.Collections.Generic.List<SinActionModel> targetSinActions, SKILL_TARGET_TYPE targetType)
    virtual void SortTargetSlots(il2cpp::Il2CppObject* targetSinActions, int32_t targetType);

    // C#: System.Single GetExpectedEgoErodeRate(BattleEgoModel egoModel)
    virtual float GetExpectedEgoErodeRate(float returnValue, il2cpp::Il2CppObject* egoModel);

    // C#: System.Boolean IsConsumeBuffSkill(BUFF_UNIQUE_KEYWORD buff)
    virtual bool IsConsumeBuffSkill(bool returnValue, int32_t buff);

    // C#: System.Boolean IsConsumeBullet()
    virtual bool IsConsumeBullet(bool returnValue);

    // C#: System.Boolean IsUseBuff(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
    virtual bool IsUseBuff(bool returnValue, int32_t buff, int32_t targetType);

    // C#: System.Boolean IsUseBuffStack(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
    virtual bool IsUseBuffStack(bool returnValue, int32_t buff, int32_t targetType);

    // C#: System.Boolean IsUseBuffTurn(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
    virtual bool IsUseBuffTurn(bool returnValue, int32_t buff, int32_t targetType);

    // C#: System.Boolean IsAddBloodDinner()
    virtual bool IsAddBloodDinner(bool returnValue);

    // C#: PairWithTargetUnitSinSet GetExpectedAllCalculationOnlyAbnormalityBattle()
    virtual il2cpp::Il2CppObject* GetExpectedAllCalculationOnlyAbnormalityBattle(il2cpp::Il2CppObject* returnValue);

    // C#: System.Void MakeReusable()
    virtual void MakeReusable();

    // C#: System.Void ResetAllTargetData()
    virtual void ResetAllTargetData();

    // C#: System.Void ResetCoinState()
    virtual void ResetCoinState();

    // C#: System.Void ResetDataWIthOutTargetData()
    virtual void ResetDataWIthOutTargetData();

    // C#: System.Void AddAttackedTarget(BattleUnitModel target)
    virtual void AddAttackedTarget(il2cpp::Il2CppObject* target);

    // C#: System.Collections.Generic.List<BattleUnitModel> GetAttackedTargetList()
    virtual il2cpp::Il2CppObject* GetAttackedTargetList(il2cpp::Il2CppObject* returnValue);

    // C#: System.Void CheckCoinDestroy(BattleActionModel winnerAction)
    virtual void CheckCoinDestroy(il2cpp::Il2CppObject* winnerAction);

    // C#: CoinModel GetHighestCoin()
    virtual il2cpp::Il2CppObject* GetHighestCoin(il2cpp::Il2CppObject* returnValue);

    // C#: CoinModel GetDestroyTargetCoin()
    virtual il2cpp::Il2CppObject* GetDestroyTargetCoin(il2cpp::Il2CppObject* returnValue);

    // C#: System.Int32 GetSkillID()
    virtual int32_t GetSkillID(int32_t returnValue);

    // C#: SKILL_TARGET_TYPE GetSkillTargetType()
    virtual int32_t GetSkillTargetType(int32_t returnValue);

    // C#: System.Int32 GetAttackWeight()
    virtual int32_t GetAttackWeight(int32_t returnValue);

    // C#: System.Int32 GetOriginAttackWeight()
    virtual int32_t GetOriginAttackWeight(int32_t returnValue);

    // C#: DEFENSE_TYPE GetDefenseType()
    virtual int32_t GetDefenseType(int32_t returnValue);

    // C#: ATK_BEHAVIOUR GetSkillAtkType()
    virtual int32_t GetSkillAtkType(int32_t returnValue);

    // C#: System.Boolean TryGetOverwriteAtkBehaviour(CoinModel coin, ATK_BEHAVIOUR& atkBehaviour)
    virtual bool TryGetOverwriteAtkBehaviour(bool returnValue, il2cpp::Il2CppObject* coin, int32_t* atkBehaviour);

    // C#: System.Boolean IsSkillAtkType(ATK_BEHAVIOUR type)
    virtual bool IsSkillAtkType(bool returnValue, int32_t type);

    // C#: ATTRIBUTE_TYPE GetSkillAttributeType()
    virtual int32_t GetSkillAttributeType(int32_t returnValue);

    // C#: System.Boolean IsSkillAttributeType(ATTRIBUTE_TYPE type)
    virtual bool IsSkillAttributeType(bool returnValue, int32_t type);

    // C#: System.Boolean IsAttack()
    virtual bool IsAttack(bool returnValue);

    // C#: System.Boolean IsDefense()
    virtual bool IsDefense(bool returnValue);

    // C#: System.Boolean IsDefenseNotCounter()
    virtual bool IsDefenseNotCounter(bool returnValue);

    // C#: System.Boolean IsGuard()
    virtual bool IsGuard(bool returnValue);

    // C#: System.Boolean IsCounter()
    virtual bool IsCounter(bool returnValue);

    // C#: System.Boolean IsCanDuelDefense()
    virtual bool IsCanDuelDefense(bool returnValue);

    // C#: System.Boolean IsEvade()
    virtual bool IsEvade(bool returnValue);

    // C#: System.Boolean IgnoreDefenseSkill(BattleUnitModel target)
    virtual bool IgnoreDefenseSkill(bool returnValue, il2cpp::Il2CppObject* target);

    // C#: System.Boolean IgnoreSupportiveDefense(BattleUnitModel originTarget, BattleUnitModel supportiveDefender)
    virtual bool IgnoreSupportiveDefense(bool returnValue, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* supportiveDefender);

    // C#: System.Boolean IsActionable()
    virtual bool IsActionable(bool returnValue);

    // C#: System.Void OnAttackCanceledByAbility(BATTLE_EVENT_TIMING timing)
    virtual void OnAttackCanceledByAbility(int32_t timing);

    // C#: System.Boolean CanBeChangedTarget(BattleActionModel oppoAction)
    virtual bool CanBeChangedTarget(bool returnValue, il2cpp::Il2CppObject* oppoAction);

    // C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleActionModel otherAction)
    virtual bool CanChangeMainTargetRegardlessSpeed(bool returnValue, il2cpp::Il2CppObject* otherAction);

    // C#: System.Boolean CanBeChangedTargetIgnoreSpeed(BattleActionModel otherAction)
    virtual bool CanBeChangedTargetIgnoreSpeed(bool returnValue, il2cpp::Il2CppObject* otherAction);

    // C#: System.Void ChangeEgoSkill(System.Boolean isOverClock)
    virtual void ChangeEgoSkill(bool isOverClock);

    // C#: System.Boolean TryChangeSkill(System.Int32 skillID)
    virtual bool TryChangeSkill(bool returnValue, int32_t skillID);

    // C#: System.Boolean ChangeSkill(SkillModel skill, System.Boolean saveOriginSkill)
    virtual bool ChangeSkill(bool returnValue, il2cpp::Il2CppObject* skill, bool saveOriginSkill);

    // C#: System.Void ReturnPreviousSkill()
    virtual void ReturnPreviousSkill();

    // C#: System.Int32 GetResonanceIndexOrStack()
    virtual int32_t GetResonanceIndexOrStack(int32_t returnValue);

    // C#: System.Int32 GetExpectedResonanceIndexOrStack()
    virtual int32_t GetExpectedResonanceIndexOrStack_P0(int32_t returnValue);

    // C#: System.Int32 GetExpectedResonanceIndexOrStack(System.Collections.Generic.List<System.Int32> indexes)
    virtual int32_t GetExpectedResonanceIndexOrStack_P1(int32_t returnValue, il2cpp::Il2CppObject* indexes);

    // C#: System.Int32 GetAttributeResonanceIndex()
    virtual int32_t GetAttributeResonanceIndex(int32_t returnValue);

    // C#: System.Int32 GetPerfectResonanceStack()
    virtual int32_t GetPerfectResonanceStack(int32_t returnValue);

    // C#: System.Void CheckResonancePassive()
    virtual void CheckResonancePassive();

    // C#: System.Void OnAttributeResonance()
    virtual void OnAttributeResonance();

    // C#: System.Boolean HasCommander(System.Int32& commander)
    virtual bool HasCommander(bool returnValue, int32_t* commander);

    // C#: System.Void SetDefenseLevel_After_UseSkill()
    virtual void SetDefenseLevel_After_UseSkill();

    // C#: System.Void ModifySpeedByParrying(System.Int32 speed)
    virtual void ModifySpeedByParrying(int32_t speed);

    // C#: System.Void ResetSpeedByParrying()
    virtual void ResetSpeedByParrying();

    // C#: System.Int32 RollSkillPower(CoinModel coin, OneCoinLog oneCoinLog, System.Int32 idx, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, System.Nullable<System.Boolean> isWinDuel, System.Boolean calculateSystemAdder)
    virtual int32_t RollSkillPower(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oneCoinLog, int32_t idx, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* isWinDuel, bool calculateSystemAdder);

    // C#: ParryingData RollSkillPowerParrying(BattleActionModel oppoAction, BattleLog_Parrying parryingLog, ParryingStatus parryingStatus)
    virtual il2cpp::Il2CppObject* RollSkillPowerParrying(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* parryingLog, il2cpp::Il2CppObject* parryingStatus);

    // C#: SkillPowerData CreateSkillPowerData(System.Boolean isValid, BATTLE_EVENT_TIMING timing, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, CoinModel coinOrNull)
    virtual il2cpp::Il2CppObject* CreateSkillPowerData(il2cpp::Il2CppObject* returnValue, bool isValid, int32_t timing, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* coinOrNull);

    // C#: ParryingData CreateParryingData(System.Boolean isValid)
    virtual il2cpp::Il2CppObject* CreateParryingData(il2cpp::Il2CppObject* returnValue, bool isValid);

    // C#: System.Boolean CanRollAllCoinForUI(System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs)
    virtual bool CanRollAllCoinForUI(bool returnValue, il2cpp::Il2CppObject** lackOfBuffs);

    // C#: System.Boolean IsRetreatSkill()
    virtual bool IsRetreatSkill(bool returnValue);

    // C#: System.Boolean IsCommandRetreatSkill()
    virtual bool IsCommandRetreatSkill(bool returnValue);

    // C#: System.Boolean CanRollCoin(CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs, System.Boolean& forceToEndSkill)
    virtual bool CanRollCoin(bool returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** lackOfBuffs, bool* forceToEndSkill);

    // C#: System.Void Behave(BattleRunLog runLog, BattleLog actionLog, BattleActionModel attackerActionOrNull, System.Boolean isLoserAttackExpected, BattleActionModel loserActionOrNull)
    virtual void Behave(il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull, bool isLoserAttackExpected, il2cpp::Il2CppObject* loserActionOrNull);

    // C#: System.Boolean BeforeCompleteCommand(BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
    virtual bool BeforeCompleteCommand(bool returnValue, int32_t timing, int32_t* newSkillID);

    // C#: System.Void OnChangeSkillBeforeCompleteCommand(BATTLE_EVENT_TIMING timing)
    virtual void OnChangeSkillBeforeCompleteCommand(int32_t timing);

    // C#: System.Void ActivateGuard(BattleRunLog runLog, BattleLog_Guard actionLog, BattleActionModel attackerActionOrNull)
    virtual void ActivateGuard(il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Void CheckOneOnOneDuelState()
    virtual void CheckOneOnOneDuelState();

    // C#: System.Boolean IsOneOnOneDuel(BattleActionModel opponentAction)
    virtual bool IsOneOnOneDuel(bool returnValue, il2cpp::Il2CppObject* opponentAction);

    // C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
    virtual void OnCompleteCommand(int32_t timing);

    // C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
    virtual void OnBattleStart(int32_t timing);

    // C#: System.Boolean CanAttackTargets()
    virtual bool CanAttackTargets(bool returnValue);

    // C#: System.Boolean CheckTargetableTarget()
    virtual bool CheckTargetableTarget(bool returnValue);

    // C#: System.Void OnEndBehave_Refresh(BATTLE_EVENT_TIMING timing)
    virtual void OnEndBehave_Refresh(int32_t timing);

    // C#: System.Void AffectToReturnUnit(System.Collections.Generic.List<OnReleaseStandByOrOnReturnData> list)
    virtual void AffectToReturnUnit(il2cpp::Il2CppObject* list);

    // C#: System.Void CallTargetDefenseActionsByAttack(BattleRunLog runLog, DEFENSE_TYPE type, System.Boolean isDuelExpected, System.Boolean canDuel, BATTLE_EVENT_TIMING timing, OneCoinLog_Attack oneCoinLog, BattleUnitModel specificTarget, System.Boolean mainTargetExclusive)
    virtual void CallTargetDefenseActionsByAttack(il2cpp::Il2CppObject* runLog, int32_t type, bool isDuelExpected, bool canDuel, int32_t timing, il2cpp::Il2CppObject* oneCoinLog, il2cpp::Il2CppObject* specificTarget, bool mainTargetExclusive);

    // C#: System.Void OnRoundStart_After()
    virtual void OnRoundStart_After();

    // C#: System.Void OnBeforeTurn(BATTLE_EVENT_TIMING timing)
    virtual void OnBeforeTurn(int32_t timing);

    // C#: System.Void OnCancelAction()
    virtual void OnCancelAction();

    // C#: System.Void OnBeforeDefense(BattleActionModel attackerActionOrNull)
    virtual void OnBeforeDefense(il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Void OnStartTurn_BeforeLog(BATTLE_EVENT_TIMING timing, System.Boolean isDuelExpected)
    virtual void OnStartTurn_BeforeLog(int32_t timing, bool isDuelExpected);

    // C#: System.Void OnStartTurn_AfterLog(BATTLE_EVENT_TIMING timing)
    virtual void OnStartTurn_AfterLog(int32_t timing);

    // C#: System.Void OnTryEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
    virtual void OnTryEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing);

    // C#: System.Void OnStartDuel(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
    virtual void OnStartDuel(il2cpp::Il2CppObject* opponentAction, int32_t timing);

    // C#: System.Void OnBeforeParryingOnce(BattleActionModel oppoAction)
    virtual void OnBeforeParryingOnce(il2cpp::Il2CppObject* oppoAction);

    // C#: System.Void OnBeforeParryingOnce_AfterLog(BattleActionModel oppoAction)
    virtual void OnBeforeParryingOnce_AfterLog(il2cpp::Il2CppObject* oppoAction);

    // C#: System.Void OnDuelAfter_BeforeLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 parryingCount, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
    virtual void OnDuelAfter_BeforeLog(int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

    // C#: System.Void OnDuelAfter_AfterLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing)
    virtual void OnDuelAfter_AfterLog(int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing);

    // C#: System.Void OnAfterParryingOnce_BeforeLog(BattleActionModel opponentAction, PARRYING_RESULT reuslt, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
    virtual void OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* opponentAction, int32_t reuslt, int32_t parryingCnt, int32_t timing);

    // C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
    virtual void OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

    // C#: System.Void OnWinParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
    virtual void OnWinParrying(il2cpp::Il2CppObject* opponentAction, int32_t timing);

    // C#: System.Void OnLoseParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
    virtual void OnLoseParrying(il2cpp::Il2CppObject* opponentAction, int32_t timing);

    // C#: System.Void OnWinDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
    virtual void OnWinDuel(il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

    // C#: System.Void CheckExtractAbility(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
    virtual void CheckExtractAbility(il2cpp::Il2CppObject* opponentAction, int32_t timing);

    // C#: System.Void FirstBsGaugeUpWithDuelableGuard(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLog)
    virtual void FirstBsGaugeUpWithDuelableGuard(il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLog);

    // C#: System.Void OnLoseDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing)
    virtual void OnLoseDuel(il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing);

    // C#: System.Void BeforeBehaviour(BATTLE_EVENT_TIMING timing)
    virtual void BeforeBehaviour(int32_t timing);

    // C#: System.Void OnStartBehaviour(BATTLE_EVENT_TIMING timing)
    virtual void OnStartBehaviour(int32_t timing);

    // C#: System.Void OnCriticalIsActivated(CoinModel coin, BATTLE_EVENT_TIMING timing, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
    virtual void OnCriticalIsActivated(il2cpp::Il2CppObject* coin, int32_t timing, il2cpp::Il2CppObject* affectKeywords);

    // C#: System.Void OnAttackConfirmed(CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
    virtual void OnAttackConfirmed(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing, bool isCritical);

    // C#: System.Void BeforeGiveAttackDamage(CoinModel coin, BattleUnitModel target, System.Nullable<System.Boolean> isWinDuel, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual void BeforeGiveAttackDamage(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* isWinDuel, bool isCritical, int32_t timing);

    // C#: System.Void OnSucceedAttack(CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual void OnSucceedAttack(il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Boolean CanGiveConcentratedAttack()
    virtual bool CanGiveConcentratedAttack(bool returnValue);

    // C#: System.Void OnSucceedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
    virtual void OnSucceedEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing);

    // C#: System.Void OnFailedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
    virtual void OnFailedEvade(il2cpp::Il2CppObject* attackerAction, int32_t timing);

    // C#: System.Void OnStartCoin(CoinModel coin, BATTLE_EVENT_TIMING timing)
    virtual void OnStartCoin(il2cpp::Il2CppObject* coin, int32_t timing);

    // C#: System.Void OnEndCoin_BeforeLog(CoinModel coin, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual void OnEndCoin_BeforeLog(il2cpp::Il2CppObject* coin, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Void OnEndCoin_AfterLog(CoinModel coin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual void OnEndCoin_AfterLog(il2cpp::Il2CppObject* coin, bool isCritical, int32_t timing);

    // C#: System.Void OnEndAttack(System.Int32 accumulatedDmg, System.Int32 accumulatedHpDmg, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing, BattleLog_Duel duelLogOrNull)
    virtual void OnEndAttack(int32_t accumulatedDmg, int32_t accumulatedHpDmg, il2cpp::Il2CppObject* isWinDuel, int32_t timing, il2cpp::Il2CppObject* duelLogOrNull);

    // C#: System.Void OnEndBehaviour(BattleRunLog runLog, BATTLE_EVENT_TIMING timing, System.Boolean isLoserAttackExpected)
    virtual void OnEndBehaviour(il2cpp::Il2CppObject* runLog, int32_t timing, bool isLoserAttackExpected);

    // C#: System.Void OnGiveBsGaugeUp(CoinModel coinOrNull, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion)
    virtual void OnGiveBsGaugeUp(il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion);

    // C#: System.Void OnEndTurn(BATTLE_EVENT_TIMING timing)
    virtual void OnEndTurn(int32_t timing);

    // C#: System.Void OnDiscarded(BATTLE_EVENT_TIMING timing)
    virtual void OnDiscarded(int32_t timing);

    // C#: System.Void OnKillTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
    virtual void OnKillTarget(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

    // C#: System.Void OnBreakTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
    virtual void OnBreakTarget(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

    // C#: System.Void OnDestroyTargetPart(BattleUnitModel_Abnormality_Part target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
    virtual void OnDestroyTargetPart(il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

    // C#: System.Void Done()
    virtual void Done();

    // C#: System.Void DoneWithAction(BATTLE_EVENT_TIMING timing)
    virtual void DoneWithAction(int32_t timing);

    // C#: System.Void AddSinStock()
    virtual void AddSinStock();

    // C#: System.Int32 GetExpectedMinCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
    virtual int32_t GetExpectedMinCoinValue_P2_1(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder);

    // C#: System.Int32 GetExpectedMaxCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
    virtual int32_t GetExpectedMaxCoinValue_P2_1(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder);

    // C#: System.Int32 GetExpectedMinCoinValue(UnitSinModel oppoSin, System.Int32& adder)
    virtual int32_t GetExpectedMinCoinValue_P2_2(int32_t returnValue, il2cpp::Il2CppObject* oppoSin, int32_t* adder);

    // C#: System.Int32 GetExpectedMaxCoinValue(UnitSinModel oppoSin, System.Int32& adder)
    virtual int32_t GetExpectedMaxCoinValue_P2_2(int32_t returnValue, il2cpp::Il2CppObject* oppoSin, int32_t* adder);

    // C#: System.Int32 GetExpectedCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
    virtual int32_t GetExpectedCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder);

    // C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamage()
    virtual int32_t GetExpectedRateOfIncreaseAndDecreaseDamage(int32_t returnValue);

    // C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(SinActionModel targetSinActionOrNull, BattleActionModel targetActionOrNull)
    virtual int32_t GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(int32_t returnValue, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionOrNull);

    // C#: System.Int32 GetExpectedDamage(CalculationType type, System.Collections.Generic.List<System.Int32> indexes, SinActionModel targetSinActionOrNull, BattleActionModel oppoActionOrNull)
    virtual int32_t GetExpectedDamage(int32_t returnValue, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull);

    // C#: System.Int32 GetExpectedDamageByTarget(CalculationType type, SinActionModel targetSinAction, BattleActionModel targetActionOrNull, System.Collections.Generic.List<System.Int32> indexes)
    virtual int32_t GetExpectedDamageByTarget(int32_t returnValue, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* targetActionOrNull, il2cpp::Il2CppObject* indexes);

    // C#: System.Boolean IsDuelExpcted(BattleActionModel oppoAction)
    virtual bool IsDuelExpcted(bool returnValue, il2cpp::Il2CppObject* oppoAction);

    // C#: System.Int32 GetParryingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
    virtual int32_t GetParryingCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder);

    // C#: System.Int32 GetDamageCalculation(SinActionModel targetSinActionOrNull, BattleActionModel targetActionModelOrNull, System.Boolean isMin, System.Int32& adder)
    virtual int32_t GetDamageCalculation(int32_t returnValue, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionModelOrNull, bool isMin, int32_t* adder);

    // C#: System.Int32 GetSnowBallingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Boolean isOpponentEvade, System.Int32& adder)
    virtual int32_t GetSnowBallingCalculation(int32_t returnValue, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, bool isOpponentEvade, int32_t* adder);

    // C#: System.Int32 GetDefaultAllCoinCalculation(System.Boolean isMin, System.Boolean isParrying, System.Boolean isOpponentEvade)
    virtual int32_t GetDefaultAllCoinCalculation(int32_t returnValue, bool isMin, bool isParrying, bool isOpponentEvade);

    // C#: System.Int32 GetParryingAdder(BattleActionModel oppoActionOrNull)
    virtual int32_t GetParryingAdder(int32_t returnValue, il2cpp::Il2CppObject* oppoActionOrNull);

    // C#: System.Int32 GetMinExpectedDamage(SinActionModel targetSinAction, System.Collections.Generic.List<System.Int32> selectedIndexes)
    virtual int32_t GetMinExpectedDamage(int32_t returnValue, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* selectedIndexes);

    // C#: System.Single GetCriticalChance(CoinModel coin, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single>& affectKeywords)
    virtual float GetCriticalChance(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** affectKeywords);

    // C#: System.Boolean CanTeamKill()
    virtual bool CanTeamKill(bool returnValue);

    // C#: System.Int32 GetSkillLevel(System.Int32 resonanceIndex, System.Int32& allCorrectionValue, System.Int32& effectCorrectionValue)
    virtual int32_t GetSkillLevel(int32_t returnValue, int32_t resonanceIndex, int32_t* allCorrectionValue, int32_t* effectCorrectionValue);

    // C#: System.Int32 GetSkillPower(COIN_ROLL_TYPE rollType, BATTLE_EVENT_TIMING timing, System.Collections.Generic.List<CoinModel> coinList, BattleActionModel attackerActionOrNull)
    virtual int32_t GetSkillPower(int32_t returnValue, int32_t rollType, int32_t timing, il2cpp::Il2CppObject* coinList, il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull, BattleActionModel attackerActionOrNull)
    virtual int32_t GetExpectedSkillPower_P3_1(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, System.Collections.Generic.List<System.Int32> indexes, SinActionModel expectedTargetSinActionOrNull)
    virtual int32_t GetExpectedSkillPower_P3_2(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

    // C#: System.Int32 GetCoinScale(CoinModel coin, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
    virtual int32_t GetCoinScale(int32_t returnValue, il2cpp::Il2CppObject* coin, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Nullable<System.Int32> OverrideCoinScale(CoinModel coin, System.Int32 originScaleAdder)
    virtual il2cpp::Il2CppObject* OverrideCoinScale(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* coin, int32_t originScaleAdder);

    // C#: System.Int32 GetExpectedCoinScale(CoinModel coin, COIN_ROLL_TYPE rollType, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
    virtual int32_t GetExpectedCoinScale(int32_t returnValue, il2cpp::Il2CppObject* coin, int32_t rollType, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

    // C#: System.Int32 GetAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
    virtual int32_t GetAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target);

    // C#: System.Int32 GetExpectedAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
    virtual int32_t GetExpectedAttackHpDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target);

    // C#: System.Int32 GetCoinScaleAdder(CoinModel coin, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
    virtual int32_t GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

    // C#: System.Int32 GetExpectedCoinScaleAdder(CoinModel coin, COIN_ROLL_TYPE rollType, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
    virtual int32_t GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, int32_t rollType, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

    // C#: System.Int32 GetSkillPowerResultAdder(BATTLE_EVENT_TIMING timing, BattleActionModel attackerActionOrNull, System.Boolean calculateSystemAdder, CoinModel coinOrNull)
    virtual int32_t GetSkillPowerResultAdder(int32_t returnValue, int32_t timing, il2cpp::Il2CppObject* attackerActionOrNull, bool calculateSystemAdder, il2cpp::Il2CppObject* coinOrNull);

    // C#: System.Int32 GetExpectedSkillPowerAdder(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
    virtual int32_t GetExpectedSkillPowerAdder(int32_t returnValue, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

    // C#: System.Int32 GetExpectedSkillPowerResultAdder(System.Collections.Generic.List<System.Int32> indexes, SinActionModel opppoSinActionOrNull, BattleActionModel oppoActionOrNull)
    virtual int32_t GetExpectedSkillPowerResultAdder(int32_t returnValue, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* opppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull);

    // C#: System.Single GetAttackDmgMultiplier(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical, System.Boolean isOneSideAttack, OneCoinLog_Attack forEditorItCanBeNull)
    virtual float GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical, bool isOneSideAttack, il2cpp::Il2CppObject* forEditorItCanBeNull);

    // C#: System.Single GetExpectedAttackDmgMultiplier(CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
    virtual float GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

    // C#: System.Int32 GetAttackDmgAdder(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel)
    virtual int32_t GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel);

    // C#: System.Int32 GetExpectedAttackDmgAdder(CoinModel coin, BattleUnitModel targetOrNull)
    virtual int32_t GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull);

    // C#: System.Int32 GetOppoSkillPowerResultAdderOnTakeAtkDmg()
    virtual int32_t GetOppoSkillPowerResultAdderOnTakeAtkDmg(int32_t returnValue);

    // C#: static System.Boolean BothCanDuelAndAttackSkill(BattleActionModel a, BattleActionModel b)
    virtual il2cpp::Il2CppObject* BothCanDuelAndAttackSkill(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

    // C#: static System.Boolean BothCanDuelAndAtLeastOneAttackSkill(BattleActionModel a, BattleActionModel b)
    virtual il2cpp::Il2CppObject* BothCanDuelAndAtLeastOneAttackSkill(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

    // C#: static System.Boolean CanDuelBoth(BattleActionModel a, BattleActionModel b)
    virtual il2cpp::Il2CppObject* CanDuelBoth(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

    // C#: System.Boolean CanDuel(BattleActionModel opponentAction)
    virtual bool CanDuel(bool returnValue, il2cpp::Il2CppObject* opponentAction);

    // C#: System.Boolean CanDuelWithoutCheckNull(BattleActionModel opponentAction)
    virtual bool CanDuelWithoutCheckNull(bool returnValue, il2cpp::Il2CppObject* opponentAction);

    // C#: System.Boolean IsPanicBlock()
    virtual bool IsPanicBlock(bool returnValue);

    // C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action, BattleUnitModel target)
    virtual il2cpp::Il2CppObject* GetDescArgs_P2(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target);

    // C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action)
    virtual il2cpp::Il2CppObject* GetDescArgs_P1(il2cpp::Il2CppObject* returnValue, il2cpp::Il2CppObject* action);

    // C#: System.Boolean IsAllCoinHead()
    virtual bool IsAllCoinHead(bool returnValue);

    // C#: System.Boolean IsAllCoinHit()
    virtual bool IsAllCoinHit(bool returnValue);

    // C#: System.Int32 GetHeadCoinNum()
    virtual int32_t GetHeadCoinNum(int32_t returnValue);

    // C#: System.Int32 GetTailCoinNum()
    virtual int32_t GetTailCoinNum(int32_t returnValue);

    // C#: System.Int32 GetUsableInDuelCoinNum()
    virtual int32_t GetUsableInDuelCoinNum(int32_t returnValue);

    // C#: System.Boolean IsFirstCoin(CoinModel coin)
    virtual bool IsFirstCoin(bool returnValue, il2cpp::Il2CppObject* coin);

    // C#: System.Boolean IsLastCoin(CoinModel coin)
    virtual bool IsLastCoin(bool returnValue, il2cpp::Il2CppObject* coin);

    // C#: System.Boolean CheckPersonalitySkillSpecificType(SKILL_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
    virtual bool CheckPersonalitySkillSpecificType(bool returnValue, int32_t keyword, int32_t targetType);

    // C#: System.Boolean CheckSkillGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckSkillGivingBuffCategory(bool returnValue, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Boolean CheckSkillGivingBuff(BUFF_UNIQUE_KEYWORD buffKeyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
    virtual bool CheckSkillGivingBuff(bool returnValue, int32_t buffKeyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

    // C#: System.Boolean IsGainBullet()
    virtual bool IsGainBullet(bool returnValue);

    // C#: CoinModel GetCoin(System.Int32 i)
    virtual il2cpp::Il2CppObject* GetCoin(il2cpp::Il2CppObject* returnValue, int32_t i);

    // C#: CoinModel GetFirstCoin()
    virtual il2cpp::Il2CppObject* GetFirstCoin(il2cpp::Il2CppObject* returnValue);

    // C#: CoinModel GetLastCoin()
    virtual il2cpp::Il2CppObject* GetLastCoin(il2cpp::Il2CppObject* returnValue);

    // C#: System.Int32 GetMpUsage(System.Boolean isErodeSkill)
    virtual int32_t GetMpUsage(int32_t returnValue, bool isErodeSkill);

    // C#: System.Boolean IsMultiTarget()
    virtual bool IsMultiTarget(bool returnValue);

    // C#: System.Boolean IsReusedAction()
    virtual bool IsReusedAction(bool returnValue);

    // C#: System.Void BeforeAttack(BATTLE_EVENT_TIMING timing)
    virtual void BeforeAttack(int32_t timing);

    // C#: System.Int32 GetFinalSkillPowerResult(BATTLE_EVENT_TIMING timing)
    virtual int32_t GetFinalSkillPowerResult(int32_t returnValue, int32_t timing);

    // C#: System.Int32 GetParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
    virtual int32_t GetParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount);

    // C#: System.Int32 GetExpectedParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
    virtual int32_t GetExpectedParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);

    // C#: System.Int32 GetOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
    virtual int32_t GetOpponentParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

    // C#: System.Int32 GetExpectedOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
    virtual int32_t GetExpectedOpponentParryingResultAdder(int32_t returnValue, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

    // C#: System.Void OverWriteSkill(System.Int32 defaultValue, System.Int32 coinNum, System.Int32 coinScale, OPERATOR_TYPE operatorType)
    virtual void OverWriteSkill(int32_t defaultValue, int32_t coinNum, int32_t coinScale, int32_t operatorType);

    // C#: System.Boolean IsRandomTarget()
    virtual bool IsRandomTarget(bool returnValue);

    // C#: System.Boolean IsTargetableSlot(SinActionModel attackerSinAction)
    virtual bool IsTargetableSlot(bool returnValue, il2cpp::Il2CppObject* attackerSinAction);

    // C#: System.Boolean IsSkillAbsorbingThisDamage()
    virtual bool IsSkillAbsorbingThisDamage(bool returnValue);

    // C#: System.Boolean IsDefenseSkillForOther(BattleUnitModel originTarget, BattleActionModel opponentActionOrNull)
    virtual bool IsDefenseSkillForOther(bool returnValue, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* opponentActionOrNull);

    // C#: System.Boolean AttackByMpDmgRatherThanHpDmg(CoinModel coin, System.Int32 resultDmg, BattleUnitModel target)
    virtual bool AttackByMpDmgRatherThanHpDmg(bool returnValue, il2cpp::Il2CppObject* coin, int32_t resultDmg, il2cpp::Il2CppObject* target);

    // C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
    virtual bool BlockLoseBuffByReactWithAction(bool returnValue, il2cpp::Il2CppObject* target, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

    // C#: System.Int32 ChangeAttackDamage(CoinModel coin, BattleUnitModel target, System.Int32 resultDmg, System.Boolean& isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
    virtual int32_t ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t resultDmg, bool* isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

    // C#: System.Void OnSkillChangedEgo(System.Boolean isOverClock, BATTLE_EVENT_TIMING timing)
    virtual void OnSkillChangedEgo(bool isOverClock, int32_t timing);

    // C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
    virtual void OnRoundEnd(int32_t timing);

    // C#: System.Void OnRoundEnd_After()
    virtual void OnRoundEnd_After();

    // C#: System.Void OnAddCoinByAbility(CoinModel newCoin, BATTLE_EVENT_TIMING timing)
    virtual void OnAddCoinByAbility(il2cpp::Il2CppObject* newCoin, int32_t timing);

    // C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
    virtual float GetGiveBsGaugeUpMultiplier(float returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull);

    // C#: System.Int32 GetGiveBsGaugeUpAdder(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
    virtual int32_t GetGiveBsGaugeUpAdder(int32_t returnValue, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull);

    // C#: System.Boolean HasCoinOperatorType(OPERATOR_TYPE type)
    virtual bool HasCoinOperatorType(bool returnValue, int32_t type);

    // C#: System.Boolean HasSuperCoin()
    virtual bool HasSuperCoin(bool returnValue);

    // C#: System.Void StackNextTurnAggroAdder()
    virtual void StackNextTurnAggroAdder();

    // C#: System.Void OnUseStageBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
    virtual void OnUseStageBuffBySkill(int32_t keyword, int32_t stack);

    // C#: System.Int32 GetUsedStageBuffStack(BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetUsedStageBuffStack(int32_t returnValue, int32_t keyword);

    // C#: System.Void OnUseBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
    virtual void OnUseBuffBySkill(int32_t keyword, int32_t stack, int32_t turn);

    // C#: System.Boolean UsedBuffStack(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
    virtual bool UsedBuffStack(bool returnValue, int32_t keyword, int32_t stack);

    // C#: System.Boolean UsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword, System.Int32 turn)
    virtual bool UsedBuffTurn(bool returnValue, int32_t keyword, int32_t turn);

    // C#: System.Int32 GetUsedBuffStack(BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetUsedBuffStack(int32_t returnValue, int32_t keyword);

    // C#: System.Int32 GetUsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
    virtual int32_t GetUsedBuffTurn(int32_t returnValue, int32_t keyword);

    // C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, CoinModel coinOrNull, System.Single& prob)
    virtual bool OverwriteCoinProb(bool returnValue, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, float* prob);

    // C#: System.Boolean OverwriteCriticalResult(CoinModel coin, System.Boolean tempCritical, System.Nullable<System.Boolean>& overwriteCriticalResult)
    virtual bool OverwriteCriticalResult(bool returnValue, il2cpp::Il2CppObject* coin, bool tempCritical, il2cpp::Il2CppObject** overwriteCriticalResult);

    // C#: System.Boolean IgnoreCheckCritical(CoinModel coin)
    virtual bool IgnoreCheckCritical(bool returnValue, il2cpp::Il2CppObject* coin);

    // C#: System.Boolean CanDealTarget(BattleUnitModel target, CoinModel coin)
    virtual bool CanDealTarget(bool returnValue, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin);

    // C#: System.Boolean BlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
    virtual bool BlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

    // C#: System.Boolean ExpectedBlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
    virtual bool ExpectedBlockGivingBuff(bool returnValue, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

    // C#: System.Void RightBeforeGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
    virtual void RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical);

    // C#: System.Void RightAfterGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, CoinModel coinOrNull)
    virtual void RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical, il2cpp::Il2CppObject* coinOrNull);

    // C#: System.Boolean IsReusable()
    virtual bool IsReusable(bool returnValue);

    // C#: System.Boolean IsSupportSkill()
    virtual bool IsSupportSkill(bool returnValue);

    // C#: System.Boolean IsChangeable()
    virtual bool IsChangeable(bool returnValue);

    // C#: System.Void OnOrderCutInAction(BattleActionModel newAction)
    virtual void OnOrderCutInAction(il2cpp::Il2CppObject* newAction);

    // C#: System.Void AddTemporarySkillAbilityToSkill(SkillAbility tempSkillAbility, System.String scriptName, System.Single jsonValue, System.Int32 idx, System.Int32 turnLimit, BuffReferenceData info)
    virtual void AddTemporarySkillAbilityToSkill(il2cpp::Il2CppObject* tempSkillAbility, il2cpp::Il2CppObject* scriptName, float jsonValue, int32_t idx, int32_t turnLimit, il2cpp::Il2CppObject* info);

    // C#: System.Void RemoveAllSpecificSkillAbility(System.Type targetSkillAbility)
    virtual void RemoveAllSpecificSkillAbility(il2cpp::Il2CppObject* targetSkillAbility);

    // C#: System.Void AddCoinIgnoredTiming(BATTLE_EVENT_TIMING timing)
    virtual void AddCoinIgnoredTiming(int32_t timing);

    // C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingTargetBurstBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

    // C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
    virtual bool IsBlockingTargetSinkingBuffEffectReact(bool returnValue, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

    // C#: System.Boolean OverwriteParryingResult(System.Int32 tempActorResult, BattleActionModel oppoAction, System.Int32 tempOppoResult, System.Nullable<System.Int32>& overwriteResult)
    virtual bool OverwriteParryingResult(bool returnValue, int32_t tempActorResult, il2cpp::Il2CppObject* oppoAction, int32_t tempOppoResult, il2cpp::Il2CppObject** overwriteResult);

    // C#: System.Boolean TryGetForcedCoinResult(System.Nullable<System.Boolean> isParrying, COIN_RESULT& result, BattleActionModel oppoActionOrNull)
    virtual bool TryGetForcedCoinResult(bool returnValue, il2cpp::Il2CppObject* isParrying, int32_t* result, il2cpp::Il2CppObject* oppoActionOrNull);

    // C#: COIN_RESULT GetForcedCoinResult(System.Nullable<System.Boolean> isParrying)
    virtual int32_t GetForcedCoinResult(int32_t returnValue, il2cpp::Il2CppObject* isParrying);

    // C#: BattleActionSystemAbility AddAbilityThisRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
    virtual il2cpp::Il2CppObject* AddAbilityThisRound(il2cpp::Il2CppObject* returnValue, int32_t keyword, int32_t stack, int32_t turn);

    // C#: BattleActionSystemAbility AddAbilityNextRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
    virtual il2cpp::Il2CppObject* AddAbilityNextRound(il2cpp::Il2CppObject* returnValue, int32_t keyword, int32_t stack, int32_t turn);

    // C#: System.Boolean HasSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
    virtual bool HasSystemAbility(bool returnValue, int32_t keyword);

    // C#: BattleActionSystemAbility GetSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
    virtual il2cpp::Il2CppObject* GetSystemAbility(il2cpp::Il2CppObject* returnValue, int32_t keyword);

    // C#: System.Void DestroySystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
    virtual void DestroySystemAbility(int32_t keyword);

    // C#: System.Void MarkAsExtracted()
    virtual void MarkAsExtracted();

    // C#: System.Void OnAddBattleAction(SinActionModel targetSinActionNullable)
    virtual void OnAddBattleAction(il2cpp::Il2CppObject* targetSinActionNullable);

    // C#: System.Void OnRemoveBattleAction()
    virtual void OnRemoveBattleAction();

    // C#: System.Void OnSetExpectedTarget(BattleActionModel targetAction)
    virtual void OnSetExpectedTarget(il2cpp::Il2CppObject* targetAction);

    // C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel mainAction, BattleActionModel oppoActionNullable)
    virtual bool IsRunUniqueAction(bool returnValue, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionNullable);

    // C#: System.Boolean IsEgoSkill()
    virtual bool IsEgoSkill(bool returnValue);

    // C#: System.Boolean HasEgoKeyword(EGO_KEYWORD keyword)
    virtual bool HasEgoKeyword(bool returnValue, int32_t keyword);

};

// creating hook and original vars region. So fun!
#pragma region

// C#: UnitSinModel get_Sin()
using BattleActionModelget_SinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_SinFn original_BattleActionModel_get_Sin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Sin(il2cpp::Il2CppObject* __this);

// C#: BattleUnitModel get_Model()
using BattleActionModelget_ModelFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_ModelFn original_BattleActionModel_get_Model = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Model(il2cpp::Il2CppObject* __this);

// C#: SkillModel get_Skill()
using BattleActionModelget_SkillFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_SkillFn original_BattleActionModel_get_Skill = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Skill(il2cpp::Il2CppObject* __this);

// C#: System.Boolean get_IsDone()
using BattleActionModelget_IsDoneFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_IsDoneFn original_BattleActionModel_get_IsDone = nullptr;
bool hooked_BattleActionModel_get_IsDone(il2cpp::Il2CppObject* __this);

// C#: System.Boolean get_isDoneWithAction()
using BattleActionModelget_isDoneWithActionFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_isDoneWithActionFn original_BattleActionModel_get_isDoneWithAction = nullptr;
bool hooked_BattleActionModel_get_isDoneWithAction(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_skillPowerResultValue()
using BattleActionModelget_skillPowerResultValueFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_skillPowerResultValueFn original_BattleActionModel_get_skillPowerResultValue = nullptr;
int32_t hooked_BattleActionModel_get_skillPowerResultValue(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_ReusedTimes()
using BattleActionModelget_ReusedTimesFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_ReusedTimesFn original_BattleActionModel_get_ReusedTimes = nullptr;
int32_t hooked_BattleActionModel_get_ReusedTimes(il2cpp::Il2CppObject* __this);

// C#: SinActionModel get_SinAction()
using BattleActionModelget_SinActionFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_SinActionFn original_BattleActionModel_get_SinAction = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_get_SinAction(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_ActionInstanceID()
using BattleActionModelget_ActionInstanceIDFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_ActionInstanceIDFn original_BattleActionModel_get_ActionInstanceID = nullptr;
int32_t hooked_BattleActionModel_get_ActionInstanceID(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_CommanderInstanceID()
using BattleActionModelget_CommanderInstanceIDFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_CommanderInstanceIDFn original_BattleActionModel_get_CommanderInstanceID = nullptr;
int32_t hooked_BattleActionModel_get_CommanderInstanceID(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_OrderedActionInstanceId()
using BattleActionModelget_OrderedActionInstanceIdFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_OrderedActionInstanceIdFn original_BattleActionModel_get_OrderedActionInstanceId = nullptr;
int32_t hooked_BattleActionModel_get_OrderedActionInstanceId(il2cpp::Il2CppObject* __this);

// C#: System.Int32 get_OrderedActionActorInstanceId()
using BattleActionModelget_OrderedActionActorInstanceIdFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_OrderedActionActorInstanceIdFn original_BattleActionModel_get_OrderedActionActorInstanceId = nullptr;
int32_t hooked_BattleActionModel_get_OrderedActionActorInstanceId(il2cpp::Il2CppObject* __this);

// C#: System.Boolean get_IsExtracted()
using BattleActionModelget_IsExtractedFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_IsExtractedFn original_BattleActionModel_get_IsExtracted = nullptr;
bool hooked_BattleActionModel_get_IsExtracted(il2cpp::Il2CppObject* __this);

// C#: BattleUnitModel get_Commander()
using BattleActionModelget_CommanderFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_CommanderFn original_BattleActionModel_get_Commander = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_get_Commander(il2cpp::Il2CppObject* __this);

// C#: ABILITY_SOURCE_TYPE get_OrderSourceType()
using BattleActionModelget_OrderSourceTypeFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelget_OrderSourceTypeFn original_BattleActionModel_get_OrderSourceType = nullptr;
int32_t hooked_BattleActionModel_get_OrderSourceType(il2cpp::Il2CppObject* __this);

// C#: System.Void SetTargetDetailType(BattleUnitModel model, System.Boolean isReuseAction)
using BattleActionModelSetTargetDetailTypeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelSetTargetDetailTypeFn original_BattleActionModel_SetTargetDetailType = nullptr;
void hooked_BattleActionModel_SetTargetDetailType(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* model, bool isReuseAction);

// C#: System.Void InitCoins()
using BattleActionModelInitCoinsFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelInitCoinsFn original_BattleActionModel_InitCoins = nullptr;
void hooked_BattleActionModel_InitCoins(il2cpp::Il2CppObject* __this);

// C#: System.Void InitCoinResults()
using BattleActionModelInitCoinResultsFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelInitCoinResultsFn original_BattleActionModel_InitCoinResults = nullptr;
void hooked_BattleActionModel_InitCoinResults(il2cpp::Il2CppObject* __this);

// C#: System.Void InitStaticData()
using BattleActionModelInitStaticDataFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelInitStaticDataFn original_BattleActionModel_InitStaticData = nullptr;
void hooked_BattleActionModel_InitStaticData(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsActivatedSupportiveProtectByThisAction()
using BattleActionModelIsActivatedSupportiveProtectByThisActionFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsActivatedSupportiveProtectByThisActionFn original_BattleActionModel_IsActivatedSupportiveProtectByThisAction = nullptr;
bool hooked_BattleActionModel_IsActivatedSupportiveProtectByThisAction(il2cpp::Il2CppObject* __this);

// C#: System.Void CheckActivationOfSupportiveProtect()
using BattleActionModelCheckActivationOfSupportiveProtectFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCheckActivationOfSupportiveProtectFn original_BattleActionModel_CheckActivationOfSupportiveProtect = nullptr;
void hooked_BattleActionModel_CheckActivationOfSupportiveProtect(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsSupportiveDefense_Old()
using BattleActionModelIsSupportiveDefense_OldFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsSupportiveDefense_OldFn original_BattleActionModel_IsSupportiveDefense_Old = nullptr;
bool hooked_BattleActionModel_IsSupportiveDefense_Old(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsSupportiveDefense()
using BattleActionModelIsSupportiveDefenseFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsSupportiveDefenseFn original_BattleActionModel_IsSupportiveDefense = nullptr;
bool hooked_BattleActionModel_IsSupportiveDefense(il2cpp::Il2CppObject* __this);

// C#: System.Void RemoveTargetData(System.Boolean returnPrevTarget)
using BattleActionModelRemoveTargetDataFn = void(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelRemoveTargetDataFn original_BattleActionModel_RemoveTargetData = nullptr;
void hooked_BattleActionModel_RemoveTargetData(il2cpp::Il2CppObject* __this, bool returnPrevTarget);

// C#: System.Collections.Generic.List<SinActionModel> GetOriginTargetSinActionsData(System.Boolean isOverlap)
using BattleActionModelGetOriginTargetSinActionsDataFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelGetOriginTargetSinActionsDataFn original_BattleActionModel_GetOriginTargetSinActionsData = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetOriginTargetSinActionsData(il2cpp::Il2CppObject* __this, bool isOverlap);

// C#: BattleUnitModel GetOriginMainTarget()
using BattleActionModelGetOriginMainTargetFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetOriginMainTargetFn original_BattleActionModel_GetOriginMainTarget = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetOriginMainTarget(il2cpp::Il2CppObject* __this);

// C#: System.Boolean HasOriginTarget()
using BattleActionModelHasOriginTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelHasOriginTargetFn original_BattleActionModel_HasOriginTarget = nullptr;
bool hooked_BattleActionModel_HasOriginTarget(il2cpp::Il2CppObject* __this);

// C#: System.Boolean HasMainTarget()
using BattleActionModelHasMainTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelHasMainTargetFn original_BattleActionModel_HasMainTarget = nullptr;
bool hooked_BattleActionModel_HasMainTarget(il2cpp::Il2CppObject* __this);

// C#: System.Boolean HasSubTarget()
using BattleActionModelHasSubTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelHasSubTargetFn original_BattleActionModel_HasSubTarget = nullptr;
bool hooked_BattleActionModel_HasSubTarget(il2cpp::Il2CppObject* __this);

// C#: SinActionModel GetMainTargetSinAction()
using BattleActionModelGetMainTargetSinActionFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetMainTargetSinActionFn original_BattleActionModel_GetMainTargetSinAction = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetMainTargetSinAction(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<SinActionModel> GetSubTargetSinActionList()
using BattleActionModelGetSubTargetSinActionListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSubTargetSinActionListFn original_BattleActionModel_GetSubTargetSinActionList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSubTargetSinActionList(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<SinActionModel> GetTargetSinActionList()
using BattleActionModelGetTargetSinActionListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetTargetSinActionListFn original_BattleActionModel_GetTargetSinActionList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetSinActionList(il2cpp::Il2CppObject* __this);

// C#: BattleUnitModel GetMainTarget()
using BattleActionModelGetMainTargetFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetMainTargetFn original_BattleActionModel_GetMainTarget = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetMainTarget(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetUnitModelList()
using BattleActionModelGetTargetUnitModelListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetTargetUnitModelListFn original_BattleActionModel_GetTargetUnitModelList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetUnitModelList(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<BattleUnitModel> GetAliveTargetUnitModelList()
using BattleActionModelGetAliveTargetUnitModelListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetAliveTargetUnitModelListFn original_BattleActionModel_GetAliveTargetUnitModelList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetAliveTargetUnitModelList(il2cpp::Il2CppObject* __this);

// C#: System.Void SetOriginTargetSinActions(System.Collections.Generic.List<SinActionModel> originTargetSinActions)
using BattleActionModelSetOriginTargetSinActionsFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelSetOriginTargetSinActionsFn original_BattleActionModel_SetOriginTargetSinActions = nullptr;
void hooked_BattleActionModel_SetOriginTargetSinActions(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTargetSinActions);

// C#: System.Void ReadyOriginTargeting()
using BattleActionModelReadyOriginTargetingFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelReadyOriginTargetingFn original_BattleActionModel_ReadyOriginTargeting = nullptr;
void hooked_BattleActionModel_ReadyOriginTargeting(il2cpp::Il2CppObject* __this);

// C#: System.Void AddTarget(SinActionModel targetSinAction)
using BattleActionModelAddTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelAddTargetFn original_BattleActionModel_AddTarget = nullptr;
void hooked_BattleActionModel_AddTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction);

// C#: System.Void SetTargetAfterBattleStart(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
using BattleActionModelSetTargetAfterBattleStartFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetAfterBattleStartFn original_BattleActionModel_SetTargetAfterBattleStart = nullptr;
void hooked_BattleActionModel_SetTargetAfterBattleStart(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

// C#: System.Void RedirectTarget(System.Boolean mainTargetAlive)
using BattleActionModelRedirectTargetFn = void(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelRedirectTargetFn original_BattleActionModel_RedirectTarget = nullptr;
void hooked_BattleActionModel_RedirectTarget(il2cpp::Il2CppObject* __this, bool mainTargetAlive);

// C#: System.Void SetTargetAuto(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
using BattleActionModelSetTargetAutoFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetAutoFn original_BattleActionModel_SetTargetAuto = nullptr;
void hooked_BattleActionModel_SetTargetAuto(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

// C#: System.Void SetTargetBySortedTargetableSinActionList(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
using BattleActionModelSetTargetBySortedTargetableSinActionListFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetBySortedTargetableSinActionListFn original_BattleActionModel_SetTargetBySortedTargetableSinActionList = nullptr;
void hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEnemyOnly, int32_t targetType);

// C#: System.Void SetTargetAfterBattleStart_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
using BattleActionModelSetTargetAfterBattleStart_CutInFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetAfterBattleStart_CutInFn original_BattleActionModel_SetTargetAfterBattleStart_CutIn = nullptr;
void hooked_BattleActionModel_SetTargetAfterBattleStart_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

// C#: System.Void SetTargetAuto_CutIn(System.Boolean canDuel, System.Boolean attackEenemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
using BattleActionModelSetTargetAuto_CutInFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetAuto_CutInFn original_BattleActionModel_SetTargetAuto_CutIn = nullptr;
void hooked_BattleActionModel_SetTargetAuto_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEenemyOnly, int32_t overwritedTargetType);

// C#: System.Void SetTargetBySortedTargetableSinActionList_CutIn(System.Boolean canDuel, System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE targetType)
using BattleActionModelSetTargetBySortedTargetableSinActionList_CutInFn = void(*)(il2cpp::Il2CppObject*, bool, bool, int32_t);
inline BattleActionModelSetTargetBySortedTargetableSinActionList_CutInFn original_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn = nullptr;
void hooked_BattleActionModel_SetTargetBySortedTargetableSinActionList_CutIn(il2cpp::Il2CppObject* __this, bool canDuel, bool attackEnemyOnly, int32_t targetType);

// C#: System.Void RemoveOneTargetSet(BattleActionModel otherAction)
using BattleActionModelRemoveOneTargetSetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelRemoveOneTargetSetFn original_BattleActionModel_RemoveOneTargetSet = nullptr;
void hooked_BattleActionModel_RemoveOneTargetSet(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction);

// C#: System.Boolean CanDuelWithSameFaction()
using BattleActionModelCanDuelWithSameFactionFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCanDuelWithSameFactionFn original_BattleActionModel_CanDuelWithSameFaction = nullptr;
bool hooked_BattleActionModel_CanDuelWithSameFaction(il2cpp::Il2CppObject* __this);

// C#: System.Void SetTarget(System.Collections.Generic.List<SinActionModel> sortedTargetSinActions, System.Boolean canDuel)
using BattleActionModelSetTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelSetTargetFn original_BattleActionModel_SetTarget = nullptr;
void hooked_BattleActionModel_SetTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* sortedTargetSinActions, bool canDuel);

// C#: System.Void RecheckTargetList()
using BattleActionModelRecheckTargetListFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelRecheckTargetListFn original_BattleActionModel_RecheckTargetList = nullptr;
void hooked_BattleActionModel_RecheckTargetList(il2cpp::Il2CppObject* __this);

// C#: System.Void AfterRecheckTargetList(System.Boolean valid, System.Boolean mainTargetAlive)
using BattleActionModelAfterRecheckTargetListFn = void(*)(il2cpp::Il2CppObject*, bool, bool);
inline BattleActionModelAfterRecheckTargetListFn original_BattleActionModel_AfterRecheckTargetList = nullptr;
void hooked_BattleActionModel_AfterRecheckTargetList(il2cpp::Il2CppObject* __this, bool valid, bool mainTargetAlive);

// C#: System.Void ChangeAllTargetOnCompleteCommand(System.Boolean attackEnemyOnly, SKILL_TARGET_TYPE overwritedTargetType)
using BattleActionModelChangeAllTargetOnCompleteCommandFn = void(*)(il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelChangeAllTargetOnCompleteCommandFn original_BattleActionModel_ChangeAllTargetOnCompleteCommand = nullptr;
void hooked_BattleActionModel_ChangeAllTargetOnCompleteCommand(il2cpp::Il2CppObject* __this, bool attackEnemyOnly, int32_t overwritedTargetType);

// C#: System.Void ChangeMainTargetSinAction(SinActionModel changeTargetSinAction, BattleActionModel oppositeAction, System.Boolean forcely)
using BattleActionModelChangeMainTargetSinActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelChangeMainTargetSinActionFn original_BattleActionModel_ChangeMainTargetSinAction = nullptr;
void hooked_BattleActionModel_ChangeMainTargetSinAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* changeTargetSinAction, il2cpp::Il2CppObject* oppositeAction, bool forcely);

// C#: System.Boolean HasBeenChangedCurrentTargetBy(BattleActionModel oppositeAction)
using BattleActionModelHasBeenChangedCurrentTargetByFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelHasBeenChangedCurrentTargetByFn original_BattleActionModel_HasBeenChangedCurrentTargetBy = nullptr;
bool hooked_BattleActionModel_HasBeenChangedCurrentTargetBy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppositeAction);

// C#: System.Void ChangeAllSubTarget()
using BattleActionModelChangeAllSubTargetFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelChangeAllSubTargetFn original_BattleActionModel_ChangeAllSubTarget = nullptr;
void hooked_BattleActionModel_ChangeAllSubTarget(il2cpp::Il2CppObject* __this);

// C#: System.Void RecheckSubTargetWhenChangeTargetNum(System.Nullable<System.Boolean> overwriteAttackEnemyOnly, SKILL_TARGET_TYPE overwriteTargetType)
using BattleActionModelRecheckSubTargetWhenChangeTargetNumFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelRecheckSubTargetWhenChangeTargetNumFn original_BattleActionModel_RecheckSubTargetWhenChangeTargetNum = nullptr;
void hooked_BattleActionModel_RecheckSubTargetWhenChangeTargetNum(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* overwriteAttackEnemyOnly, int32_t overwriteTargetType);

// C#: System.Void RemoveAllTargetExceptMainTarget()
using BattleActionModelRemoveAllTargetExceptMainTargetFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelRemoveAllTargetExceptMainTargetFn original_BattleActionModel_RemoveAllTargetExceptMainTarget = nullptr;
void hooked_BattleActionModel_RemoveAllTargetExceptMainTarget(il2cpp::Il2CppObject* __this);

// C#: System.Void RemoveUntargetableTarget()
using BattleActionModelRemoveUntargetableTargetFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelRemoveUntargetableTargetFn original_BattleActionModel_RemoveUntargetableTarget = nullptr;
void hooked_BattleActionModel_RemoveUntargetableTarget(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetCurrentOccupiedWeight()
using BattleActionModelGetCurrentOccupiedWeight_P0Fn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetCurrentOccupiedWeight_P0Fn original_BattleActionModel_GetCurrentOccupiedWeight_P0 = nullptr;
int32_t hooked_BattleActionModel_GetCurrentOccupiedWeight_P0(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetCurrentOccupiedWeight(SinActionModel targetSinAction)
using BattleActionModelGetCurrentOccupiedWeight_P1Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetCurrentOccupiedWeight_P1Fn original_BattleActionModel_GetCurrentOccupiedWeight_P1 = nullptr;
int32_t hooked_BattleActionModel_GetCurrentOccupiedWeight_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction);

// C#: System.Void AddPrimeTargets(System.Boolean canDuel)
using BattleActionModelAddPrimeTargetsFn = void(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelAddPrimeTargetsFn original_BattleActionModel_AddPrimeTargets = nullptr;
void hooked_BattleActionModel_AddPrimeTargets(il2cpp::Il2CppObject* __this, bool canDuel);

// C#: System.Boolean GetPrimeTargetSinActions(System.Collections.Generic.List<TargetSinActionData>& primeTargetSinActions, System.Int32& remainedSlotNum)
using BattleActionModelGetPrimeTargetSinActionsFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject**, int32_t*);
inline BattleActionModelGetPrimeTargetSinActionsFn original_BattleActionModel_GetPrimeTargetSinActions = nullptr;
bool hooked_BattleActionModel_GetPrimeTargetSinActions(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject** primeTargetSinActions, int32_t* remainedSlotNum);

// C#: System.Collections.Generic.List<SinActionModel> GetSatisfiedPrimeTargetSinActions()
using BattleActionModelGetSatisfiedPrimeTargetSinActionsFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSatisfiedPrimeTargetSinActionsFn original_BattleActionModel_GetSatisfiedPrimeTargetSinActions = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSatisfiedPrimeTargetSinActions(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<SinActionModel> ExtractSortedPrimeTargetSinActionList(System.Collections.Generic.List<PrimeTargetData> primeTargetDatas)
using BattleActionModelExtractSortedPrimeTargetSinActionListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelExtractSortedPrimeTargetSinActionListFn original_BattleActionModel_ExtractSortedPrimeTargetSinActionList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_ExtractSortedPrimeTargetSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* primeTargetDatas);

// C#: System.Collections.Generic.List<SinActionModel> GetCollapsedTargetableSinActionList(System.Collections.Generic.List<SinActionModel> addedTargetSinActions, System.Nullable<System.Boolean> attackEnemyOnly, SKILL_TARGET_TYPE targetType, System.Boolean canAttackAllyAssist)
using BattleActionModelGetCollapsedTargetableSinActionListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool);
inline BattleActionModelGetCollapsedTargetableSinActionListFn original_BattleActionModel_GetCollapsedTargetableSinActionList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetCollapsedTargetableSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* addedTargetSinActions, il2cpp::Il2CppObject* attackEnemyOnly, int32_t targetType, bool canAttackAllyAssist);

// C#: System.Void SortSinActionList(System.Collections.Generic.List<SinActionModel> list, SKILL_TARGET_TYPE targetType)
using BattleActionModelSortSinActionListFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelSortSinActionListFn original_BattleActionModel_SortSinActionList = nullptr;
void hooked_BattleActionModel_SortSinActionList(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* list, int32_t targetType);

// C#: System.Collections.Generic.List<BattleUnitModel> GetTargetableUnitList(System.Boolean canAttackAllyAssist)
using BattleActionModelGetTargetableUnitListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelGetTargetableUnitListFn original_BattleActionModel_GetTargetableUnitList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetTargetableUnitList(il2cpp::Il2CppObject* __this, bool canAttackAllyAssist);

// C#: System.Void SortTargetSlots(System.Collections.Generic.List<SinActionModel> targetSinActions, SKILL_TARGET_TYPE targetType)
using BattleActionModelSortTargetSlotsFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelSortTargetSlotsFn original_BattleActionModel_SortTargetSlots = nullptr;
void hooked_BattleActionModel_SortTargetSlots(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActions, int32_t targetType);

// C#: System.Single GetExpectedEgoErodeRate(BattleEgoModel egoModel)
using BattleActionModelGetExpectedEgoErodeRateFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedEgoErodeRateFn original_BattleActionModel_GetExpectedEgoErodeRate = nullptr;
float hooked_BattleActionModel_GetExpectedEgoErodeRate(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* egoModel);

// C#: System.Boolean IsConsumeBuffSkill(BUFF_UNIQUE_KEYWORD buff)
using BattleActionModelIsConsumeBuffSkillFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelIsConsumeBuffSkillFn original_BattleActionModel_IsConsumeBuffSkill = nullptr;
bool hooked_BattleActionModel_IsConsumeBuffSkill(il2cpp::Il2CppObject* __this, int32_t buff);

// C#: System.Boolean IsConsumeBullet()
using BattleActionModelIsConsumeBulletFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsConsumeBulletFn original_BattleActionModel_IsConsumeBullet = nullptr;
bool hooked_BattleActionModel_IsConsumeBullet(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsUseBuff(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
using BattleActionModelIsUseBuffFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelIsUseBuffFn original_BattleActionModel_IsUseBuff = nullptr;
bool hooked_BattleActionModel_IsUseBuff(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType);

// C#: System.Boolean IsUseBuffStack(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
using BattleActionModelIsUseBuffStackFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelIsUseBuffStackFn original_BattleActionModel_IsUseBuffStack = nullptr;
bool hooked_BattleActionModel_IsUseBuffStack(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType);

// C#: System.Boolean IsUseBuffTurn(BUFF_UNIQUE_KEYWORD buff, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
using BattleActionModelIsUseBuffTurnFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelIsUseBuffTurnFn original_BattleActionModel_IsUseBuffTurn = nullptr;
bool hooked_BattleActionModel_IsUseBuffTurn(il2cpp::Il2CppObject* __this, int32_t buff, int32_t targetType);

// C#: System.Boolean IsAddBloodDinner()
using BattleActionModelIsAddBloodDinnerFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsAddBloodDinnerFn original_BattleActionModel_IsAddBloodDinner = nullptr;
bool hooked_BattleActionModel_IsAddBloodDinner(il2cpp::Il2CppObject* __this);

// C#: PairWithTargetUnitSinSet GetExpectedAllCalculationOnlyAbnormalityBattle()
using BattleActionModelGetExpectedAllCalculationOnlyAbnormalityBattleFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedAllCalculationOnlyAbnormalityBattleFn original_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetExpectedAllCalculationOnlyAbnormalityBattle(il2cpp::Il2CppObject* __this);

// C#: System.Void MakeReusable()
using BattleActionModelMakeReusableFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelMakeReusableFn original_BattleActionModel_MakeReusable = nullptr;
void hooked_BattleActionModel_MakeReusable(il2cpp::Il2CppObject* __this);

// C#: System.Void ResetAllTargetData()
using BattleActionModelResetAllTargetDataFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelResetAllTargetDataFn original_BattleActionModel_ResetAllTargetData = nullptr;
void hooked_BattleActionModel_ResetAllTargetData(il2cpp::Il2CppObject* __this);

// C#: System.Void ResetCoinState()
using BattleActionModelResetCoinStateFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelResetCoinStateFn original_BattleActionModel_ResetCoinState = nullptr;
void hooked_BattleActionModel_ResetCoinState(il2cpp::Il2CppObject* __this);

// C#: System.Void ResetDataWIthOutTargetData()
using BattleActionModelResetDataWIthOutTargetDataFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelResetDataWIthOutTargetDataFn original_BattleActionModel_ResetDataWIthOutTargetData = nullptr;
void hooked_BattleActionModel_ResetDataWIthOutTargetData(il2cpp::Il2CppObject* __this);

// C#: System.Void AddAttackedTarget(BattleUnitModel target)
using BattleActionModelAddAttackedTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelAddAttackedTargetFn original_BattleActionModel_AddAttackedTarget = nullptr;
void hooked_BattleActionModel_AddAttackedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target);

// C#: System.Collections.Generic.List<BattleUnitModel> GetAttackedTargetList()
using BattleActionModelGetAttackedTargetListFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetAttackedTargetListFn original_BattleActionModel_GetAttackedTargetList = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetAttackedTargetList(il2cpp::Il2CppObject* __this);

// C#: System.Void CheckCoinDestroy(BattleActionModel winnerAction)
using BattleActionModelCheckCoinDestroyFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCheckCoinDestroyFn original_BattleActionModel_CheckCoinDestroy = nullptr;
void hooked_BattleActionModel_CheckCoinDestroy(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* winnerAction);

// C#: CoinModel GetHighestCoin()
using BattleActionModelGetHighestCoinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetHighestCoinFn original_BattleActionModel_GetHighestCoin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetHighestCoin(il2cpp::Il2CppObject* __this);

// C#: CoinModel GetDestroyTargetCoin()
using BattleActionModelGetDestroyTargetCoinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetDestroyTargetCoinFn original_BattleActionModel_GetDestroyTargetCoin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDestroyTargetCoin(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetSkillID()
using BattleActionModelGetSkillIDFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillIDFn original_BattleActionModel_GetSkillID = nullptr;
int32_t hooked_BattleActionModel_GetSkillID(il2cpp::Il2CppObject* __this);

// C#: SKILL_TARGET_TYPE GetSkillTargetType()
using BattleActionModelGetSkillTargetTypeFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillTargetTypeFn original_BattleActionModel_GetSkillTargetType = nullptr;
int32_t hooked_BattleActionModel_GetSkillTargetType(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetAttackWeight()
using BattleActionModelGetAttackWeightFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetAttackWeightFn original_BattleActionModel_GetAttackWeight = nullptr;
int32_t hooked_BattleActionModel_GetAttackWeight(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetOriginAttackWeight()
using BattleActionModelGetOriginAttackWeightFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetOriginAttackWeightFn original_BattleActionModel_GetOriginAttackWeight = nullptr;
int32_t hooked_BattleActionModel_GetOriginAttackWeight(il2cpp::Il2CppObject* __this);

// C#: DEFENSE_TYPE GetDefenseType()
using BattleActionModelGetDefenseTypeFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetDefenseTypeFn original_BattleActionModel_GetDefenseType = nullptr;
int32_t hooked_BattleActionModel_GetDefenseType(il2cpp::Il2CppObject* __this);

// C#: ATK_BEHAVIOUR GetSkillAtkType()
using BattleActionModelGetSkillAtkTypeFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillAtkTypeFn original_BattleActionModel_GetSkillAtkType = nullptr;
int32_t hooked_BattleActionModel_GetSkillAtkType(il2cpp::Il2CppObject* __this);

// C#: System.Boolean TryGetOverwriteAtkBehaviour(CoinModel coin, ATK_BEHAVIOUR& atkBehaviour)
using BattleActionModelTryGetOverwriteAtkBehaviourFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelTryGetOverwriteAtkBehaviourFn original_BattleActionModel_TryGetOverwriteAtkBehaviour = nullptr;
bool hooked_BattleActionModel_TryGetOverwriteAtkBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t* atkBehaviour);

// C#: System.Boolean IsSkillAtkType(ATK_BEHAVIOUR type)
using BattleActionModelIsSkillAtkTypeFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelIsSkillAtkTypeFn original_BattleActionModel_IsSkillAtkType = nullptr;
bool hooked_BattleActionModel_IsSkillAtkType(il2cpp::Il2CppObject* __this, int32_t type);

// C#: ATTRIBUTE_TYPE GetSkillAttributeType()
using BattleActionModelGetSkillAttributeTypeFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillAttributeTypeFn original_BattleActionModel_GetSkillAttributeType = nullptr;
int32_t hooked_BattleActionModel_GetSkillAttributeType(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsSkillAttributeType(ATTRIBUTE_TYPE type)
using BattleActionModelIsSkillAttributeTypeFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelIsSkillAttributeTypeFn original_BattleActionModel_IsSkillAttributeType = nullptr;
bool hooked_BattleActionModel_IsSkillAttributeType(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Boolean IsAttack()
using BattleActionModelIsAttackFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsAttackFn original_BattleActionModel_IsAttack = nullptr;
bool hooked_BattleActionModel_IsAttack(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsDefense()
using BattleActionModelIsDefenseFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsDefenseFn original_BattleActionModel_IsDefense = nullptr;
bool hooked_BattleActionModel_IsDefense(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsDefenseNotCounter()
using BattleActionModelIsDefenseNotCounterFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsDefenseNotCounterFn original_BattleActionModel_IsDefenseNotCounter = nullptr;
bool hooked_BattleActionModel_IsDefenseNotCounter(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsGuard()
using BattleActionModelIsGuardFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsGuardFn original_BattleActionModel_IsGuard = nullptr;
bool hooked_BattleActionModel_IsGuard(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsCounter()
using BattleActionModelIsCounterFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsCounterFn original_BattleActionModel_IsCounter = nullptr;
bool hooked_BattleActionModel_IsCounter(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsCanDuelDefense()
using BattleActionModelIsCanDuelDefenseFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsCanDuelDefenseFn original_BattleActionModel_IsCanDuelDefense = nullptr;
bool hooked_BattleActionModel_IsCanDuelDefense(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsEvade()
using BattleActionModelIsEvadeFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsEvadeFn original_BattleActionModel_IsEvade = nullptr;
bool hooked_BattleActionModel_IsEvade(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IgnoreDefenseSkill(BattleUnitModel target)
using BattleActionModelIgnoreDefenseSkillFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIgnoreDefenseSkillFn original_BattleActionModel_IgnoreDefenseSkill = nullptr;
bool hooked_BattleActionModel_IgnoreDefenseSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target);

// C#: System.Boolean IgnoreSupportiveDefense(BattleUnitModel originTarget, BattleUnitModel supportiveDefender)
using BattleActionModelIgnoreSupportiveDefenseFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIgnoreSupportiveDefenseFn original_BattleActionModel_IgnoreSupportiveDefense = nullptr;
bool hooked_BattleActionModel_IgnoreSupportiveDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* supportiveDefender);

// C#: System.Boolean IsActionable()
using BattleActionModelIsActionableFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsActionableFn original_BattleActionModel_IsActionable = nullptr;
bool hooked_BattleActionModel_IsActionable(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAttackCanceledByAbility(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnAttackCanceledByAbilityFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnAttackCanceledByAbilityFn original_BattleActionModel_OnAttackCanceledByAbility = nullptr;
void hooked_BattleActionModel_OnAttackCanceledByAbility(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Boolean CanBeChangedTarget(BattleActionModel oppoAction)
using BattleActionModelCanBeChangedTargetFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanBeChangedTargetFn original_BattleActionModel_CanBeChangedTarget = nullptr;
bool hooked_BattleActionModel_CanBeChangedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction);

// C#: System.Boolean CanChangeMainTargetRegardlessSpeed(BattleActionModel otherAction)
using BattleActionModelCanChangeMainTargetRegardlessSpeedFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanChangeMainTargetRegardlessSpeedFn original_BattleActionModel_CanChangeMainTargetRegardlessSpeed = nullptr;
bool hooked_BattleActionModel_CanChangeMainTargetRegardlessSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction);

// C#: System.Boolean CanBeChangedTargetIgnoreSpeed(BattleActionModel otherAction)
using BattleActionModelCanBeChangedTargetIgnoreSpeedFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanBeChangedTargetIgnoreSpeedFn original_BattleActionModel_CanBeChangedTargetIgnoreSpeed = nullptr;
bool hooked_BattleActionModel_CanBeChangedTargetIgnoreSpeed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* otherAction);

// C#: System.Void ChangeEgoSkill(System.Boolean isOverClock)
using BattleActionModelChangeEgoSkillFn = void(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelChangeEgoSkillFn original_BattleActionModel_ChangeEgoSkill = nullptr;
void hooked_BattleActionModel_ChangeEgoSkill(il2cpp::Il2CppObject* __this, bool isOverClock);

// C#: System.Boolean TryChangeSkill(System.Int32 skillID)
using BattleActionModelTryChangeSkillFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelTryChangeSkillFn original_BattleActionModel_TryChangeSkill = nullptr;
bool hooked_BattleActionModel_TryChangeSkill(il2cpp::Il2CppObject* __this, int32_t skillID);

// C#: System.Boolean ChangeSkill(SkillModel skill, System.Boolean saveOriginSkill)
using BattleActionModelChangeSkillFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelChangeSkillFn original_BattleActionModel_ChangeSkill = nullptr;
bool hooked_BattleActionModel_ChangeSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* skill, bool saveOriginSkill);

// C#: System.Void ReturnPreviousSkill()
using BattleActionModelReturnPreviousSkillFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelReturnPreviousSkillFn original_BattleActionModel_ReturnPreviousSkill = nullptr;
void hooked_BattleActionModel_ReturnPreviousSkill(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetResonanceIndexOrStack()
using BattleActionModelGetResonanceIndexOrStackFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetResonanceIndexOrStackFn original_BattleActionModel_GetResonanceIndexOrStack = nullptr;
int32_t hooked_BattleActionModel_GetResonanceIndexOrStack(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetExpectedResonanceIndexOrStack()
using BattleActionModelGetExpectedResonanceIndexOrStack_P0Fn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedResonanceIndexOrStack_P0Fn original_BattleActionModel_GetExpectedResonanceIndexOrStack_P0 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P0(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetExpectedResonanceIndexOrStack(System.Collections.Generic.List<System.Int32> indexes)
using BattleActionModelGetExpectedResonanceIndexOrStack_P1Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedResonanceIndexOrStack_P1Fn original_BattleActionModel_GetExpectedResonanceIndexOrStack_P1 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedResonanceIndexOrStack_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* indexes);

// C#: System.Int32 GetAttributeResonanceIndex()
using BattleActionModelGetAttributeResonanceIndexFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetAttributeResonanceIndexFn original_BattleActionModel_GetAttributeResonanceIndex = nullptr;
int32_t hooked_BattleActionModel_GetAttributeResonanceIndex(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetPerfectResonanceStack()
using BattleActionModelGetPerfectResonanceStackFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetPerfectResonanceStackFn original_BattleActionModel_GetPerfectResonanceStack = nullptr;
int32_t hooked_BattleActionModel_GetPerfectResonanceStack(il2cpp::Il2CppObject* __this);

// C#: System.Void CheckResonancePassive()
using BattleActionModelCheckResonancePassiveFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCheckResonancePassiveFn original_BattleActionModel_CheckResonancePassive = nullptr;
void hooked_BattleActionModel_CheckResonancePassive(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAttributeResonance()
using BattleActionModelOnAttributeResonanceFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelOnAttributeResonanceFn original_BattleActionModel_OnAttributeResonance = nullptr;
void hooked_BattleActionModel_OnAttributeResonance(il2cpp::Il2CppObject* __this);

// C#: System.Boolean HasCommander(System.Int32& commander)
using BattleActionModelHasCommanderFn = bool(*)(il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelHasCommanderFn original_BattleActionModel_HasCommander = nullptr;
bool hooked_BattleActionModel_HasCommander(il2cpp::Il2CppObject* __this, int32_t* commander);

// C#: System.Void SetDefenseLevel_After_UseSkill()
using BattleActionModelSetDefenseLevel_After_UseSkillFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelSetDefenseLevel_After_UseSkillFn original_BattleActionModel_SetDefenseLevel_After_UseSkill = nullptr;
void hooked_BattleActionModel_SetDefenseLevel_After_UseSkill(il2cpp::Il2CppObject* __this);

// C#: System.Void ModifySpeedByParrying(System.Int32 speed)
using BattleActionModelModifySpeedByParryingFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelModifySpeedByParryingFn original_BattleActionModel_ModifySpeedByParrying = nullptr;
void hooked_BattleActionModel_ModifySpeedByParrying(il2cpp::Il2CppObject* __this, int32_t speed);

// C#: System.Void ResetSpeedByParrying()
using BattleActionModelResetSpeedByParryingFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelResetSpeedByParryingFn original_BattleActionModel_ResetSpeedByParrying = nullptr;
void hooked_BattleActionModel_ResetSpeedByParrying(il2cpp::Il2CppObject* __this);

// C#: System.Int32 RollSkillPower(CoinModel coin, OneCoinLog oneCoinLog, System.Int32 idx, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, System.Nullable<System.Boolean> isWinDuel, System.Boolean calculateSystemAdder)
using BattleActionModelRollSkillPowerFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelRollSkillPowerFn original_BattleActionModel_RollSkillPower = nullptr;
int32_t hooked_BattleActionModel_RollSkillPower(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oneCoinLog, int32_t idx, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* isWinDuel, bool calculateSystemAdder);

// C#: ParryingData RollSkillPowerParrying(BattleActionModel oppoAction, BattleLog_Parrying parryingLog, ParryingStatus parryingStatus)
using BattleActionModelRollSkillPowerParryingFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelRollSkillPowerParryingFn original_BattleActionModel_RollSkillPowerParrying = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_RollSkillPowerParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction, il2cpp::Il2CppObject* parryingLog, il2cpp::Il2CppObject* parryingStatus);

// C#: SkillPowerData CreateSkillPowerData(System.Boolean isValid, BATTLE_EVENT_TIMING timing, COIN_ROLL_TYPE rollType, BattleActionModel attackerActionOrNull, CoinModel coinOrNull)
using BattleActionModelCreateSkillPowerDataFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, bool, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCreateSkillPowerDataFn original_BattleActionModel_CreateSkillPowerData = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_CreateSkillPowerData(il2cpp::Il2CppObject* __this, bool isValid, int32_t timing, int32_t rollType, il2cpp::Il2CppObject* attackerActionOrNull, il2cpp::Il2CppObject* coinOrNull);

// C#: ParryingData CreateParryingData(System.Boolean isValid)
using BattleActionModelCreateParryingDataFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelCreateParryingDataFn original_BattleActionModel_CreateParryingData = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_CreateParryingData(il2cpp::Il2CppObject* __this, bool isValid);

// C#: System.Boolean CanRollAllCoinForUI(System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs)
using BattleActionModelCanRollAllCoinForUIFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject**);
inline BattleActionModelCanRollAllCoinForUIFn original_BattleActionModel_CanRollAllCoinForUI = nullptr;
bool hooked_BattleActionModel_CanRollAllCoinForUI(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject** lackOfBuffs);

// C#: System.Boolean IsRetreatSkill()
using BattleActionModelIsRetreatSkillFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsRetreatSkillFn original_BattleActionModel_IsRetreatSkill = nullptr;
bool hooked_BattleActionModel_IsRetreatSkill(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsCommandRetreatSkill()
using BattleActionModelIsCommandRetreatSkillFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsCommandRetreatSkillFn original_BattleActionModel_IsCommandRetreatSkill = nullptr;
bool hooked_BattleActionModel_IsCommandRetreatSkill(il2cpp::Il2CppObject* __this);

// C#: System.Boolean CanRollCoin(CoinModel coin, System.Collections.Generic.List<BUFF_UNIQUE_KEYWORD>& lackOfBuffs, System.Boolean& forceToEndSkill)
using BattleActionModelCanRollCoinFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject**, bool*);
inline BattleActionModelCanRollCoinFn original_BattleActionModel_CanRollCoin = nullptr;
bool hooked_BattleActionModel_CanRollCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** lackOfBuffs, bool* forceToEndSkill);

// C#: System.Void Behave(BattleRunLog runLog, BattleLog actionLog, BattleActionModel attackerActionOrNull, System.Boolean isLoserAttackExpected, BattleActionModel loserActionOrNull)
using BattleActionModelBehaveFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*);
inline BattleActionModelBehaveFn original_BattleActionModel_Behave = nullptr;
void hooked_BattleActionModel_Behave(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull, bool isLoserAttackExpected, il2cpp::Il2CppObject* loserActionOrNull);

// C#: System.Boolean BeforeCompleteCommand(BATTLE_EVENT_TIMING timing, System.Int32& newSkillID)
using BattleActionModelBeforeCompleteCommandFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t*);
inline BattleActionModelBeforeCompleteCommandFn original_BattleActionModel_BeforeCompleteCommand = nullptr;
bool hooked_BattleActionModel_BeforeCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing, int32_t* newSkillID);

// C#: System.Void OnChangeSkillBeforeCompleteCommand(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnChangeSkillBeforeCompleteCommandFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnChangeSkillBeforeCompleteCommandFn original_BattleActionModel_OnChangeSkillBeforeCompleteCommand = nullptr;
void hooked_BattleActionModel_OnChangeSkillBeforeCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void ActivateGuard(BattleRunLog runLog, BattleLog_Guard actionLog, BattleActionModel attackerActionOrNull)
using BattleActionModelActivateGuardFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelActivateGuardFn original_BattleActionModel_ActivateGuard = nullptr;
void hooked_BattleActionModel_ActivateGuard(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, il2cpp::Il2CppObject* actionLog, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Void CheckOneOnOneDuelState()
using BattleActionModelCheckOneOnOneDuelStateFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCheckOneOnOneDuelStateFn original_BattleActionModel_CheckOneOnOneDuelState = nullptr;
void hooked_BattleActionModel_CheckOneOnOneDuelState(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsOneOnOneDuel(BattleActionModel opponentAction)
using BattleActionModelIsOneOnOneDuelFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsOneOnOneDuelFn original_BattleActionModel_IsOneOnOneDuel = nullptr;
bool hooked_BattleActionModel_IsOneOnOneDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction);

// C#: System.Void OnCompleteCommand(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnCompleteCommandFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnCompleteCommandFn original_BattleActionModel_OnCompleteCommand = nullptr;
void hooked_BattleActionModel_OnCompleteCommand(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnBattleStart(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnBattleStartFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnBattleStartFn original_BattleActionModel_OnBattleStart = nullptr;
void hooked_BattleActionModel_OnBattleStart(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Boolean CanAttackTargets()
using BattleActionModelCanAttackTargetsFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCanAttackTargetsFn original_BattleActionModel_CanAttackTargets = nullptr;
bool hooked_BattleActionModel_CanAttackTargets(il2cpp::Il2CppObject* __this);

// C#: System.Boolean CheckTargetableTarget()
using BattleActionModelCheckTargetableTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCheckTargetableTargetFn original_BattleActionModel_CheckTargetableTarget = nullptr;
bool hooked_BattleActionModel_CheckTargetableTarget(il2cpp::Il2CppObject* __this);

// C#: System.Void OnEndBehave_Refresh(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnEndBehave_RefreshFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnEndBehave_RefreshFn original_BattleActionModel_OnEndBehave_Refresh = nullptr;
void hooked_BattleActionModel_OnEndBehave_Refresh(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void AffectToReturnUnit(System.Collections.Generic.List<OnReleaseStandByOrOnReturnData> list)
using BattleActionModelAffectToReturnUnitFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelAffectToReturnUnitFn original_BattleActionModel_AffectToReturnUnit = nullptr;
void hooked_BattleActionModel_AffectToReturnUnit(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* list);

// C#: System.Void CallTargetDefenseActionsByAttack(BattleRunLog runLog, DEFENSE_TYPE type, System.Boolean isDuelExpected, System.Boolean canDuel, BATTLE_EVENT_TIMING timing, OneCoinLog_Attack oneCoinLog, BattleUnitModel specificTarget, System.Boolean mainTargetExclusive)
using BattleActionModelCallTargetDefenseActionsByAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool, bool, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelCallTargetDefenseActionsByAttackFn original_BattleActionModel_CallTargetDefenseActionsByAttack = nullptr;
void hooked_BattleActionModel_CallTargetDefenseActionsByAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, int32_t type, bool isDuelExpected, bool canDuel, int32_t timing, il2cpp::Il2CppObject* oneCoinLog, il2cpp::Il2CppObject* specificTarget, bool mainTargetExclusive);

// C#: System.Void OnRoundStart_After()
using BattleActionModelOnRoundStart_AfterFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelOnRoundStart_AfterFn original_BattleActionModel_OnRoundStart_After = nullptr;
void hooked_BattleActionModel_OnRoundStart_After(il2cpp::Il2CppObject* __this);

// C#: System.Void OnBeforeTurn(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnBeforeTurnFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnBeforeTurnFn original_BattleActionModel_OnBeforeTurn = nullptr;
void hooked_BattleActionModel_OnBeforeTurn(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnCancelAction()
using BattleActionModelOnCancelActionFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelOnCancelActionFn original_BattleActionModel_OnCancelAction = nullptr;
void hooked_BattleActionModel_OnCancelAction(il2cpp::Il2CppObject* __this);

// C#: System.Void OnBeforeDefense(BattleActionModel attackerActionOrNull)
using BattleActionModelOnBeforeDefenseFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnBeforeDefenseFn original_BattleActionModel_OnBeforeDefense = nullptr;
void hooked_BattleActionModel_OnBeforeDefense(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Void OnStartTurn_BeforeLog(BATTLE_EVENT_TIMING timing, System.Boolean isDuelExpected)
using BattleActionModelOnStartTurn_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, int32_t, bool);
inline BattleActionModelOnStartTurn_BeforeLogFn original_BattleActionModel_OnStartTurn_BeforeLog = nullptr;
void hooked_BattleActionModel_OnStartTurn_BeforeLog(il2cpp::Il2CppObject* __this, int32_t timing, bool isDuelExpected);

// C#: System.Void OnStartTurn_AfterLog(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnStartTurn_AfterLogFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnStartTurn_AfterLogFn original_BattleActionModel_OnStartTurn_AfterLog = nullptr;
void hooked_BattleActionModel_OnStartTurn_AfterLog(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnTryEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnTryEvadeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnTryEvadeFn original_BattleActionModel_OnTryEvade = nullptr;
void hooked_BattleActionModel_OnTryEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing);

// C#: System.Void OnStartDuel(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnStartDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnStartDuelFn original_BattleActionModel_OnStartDuel = nullptr;
void hooked_BattleActionModel_OnStartDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing);

// C#: System.Void OnBeforeParryingOnce(BattleActionModel oppoAction)
using BattleActionModelOnBeforeParryingOnceFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnBeforeParryingOnceFn original_BattleActionModel_OnBeforeParryingOnce = nullptr;
void hooked_BattleActionModel_OnBeforeParryingOnce(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction);

// C#: System.Void OnBeforeParryingOnce_AfterLog(BattleActionModel oppoAction)
using BattleActionModelOnBeforeParryingOnce_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnBeforeParryingOnce_AfterLogFn original_BattleActionModel_OnBeforeParryingOnce_AfterLog = nullptr;
void hooked_BattleActionModel_OnBeforeParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction);

// C#: System.Void OnDuelAfter_BeforeLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 parryingCount, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
using BattleActionModelOnDuelAfter_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelOnDuelAfter_BeforeLogFn original_BattleActionModel_OnDuelAfter_BeforeLog = nullptr;
void hooked_BattleActionModel_OnDuelAfter_BeforeLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t parryingCount, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

// C#: System.Void OnDuelAfter_AfterLog(PARRYING_RESULT result, BattleActionModel oppoAction, System.Int32 selfRemainedCoin, System.Int32 oppoRemainedCoin, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnDuelAfter_AfterLogFn = void(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline BattleActionModelOnDuelAfter_AfterLogFn original_BattleActionModel_OnDuelAfter_AfterLog = nullptr;
void hooked_BattleActionModel_OnDuelAfter_AfterLog(il2cpp::Il2CppObject* __this, int32_t result, il2cpp::Il2CppObject* oppoAction, int32_t selfRemainedCoin, int32_t oppoRemainedCoin, int32_t timing);

// C#: System.Void OnAfterParryingOnce_BeforeLog(BattleActionModel opponentAction, PARRYING_RESULT reuslt, System.Int32 parryingCnt, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnAfterParryingOnce_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline BattleActionModelOnAfterParryingOnce_BeforeLogFn original_BattleActionModel_OnAfterParryingOnce_BeforeLog = nullptr;
void hooked_BattleActionModel_OnAfterParryingOnce_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t reuslt, int32_t parryingCnt, int32_t timing);

// C#: System.Void OnAfterParryingOnce_AfterLog(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
using BattleActionModelOnAfterParryingOnce_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelOnAfterParryingOnce_AfterLogFn original_BattleActionModel_OnAfterParryingOnce_AfterLog = nullptr;
void hooked_BattleActionModel_OnAfterParryingOnce_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

// C#: System.Void OnWinParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnWinParryingFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnWinParryingFn original_BattleActionModel_OnWinParrying = nullptr;
void hooked_BattleActionModel_OnWinParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing);

// C#: System.Void OnLoseParrying(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnLoseParryingFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnLoseParryingFn original_BattleActionModel_OnLoseParrying = nullptr;
void hooked_BattleActionModel_OnLoseParrying(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing);

// C#: System.Void OnWinDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLogOrNull)
using BattleActionModelOnWinDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelOnWinDuelFn original_BattleActionModel_OnWinDuel = nullptr;
void hooked_BattleActionModel_OnWinDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing, il2cpp::Il2CppObject* lastLogOrNull);

// C#: System.Void CheckExtractAbility(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelCheckExtractAbilityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelCheckExtractAbilityFn original_BattleActionModel_CheckExtractAbility = nullptr;
void hooked_BattleActionModel_CheckExtractAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing);

// C#: System.Void FirstBsGaugeUpWithDuelableGuard(BattleActionModel opponentAction, BATTLE_EVENT_TIMING timing, BattleLog_Parrying lastLog)
using BattleActionModelFirstBsGaugeUpWithDuelableGuardFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelFirstBsGaugeUpWithDuelableGuardFn original_BattleActionModel_FirstBsGaugeUpWithDuelableGuard = nullptr;
void hooked_BattleActionModel_FirstBsGaugeUpWithDuelableGuard(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t timing, il2cpp::Il2CppObject* lastLog);

// C#: System.Void OnLoseDuel(BattleActionModel opponentAction, System.Int32 parryingCount, System.Int32 remainedOwenrCoin, System.Int32 remainedOpponentCoin, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnLoseDuelFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline BattleActionModelOnLoseDuelFn original_BattleActionModel_OnLoseDuel = nullptr;
void hooked_BattleActionModel_OnLoseDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction, int32_t parryingCount, int32_t remainedOwenrCoin, int32_t remainedOpponentCoin, int32_t timing);

// C#: System.Void BeforeBehaviour(BATTLE_EVENT_TIMING timing)
using BattleActionModelBeforeBehaviourFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelBeforeBehaviourFn original_BattleActionModel_BeforeBehaviour = nullptr;
void hooked_BattleActionModel_BeforeBehaviour(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnStartBehaviour(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnStartBehaviourFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnStartBehaviourFn original_BattleActionModel_OnStartBehaviour = nullptr;
void hooked_BattleActionModel_OnStartBehaviour(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnCriticalIsActivated(CoinModel coin, BATTLE_EVENT_TIMING timing, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single> affectKeywords)
using BattleActionModelOnCriticalIsActivatedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelOnCriticalIsActivatedFn original_BattleActionModel_OnCriticalIsActivated = nullptr;
void hooked_BattleActionModel_OnCriticalIsActivated(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t timing, il2cpp::Il2CppObject* affectKeywords);

// C#: System.Void OnAttackConfirmed(CoinModel coin, BattleUnitModel target, BATTLE_EVENT_TIMING timing, System.Boolean isCritical)
using BattleActionModelOnAttackConfirmedFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool);
inline BattleActionModelOnAttackConfirmedFn original_BattleActionModel_OnAttackConfirmed = nullptr;
void hooked_BattleActionModel_OnAttackConfirmed(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t timing, bool isCritical);

// C#: System.Void BeforeGiveAttackDamage(CoinModel coin, BattleUnitModel target, System.Nullable<System.Boolean> isWinDuel, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using BattleActionModelBeforeGiveAttackDamageFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelBeforeGiveAttackDamageFn original_BattleActionModel_BeforeGiveAttackDamage = nullptr;
void hooked_BattleActionModel_BeforeGiveAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* isWinDuel, bool isCritical, int32_t timing);

// C#: System.Void OnSucceedAttack(CoinModel coin, BattleUnitModel target, System.Int32 finalDmg, System.Int32 realDmg, System.Int32 realHpDmg, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnSucceedAttackFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, bool, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnSucceedAttackFn original_BattleActionModel_OnSucceedAttack = nullptr;
void hooked_BattleActionModel_OnSucceedAttack(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t finalDmg, int32_t realDmg, int32_t realHpDmg, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Boolean CanGiveConcentratedAttack()
using BattleActionModelCanGiveConcentratedAttackFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCanGiveConcentratedAttackFn original_BattleActionModel_CanGiveConcentratedAttack = nullptr;
bool hooked_BattleActionModel_CanGiveConcentratedAttack(il2cpp::Il2CppObject* __this);

// C#: System.Void OnSucceedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnSucceedEvadeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnSucceedEvadeFn original_BattleActionModel_OnSucceedEvade = nullptr;
void hooked_BattleActionModel_OnSucceedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing);

// C#: System.Void OnFailedEvade(BattleActionModel attackerAction, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnFailedEvadeFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnFailedEvadeFn original_BattleActionModel_OnFailedEvade = nullptr;
void hooked_BattleActionModel_OnFailedEvade(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerAction, int32_t timing);

// C#: System.Void OnStartCoin(CoinModel coin, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnStartCoinFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnStartCoinFn original_BattleActionModel_OnStartCoin = nullptr;
void hooked_BattleActionModel_OnStartCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t timing);

// C#: System.Void OnEndCoin_BeforeLog(CoinModel coin, System.Boolean isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnEndCoin_BeforeLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnEndCoin_BeforeLogFn original_BattleActionModel_OnEndCoin_BeforeLog = nullptr;
void hooked_BattleActionModel_OnEndCoin_BeforeLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Void OnEndCoin_AfterLog(CoinModel coin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnEndCoin_AfterLogFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelOnEndCoin_AfterLogFn original_BattleActionModel_OnEndCoin_AfterLog = nullptr;
void hooked_BattleActionModel_OnEndCoin_AfterLog(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isCritical, int32_t timing);

// C#: System.Void OnEndAttack(System.Int32 accumulatedDmg, System.Int32 accumulatedHpDmg, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing, BattleLog_Duel duelLogOrNull)
using BattleActionModelOnEndAttackFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelOnEndAttackFn original_BattleActionModel_OnEndAttack = nullptr;
void hooked_BattleActionModel_OnEndAttack(il2cpp::Il2CppObject* __this, int32_t accumulatedDmg, int32_t accumulatedHpDmg, il2cpp::Il2CppObject* isWinDuel, int32_t timing, il2cpp::Il2CppObject* duelLogOrNull);

// C#: System.Void OnEndBehaviour(BattleRunLog runLog, BATTLE_EVENT_TIMING timing, System.Boolean isLoserAttackExpected)
using BattleActionModelOnEndBehaviourFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool);
inline BattleActionModelOnEndBehaviourFn original_BattleActionModel_OnEndBehaviour = nullptr;
void hooked_BattleActionModel_OnEndBehaviour(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* runLog, int32_t timing, bool isLoserAttackExpected);

// C#: System.Void OnGiveBsGaugeUp(CoinModel coinOrNull, BattleUnitModel target, System.Int32 value, BATTLE_EVENT_TIMING timing, System.Boolean onExplosion)
using BattleActionModelOnGiveBsGaugeUpFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, bool);
inline BattleActionModelOnGiveBsGaugeUpFn original_BattleActionModel_OnGiveBsGaugeUp = nullptr;
void hooked_BattleActionModel_OnGiveBsGaugeUp(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* target, int32_t value, int32_t timing, bool onExplosion);

// C#: System.Void OnEndTurn(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnEndTurnFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnEndTurnFn original_BattleActionModel_OnEndTurn = nullptr;
void hooked_BattleActionModel_OnEndTurn(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnDiscarded(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnDiscardedFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnDiscardedFn original_BattleActionModel_OnDiscarded = nullptr;
void hooked_BattleActionModel_OnDiscarded(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnKillTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnKillTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelOnKillTargetFn original_BattleActionModel_OnKillTarget = nullptr;
void hooked_BattleActionModel_OnKillTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

// C#: System.Void OnBreakTarget(BattleUnitModel target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnBreakTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelOnBreakTargetFn original_BattleActionModel_OnBreakTarget = nullptr;
void hooked_BattleActionModel_OnBreakTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

// C#: System.Void OnDestroyTargetPart(BattleUnitModel_Abnormality_Part target, CoinModel coinOrNull, DAMAGE_SOURCE_TYPE dmgSrcType, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnDestroyTargetPartFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelOnDestroyTargetPartFn original_BattleActionModel_OnDestroyTargetPart = nullptr;
void hooked_BattleActionModel_OnDestroyTargetPart(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull, int32_t dmgSrcType, int32_t timing);

// C#: System.Void Done()
using BattleActionModelDoneFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelDoneFn original_BattleActionModel_Done = nullptr;
void hooked_BattleActionModel_Done(il2cpp::Il2CppObject* __this);

// C#: System.Void DoneWithAction(BATTLE_EVENT_TIMING timing)
using BattleActionModelDoneWithActionFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelDoneWithActionFn original_BattleActionModel_DoneWithAction = nullptr;
void hooked_BattleActionModel_DoneWithAction(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void AddSinStock()
using BattleActionModelAddSinStockFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelAddSinStockFn original_BattleActionModel_AddSinStock = nullptr;
void hooked_BattleActionModel_AddSinStock(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetExpectedMinCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
using BattleActionModelGetExpectedMinCoinValue_P2_1Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelGetExpectedMinCoinValue_P2_1Fn original_BattleActionModel_GetExpectedMinCoinValue_P2_1 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedMinCoinValue_P2_1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder);

// C#: System.Int32 GetExpectedMaxCoinValue(SinActionModel oppoSinActionOrNull, System.Int32& adder)
using BattleActionModelGetExpectedMaxCoinValue_P2_1Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelGetExpectedMaxCoinValue_P2_1Fn original_BattleActionModel_GetExpectedMaxCoinValue_P2_1 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, int32_t* adder);

// C#: System.Int32 GetExpectedMinCoinValue(UnitSinModel oppoSin, System.Int32& adder)
using BattleActionModelGetExpectedMinCoinValue_P2_2Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelGetExpectedMinCoinValue_P2_2Fn original_BattleActionModel_GetExpectedMinCoinValue_P2_2 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedMinCoinValue_P2_2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSin, int32_t* adder);

// C#: System.Int32 GetExpectedMaxCoinValue(UnitSinModel oppoSin, System.Int32& adder)
using BattleActionModelGetExpectedMaxCoinValue_P2_2Fn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*);
inline BattleActionModelGetExpectedMaxCoinValue_P2_2Fn original_BattleActionModel_GetExpectedMaxCoinValue_P2_2 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedMaxCoinValue_P2_2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSin, int32_t* adder);

// C#: System.Int32 GetExpectedCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
using BattleActionModelGetExpectedCalculationFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t*);
inline BattleActionModelGetExpectedCalculationFn original_BattleActionModel_GetExpectedCalculation = nullptr;
int32_t hooked_BattleActionModel_GetExpectedCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder);

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamage()
using BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageFn original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage = nullptr;
int32_t hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamage(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(SinActionModel targetSinActionOrNull, BattleActionModel targetActionOrNull)
using BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageByTargetFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedRateOfIncreaseAndDecreaseDamageByTargetFn original_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget = nullptr;
int32_t hooked_BattleActionModel_GetExpectedRateOfIncreaseAndDecreaseDamageByTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionOrNull);

// C#: System.Int32 GetExpectedDamage(CalculationType type, System.Collections.Generic.List<System.Int32> indexes, SinActionModel targetSinActionOrNull, BattleActionModel oppoActionOrNull)
using BattleActionModelGetExpectedDamageFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedDamageFn original_BattleActionModel_GetExpectedDamage = nullptr;
int32_t hooked_BattleActionModel_GetExpectedDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull);

// C#: System.Int32 GetExpectedDamageByTarget(CalculationType type, SinActionModel targetSinAction, BattleActionModel targetActionOrNull, System.Collections.Generic.List<System.Int32> indexes)
using BattleActionModelGetExpectedDamageByTargetFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedDamageByTargetFn original_BattleActionModel_GetExpectedDamageByTarget = nullptr;
int32_t hooked_BattleActionModel_GetExpectedDamageByTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* type, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* targetActionOrNull, il2cpp::Il2CppObject* indexes);

// C#: System.Boolean IsDuelExpcted(BattleActionModel oppoAction)
using BattleActionModelIsDuelExpctedFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsDuelExpctedFn original_BattleActionModel_IsDuelExpcted = nullptr;
bool hooked_BattleActionModel_IsDuelExpcted(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoAction);

// C#: System.Int32 GetParryingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Int32& adder)
using BattleActionModelGetParryingCalculationFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t*);
inline BattleActionModelGetParryingCalculationFn original_BattleActionModel_GetParryingCalculation = nullptr;
int32_t hooked_BattleActionModel_GetParryingCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, int32_t* adder);

// C#: System.Int32 GetDamageCalculation(SinActionModel targetSinActionOrNull, BattleActionModel targetActionModelOrNull, System.Boolean isMin, System.Int32& adder)
using BattleActionModelGetDamageCalculationFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, int32_t*);
inline BattleActionModelGetDamageCalculationFn original_BattleActionModel_GetDamageCalculation = nullptr;
int32_t hooked_BattleActionModel_GetDamageCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionOrNull, il2cpp::Il2CppObject* targetActionModelOrNull, bool isMin, int32_t* adder);

// C#: System.Int32 GetSnowBallingCalculation(SinActionModel oppoSinActionOrNull, BattleActionModel oppoActionOrNull, System.Boolean isMin, System.Boolean isOpponentEvade, System.Int32& adder)
using BattleActionModelGetSnowBallingCalculationFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, bool, int32_t*);
inline BattleActionModelGetSnowBallingCalculationFn original_BattleActionModel_GetSnowBallingCalculation = nullptr;
int32_t hooked_BattleActionModel_GetSnowBallingCalculation(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull, bool isMin, bool isOpponentEvade, int32_t* adder);

// C#: System.Int32 GetDefaultAllCoinCalculation(System.Boolean isMin, System.Boolean isParrying, System.Boolean isOpponentEvade)
using BattleActionModelGetDefaultAllCoinCalculationFn = int32_t(*)(il2cpp::Il2CppObject*, bool, bool, bool);
inline BattleActionModelGetDefaultAllCoinCalculationFn original_BattleActionModel_GetDefaultAllCoinCalculation = nullptr;
int32_t hooked_BattleActionModel_GetDefaultAllCoinCalculation(il2cpp::Il2CppObject* __this, bool isMin, bool isParrying, bool isOpponentEvade);

// C#: System.Int32 GetParryingAdder(BattleActionModel oppoActionOrNull)
using BattleActionModelGetParryingAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetParryingAdderFn original_BattleActionModel_GetParryingAdder = nullptr;
int32_t hooked_BattleActionModel_GetParryingAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* oppoActionOrNull);

// C#: System.Int32 GetMinExpectedDamage(SinActionModel targetSinAction, System.Collections.Generic.List<System.Int32> selectedIndexes)
using BattleActionModelGetMinExpectedDamageFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetMinExpectedDamageFn original_BattleActionModel_GetMinExpectedDamage = nullptr;
int32_t hooked_BattleActionModel_GetMinExpectedDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinAction, il2cpp::Il2CppObject* selectedIndexes);

// C#: System.Single GetCriticalChance(CoinModel coin, System.Collections.Generic.Dictionary<BUFF_UNIQUE_KEYWORD,System.Single>& affectKeywords)
using BattleActionModelGetCriticalChanceFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject**);
inline BattleActionModelGetCriticalChanceFn original_BattleActionModel_GetCriticalChance = nullptr;
float hooked_BattleActionModel_GetCriticalChance(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject** affectKeywords);

// C#: System.Boolean CanTeamKill()
using BattleActionModelCanTeamKillFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelCanTeamKillFn original_BattleActionModel_CanTeamKill = nullptr;
bool hooked_BattleActionModel_CanTeamKill(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetSkillLevel(System.Int32 resonanceIndex, System.Int32& allCorrectionValue, System.Int32& effectCorrectionValue)
using BattleActionModelGetSkillLevelFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, int32_t*, int32_t*);
inline BattleActionModelGetSkillLevelFn original_BattleActionModel_GetSkillLevel = nullptr;
int32_t hooked_BattleActionModel_GetSkillLevel(il2cpp::Il2CppObject* __this, int32_t resonanceIndex, int32_t* allCorrectionValue, int32_t* effectCorrectionValue);

// C#: System.Int32 GetSkillPower(COIN_ROLL_TYPE rollType, BATTLE_EVENT_TIMING timing, System.Collections.Generic.List<CoinModel> coinList, BattleActionModel attackerActionOrNull)
using BattleActionModelGetSkillPowerFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillPowerFn original_BattleActionModel_GetSkillPower = nullptr;
int32_t hooked_BattleActionModel_GetSkillPower(il2cpp::Il2CppObject* __this, int32_t rollType, int32_t timing, il2cpp::Il2CppObject* coinList, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull, BattleActionModel attackerActionOrNull)
using BattleActionModelGetExpectedSkillPower_P3_1Fn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedSkillPower_P3_1Fn original_BattleActionModel_GetExpectedSkillPower_P3_1 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedSkillPower_P3_1(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Int32 GetExpectedSkillPower(COIN_ROLL_TYPE rollType, System.Collections.Generic.List<System.Int32> indexes, SinActionModel expectedTargetSinActionOrNull)
using BattleActionModelGetExpectedSkillPower_P3_2Fn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedSkillPower_P3_2Fn original_BattleActionModel_GetExpectedSkillPower_P3_2 = nullptr;
int32_t hooked_BattleActionModel_GetExpectedSkillPower_P3_2(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

// C#: System.Int32 GetCoinScale(CoinModel coin, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
using BattleActionModelGetCoinScaleFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetCoinScaleFn original_BattleActionModel_GetCoinScale = nullptr;
int32_t hooked_BattleActionModel_GetCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Nullable<System.Int32> OverrideCoinScale(CoinModel coin, System.Int32 originScaleAdder)
using BattleActionModelOverrideCoinScaleFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOverrideCoinScaleFn original_BattleActionModel_OverrideCoinScale = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_OverrideCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t originScaleAdder);

// C#: System.Int32 GetExpectedCoinScale(CoinModel coin, COIN_ROLL_TYPE rollType, System.Boolean includeAdder, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
using BattleActionModelGetExpectedCoinScaleFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedCoinScaleFn original_BattleActionModel_GetExpectedCoinScale = nullptr;
int32_t hooked_BattleActionModel_GetExpectedCoinScale(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t rollType, bool includeAdder, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

// C#: System.Int32 GetAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
using BattleActionModelGetAttackHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*);
inline BattleActionModelGetAttackHpDmgAdderFn original_BattleActionModel_GetAttackHpDmgAdder = nullptr;
int32_t hooked_BattleActionModel_GetAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target);

// C#: System.Int32 GetExpectedAttackHpDmgAdder(CoinModel coin, System.Boolean isWinDuel, BattleUnitModel target)
using BattleActionModelGetExpectedAttackHpDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedAttackHpDmgAdderFn original_BattleActionModel_GetExpectedAttackHpDmgAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedAttackHpDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool isWinDuel, il2cpp::Il2CppObject* target);

// C#: System.Int32 GetCoinScaleAdder(CoinModel coin, BattleActionModel oppoActionOrNull, BattleActionModel attackerActionOrNull)
using BattleActionModelGetCoinScaleAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetCoinScaleAdderFn original_BattleActionModel_GetCoinScaleAdder = nullptr;
int32_t hooked_BattleActionModel_GetCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* attackerActionOrNull);

// C#: System.Int32 GetExpectedCoinScaleAdder(CoinModel coin, COIN_ROLL_TYPE rollType, BattleActionModel oppoActionOrNull, SinActionModel targetSinActionOrNull)
using BattleActionModelGetExpectedCoinScaleAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedCoinScaleAdderFn original_BattleActionModel_GetExpectedCoinScaleAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedCoinScaleAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t rollType, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

// C#: System.Int32 GetSkillPowerResultAdder(BATTLE_EVENT_TIMING timing, BattleActionModel attackerActionOrNull, System.Boolean calculateSystemAdder, CoinModel coinOrNull)
using BattleActionModelGetSkillPowerResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*);
inline BattleActionModelGetSkillPowerResultAdderFn original_BattleActionModel_GetSkillPowerResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetSkillPowerResultAdder(il2cpp::Il2CppObject* __this, int32_t timing, il2cpp::Il2CppObject* attackerActionOrNull, bool calculateSystemAdder, il2cpp::Il2CppObject* coinOrNull);

// C#: System.Int32 GetExpectedSkillPowerAdder(COIN_ROLL_TYPE rollType, SinActionModel expectedTargetSinActionOrNull)
using BattleActionModelGetExpectedSkillPowerAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedSkillPowerAdderFn original_BattleActionModel_GetExpectedSkillPowerAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedSkillPowerAdder(il2cpp::Il2CppObject* __this, int32_t rollType, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);

// C#: System.Int32 GetExpectedSkillPowerResultAdder(System.Collections.Generic.List<System.Int32> indexes, SinActionModel opppoSinActionOrNull, BattleActionModel oppoActionOrNull)
using BattleActionModelGetExpectedSkillPowerResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedSkillPowerResultAdderFn original_BattleActionModel_GetExpectedSkillPowerResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedSkillPowerResultAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* indexes, il2cpp::Il2CppObject* opppoSinActionOrNull, il2cpp::Il2CppObject* oppoActionOrNull);

// C#: System.Single GetAttackDmgMultiplier(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel, System.Boolean isCritical, System.Boolean isOneSideAttack, OneCoinLog_Attack forEditorItCanBeNull)
using BattleActionModelGetAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, bool, bool, il2cpp::Il2CppObject*);
inline BattleActionModelGetAttackDmgMultiplierFn original_BattleActionModel_GetAttackDmgMultiplier = nullptr;
float hooked_BattleActionModel_GetAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical, bool isOneSideAttack, il2cpp::Il2CppObject* forEditorItCanBeNull);

// C#: System.Single GetExpectedAttackDmgMultiplier(CoinModel coin, BattleUnitModel targetOrNull, SinActionModel targetSinActionOrNull)
using BattleActionModelGetExpectedAttackDmgMultiplierFn = float(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedAttackDmgMultiplierFn original_BattleActionModel_GetExpectedAttackDmgMultiplier = nullptr;
float hooked_BattleActionModel_GetExpectedAttackDmgMultiplier(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);

// C#: System.Int32 GetAttackDmgAdder(CoinModel coin, BattleUnitModel target, System.Boolean isWinDuel)
using BattleActionModelGetAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool);
inline BattleActionModelGetAttackDmgAdderFn original_BattleActionModel_GetAttackDmgAdder = nullptr;
int32_t hooked_BattleActionModel_GetAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel);

// C#: System.Int32 GetExpectedAttackDmgAdder(CoinModel coin, BattleUnitModel targetOrNull)
using BattleActionModelGetExpectedAttackDmgAdderFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetExpectedAttackDmgAdderFn original_BattleActionModel_GetExpectedAttackDmgAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedAttackDmgAdder(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull);

// C#: System.Int32 GetOppoSkillPowerResultAdderOnTakeAtkDmg()
using BattleActionModelGetOppoSkillPowerResultAdderOnTakeAtkDmgFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetOppoSkillPowerResultAdderOnTakeAtkDmgFn original_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg = nullptr;
int32_t hooked_BattleActionModel_GetOppoSkillPowerResultAdderOnTakeAtkDmg(il2cpp::Il2CppObject* __this);

// C#: static System.Boolean BothCanDuelAndAttackSkill(BattleActionModel a, BattleActionModel b)
using BattleActionModelBothCanDuelAndAttackSkillFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelBothCanDuelAndAttackSkillFn original_BattleActionModel_BothCanDuelAndAttackSkill = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_BothCanDuelAndAttackSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

// C#: static System.Boolean BothCanDuelAndAtLeastOneAttackSkill(BattleActionModel a, BattleActionModel b)
using BattleActionModelBothCanDuelAndAtLeastOneAttackSkillFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelBothCanDuelAndAtLeastOneAttackSkillFn original_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_BothCanDuelAndAtLeastOneAttackSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

// C#: static System.Boolean CanDuelBoth(BattleActionModel a, BattleActionModel b)
using BattleActionModelCanDuelBothFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanDuelBothFn original_BattleActionModel_CanDuelBoth = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_CanDuelBoth(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* a, il2cpp::Il2CppObject* b);

// C#: System.Boolean CanDuel(BattleActionModel opponentAction)
using BattleActionModelCanDuelFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanDuelFn original_BattleActionModel_CanDuel = nullptr;
bool hooked_BattleActionModel_CanDuel(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction);

// C#: System.Boolean CanDuelWithoutCheckNull(BattleActionModel opponentAction)
using BattleActionModelCanDuelWithoutCheckNullFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanDuelWithoutCheckNullFn original_BattleActionModel_CanDuelWithoutCheckNull = nullptr;
bool hooked_BattleActionModel_CanDuelWithoutCheckNull(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* opponentAction);

// C#: System.Boolean IsPanicBlock()
using BattleActionModelIsPanicBlockFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsPanicBlockFn original_BattleActionModel_IsPanicBlock = nullptr;
bool hooked_BattleActionModel_IsPanicBlock(il2cpp::Il2CppObject* __this);

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action, BattleUnitModel target)
using BattleActionModelGetDescArgs_P2Fn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetDescArgs_P2Fn original_BattleActionModel_GetDescArgs_P2 = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDescArgs_P2(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target);

// C#: System.Collections.Generic.List<System.Object> GetDescArgs(BattleActionModel action)
using BattleActionModelGetDescArgs_P1Fn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetDescArgs_P1Fn original_BattleActionModel_GetDescArgs_P1 = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetDescArgs_P1(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* action);

// C#: System.Boolean IsAllCoinHead()
using BattleActionModelIsAllCoinHeadFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsAllCoinHeadFn original_BattleActionModel_IsAllCoinHead = nullptr;
bool hooked_BattleActionModel_IsAllCoinHead(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsAllCoinHit()
using BattleActionModelIsAllCoinHitFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsAllCoinHitFn original_BattleActionModel_IsAllCoinHit = nullptr;
bool hooked_BattleActionModel_IsAllCoinHit(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetHeadCoinNum()
using BattleActionModelGetHeadCoinNumFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetHeadCoinNumFn original_BattleActionModel_GetHeadCoinNum = nullptr;
int32_t hooked_BattleActionModel_GetHeadCoinNum(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetTailCoinNum()
using BattleActionModelGetTailCoinNumFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetTailCoinNumFn original_BattleActionModel_GetTailCoinNum = nullptr;
int32_t hooked_BattleActionModel_GetTailCoinNum(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetUsableInDuelCoinNum()
using BattleActionModelGetUsableInDuelCoinNumFn = int32_t(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetUsableInDuelCoinNumFn original_BattleActionModel_GetUsableInDuelCoinNum = nullptr;
int32_t hooked_BattleActionModel_GetUsableInDuelCoinNum(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsFirstCoin(CoinModel coin)
using BattleActionModelIsFirstCoinFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsFirstCoinFn original_BattleActionModel_IsFirstCoin = nullptr;
bool hooked_BattleActionModel_IsFirstCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin);

// C#: System.Boolean IsLastCoin(CoinModel coin)
using BattleActionModelIsLastCoinFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsLastCoinFn original_BattleActionModel_IsLastCoin = nullptr;
bool hooked_BattleActionModel_IsLastCoin(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin);

// C#: System.Boolean CheckPersonalitySkillSpecificType(SKILL_KEYWORD keyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType)
using BattleActionModelCheckPersonalitySkillSpecificTypeFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelCheckPersonalitySkillSpecificTypeFn original_BattleActionModel_CheckPersonalitySkillSpecificType = nullptr;
bool hooked_BattleActionModel_CheckPersonalitySkillSpecificType(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t targetType);

// C#: System.Boolean CheckSkillGivingBuffCategory(BUFF_CATEGORY_KEYWORD category, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using BattleActionModelCheckSkillGivingBuffCategoryFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline BattleActionModelCheckSkillGivingBuffCategoryFn original_BattleActionModel_CheckSkillGivingBuffCategory = nullptr;
bool hooked_BattleActionModel_CheckSkillGivingBuffCategory(il2cpp::Il2CppObject* __this, int32_t category, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Boolean CheckSkillGivingBuff(BUFF_UNIQUE_KEYWORD buffKeyword, GIVING_BUFF_SKILL_TARGET_TYPE targetType, System.Boolean& stackGiver, System.Boolean& turnGiver)
using BattleActionModelCheckSkillGivingBuffFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t, bool*, bool*);
inline BattleActionModelCheckSkillGivingBuffFn original_BattleActionModel_CheckSkillGivingBuff = nullptr;
bool hooked_BattleActionModel_CheckSkillGivingBuff(il2cpp::Il2CppObject* __this, int32_t buffKeyword, int32_t targetType, bool* stackGiver, bool* turnGiver);

// C#: System.Boolean IsGainBullet()
using BattleActionModelIsGainBulletFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsGainBulletFn original_BattleActionModel_IsGainBullet = nullptr;
bool hooked_BattleActionModel_IsGainBullet(il2cpp::Il2CppObject* __this);

// C#: CoinModel GetCoin(System.Int32 i)
using BattleActionModelGetCoinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetCoinFn original_BattleActionModel_GetCoin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetCoin(il2cpp::Il2CppObject* __this, int32_t i);

// C#: CoinModel GetFirstCoin()
using BattleActionModelGetFirstCoinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetFirstCoinFn original_BattleActionModel_GetFirstCoin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetFirstCoin(il2cpp::Il2CppObject* __this);

// C#: CoinModel GetLastCoin()
using BattleActionModelGetLastCoinFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*);
inline BattleActionModelGetLastCoinFn original_BattleActionModel_GetLastCoin = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetLastCoin(il2cpp::Il2CppObject* __this);

// C#: System.Int32 GetMpUsage(System.Boolean isErodeSkill)
using BattleActionModelGetMpUsageFn = int32_t(*)(il2cpp::Il2CppObject*, bool);
inline BattleActionModelGetMpUsageFn original_BattleActionModel_GetMpUsage = nullptr;
int32_t hooked_BattleActionModel_GetMpUsage(il2cpp::Il2CppObject* __this, bool isErodeSkill);

// C#: System.Boolean IsMultiTarget()
using BattleActionModelIsMultiTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsMultiTargetFn original_BattleActionModel_IsMultiTarget = nullptr;
bool hooked_BattleActionModel_IsMultiTarget(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsReusedAction()
using BattleActionModelIsReusedActionFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsReusedActionFn original_BattleActionModel_IsReusedAction = nullptr;
bool hooked_BattleActionModel_IsReusedAction(il2cpp::Il2CppObject* __this);

// C#: System.Void BeforeAttack(BATTLE_EVENT_TIMING timing)
using BattleActionModelBeforeAttackFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelBeforeAttackFn original_BattleActionModel_BeforeAttack = nullptr;
void hooked_BattleActionModel_BeforeAttack(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Int32 GetFinalSkillPowerResult(BATTLE_EVENT_TIMING timing)
using BattleActionModelGetFinalSkillPowerResultFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetFinalSkillPowerResultFn original_BattleActionModel_GetFinalSkillPowerResult = nullptr;
int32_t hooked_BattleActionModel_GetFinalSkillPowerResult(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Int32 GetParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult, System.Int32 parryingCount)
using BattleActionModelGetParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelGetParryingResultAdderFn original_BattleActionModel_GetParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount);

// C#: System.Int32 GetExpectedParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoActionOrNull, System.Int32 oppoResult)
using BattleActionModelGetExpectedParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetExpectedParryingResultAdderFn original_BattleActionModel_GetExpectedParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);

// C#: System.Int32 GetOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
using BattleActionModelGetOpponentParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetOpponentParryingResultAdderFn original_BattleActionModel_GetOpponentParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

// C#: System.Int32 GetExpectedOpponentParryingResultAdder(System.Int32 actorResult, BattleActionModel oppoAction, System.Int32 oppoResult)
using BattleActionModelGetExpectedOpponentParryingResultAdderFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetExpectedOpponentParryingResultAdderFn original_BattleActionModel_GetExpectedOpponentParryingResultAdder = nullptr;
int32_t hooked_BattleActionModel_GetExpectedOpponentParryingResultAdder(il2cpp::Il2CppObject* __this, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);

// C#: System.Void OverWriteSkill(System.Int32 defaultValue, System.Int32 coinNum, System.Int32 coinScale, OPERATOR_TYPE operatorType)
using BattleActionModelOverWriteSkillFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t);
inline BattleActionModelOverWriteSkillFn original_BattleActionModel_OverWriteSkill = nullptr;
void hooked_BattleActionModel_OverWriteSkill(il2cpp::Il2CppObject* __this, int32_t defaultValue, int32_t coinNum, int32_t coinScale, int32_t operatorType);

// C#: System.Boolean IsRandomTarget()
using BattleActionModelIsRandomTargetFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsRandomTargetFn original_BattleActionModel_IsRandomTarget = nullptr;
bool hooked_BattleActionModel_IsRandomTarget(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsTargetableSlot(SinActionModel attackerSinAction)
using BattleActionModelIsTargetableSlotFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsTargetableSlotFn original_BattleActionModel_IsTargetableSlot = nullptr;
bool hooked_BattleActionModel_IsTargetableSlot(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* attackerSinAction);

// C#: System.Boolean IsSkillAbsorbingThisDamage()
using BattleActionModelIsSkillAbsorbingThisDamageFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsSkillAbsorbingThisDamageFn original_BattleActionModel_IsSkillAbsorbingThisDamage = nullptr;
bool hooked_BattleActionModel_IsSkillAbsorbingThisDamage(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsDefenseSkillForOther(BattleUnitModel originTarget, BattleActionModel opponentActionOrNull)
using BattleActionModelIsDefenseSkillForOtherFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsDefenseSkillForOtherFn original_BattleActionModel_IsDefenseSkillForOther = nullptr;
bool hooked_BattleActionModel_IsDefenseSkillForOther(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* originTarget, il2cpp::Il2CppObject* opponentActionOrNull);

// C#: System.Boolean AttackByMpDmgRatherThanHpDmg(CoinModel coin, System.Int32 resultDmg, BattleUnitModel target)
using BattleActionModelAttackByMpDmgRatherThanHpDmgFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelAttackByMpDmgRatherThanHpDmgFn original_BattleActionModel_AttackByMpDmgRatherThanHpDmg = nullptr;
bool hooked_BattleActionModel_AttackByMpDmgRatherThanHpDmg(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, int32_t resultDmg, il2cpp::Il2CppObject* target);

// C#: System.Boolean BlockLoseBuffByReactWithAction(BattleUnitModel target, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
using BattleActionModelBlockLoseBuffByReactWithActionFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelBlockLoseBuffByReactWithActionFn original_BattleActionModel_BlockLoseBuffByReactWithAction = nullptr;
bool hooked_BattleActionModel_BlockLoseBuffByReactWithAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

// C#: System.Int32 ChangeAttackDamage(CoinModel coin, BattleUnitModel target, System.Int32 resultDmg, System.Boolean& isCritical, System.Nullable<System.Boolean> isWinDuel, BATTLE_EVENT_TIMING timing)
using BattleActionModelChangeAttackDamageFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, bool*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelChangeAttackDamageFn original_BattleActionModel_ChangeAttackDamage = nullptr;
int32_t hooked_BattleActionModel_ChangeAttackDamage(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, int32_t resultDmg, bool* isCritical, il2cpp::Il2CppObject* isWinDuel, int32_t timing);

// C#: System.Void OnSkillChangedEgo(System.Boolean isOverClock, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnSkillChangedEgoFn = void(*)(il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelOnSkillChangedEgoFn original_BattleActionModel_OnSkillChangedEgo = nullptr;
void hooked_BattleActionModel_OnSkillChangedEgo(il2cpp::Il2CppObject* __this, bool isOverClock, int32_t timing);

// C#: System.Void OnRoundEnd(BATTLE_EVENT_TIMING timing)
using BattleActionModelOnRoundEndFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnRoundEndFn original_BattleActionModel_OnRoundEnd = nullptr;
void hooked_BattleActionModel_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Void OnRoundEnd_After()
using BattleActionModelOnRoundEnd_AfterFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelOnRoundEnd_AfterFn original_BattleActionModel_OnRoundEnd_After = nullptr;
void hooked_BattleActionModel_OnRoundEnd_After(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAddCoinByAbility(CoinModel newCoin, BATTLE_EVENT_TIMING timing)
using BattleActionModelOnAddCoinByAbilityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelOnAddCoinByAbilityFn original_BattleActionModel_OnAddCoinByAbility = nullptr;
void hooked_BattleActionModel_OnAddCoinByAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* newCoin, int32_t timing);

// C#: System.Single GetGiveBsGaugeUpMultiplier(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
using BattleActionModelGetGiveBsGaugeUpMultiplierFn = float(*)(il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetGiveBsGaugeUpMultiplierFn original_BattleActionModel_GetGiveBsGaugeUpMultiplier = nullptr;
float hooked_BattleActionModel_GetGiveBsGaugeUpMultiplier(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull);

// C#: System.Int32 GetGiveBsGaugeUpAdder(System.Boolean onGiveExplosion, BattleUnitModel target, CoinModel coinOrNull)
using BattleActionModelGetGiveBsGaugeUpAdderFn = int32_t(*)(il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetGiveBsGaugeUpAdderFn original_BattleActionModel_GetGiveBsGaugeUpAdder = nullptr;
int32_t hooked_BattleActionModel_GetGiveBsGaugeUpAdder(il2cpp::Il2CppObject* __this, bool onGiveExplosion, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coinOrNull);

// C#: System.Boolean HasCoinOperatorType(OPERATOR_TYPE type)
using BattleActionModelHasCoinOperatorTypeFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelHasCoinOperatorTypeFn original_BattleActionModel_HasCoinOperatorType = nullptr;
bool hooked_BattleActionModel_HasCoinOperatorType(il2cpp::Il2CppObject* __this, int32_t type);

// C#: System.Boolean HasSuperCoin()
using BattleActionModelHasSuperCoinFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelHasSuperCoinFn original_BattleActionModel_HasSuperCoin = nullptr;
bool hooked_BattleActionModel_HasSuperCoin(il2cpp::Il2CppObject* __this);

// C#: System.Void StackNextTurnAggroAdder()
using BattleActionModelStackNextTurnAggroAdderFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelStackNextTurnAggroAdderFn original_BattleActionModel_StackNextTurnAggroAdder = nullptr;
void hooked_BattleActionModel_StackNextTurnAggroAdder(il2cpp::Il2CppObject* __this);

// C#: System.Void OnUseStageBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
using BattleActionModelOnUseStageBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelOnUseStageBuffBySkillFn original_BattleActionModel_OnUseStageBuffBySkill = nullptr;
void hooked_BattleActionModel_OnUseStageBuffBySkill(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack);

// C#: System.Int32 GetUsedStageBuffStack(BUFF_UNIQUE_KEYWORD keyword)
using BattleActionModelGetUsedStageBuffStackFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetUsedStageBuffStackFn original_BattleActionModel_GetUsedStageBuffStack = nullptr;
int32_t hooked_BattleActionModel_GetUsedStageBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Void OnUseBuffBySkill(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
using BattleActionModelOnUseBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline BattleActionModelOnUseBuffBySkillFn original_BattleActionModel_OnUseBuffBySkill = nullptr;
void hooked_BattleActionModel_OnUseBuffBySkill(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn);

// C#: System.Boolean UsedBuffStack(BUFF_UNIQUE_KEYWORD keyword, System.Int32 stack)
using BattleActionModelUsedBuffStackFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelUsedBuffStackFn original_BattleActionModel_UsedBuffStack = nullptr;
bool hooked_BattleActionModel_UsedBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack);

// C#: System.Boolean UsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword, System.Int32 turn)
using BattleActionModelUsedBuffTurnFn = bool(*)(il2cpp::Il2CppObject*, int32_t, int32_t);
inline BattleActionModelUsedBuffTurnFn original_BattleActionModel_UsedBuffTurn = nullptr;
bool hooked_BattleActionModel_UsedBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t turn);

// C#: System.Int32 GetUsedBuffStack(BUFF_UNIQUE_KEYWORD keyword)
using BattleActionModelGetUsedBuffStackFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetUsedBuffStackFn original_BattleActionModel_GetUsedBuffStack = nullptr;
int32_t hooked_BattleActionModel_GetUsedBuffStack(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Int32 GetUsedBuffTurn(BUFF_UNIQUE_KEYWORD keyword)
using BattleActionModelGetUsedBuffTurnFn = int32_t(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetUsedBuffTurnFn original_BattleActionModel_GetUsedBuffTurn = nullptr;
int32_t hooked_BattleActionModel_GetUsedBuffTurn(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Boolean OverwriteCoinProb(BattleUnitModel unit, SkillModel skill, CoinModel coinOrNull, System.Single& prob)
using BattleActionModelOverwriteCoinProbFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, float*);
inline BattleActionModelOverwriteCoinProbFn original_BattleActionModel_OverwriteCoinProb = nullptr;
bool hooked_BattleActionModel_OverwriteCoinProb(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* unit, il2cpp::Il2CppObject* skill, il2cpp::Il2CppObject* coinOrNull, float* prob);

// C#: System.Boolean OverwriteCriticalResult(CoinModel coin, System.Boolean tempCritical, System.Nullable<System.Boolean>& overwriteCriticalResult)
using BattleActionModelOverwriteCriticalResultFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, bool, il2cpp::Il2CppObject**);
inline BattleActionModelOverwriteCriticalResultFn original_BattleActionModel_OverwriteCriticalResult = nullptr;
bool hooked_BattleActionModel_OverwriteCriticalResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin, bool tempCritical, il2cpp::Il2CppObject** overwriteCriticalResult);

// C#: System.Boolean IgnoreCheckCritical(CoinModel coin)
using BattleActionModelIgnoreCheckCriticalFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIgnoreCheckCriticalFn original_BattleActionModel_IgnoreCheckCritical = nullptr;
bool hooked_BattleActionModel_IgnoreCheckCritical(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* coin);

// C#: System.Boolean CanDealTarget(BattleUnitModel target, CoinModel coin)
using BattleActionModelCanDealTargetFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelCanDealTargetFn original_BattleActionModel_CanDealTarget = nullptr;
bool hooked_BattleActionModel_CanDealTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin);

// C#: System.Boolean BlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, System.Nullable<System.Int32> activeRound, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
using BattleActionModelBlockGivingBuffFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelBlockGivingBuffFn original_BattleActionModel_BlockGivingBuff = nullptr;
bool hooked_BattleActionModel_BlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* activeRound, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

// C#: System.Boolean ExpectedBlockGivingBuff(BattleUnitModel buffTarget, BUFF_UNIQUE_KEYWORD keyword, CoinModel coinOrNull, System.Nullable<System.Boolean> isCritical)
using BattleActionModelExpectedBlockGivingBuffFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelExpectedBlockGivingBuffFn original_BattleActionModel_ExpectedBlockGivingBuff = nullptr;
bool hooked_BattleActionModel_ExpectedBlockGivingBuff(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* buffTarget, int32_t keyword, il2cpp::Il2CppObject* coinOrNull, il2cpp::Il2CppObject* isCritical);

// C#: System.Void RightBeforeGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical)
using BattleActionModelRightBeforeGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelRightBeforeGiveBuffBySkillFn original_BattleActionModel_RightBeforeGiveBuffBySkill = nullptr;
void hooked_BattleActionModel_RightBeforeGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical);

// C#: System.Void RightAfterGiveBuffBySkill(BattleUnitModel target, BUFF_UNIQUE_KEYWORD bufKeyword, System.Int32 originalStack, System.Int32 originalTurn, System.Int32 resultStack, System.Int32 resultTurn, System.Int32 activeRound, BATTLE_EVENT_TIMING timing, System.Nullable<System.Boolean> isCritical, CoinModel coinOrNull)
using BattleActionModelRightAfterGiveBuffBySkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelRightAfterGiveBuffBySkillFn original_BattleActionModel_RightAfterGiveBuffBySkill = nullptr;
void hooked_BattleActionModel_RightAfterGiveBuffBySkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t bufKeyword, int32_t originalStack, int32_t originalTurn, int32_t resultStack, int32_t resultTurn, int32_t activeRound, int32_t timing, il2cpp::Il2CppObject* isCritical, il2cpp::Il2CppObject* coinOrNull);

// C#: System.Boolean IsReusable()
using BattleActionModelIsReusableFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsReusableFn original_BattleActionModel_IsReusable = nullptr;
bool hooked_BattleActionModel_IsReusable(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsSupportSkill()
using BattleActionModelIsSupportSkillFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsSupportSkillFn original_BattleActionModel_IsSupportSkill = nullptr;
bool hooked_BattleActionModel_IsSupportSkill(il2cpp::Il2CppObject* __this);

// C#: System.Boolean IsChangeable()
using BattleActionModelIsChangeableFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsChangeableFn original_BattleActionModel_IsChangeable = nullptr;
bool hooked_BattleActionModel_IsChangeable(il2cpp::Il2CppObject* __this);

// C#: System.Void OnOrderCutInAction(BattleActionModel newAction)
using BattleActionModelOnOrderCutInActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnOrderCutInActionFn original_BattleActionModel_OnOrderCutInAction = nullptr;
void hooked_BattleActionModel_OnOrderCutInAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* newAction);

// C#: System.Void AddTemporarySkillAbilityToSkill(SkillAbility tempSkillAbility, System.String scriptName, System.Single jsonValue, System.Int32 idx, System.Int32 turnLimit, BuffReferenceData info)
using BattleActionModelAddTemporarySkillAbilityToSkillFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, float, int32_t, int32_t, il2cpp::Il2CppObject*);
inline BattleActionModelAddTemporarySkillAbilityToSkillFn original_BattleActionModel_AddTemporarySkillAbilityToSkill = nullptr;
void hooked_BattleActionModel_AddTemporarySkillAbilityToSkill(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* tempSkillAbility, il2cpp::Il2CppObject* scriptName, float jsonValue, int32_t idx, int32_t turnLimit, il2cpp::Il2CppObject* info);

// C#: System.Void RemoveAllSpecificSkillAbility(System.Type targetSkillAbility)
using BattleActionModelRemoveAllSpecificSkillAbilityFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelRemoveAllSpecificSkillAbilityFn original_BattleActionModel_RemoveAllSpecificSkillAbility = nullptr;
void hooked_BattleActionModel_RemoveAllSpecificSkillAbility(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSkillAbility);

// C#: System.Void AddCoinIgnoredTiming(BATTLE_EVENT_TIMING timing)
using BattleActionModelAddCoinIgnoredTimingFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelAddCoinIgnoredTimingFn original_BattleActionModel_AddCoinIgnoredTiming = nullptr;
void hooked_BattleActionModel_AddCoinIgnoredTiming(il2cpp::Il2CppObject* __this, int32_t timing);

// C#: System.Boolean IsBlockingTargetBurstBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using BattleActionModelIsBlockingTargetBurstBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelIsBlockingTargetBurstBuffEffectReactFn original_BattleActionModel_IsBlockingTargetBurstBuffEffectReact = nullptr;
bool hooked_BattleActionModel_IsBlockingTargetBurstBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

// C#: System.Boolean IsBlockingTargetSinkingBuffEffectReact(BattleUnitModel target, System.Int32 stack, System.Int32 turn, CoinModel selfCoin, System.Boolean isCritical, BATTLE_EVENT_TIMING timing)
using BattleActionModelIsBlockingTargetSinkingBuffEffectReactFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t, int32_t, il2cpp::Il2CppObject*, bool, int32_t);
inline BattleActionModelIsBlockingTargetSinkingBuffEffectReactFn original_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact = nullptr;
bool hooked_BattleActionModel_IsBlockingTargetSinkingBuffEffectReact(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* target, int32_t stack, int32_t turn, il2cpp::Il2CppObject* selfCoin, bool isCritical, int32_t timing);

// C#: System.Boolean OverwriteParryingResult(System.Int32 tempActorResult, BattleActionModel oppoAction, System.Int32 tempOppoResult, System.Nullable<System.Int32>& overwriteResult)
using BattleActionModelOverwriteParryingResultFn = bool(*)(il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject*, int32_t, il2cpp::Il2CppObject**);
inline BattleActionModelOverwriteParryingResultFn original_BattleActionModel_OverwriteParryingResult = nullptr;
bool hooked_BattleActionModel_OverwriteParryingResult(il2cpp::Il2CppObject* __this, int32_t tempActorResult, il2cpp::Il2CppObject* oppoAction, int32_t tempOppoResult, il2cpp::Il2CppObject** overwriteResult);

// C#: System.Boolean TryGetForcedCoinResult(System.Nullable<System.Boolean> isParrying, COIN_RESULT& result, BattleActionModel oppoActionOrNull)
using BattleActionModelTryGetForcedCoinResultFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, int32_t*, il2cpp::Il2CppObject*);
inline BattleActionModelTryGetForcedCoinResultFn original_BattleActionModel_TryGetForcedCoinResult = nullptr;
bool hooked_BattleActionModel_TryGetForcedCoinResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* isParrying, int32_t* result, il2cpp::Il2CppObject* oppoActionOrNull);

// C#: COIN_RESULT GetForcedCoinResult(System.Nullable<System.Boolean> isParrying)
using BattleActionModelGetForcedCoinResultFn = int32_t(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelGetForcedCoinResultFn original_BattleActionModel_GetForcedCoinResult = nullptr;
int32_t hooked_BattleActionModel_GetForcedCoinResult(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* isParrying);

// C#: BattleActionSystemAbility AddAbilityThisRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
using BattleActionModelAddAbilityThisRoundFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline BattleActionModelAddAbilityThisRoundFn original_BattleActionModel_AddAbilityThisRound = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_AddAbilityThisRound(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn);

// C#: BattleActionSystemAbility AddAbilityNextRound(BATTLE_ACTION_SYSTEM_KEYWORD keyword, System.Int32 stack, System.Int32 turn)
using BattleActionModelAddAbilityNextRoundFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t, int32_t, int32_t);
inline BattleActionModelAddAbilityNextRoundFn original_BattleActionModel_AddAbilityNextRound = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_AddAbilityNextRound(il2cpp::Il2CppObject* __this, int32_t keyword, int32_t stack, int32_t turn);

// C#: System.Boolean HasSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
using BattleActionModelHasSystemAbilityFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelHasSystemAbilityFn original_BattleActionModel_HasSystemAbility = nullptr;
bool hooked_BattleActionModel_HasSystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: BattleActionSystemAbility GetSystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
using BattleActionModelGetSystemAbilityFn = il2cpp::Il2CppObject*(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelGetSystemAbilityFn original_BattleActionModel_GetSystemAbility = nullptr;
il2cpp::Il2CppObject* hooked_BattleActionModel_GetSystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Void DestroySystemAbility(BATTLE_ACTION_SYSTEM_KEYWORD keyword)
using BattleActionModelDestroySystemAbilityFn = void(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelDestroySystemAbilityFn original_BattleActionModel_DestroySystemAbility = nullptr;
void hooked_BattleActionModel_DestroySystemAbility(il2cpp::Il2CppObject* __this, int32_t keyword);

// C#: System.Void MarkAsExtracted()
using BattleActionModelMarkAsExtractedFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelMarkAsExtractedFn original_BattleActionModel_MarkAsExtracted = nullptr;
void hooked_BattleActionModel_MarkAsExtracted(il2cpp::Il2CppObject* __this);

// C#: System.Void OnAddBattleAction(SinActionModel targetSinActionNullable)
using BattleActionModelOnAddBattleActionFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnAddBattleActionFn original_BattleActionModel_OnAddBattleAction = nullptr;
void hooked_BattleActionModel_OnAddBattleAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetSinActionNullable);

// C#: System.Void OnRemoveBattleAction()
using BattleActionModelOnRemoveBattleActionFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelOnRemoveBattleActionFn original_BattleActionModel_OnRemoveBattleAction = nullptr;
void hooked_BattleActionModel_OnRemoveBattleAction(il2cpp::Il2CppObject* __this);

// C#: System.Void OnSetExpectedTarget(BattleActionModel targetAction)
using BattleActionModelOnSetExpectedTargetFn = void(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelOnSetExpectedTargetFn original_BattleActionModel_OnSetExpectedTarget = nullptr;
void hooked_BattleActionModel_OnSetExpectedTarget(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* targetAction);

// C#: System.Boolean IsRunUniqueAction(UniqueCutInTiming uniqueTiming, BattleActionModel mainAction, BattleActionModel oppoActionNullable)
using BattleActionModelIsRunUniqueActionFn = bool(*)(il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*, il2cpp::Il2CppObject*);
inline BattleActionModelIsRunUniqueActionFn original_BattleActionModel_IsRunUniqueAction = nullptr;
bool hooked_BattleActionModel_IsRunUniqueAction(il2cpp::Il2CppObject* __this, il2cpp::Il2CppObject* uniqueTiming, il2cpp::Il2CppObject* mainAction, il2cpp::Il2CppObject* oppoActionNullable);

// C#: System.Boolean IsEgoSkill()
using BattleActionModelIsEgoSkillFn = bool(*)(il2cpp::Il2CppObject*);
inline BattleActionModelIsEgoSkillFn original_BattleActionModel_IsEgoSkill = nullptr;
bool hooked_BattleActionModel_IsEgoSkill(il2cpp::Il2CppObject* __this);

// C#: System.Boolean HasEgoKeyword(EGO_KEYWORD keyword)
using BattleActionModelHasEgoKeywordFn = bool(*)(il2cpp::Il2CppObject*, int32_t);
inline BattleActionModelHasEgoKeywordFn original_BattleActionModel_HasEgoKeyword = nullptr;
bool hooked_BattleActionModel_HasEgoKeyword(il2cpp::Il2CppObject* __this, int32_t keyword);

#pragma endregion

void init_BattleActionModel_framework();
} // myosotis::testmod
