#ifndef SCREENEASYVIEW_HPP
#define SCREENEASYVIEW_HPP

#include <gui_generated/screeneasy_screen/ScreenEasyViewBase.hpp>
#include <gui/screeneasy_screen/ScreenEasyPresenter.hpp>

class ScreenEasyView : public ScreenEasyViewBase
{
public:
    ScreenEasyView();
    virtual ~ScreenEasyView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
protected:
    int16_t localImageX;
    uint32_t tickCount;

    void scoringFunct();
    Unicode::UnicodeChar scoreBuffer[10]; // bộ đệm để chứa chuỗi
};

#endif // SCREENEASYVIEW_HPP
