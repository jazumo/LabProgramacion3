#include "MapScene.h"

USING_NS_CC;

Scene* MapScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MapScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool MapScene::init() 
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    log("Initializing map scene");

    auto bg = cocos2d::LayerColor::create(Color4B(51, 255, 238, 255));
    this->addChild(bg, -1);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Agregar imagen de mapa
    auto mapa = Sprite::create("Images/mapa.png");
    if (mapa != nullptr) {
        mapa->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
        this->addChild(mapa, 0);
    }


    //T�tulo
    auto label = Label::createWithTTF("Mapa", "fonts/Marker Felt.ttf", 24);
    if (label != nullptr) {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        label->setColor(Color3B::BLACK);
        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    return true;
}

void MapScene::regresarCloseCallback(Ref* pSender)
{
    log("Regresando al men� principal");
    //creando la escena
    auto scene = MainMenu::createScene();
    //Reemplazando la escena actual con la siguiente, se aplica un efecto de transici�n
    Director::getInstance()->replaceScene(TransitionSlideInL::create(1, scene));
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}