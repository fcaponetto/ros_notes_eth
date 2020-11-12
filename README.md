[img01]: ./images/ros_master.png "Ros Master"
[img02]: ./images/ros_nodes.png "Ros Nodes"
[img03]: ./images/ros_topics.png "Ros Topics"
[img04]: ./images/ros_messages.png "Ros Messages

"[img05]: ./images/ros_ation.png "Ros Action"

# ROS Overview

All the credits for the slides and images goes to Robotic Systems Lab @ ETH Zurich:  [Programming for Robotics](http://www.rsl.ethz.ch/education-students/lectures/ros.html)

Ros originally was developed in 2007 at the Stanford Artificial Intelligence Laboratory

### ROS Workspace Environment

Defines context for the current workspace:

```
> source /opt/ros/kinetic/setup.bash
```

Overlay your catkin workspace with:

```
> cd ~/catkin_ws
> source devel/setup.bash
```

Check your workspace with:

```
> echo $ROS_PACKAGE_PATH
```

### ROS Master

![alt text][img01]

* Manages the communication between nodes
* Every node registers at startup with the master

Start a master with:

```
> roscore
```

### ROS Nodes

![alt text][img02]

* Single-purpose, executable program
* Individually compiled, executed, and managed
* Organized in packages

Run a node with:

```
> rosrun package_name node_name
```

See active nodes with:

```
> rosnode list
```

Retrieve information about a node with:

```
> rosnode info node_name
```

### ROS Topics

![alt text][img03]

* Nodes communicate over topics
  * Nodes can publish or subscribe to a topic
  * Typically, 1 publisher and n subscribers
* Topic is a name for a stream of messages

List active topics with:

```
> rostopic list
```

Subscribe and print the contents of a topic with:

```
> rostopic echo /topic
```

Show information about a topic with:

```
> rostopic info /topic
```

### ROS Messages

![alt text][img04]

* Data structure defining the type of a topic
* Compromised of a nested structure of integers, floats, booleans, strings etc. and arrays of objects
* Defined in *.msg files

See the type of a topic:

```
> rostopic type /topic
```

Publish a message to a topic:

```
> rostopic pub /topic type args
```

Show the service definition with

```
rossrv show $(rosservice type /service_name)
```

### ROS Services

* Request/response communication between nodes is realized with services
  * The service server advertises the service
  * The service client accesses this service
* Similar in structure to messages, services are defined in *.srv files

List available services with:

```
> rosservice list
```

Show the type of a service

```
> rosservice type /service_name
```

Call a service with the request contents:

```
>  rosservice call /service_name args
```

## ROS Action

![alt text][img05]

Ros action are similar to ROS services, but faster. Moreover, it is possible:

* To cancel the request (pre-empted).

* Receive feedback on the progress
  
  

Best way to implement interfaces to timeextended, goal-oriented behaviors. Internally, actions **are implemented with a set of topics**



## Catkin best practices

* catkin is the ROS build system to generate executables, libraries, and interfaces
* We suggest to use the Catkin Command Line Tools.  

Use **catkin build** instead of **catkin_make**.  
Navigate to your catkin workspace with:

```
> cd ~/catkin_ws
```

Create the src forlder and init the wokspace:

```
mkdir src
cd src
catkin_init_workspace
```

Make the simbolic link of the repository downloaded:

```
cd src
ln -s /path/of/the/repo .
```

Build a package with:

```
catkin build package_name
```

Whenever you build a new package, update your environment:

```
> source devel/setup.bash
```

If necessary, *clean* the entire build and devel space with:

```
> catkin clean
```

## Example

* ├── build
* │   ├── ...
* │   ├── ...
* │   ├── ...
* ├── CMakeLists.txt
* ├── devel
* │   ├── ...
* │   ├── ...
* │   ├── ...
* │   └── share
* ├── logs
* │   ├── ...
* │   ├── ...
* │   ├── ...
* └── src
* ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
* ├── kuka-lwr-ros -> ~/workspace/kuka/kuka-lwr-ros
* ├── ...
*  ├── ...

**NOTE: DON'T TOUCH THE DEVEL OR BUILD FOLDER**
