#include "drum_model.h"

DrumModel* create_drum_model() {
    DrumModel* drum_model = (DrumModel*)malloc(sizeof(DrumModel));
    // TODO: initialize with default values
    return drum_model;
}

float decay(size_t x, size_t length) {
    float norm_factor = 1.0/(1.0 - 0.01832);
    return fmax((norm_factor * exp(-1.0*4*(x/(float)length))-0.01832), 0.0);
}

void drum_model_process(DrumModel* drum_model,
                        float* drum_buf,
                        size_t drum_buf_size)
{
    size_t samplerate = 48000;
    float base_freq_norm_min = (drum_model->base_freq*2*M_PI)/(float)(samplerate);
    float base_freq_norm_extra = 0.5 * base_freq_norm_min;

    float base[drum_buf_size];
    float ov1[drum_buf_size];
    float ov2[drum_buf_size];
    float noise[drum_buf_size];

    size_t si = drum_model->sample_idx;
    for(int i = 0; i < drum_buf_size; i++)
    {
        float fm_decay_t = decay(i+si, samplerate*drum_model->fm_decay);
        float base_freq_norm = base_freq_norm_min + 2.0*fm_decay_t*base_freq_norm_extra;
        float ov1_freq_norm = 2*base_freq_norm;
        float ov2_freq_norm = 4*base_freq_norm;

        base[i] = decay(i+si, samplerate*drum_model->base_decay) * drum_model->base_amp * sin(base_freq_norm*(i+si));
        ov1[i] = decay(i+si, samplerate*drum_model->ov1_decay) * drum_model->ov1_amp * sin(ov1_freq_norm*(i+si));
        ov2[i] = decay(i+si, samplerate*drum_model->ov2_decay) * drum_model->ov2_amp * sin(ov2_freq_norm*(i+si));
        noise[i] = decay(i+si, samplerate*drum_model->noise_decay) * drum_model->noise_amp * (2.0*(rand()/((float)RAND_MAX)) - 1.0);

        drum_buf[i] = base[i] + ov1[i] + ov2[i] + noise[i];
    }

    drum_model->sample_idx += drum_buf_size;
    if(drum_model->sample_idx >= 48000){
        drum_model->is_end = true;
    }
}

void drum_model_clear(DrumModel* drum_model)
{
    free(drum_model);
}
