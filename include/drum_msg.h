#ifndef DRUM_MSG_H_
#define DRUM_MSG_H_
#include <stdbool.h>
#include <stddef.h>

typedef struct DrumMsg {
    float base_freq;
    float base_amp;
    float ov1_amp;
    float ov2_amp;
    float noise_amp;
    float base_decay;
    float ov1_decay;
    float ov2_decay;
    float noise_decay;
    size_t time_stamp;
} DrumMsg;

void set_drum_msg(void* midi_msg_new_raw, void* midi_msg_raw);
//void set_drum_msgs_in_hmap(void* midi_msg_new_raw, void* key_map_raw);

#endif // DRUM_MSG_H_
