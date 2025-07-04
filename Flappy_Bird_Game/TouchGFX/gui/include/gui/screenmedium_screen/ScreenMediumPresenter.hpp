#ifndef SCREENMEDIUMPRESENTER_HPP
#define SCREENMEDIUMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenMediumView;

class ScreenMediumPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenMediumPresenter(ScreenMediumView& v);

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

    virtual ~ScreenMediumPresenter() {}
    void UpdateImageX(int16_t x);
    int16_t GetImageX();
private:
    ScreenMediumPresenter();

    ScreenMediumView& view;
};

#endif // SCREENMEDIUMPRESENTER_HPP
