#include <gui/screenhard_screen/ScreenHardView.hpp>
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

uint32_t hgameSpeed= 1;
uint16_t hholeX = 0;
float hholeY = 0;
float hholeYCentre = 0;
uint16_t hhalfSpace = 60;

float hsinValue = 0;
float hbirdY = 160.0f;         // vị trí chim theo trục Y
float hbirdVelocity = 0.0f;    // vận tốc tức thời
float hgravity = -0.2f;        // gia tốc rơi (thử từ 0.2 đến 0.5)
float hjumpStrength = 3.5f;   // vận tốc khi nhấn nút

bool isShield = true;
bool makeShield = false;

static uint8_t rand_n = 0;

ScreenHardView::ScreenHardView()
{
	tickCount = 0;
}

void ScreenHardView::setupScreen()
{
    localImageX = presenter->GetImageX();
	ScreenHardViewBase::setupScreen();
	bird.setX(birdX);
	hholeYCentre = 0;
	hholeX = 265;
	hholeY = 160;
	shield.setX(240);
	shield.setY(320);
	isShield = false;
	makeShield = false;
	scorePlaying = 0;
	//Text Progress
	Unicode::snprintf(scoreBuffer, 10, "%u", scorePlaying);
	score.setWildcard(scoreBuffer);
	score.invalidate();
	//Reset Queue
	osMessageQueueReset(Queue1Handle);

	hgameSpeed= 1;
}

void ScreenHardView::tearDownScreen()
{
    ScreenHardViewBase::tearDownScreen();
	presenter->UpdateImageX(localImageX);
	//Callback setup Screen each time press START
	setupScreen();
}

void ScreenHardView::scoringFunct() {

	//TODO: Fix exact colision of lamb and image1 for Scoring


	if(hholeX == 0){
		scorePlaying += 1;
	}

	if( ((hbirdY + 36 >= hholeY + hhalfSpace) || (hbirdY <= hholeY - hhalfSpace))
		&& !(birdX >= hholeX + 65 || birdX + 36 <= hholeX)){
		if(isShield){
			isShield = false;
			makeShield = false;
			tickCount = 0;
		} else {
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
	}

	//Update score Playing
	Unicode::snprintf(scoreBuffer, 10, "%u", scorePlaying);
	score.setWildcard(scoreBuffer);

}

void ScreenHardView::handleTickEvent(){
	score.invalidate();
	ScreenHardViewBase::handleTickEvent();

	tickCount++;

	//Random
	if (tickCount * hgameSpeed% 300 == 0) {
		rand_n = osKernelGetTickCount() % (320 - 40 - 60 - 2 * hhalfSpace);
		if (scorePlaying % 2 == 0 && !isShield && scorePlaying != 0){
			makeShield = true;
		}
	}
	//Game speeding
	if (scorePlaying > 10) {
		hgameSpeed= 2;
	} else if (scorePlaying > 30) {
		hgameSpeed= 3;
	} else if (scorePlaying > 70) {
		hgameSpeed= 4;
	}

	hholeX = 240 - (tickCount * hgameSpeed % 300);

	boxWithBorder2.setX(hholeX);
	boxWithBorder1.setX(hholeX);

	float amplitude = 30.0f;
	float angle = tickCount * hgameSpeed * 0.05f;
	float sinValue = sinf(angle);  // sinf: dùng cho float

	hholeYCentre = rand_n + hhalfSpace + 20 + amplitude;

	hholeY = hholeYCentre + sinValue * amplitude;
	boxWithBorder2.setY(hholeY + hhalfSpace);
	boxWithBorder1.setY(hholeY - hhalfSpace - boxWithBorder1.getHeight());

	if(hholeX == 48 && makeShield){
		isShield = true;
		makeShield = false;
	}

	if (isShield){
		shield.setX(8);
		shield.setY(hbirdY- 17);
	} else if (makeShield){
		shield.setX(hholeX);
		shield.setY(hholeYCentre + sinValue * amplitude - 40);
	} else {
		shield.setX(240);
		shield.setY(320);
	}


	//Moving bird
	char cmd[5];  // bộ đệm để nhận lện
	if (osMessageQueueGet(Queue1Handle, &cmd, NULL, 0) == osOK) {
		if (strcmp(cmd, "jump") == 0) {
			hbirdVelocity = hjumpStrength;   // bật lên

		}
	}

	// Cập nhật vật lý
	hbirdVelocity += hgravity;      // tăng dần do trọng lực
	hbirdY += hbirdVelocity;        // cập nhật vị trí chim

	// Giới hạn không cho rơi xuống dưới đáy
	//	if (mbirdY > 240) mbirdY = 240;
	if (hbirdY < 0)   hbirdY = 0;
	if (hbirdY > 290)  hbirdY = 290;

	bird.setY((int)hbirdY);        // cập nhật vị trí cho chim

	scoringFunct();

	invalidate();

}



