# Intel Realsense USB Camera setup

- ref : https://github.com/IntelRealSense/realsense-ros
- ref: https://github.com/IntelRealSense/librealsense/blob/master/doc/distribution_linux.md
- troubleshooting : the end of this page

## step 1 : Intel® RealSense™ SDK 2.0 (librealsense) installation for checking realsense d435 usb camera 

```
sudo apt-key adv --keyserver keys.gnupg.net --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE || sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE

sudo add-apt-repository "deb http://realsense-hw-public.s3.amazonaws.com/Debian/apt-repo bionic main" -u

sudo apt-get install librealsense2-dkms
sudo apt-get install librealsense2-utils
```
- optional for developer, debugging
```
sudo apt-get install librealsense2-dev
sudo apt-get install librealsense2-dbg
```

## step 2 : checking d435 is working fine
```
realsense-viewer
```
```
modinfo uvcvideo | grep "version:"
```

## step 3 : realsense ROS2 package source download
```
cd ~/catkin_ws/src/
git clone https://github.com/IntelRealSense/realsense-ros
```

## step 4 : build
```
cd ~/catkin_ws
catkin_make
source ~/catkin_ws/devel/setup.bash
```
```
export ROS_VER=melodic 
sudo apt-get install ros-$ROS_VER-realsense2-camera
```

## step 5 : getting serial number from enumerate
```
rs-enumerate-devices | grep Serial
```


## step 6 : change the serial number in rs_camera.launch 
```
~/catkin_ws/src/realsense-ros/realsense2_camera/launch$ vi rs_camera.launch
```
```
 <arg name="serial_no"           default="935422070341"/>

```

## step 7 : execution of realsense camera (D435)
```
roslaunch realsense2_camera rs_camera.launch camera:=cam_1 serial_no:=935422070341
```
or
```
roslaunch realsense2_camera rs_camera.launch camera:=cam_1 
```

## step 8 : check it is working fine

```
rosrun rqt_graph rqt_graph
```
```
rviz
```

## Trobuleshooting

- if your pc/robot could not find the camera interface, please refer to the following
  ref: https://github.com/IntelRealSense/realsense-ros/issues/1408
```
cd /etc/udev/rules.d/ 
sudo wget https://github.com/IntelRealSense/librealsense/blob/master/config/99-realsense-libusb.rules
reboot
```
