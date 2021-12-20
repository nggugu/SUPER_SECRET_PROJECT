/*
 * signals.h
 *
 *  Created on: Dec 19, 2021
 *      Author: gugu
 */

#ifndef INC_SIGNALS_H_
#define INC_SIGNALS_H_

// Number of tones
#define TONE_NUMBER		12

// Something I don't quite understand
#define	TON_C		0
#define	TON_C_SHARP	1
#define	TON_D		2
#define	TON_D_SHARP	3
#define	TON_E		4
#define	TON_F		5
#define	TON_F_SHARP	6
#define	TON_G		7
#define	TON_G_SHARP	8
#define	TON_A		9
#define	TON_A_SHARP	10
#define	TON_H		11

// Note frequiencies
#define	FREQ_C			261.63
#define	FREQ_C_SHARP	277.18
#define	FREQ_D			293.66
#define	FREQ_D_SHARP	311.13
#define	FREQ_E			329.63
#define	FREQ_F			349.23
#define	FREQ_F_SHARP	369.99
#define	FREQ_G			392.00
#define FREQ_G_SHARP	415.30
#define	FREQ_A			440.00
#define	FREQ_A_SHARP	466.16
#define FREQ_H			493.88

// Number of samples
// Samples were calculated SAMPLE_FREQUENCY / NOTE_FREQUENCY
#define	C_SAMPLES		184
#define	C_SHARP_SAMPLES	174
#define	D_SAMPLES		164
#define	D_SHARP_SAMPLES	155
#define	E_SAMPLES		146
#define	F_SAMPLES		138
#define	F_SHARP_SAMPLES	130
#define	G_SAMPLES		123
#define	G_SHARP_SAMPLES	116
#define	A_SAMPLES		110
#define	A_SHARP_SAMPLES	103
#define	H_SAMPLES		98

// Sample frequency
#define	SAMPLE_FREQUENCY	48000

// Signals
extern uint16_t C[368];
extern uint16_t C_SHARP[348];
extern uint16_t D[328];
extern uint16_t D_SHARP[310];
extern uint16_t E[292];
extern uint16_t F[276];
extern uint16_t F_SHARP[260];
extern uint16_t G[246];
extern uint16_t G_SHARP[232];
extern uint16_t A[220];
extern uint16_t A_SHARP[206];
extern uint16_t H[196];
extern uint16_t silence[368];

// Prototypes
void generateSignals();

#endif /* INC_SIGNALS_H_ */
