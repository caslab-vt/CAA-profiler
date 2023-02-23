#!/usr/bin/env python3.6


#import rospy
#from std_msgs.msg import String
#from std_msgs.msg import Float32MultiArray
#from std_msgs.msg import Int16
#import serial
from array import array
import numpy as np
from numpy import nan
from numpy import meshgrid
import matplotlib
from matplotlib import pyplot as plt
import matplotlib.cm as cm
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits import mplot3d
from mpl_toolkits.basemap import Basemap
#from scipy.stats import multivariate_normal
from sklearn.model_selection import train_test_split
#from sklearn.preprocessing import StandardScaler
#from sklearn.neural_network import MLPRegressor
#from sklearn.gaussian_process import GaussianProcessRegressor
#from sklearn.gaussian_process.kernels import WhiteKernel,RBF, ConstantKernel as C
import gmaps
import gpytorch
import torch
import math

num_lines = 0
num_read=0
num_lines_old = 0

# setting parameters for title and axes ##basemap
font = {'family' : 'verdana',
        'size'   : 16}
matplotlib.rc('font', **font)
# Use google maps api
gmaps.configure(api_key='AIzaSyANeVkUuKIp9QPNrnJ9vo_de5IZZZ7MC44') # Fill in with your API key

#for i in range(len(grid_bounds)):
#    grid_diff = float(grid_bounds[i][1] - grid_bounds[i][0]) / (grid_size - 2)
#    grid[:, i] = torch.linspace(grid_bounds[i][0] - grid_diff, grid_bounds[i][1] + grid_diff, grid_size)

#train_x = gpytorch.utils.grid.create_data_from_grid(grid)
#train_y = torch.sin((train_x[:, 0] + train_x[:, 1]) * (2 * math.pi)) + torch.randn_like(train_x[:, 0]).mul(0.01)
X=[]
f = open("system_load7-25-gmap2.txt", "r")
for y in f:
    x=y.split(',')
#	print(x)
    num_lines += 1
#	print num_lines
#	pos=np.array(pos)
#	util=np.array(util)
    if (x[1]!=nan):
	    X.append([(x[1]),(x[2]),(x[3]),(x[4])])
#        if num_lines == 250:	   
#	    	break

x_train ,x_test = train_test_split(X,test_size=0.1)		#test_size=0.5(whole_data)
x_test=np.array(x_test).astype(np.double)
x_train=np.array(x_train).astype(np.double)
#print(x_train)
pos=np.array([x_train[:,0], x_train[:,1]]).T
#    print 'pos', pos
util=np.array(x_train[:,2]).T
#    print util
x_pred=np.array([x_test[:,0],x_test[:,1]]).T
y_act=np.array(x_test[:,2]).T
#print(pos)
#print(util)
X=np.array(X).astype(np.double)
print(X[:,0])
print(X[:,1])



############################################################################
#lats= np.array(X[:,0])
#lons= np.array(X[:,1])
#altitude= np.array(X[:,3])


#Get the locations from the data set
locations = X[:,0:2]
print("locations",locations)
weights = X[:,3]
fig1 = gmaps.figure()
fig1.add_layer(gmaps.heatmap_layer(locations, weights=weights,max_intensity=30, point_radius=3.0)
gmaps.draw(fig1)

####################################################################################
## How much to zoom from coordinates (in degrees)
#zoom_scale = 1

# Setup the bounding box for the zoom and bounds of the map
bbox = [np.min(lats),np.max(lats),\
        np.min(lons),np.max(lons)]
        
#f, ax = plt.subplots(1, 1, figsize=(10, 8))

fig, ax = plt.subplots(1, 1,figsize=(10,10))
plt.title("util_map")
# Define the projection, scale, the corners of the map, and the resolution.
m = Basemap(projection='merc',llcrnrlat=bbox[0],urcrnrlat=bbox[1],\
            llcrnrlon=bbox[2],urcrnrlon=bbox[3],lat_ts=10,resolution='i')

## Draw coastlines and fill continents and water with color
#m.drawcoastlines()
#m.fillcontinents(color='#CCCCCC',lake_color='lightblue')

# draw parallels, meridians, and color boundaries
m.drawparallels(np.arange(bbox[0],bbox[1],(bbox[1]-bbox[0])/5),labels=[1,0,0,0])
m.drawmeridians(np.arange(bbox[2],bbox[3],(bbox[3]-bbox[2])/5),labels=[0,0,0,1],rotation=15)
m.drawmapboundary(fill_color='lightblue')

# format colors for elevation range
alt_min = np.min(altitude)
alt_max = np.max(altitude)
cmap = plt.get_cmap('gist_earth')
normalize = matplotlib.colors.Normalize(vmin=alt_min, vmax=alt_max)

# plot elevations with different colors using the numpy interpolation mapping tool
# the range [50,200] can be changed to create different colors and ranges
for ii in range(0,len(altitude)):
    x,y = m(lons[ii],lats[ii])
    color_interp = np.interp(altitude[ii],[alt_min,alt_max],[50, 500])
    plt.plot(x,y,3,marker='o',color=cmap(int(color_interp)))

#x,y=meshgrid(lats,lons)
#cs = m.contourf(x,y,altitude,30,cmap=plt.cm.jet)

# format the colorbar 
cax, _ = matplotlib.colorbar.make_axes(ax)
cbar = matplotlib.colorbar.ColorbarBase(cax, cmap=cmap,norm=normalize,label='computational time')

# save the figure and show it
fig.savefig('computation heat map_7-25-gmap2.png', format='png', dpi=500,transparent=False)
#plt.show()
#######################################################################################3


#grid_bounds = [(X[:,0].min(), X[:,0].max()), (X[:,1].min(), X[:,1].max())]
grid_bounds = [(x_train[:,0].min(), x_train[:,0].max()), (x_train[:,1].min(), x_train[:,1].max())]
grid_size = 100
grid = torch.zeros(grid_size, len(grid_bounds))

for i in range(len(grid_bounds)):
    grid_diff = float(grid_bounds[i][1] - grid_bounds[i][0]) / (grid_size - 2)
    grid[:, i] = torch.linspace(grid_bounds[i][0] - grid_diff, grid_bounds[i][1] + grid_diff, grid_size)

#test_x = gpytorch.utils.grid.create_data_from_grid(grid)
#test_x=test_x.double()
#print('test_x')
#print(test_x)

pos=torch.from_numpy(pos).double()
util=torch.from_numpy(util).double()
samples_train=np.arange(0,len(util),1)
x_pred=torch.from_numpy(x_pred).double()
#y_act=torch.from_numpy(y_act).double()
samples_test=np.arange(0,len(y_act),1)

class GridGPRegressionModel(gpytorch.models.ExactGP):
    def __init__(self, grid, pos, util, likelihood):
        super(GridGPRegressionModel, self).__init__(pos, util, likelihood)
        num_dims = pos.size(-1)
        self.mean_module = gpytorch.means.ConstantMean()
        self.covar_module = gpytorch.kernels.GridKernel(gpytorch.kernels.RBFKernel(), grid=grid)

    def forward(self, x):
        mean_x = self.mean_module(x)
        covar_x = self.covar_module(x)
        return gpytorch.distributions.MultivariateNormal(mean_x, covar_x)

likelihood = gpytorch.likelihoods.GaussianLikelihood()
model = GridGPRegressionModel(grid, pos, util, likelihood).double()



# Find optimal model hyperparameters
model.train()
likelihood.train()

# Use the adam optimizer
optimizer = torch.optim.Adam([
    {'params': model.parameters()},  # Includes GaussianLikelihood parameters
], lr=0.1)

# "Loss" for GPs - the marginal log likelihood
mll = gpytorch.mlls.ExactMarginalLogLikelihood(likelihood, model)

training_iter = 100
for i in range(training_iter):
    # Zero gradients from previous iteration
    optimizer.zero_grad()
    # Output from model
    output = model(pos)
    # Calc loss and backprop gradients
    loss = -mll(output, util)
    loss.backward()
    print('Iter %d/%d - Loss: %.3f   lengthscale: %.3f   noise: %.3f' % (
        i + 1, training_iter, loss.item(),
        model.covar_module.base_kernel.lengthscale.item(),
        model.likelihood.noise.item()
    ))
    optimizer.step()

##put the model and likelihood in eval mode
model.eval()
likelihood.eval()
#n = max(x_pred[:,0].max()-x_pred[:,0].min(),x_pred[:,1].max()-x_pred[:,1].min()).data
#n=int(n)
#print(n)
n=40
#test_x = torch.zeros(int(pow(n, 2)), 2)


#with torch.no_grad(), gpytorch.settings.fast_pred_var():
#    observed_pred = likelihood(model(x_pred))


#x = np.linspace(X[:,0].min(), X[:,0].max(), 100)
#y = np.linspace(X[:,1].min(), X[:,1].max(), 100)
#X, Y = np.meshgrid(x, y)

with torch.no_grad(), gpytorch.settings.fast_pred_var():
    observed_pred = likelihood(model(x_pred))

pred_labels = observed_pred.mean.numpy()

#test_x=np.array(test_x)
#print(test_x)
          
#fig = plt.figure()
#ax = fig.add_subplot(111, projection='3d')
#ax.plot_surface(test_x[:,0],test_x[:,1], observed_pred)
#fig.show()

# Calc abosolute error
#test_y_actual = torch.sin(((test_x[:, 0] + test_x[:, 1]) * (2 * math.pi))).view(n, n)
#delta_y = torch.abs(pred_labels - y_act).detach().numpy()
delta_y = np.abs(pred_labels - y_act)
#dy, bin_edges = np.histogram(delta_y, bins=10)
#bin_centers = 0.5*(bin_edges[1:] + bin_edges[:-1])
#plt.errorbar(
#    bin_centers,
#    y,
#    yerr = y**0.5,
#    marker = '.',
#    drawstyle = 'steps-mid-'
#)
#plt.show()

with torch.no_grad():
    # Initialize plot
    f, ax = plt.subplots(1, 1, figsize=(10, 8))

    # Get upper and lower confidence bounds
    lower, upper = observed_pred.confidence_region()
    # Plot training data as black stars
    ax.plot(samples_test, y_act, 'k*')
    # Plot predictive means as blue line
    ax.plot(samples_test, pred_labels, 'b')
    # Shade between the lower and upper confidence bounds
    ax.fill_between(samples_test, lower.numpy(), upper.numpy(), alpha=0.5)
#    ax.set_ylim([-3, 3])
    ax.legend(['Observed Data', 'Mean', 'Confidence'])

## Define a plotting function
#def ax_plot(f, ax, y_labels, title):
#    im = ax.imshow(y_labels)
#    ax.set_title(title)
#    f.colorbar(im)

## Plot our predictive means
#f, observed_ax = plt.subplots(1, 1, figsize=(4, 3))
#ax_plot(f, observed_ax, pred_labels, 'Predicted Values (Likelihood)')
##plt.show()
f.savefig('gpr_7-25-loam2.png', bbox_inches='tight')

## Plot the true values
#f, observed_ax2 = plt.subplots(1, 1, figsize=(4, 3))
#ax_plot(f, observed_ax2, y_act, 'Actual Values (Likelihood)')

## Plot the absolute errors
#f, observed_ax3 = plt.subplots(1, 1, figsize=(4, 3))
#ax_plot(f, observed_ax3, delta_y, 'Absolute Error Surface')

#def learn_map():

##    fname = input("Enter file name: ")
#    num_lines = 0
#    num_read=0
#    num_lines_old = 0
##    lines_=[]
##    pos=np.array([])
##    util=np.array([])
##    pos=[]
##    util=[]
#    X=[]
#    f = open("system_load.txt", "r")
#    for y in f:
#    	x=y.split(',')
##	print(x)
#	num_lines += 1
##	print num_lines
##	pos=np.array(pos)
##	util=np.array(util)
#        if (x[1]!=nan):
##	    pos.append([(x[1]),(x[2])])
##	    util.append(x[3])
#            X.append([(x[1]),(x[2]),x[3]])
##        if num_lines == 250:	   
##	    break

##        if (num_lines-num_lines_old) == 10:
###            pos = pos.reshape(-1, 1)
###            util = util.reshape(-1, 1)
##	    # Fit to data using Maximum Likelihood Estimation of the parameters
###	    gp.fit(pos, util)
##	    break

#    x_train ,x_test = train_test_split(X,test_size=0.2)		#test_size=0.5(whole_data)
#    x_test=np.array(x_test).astype(np.float)
#    x_train=np.array(x_train).astype(np.float)
#    pos=np.array([x_train[:,0], x_train[:,1]]).T
##    print 'pos', pos
#    util=np.array(x_train[:,2]).T
##    print util
#    x_pred=np.array([x_test[:,0],x_test[:,1]]).T
#    y_act=np.array(x_test[:,2]).T
    
    
    
#if __name__ == '__main__':
#    try:
#        learn_map()
        
#    except rospy.ROSInterruptException:
#        pass
