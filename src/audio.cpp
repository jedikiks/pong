#include "../include/audio.hpp"
#include "raylib.h"


Audio::Audio (Sound ballFx) {
    m_ballFx = ballFx;
}

void Audio::initAudio() {
    InitAudioDevice();
}

void Audio::deInitAudio() {
    UnloadSound(m_ballFx);
    CloseAudioDevice();
}

void Audio::playBallFx() {
    PlaySound(m_ballFx);
}