#include "drum_tone_handler.h"
#include <math.h>
#include <stdio.h>
#include "stb_ds.h"
#include "drum_msg.h"
#include "drum_model.h"

void set_drum_tone_wrapper(void* drum_msg_new_raw, void* drum_tone_handler_raw)
{
    DrumMsg *drum_msg_new = (DrumMsg*)drum_msg_new_raw;
    DrumToneHandler *drum_tone_handler = (DrumToneHandler*)drum_tone_handler_raw;
    set_drum_tone(drum_msg_new, drum_tone_handler);
}

void set_drum_tone(DrumMsg *drum_msg_new, DrumToneHandler *drum_tone_handler)
{
    int key = drum_tone_handler->key_idx++;

    DrumModel drum_model = {.base_freq = drum_msg_new->base_freq,
                            .noise_amp = drum_msg_new->noise_amp,
                            .base_amp = drum_msg_new->base_amp,
                            .ov1_amp = drum_msg_new->ov1_amp,
                            .ov2_amp = drum_msg_new->ov2_amp,
                            .noise_decay = drum_msg_new->noise_decay,
                            .base_decay = drum_msg_new->base_decay,
                            .ov1_decay = drum_msg_new->ov1_decay,
                            .ov2_decay = drum_msg_new->ov2_decay,
                            .is_end = false,
                            .sample_idx = 0
                        };

    hmput(drum_tone_handler->drum_tone_map, key, drum_model);
}

int drum_tone_handler_len(DrumToneHandler *drum_tone_handler)
{
    return hmlen(drum_tone_handler->drum_tone_map);
}


void drum_tone_handler_cleanup(DrumToneHandler *drum_tone_handler)
{
    int length = drum_tone_handler_len(drum_tone_handler);
    if(length < 0) return;
    for (int i = 0; i < length; ++i) {
        if(drum_tone_handler->drum_tone_map[i].value.is_end){
            int key = drum_tone_handler->drum_tone_map[i].key;
            hmdel(drum_tone_handler->drum_tone_map, key);
        }
    }
}

void drum_tone_handler_free_hashmap(DrumToneHandler *drum_tone_handler)
{
    hmfree(drum_tone_handler->drum_tone_map);
}
