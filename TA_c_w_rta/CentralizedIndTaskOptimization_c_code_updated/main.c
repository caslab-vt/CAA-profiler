/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include <stdio.h>
#include <stdlib.h>
/*#include <time.h>*/
#include <sys/time.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "main.h"
#include "centralizedTaskIndOptimization_terminate.h"
#include "centralizedTaskIndOptimization_emxAPI.h"
#include "centralizedTaskIndOptimization_initialize.h"
#include "conncomp1.h"

/* Function Declarations */
static void random_double_2_d_array(emxArray_real_T *Temp_array,unsigned int row, unsigned int col);
static void copy_utility_data(emxArray_real_T *Temp_array, emxArray_real_T *Temp_array_1);

emxArray_real_T *utility;
emxArray_real_T *local_utility;

/*unsigned int stats_N[100];
unsigned int stats_numReq[100];
unsigned int stats_numFunc[100];
unsigned int stats_maxFuncPerReq[100];
unsigned int stats_numTasks[100];
emxArray_real_T *stats_taskIdxToFuncReq[100];*/
//unsigned int stats_indConstraints = cell(1,M);
//emxArray_real_T *stats_utility[M];
//emxArray_real_T *stats_pos[M];
//emxArray_real_T *stats_commRadii[M];
//struct0_T stats_indset[100];
//stats_G = cell(1,M);
/*unsigned int stats_greedyUtility[2000];
unsigned int stats_optimalUtility[100];*/
emxArray_real_T *taskIdxToFuncReq;
emxArray_real_T *funcReqToTaskIdx;
emxArray_cell_wrap_4 *indConstraints;
double numTasks;
emxArray_real_T *pos;
emxArray_real_T *commRadii;
 struct0_T indset;

  emxArray_real_T *G;
  emxArray_real_T *Gprev;
unsigned int i,j;//for testing



/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  unsigned int M = 1000; // number of loops
  unsigned int m = 0;
  unsigned int Nrange_min = 64;  // minimum Nrange value
  unsigned int Nrange_max = 96; // maximum Nrange value
  unsigned int numReqRange_min = 8; // minimum numReqRange
  unsigned int numReqRange_max = 100; // maximum numReqRange
  unsigned int numFuncRange_min = 8; // minimum numFuncRange
  unsigned int numFuncRange_max = 100; // Maximum numFuncRange

  unsigned int N = 0;
  unsigned int numReq = 0;
  unsigned int numFunc = 0;
  unsigned int maxFuncPerReq = 0;
  unsigned int S = 0;
  unsigned int task_index=0;
  double sum_utility = 0; // variable for storing the total sum of utility for each loop

  srand(time(0));
/*  clock_t start, stop;*/
   struct timeval t0;
   struct timeval t1;
   float elapsed;


  /*Initializing the variables with 2 dimension array*/
  emxInitArray_real_T(&taskIdxToFuncReq, 2);
  emxInitArray_real_T(&funcReqToTaskIdx, 2);
  emxInitArray_cell_wrap_4(&indConstraints, 2);

  emxInitArray_real_T(&utility, 2);
  emxInitArray_real_T(&local_utility, 2);
  emxInitArray_real_T(&pos, 2);
  emxInitArray_real_T(&commRadii, 2);

  emxInitArray_real_T(&G, 2);
  emxInitArray_real_T(&Gprev, 2);

  /* Initialize the application.
     You do not need to do this more than one time. */
  centralizedTaskIndOptimization_initialize();

  /* initialize the variables with number of dimensions*/
  initialize_variable();
  initialize_variable_centralized_task();

  /* initialize the indset variables dimension*/
  emxInitArray_real_T(&indset.agentID, 2);
  emxInitArray_real_T(&indset.requirements, 2);
  emxInitArray_real_T(&indset.functionalities, 2);
  emxInitArray_real_T(&indset.tasks, 2);
  emxInitArray_real_T(&indset.utility, 2);


  emxInitArray_real_T(&D, 2);
  emxInitArray_real_T(&L, 2);

  emxEnsureCapacity_real_T(indset.agentID,0);
  emxEnsureCapacity_real_T(indset.functionalities,0);
  emxEnsureCapacity_real_T(indset.requirements,0);
  emxEnsureCapacity_real_T(indset.tasks,0);
  emxEnsureCapacity_real_T(indset.utility,0);

  FILE *fp = fopen("ta_res1_fpr_test_ffmax.txt", "w"); 
/*  if (fp == NULL) return -1;*/

  for(m = 0; m<M; m++)
  {
/*      start = clock();*/
      gettimeofday(&t0, 0);
/*      printf("time = %f \n",t0.tv_sec* 1000.0f + t0.tv_usec* 1000.0f);*/
      printf("time = %f \n",t0.tv_sec* 1000.0f);
      printf("m = %d \n",m);
      N = rand()%((Nrange_max+1)-Nrange_min) + Nrange_min;
      numReq = rand()%((numReqRange_max+1)-numReqRange_min) + numReqRange_min;
      numFunc = rand()%((numFuncRange_max+1)-numFuncRange_min) + numFuncRange_min;
      maxFuncPerReq = rand()%numFunc;

      /* randomize the variables numTasks, taskIdxToFuncReq, funcReqToTaskIdx, indconstrains*/
      randomTaskIndConditions(N,numReq,numFunc,maxFuncPerReq,&numTasks,taskIdxToFuncReq,funcReqToTaskIdx,indConstraints);
      random_double_2_d_array(utility,N,(unsigned int)numTasks); // initialize utility
      random_double_2_d_array(pos,numReq,2); // initialize pos
      random_double_2_d_array(commRadii,N,(unsigned int)numTasks); // initialize commRadii

      //copy_utility_data(utility,local_utility); // make a copy of the utility function

      centralizedTaskIndOptimization(numReq, numTasks, taskIdxToFuncReq,utility, indConstraints, pos, commRadii,true,&indset,G,Gprev,&task_index);
      S = conncomp1(G);
      if((task_index < numTasks) && (S == 1))
      {
        centralizedTaskIndOptimization(numReq, numTasks, taskIdxToFuncReq,utility, indConstraints, pos, commRadii,false,&indset,G,Gprev,&task_index);
      }


    /* calculate the greedy utility*/
    sum_utility = 0;
    for(i=0; i<indset.data_counter ;i++)
    {
       sum_utility = sum_utility + indset.utility->data[i];
    }
    //stats_greedyUtility[m] = sum_utility;

    printf("greedy_utility = %lf \n",sum_utility);
/*    stop = clock();*/
/*    printf("elapsed time = %lf \n",stop-start);*/
   gettimeofday(&t1, 0);
   elapsed = timedifference_msec(t0, t1);

   printf("Code executed in %f milliseconds.\n", elapsed);
   fprintf(fp, "%f %f \n", (t0.tv_sec* 1000.0f), elapsed);
   fflush(fp);

  }
   fclose(fp);


  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times.
  main_centralizedTaskIndOptimization();
  main_conncomp1();
   Terminate the application.
     You do not need to do this more than one time.
  centralizedTaskIndOptimization_terminate();*/
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
static void random_double_2_d_array(emxArray_real_T *Temp_array,unsigned int row, unsigned int col)
{
    int i0,i1,i2;
    int loop_ub;
    i0 = Temp_array->size[0] * Temp_array->size[1];
    i1 = (int)row;
    Temp_array->size[0] = i1;
    i2 = (int)col;
    Temp_array->size[1] = i2;
    emxEnsureCapacity_real_T(Temp_array, i0);
    loop_ub = i1 * i2;
    for (i0 = 0; i0 < loop_ub; i0++) {
        Temp_array->data[i0] = (double)rand() / (double)RAND_MAX;
    }


}

static void copy_utility_data(emxArray_real_T *Temp_array, emxArray_real_T *Temp_array_1)
{

    int i0,i1,i2;
    int loop_ub;
    i0 = Temp_array_1->size[0] * Temp_array_1->size[1];
    i1 = (int)Temp_array->size[0];
    Temp_array_1->size[0] = i1;
    i2 = (int)Temp_array->size[1];
    Temp_array_1->size[1] = i2;
    emxEnsureCapacity_real_T(Temp_array_1, i0);
    loop_ub = i1 * i2;
    for (i0 = 0; i0 < loop_ub; i0++) {
        Temp_array_1->data[i0] = Temp_array->data[i0];
    }

}
