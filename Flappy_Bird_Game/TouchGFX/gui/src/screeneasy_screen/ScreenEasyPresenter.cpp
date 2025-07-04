#include <gui/screeneasy_screen/ScreenEasyView.hpp>
#include <gui/screeneasy_screen/ScreenEasyPresenter.hpp>

ScreenEasyPresenter::ScreenEasyPresenter(ScreenEasyView& v)
    : view(v)
{

}

void ScreenEasyPresenter::activate()
{

}

void ScreenEasyPresenter::deactivate()
{

}

void ScreenEasyPresenter::UpdateImageX(int16_t x)
{
	model->update(x);
}

int16_t ScreenEasyPresenter::GetImageX()
{
	return model->GetImageX();
}
