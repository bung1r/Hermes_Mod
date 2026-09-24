#pragma once
#include "il2cpp.hpp"
#include "hermesUtils.hpp"
#include <vector>

namespace myosotis::testmod {

using StageControllerRoundEndFn = void(*)(il2cpp::Il2CppObject*, int32_t);

inline std::vector<il2cpp::Il2CppObject*> playerBattleUnits = {};
inline std::vector<il2cpp::Il2CppObject*> opponentBattleUnits = {};

inline il2cpp::Il2CppField* stageController__stageName = nullptr;

inline il2cpp::Il2CppMethod* stageController_ctor = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnRoundStart = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnRoundEnd = nullptr; 
inline il2cpp::Il2CppMethod* stageController_OnBattleStart = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnBattleEnd = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnStageStart = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnStageEnd = nullptr;
inline il2cpp::Il2CppMethod* stageController_OnCompleteCommand = nullptr;

void hooked_StageController_ctor(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnRoundStart(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnRoundEnd(il2cpp::Il2CppObject* __this, int32_t timing);
void hooked_StageController_OnBattleStart(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnBattleEnd(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnStageStart(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnStageEnd(il2cpp::Il2CppObject* __this);
void hooked_StageController_OnCompleteCommand(il2cpp::Il2CppObject* __this);

inline BaseMethodType original_StageController_ctor = nullptr;
inline BaseMethodType original_StageController_OnRoundStart = nullptr;
inline StageControllerRoundEndFn original_StageController_OnRoundEnd = nullptr; 
inline BaseMethodType original_StageController_OnBattleStart = nullptr;
inline BaseMethodType original_StageController_OnBattleEnd = nullptr;
inline BaseMethodType original_StageController_OnStageStart = nullptr;
inline BaseMethodType original_StageController_OnStageEnd = nullptr;
inline BaseMethodType original_StageController_OnCompleteCommand = nullptr;


void init_stage_controller2(il2cpp::Il2CppImage* img, const char* namespaze);

}