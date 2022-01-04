#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level2::createScene()
{
    return level2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level2::init()
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
    auto sprite = Sprite::create("level2.png");
    if (sprite == nullptr)
    {
        problemLoading("'level2.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);
    }

    //terrain
    black = Sprite::create("level2sprite.png");
    black->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2.4 + origin2.y));
    black->setScale(1);
    this->addChild(black, 1);
   
    //boutton retry
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level2::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    //boutton home
    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level2::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);

    //balle
    ball = Sprite::create("ball.png");
    ball->setPosition(Vec2(270, 101));
    ball->setScale(1);
    this->addChild(ball,1);

    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level2::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);

    return true;
}


bool level2::touche(cocos2d::Touch* touch, cocos2d::Event* event)
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
    if (Xa == 270 && Yb == 101)
    {
        if (x <= 395 && x > 300 && y >= 75 && y <= 125)
        {
            a = 370; b = 101;
            c = 235; d = 90;
            e = 400; f = 90;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
    }

    if (Xa == 370 && Yb == 101)
    {
        if (x <= 335 && x > 245 && y >= 75 && y <= 125)
        {
            a = 270;b = 101;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
           
        }
        if (x <= 395 && x > 345 && y >= 130 && y <= 225)
        {
            a = 370; b = 200;
            c = 380; d = 101;
            e = 380; f = 230;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
    }

    if (Xa == 370 && Yb == 200)
    {
        if (x <= 395 && x > 345 && y >= 75 && y <= 180)
        {
            a = 370; b = 101;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 335 && x > 245 && y >= 175 && y <= 225)
        {
            a = 270; b = 200;
            c = 395; d = 190;
            e = 245; f = 190;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
    }

    if (Xa == 270 && Yb == 200) {
        if (x <= 395 && x > 300 && y >= 175 && y <= 225)
        {
            a = 370; b = 200;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 295 && x > 245 && y >= 235 && y <= 325) {
            a = 270; b = 300;
            c = 260; d = 175;
            e = 260; f = 340;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
    }

    if (Xa == 270 && Yb == 300) {
        if (x <= 295 && x > 245 && y >= 175 && y <= 270)
        {
            a = 270; b = 200;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 395 && x > 300 && y >= 275 && y <= 325) {
            a = 370; b = 300;
            c = 245; d = 300;
            e = 400; f = 300;
            //sound effects
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");
            //peindre
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
            //rebondissement
            auto jump = JumpBy::create(10, Vec2(0, 0), 20, 15);
            auto jumpforever = RepeatForever::create(jump);
            ball->runAction(jumpforever);
            //niveau suivant
            auto visibleSize3 = Director::getInstance()->getVisibleSize();
            Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
            auto menu_item_1 = MenuItemImage::create("next.png", "nextselected.png", CC_CALLBACK_1(level2::next, this));
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
void level2::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = level3::createScene();
    Director::getInstance()->pushScene(scene);
}
//retry
void level2::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level2::createScene();
    Director::getInstance()->pushScene(scene);
}
//home
void level2::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}