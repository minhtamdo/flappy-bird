#include <gui/screenmedium_screen/ScreenMediumView.hpp>
#include <gui/screenmedium_screen/ScreenMediumPresenter.hpp>

ScreenMediumPresenter::ScreenMediumPresenter(ScreenMediumView& v)
    : view(v)
{

}

void ScreenMediumPresenter::activate()
{

}

void ScreenMediumPresenter::deactivate()
{

}

void ScreenMediumPresenter::UpdateImageX(int16_t x)
{
	model->update(x);
}

int16_t ScreenMediumPresenter::GetImageX()
{
	return model->GetImageX();
}

