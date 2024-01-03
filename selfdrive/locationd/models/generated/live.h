#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_4061266139548719060);
void live_err_fun(double *nom_x, double *delta_x, double *out_910979890283891971);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7762481351514957565);
void live_H_mod_fun(double *state, double *out_4913423897642114016);
void live_f_fun(double *state, double dt, double *out_7534826237228476571);
void live_F_fun(double *state, double dt, double *out_8471380351583711664);
void live_h_4(double *state, double *unused, double *out_2523131625364373502);
void live_H_4(double *state, double *unused, double *out_1123809187897751568);
void live_h_9(double *state, double *unused, double *out_1867464073431487895);
void live_H_9(double *state, double *unused, double *out_6163409747366695902);
void live_h_10(double *state, double *unused, double *out_1790339001414145555);
void live_H_10(double *state, double *unused, double *out_1893699452435324030);
void live_h_12(double *state, double *unused, double *out_6926741151746481023);
void live_H_12(double *state, double *unused, double *out_6543319125784698924);
void live_h_35(double *state, double *unused, double *out_8761237368677182567);
void live_H_35(double *state, double *unused, double *out_2242852869474855808);
void live_h_32(double *state, double *unused, double *out_5272327477643904569);
void live_H_32(double *state, double *unused, double *out_4183691206807864609);
void live_h_13(double *state, double *unused, double *out_5700904563708779069);
void live_H_13(double *state, double *unused, double *out_3093157017860749561);
void live_h_14(double *state, double *unused, double *out_1867464073431487895);
void live_H_14(double *state, double *unused, double *out_6163409747366695902);
void live_h_33(double *state, double *unused, double *out_2385039172882953183);
void live_H_33(double *state, double *unused, double *out_6007304910960981379);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}