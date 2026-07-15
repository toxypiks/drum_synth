#ifndef DRUM_TONE_HANDLER_H_
#define DRUM_TONE_HANDLER_H_

#include "drum_model.h"
#include "drum_msg.h"
#include "adsr.h"

typedef struct DrumToneMap {
    int key;
    DrumModel value;
} DrumToneMap;


typedef struct DrumToneHandler {
    DrumToneMap* drum_tone_map;
    int key_idx;
} DrumToneHandler;

void set_drum_tone_wrapper(void* drum_msg_new_raw, void* drum_tone_handler_raw);
void set_drum_tone(DrumMsg *drum_msg_new, DrumToneHandler *drum_tone_handler);
int drum_tone_handler_len(DrumToneHandler *drum_tone_handler);
void drum_tone_handler_cleanup(DrumToneHandler *drum_tone_handler);
void drum_tone_handler_free_hashmap(DrumToneHandler *drum_tone_handler);
void print_drum_tone_handler_hash_map(DrumToneHandler *drum_tone_handler);

#endif // DRUM_TONE_HANDLER_H_
