cmake_minimum_required(VERSION 3.8)
project(l3)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

cmake_minimum_required(VERSION 3.8)
project(l3)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  # 1. Build the Attacker (Type 89B)
add_executable(attacker_node src/attacker.cpp)
ament_target_dependencies(attacker_node rclcpp std_msgs)

# 2. Build the Tank System (L3)
add_executable(tank_node src/tank_system.cpp)
ament_target_dependencies(tank_node rclcpp std_msgs)

# 3. Install the nodes so ROS 2 can find them
install(TARGETS
  attacker_node
  tank_node
  DESTINATION lib/${PROJECT_NAME}
)
endif()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
