#include "custommsg_to_pointcloud.hpp"

#include "livox_ros_driver2/msg/custom_msg.hpp"

namespace livox_converter {

CustomMsgToPointCloudNode::CustomMsgToPointCloudNode(
    const rclcpp::NodeOptions& options)
    : rclcpp::Node("custommsg_to_pointcloud_node", options) {

  points_pub = this->create_publisher<sensor_msgs::msg::PointCloud2>(
      "/livox/points", rclcpp::SensorDataQoS());

  livox_sub = this->create_subscription<livox_ros_driver2::msg::CustomMsg>(
      "/livox/lidar", rclcpp::SensorDataQoS(),
      [this](const livox_ros_driver2::msg::CustomMsg::ConstSharedPtr livox_msg) {
        const auto points_msg = converter.convert(*livox_msg);
        points_pub->publish(*points_msg);
      });
}

CustomMsgToPointCloudNode::~CustomMsgToPointCloudNode() {}

}  // namespace livox_converter

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(livox_converter::CustomMsgToPointCloudNode);