## Husky Laser

The package should be able to subscribe to a laser **scan** message from the Husky robot and process the incoming data.

## Compilation
Init workspace:
```
cd carkin_ws/src
catkin_init_workspace
```
Build:
```
catkin build
```

## Create Eclipse project:
```
catkin build -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -D__cplusplus=201103L -D__GXX_EXPERIMENTAL_CXX0X__=1
```
then open Eclipse-> File -> Import -> General -> Existing Projects into Workspace
Select the root directory as:
```
/path-to-project/catkin_ws/build
```
and select only the husky_highlevel_controller

Rebuild the C/C++ index: Right click on Project -> Index -> Rebuild

Build with CTRL+B

## Running
```
roslaunch husky_highlevel_controller husky.launch
```
It will open Gazebo and Rviz.
Typing:
```
rostopic list
```
it is possible to see that there is the **scan** topic in the list. In pratice, it is a funcionality provided from Husky Robot to scan the environment.  
Insert on Gazebo a random Box and on the RViz and on the log system you can see the scanned element.
