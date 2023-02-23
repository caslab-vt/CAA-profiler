#!/usr/bin/env python

#
# Revision $Id$
from fractions import Fraction
import rospy
import rostopic
import random
#from std_msgs.msg import String
#from std_msgs.msg import Float32MultiArray
from std_msgs.msg import Int16
import serial
from array import array
import numpy as np
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Imu
import os
import subprocess
import datetime
from time import time
#r = rostopic.ROSTopicHz(-1)
#s = rospy.Subscriber('/navsat/fix', rospy.AnyMsg, r.callback_hz, callback_args='/navsat/fix')
#rospy.sleep(1)
#r.print_hz(['/navsat/fix'])
#abc=r.print_hz(['/navsat/fix'])
#print(abc)
#print(abc)
abc=[]

def log():
	global abc
	#log_loads1(time(),[msg.latitude,msg.longitude])
	with open('/home/nvidia/catkin_ws/test_topic.txt','a') as f:
		data=[str(abc)]
 		f.write(','.join(data))
		f.write('\n')	

def test_rostopic():
    global abc
    i=0
    rospy.init_node('test_rostopic', anonymous=True)
    rate = rospy.Rate(10) # 10hz
#    r = rostopic.ROSTopicHz(-1)
#    s = rospy.Subscriber('/navsat/fix', rospy.AnyMsg, r.callback_hz, callback_args='/navsat/fix')
#    #rospy.Subscriber('/navsat/fix', NavSatFix, log)
    #rospy.Subscriber('/imu/data', Imu, imu)
    while not rospy.is_shutdown():
	command="rostopic hz /navsat/fix"
	with open('output.txt','a') as outfile:
            outfile.write(os.popen(command).read()+"\n")

#	os.system(cmd + " 1>/home/nvidia/catkin_ws/log.txt" + " 2>/home/nvidia/catkin_ws/Error.txt")
	#abc=r.print_hz(['/navsat/fix'])
	    print("reniced \n ")
	#print(abc)
	#read_power()
	rate.sleep()
    #log()

if __name__ == '__main__':
    try:
	test_rostopic()
        #os.chdir("../../../..")
    except rospy.ROSInterruptException:
        pass
