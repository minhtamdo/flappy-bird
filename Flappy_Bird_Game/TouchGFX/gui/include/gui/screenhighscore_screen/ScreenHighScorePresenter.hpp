#ifndef SCREENHIGHSCOREPRESENTER_HPP
#define SCREENHIGHSCOREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenHighScoreView;

class ScreenHighScorePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenHighScorePresenter(ScreenHighScoreView& v);

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

    virtual ~ScreenHighScorePresenter() {}
    void UpdateImageX(int16_t x);
	int16_t GetImageX();
private:
    ScreenHighScorePresenter();

    ScreenHighScoreView& view;
};

#endif // SCREENHIGHSCOREPRESENTER_HPP
