#include <cstdlib>
#include <iostream>
#include <cutil.h>
#include "rrt.hpp"
#include <ctime>
#include <chrono>

double get_time_point() {
    std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(current_time.time_since_epoch()).count();
}


int main(int argc, char * argv[])
{
	FILE *fp;
	fp = fopen("RRT_time.txt", "w");
  printf("\n\n**===-------------------------------------------------===**\n");
  printf("\n\n**===--- RRT ---===**\n");
  printf("\n\n**===-------------------------------------------------===**\n");
  double start[] = {5,50};
  double goal[] = {70,50};
	int xmax=100;
	int ymax=100;
//  double start[] = {5,500};
//  double goal[] = {500,500};
//	int xmax=500;
//	int ymax=500;

  int num_circs;
  int rand_num;
  double total_time = 0; 
  int loopcount = 0;
  bool success; 
  double area;

  //expecting command line args to be rand num, then num circs
  if (argc > 2)
  {
    num_circs = std::atoi(argv[2]);
    rand_num = std::atoi(argv[1]);
  } else if (argc > 1) {
    rand_num = std::atoi(argv[1]);
    num_circs = 0;
  } else {
    num_circs = 0;
    rand_num = 10;
  }


  for(loopcount = 0; loopcount < 150;loopcount++)
  {

	if (!(loopcount%3))
	{num_circs+=512;
	printf("obstacle count= %d ", num_circs);}

	 fprintf(fp, " %d ", num_circs);

//    	double num_double = std::stod(s1);
	  double begin_time = get_time_point();
	  printf(" %lf ", begin_time/1e6);
	 fprintf(fp, " %lf ", begin_time/1e6);
	  printf("GPU**===-------------------------------------------------===**\n");
	  printf("loopcount = %d \n",loopcount);

  RRT rrt(start, goal, rand_num, xmax, ymax);
  area=rrt.randomCircles(num_circs, 0.0, 0.5);

	 fprintf(fp, " %lf ", area/(xmax*ymax));
	 printf("area= %lf ", area/(xmax*ymax));

  // rrt.explore();
  // rrt.exploreObstacles();
  // rrt.exploreCuda();


//  unsigned int timer;
//  float host_time;

//  CUT_SAFE_CALL(cutCreateTimer(&timer));
//  cutStartTimer(timer);

  //success=rrt.exploreObstacles();

//  cutStopTimer(timer);
//  printf("\n\n**===-------------------------------------------------===**\n");
//  printf("Host CPU Processing time: %f (ms)\n", cutGetTimerValue(timer));
//  host_time = cutGetTimerValue(timer);
//  CUT_SAFE_CALL(cutDeleteTimer(timer));



//  float device_time;

//  CUT_SAFE_CALL(cutCreateTimer(&timer));
//  cutStartTimer(timer);

  success=rrt.exploreCuda();

	  double time_diff = ((double)get_time_point() - begin_time) / 1e6;
	fprintf(fp, "  %lf  %d \n", time_diff,success);
	printf(" response time= %lf  %d \n", time_diff,success);
	  total_time+= time_diff;

//  cutStopTimer(timer);
//  printf("\n\n**===-------------------------------------------------===**\n");
//  printf("CUDA Processing time: %f (ms)\n", cutGetTimerValue(timer));
//  device_time = cutGetTimerValue(timer);
//  printf("Speedup: %fX\n", host_time/device_time);

//  CUT_SAFE_CALL(cutDeleteTimer(timer));
//  std::vector<vertex> path;
//  rrt.traverseGraph(path);


//  // rrt.printGraph();
//  rrt.visualizeGraph();

	}


  // find path
  //
  // std::cout << "-----------------------" << std::endl;
  // for(unsigned int i = 0; i < path.size(); i++)
  // {
  //   std::cout << "[" << path.at(i).x << " " << path.at(i).y << "]" << std::endl;
  // }
  // std::cout << "-----------------------" << std::endl;

	fclose(fp);

  return 0;
}
