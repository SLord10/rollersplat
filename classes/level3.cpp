#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level3::createScene()
{
    return level3::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level3::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize2 = Director::getInstance()->getVisibleSize();
    Vec2 origin2 = Director::getInstance()->getVisibleOrigin();

    //arriere plan
    auto sprite = Sprite::create("level3.png");
    if (sprite == nullptr)
    {
        problemLoading("'level3.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);

    }

    //terrain
    black = Sprite::create("level3sprite.png");
    black->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2.4 + origin2.y));
    black->setScale(1);
    this->addChild(black, 1);

    //retry
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level3::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    //home
    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level3::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);

    //la balle
    ball = Sprite::create("ball.png");
    ball->setPosition(Vec2(222, 108));
    ball->setScale(1);
    this->addChild(ball, 1);

    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level3::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);

    return true;
}

//conditions
bool level3::touche(cocos2d::Touch* touch, cocos2d::Event* event)
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
    if (Xa == 222 && Yb == 108)
    { 
        if (x <= 248 && x > 197 && y >= 135 && y <= 334)
        {
            a = 220; b = 310;
            c = 214; d = 92;
            e = 214; f = 325;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }

    }
    if (Xa == 220 && Yb == 310)
    {   
        if (x <= 248 && x > 197 && y >= 83 && y <= 284)
        {
            a = 222; b = 108;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
       
        if (x <= 448 && x > 260 && y >= 282 && y <= 335)
        {
            a = 422; b = 307;
            c = 218; d = 311;
            e = 463; f = 311;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }
 
    if (Xa == 422 && Yb == 307)
    {
        if (x <= 395 && x > 195 && y >= 282 && y <= 335)
        {
            a = 220; b = 310;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");

        }
        if (x <= 446 && x > 396 && y >= 83 && y <= 276)
        {
            a = 422; b = 108;
            c = 430; d = 85;
            e = 430; f = 276;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }
   
    if (Xa == 422 && Yb == 108) {
        if (x <= 446 && x > 369 && y >= 135 && y <= 344)
        {
            a = 422; b = 307;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 396 && x > 295 && y >= 83 && y <= 134) {
            a = 320; b = 108;
            c = 424; d = 100;
            e = 270; f = 100;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::RED);
            this->addChild(draw, -0.5);
        }
    }

    if (Xa == 320 && Yb == 108) {
        if (x <= 445 && x > 363 && y >= 83 && y <= 134)
        {
            a = 422; b = 108;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 349 && x > 295 && y >= 134 && y <= 233) {
            a = 320; b = 205;
            c = 320; d = 68;
            e = 320; f = 260;
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
            auto menu_item_1 = MenuItemImage::create("next.png", "nextselected.png", CC_CALLBACK_1(level3::next, this));
            menu_item_1->setPosition(Vec2(visibleSize3.width / 2, (visibleSize3.height / 2.5) * 2));
            auto* menu1 = Menu::create(menu_item_1, NULL);
            menu1->setPosition(Vec2(0, 0));
            this->addChild(menu1, 1.5);
        }
    }

    auto moveto = MoveTo::create(0.10, Vec2(a, b));
    ball->runAction(moveto);
    return true;
}

//next
void level3::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = level4::createScene();
    Director::getInstance()->pushScene(scene);
}

//retry
void level3::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level3::createScene();
    Director::getInstance()->pushScene(scene);
}

//home
void level3::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}