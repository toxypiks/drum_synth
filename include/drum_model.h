#ifndef DRUM_MODEL_H
#define DRUM_MODEL_H

#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct DrumModel{
    float base_freq;

    float noise_amp;
    float base_amp;
    float ov1_amp;
    float ov2_amp;

    float noise_decay;
    float base_decay;
    float ov1_decay;
    float ov2_decay;
    bool is_end;
    size_t sample_idx;
} DrumModel;

DrumModel* create_drum_model();

void drum_model_process(DrumModel* drum_model,
                        float* drum_buf,
                        size_t drum_buf_size);

void synth_model_clear(DrumModel* drum_model);


#endif // DRUM_MODEL_H
