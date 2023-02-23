
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>

// #include <cuda.h>
// #include <cuda_runtime.h>

#include "rrt.hpp"
#include "collision_check.h"

double distance(const double *p1, const double *p2)
{
  const double dx = p1[0] - p2[0];
  const double dy = p1[1] - p2[1];

  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}


RRT::RRT(double *start, double *goal, int rando,int xmax,int ymax)
        : start_(start),
          goal_(goal),
          delta_(0.05),
          epsilon_(0),
          xmin_(0),
          xmax_(xmax),
          ymin_(0),
          ymax_(ymax),
          resolution_(1.0),
          max_iter_(100000),
          vertex_count_(0)
{
  // // add start to graph
  // vertex v_start;
  // v_start.x = start[0];
  // v_start.y = start[1];
  // addVertex(v_start);

  // seed random generator
  std::srand(rando);
}

bool RRT::collision_check(const vertex &v_new, const vertex &v_near)
{
  for(unsigned int i = 0; i < circles_.size(); i++)
  {
    Circle circ = circles_.at(i);
    const double p3[2] = {circ.x, circ.y};
    const double p1[2] = {v_new.x, v_new.y};
    const double p2[2] = {v_near.x, v_near.y};
    const double num = (p3[0]-p1[0])*(p2[0]-p1[0]) + (p3[1]-p1[1])*(p2[1]-p1[1]);
    const double denom = std::pow((p2[0]-p1[0]), 2) + std::pow((p2[1]-p1[1]), 2); //trying distance squared
    const double u = num/denom;

    const double x = p1[0] + u*(p2[0]-p1[0]);
    const double y = p1[1] + u*(p2[1]-p1[1]);
    const double P[2] = {x,y};

    const double dist_to_line = distance(P, p3);

    //if shortest distance to line lays outside circle youre good
    // std::cout << "circ at: " << circ.x << ", " << circ.y << std::endl;
    // std::cout << "dist to line: " << dist_to_line << " radius: " << circ.r << std::endl;
    if (dist_to_line > circ.r){
      continue;
    }

    //now we know the shortest distance lays within the circle
    //must determine if its on the line or merely the ray

    //check if either point exists in circle
    const double dist_p1 = distance(p1,p3);
    // const double dist_p2 = distance(p2,p3);

    if ((dist_p1 > circ.r) /*&& (dist_p2 > circ.r)*/)
    {
      //check if the shortest point exists on line
      if ((u < 1) && (u > 0))
      {
        return true;
      }
      else
      {
        continue;
      }
    }
    else
    {
      //one of the end points of line in circle
      return true;
    }

  }

  return false;
}

bool RRT::exploreObstacles()
{
  // add start to graph
  vertex v_start;
  v_start.x = start_[0];
  v_start.y = start_[1];
  addVertex(v_start);


  bool success = false;
  int ctr = 0;


  while(!success)
  {
    if (ctr > max_iter_)
    {
      std::cout << "Goal not achieved" << std::endl;
      return false;
    }

    // std::cout << "Iter: " << ctr << std::endl;

    // 1) random point
    double q_rand[2];
    randomConfig(q_rand);

    // 2) nearest node in graph
    vertex v_near;
    nearestVertex(v_near, q_rand);

    // 3) new node
    vertex v_new;
    if(!newConfiguration(v_new, v_near, q_rand))
    {
      continue;
    }

    // std::cout << "v new at: " << v_new.x << ", " << v_new.y <<std::endl;

    ctr++;

    // 4) check for collisions
    if (collision_check(v_new, v_near))
    {
      // std::cout << "Collision" << std::endl;
      continue;
    }


    // std::cout << v_new.x << " " << v_new.y << "\n";

    // 6) add new node
    addVertex(v_new);
    addEdge(v_near, v_new);

    // 7) win check
    bool win_flag = win_check(v_new, goal_);

    if (win_flag)
    {
      std::cout << "Goal reached on CPU" << std::endl;
      // add goal to graph
      vertex v_goal;
      v_goal.x = goal_[0];
      v_goal.y = goal_[1];
      addVertex(v_goal);
      addEdge(v_new, v_goal);

      success = true;
      break;
    }


  }

  return success;
}


bool RRT::win_check(const vertex &v_new, const double *goal)
{
  //cast goal to vertex //TODO: overlead collision to optionally take double as second arg
  vertex v_goal(goal[0],goal[1]);
  // std::cout << "SURUR\n";
  bool collis_check = collision_check(v_new, v_goal);

  return !collis_check;
}


bool RRT::exploreCuda()
{
  ////////////////////////////////////////////////////////////////////////////
  // set up variables for host
  uint32_t num_circles = circles_.size();
  // float3 *h_c = (float3 *)malloc(num_circles * sizeof(float3));

  // size of grid
  // uint32_t x_size = std::ceil((xmax_ - xmin_) / resolution_);
  // uint32_t y_size = std::ceil((ymax_ - ymin_) / resolution_);
  // uint32_t grid_size = x_size * y_size;

  // max circles per grid cell
  // uint32_t max_circles_cell = 100;
  // uint32_t mem_size = max_circles_cell * grid_size;

  // float3 *h_bins = (float3 *)malloc(mem_size * sizeof(float3));


  float *h_x = (float *)malloc(num_circles * sizeof(float));
  float *h_y = (float *)malloc(num_circles * sizeof(float));
  float *h_r = (float *)malloc(num_circles * sizeof(float));
  float *h_qnew = (float *)malloc(2 * sizeof(float));
  float *h_qnear = (float *)malloc(2 * sizeof(float));
  uint32_t *h_flag = (uint32_t *)malloc(sizeof(uint32_t));

  // fill circles with data
  circleData(h_x, h_y, h_r);
  // circleDatafloat3(h_c);

  // for(int i = 0; i < num_circles; i++)
  // {
  //    printf("[x: %f y: %f r: %f] \n", h_c[i].x, h_c[i].y, h_c[i].z);
  // }


  /////////////////////_///////////////////////////////////////////////////////
  // set up variables for device
  // float3 *d_c = (float3 *)allocateDeviceMemory(num_circles * sizeof(float3));
  // float3 *d_bins = (float3 *)allocateDeviceMemory(mem_size * sizeof(float3));

  float *d_x = (float *)allocateDeviceMemory(num_circles * sizeof(float));
  float *d_y = (float *)allocateDeviceMemory(num_circles * sizeof(float));
  float *d_r = (float *)allocateDeviceMemory(num_circles * sizeof(float));
  float *d_qnew = (float *)allocateDeviceMemory(2 * sizeof(float));
  float *d_qnear = (float *)allocateDeviceMemory(2 * sizeof(float));
  uint32_t *d_flag = (uint32_t *)allocateDeviceMemory(sizeof(uint32_t));


  copyToDeviceMemory(d_x, h_x, num_circles * sizeof(float));
  copyToDeviceMemory(d_y, h_y, num_circles * sizeof(float));
  copyToDeviceMemory(d_r, h_r, num_circles * sizeof(float));

  // copy circles to device
  // copyToDeviceMemory(d_c, h_c, num_circles * sizeof(float3));

  ////////////////////////////////////////////////////////////////////////////
  // pre process grid
  // bin_call(d_c, d_bins, mem_size);
  //
  // copyToHostMemory(h_bins, d_bins, mem_size * sizeof(float3));


  // for(int i = 0; i < max_circles_cell; i++)
  // {
  //   for(int j = 0; j < grid_size; j++)
  //   {
  //     int index = j * max_circles_cell + i;
  //     printf("[x: %f y: %f r: %f] ", h_bins[index].x, h_bins[index].y, h_bins[index].z);
  //   }
  //   printf("\n");
  // }


  // ////////////////////////////////////////////////////////////////////////////

  // start RRT
  // clear graph each time
  vertices_.clear();
  vertex_count_ = 0;

  // add start to graph
  vertex v_start;
  v_start.x = start_[0];
  v_start.y = start_[1];
  addVertex(v_start);


  bool success = false;
  int ctr = 0;


  while(!success)
  {
    if (ctr == max_iter_)
    {
      std::cout << "Goal not achieved" << std::endl;
      return false;
    }


    // 1) random point
    double q_rand[2];
    randomConfig(q_rand);

    // 2) nearest node in graph
    vertex v_near;
    nearestVertex(v_near, q_rand);

    // 3) new node
    vertex v_new;
    if(!newConfiguration(v_new, v_near, q_rand))
    {
      continue;
    }


    ////////////////////////////////////////////////////////////////////////////
    // call device for obstacle collisions
    // 4)/5) collision btw new vertex and circles

    h_qnew[0] = ((float)v_new.x);
    h_qnew[1] = ((float)v_new.y);

    h_qnear[0] = ((float)v_near.x);
    h_qnear[1] = ((float)v_near.y);

    // copy nominal new vertex
    copyToDeviceMemory(d_qnew, h_qnew, 2 * sizeof(float));
    // copy nearest vertex
    copyToDeviceMemory(d_qnear, h_qnear, 2 * sizeof(float));


    // calls obstalce kernel
    // collision_call_1(d_x, d_y, d_r, d_qnew, d_qnear, d_flag);
    collision_call_2(d_x, d_y, d_r, d_qnew, d_qnear, d_flag, num_circles);
    // collision_call_3(d_x, d_y, d_r, d_qnew, d_qnear, d_flag);



    // copy flag to host
    copyToHostMemory(h_flag, d_flag, sizeof(uint32_t));


    ////////////////////////////////////////////////////////////////////////////


    ctr++;

    // if (ctr % 100 == 0)
    // {
    //   std::cout << "count " << ctr << std::endl;
    // }


    if (((int)*h_flag))
    {
      // std::cout << "Collision" << std::endl;
      continue;
    }



    // std::cout << v_new.x << " " << v_new.y << "\n";

    // 6) add new node
    addVertex(v_new);
    addEdge(v_near, v_new);


    // 7) win check
    bool win_flag = win_check(v_new, goal_);

    if (win_flag)
    {
      std::cout << "CUDA Goal reached" << std::endl;
      // add goal to graph
      vertex v_goal;
      v_goal.x = goal_[0];
      v_goal.y = goal_[1];
      addVertex(v_goal);
      addEdge(v_new, v_goal);

      success = true;
      break;
    }

  }

  ////////////////////////////////////////////////////////////////////////////
  // tear down host variables
  // free(h_c);
  // free(h_bins);
  free(h_x);
  free(h_y);
  free(h_r);
  free(h_qnew);
  free(h_qnear);
  free(h_flag);

  ////////////////////////////////////////////////////////////////////////////
  // tear down device variables
  // freeDeviceMemory(d_c);
  // freeDeviceMemory(d_bins);
  freeDeviceMemory(d_x);
  freeDeviceMemory(d_y);
  freeDeviceMemory(d_r);
  freeDeviceMemory(d_qnew);
  freeDeviceMemory(d_qnear);
  freeDeviceMemory(d_flag);

  return success;
}


double RRT::randomCircles(int num_cirles, double r_min, double r_max)
{

	double area=0;

  for(int i = 0; i < num_cirles; i++)
  {
    // circle center within bounds of world
    const double x = xmin_+static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(xmax_-xmin_)));
    const double y = xmin_+static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(xmax_-xmin_)));

    // radius between r_min and r_max;
    const double r = r_min+static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(r_max-r_min)));

    const double center[] = {x, y};

    // make sure start and goal are not within an obstacle
    const double d_init = distance(center, start_);
    const double d_goal = distance(center, goal_);


    if (d_init > r + epsilon_ and d_goal > r + epsilon_)
    {
      Circle c;
      c.x = x;
      c.y = y;
      c.r = r;

      circles_.push_back(c);
	area+=3.14159*r*r;
    }
  }

  // for(const auto &circle: circles_)
  // {
  //   std::cout << "Circle: " << circle.r << " [" << circle.x << " " << circle.y << "]" << std::endl;
  // }
return area;
}



void RRT::circleData(float *h_x, float *h_y, float *h_r)
{
  for(unsigned int i = 0; i < circles_.size(); i++)
  {
    h_x[i] = ((float)circles_.at(i).x);

    h_y[i] = ((float)circles_.at(i).y);

    h_r[i] = ((float)circles_.at(i).r);
  }
}


void RRT::circleDatafloat3(float3 *h_c)
{
  for(unsigned int i = 0; i < circles_.size(); i++)
  {
    h_c[i].x = ((float)circles_.at(i).x);

    h_c[i].y = ((float)circles_.at(i).y);

    h_c[i].z = ((float)circles_.at(i).r);
  }
}



void RRT::traverseGraph(std::vector<vertex> &path) const
{
  // path.reserve(vertices_.size());
  std::ofstream pathout;
  pathout.open("rrtout/path.csv");

  int start_idx = 0;                  // first vertex added
  int goal_idx = vertex_count_-1;  // last vertex added


  // std::cout << "start: " << start_idx << std::endl;
  // std::cout << "goal: " << goal_idx << std::endl;


  // path is backwards
  path.push_back(vertices_.at(goal_idx));

  // current vertex is the goal
  vertex curr_v = vertices_.at(goal_idx);
  int curr_idx = goal_idx;


  while(curr_idx != start_idx)
  {

    int parent_idx = findParent(curr_v);
    pathout << vertices_.at(curr_idx).x << "," << vertices_.at(curr_idx).y << "," << vertices_.at(parent_idx).x << "," << vertices_.at(parent_idx).y << "\n";

    path.push_back(vertices_.at(parent_idx));

    // update current node and current index
    curr_v = vertices_.at(parent_idx);
    curr_idx = parent_idx;
  }
}



void RRT::printGraph() const
{
  for(unsigned int i = 0; i < vertices_.size(); i++)
  {
    std::cout << "vertex: " << vertices_.at(i).id << " -> ";
    for(unsigned int j = 0; j < vertices_.at(i).adjacent_vertices.size(); j++)
    {
      std::cout << vertices_.at(i).adjacent_vertices.at(j) << " ";
    }
    std::cout << std::endl;
  }
}

void RRT::visualizeGraph() const
{
  std::ofstream obstacles;
  std::ofstream graph;
  obstacles.open("rrtout/obstacles.csv");
  graph.open("rrtout/graph.csv");
  double x1, y1;
  int mark;

  if (graph.is_open())
  {
    std::cout << "rrtout/graph.csv is open" << std::endl;
  }

if (obstacles.is_open())
  {
    std::cout << "rrtout/obstacles.csv is open" << std::endl;
  }

  //log obstacles
  for (unsigned int i = 0; i < circles_.size(); i++){
    obstacles << circles_.at(i).x << "," << circles_.at(i).y << "," << circles_.at(i).r << "\n";
  }

  //log graph (nodes and vertices)
  for(unsigned int i = 0; i < vertices_.size(); i++)
  {

    //mark if root or goal -1 for root, 1 for goal, 0 for all else
    if (i == 0){
      mark = -1;
    } else if (i == (vertices_.size() -1)){ //TODO: figure out why its not setting last el to 1
      mark = 1;
    } else {
      mark = 0;
    }

    x1 = vertices_.at(i).x;
    y1 = vertices_.at(i).y;

    for(unsigned int j = 0; j < vertices_.at(i).adjacent_vertices.size(); j++)
    {
      int v_id = vertices_.at(i).adjacent_vertices.at(j);
      graph << vertices_.at(v_id).x << "," << vertices_.at(v_id).y << "," << x1 << "," << y1 << "," << mark << "\n";
    }

  }

  graph << goal_[0] << "," << goal_[1] << "," << vertices_.back().x << "," << vertices_.back().y << "," << 1 <<"\n";

  obstacles.close();
  graph.close();
}


void RRT::addVertex(vertex &v)
{
  v.id = vertex_count_;

  vertices_.push_back(v);
  vertex_count_++;

  // std::cout << "New vertex count: " << vertex_count_ << std::endl;
}



void RRT::addEdge(const vertex &v_near, const vertex &v_new)
{
  // search for node1 and node2
  // addes edge btw both
  bool added = false;


  for(unsigned int i = 0; i < vertices_.size(); i++)
  {
    // found node 1
    if (vertices_.at(i).id == v_near.id)
    {
      for(unsigned int j = 0; j < vertices_.size(); j++)
      {
        // do not add vertex to itself
        // found node 2
        if(vertices_.at(j).id == v_new.id && i != j)
        {
          // edge connecting node 1 to node 2
          // std::cout << "adding edge " << v_near.id << "->" << v_new.id << std::endl;
          // v_near.adjacent_vertices.push_back(v_new.id);
          vertices_.at(v_near.id).adjacent_vertices.push_back(v_new.id);
          added = true;
        }

      } // end inner loop
    }
  } // end outer loop

  if (!added)
  {
    std::cout << "Error: 'addEdge' edge not added" << std::endl;
  }
}


bool RRT::newConfiguration(vertex &v_new, const vertex &v_near, const double *q_rand) const
{

  // difference btw q_rand and v_near
  const double vx = q_rand[0] - v_near.x;
  const double vy = q_rand[1] - v_near.y;

  // distance between v_near and q_rand
  const double magnitude = std::sqrt(std::pow(vx, 2) + std::pow(vy, 2));

  if (magnitude == 0)
  {
    return false;
  }

  // unit vector in driection of q_rand
  const double ux = vx / magnitude;
  const double uy = vy / magnitude;

  // place v_new a delta away from v_near
  v_new.x = v_near.x + delta_ * ux;
  v_new.y = v_near.y + delta_ * uy;

  // make sure still within bounds
  if (v_new.x > xmax_ || v_new.x < xmin_ || v_new.y > ymax_ || v_new.y < ymin_)
  {
    return false;
  }

  return true;
}



void RRT::nearestVertex(vertex &v, double *q_rand) const
{
  double point[2];
  std::vector<double> d;

  for(unsigned int i = 0; i < vertices_.size(); i++)
  {
    point[0] = vertices_.at(i).x;
    point[1] = vertices_.at(i).y;

    d.push_back(distance(point, q_rand));
  }

  // index of nearest node
  const int idx = std::min_element(d.begin(), d.end()) - d.begin();

  // int idx = 0;
  // double smallest = d.at(0);
  //
  // for(unsigned int i = 1; i < d.size(); i++)
  // {
  //   if(d.at(i) < smallest)
  //   {
  //     smallest = d.at(i);
  //     idx = i;
  //   }
  // }

  // std::cout << "minElementIndex:" << idx
  //     << ", minElement: [" << vertices_[idx].x << " " << vertices_[idx].y << "]\n";

  // vertex v_near = vertices_.at(idx);
  v = vertices_.at(idx);
}



void RRT::randomConfig(double *q_rand) const
{
  // x position
  q_rand[0] = xmin_+static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(xmax_-xmin_)));

  // y position
  q_rand[1] = ymin_+static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX/(ymax_-ymin_)));
}

int RRT::findParent(const vertex &v) const
{
  // iterate over vertices
  for(unsigned int i = 0; i < vertices_.size(); i++)
  {
    for(unsigned int j = 0; j < vertices_.at(i).adjacent_vertices.size(); j++)
    {
      if (vertices_.at(i).adjacent_vertices.at(j) == v.id)
      {
        // std::cout << "Parent found" << std::endl;
        return i;
      }
    } // end inner loop
  } // end outer loop

  std::cout << "Parent not found" << std::endl;
  return -1;
}










// end file
