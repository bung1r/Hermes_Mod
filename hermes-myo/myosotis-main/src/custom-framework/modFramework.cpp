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
#include "custom-framework/modFramework.hpp"
#include "custom-framework/battleUnitModel.hpp"
#include "custom-framework/battleActionModel.hpp"
#include "custom-framework/battleCoinModel.hpp"

namespace myosotis::testmod {
    void init_modding_framework() {
        init_BattleUnitModel_framework();
        init_BattleActionModel_framework();
    }
}