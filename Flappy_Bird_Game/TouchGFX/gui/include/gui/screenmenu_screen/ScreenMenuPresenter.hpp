#ifndef SCREENMENUPRESENTER_HPP
#define SCREENMENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenMenuView;

class ScreenMenuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenMenuPresenter(ScreenMenuView& v);

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

    virtual ~ScreenMenuPresenter() {}

private:
    ScreenMenuPresenter();

    ScreenMenuView& view;
};

#endif // SCREENMENUPRESENTER_HPP
