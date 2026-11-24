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
#include "passiveBase.hpp"

// This is where the BattleUnitModel is stored

namespace myosotis::testmod {

class BattleUnitModel {

public:
    // OBJs mean the actual object inside Unity. 
    il2cpp::Il2CppObject* unitObj = nullptr; // BattleUnitModel, the one and only
    il2cpp::Il2CppObject* passiveDetailObj = nullptr; 
    il2cpp::Il2CppObject* buffDetailObj = nullptr;
    il2cpp::Il2CppObject* battleActionModelListObj = nullptr; // the actual List<BattleActionModel>
    std::vector<il2cpp::Il2CppObject*> battleActionModelObjs = {}; // like above, but in a C++ vector instead

    // Custom hooked implementation of these things! Glory to Limbus Company. 
    PassiveDetail passiveDetail = {}; //
    // BuffDetail buffDetail = {};
    virtual ~BattleUnitModel() = default;

    // If the unit has any custom implementation, this method will attempt create a BattleUnitModel. Otherwise it will return false. 
    // Use ForceInitBattleUnitModel if you want to include IDs without custom implementation. 
    // Note: Custom Implementation just means "custom unit." modifying existing units is currently a work in progress. 
    virtual bool TryInitCustomBattleUnitModel(); 

    virtual void InitPassiveDetail();
    virtual void InitBuffDetail();
    virtual void InitBattleActionModels();

    // Will force the creation of a BattleUnitModel of any unit, regardless of custom implementation.
    virtual void ForceInitBattleUnitModel();

    // Any methods below are hooked (although it's not that necessary)
};

void init_BattleUnitModel_framework();

}