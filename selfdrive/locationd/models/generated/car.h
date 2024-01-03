#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3252114057011917524);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8642410575792832576);
void car_H_mod_fun(double *state, double *out_9157679730372221636);
void car_f_fun(double *state, double dt, double *out_5892044963083798211);
void car_F_fun(double *state, double dt, double *out_4974012336382314435);
void car_h_25(double *state, double *unused, double *out_3022083034826800390);
void car_H_25(double *state, double *unused, double *out_6598231668524653260);
void car_h_24(double *state, double *unused, double *out_1738268782446370288);
void car_H_24(double *state, double *unused, double *out_8770881267530152826);
void car_h_30(double *state, double *unused, double *out_7816289270781607542);
void car_H_30(double *state, double *unused, double *out_318458672966963495);
void car_h_26(double *state, double *unused, double *out_2853909273100314310);
void car_H_26(double *state, double *unused, double *out_8107009086310842132);
void car_h_27(double *state, double *unused, double *out_8664812905907757225);
void car_H_27(double *state, double *unused, double *out_8902333927468318241);
void car_h_29(double *state, double *unused, double *out_1204254141658868900);
void car_H_29(double *state, double *unused, double *out_7831047419371682342);
void car_h_28(double *state, double *unused, double *out_4780257900140948746);
void car_H_28(double *state, double *unused, double *out_8652066382772543023);
void car_h_31(double *state, double *unused, double *out_2621981795657599467);
void car_H_31(double *state, double *unused, double *out_6567585706647692832);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}