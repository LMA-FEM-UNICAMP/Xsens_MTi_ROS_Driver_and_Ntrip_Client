/*
 * autoware_ins.hpp
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

#ifndef autoware_ins__autoware_ins_HPP_
#define autoware_ins__autoware_ins_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "autoware_sensing_msgs/msg/gnss_ins_orientation.hpp"
#include "autoware_sensing_msgs/msg/gnss_ins_orientation_stamped.hpp"

class AutowareIns : public rclcpp::Node
{
public:
    AutowareIns();

private:
    
    double rmse_rotation_x_;
    double rmse_rotation_y_;
    double rmse_rotation_z_;

    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr gnss_pose_sub_;
    rclcpp::Publisher<autoware_sensing_msgs::msg::GnssInsOrientationStamped>::SharedPtr gnss_ins_orientation_pub_;


    void gnss_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
};
#endif  // autoware_ins__autoware_ins_HPP_
