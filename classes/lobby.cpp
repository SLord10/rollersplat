#include "methodes.h"
USING_NS_CC;

Scene* lobby::createScene()
{
    return lobby::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

// on "init" you need to initialize your instance
bool lobby::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //arriere plan 
    auto sprite = Sprite::create("lobby.png");
    if (sprite == nullptr)
    {
        problemLoading("'lobby.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    //level1
    auto menu_item_1 = MenuItemImage::create("level01.png", "level01selected.png", CC_CALLBACK_1(lobby::level1, this));
    menu_item_1->setPosition(Vec2(visibleSize.width / 7, (visibleSize.height / 2.5) * 2));
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->setPosition(Vec2(0, 0));
    this->addChild(menu);

    //level2
    auto menu_item_2 = MenuItemImage::create("level02.png", "level02selected.png", CC_CALLBACK_1(lobby::level2, this));
    menu_item_2->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height / 2.5) * 2));
    auto* menu2 = Menu::create(menu_item_2, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2);

    //level3
    auto menu_item_3 = MenuItemImage::create("level03.png", "level03selected.png", CC_CALLBACK_1(lobby::level3, this));
    menu_item_3->setPosition(Vec2(visibleSize.width / 1.18, (visibleSize.height / 2.5) * 2));
    auto* menu3 = Menu::create(menu_item_3, NULL);
    menu3->setPosition(Vec2(0, 0));
    this->addChild(menu3);

    //level4
    auto menu_item_4 = MenuItemImage::create("level04.png", "level04selected.png", CC_CALLBACK_1(lobby::level4, this));
    menu_item_4->setPosition(Vec2(visibleSize.width / 7, (visibleSize.height / 4) * 2));
    auto* menu4 = Menu::create(menu_item_4, NULL);
    menu4->setPosition(Vec2(0, 0));
    this->addChild(menu4);

    //level5
    auto menu_item_5 = MenuItemImage::create("level05.png", "level05selected.png", CC_CALLBACK_1(lobby::level5, this));
    menu_item_5->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height / 4) * 2));
    auto* menu5 = Menu::create(menu_item_5, NULL);
    menu5->setPosition(Vec2(0, 0));
    this->addChild(menu5);

    //level6
    auto menu_item_6 = MenuItemImage::create("level06.png", "level06selected.png", CC_CALLBACK_1(lobby::level6, this));
    menu_item_6->setPosition(Vec2(visibleSize.width / 1.18, (visibleSize.height / 4) * 2));
    auto* menu6 = Menu::create(menu_item_6, NULL);
    menu6->setPosition(Vec2(0, 0));
    this->addChild(menu6);

    return true;
}

void lobby::level1(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level1");
    auto scene = level1::createScene();
    Director::getInstance()->pushScene(scene);
}

void lobby::level2(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level2");
    auto scene = level2::createScene();
    Director::getInstance()->pushScene(scene);
}

void lobby::level3(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level3");
    auto scene = level3::createScene();
    Director::getInstance()->pushScene(scene);
}

void lobby::level4(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level4");
    auto scene = level4::createScene();
    Director::getInstance()->pushScene(scene);
}

void lobby::level5(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level");
    auto scene = level5::createScene();
    Director::getInstance()->pushScene(scene);
}

void lobby::level6(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("level6");
    auto scene = level6::createScene();
    Director::getInstance()->pushScene(scene);
}

