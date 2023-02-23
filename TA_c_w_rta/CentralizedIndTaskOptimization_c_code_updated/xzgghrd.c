/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzgghrd.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 23-May-2020 16:25:41
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "centralizedTaskIndOptimization.h"
#include "xzgghrd.h"
#include "xzlartg.h"

/* Function Definitions */

/*
 * Arguments    : int ilo
 *                int ihi
 *                emxArray_creal_T *A
 * Return Type  : void
 */
void xzgghrd(int ilo, int ihi, emxArray_creal_T *A)
{
  int n;
  int jcol;
  int jcolp1;
  int jrow;
  creal_T b_A;
  creal_T c_A;
  double c;
  creal_T s;
  int j;
  double stemp_im;
  double s_im;
  double stemp_re;
  double A_im;
  double b_A_im;
  double A_re;
  n = A->size[0];
  if ((A->size[0] > 1) && (ihi >= ilo + 2)) {
    for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
      jcolp1 = jcol + 2;
      for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
        b_A = A->data[(jrow + A->size[0] * jcol) - 1];
        c_A = A->data[jrow + A->size[0] * jcol];
        xzlartg(b_A, c_A, &c, &s, &A->data[(jrow + A->size[0] * jcol) - 1]);
        A->data[jrow + A->size[0] * jcol].re = 0.0;
        A->data[jrow + A->size[0] * jcol].im = 0.0;
        for (j = jcolp1; j <= n; j++) {
          stemp_im = s.re * A->data[jrow + A->size[0] * (j - 1)].re - s.im *
            A->data[jrow + A->size[0] * (j - 1)].im;
          s_im = s.re * A->data[jrow + A->size[0] * (j - 1)].im + s.im * A->
            data[jrow + A->size[0] * (j - 1)].re;
          stemp_re = c * A->data[(jrow + A->size[0] * (j - 1)) - 1].re +
            stemp_im;
          stemp_im = c * A->data[(jrow + A->size[0] * (j - 1)) - 1].im + s_im;
          s_im = A->data[(jrow + A->size[0] * (j - 1)) - 1].re;
          A_im = A->data[(jrow + A->size[0] * (j - 1)) - 1].im;
          b_A_im = A->data[(jrow + A->size[0] * (j - 1)) - 1].im;
          A_re = A->data[(jrow + A->size[0] * (j - 1)) - 1].re;
          A->data[jrow + A->size[0] * (j - 1)].re = c * A->data[jrow + A->size[0]
            * (j - 1)].re - (s.re * s_im + s.im * A_im);
          A->data[jrow + A->size[0] * (j - 1)].im = c * A->data[jrow + A->size[0]
            * (j - 1)].im - (s.re * b_A_im - s.im * A_re);
          A->data[(jrow + A->size[0] * (j - 1)) - 1].re = stemp_re;
          A->data[(jrow + A->size[0] * (j - 1)) - 1].im = stemp_im;
        }

        s.re = -s.re;
        s.im = -s.im;
        for (j = 1; j <= ihi; j++) {
          stemp_im = s.re * A->data[(j + A->size[0] * (jrow - 1)) - 1].re - s.im
            * A->data[(j + A->size[0] * (jrow - 1)) - 1].im;
          s_im = s.re * A->data[(j + A->size[0] * (jrow - 1)) - 1].im + s.im *
            A->data[(j + A->size[0] * (jrow - 1)) - 1].re;
          stemp_re = c * A->data[(j + A->size[0] * jrow) - 1].re + stemp_im;
          stemp_im = c * A->data[(j + A->size[0] * jrow) - 1].im + s_im;
          s_im = A->data[(j + A->size[0] * jrow) - 1].re;
          A_im = A->data[(j + A->size[0] * jrow) - 1].im;
          b_A_im = A->data[(j + A->size[0] * jrow) - 1].im;
          A_re = A->data[(j + A->size[0] * jrow) - 1].re;
          A->data[(j + A->size[0] * (jrow - 1)) - 1].re = c * A->data[(j +
            A->size[0] * (jrow - 1)) - 1].re - (s.re * s_im + s.im * A_im);
          A->data[(j + A->size[0] * (jrow - 1)) - 1].im = c * A->data[(j +
            A->size[0] * (jrow - 1)) - 1].im - (s.re * b_A_im - s.im * A_re);
          A->data[(j + A->size[0] * jrow) - 1].re = stemp_re;
          A->data[(j + A->size[0] * jrow) - 1].im = stemp_im;
        }
      }
    }
  }
}

/*
 * File trailer for xzgghrd.c
 *
 * [EOF]
 */
