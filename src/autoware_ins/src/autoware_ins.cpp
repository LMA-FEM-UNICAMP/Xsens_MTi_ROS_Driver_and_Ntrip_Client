/*
 * autoware_ins.cpp
 *
 *  Created on: Apr 16, 2025
 *
 *  Author: Gabriel Toffanetto França da Rocha
 *
 *  Laboratory of Autonomous Mobility (LMA)
 *  School of Mechanical Engineering (FEM)
 *  University of Campinas (Unicamp)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

 #include "autoware_ins/autoware_ins.hpp"

AutowareIns::AutowareIns() : Node("autoware_ins")
{
    this->declare_parameter("rmse_rotation_x", 0.0);
    this->declare_parameter("rmse_rotation_y", 0.0);
    this->declare_parameter("rmse_rotation_z", 0.0);

    rmse_rotation_x_ = this->get_parameter("rmse_rotation_x").as_double();
    rmse_rotation_y_ = this->get_parameter("rmse_rotation_y").as_double();
    rmse_rotation_z_ = this->get_parameter("rmse_rotation_z").as_double();


    using std::placeholders::_1;
    gnss_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "/gnss_pose", 1, std::bind(&AutowareIns::gnss_pose_callback, this, _1));
    
    gnss_ins_orientation_pub_ = this->create_publisher<autoware_sensing_msgs::msg::GnssInsOrientationStamped>("/autoware_orientation", 1);
}

void AutowareIns::gnss_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
    autoware_sensing_msgs::msg::GnssInsOrientationStamped gnss_ins_orientation_msg;

    gnss_ins_orientation_msg.header = msg->header;

    gnss_ins_orientation_msg.orientation.orientation = msg->pose.orientation;
    gnss_ins_orientation_msg.orientation.rmse_rotation_x = rmse_rotation_x_;
    gnss_ins_orientation_msg.orientation.rmse_rotation_y = rmse_rotation_y_;
    gnss_ins_orientation_msg.orientation.rmse_rotation_z = rmse_rotation_z_;

    gnss_ins_orientation_pub_->publish(gnss_ins_orientation_msg);
}