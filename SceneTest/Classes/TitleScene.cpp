#include "TitleScene.h"
//#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "GameManager.h"
#include "../CocosDenshion/include/SimpleAudioEngine.h"


using namespace cocos2d;
using namespace CocosDenshion;

//using namespace CocosDenshion;

CCScene* Title::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    //背景色追加
    CCLayerColor* background = CCLayerColor::create(ccc4(100, 0, 100, 255));
    scene->addChild(background);

    // 'layer' is an autorelease object
    Title *layer = Title::create();



    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Title::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    int stage_id = GameManager::sharedInstance()->getStageId();
    CCLog("%d", stage_id);

    GameManager::sharedInstance()->setStageId(4);
    stage_id = GameManager::sharedInstance()->getStageId();



    /////////////////////////////
    // 2. add a menu item with change scene
    CCMenuItemImage *pChangeSceneItem = CCMenuItemImage::create(
                                                                "CloseNormal.png",
                                                                "CloseSelected.png",
                                                                this,
                                                                menu_selector(Title::menuChangeScene) );
    pChangeSceneItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pChangeSceneItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();


    // add "HelloWorld" splash screen"
    pSprite = CCSprite::create("title_back.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    //パーティクル追加
    //パーティクル
    CCParticleExplosion *pParticle = CCParticleExplosion::createWithTotalParticles(1000);
    this->addChild(pParticle);

    //BGM
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgm.mp3", true);


    return true;
}

void Title::menuChangeScene(CCObject *pSender)
{
	//フェードにいろいろなエフェクト
	/*pSprite->runAction(CCSpawn::create
	    						(
	    							CCTintTo::create(1.0f , 255 , 0 , 0),
	    							CCTintTo::create(1.0f , 255 , 0 , 0),
	    							NULL)
	    						);
	*/

	CCScene *pScene = HelloWorld::scene();

	// 0.5秒かけてフェードアウトしながら次の画面に遷移します
	CCTransitionCrossFade* transition = CCTransitionCrossFade::create(1.0f, pScene);

	CCDirector::sharedDirector()->replaceScene(transition);

    //CCDirector::sharedDirector()->replaceScene( HelloWorld::scene());
}
