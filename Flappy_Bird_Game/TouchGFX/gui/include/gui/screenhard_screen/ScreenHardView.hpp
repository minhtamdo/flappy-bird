#ifndef SCREENHARDVIEW_HPP
#define SCREENHARDVIEW_HPP

#include <gui_generated/screenhard_screen/ScreenHardViewBase.hpp>
#include <gui/screenhard_screen/ScreenHardPresenter.hpp>

class ScreenHardView : public ScreenHardViewBase
{
public:
    ScreenHardView();
    virtual ~ScreenHardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
};

#endif // SCREENHARDVIEW_HPP
