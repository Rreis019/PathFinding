#include "CClock.h"

void CClock::Tick(int fps)
{
    int EndTick = SDL_GetTicks();
    int Delta = EndTick - StartTick;

    if (Delta < 1000 / fps)
    {
        SDL_Delay(1000 / fps - Delta);
    }

    StartTick = SDL_GetTicks();
}