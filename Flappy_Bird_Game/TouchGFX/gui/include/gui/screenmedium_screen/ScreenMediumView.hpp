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

    virtual void handleTickEvent();
protected:
        int16_t localImageX;
        uint32_t tickCount;

        void scoringFunct();
        Unicode::UnicodeChar scoreBuffer[10]; // bộ đệm để chứa chuỗi
    };

#endif // SCREENMEDIUMVIEW_HPP
