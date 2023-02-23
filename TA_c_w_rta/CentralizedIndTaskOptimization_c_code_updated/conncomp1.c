/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: conncomp1.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "eig.h"

/* Function Definitions */

/*
 * CONNCOMP Drop in replacement for graphconncomp.m from the bioinformatics
 *  toobox. G is an n by n adjacency matrix, then this identifies the S
 *  connected components C. This is also an order of magnitude faster.
 *
 *  [S,C] = conncomp(G)
 *
 *  Inputs:
 *    G  n by n adjacency matrix
 *  Outputs:
 *    S  scalar number of connected components
 *    C
 *    [p,q,r] = dmperm(G+speye(size(G)));
 *    S = numel(r)-1;
 *    C = cumsum(full(sparse(1,r(1:end-1),1,1,size(G,1))));
 *    C(p) = C;
 * Arguments    : const coder_internal_sparse_1 G
 * Return Type  : double
 */

emxArray_real_T *D;
emxArray_real_T *L;
creal_T eigen_data[100];


unsigned int conncomp1(emxArray_real_T *G)
{
    unsigned int i;
    unsigned int j;
    int xpageoffset;
    unsigned int loop_ub;
    double sum;
    unsigned int S;
    creal_T temp_eigen;
    int min_idx = 0;
    int eigen_size[1];


    i = D->size[0] * D->size[1];
    D->size[0] = G->size[0];
    D->size[1] = G->size[0];
    emxEnsureCapacity_real_T(D, i);
    loop_ub = D->size[0] * D->size[1];
    for (i = 0; i < loop_ub; i++) {
      D->data[i] = 0.0;
    }

    i = L->size[0] * L->size[1];
    L->size[0] = G->size[0];
    L->size[1] = G->size[0];
    emxEnsureCapacity_real_T(L, i);
    loop_ub = L->size[0] * L->size[1];
    for (i = 0; i < loop_ub; i++) {
      L->data[i] = 0.0;
    }
    xpageoffset = G->size[0];


    /* calculating Degree matrix*/
    for(i = 0; i<G->size[0] ;i++)
    {
        sum = 0;
        for(j=0;j<G->size[0];j++)
        {
            sum = sum + G->data[(xpageoffset*i) + j];
        }
        D->data[(i*xpageoffset)+ i] = sum;
    }

    xpageoffset = G->size[0];
    /* calculating laplacian matrix*/
    for(i = 0; i<G->size[0] ;i++)
    {
        for(j=0;j<G->size[0];j++)
        {
            L->data[(xpageoffset*i) + j] = D->data[(xpageoffset*i) + j] - G->data[(xpageoffset*i) + j];
        }
    }

    eig(L, eigen_data, eigen_size);// calculate the eigen value
    if(eigen_size[0] > 0)
    {
        for (i = 0; i < (eigen_size[0] - 1); i++)
        {
                min_idx = i;
                for (j = i + 1; j < (eigen_size[0]); j++)
                    if (eigen_data[j].re < eigen_data[min_idx].re)
                        min_idx = j;
                temp_eigen = eigen_data[min_idx];
                eigen_data[min_idx] = eigen_data[i];
                eigen_data[i] =temp_eigen;
        }
        S= eigen_size[0];
        for(i= 0 ; i< (eigen_size[0]-1) ; i++)
        {
            if((abs(eigen_data[i].re) == 0) && (eigen_data[i+1].re > 0))
            {
                 S = i+1;
                 break;
            }
        }
    }
    else
    {
        S = 0;
    }
    return S;
}

/*
 * File trailer for conncomp1.c
 *
 * [EOF]
 */
