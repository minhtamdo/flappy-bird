#include <gui/screenhighscore_screen/ScreenHighScoreView.hpp>
#include <gui/screenhighscore_screen/ScreenHighScorePresenter.hpp>

ScreenHighScorePresenter::ScreenHighScorePresenter(ScreenHighScoreView& v)
    : view(v)
{

}

void ScreenHighScorePresenter::activate()
{

}

void ScreenHighScorePresenter::deactivate()
{

}

void ScreenHighScorePresenter::UpdateImageX(int16_t x)
{
	model->update(x);
}

int16_t ScreenHighScorePresenter::GetImageX()
{
	return model->GetImageX();
}
