/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: centralizedTaskIndOptimization.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 18-Feb-2020 22:41:25
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "conncomp1.h"
#include "randomTaskIndConditions.h"
#include "sort1.h"
#include "centralizedTaskIndOptimization_emxutil.h"

/* Function Definitions */

/*
 * This function computes in a greedy way the optimal task allocation for a
 *  system with matroid independence constraints per-agent, a connectivity
 *  matroid constraint that controls the interconnection of task allocations
 *  (for spatial allocations and communication), where the task space is
 *  hierarchially separated into requirements and functionalities.
 * Arguments    : double numReq
 *                double numTasks
 *                const double taskIdxToFuncReq_data[]
 *                const int taskIdxToFuncReq_size[2]
 *                double utility_data[]
 *                int utility_size[2]
 *                const cell_wrap_1 indConstraints_data[]
 *                const int indConstraints_size[2]
 *                const double pos_data[]
 *                const int pos_size[2]
 *                const double commRadii_data[]
 *                const int commRadii_size[2]
 *                boolean_T CONSTRAIN_TOPOLOGY
 * Return Type  : void

 */

  emxArray_cell_wrap_3_1x3 indConstraints_1;
  emxArray_real_T_2x2 indset_1;
  emxArray_real_T *val1;
  emxArray_real_T *idx_1;
  emxArray_real_T *c_agentAllocation_functionaliti;
  emxArray_real_T *c_agentAllocation_requirements_;

  emxArray_real_T *b_idx_data;
  emxArray_real_T *tmp_data;



 boolean_T buildAllocationGraph(emxArray_real_T *G,emxArray_real_T *Gprev, emxArray_real_T *pos, emxArray_real_T *commRadii,unsigned int taskID,
                               unsigned int reqIDX, unsigned int agentid, boolean_T TEST_INDEPENDENCE,unsigned int num_pos);


void centralizedTaskIndOptimization(double numReq, double numTasks, emxArray_real_T *taskIdxToFuncReq,
                                    emxArray_real_T *utility,emxArray_cell_wrap_4 *indConstraints,
                                    emxArray_real_T *pos,emxArray_real_T *commRadii, boolean_T CONSTRAIN_TOPOLOGY,
                                    struct0_T *indset,emxArray_real_T *G,emxArray_real_T *Gprev, unsigned int *task_index)
{
  unsigned int loop_ub = 0;
  double sum_utility = 0.0;
  unsigned int funcIdx = 0;
  unsigned int reqIdx  =0;
  unsigned int agentID = 0;
  unsigned int indset_size=0;
  int i;
  unsigned int flag = 0;
  unsigned int res = 0;
  int npages;
  int xpageoffset;
  int k;
  unsigned int local_task_index;


  unsigned int iidx= 0;


  double val2;
  int ex_size[2];
  int x_size[2];
  double x_data[2];
  int iidx_size[2];
  boolean_T isAllocationGraphIndependent;
  int i0;
  int m;
  int ex_data_tmp;
  signed char input_sizes_idx_1;
  int vlen;

  local_task_index = *task_index;

  if(CONSTRAIN_TOPOLOGY)
  {

  vlen = indset->tasks->size[0] * indset->tasks->size[1];
  indset->tasks->size[0] = 1;
  loop_ub = (int)numTasks;
  indset->tasks->size[1] = (int)numTasks;
  emxEnsureCapacity_real_T(indset->tasks, vlen);

  for (vlen = 0; vlen < loop_ub; vlen++) {
    indset->tasks->data[vlen] = 0.0;
  }

  vlen = indset->utility->size[0] * indset->utility->size[1];
  indset->utility->size[0] = 1;
  indset->utility->size[1] = (int)numTasks;
  emxEnsureCapacity_real_T(indset->utility, vlen);
  for (vlen = 0; vlen < loop_ub; vlen++) {
    indset->utility->data[vlen] = 0.0;
  }

  vlen = indset->agentID->size[0] * indset->agentID->size[1];
  indset->agentID->size[0] = 1;
  indset->agentID->size[1] = (int)numTasks;
  emxEnsureCapacity_real_T(indset->agentID, vlen);
  for (vlen = 0; vlen < loop_ub; vlen++) {
    indset->agentID->data[vlen] = 0.0;
  }

  vlen = indset->requirements->size[0] * indset->requirements->size[1];
  indset->requirements->size[0] = 1;
  indset->requirements->size[1] = (int)numTasks;
  emxEnsureCapacity_real_T(indset->requirements, vlen);
  for (vlen = 0; vlen < loop_ub; vlen++) {
    indset->requirements->data[vlen] = 0.0;
  }

    vlen = indset->functionalities->size[0] * indset->functionalities->size[1];
  indset->functionalities->size[0] = 1;
  indset->functionalities->size[1] = (int)numTasks;
  emxEnsureCapacity_real_T(indset->functionalities, vlen);
  for (vlen = 0; vlen < loop_ub; vlen++) {
    indset->functionalities->data[vlen] = 0.0;
  }


    indset->data_counter = 0;

    local_task_index = 0;
  }

  loop_ub = utility->size[0] * utility->size[1];
  for(i = 0; i<loop_ub; i++)
  {
        sum_utility = sum_utility + utility->data[i];
  }

  while((local_task_index < numTasks) && (sum_utility > 0))
  {

        sum_utility = 0;
        npages = utility->size[1];

        i = val1->size[0];
        val1->size[0] = npages;
        emxEnsureCapacity_real_T(val1, i);

        i = idx_1->size[0];
        idx_1->size[0] = npages;
        emxEnsureCapacity_real_T(idx_1, i);

        for (i = 0; i <npages; i++)
        {
            xpageoffset = i * utility->size[0];
            val1->data[i] = utility->data[xpageoffset];
            idx_1->data[i] = 0;
            for (k = 0; k < utility->size[0]; k++)
            {
                if(utility->data[k + xpageoffset] > val1->data[i])
                {
                    val1->data[i] = utility->data[k + xpageoffset];
                    idx_1->data[i] = k;
                }
            }
        }
        val2 = val1->data[0];
        iidx = 0;
        for (i = 0; i < npages; i++)
        {
            if(val1->data[i] > val2)
            {
                val2 = val1->data[i];
                iidx = i;
            }
        }

        xpageoffset = taskIdxToFuncReq->size[0];
        funcIdx = (unsigned int)taskIdxToFuncReq->data[(xpageoffset*(0)) + iidx];
        reqIdx = (unsigned int)taskIdxToFuncReq->data[(xpageoffset*(1)) + iidx];

        agentID = (unsigned int)idx_1->data[iidx];

       /****************************/
      m = indset->agentID->size[0] * indset->agentID->size[1];

      i0 = b_idx_data->size[0];
      b_idx_data->size[0] = m;
      emxEnsureCapacity_real_T(b_idx_data, i0);

      i0 = tmp_data->size[0];
      tmp_data->size[0] = m;
      emxEnsureCapacity_real_T(tmp_data, i0);

      for (i0 = 0; i0 < m; i0++)
      {
        if(indset->agentID->data[i0] == agentID)
        {
           b_idx_data->data[i0] = 1;
        }
        else
        {
           b_idx_data->data[i0] = 0;
        }
      }
      ex_data_tmp = m;
      m=0;
      for (i = 0; i < ex_data_tmp; i++)
      {
        if (((unsigned int)b_idx_data->data[i]) == 1)
        {
          tmp_data->data[m] = i;
          m++;
        }
      }
      i0 = c_agentAllocation_functionaliti->size[0];
      c_agentAllocation_functionaliti->size[0] = ex_data_tmp+1;
      emxEnsureCapacity_real_T(c_agentAllocation_functionaliti, i0);

      i0 = c_agentAllocation_requirements_->size[0];
      c_agentAllocation_requirements_->size[0] = ex_data_tmp+1;
      emxEnsureCapacity_real_T(c_agentAllocation_requirements_, i0);

      for (i0 = 0; i0 < ex_data_tmp; i0++) {
        c_agentAllocation_functionaliti->data[i0] = indset->functionalities->data[((unsigned int)tmp_data->data[i0])];
        c_agentAllocation_requirements_->data[i0] = indset->requirements->data[((unsigned int)tmp_data->data[i0])];
      }

      loop_ub = 0;
      for (i = 0; i < ex_data_tmp; i++) {
        if(((unsigned int)b_idx_data->data[i]) == 1)
        {
          loop_ub++;
        }
      }
      input_sizes_idx_1 = (signed char)(loop_ub != 0);
      c_agentAllocation_functionaliti->data[input_sizes_idx_1] = funcIdx;
      c_agentAllocation_requirements_->data[input_sizes_idx_1] = reqIdx;

        /**************************/

       if(CONSTRAIN_TOPOLOGY)
        {
          xpageoffset = utility->size[0];
          isAllocationGraphIndependent =  buildAllocationGraph(G,Gprev,pos,commRadii,iidx,reqIdx,agentID,true,(unsigned int)numReq);
        }


        /****************/

        loop_ub = indConstraints->data[agentID].f1.size[0]*indConstraints->data[agentID].f1.size[1];
        indConstraints_1.size[0] = 1;
        indConstraints_1.size[1] = loop_ub;
      for (i0 = 0; i0 < loop_ub; i0++)
      {
        indConstraints_1.data[i0] = indConstraints->data[agentID].f1.data[i0];
      }

      res = false;
      x_size[0] = 1;
      x_size[1] = input_sizes_idx_1 + 1;
      memcpy(&x_data[0], &c_agentAllocation_functionaliti->data[0], (unsigned int)
             ((input_sizes_idx_1 + 1) * (int)sizeof(double)));
      b_sort(x_data, x_size, ex_size, iidx_size);

      x_data[0] =c_agentAllocation_functionaliti->data[iidx_size[0]];
      x_data[1] =c_agentAllocation_requirements_->data[iidx_size[0]];
      loop_ub = indConstraints->data[agentID].f1.size[0]*indConstraints->data[agentID].f1.size[1];
      flag = 0;


      for(i0 = 0; i0<loop_ub;i0++)
      {
            if(flag == 0)
            {
            indset_1.size[0] = indConstraints_1.data[i0].f1.size[0];
            indset_1.size[1] = indConstraints_1.data[i0].f1.size[1];

            for(i=0;i<(indset_1.size[0] * indset_1.size[1]);i++)
            {
                indset_1.data[i] = indConstraints_1.data[i0].f1.data[i];
            }
            indset_size = indset_1.size[0];

            if(indset_size > (input_sizes_idx_1 + 1))
            {
                flag = 1;
                res = false;
            }
            if(indset_size < (input_sizes_idx_1 + 1))
            {
                flag = 2;
            }

            if(flag == 0)
            {
                m=0;
                for(i = 0; i<2 ;i++)
                {
                    if(indset_1.data[i] != x_data[i])
                    {
                        m++;
                    }
                    if(m == 0)
                    {
                        flag = 3;
                        res =true;
                    }
                }

            }
            if(flag == 2)
            {
                flag =0;
            }
            else
            {
                break;
            }
          }
      }

       /****************/

        if((res == false) || (CONSTRAIN_TOPOLOGY && (isAllocationGraphIndependent == 0)))
        {
            xpageoffset = utility->size[0];
            utility->data[(xpageoffset*iidx)+(agentID)] = 0;
        }
        else
        {
            indset->tasks->data[local_task_index] = iidx;
            indset->functionalities->data[local_task_index] = funcIdx;
            indset->requirements->data[local_task_index]=reqIdx;
            indset->utility->data[local_task_index]=val2;
            indset->agentID->data[local_task_index] = agentID;
            local_task_index = local_task_index +1;
            indset->data_counter++;


            xpageoffset = utility->size[0] * iidx;
             for(loop_ub = 0; loop_ub <  utility->size[0]; loop_ub++)
            {
                utility->data[xpageoffset + loop_ub]=0.0;
            }
        }

     loop_ub = utility->size[0] * utility->size[1];
      for(i = 0; i<loop_ub; i++)
      {
            sum_utility = sum_utility + utility->data[i];
      }
  }
     //emxFree_real_T(&utility);
     *task_index = local_task_index ;
}

boolean_T buildAllocationGraph(emxArray_real_T *G,emxArray_real_T *Gprev, emxArray_real_T *pos, emxArray_real_T *commRadii,unsigned int taskID,
                               unsigned int reqIDX, unsigned int agentid, boolean_T TEST_INDEPENDENCE,unsigned int num_pos)
{
    unsigned int i;
    unsigned int j;
    int xpageoffset_1;
    int xpageoffset_2;
    int xpageoffset_3;
    unsigned int loop_ub;
    double temp_array[2];
    double sum = 0;
    double norm = 0;
    unsigned int Sprev = 0;
    unsigned int S = 0;

    /* copy G in Gprev*/
    i = Gprev->size[0] * Gprev->size[1];
    Gprev->size[0] = G->size[0];
    Gprev->size[1] = G->size[1];
    emxEnsureCapacity_real_T(Gprev, i);
    loop_ub = G->size[0] * G->size[1];
    for (i = 0; i < loop_ub; i++) {
      Gprev->data[i] = G->data[i];
    }


    i = G->size[0] * G->size[1];
    G->size[0] = (int)num_pos;
    G->size[1] = (int)num_pos;
    emxEnsureCapacity_real_T(G, i);
    loop_ub = (int)num_pos * (int)num_pos;
    for (i = 0; i < loop_ub; i++) {
      G->data[i] = 0.0;
    }

    xpageoffset_2 = commRadii->size[0];
    xpageoffset_1 = pos->size[0];
    xpageoffset_3 = G->size[0];

    for(j = 0; j<num_pos;j++)
    {
        if(j != (reqIDX-1))
        {
            for(i = 0 ; i< 2;i++)
            {
                temp_array[i] = pos->data[(i*xpageoffset_1)+(reqIDX-1)] - pos->data[(i*xpageoffset_1)+j];
                sum = sum + (temp_array[i] * temp_array[i]);
            }
            norm = sqrt(sum);
            if(norm <= (commRadii->data[((taskID)*xpageoffset_2)+(agentid)]))
            {
                G->data[(xpageoffset_3*j) + (reqIDX - 1)] = 1;
                G->data[(xpageoffset_3*(reqIDX-1)) + j] = 1;
            }
        }
    }

    if(TEST_INDEPENDENCE)
    {
        Sprev =conncomp1(Gprev);
        S =conncomp1(G);
        if((S < Sprev) || (S == 1))
            return true;
        else
            return false;
    }
    else
        return false;
}

void initialize_variable_centralized_task(void)
{
 emxInit_real_T(&val1, 1);
 emxInit_real_T(&idx_1, 1);
 emxInit_real_T(&c_agentAllocation_functionaliti, 1);
 emxInit_real_T(&c_agentAllocation_requirements_, 1);
 emxInit_real_T(&b_idx_data, 1);
 emxInit_real_T(&tmp_data, 1);

}



/*
 * File trailer for centralizedTaskIndOptimization.c
 *
 * [EOF]
 */
