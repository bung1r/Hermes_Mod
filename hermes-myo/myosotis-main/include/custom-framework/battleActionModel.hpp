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


namespace myosotis::testmod {

class BattleActionModel {

public:

};

using BattleActionModelInitCoinsFn = void(*)(il2cpp::Il2CppObject*);
inline BattleActionModelInitCoinsFn original_BattleActionModel_InitCoins = nullptr;
void hooked_BattleActionModel_InitCoins(il2cpp::Il2CppObject* __this);

void init_BattleActionModel_framework();


}