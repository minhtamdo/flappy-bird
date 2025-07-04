#ifndef SCREENMEDIUMVIEW_HPP
#define SCREENMEDIUMVIEW_HPP

#include <gui_generated/screenmedium_screen/ScreenMediumViewBase.hpp>
#include <gui/screenmedium_screen/ScreenMediumPresenter.hpp>

class ScreenMediumView : public ScreenMediumViewBase
{
public:
    ScreenMediumView();
    virtual ~ScreenMediumView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
};

#endif // SCREENMEDIUMVIEW_HPP
