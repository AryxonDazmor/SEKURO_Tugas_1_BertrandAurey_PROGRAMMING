#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <iostream>
#include <chrono>   

//Reference to OVA 7: This is the Real Anzio Battle.
class l3 : public rclcpp::Node
{
    public:
        l3(): Node("L3"){
            hp_ = 100;

            subscription_ = this->create_subscription<std_msgs::msg::Int32>(
                "tank_damage", 
                3, //Banyak pesan yang ditampung sebelum dibuang 
                std::bind(&l3::take_damage, this, std::placeholders::_1)
            );
            status_pub_ = this->create_publisher<std_msgs::msg::String>("tank_status", 10);
        }
    private:
        int hp_;
        void take_damage(const std_msgs::msg::Int32::SharedPtr msg){ 
            int damage = msg->data;
            hp_ -= damage; //Sama aja kayak x -= 1!
            if (hp_ <= 0){
                hp_ = 0; //hp jangan negatif
                RCLCPP_INFO(this->get_logger(), "L3 takes %d damage! Remaining hp: %d", damage, hp_); //%d di sini itu kek variabel di phyton, cuma variabelnya didefinisiin di belakang
                RCLCPP_INFO(this->get_logger(), "L3 is destroyed! Protect the Duce!"); 
                auto status_msg = std_msgs::msg::String();
                status_msg.data = "Flag raised";
                status_pub_->publish(status_msg);
                rclcpp::shutdown(); //matiin
            }else{
                RCLCPP_INFO(this->get_logger(), "L3 takes %d damage! Remaining hp: %d", damage, hp_); 
            }
        }
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<l3>());
    rclcpp::shutdown();
    return 0;
};