/*
 * signals.c
 *
 *  Created on: Dec 19, 2021
 *      Author: gugu
 */

#include <math.h>
#include <stdint.h>
#include "signals.h"

uint16_t C[368] = {0};
uint16_t C_SHARP[348] = {0};
uint16_t D[328] = {0};
uint16_t D_SHARP[310] = {0};
uint16_t E[292] = {0};
uint16_t F[276] = {0};
uint16_t F_SHARP[260] = {0};
uint16_t G[246] = {0};
uint16_t G_SHARP[232] = {0};
uint16_t A[220] = {0};
uint16_t A_SHARP[206] = {0};
uint16_t H[196] = {0};

void sampling(float frequency, int samples, uint16_t *signal_array);

void generateSignals() {
	sampling(FREQ_C, C_SAMPLES, C);
	sampling(FREQ_C_SHARP, C_SHARP_SAMPLES, C_SHARP);
	sampling(FREQ_D, D_SAMPLES, D);
	sampling(FREQ_D_SHARP, D_SHARP_SAMPLES, D_SHARP);
	sampling(FREQ_E, E_SAMPLES, E);
	sampling(FREQ_F, F_SAMPLES, F);
	sampling(FREQ_F_SHARP, F_SHARP_SAMPLES, F_SHARP);
	sampling(FREQ_G, G_SAMPLES, G);
	sampling(FREQ_G_SHARP, G_SHARP_SAMPLES, G_SHARP);
	sampling(FREQ_A, A_SAMPLES, A);
	sampling(FREQ_A_SHARP, A_SHARP_SAMPLES, A_SHARP);
	sampling(FREQ_H, H_SAMPLES, H);
}

void sampling(float frequency, int samples, uint16_t *signal_array) {
	for (int i = 0; i < samples; i+=2) {
		signal_array[i] = (uint16_t) 65535*sin(2*M_PI*frequency*i*(1/SAMPLE_FREQUENCY)) + 32767;
		signal_array[i+1] = (uint16_t) signal_array[i];
	}
}
