#pragma once

#include <iostream>
#include <rclcpp/rclcpp.hpp>

#include "livox_converter.hpp"

namespace livox_converter {

class CustomMsgToPointCloudNode : public rclcpp::Node {
 public:
  CustomMsgToPointCloudNode(const rclcpp::NodeOptions& options);
  ~CustomMsgToPointCloudNode();

 private:
  LivoxConverter converter;
  rclcpp::SubscriptionBase::SharedPtr livox_sub;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr points_pub;

};  // class CustomMsgToPointCloudNode
}  // namespace livox_converter