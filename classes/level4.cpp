#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level4::createScene()
{
    return level4::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level4::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize2 = Director::getInstance()->getVisibleSize();
    Vec2 origin2 = Director::getInstance()->getVisibleOrigin();

    //arriere plan
    auto sprite = Sprite::create("level4.png");
    if (sprite == nullptr)
    {
        problemLoading("'level4.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);

    }



    black = Sprite::create("level4sprite.png");

    black->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2.4 + origin2.y));
    black->setScale(1);
    this->addChild(black, 1);

  
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level4::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level4::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);

    ball = Sprite::create("ball.png");
    ball->setPosition(Vec2(285, 100));
    ball->setScale(1);
    this->addChild(ball, 1);

    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level4::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);


    return true;
}


bool level4::touche(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("x = %f ,y = %f", touch->getLocation().x, touch->getLocation().y);
    int a, b, c, d, e, f;

    a = ball->getPosition().x;
    b = ball->getPosition().y;
    float x = touch->getLocation().x;
    float y = touch->getLocation().y;
    float Xa = ball->getPosition().x;
    float Yb = ball->getPosition().y;
    CCLOG("Xa = %f Xb = %f", Xa, Yb);
    if (Xa == 285 && Yb == 100)
    {
        if (x <= 255 && x > 208 && y >= 75 && y <= 125)
        {
            a = 230; b = 100;
            c = 298; d = 90;
            e = 195; f = 90;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }

    }

    if (Xa == 230 && Yb == 100)
    {
        if (x <= 309 && x > 259 && y >= 75 && y <= 125)
        {
            a = 285; b = 100;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");

        }
        if (x <= 260 && x > 210 && y >= 130 && y <= 225)
        {
            a = 230; b = 200;
            c = 226; d = 92;
            e = 226; f = 240;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }

    }

    if (Xa == 230 && Yb == 200)
    {
        if (x <= 260 && x > 210 && y >= 81 && y <= 177)
        {
            a = 230; b = 100;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");

        }
        if (x <= 455 && x > 240 && y >= 175 && y <= 225)
        {
            a = 435; b = 200;
            c = 220; d = 200;
            e = 450; f = 200;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 27, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }


    if (Xa == 435 && Yb == 200) {
        if (x <= 389 && x > 206 && y >= 175 && y <= 225)
        {
            a = 230; b = 200;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 454 && x > 408 && y >= 232 && y <= 325) {
            a = 430; b = 300;
            c = 435; d = 211;
            e = 435; f = 344;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 30, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }
    if (Xa == 430 && Yb == 300) {
        if (x <= 457 && x > 407 && y >= 175 && y <= 270)
        {
            a = 435; b = 200;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 400 && x > 307 && y >= 276 && y <= 325) {
            a = 330; b = 300;
            c = 470; d = 300;
            e = 297; f = 300;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 30, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }
    if (Xa == 330 && Yb == 300) {
        if (x <= 456 && x > 355 && y >= 276 && y <= 325)
        {
            a = 430; b = 300;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 355 && x > 305 && y >= 127 && y <= 270) {
            a = 332; b = 149;
            c = 330; d = 300;
            e = 330; f = 130;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);

            auto jump = JumpBy::create(10, Vec2(0, 0), 20, 15);
            auto jumpforever = RepeatForever::create(jump);
            ball->runAction(jumpforever);

            auto visibleSize3 = Director::getInstance()->getVisibleSize();
            Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
            auto menu_item_3 = MenuItemImage::create("next.png", "nextselected.png", CC_CALLBACK_1(level4::next, this));
            menu_item_3->setPosition(Vec2(visibleSize3.width / 2, (visibleSize3.height / 2.5) * 2));
            auto* menu1 = Menu::create(menu_item_3, NULL);
            menu1->setPosition(Vec2(0, 0));
            this->addChild(menu1, 1.5);
        }
    }




    auto moveto = MoveTo::create(0.10, Vec2(a, b));
    ball->runAction(moveto);
    return true;
}

void level4::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = level5::createScene();
    Director::getInstance()->pushScene(scene);

}

void level4::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level4::createScene();
    Director::getInstance()->pushScene(scene);
}

void level4::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}