/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzgeev.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
//#include "test.h"
#include "xzgeev.h"
#include "centralizedTaskIndOptimization_emxutil.h"
#include "xzlascl.h"
#include "xzhgeqz.h"
#include "xzgghrd.h"
#include "xzggbal.h"
#include "isfinite.h"
#include "xzlangeM.h"
#include "centralizedTaskIndOptimization.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                int *info
 *                creal_T alpha1_data[]
 *                int alpha1_size[1]
 *                creal_T beta1_data[]
 *                int beta1_size[1]
 * Return Type  : void
 */
void xzgeev(const emxArray_real_T *A, int *info, creal_T alpha1_data[], int
            alpha1_size[1], creal_T beta1_data[], int beta1_size[1])
{
  emxArray_creal_T *At;
  int ilo;
  int loop_ub;
  double anrm;
  boolean_T ilascl;
  double anrmto;
  int rscale_data[100];
  int rscale_size[1];
  emxInit_creal_T(&At, 2);
  ilo = At->size[0] * At->size[1];
  At->size[0] = A->size[0];
  At->size[1] = A->size[1];
  emxEnsureCapacity_creal_T(At, ilo);
  loop_ub = A->size[0] * A->size[1];
  for (ilo = 0; ilo < loop_ub; ilo++) {
    At->data[ilo].re = A->data[ilo];
    At->data[ilo].im = 0.0;
  }

  *info = 0;
  anrm = xzlangeM(At);
  if (!b_isfinite(anrm)) {
    alpha1_size[0] = At->size[0];
    loop_ub = At->size[0];
    for (ilo = 0; ilo < loop_ub; ilo++) {
      alpha1_data[ilo].re = rtNaN;
      alpha1_data[ilo].im = 0.0;
    }

    beta1_size[0] = At->size[0];
    loop_ub = At->size[0];
    for (ilo = 0; ilo < loop_ub; ilo++) {
      beta1_data[ilo].re = rtNaN;
      beta1_data[ilo].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      xzlascl(anrm, anrmto, At);
    }

    xzggbal(At, &ilo, &loop_ub, rscale_data, rscale_size);
    xzgghrd(ilo, loop_ub, At);
    xzhgeqz(At, ilo, loop_ub, info, alpha1_data, alpha1_size, beta1_data,
            beta1_size);
    if ((*info == 0) && ilascl) {
      b_xzlascl(anrmto, anrm, alpha1_data, alpha1_size);
    }
  }

  emxFree_creal_T(&At);
}

/*
 * File trailer for xzgeev.c
 *
 * [EOF]
 */
