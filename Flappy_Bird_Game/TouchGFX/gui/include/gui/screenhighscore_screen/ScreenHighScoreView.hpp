#ifndef SCREENHIGHSCOREVIEW_HPP
#define SCREENHIGHSCOREVIEW_HPP

#include <gui_generated/screenhighscore_screen/ScreenHighScoreViewBase.hpp>
#include <gui/screenhighscore_screen/ScreenHighScorePresenter.hpp>

class ScreenHighScoreView : public ScreenHighScoreViewBase
{
public:
    ScreenHighScoreView();
    virtual ~ScreenHighScoreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    int16_t localImageX;
    Unicode::UnicodeChar scoreBuffer[3][10];; // bộ đệm cho số điểm

};

#endif // SCREENHIGHSCOREVIEW_HPP
