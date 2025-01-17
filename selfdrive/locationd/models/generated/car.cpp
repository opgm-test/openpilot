#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4112143657443420345) {
   out_4112143657443420345[0] = delta_x[0] + nom_x[0];
   out_4112143657443420345[1] = delta_x[1] + nom_x[1];
   out_4112143657443420345[2] = delta_x[2] + nom_x[2];
   out_4112143657443420345[3] = delta_x[3] + nom_x[3];
   out_4112143657443420345[4] = delta_x[4] + nom_x[4];
   out_4112143657443420345[5] = delta_x[5] + nom_x[5];
   out_4112143657443420345[6] = delta_x[6] + nom_x[6];
   out_4112143657443420345[7] = delta_x[7] + nom_x[7];
   out_4112143657443420345[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1448447221229649002) {
   out_1448447221229649002[0] = -nom_x[0] + true_x[0];
   out_1448447221229649002[1] = -nom_x[1] + true_x[1];
   out_1448447221229649002[2] = -nom_x[2] + true_x[2];
   out_1448447221229649002[3] = -nom_x[3] + true_x[3];
   out_1448447221229649002[4] = -nom_x[4] + true_x[4];
   out_1448447221229649002[5] = -nom_x[5] + true_x[5];
   out_1448447221229649002[6] = -nom_x[6] + true_x[6];
   out_1448447221229649002[7] = -nom_x[7] + true_x[7];
   out_1448447221229649002[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6589730968564999447) {
   out_6589730968564999447[0] = 1.0;
   out_6589730968564999447[1] = 0;
   out_6589730968564999447[2] = 0;
   out_6589730968564999447[3] = 0;
   out_6589730968564999447[4] = 0;
   out_6589730968564999447[5] = 0;
   out_6589730968564999447[6] = 0;
   out_6589730968564999447[7] = 0;
   out_6589730968564999447[8] = 0;
   out_6589730968564999447[9] = 0;
   out_6589730968564999447[10] = 1.0;
   out_6589730968564999447[11] = 0;
   out_6589730968564999447[12] = 0;
   out_6589730968564999447[13] = 0;
   out_6589730968564999447[14] = 0;
   out_6589730968564999447[15] = 0;
   out_6589730968564999447[16] = 0;
   out_6589730968564999447[17] = 0;
   out_6589730968564999447[18] = 0;
   out_6589730968564999447[19] = 0;
   out_6589730968564999447[20] = 1.0;
   out_6589730968564999447[21] = 0;
   out_6589730968564999447[22] = 0;
   out_6589730968564999447[23] = 0;
   out_6589730968564999447[24] = 0;
   out_6589730968564999447[25] = 0;
   out_6589730968564999447[26] = 0;
   out_6589730968564999447[27] = 0;
   out_6589730968564999447[28] = 0;
   out_6589730968564999447[29] = 0;
   out_6589730968564999447[30] = 1.0;
   out_6589730968564999447[31] = 0;
   out_6589730968564999447[32] = 0;
   out_6589730968564999447[33] = 0;
   out_6589730968564999447[34] = 0;
   out_6589730968564999447[35] = 0;
   out_6589730968564999447[36] = 0;
   out_6589730968564999447[37] = 0;
   out_6589730968564999447[38] = 0;
   out_6589730968564999447[39] = 0;
   out_6589730968564999447[40] = 1.0;
   out_6589730968564999447[41] = 0;
   out_6589730968564999447[42] = 0;
   out_6589730968564999447[43] = 0;
   out_6589730968564999447[44] = 0;
   out_6589730968564999447[45] = 0;
   out_6589730968564999447[46] = 0;
   out_6589730968564999447[47] = 0;
   out_6589730968564999447[48] = 0;
   out_6589730968564999447[49] = 0;
   out_6589730968564999447[50] = 1.0;
   out_6589730968564999447[51] = 0;
   out_6589730968564999447[52] = 0;
   out_6589730968564999447[53] = 0;
   out_6589730968564999447[54] = 0;
   out_6589730968564999447[55] = 0;
   out_6589730968564999447[56] = 0;
   out_6589730968564999447[57] = 0;
   out_6589730968564999447[58] = 0;
   out_6589730968564999447[59] = 0;
   out_6589730968564999447[60] = 1.0;
   out_6589730968564999447[61] = 0;
   out_6589730968564999447[62] = 0;
   out_6589730968564999447[63] = 0;
   out_6589730968564999447[64] = 0;
   out_6589730968564999447[65] = 0;
   out_6589730968564999447[66] = 0;
   out_6589730968564999447[67] = 0;
   out_6589730968564999447[68] = 0;
   out_6589730968564999447[69] = 0;
   out_6589730968564999447[70] = 1.0;
   out_6589730968564999447[71] = 0;
   out_6589730968564999447[72] = 0;
   out_6589730968564999447[73] = 0;
   out_6589730968564999447[74] = 0;
   out_6589730968564999447[75] = 0;
   out_6589730968564999447[76] = 0;
   out_6589730968564999447[77] = 0;
   out_6589730968564999447[78] = 0;
   out_6589730968564999447[79] = 0;
   out_6589730968564999447[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6843342043308437648) {
   out_6843342043308437648[0] = state[0];
   out_6843342043308437648[1] = state[1];
   out_6843342043308437648[2] = state[2];
   out_6843342043308437648[3] = state[3];
   out_6843342043308437648[4] = state[4];
   out_6843342043308437648[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6843342043308437648[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6843342043308437648[7] = state[7];
   out_6843342043308437648[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5517739003727465901) {
   out_5517739003727465901[0] = 1;
   out_5517739003727465901[1] = 0;
   out_5517739003727465901[2] = 0;
   out_5517739003727465901[3] = 0;
   out_5517739003727465901[4] = 0;
   out_5517739003727465901[5] = 0;
   out_5517739003727465901[6] = 0;
   out_5517739003727465901[7] = 0;
   out_5517739003727465901[8] = 0;
   out_5517739003727465901[9] = 0;
   out_5517739003727465901[10] = 1;
   out_5517739003727465901[11] = 0;
   out_5517739003727465901[12] = 0;
   out_5517739003727465901[13] = 0;
   out_5517739003727465901[14] = 0;
   out_5517739003727465901[15] = 0;
   out_5517739003727465901[16] = 0;
   out_5517739003727465901[17] = 0;
   out_5517739003727465901[18] = 0;
   out_5517739003727465901[19] = 0;
   out_5517739003727465901[20] = 1;
   out_5517739003727465901[21] = 0;
   out_5517739003727465901[22] = 0;
   out_5517739003727465901[23] = 0;
   out_5517739003727465901[24] = 0;
   out_5517739003727465901[25] = 0;
   out_5517739003727465901[26] = 0;
   out_5517739003727465901[27] = 0;
   out_5517739003727465901[28] = 0;
   out_5517739003727465901[29] = 0;
   out_5517739003727465901[30] = 1;
   out_5517739003727465901[31] = 0;
   out_5517739003727465901[32] = 0;
   out_5517739003727465901[33] = 0;
   out_5517739003727465901[34] = 0;
   out_5517739003727465901[35] = 0;
   out_5517739003727465901[36] = 0;
   out_5517739003727465901[37] = 0;
   out_5517739003727465901[38] = 0;
   out_5517739003727465901[39] = 0;
   out_5517739003727465901[40] = 1;
   out_5517739003727465901[41] = 0;
   out_5517739003727465901[42] = 0;
   out_5517739003727465901[43] = 0;
   out_5517739003727465901[44] = 0;
   out_5517739003727465901[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5517739003727465901[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5517739003727465901[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5517739003727465901[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5517739003727465901[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5517739003727465901[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5517739003727465901[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5517739003727465901[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5517739003727465901[53] = -9.8000000000000007*dt;
   out_5517739003727465901[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5517739003727465901[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5517739003727465901[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5517739003727465901[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5517739003727465901[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5517739003727465901[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5517739003727465901[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5517739003727465901[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5517739003727465901[62] = 0;
   out_5517739003727465901[63] = 0;
   out_5517739003727465901[64] = 0;
   out_5517739003727465901[65] = 0;
   out_5517739003727465901[66] = 0;
   out_5517739003727465901[67] = 0;
   out_5517739003727465901[68] = 0;
   out_5517739003727465901[69] = 0;
   out_5517739003727465901[70] = 1;
   out_5517739003727465901[71] = 0;
   out_5517739003727465901[72] = 0;
   out_5517739003727465901[73] = 0;
   out_5517739003727465901[74] = 0;
   out_5517739003727465901[75] = 0;
   out_5517739003727465901[76] = 0;
   out_5517739003727465901[77] = 0;
   out_5517739003727465901[78] = 0;
   out_5517739003727465901[79] = 0;
   out_5517739003727465901[80] = 1;
}
void h_25(double *state, double *unused, double *out_3400981906576064285) {
   out_3400981906576064285[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2200893013917596422) {
   out_2200893013917596422[0] = 0;
   out_2200893013917596422[1] = 0;
   out_2200893013917596422[2] = 0;
   out_2200893013917596422[3] = 0;
   out_2200893013917596422[4] = 0;
   out_2200893013917596422[5] = 0;
   out_2200893013917596422[6] = 1;
   out_2200893013917596422[7] = 0;
   out_2200893013917596422[8] = 0;
}
void h_24(double *state, double *unused, double *out_3243230712214609592) {
   out_3243230712214609592[0] = state[4];
   out_3243230712214609592[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1781430137480171476) {
   out_1781430137480171476[0] = 0;
   out_1781430137480171476[1] = 0;
   out_1781430137480171476[2] = 0;
   out_1781430137480171476[3] = 0;
   out_1781430137480171476[4] = 1;
   out_1781430137480171476[5] = 0;
   out_1781430137480171476[6] = 0;
   out_1781430137480171476[7] = 0;
   out_1781430137480171476[8] = 0;
   out_1781430137480171476[9] = 0;
   out_1781430137480171476[10] = 0;
   out_1781430137480171476[11] = 0;
   out_1781430137480171476[12] = 0;
   out_1781430137480171476[13] = 0;
   out_1781430137480171476[14] = 1;
   out_1781430137480171476[15] = 0;
   out_1781430137480171476[16] = 0;
   out_1781430137480171476[17] = 0;
}
void h_30(double *state, double *unused, double *out_236467621677958065) {
   out_236467621677958065[0] = state[4];
}
void H_30(double *state, double *unused, double *out_9117583355409213177) {
   out_9117583355409213177[0] = 0;
   out_9117583355409213177[1] = 0;
   out_9117583355409213177[2] = 0;
   out_9117583355409213177[3] = 0;
   out_9117583355409213177[4] = 1;
   out_9117583355409213177[5] = 0;
   out_9117583355409213177[6] = 0;
   out_9117583355409213177[7] = 0;
   out_9117583355409213177[8] = 0;
}
void h_26(double *state, double *unused, double *out_366848262998519452) {
   out_366848262998519452[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1540610304956459802) {
   out_1540610304956459802[0] = 0;
   out_1540610304956459802[1] = 0;
   out_1540610304956459802[2] = 0;
   out_1540610304956459802[3] = 0;
   out_1540610304956459802[4] = 0;
   out_1540610304956459802[5] = 0;
   out_1540610304956459802[6] = 0;
   out_1540610304956459802[7] = 1;
   out_1540610304956459802[8] = 0;
}
void h_27(double *state, double *unused, double *out_2643131761415245475) {
   out_2643131761415245475[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6942820043608788266) {
   out_6942820043608788266[0] = 0;
   out_6942820043608788266[1] = 0;
   out_6942820043608788266[2] = 0;
   out_6942820043608788266[3] = 1;
   out_6942820043608788266[4] = 0;
   out_6942820043608788266[5] = 0;
   out_6942820043608788266[6] = 0;
   out_6942820043608788266[7] = 0;
   out_6942820043608788266[8] = 0;
}
void h_29(double *state, double *unused, double *out_5238140889338803710) {
   out_5238140889338803710[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5229457316739237233) {
   out_5229457316739237233[0] = 0;
   out_5229457316739237233[1] = 1;
   out_5229457316739237233[2] = 0;
   out_5229457316739237233[3] = 0;
   out_5229457316739237233[4] = 0;
   out_5229457316739237233[5] = 0;
   out_5229457316739237233[6] = 0;
   out_5229457316739237233[7] = 0;
   out_5229457316739237233[8] = 0;
}
void h_28(double *state, double *unused, double *out_7381277810922059405) {
   out_7381277810922059405[0] = state[0];
}
void H_28(double *state, double *unused, double *out_147058299669706659) {
   out_147058299669706659[0] = 1;
   out_147058299669706659[1] = 0;
   out_147058299669706659[2] = 0;
   out_147058299669706659[3] = 0;
   out_147058299669706659[4] = 0;
   out_147058299669706659[5] = 0;
   out_147058299669706659[6] = 0;
   out_147058299669706659[7] = 0;
   out_147058299669706659[8] = 0;
}
void h_31(double *state, double *unused, double *out_6194173636447207953) {
   out_6194173636447207953[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2231538975794556850) {
   out_2231538975794556850[0] = 0;
   out_2231538975794556850[1] = 0;
   out_2231538975794556850[2] = 0;
   out_2231538975794556850[3] = 0;
   out_2231538975794556850[4] = 0;
   out_2231538975794556850[5] = 0;
   out_2231538975794556850[6] = 0;
   out_2231538975794556850[7] = 0;
   out_2231538975794556850[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4112143657443420345) {
  err_fun(nom_x, delta_x, out_4112143657443420345);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1448447221229649002) {
  inv_err_fun(nom_x, true_x, out_1448447221229649002);
}
void car_H_mod_fun(double *state, double *out_6589730968564999447) {
  H_mod_fun(state, out_6589730968564999447);
}
void car_f_fun(double *state, double dt, double *out_6843342043308437648) {
  f_fun(state,  dt, out_6843342043308437648);
}
void car_F_fun(double *state, double dt, double *out_5517739003727465901) {
  F_fun(state,  dt, out_5517739003727465901);
}
void car_h_25(double *state, double *unused, double *out_3400981906576064285) {
  h_25(state, unused, out_3400981906576064285);
}
void car_H_25(double *state, double *unused, double *out_2200893013917596422) {
  H_25(state, unused, out_2200893013917596422);
}
void car_h_24(double *state, double *unused, double *out_3243230712214609592) {
  h_24(state, unused, out_3243230712214609592);
}
void car_H_24(double *state, double *unused, double *out_1781430137480171476) {
  H_24(state, unused, out_1781430137480171476);
}
void car_h_30(double *state, double *unused, double *out_236467621677958065) {
  h_30(state, unused, out_236467621677958065);
}
void car_H_30(double *state, double *unused, double *out_9117583355409213177) {
  H_30(state, unused, out_9117583355409213177);
}
void car_h_26(double *state, double *unused, double *out_366848262998519452) {
  h_26(state, unused, out_366848262998519452);
}
void car_H_26(double *state, double *unused, double *out_1540610304956459802) {
  H_26(state, unused, out_1540610304956459802);
}
void car_h_27(double *state, double *unused, double *out_2643131761415245475) {
  h_27(state, unused, out_2643131761415245475);
}
void car_H_27(double *state, double *unused, double *out_6942820043608788266) {
  H_27(state, unused, out_6942820043608788266);
}
void car_h_29(double *state, double *unused, double *out_5238140889338803710) {
  h_29(state, unused, out_5238140889338803710);
}
void car_H_29(double *state, double *unused, double *out_5229457316739237233) {
  H_29(state, unused, out_5229457316739237233);
}
void car_h_28(double *state, double *unused, double *out_7381277810922059405) {
  h_28(state, unused, out_7381277810922059405);
}
void car_H_28(double *state, double *unused, double *out_147058299669706659) {
  H_28(state, unused, out_147058299669706659);
}
void car_h_31(double *state, double *unused, double *out_6194173636447207953) {
  h_31(state, unused, out_6194173636447207953);
}
void car_H_31(double *state, double *unused, double *out_2231538975794556850) {
  H_31(state, unused, out_2231538975794556850);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
