#ifndef COSTMAP_2D_COST_VALUES_H_
#define COSTMAP_2D_COST_VALUES_H_
/** Provides a mapping for often used cost values */
namespace UstarCostmap
{
    static const unsigned char NO_INFORMATION = 255;
    static const unsigned char LETHAL_OBSTACLE = 254;
    static const unsigned char INSCRIBED_INFLATED_OBSTACLE = 253;
    static const unsigned char FREE_SPACE = 0;
} // namespace UstarCostmap
#endif // UstarCostmap_COST_VALUES_H_
