#include <iostream>
#include <passiveBase.hpp>
#include <hermesBuff.hpp>
#include "custom-passives/moPassives.hpp"


namespace myosotis::testmod {

void MoPassive1::OnStageStart(int32_t timing) {
    // PassiveBase::OnStageStart(timing);
    
    ClassCache& BuffDetailC = GetClassRef("BuffDetail");
    ClassCache& BattleUnitModelC = GetClassRef("BattleUnitModel");

    MYO_LOG("MoPassive1", "The Stage Has Started, and the Mo Passive Exists! Hip hip hooray! Here is the timing: {}", timing);
    // il2cpp::Il2CppObject* owner = GetOwner();
    // // il2cpp::Il2CppObject* buffDetail = BattleUnitModelRef.Get<il2cpp::Il2CppObject*>(owner, "_buffDetail");
    
    // int32_t keywordIndex = 5;
    // AddBuff(owner, 5, 10, 0, 0, 8, timing); 
}

void MoPassive1::OnBattleStart(int32_t timing) {
    MYO_LOG("MoPassive1", "The Combat Phase Has Started, and the Mo Passive Exists! Hip hip hooray! Here is the timing: {}", timing);
}
void MoPassive1::OnBattleEnd(int32_t timing) {
    MYO_LOG("MoPassive1", "The Combat Phase Has Ended, and the Mo Passive Exists! Hip hip hooray! Here is the timing: {}", timing);
}

int32_t MoPassive1::GetCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* oppoActionOrNull, il2cpp::Il2CppObject* coin) {
    MYO_LOG("MoPassive1", "Current Coin Scale Adder: {}", returnValue);
    return returnValue + 20;
}
// int32_t MoPassive1::GetExpectedCoinScaleAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* expectedTargetSinActionOrNull) {
//     MYO_LOG("MoPassive1", "Current Expected Coin Scale Adder: {}", returnValue);
//     return returnValue + 44;
// }

void MoPassive2::OnStageStart(int32_t timing) {
    // PassiveBase::OnStageStart(timing);
    MYO_LOG("MoPassive2", "The Stage Has Started, and the Mo Passive Exists! Hip hip hooray! Here is the timing: {}", timing);
}

float MoPassive2::GetAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* target, bool isWinDuel, bool isCritical) {
    MYO_LOG("MoPassive2", "Current Attack Dmg Multiplier: {}", returnValue);
    return returnValue + 10.0f;
}
float MoPassive2::GetExpectedAttackDmgMultiplier(float returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coin, il2cpp::Il2CppObject* targetOrNull, il2cpp::Il2CppObject* targetSinActionOrNull) {
    MYO_LOG("MoPassive2", "Current Expected Dmg Multiplier: {}", returnValue);
    return returnValue + 777.0f;
}

int32_t MoPassive2::ChangeAttackDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target, il2cpp::Il2CppObject* coin, int32_t resultDmg, bool* isCritical, int32_t timing, bool* isChanged) {
    MYO_LOG("MoPassive2", "Change Attack Dmg: {}", returnValue);
    return 50;
}
int32_t MoPassive2::ChangeTakeDamage(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* coinOrNull, int32_t resultDmg, int32_t dmgSrcType, int32_t keyword, int32_t timing, bool* isChanged, int32_t preCalculatedDmg) {
    MYO_LOG("MoPassive2", "Change Take Dmg: {}", returnValue);
    return 0;
}

int32_t MoPassive2::GetParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult, int32_t parryingCount) {
    MYO_LOG("MoPassive2", "Return Value: {}", returnValue);
    return returnValue;
}
int32_t MoPassive2::GetExpectedParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoActionOrNull, int32_t oppoResult) {
    MYO_LOG("MoPassive2", "Return Value: {}", returnValue);
    return returnValue;
}
int32_t MoPassive2::GetOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    MYO_LOG("MoPassive2", "Return Value: {}", returnValue);
    return returnValue;
}
int32_t MoPassive2::GetExpectedOpponentParryingResultAdder(int32_t returnValue, il2cpp::Il2CppObject* action, int32_t actorResult, il2cpp::Il2CppObject* oppoAction, int32_t oppoResult) {
    MYO_LOG("MoPassive2", "Return Value: {}", returnValue);
    return returnValue;
}

void MoPassive3::OnStageStart(int32_t timing) {
    // PassiveBase::OnStageStart(timing);
    
    ClassCache& BuffDetailRef = GetClassRef("BuffDetail");
    ClassCache& BattleUnitModelRef = GetClassRef("BattleUnitModel");

    MYO_LOG("MoPassive3", "The Stage Has Started, and the Mo Passive Exists! Hip hip hooray! Here is the timing: {}", timing);
    // il2cpp::Il2CppObject* owner = GetOwner();
    // // il2cpp::Il2CppObject* buffDetail = BattleUnitModelRef.Get<il2cpp::Il2CppObject*>(owner, "_buffDetail");
    
    // int32_t keywordIndex = 5;
    // AddBuff(owner, 5, 10, 0, 0, 8, timing); 
}

// int32_t MoPassive3::GetAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* target) {
//     MYO_LOG("MoPassive3", "Current Attack Dmg Adder: {}", returnValue);
//     return returnValue + 123;
// }
// int32_t MoPassive3::GetExpectedAttackDmgAdder(int32_t returnValue, il2cpp::Il2CppObject* action, il2cpp::Il2CppObject* targetOrNull) {
//     MYO_LOG("MoPassive3", "Current Attack Dmg Adder: {}", returnValue);
//     return returnValue + 456;
// }


} // myosotis::testmod