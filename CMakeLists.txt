cmake_minimum_required(VERSION 3.5)
project(livox_converter)

set(CMAKE_CXX_STANDARD 20)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(
    pointcloud_to_laserscan SHARED
    src/pointcloud_to_laserscan.cpp
    )

rclcpp_components_register_node(
    pointcloud_to_laserscan
    PLUGIN "livox_converter::PointCloudToLaserScanNode"
    EXECUTABLE pointcloud_to_laserscan_node
    )

ament_auto_add_library(
    custommsg_to_pointcloud SHARED
    src/custommsg_to_pointcloud.cpp
    )

rclcpp_components_register_node(
    custommsg_to_pointcloud
    PLUGIN "livox_converter::CustomMsgToPointCloudNode"
    EXECUTABLE custommsg_to_pointcloud_node
    )

if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(
INSTALL_TO_SHARE
    launch
)
