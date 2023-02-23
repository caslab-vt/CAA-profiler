# This file is subject to the terms and conditions defined in
# file 'LICENSE', which is part of this source code package.
import sys
sys.path.append('./rrt_algorithms')

import numpy as np
from time import time
from src.rrt.rrt import RRT
from src.search_space.search_space import SearchSpace
from src.utilities.obstacle_generation import generate_random_obstacles
#from src.utilities.plotting import Plot

i=0
t1=0
t2=0
with open('/home/nvidia/catkin_ws/rta_rrt1_fprtest_ffmax.txt','a') as f:
	while i<50000:
		t1=time()

		X_dimensions = np.array([(0, 1000), (0, 1000)])  # dimensions of Search Space
		x_init = (0, 0)  # starting location
		x_goal = (1000, 1000)  # goal location

		Q = np.array([(8, 4)])  # length of tree edges
		r = 1  # length of smallest edge to check for intersection with obstacles
		max_samples = 20480  # max number of samples to take before timing out
		prc = 0.1  # probability of checking for a connection to goal

		# create search space
		X = SearchSpace(X_dimensions)
		n = 100
		Obstacles = generate_random_obstacles(X, x_init, x_goal, n)
		# create rrt_search
		rrt = RRT(X, Q, x_init, x_goal, max_samples, r, prc)
		path = rrt.rrt_search()
		t2=time()
		data=list([str(t1),str(t2-t1)])
		f.write(','.join(data))
		f.write('\n')
		print(data)
		i=i+1


# plot
#plot = Plot("rrt_2d_with_random_obstacles")
#plot.plot_tree(X, rrt.trees)
#if path is not None:
#    plot.plot_path(X, path)
#plot.plot_obstacles(X, Obstacles)
#plot.plot_start(X, x_init)
#plot.plot_goal(X, x_goal)
#plot.draw(auto_open=True)
