# ros_melodic

ROS melodic installation & build & test


## step 1
```
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

sudo apt update
```

## step 2
```
sudo apt install ros-melodic-desktop

sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential

sudo rosdep init

rosdep update

echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc

source ~/.bashrc
```


## step 3 : test for installation of ROS:Melodic
```
roscore
```
```
rosrun turtlesim turtlesim_node
```
```
rosrun turtlesim turtle_teleop_key
```

## step 4 : making workspace
```
wget https://raw.githubusercontent.com/katebrighteyes/jetson_ros_melodic/master/install_catkinws.sh
chmod 777 install_catkinws.sh
./install_catkinws.sh
ls ~/catkin_ws
```

## step 5 : making package 

```
cd ~/catkin_ws/src
catkin_create_pkg ros_topic_test std_msgs roscpp
```

## step 6: developing
```
copy to ~/catkin_ws/src/ros_topic_test/src/ from this site /src/ros_pub_test.cpp, ros_sub_test.cpp
copy to ~/catkin_ws/src/ros_topic_test/ from this site /src/CMakeLists.txt
```

## step 7 : compile & build
```
cd ~/catkin_ws
catkin_make
```

## step 8 : execution
```
cd ~/catkin_ws
source ./devel/setup.bash
rosrun ros_topic_test ros_pub_test
```
```
rosrun ros_topic_test ros_sub_test
```
