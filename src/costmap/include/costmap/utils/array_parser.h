#ifndef COSTMAP_2D_ARRAY_PARSER_H_
#define COSTMAP_2D_ARRAY_PARSER_H_

#include <vector>
#include <string>

namespace UstarCostmap
{

    /** @brief Parse a vector of vectors of floats from a string.
 * @param error_return If no error, error_return is set to "".  If
 *        error, error_return will describe the error.
 * Syntax is [[1.0, 2.0], [3.3, 4.4, 5.5], ...]
 *
 * On error, error_return is set and the return value could be
 * anything, like part of a successful parse. */
    std::vector<std::vector<float> > parseVVF(const std::string &input, std::string &error_return);

} // namespace UstarCostmap

#endif // COSTMAP_2D_ARRAY_PARSER_H
