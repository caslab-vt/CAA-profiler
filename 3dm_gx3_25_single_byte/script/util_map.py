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

def log_loads1():
    global time_sys1
    global time_usr1	
    with open('/home/nvidia/catkin_ws/system_loadpath200.txt','a') as f:
  	p = psutil.Process(12365)
  	times=p.cpu_times()
	util=psutil.cpu_percent()
	mem = psutil.virtual_memory()
        cpu_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power1_input','r').read().split('\n')
        gpu_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power0_input','r').read().split('\n')
        soc_p = open('/sys/bus/i2c/drivers/ina3221x/1-0040/iio_device/in_power2_input','r').read().split('\n')
        #gps = ','.join(map(str,gps))
        time = str(datetime.datetime.now())
        
#        data = list([time,gps,str(psutil.cpu_percent()),str(100)])
#        data = list([time,gps,str(p.cpu_percent(interval=1)),str(100)])
#        data = list([time,gps,str(times[0]-time_usr),str(times[1]-time_sys),str(ang_vel), str(lin_acc),str(cpu_p),str(100)])
	data = list([time,str(times[0]-time_usr1),str(times[1]-time_sys1), str(util), str(mem[3]), str(cpu_p[0]), str(gpu_p[0]), str(soc_p[0]), str(100)])
        print(data)
        f.write(','.join(data))
	f.write('\n')
	time_usr1=times[0]
	time_sys1=times[1]

def imu (msg):	  
	global ang_vel
	global lin_acc
	#ang_vel = math.sqrt((2**msg.angular_velocity.x) + 2**(msg.angular_velocity.y) + 2**(msg.angular_velocity.z))
	#lin_acc = math.sqrt(2**(msg.linear_acceleration.x) + 2**(msg.linear_acceleration.y) + 2**(msg.linear_acceleration.z))
	
def log(msg):
	log_loads1(datetime.datetime.now(),[msg.latitude,msg.longitude])

def util_map():

    rospy.init_node('util_map', anonymous=True)
    rate = rospy.Rate(7) # 10hz
    #rospy.Subscriber('/navsat/fix', NavSatFix, log)
    #rospy.Subscriber('/imu/data', Imu, imu)
#    rospy.Subscriber('/fix', NavSatFix, log)
    while not rospy.is_shutdown():
	log_loads1()
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
