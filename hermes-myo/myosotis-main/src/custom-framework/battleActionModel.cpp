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
#include "hermesUtils.hpp"
#include "custom-framework/battleActionModel.hpp"

namespace myosotis::testmod
{
    void init_BattleActionModel_framework()
    {
        ClassCache BAMC = RegisterClassFull("BattleActionModel", IMG_MAIN, "", "BattleActionModel");
        original_BattleActionModel_InitCoins = InstallHook<BattleActionModelInitCoinsFn>(BAMC.GetMethod("InitCoins"), &hooked_BattleActionModel_InitCoins);
    }
}