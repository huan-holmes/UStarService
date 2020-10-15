/* This file contains global constants shared among tests */

/* Note that these must be changed if the test image changes */

#include "test_constants.h"

const unsigned int g_valid_image_width = 10;
const unsigned int g_valid_image_height = 10;
// Note that the image content is given in row-major order, with the
// lower-left pixel first.  This is different from a graphics coordinate
// system, which starts with the upper-left pixel.  The loadMapFromFile
// call converts from the latter to the former when it loads the image, and
// we want to compare against the result of that conversion.
const char g_valid_image_content[] = {
0,0,0,0,0,0,0,0,0,0,
100,100,100,100,0,0,100,100,100,0,
100,100,100,100,0,0,100,100,100,0,
100,0,0,0,0,0,0,0,0,0,
100,0,0,0,0,0,0,0,0,0,
100,0,0,0,0,0,100,100,0,0,
100,0,0,0,0,0,100,100,0,0,
100,0,0,0,0,0,100,100,0,0,
100,0,0,0,0,0,100,100,0,0,
100,0,0,0,0,0,0,0,0,0,
};

const char* g_valid_png_file = "test/testmap.png";
const char* g_valid_bmp_file = "test/testmap.bmp";
const char* g_spectrum_png_file = "test/spectrum.png";

const float g_valid_image_res = 0.1;

