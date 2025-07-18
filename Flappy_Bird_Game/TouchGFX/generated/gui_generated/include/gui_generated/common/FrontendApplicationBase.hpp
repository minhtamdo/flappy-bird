/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoScreenStartScreenNoTransition();
    }

    // ScreenStart
    void gotoScreenStartScreenNoTransition();

    void gotoScreenStartScreenSlideTransitionEast();

    // ScreenMenu
    void gotoScreenMenuScreenSlideTransitionEast();

    // ScreenEasy
    void gotoScreenEasyScreenSlideTransitionEast();

    // ScreenMedium
    void gotoScreenMediumScreenSlideTransitionEast();

    // ScreenHard
    void gotoScreenHardScreenSlideTransitionEast();

    // ScreenHighScore
    void gotoScreenHighScoreScreenSlideTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // ScreenStart
    void gotoScreenStartScreenNoTransitionImpl();

    void gotoScreenStartScreenSlideTransitionEastImpl();

    // ScreenMenu
    void gotoScreenMenuScreenSlideTransitionEastImpl();

    // ScreenEasy
    void gotoScreenEasyScreenSlideTransitionEastImpl();

    // ScreenMedium
    void gotoScreenMediumScreenSlideTransitionEastImpl();

    // ScreenHard
    void gotoScreenHardScreenSlideTransitionEastImpl();

    // ScreenHighScore
    void gotoScreenHighScoreScreenSlideTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
