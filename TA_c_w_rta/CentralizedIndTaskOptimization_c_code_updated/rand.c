/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rand.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "rand.h"
#include "centralizedTaskIndOptimization_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
double b_rand(void)
{
  double r;

  r = (double)rand() / (double)RAND_MAX;

  return r;
}


  /*  int perm[SZ];
    int j, t;

    for (int i = 0; i < SZ; i++)
        perm[i] = i;
*/
    // Random permutation the order
  /*  for (int i = 0; i < SZ; i++) {
        j = rand() % (SZ-i) + i;
        t = perm[j]; perm[j] = perm[i]; perm[i] = t; // Swap i and j
    }*/

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
