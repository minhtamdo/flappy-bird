#include <gui/screenmedium_screen/ScreenMediumView.hpp>
#include "cmsis_os.h"
#include "main.h"
#include "stdio.h"
#include <cstdlib>
#include <math.h>
#include <string.h>

extern osMessageQueueId_t Queue1Handle;
extern uint16_t birdX;

extern uint32_t scorePlaying;
extern uint32_t scoreBest;
extern uint32_t scoreSecond;
extern uint32_t scoreThird;

extern uint32_t tickKernel;

uint32_t mgameSpeed= 1;
uint16_t mholeX = 0;
float mholeY = 0;
float mholeYCentre = 0;
uint16_t mhalfSpace = 60;

float sinValue = 0;
float mbirdY = 160.0f;         // vị trí chim theo trục Y
float mbirdVelocity = 0.0f;    // vận tốc tức thời
float mgravity = 0.2f;        // gia tốc rơi (thử từ 0.2 đến 0.5)
float mjumpStrength = -3.5f;   // vận tốc khi nhấn nút

static uint8_t rand_n = 0;

ScreenMediumView::ScreenMediumView()
{
	tickCount = 0;
}

void ScreenMediumView::setupScreen()
{
    localImageX = presenter->GetImageX();
	ScreenMediumViewBase::setupScreen();
	bird.setX(birdX);
	mholeYCentre = 0;
	mholeX = 265;
	mholeY = 160;


	scorePlaying = 0;
	//Text Progress
	Unicode::snprintf(scoreBuffer, 10, "%u", scorePlaying);
	score.setWildcard(scoreBuffer);
	score.invalidate();
	//Reset Queue
	osMessageQueueReset(Queue1Handle);

	mgameSpeed= 1;
}

void ScreenMediumView::tearDownScreen()
{
    ScreenMediumViewBase::tearDownScreen();
	presenter->UpdateImageX(localImageX);
	//Callback setup Screen each time press START
	setupScreen();
}

void ScreenMediumView::scoringFunct() {

	//TODO: Fix exact colision of lamb and image1 for Scoring



	if(mholeX == 0){
		scorePlaying += 1;
	}

	if( ((mbirdY + 36 >= mholeY + mhalfSpace) || (mbirdY <= mholeY - mhalfSpace))
		&& !(birdX >= mholeX + 65 || birdX + 36 <= mholeX)){
		if(scorePlaying >= scoreBest){
			scoreThird = scoreSecond;
			scoreSecond = scoreBest;
			scoreBest = scorePlaying;
		}
		else if(scorePlaying >= scoreSecond){
			scoreThird = scoreSecond;
			scoreSecond = scorePlaying;
		}
		else if(scorePlaying >= scoreThird){
			scoreThird = scorePlaying;
		}
		application().gotoScreenHighScoreScreenSlideTransitionEast();
	}

	//Update score Playing
	Unicode::snprintf(scoreBuffer, 10, "%u", scorePlaying);
	score.setWildcard(scoreBuffer);

}

void ScreenMediumView::handleTickEvent(){
	score.invalidate();
	ScreenMediumViewBase::handleTickEvent();

	tickCount++;

	//Random
	if (tickCount * mgameSpeed% 300 == 0) {
		rand_n = osKernelGetTickCount() % (320 - 40 - 60 - 2 * mhalfSpace);
	}
	//Game speeding
	if (scorePlaying > 10) {
		mgameSpeed= 2;
	} else if (scorePlaying > 30) {
		mgameSpeed= 3;
	} else if (scorePlaying > 70) {
		mgameSpeed= 4;
	}

	mholeX = 240 - (tickCount * mgameSpeed % 300);

	boxWithBorder2.setX(mholeX);
	boxWithBorder1.setX(mholeX);

	float amplitude = 30.0f;
	float angle = tickCount * mgameSpeed * 0.05f;
	float sinValue = sinf(angle);  // sinf: dùng cho float

	mholeYCentre = rand_n + mhalfSpace + 20 + amplitude;

	mholeY = mholeYCentre + sinValue * amplitude;
	boxWithBorder2.setY(mholeY + mhalfSpace);
	boxWithBorder1.setY(mholeY - mhalfSpace - boxWithBorder1.getHeight());


	//Moving bird
	char cmd[5];  // bộ đệm để nhận lệnh
	if (osMessageQueueGet(Queue1Handle, &cmd, NULL, 0) == osOK) {
		if (strcmp(cmd, "jump") == 0) {
			mbirdVelocity = mjumpStrength;   // bật lên

		}
	}

	// Cập nhật vật lý
	mbirdVelocity += mgravity;      // tăng dần do trọng lực
	mbirdY += mbirdVelocity;        // cập nhật vị trí chim

	// Giới hạn không cho rơi xuống dưới đáy
	//	if (mbirdY > 240) mbirdY = 240;
	if (mbirdY < 0)   mbirdY = 0;
	if (mbirdY > 290)  mbirdY = 290;

	bird.setY((int)mbirdY);        // cập nhật vị trí cho chim

	scoringFunct();

	invalidate();

}



