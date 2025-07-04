#include <gui/screenhard_screen/ScreenHardView.hpp>
#include <gui/screenhard_screen/ScreenHardPresenter.hpp>

ScreenHardPresenter::ScreenHardPresenter(ScreenHardView& v)
    : view(v)
{

}

void ScreenHardPresenter::activate()
{

}

void ScreenHardPresenter::deactivate()
{

}

void ScreenHardPresenter::UpdateImageX(int16_t x)
{
	model->update(x);
}

int16_t ScreenHardPresenter::GetImageX()
{
	return model->GetImageX();
}
