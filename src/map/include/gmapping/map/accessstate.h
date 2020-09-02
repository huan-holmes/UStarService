#ifndef ACCESSSTATE_H_
#define ACCESSSTATE_H_

namespace UstarSlam
{
    enum AccessibilityState
    {
        Outside = 0x0,
        Inside = 0x1,
        Allocated = 0x2
    };
};

#endif
