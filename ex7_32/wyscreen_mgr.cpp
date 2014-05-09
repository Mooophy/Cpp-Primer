#include "wyscreen_mgr.h"
#include <string>

void wyScreen_mgr::clear(ScreenIndex i)
{
    wyScreen &s = this->wyScreens[i];
    s.contents = std::string(" ", s.height * s.width);
}


