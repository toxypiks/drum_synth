#include "dum_msg.h"
#include <string.h>
#include "ui_stuff.h"
#include "stb_ds.h"
#include <stdio.h>

void set_drum_msg(void* drum_msg_new_raw, void* drum_msg_raw)
{
    DrumMsg* drum_msg = (DrumMsg*)drum_msg_raw;
    DrumMsg* drum_msg_new = (DrumMsg*)drum_msg_new_raw;
    memcpy(drum_msg, drum_msg_new, sizeof(DrumMsg));
}

/*
void set_drum_msgs_in_hmap(void* drum_msg_new_raw, void* key_map_raw)
{
    KeyboardPressedKeyMap** key_map = (KeyboardPressedKeyMap**)key_map_raw;
    DrumMsg* drum_msg_new = (DrumMsg*)drum_msg_new_raw;

    int key = drum_msg_new->key;
    if(drum_msg_new->is_on){
         bool value = true;
        hmput((*key_map), key, value);
        printf("set_drum_msg_in_hmap: key: %d\n", key);
    } else {
        // NoteOff is_on = false
        hmdel((*key_map), key);
    }
}
*/
