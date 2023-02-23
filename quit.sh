#! /bin/bash

rrt_ID=$(pidof python3 src/rrt-algorithms/examples/rrt/rrt_2d.py)
TA_ID=$(pidof test1)
MPC_ID=$(pidof python ./src/osqp_mpc/osqp_mpc.py)

GMAP_ID=$(pidof slam_gmapping)
ROSMASTER_ID=$(pidof rosmaster)
ROSBAG_ID=$(pgrep -f rosbag)

sudo kill $rrt_ID $TA_ID $MPC_ID $GMAP_ID $ROSMASTER_ID $ROSBAG_ID
