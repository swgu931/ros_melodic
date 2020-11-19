# USB Camera setup

## step 1 : checking usb camera 

```
ls -ltr /dev/video*

cd catkin_ws/src

git clone https://github.com/bosch-ros-pkg/usb_cam
```

## step 2 : change video device number in downloaded usb_cam source

```
nvidia@nvidia:~$ ls -ltr /dev/video*

crw-rw----+ 1 root video 81, 0 9월 18 23:46 /dev/video0

crw-rw----+ 1 root video 81, 3 9월 19 02:41 /dev/video1

nvidia@nvidia:~$ cd catkin_ws/src

nvidia@nvidia:~/catkin_ws/src$ grep -rn video0 *

usb_cam/launch/usb_cam-test.launch:3:

usb_cam/nodes/usb_cam_node.cpp:92: node_.param("video_device", video_device_name_, std::string("/dev/video0"));

** YOU HAVE TO MODIFY THOSE 2 LINES TO "/dev/video1" !!!!
```

## step 3 : usb_cam source build
```
cd ..

sudo apt-get install ros-melodic-camera-info-manager libavcodec-dev libswscale-dev -y

catkin_make

source ~/catkin_ws/devel/setup.bash

rospack find usb_cam

sudo apt-get install ros-melodic-image-view

source ~/catkin_ws/devel/setup.bash
```

## step 4 : test

```
roslaunch usb_cam usb_cam-test.launch

```
```
rosrun rqt_graph rqt_graph
```
