//! @Alan
//!
//! Exercise 7.32:
//! Define your own versions of Screen and Window_mgr
//! in which clear is a member of Window_mgr and a friend of Screen.
//  steps:
//  First, define the Window_mgr class, which declares, but cannot
//  define, clear. Screen must be declared before clear can use the
//  members of Screen.
//
//  Next, define class Screen, including a friend declaration for clear.
//
//  Finally, define clear, which can now refer to the members in Screen.
//

#ifndef WYSCREEN_MGR_H
#define WYSCREEN_MGR_H

#include <vector>
#include <wyscreen.h>

class wyScreen_mgr
{
public:
    //! @attention  note this statement
    using ScreenIndex =std::vector<wyScreen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<wyScreen> wyScreens{wyScreen(24, 80, ' ')};
};
#endif // WYSCREEN_MGR_H
