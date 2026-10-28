#include <iostream>
#include <passiveBase.hpp>
#include <hermesBuff.hpp>
#include "custom-passives/moPassives.hpp"


namespace myosotis::testmod {

void MoPassive1::OnStageStart(int32_t timing) {
    // PassiveBase::OnStageStart(timing);
    
    ClassCache& BuffDetailRef = GetClassRef("BuffDetail");
    ClassCache& BattleUnitModelRef = GetClassRef("BattleUnitModel");
    // il2cpp::Il2CppObject* owner = GetOwner();
    // // il2cpp::Il2CppObject* buffDetail = BattleUnitModelRef.Get<il2cpp::Il2CppObject*>(owner, "_buffDetail");
    
    // int32_t keywordIndex = 5;
    // AddBuff(owner, 5, 10, 0, 0, 8, timing); 
}

} // myosotis::testmod