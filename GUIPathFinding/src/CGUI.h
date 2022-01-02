#include "CSingleton.h"

struct CColor4{
    int r,g,b,a;
};



class CGUI : public CSingleton<CGUI>
{
    public:
        CColor4 ButtonColor = {255,255,255,255};
        CColor4 ButtonHoverColor = {233,233,233,255};
        CColor4 ButtonClickColor = {200,200,200,255};
        CColor4 ButtonTextColor = {0,0,0,255};
        CColor4 ButtonBorderColor = {0,0,0,255};
        int ButtonBorderThickness = 0;
        int ButtonWidth = 30, ButtonHeight = 30;


        static bool button(int x, int y);
        
    private:
};

