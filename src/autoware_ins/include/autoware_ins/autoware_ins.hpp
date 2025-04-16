#ifndef autoware_ins__autoware_ins_HPP_
#define autoware_ins__autoware_ins_HPP_

#include "rclcpp/rclcpp.hpp"
#include "autoware_sensing_msgs/msg/gnss_ins_orientation.hpp"
#include "autoware_sensing_msgs/msg/gnss_ins_orientation_stamped.hpp"

class AutowareIns : public rclcpp::Node
{
public:
    AutowareIns();

private:
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr gnss_pose_sub_;
    rclcpp::Publisher<autoware_sensing_msgs::msg::GnssInsOrientationStamped>::SharedPtr gnss_ins_orientation_pub_;

};
#endif  // autoware_ins__autoware_ins_HPP_
