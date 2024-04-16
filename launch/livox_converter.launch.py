import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    bringup_dir = get_package_share_directory('livox_converter')

    c2p_node = Node(
        package='livox_converter',
        executable='custommsg_to_pointcloud_node',
        name='pointcloud_to_laserscan'
    )

    p2l_node = Node(
        package='livox_converter',
        executable='pointcloud_to_laserscan_node',
        remappings=[('cloud_in',  ['/livox/points']),
                    ('scan',  ['/scan'])],
        parameters=[{
            'target_frame': 'livox_frame',
            'transform_tolerance': 0.01,
            'min_height': -0.1,
            'max_height': 0.1,
            'angle_min': -3.14159,  # -M_PI/2
            'angle_max': 3.14159,  # M_PI/2
            'angle_increment': 0.0043,  # M_PI/360.0
            'scan_time': 0.3333,
            'range_min': 0.45,
            'range_max': 10.0,
            'use_inf': True,
            'inf_epsilon': 1.0
        }],
        name='pointcloud_to_laserscan'
    )

    ld = LaunchDescription()

    ld.add_action(c2p_node)
    ld.add_action(p2l_node)

    return ld

