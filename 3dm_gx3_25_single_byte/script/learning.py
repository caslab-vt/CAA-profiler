#!/usr/bin/env python


import rospy
#from std_msgs.msg import String
#from std_msgs.msg import Float32MultiArray
#from std_msgs.msg import Int16
#import serial
from array import array
import numpy as np
from numpy import nan
from matplotlib import pyplot as plt
import matplotlib.cm as cm
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.basemap import Basemap
from scipy.stats import multivariate_normal
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neural_network import MLPRegressor
from sklearn.gaussian_process import GaussianProcessRegressor
from sklearn.gaussian_process.kernels import WhiteKernel,RBF, ConstantKernel as C

#import googlemaps
#from datetime import datetime
#gmaps = googlemaps.Client(key='AIzaSyCPH3kqaF9kCARJMyU-TIcWmL6G1UaAnwo')

map = Basemap()

scaler = StandardScaler()
#nn = MLPRegressor(
#    hidden_layer_sizes=(500,),  activation='relu', solver='sgd', alpha=0.0001, batch_size='auto',
#    learning_rate='constant', learning_rate_init=0.01, power_t=0.5, max_iter=5000, shuffle=True,
#    random_state=9, tol=0.0001, verbose=False, warm_start=False, momentum=0.9, nesterovs_momentum=True,
#early_stopping=False, validation_fraction=0.1, beta_1=0.9, beta_2=0.999, epsilon=1e-08)


def learn_map():
#    fname = input("Enter file name: ")
    num_lines = 0
    num_read=0
    num_lines_old = 0
#    lines_=[]
#    pos=np.array([])
#    util=np.array([])
#    pos=[]
#    util=[]
    X=[]
    f = open("system_load_ubtm20190418_roundabout.txt", "r")
    for y in f:
    	x=y.split(',')
#	print(x)
	num_lines += 1
#	print num_lines
#	pos=np.array(pos)
#	util=np.array(util)
        if (x[1]!=nan):
#	    pos.append([(x[1]),(x[2])])
#	    util.append(x[3])
            X.append([(x[1]),(x[2]),x[3]])
#        if num_lines == 250:	   
#	    break

#        if (num_lines-num_lines_old) == 10:
##            pos = pos.reshape(-1, 1)
##            util = util.reshape(-1, 1)
#	    # Fit to data using Maximum Likelihood Estimation of the parameters
##	    gp.fit(pos, util)
#	    break
#    print len(pos)
#    print len(util)
#    pos=np.array(pos,dtype=np.float64)
#    util=np.array(util,dtype=np.float64)
#    pos=np.array(pos).astype(np.float)
#    util=np.array(util).astype(np.float)
    x_train ,x_test = train_test_split(X,test_size=0.2)		#test_size=0.5(whole_data)
    x_test=np.array(x_test).astype(np.float)
    x_train=np.array(x_train).astype(np.float)
    pos=np.array([x_train[:,0], x_train[:,1]]).T
#    print 'pos', pos
    util=np.array(x_train[:,2]).T
#    print util
    x_pred=np.array([x_test[:,0],x_test[:,1]]).T
    y_act=np.array(x_test[:,2]).T
#    print x_train[:,2]
#    pos = pos.reshape(-1, 1)
#    util = util.reshape(-1, 1)
# Instantiate a Gaussian Process model
#    print np.average(util)
# Input space
    a1 = np.linspace(pos[:,0].min(), pos[:,0].max()) #p
    a2 = np.linspace(pos[:,1].min(), pos[:,1].max()) #q
    a = (np.array([a1, a2])).T
    xy = np.column_stack([a1.flat, a2.flat])
    kernel = C(.5, (1e-3, 1e3)) * RBF([.1,.1], [(1e-5, 10), (1e-5, 10)]) + WhiteKernel(noise_level=1)		#set hyperparameters
    gp = GaussianProcessRegressor(kernel=kernel, n_restarts_optimizer=15)
    gp.fit(xy, util)
    
    
    a1 = np.linspace(x_pred[:,0].min(), x_pred[:,0].max()) #p
    a2 = np.linspace(x_pred[:,1].min(), x_pred[:,1].max()) #q
    a = (np.array([a1, a2])).T
    xy = np.column_stack([a1.flat, a2.flat])
    y_pred, sigma = gp.predict(xy, return_std=True)
    print 'pred', y_pred
#    print 'actual', y_act
    print 'std', sigma
    z = multivariate_normal.pdf(xy, mean=y_pred, cov=sigma)
    z = z.reshape(a1.shape)
    samples=np.arange(0,len(y_pred),1)
    Xp, Yp = np.meshgrid(a1, a2)
    ax = plt.axes(projection='3d')
    ax.plot_surface(Xp, Yp, z, rstride=1, cstride=1,
                cmap='viridis', edgecolor='none')
    ax.set_title('surface');

#    #Set up your map
#    
#    fig2 = plt.figure()
#    ax2 = Axes3D(fig2)
#    x, y = map(x_train[:,0], x_train[:,1])
#    
#    ax2.bar3d(x, y, np.zeros(len(x)), 2, 2, util, color= 'r', alpha=0.8)

#    plt.show()
    
    ########################################################################
#    # show hight map in 3d
#    fig = plt.figure()
#    ax = fig.add_subplot(111, projection='3d')
#    Xp, Yp = np.meshgrid(x_train[:,0], x_train[:,1])
#    ax.plot_surface(Xp, Yp, x_train[:,2], rstride=1, cstride=1,
#                cmap='viridis', edgecolor='none')
##    ax.contour3D(Xp, Yp, y_pred, 50, cmap='binary')
##    ax.plot3D(x_pred, y_pred, 'gray')
#    plt.title('comp_time as 3d height map')
#    plt.show()

#    # show hight map in 2d
#    plt.figure() 
#    plt.title('z as 2d heat map')
#    p = plt.imshow(y_pred)
#    plt.colorbar(p)
#    plt.show()    
    
    ######################################################################
#    fig1 = plt.figure()

#    ax1 = fig1.add_subplot(111, projection='3d')
#    ax1.plot_surface(a1,a2,z)
#    plt.show()
    
#    fig = plt.figure()
#    ax = fig.add_subplot(111, projection='3d')
#    Xp, Yp = np.meshgrid(a1, a2)
#    Zp = np.reshape(y_pred,Xp.shape)

#    surf = ax.plot_surface(Xp, Yp, y_pred, rstride=1, cstride=1, cmap=cm.jet,
#    linewidth=1, antialiased=False)
#    plt.show()
    
#    fig_prior = plt.figure(figsize = (20,12))
#    plt.rcParams.update({'font.size': 20})

#    # Draw a mean function and 95% confidence interval
#    plt.plot(samples, y_pred, 'b-', label='mean function')
##    upper_bound = y_pred + 1.96 * sigma
##    lower_bound = y_pred - 1.96 * sigma
##    plt.fill_between(sigma.ravel(), lower_bound, upper_bound, color = 'b', alpha = 0.1,
##                 label='95% confidence interval')
#    plt.plot(samples, y_act, 'g-', label='actual value')
### Draw samples from the posterior and plot
##    X_samples = np.array(np.linspace(-5, 5, 30), ndmin = 2).T
##    seed = np.random.randint(10) # random seed
##    plt.plot(X_samples, gp.sample_y(X_samples, n_samples = 5, random_state = seed), ':')

## Aesthetics
#    plt.xlabel('$x$')
#    plt.ylabel('$f(x)$')
##    plt.xlim(X_test.min(), X_test.max())
##    plt.ylim(-3, 3)
#    plt.legend(loc='upper left')
#    plt.title('Samples(Functions) from a GP prior')
#    plt.show()
    
#    with open('system_load.txt', 'r') as f:
#    
#	for line in f:
##	    lines[num_lines]=f.readline().rstrip()
##	    print lines[num_lines]
#	    lines_.append(line)
#	    print lines_
#	    num_lines += 1
#	    if (num_lines-num_lines_old) == 10:
#	        break
	    
	    
	    
	    
	    
if __name__ == '__main__':
    try:
        learn_map()
        
    except rospy.ROSInterruptException:
        pass
