#include <gui/screeneasy_screen/ScreenEasyView.hpp>
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

uint32_t gameSpeed = 1;
uint16_t holeX = 0;
uint16_t holeY = 0;
uint16_t halfSpace = 60;

float birdY = 160.0f;         // vị trí chim theo trục Y
float birdVelocity = 0.0f;    // vận tốc tức thời
float gravity = 0.2f;        // gia tốc rơi (thử từ 0.2 đến 0.5)
float jumpStrength = -3.5f;   // vận tốc khi nhấn nút

static uint8_t rand_n = 0;

ScreenEasyView::ScreenEasyView()
{
	tickCount = 0;
}

void ScreenEasyView::setupScreen()
{
    localImageX = presenter->GetImageX();
	ScreenEasyViewBase::setupScreen();
	bird.setX(birdX);
	holeX = 265;
	holeY = 160;


	scorePlaying = 0;
	//Text Progress
	Unicode::snprintf(scoreBuffer, 10, "%u", scorePlaying);
	score.setWildcard(scoreBuffer);
	score.invalidate();
	//Reset Queue
	osMessageQueueReset(Queue1Handle);

	gameSpeed = 1;
}

void ScreenEasyView::tearDownScreen()
{
    ScreenEasyViewBase::tearDownScreen();
	presenter->UpdateImageX(localImageX);
	//Callback setup Screen each time press START
	setupScreen();
}

void ScreenEasyView::scoringFunct() {

	//TODO: Fix exact colision of lamb and image1 for Scoring


	if(holeX == 0){
		scorePlaying += 1;
	}

	if( ((birdY + 36 >= holeY + halfSpace) || (birdY <= holeY - halfSpace))
		&& !(birdX >= holeX + 65 || birdX + 36 <= holeX)){
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

void ScreenEasyView::handleTickEvent(){
	score.invalidate();
	ScreenEasyViewBase::handleTickEvent();

	tickCount++;

	//Random
	if (tickCount * gameSpeed % 300 == 0) {
		rand_n = osKernelGetTickCount() % (320 - 40 - 2 * halfSpace);
	}
	//Game speeding
	if (scorePlaying > 10) {
		gameSpeed = 2;
	} else if (scorePlaying > 30) {
		gameSpeed = 3;
	} else if (scorePlaying > 70) {
		gameSpeed = 4;
	}

	holeX = 240 - (tickCount * gameSpeed % 300);
	holeY = rand_n + halfSpace + 20;

	boxWithBorder2.setX(holeX);
	boxWithBorder1.setX(holeX);

	boxWithBorder2.setY(holeY + halfSpace);
	boxWithBorder1.setY(holeY - halfSpace - boxWithBorder1.getHeight());


	//Moving bird
	char cmd[5];  // bộ đệm để nhận lệnh
	if (osMessageQueueGet(Queue1Handle, &cmd, NULL, 0) == osOK) {
		if (strcmp(cmd, "jump") == 0) {
			birdVelocity = jumpStrength;   // bật lên

		}
	}

	// Cập nhật vật lý
	birdVelocity += gravity;      // tăng dần do trọng lực
	birdY += birdVelocity;        // cập nhật vị trí chim

	// Giới hạn không cho rơi xuống dưới đáy
	//	if (birdY > 240) birdY = 240;
	if (birdY < 0)   birdY = 0;
	if (birdY > 290)  birdY = 290;

	bird.setY((int)birdY);        // cập nhật vị trí cho chim

	scoringFunct();

	invalidate();

}

