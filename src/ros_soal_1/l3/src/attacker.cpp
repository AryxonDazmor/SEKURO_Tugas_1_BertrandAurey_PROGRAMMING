#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
//Reference to OVA 7: This is the Real Anzio Battle.
class Attacker : public rclcpp::Node
{
    public:
        Attacker(): Node("Type_89B")
        {
            damage_pub_ = this->create_publisher<std_msgs::msg::Int32>("tank_damage", 10);
            status_sub_ = this->create_subscription<std_msgs::msg::String>(
            "tank_status", 10, std::bind(&Attacker::status_callback, this, std::placeholders::_1));
            timer_ = this->create_wall_timer(
                std::chrono::milliseconds(500), //Manuvernya L3.33 Kenceng. Tapi gunnya g efektif. Jadi Duck team cuma perlu nyerang aja, g ush takut diserang (kecuali muncul Semevonte sm P40).
                std::bind(&Attacker::attack, this)
            );
        };
    private:
        void status_callback(const std_msgs::msg::String::SharedPtr msg) {
            if (msg->data == "Flag raised") {
                RCLCPP_INFO(this->get_logger(), "Target destroyed! Find the P40!");
                timer_->cancel(); // Stops the timer from ever running again
                rclcpp::shutdown(); //matiin
            }
        };
        void attack()
        {
            auto message = std_msgs::msg::Int32();
            message.data = std::rand() % 10 + 1;;
            std::cout << "L3 Hit!" << std::endl;
            RCLCPP_INFO(this->get_logger(), "Duck Team Fires! Dealt %d damage...", message.data);
            damage_pub_->publish(message);
        };
        
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr damage_pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr status_sub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv); //Buat bangunin ROS2nya
  rclcpp::spin(std::make_shared<Attacker>()); //spin tuh tugasnya buat ngerjain programnyta berulang2. Dalemnya tuh buat ngejalanin kode attacker public di atas
  rclcpp::shutdown(); //Si tank imut udah mati, ga usah nembak lagi. Nanti didenda Federasi
  return 0; //program selesai, Tinggal cari tank si Duce
}
            