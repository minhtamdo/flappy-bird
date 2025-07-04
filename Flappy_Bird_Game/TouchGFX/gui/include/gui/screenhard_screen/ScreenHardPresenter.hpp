#ifndef SCREENHARDPRESENTER_HPP
#define SCREENHARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenHardView;

class ScreenHardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenHardPresenter(ScreenHardView& v);

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

    virtual ~ScreenHardPresenter() {}
    void UpdateImageX(int16_t x);
    int16_t GetImageX();
private:
    ScreenHardPresenter();

    ScreenHardView& view;
};

#endif // SCREENHARDPRESENTER_HPP
