# Making use of Darknet (Yolo) in ROS Melodic using Intel Realsense D435


## step 1 : git clone darknet_ros

```
git clone https://github.com/katebrighteyes/darknet_ros
```

## step 2 : check camera image topic 
```
roslaunch realsense2_camera rs_camera.launch camera:=realsense
```

```
rostopic list
```

in case of realsense d435
/realsense/color/image_raw


## step 3 : modifying topic name in ros.yaml
```
~/catkin_ws/src/darknet_ros/darknet_ros/config$ vi ros.yaml
```
```
  camera_reading:
    topic: /realsense/color/image_raw
    queue_size: 1

```

## step 4 : modifying launch file
```
vi launch/darknet_ros.launch
```
```
<!-- ROS and network parameter files -->
     12   <arg name="ros_param_file"             default="$(find darknet_ros)/config/ros.yaml"/>
     13   <arg name="network_param_file"         default="$(find darknet_ros)/config/yolov2-tiny.yaml"/>
```
 - yolov2-tiny.yaml : this is indicating where are config_file, weight_file, threshold, detection_classes


## step 5 : modifying source code 

vi darknet_ros/src/YoloObjectDetector.cpp +158
```
//TODO 3-1
imageSubscriber_ = imageTransport_.subscribe(cameraTopicName, cameraQueueSize, &YoloObjectDetector::cameraCallback, this);
//TODO 3-2
objectPublisher_ = nodeHandle_.advertise<std_msgs::Int8>(objectDetectorTopicName, objectDetectorQueueSize, objectDetectorLatch);
//TODO 3-3
boundingBoxesPublisher_ = nodeHandle_.advertise<darknet_ros_msgs::BoundingBoxes>( boundingBoxesTopicName, boundingBoxesQueueSize, boundingBoxesLatch);
//TODO 3-4
detectionImagePublisher_ = nodeHandle_.advertise<sensor_msgs::Image>(detectionImageTopicName, detectionImageQueueSize, detectionImageLatch);
```

## step 6 : build
```
cd ~/catkin_ws
catkin_make
```

## step 7 : test
```
roscore
```
```
roslaunch realsense2_camera rs_camera.launch camera:=realsense 
```
```
roslaunch darknet_ros darknet_ros.launch
```
```
rviz
```
```
rosrun rqt_graph rqt_graph
```

