#ifndef SCREENEASYPRESENTER_HPP
#define SCREENEASYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenEasyView;

class ScreenEasyPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenEasyPresenter(ScreenEasyView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenEasyPresenter() {}
    void UpdateImageX(int16_t x);
    int16_t GetImageX();

private:
    ScreenEasyPresenter();

    ScreenEasyView& view;
};

#endif // SCREENEASYPRESENTER_HPP
