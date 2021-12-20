/*
 * audio.h
 *
 *  Created on: Dec 18, 2021
 *      Author: gugu
 */

#ifndef INC_AUDIO_H_
#define INC_AUDIO_H_

#define AUDIO_RESET_PIN		CS43L22_Reset_Pin
#define AUDIO_I2C_ADDRESS	0x94

void init_AudioReset();
void configAudio();

#endif /* INC_AUDIO_H_ */
