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

    virtual void handleTickEvent();
protected:
           int16_t localImageX;
           uint32_t tickCount;

           void scoringFunct();
           Unicode::UnicodeChar scoreBuffer[10]; // bộ đệm để chứa chuỗi
       };

#endif // SCREENHARDVIEW_HPP
