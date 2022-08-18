#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

class Audio {
    private:
            Sound m_ballFx {};
        
    public:
            Audio (Sound ballFx);

            void initAudio();
            void deInitAudio();
            void playBallFx();
};

#endif