# ROS Overview

[ROS course from ETH Zurich](http://www.rsl.ethz.ch/education-students/lectures/ros.html)

Originally developed in 2007 at theStanford Artificial Intelligence Laboratory

### ROS Workspace Environment

Defines context for the current workspace
```
> source /opt/ros/kinetic/setup.bash
```
Overlay your catkin workspace with
```
> cd ~/catkin_ws
> source devel/setup.bash
```
Check your workspace with
```
> echo $ROS_PACKAGE_PATH
```

### ROS Master
* Manages the communication between nodes
* Every node registers at startup with the master

Start a master with
```
> roscore
```

### ROS Nodes
* Single-purpose, executable program
* Individually compiled, executed, and managed
* Organized in packages

Run a node with
```
> rosrun package_name node_name
```
See active nodes with
```
> rosnode list
```
Retrieve information about a node with
```
> rosnode info node_name
```

### ROS Topics
* Nodes communicate over topics
    * Nodes can publish or subscribe to a topic
    * Typically, 1 publisher and n subscribers
* Topic is a name for a stream of messages

List active topics with
```
> rostopic list
```
Subscribe and print the contents of a topic with
```
> rostopic echo /topic
```
Show information about a topic with
```
> rostopic info /topic
```

### ROS Messages

* Data structure defining the type of a topic
* Compromised of a nested structure of integers, floats, booleans, strings etc. and arrays of objects
* Defined in *.msg files

See the type of a topic
```
> rostopic type /topic
```
Publish a message to a topic
```
> rostopic pub /topic type args
```

### catkin Build System

* catkin is the ROS build system to generate executables, libraries, and interfaces
* We suggest to use the Catkin Command Line Tools
**Use catkin build instead of catkin_make**
Navigate to your catkin workspace with
```
> cd ~/catkin_ws
```
Build a package with
```
> catkin build package_name
```
Whenever you build a new package, update your environment
```
> source devel/setup.bash
```
If necessary, clean the entire build and devel space with
```
> catkin clean
```