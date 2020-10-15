#include <stdexcept> // for std::runtime_error
#include <gtest/gtest.h>
#include "map_server/image_loader.h"
#include "test_constants.h"

/* Try to load a valid PNG file.  Succeeds if no exception is thrown, and if
 * the loaded image matches the known dimensions and content of the file.
 *
 * This test can fail on OS X, due to an apparent limitation of the
 * underlying SDL_Image library. */
TEST(MapServer, loadValidPNG)
{
  try
  {
    nav_msgs::GetMap::Response map_resp;
    double origin[3] = { 0.0, 0.0, 0.0 };
    map_server::loadMapFromFile(&map_resp, g_valid_png_file, g_valid_image_res, false, 0.65, 0.1, origin);
    EXPECT_FLOAT_EQ(map_resp.map.info.resolution, g_valid_image_res);
    EXPECT_EQ(map_resp.map.info.width, g_valid_image_width);
    EXPECT_EQ(map_resp.map.info.height, g_valid_image_height);
    for(unsigned int i=0; i < map_resp.map.info.width * map_resp.map.info.height; i++)
      EXPECT_EQ(g_valid_image_content[i], map_resp.map.data[i]);
  }
  catch(...)
  {
    ADD_FAILURE() << "Uncaught exception : " << "This is OK on OS X";
  }
}

/* Try to load a valid BMP file.  Succeeds if no exception is thrown, and if
 * the loaded image matches the known dimensions and content of the file. */
TEST(MapServer, loadValidBMP)
{
  try
  {
    nav_msgs::GetMap::Response map_resp;
    double origin[3] = { 0.0, 0.0, 0.0 };
    map_server::loadMapFromFile(&map_resp, g_valid_bmp_file, g_valid_image_res, false, 0.65, 0.1, origin);
    EXPECT_FLOAT_EQ(map_resp.map.info.resolution, g_valid_image_res);
    EXPECT_EQ(map_resp.map.info.width, g_valid_image_width);
    EXPECT_EQ(map_resp.map.info.height, g_valid_image_height);
    for(unsigned int i=0; i < map_resp.map.info.width * map_resp.map.info.height; i++)
      EXPECT_EQ(g_valid_image_content[i], map_resp.map.data[i]);
  }
  catch(...)
  {
    ADD_FAILURE() << "Uncaught exception";
  }
}

/* Try to load an invalid file.  Succeeds if a std::runtime_error exception
 * is thrown. */
TEST(MapServer, loadInvalidFile)
{
  try
  {
    nav_msgs::GetMap::Response map_resp;
    double origin[3] = { 0.0, 0.0, 0.0 };
    map_server::loadMapFromFile(&map_resp, "foo", 0.1, false, 0.65, 0.1, origin);
  }
  catch(std::runtime_error &e)
  {
    SUCCEED();
    return;
  }
  catch(...)
  {
    FAIL() << "Uncaught exception";
  }
  ADD_FAILURE() << "Didn't throw exception as expected";
}

std::vector<unsigned int> countValues(const nav_msgs::GetMap::Response& map_resp)
{
  std::vector<unsigned int> counts(256, 0);
  for (unsigned int i = 0; i < map_resp.map.data.size(); i++)
  {
    unsigned char value = static_cast<unsigned char>(map_resp.map.data[i]);
    counts[value]++;
  }
  return counts;
}

TEST(MapServer, testMapMode)
{
  nav_msgs::GetMap::Response map_resp;
  double origin[3] = { 0.0, 0.0, 0.0 };

  map_server::loadMapFromFile(&map_resp, g_spectrum_png_file, 0.1, false, 0.65, 0.1, origin, TRINARY);
  std::vector<unsigned int> trinary_counts = countValues(map_resp);
  EXPECT_EQ(90u, trinary_counts[100]);
  EXPECT_EQ(26u, trinary_counts[0]);
  EXPECT_EQ(140u, trinary_counts[255]);

  map_server::loadMapFromFile(&map_resp, g_spectrum_png_file, 0.1, false, 0.65, 0.1, origin, SCALE);
  std::vector<unsigned int> scale_counts = countValues(map_resp);
  EXPECT_EQ(90u, scale_counts[100]);
  EXPECT_EQ(26u, scale_counts[0]);
  unsigned int scaled_values = 0;
  for (unsigned int i = 1; i < 100; i++)
  {
    scaled_values += scale_counts[i];
  }
  EXPECT_EQ(140u, scaled_values);

  map_server::loadMapFromFile(&map_resp, g_spectrum_png_file, 0.1, false, 0.65, 0.1, origin, RAW);
  std::vector<unsigned int> raw_counts = countValues(map_resp);
  for (unsigned int i = 0; i < raw_counts.size(); i++)
  {
    EXPECT_EQ(1u, raw_counts[i]) << i;
  }
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
