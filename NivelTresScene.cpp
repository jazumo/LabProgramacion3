//Leo Pazzetti
#include "NivelTresScene.h"
#include "MapScene.h"

USING_NS_CC;

Scene* NivelTresScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = NivelTresScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NivelTresScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto menuItem1 = MenuItemFont::create("GoBack3", CC_CALLBACK_1(NivelTresScene::GoBack, this));

    menuItem1->setPosition(Point(visibleSize.width / 2, (visibleSize.height / 2) * 1));

    auto mapa = Menu::create(menuItem1, NULL);
    mapa->setPosition(Point(0, 0));
    this->addChild(mapa);

    return true;
}

void NivelTresScene::GoBack(cocos2d::Ref* pSender) {
    auto scene = MapScene::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInL::create(1, scene));
}


void NivelTresScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}