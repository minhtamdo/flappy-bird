#include <gui/screenhighscore_screen/ScreenHighScoreView.hpp>
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include <cstdlib>
#include <math.h>
#include <string.h>


extern uint32_t scoreBest;
extern uint32_t scoreSecond;
extern uint32_t scoreThird;

ScreenHighScoreView::ScreenHighScoreView()
{

}

void ScreenHighScoreView::setupScreen()
{
	localImageX = presenter->GetImageX();
    ScreenHighScoreViewBase::setupScreen();
	//Update score Playing
//    Unicode::snprintf(scoreBuffer[0], 10, "%u", scoreBest);
//    highescore1.setWildcard(scoreBuffer[0]);
//    highescore1.invalidate();
//
//    Unicode::snprintf(scoreBuffer[1], 10, "%u", scoreSecond);
//    highescore2.setWildcard(scoreBuffer[1]);
//    highescore2.invalidate();
//
//    Unicode::snprintf(scoreBuffer[2], 10, "%u", scoreThird);
//    highescore3.setWildcard(scoreBuffer[2]);
//    highescore3.invalidate();
    textProgress1.setValue(scoreBest);
    textProgress1.invalidate();
    textProgress2.setValue(scoreSecond);
    textProgress2.invalidate();
    textProgress3.setValue(scoreThird);
    textProgress3.invalidate();

}

void ScreenHighScoreView::tearDownScreen()
{
    ScreenHighScoreViewBase::tearDownScreen();
	setupScreen();
}
