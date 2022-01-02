#include <SDL2/SDL.h>
class CClock
{
    public:
        void Tick(int fps);
        int GetFps();

    private:
    	int StartTick = 0;
};

