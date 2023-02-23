#!/usr/bin/env python

#
# Revision $Id$

## output recoreded utilization data to file 'system_load.txt'
#import roslib; roslib.load_manifest('numpy_tutorials')
#from decimal import *
from fractions import Fraction
import rospy
#from std_msgs.msg import String
#from std_msgs.msg import Float32MultiArray
from std_msgs.msg import Int16
import serial
from array import array
import numpy as np
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Imu
import os
import datetime
import time
import psutil
import math
from matplotlib import pyplot as plt

cpu_p=0
gpu_p=0
soc_p=0
ang_vel=0
lin_acc=0
time_usr1=0
time_sys1=0
format(time_usr1, '.6f')
format(time_sys1, '.6f')
time_usr2=0
time_sys2=0
format(time_usr2, '.6f')
format(time_sys2, '.6f')
time_usr3=0
time_sys3=0
format(time_usr3, '.6f')
format(time_sys3, '.6f')
time_usr4=0
time_sys4=0
format(time_usr4, '.6f')
format(time_sys4, '.6f')
#ser = serial.Serial('/dev/ttyACM0', 230400)
#fpath=os.path.join(/sys/bus/i2c/drivers/ina3221x/0-0040/iio_device/in_power1_input)
#absolute_path = os.path.dirname(os.path.abspath(in_power1_input))
os.chdir("../../../")
#absolute_path = os.path.dirname(os.path.abspath(in_power1_input))
print os.getcwd()
print os.listdir(os.getcwd())
#print absolute_path

#slam-gmap
def log_loads1(time,gps):
    global time_sys1
    global time_usr1	
    #print os.getcwd()
    with open('/home/nvidia/catkin_ws/system_loadg1_10W.txt','a') as f:
  	p = psutil.Process(10167)
  	times=p.cpu_times()
  	#atimes=psutil.cpu_times()
	mem = psutil.virtual_memory()
        gps = ','.join(map(str,gps))
        time = str(time)
	util=psutil.cpu_percent()
        cpu_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power1_input','r').read().split('\n')
        gpu_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power0_input','r').read().split('\n')
        soc_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power2_input','r').read().split('\n')
#        data = list([time,gps,str(psutil.cpu_percent()),str(100)])
#        data = list([time,gps,str(p.cpu_percent(interval=1)),str(100)])
#        data = list([time,gps,str(times[0]-time_usr),str(times[1]-time_sys),str(ang_vel), str(lin_acc),str(cpu_p),str(100)])
	data = list([time,gps,str(times[0]-time_usr1),str(times[1]-time_sys1), str(util), str(mem[3]), str(cpu_p[0]), str(gpu_p[0]), str(soc_p[0]), str(100)])
        print(data)
        f.write(','.join(data))
	f.write('\n')
	time_usr1=times[0]
	time_sys1=times[1]

#baselink_laser-2
def log_loads2(time,gps):
    global time_sys2
    global time_usr2	
    #print os.getcwd()
    with open('/home/nvidia/catkin_ws/system_loadg2_10W.txt','a') as f:
  	p = psutil.Process(10154)
  	times=p.cpu_times()
	#mem = psutil.virtual_memory()
        gps = ','.join(map(str,gps))
        time = str(time)
        
#        data = list([time,gps,str(psutil.cpu_percent()),str(100)])
#        data = list([time,gps,str(p.cpu_percent(interval=1)),str(100)])
#        data = list([time,gps,str(times[0]-time_usr),str(times[1]-time_sys),str(ang_vel), str(lin_acc),str(cpu_p),str(100)])
	data = list([time,gps,str(times[0]-time_usr2),str(times[1]-time_sys2), str(100)])
        print(data)
        f.write(','.join(data))
	f.write('\n')
	time_usr2=times[0]
	time_sys2=times[1]

#odom_map_broadcaster-3
def log_loads3(time,gps):
    global time_sys3
    global time_usr3	
    #print os.getcwd()
    with open('/home/nvidia/catkin_ws/system_loadg3_10W.txt','a') as f:
  	p = psutil.Process(10155)
  	times=p.cpu_times()
#	mem = p.virtual_memory()
        gps = ','.join(map(str,gps))
        time = str(time)
        
#        data = list([time,gps,str(psutil.cpu_percent()),str(100)])
#        data = list([time,gps,str(p.cpu_percent(interval=1)),str(100)])
#        data = list([time,gps,str(times[0]-time_usr),str(times[1]-time_sys),str(ang_vel), str(lin_acc),str(cpu_p),str(100)])
	data = list([time,gps,str(times[0]-time_usr3),str(times[1]-time_sys3), str(100)])
        print(data)
        f.write(','.join(data))
	f.write('\n')
	time_usr3=times[0]
	time_sys3=times[1]

#static_tf2-4
def log_loads4(time,gps):
    global time_sys4
    global time_usr4	
    #print os.getcwd()
    with open('/home/nvidia/catkin_ws/system_loadg4_10W.txt','a') as f:
  	p = psutil.Process(10160)
  	times=p.cpu_times()
#	mem = p.virtual_memory()
        gps = ','.join(map(str,gps))
        time = str(time)
        
#        data = list([time,gps,str(psutil.cpu_percent()),str(100)])
#        data = list([time,gps,str(p.cpu_percent(interval=1)),str(100)])
#        data = list([time,gps,str(times[0]-time_usr),str(times[1]-time_sys),str(ang_vel), str(lin_acc),str(cpu_p),str(100)])
	data = list([time,gps,str(times[0]-time_usr4),str(times[1]-time_sys4), str(100)])
        print(data)
        f.write(','.join(data))
	f.write('\n')
	time_usr4=times[0]
	time_sys4=times[1]
	
#def read_power():
#	global cpu_p	
#	with open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power1_input') as q:
#  		cpu_p=q.read()
##	temp = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power1_input','r').read().split('\n')
#	print cpu_p

#def imu (msg):	  
#	global ang_vel
#	global lin_acc
#	#ang_vel = math.sqrt((2**msg.angular_velocity.x) + 2**(msg.angular_velocity.y) + 2**(msg.angular_velocity.z))
#	#lin_acc = math.sqrt(2**(msg.linear_acceleration.x) + 2**(msg.linear_acceleration.y) + 2**(msg.linear_acceleration.z))
	
def log(msg):
	log_loads1(datetime.datetime.now(),[msg.latitude,msg.longitude])
	log_loads2(datetime.datetime.now(),[msg.latitude,msg.longitude])
	log_loads3(datetime.datetime.now(),[msg.latitude,msg.longitude])
	log_loads4(datetime.datetime.now(),[msg.latitude,msg.longitude])

def util_map():

    rospy.init_node('util_map', anonymous=True)
    rate = rospy.Rate(100) # 10hz
    rospy.Subscriber('/navsat/fix', NavSatFix, log)
    #rospy.Subscriber('/imu/data', Imu, imu)
#    rospy.Subscriber('/fix', NavSatFix, log)
    while not rospy.is_shutdown():

	#read_power()
        rate.sleep()

if __name__ == '__main__':
    try:
	#os.chdir("..")
	#print os.getcwd()
	#absolute_path = os.path.dirname(os.path.abspath(in_power1_input))	
	#print absolute_path
        util_map()
        #os.chdir("../../../..")
    except rospy.ROSInterruptException:
        pass
