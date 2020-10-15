#include <gtest/gtest.h>
#include <ros/service.h>
#include <ros/ros.h>
#include <nav_msgs/GetMap.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/MapMetaData.h>

#include "test_constants.h"

int g_argc;
char** g_argv;

class MapClientTest : public testing::Test
{
  public:
    // A node is needed to make a service call
    ros::NodeHandle* n_;

    MapClientTest()
    {
      ros::init(g_argc, g_argv, "map_client_test");
      n_ = new ros::NodeHandle();
      got_map_ = false;
      got_map_metadata_ = false;
    }

    ~MapClientTest()
    {
      delete n_;
    }

    bool got_map_;
    boost::shared_ptr<nav_msgs::OccupancyGrid const> map_;
    void mapCallback(const boost::shared_ptr<nav_msgs::OccupancyGrid const>& map)
    {
      map_ = map;
      got_map_ = true;
    }

    bool got_map_metadata_;
    boost::shared_ptr<nav_msgs::MapMetaData const> map_metadata_;
    void mapMetaDataCallback(const boost::shared_ptr<nav_msgs::MapMetaData const>& map_metadata)
    {
      map_metadata_ = map_metadata;
      got_map_metadata_ = true;
    }
};

/* Try to retrieve the map via service, and compare to ground truth */
TEST_F(MapClientTest, call_service)
{
  nav_msgs::GetMap::Request  req;
  nav_msgs::GetMap::Response resp;
  ASSERT_TRUE(ros::service::waitForService("static_map", 5000));
  ASSERT_TRUE(ros::service::call("static_map", req, resp));
  ASSERT_FLOAT_EQ(resp.map.info.resolution, g_valid_image_res);
  ASSERT_EQ(resp.map.info.width, g_valid_image_width);
  ASSERT_EQ(resp.map.info.height, g_valid_image_height);
  ASSERT_STREQ(resp.map.header.frame_id.c_str(), "map");
  for(unsigned int i=0; i < resp.map.info.width * resp.map.info.height; i++)
    ASSERT_EQ(g_valid_image_content[i], resp.map.data[i]);
}

/* Try to retrieve the map via topic, and compare to ground truth */
TEST_F(MapClientTest, subscribe_topic)
{
  ros::Subscriber sub = n_->subscribe<nav_msgs::OccupancyGrid>("map", 1, boost::bind(&MapClientTest::mapCallback, this, _1));

  // Try a few times, because the server may not be up yet.
  int i=20;
  while(!got_map_ && i > 0)
  {
    ros::spinOnce();
    ros::Duration d = ros::Duration().fromSec(0.25);
    d.sleep();
    i--;
  }
  ASSERT_TRUE(got_map_);
  ASSERT_FLOAT_EQ(map_->info.resolution, g_valid_image_res);
  ASSERT_EQ(map_->info.width, g_valid_image_width);
  ASSERT_EQ(map_->info.height, g_valid_image_height);
  ASSERT_STREQ(map_->header.frame_id.c_str(), "map");
  for(unsigned int i=0; i < map_->info.width * map_->info.height; i++)
    ASSERT_EQ(g_valid_image_content[i], map_->data[i]);
}

/* Try to retrieve the metadata via topic, and compare to ground truth */
TEST_F(MapClientTest, subscribe_topic_metadata)
{
  ros::Subscriber sub = n_->subscribe<nav_msgs::MapMetaData>("map_metadata", 1, boost::bind(&MapClientTest::mapMetaDataCallback, this, _1));

  // Try a few times, because the server may not be up yet.
  int i=20;
  while(!got_map_metadata_ && i > 0)
  {
    ros::spinOnce();
    ros::Duration d = ros::Duration().fromSec(0.25);
    d.sleep();
    i--;
  }
  ASSERT_TRUE(got_map_metadata_);
  ASSERT_FLOAT_EQ(map_metadata_->resolution, g_valid_image_res);
  ASSERT_EQ(map_metadata_->width, g_valid_image_width);
  ASSERT_EQ(map_metadata_->height, g_valid_image_height);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  g_argc = argc;
  g_argv = argv;

  return RUN_ALL_TESTS();
}
