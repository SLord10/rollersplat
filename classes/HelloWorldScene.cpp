#include "HelloWorldScene.h"
#include "methodes.h"
#include "cocos/editor-support/cocostudio/SimpleAudioEngine.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //arriere plan
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);

    }

    
    //bouton play pour aller vers choix de niveau
    auto menu_item_1 = MenuItemImage::create("play.png", "playselected.png", CC_CALLBACK_1(HelloWorld::Play, this));
    menu_item_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);


    return true;
}
//fonction pour aller au choix des niveaux
void HelloWorld::Play(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("play");
    auto scene = lobby::createScene();
    Director::getInstance()->pushScene(scene);

}