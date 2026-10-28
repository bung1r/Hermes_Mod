#include <iostream>
#include <passiveBase.hpp>
#include <hermesBuff.hpp>

namespace myosotis::testmod {

class MoPassive1 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    void OnStageStart(int32_t timing);
};

class MoPassive2 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    // void OnStageStart(int32_t timing);
};

class MoPassive3 : public PassiveBase {
public:
    // when the stage starts, Mo gains 10 charge. Every 10 charge consumed converts to 1 Charge Potency (hooray!)
    // also deal more damage with more charge. 
    // void OnStageStart(int32_t timing);
};

} // myosotis::testmod