#ifndef _ACCESSSTATE_H_
#define _ACCESSSTATE_H_

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
