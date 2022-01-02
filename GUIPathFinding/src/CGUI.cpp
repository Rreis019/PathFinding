#include "CGUI.h"
#include "CInput.h"
#include "CWindow.h"

bool CGUI::button(int x, int y){
    CWindow &w = CWindow::Get();
    CGUI &g = CGUI::Get();

    bool isHovered = Input::GetMouseX() > x && Input::GetMouseX() < x + g.ButtonWidth && Input::GetMouseY() > y && Input::GetMouseY() < y + g.ButtonHeight;

    w.DrawRectangle(x- g.ButtonBorderThickness, y- g.ButtonBorderThickness, g.ButtonWidth+ g.ButtonBorderThickness*2, g.ButtonHeight+ g.ButtonBorderThickness*2, g.ButtonBorderThickness, g.ButtonBorderColor.r, g.ButtonBorderColor.g, g.ButtonBorderColor.b, g.ButtonBorderColor.a);
    if(isHovered)
    {
        w.DrawFilledRectangle(x, y, g.ButtonWidth, g.ButtonHeight, g.ButtonHoverColor.r, g.ButtonHoverColor.g, g.ButtonHoverColor.b, g.ButtonHoverColor.a);
        //SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND));
        //if(Input::IsMouseLeftClicked())
        return true;
    }
    else{
         w.DrawFilledRectangle(x, y, g.ButtonWidth, g.ButtonHeight, g.ButtonColor.r, g.ButtonColor.g, g.ButtonColor.b, g.ButtonColor.a);
    }

    return false;
}