#include "methodes.h"

USING_NS_CC;

Scene* credit::createScene()
{
    return credit::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool credit::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize2 = Director::getInstance()->getVisibleSize();
    Vec2 origin2 = Director::getInstance()->getVisibleOrigin();


    auto sprite = Sprite::create("credit.png");
    if (sprite == nullptr)
    {
        problemLoading("'credit.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 100 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);

    }
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("ending.mp3");
    auto moveto = MoveTo::create(95, Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 0.5 + origin2.y));
    sprite->runAction(moveto);

   
}


