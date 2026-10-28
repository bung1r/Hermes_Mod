#pragma once
#include <string>
#include <format>
#include "il2cpp.hpp"
#include "hermesStatic.hpp"

namespace myosotis::testmod {
    inline il2cpp::Il2CppImage* mainImg = nullptr;
    void init_all();
    void init_test_thing(il2cpp::Il2CppImage* img, const char* namespaze);
}