#include <iostream>
#include <passiveBase.hpp>
#include <hermesBuff.hpp>

namespace myosotis::testmod {

class MoPassive1 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    void OnStageStart(int32_t timing);
    void OnBattleStart(int32_t timing);
    void OnBattleEnd(int32_t timing);

    int32_t GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin);
    // int32_t GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull);
};

class MoPassive2 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    void OnStageStart(int32_t timing);

    float GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical);
    float GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull);
    int32_t ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged);
    int32_t ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg);
    int32_t GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount);
    int32_t GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult);
    int32_t GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);
    int32_t GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult);
};

class MoPassive3 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    void OnStageStart(int32_t timing);

    // int32_t GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target);
    // int32_t GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull);
};

} // myosotis::testmod