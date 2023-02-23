#! /bin/bash

roslaunch gmapping test.launch &

sleep 20

./src/TA_c_w_rta/CentralizedIndTaskOptimization_c_code_updated/test1 & python3 src/rrt-algorithms/examples/rrt/rrt_2d_with_random_obstacles.py & ./src/osqp_mpc/osqp_mpc.py &

rrt_ID=$(pgrep -f src/rrt-algorithms/examples/rrt/rrt_2d_with_random_obstacles.py)
TA_ID=$(pidof test1)
GMAP_ID=$(pidof slam_gmapping)
MPC_ID=$(pgrep -f ./src/osqp_mpc/osqp_mpc.py)

echo "GMAP PID $GMAP_ID"
echo "TA PID $TA_ID"
echo "rrt PID $rrt_ID"
echo "Mpc PID $MPC_ID"

sudo chrt -f -p 20 $GMAP_ID
sudo chrt -f -p 30 $rrt_ID
sudo chrt -f -p 40 $TA_ID
sudo chrt -f -p 50 $MPC_ID

sleep 20

rosbag play subset2.bag --clock &

sleep 0.1

sudo kill -CONT $MPC_ID & sudo kill -CONT $rrt_ID & sudo kill -CONT $TA_ID &
#& rosbag play subset2.bag --clock
#sudo kill -CONT $rrt_ID &
sleep 300
./quit.sh

