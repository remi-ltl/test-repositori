#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "TitleScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    //FPSなどの表示
    pDirector->setDisplayStats(true);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCEGLView* view = CCDirector::sharedDirector()->getOpenGLView();
    CCSize frame = view->getFrameSize();
    if (frame.height==1136.0) {
        // iPhone5などの解像度
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(320, 568, kResolutionExactFit);
    } else {
        CCEGLView::sharedOpenGLView()->setDesignResolutionSize(320, 480, kResolutionExactFit);
    }
#else
    // Android用
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(320, 480, kResolutionExactFit);
#endif

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = Title::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
