#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level6::createScene()
{
    return level6::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level6::init()
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
    auto sprite = Sprite::create("level6.png");
    if (sprite == nullptr)
    {
        problemLoading("'level6.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);
    }

    //terrain
    black = Sprite::create("level6sprite.png");
    black->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2.4 + origin2.y));
    black->setScale(1);
    this->addChild(black, 1);

    //retry
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level6::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    //home
    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level6::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);

    //la balle
    ball = Sprite::create("ball2.png");
    ball->setPosition(Vec2(167, 335));
    ball->setScale(1);
    this->addChild(ball, 1);

    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level6::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);


    return true;
}

//conditions 
int c1, c2, c3, c4, c5, c6, c7, c8, c9;
bool level6::touche(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("x = %f ,y = %f", touch->getLocation().x, touch->getLocation().y);
    int a, b, c, d, e, f;
    c = 0; d = 0;
    e = 0; f = 0;
    a = ball->getPosition().x;
    b = ball->getPosition().y;
    float x = touch->getLocation().x;
    float y = touch->getLocation().y;
    float Xa = ball->getPosition().x;
    float Yb = ball->getPosition().y;
    CCLOG("Xa = %f Xb = %f", Xa, Yb);
    if (Xa == 167 && Yb == 335)
    {
        if (x <= 189 && x > 142 && y >= 48 && y <= 313)
        {
            a = 167; b = 71;
            c = 167; d = 360;
            e = 167; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 167 && Yb == 71)
    {
        if (x <= 189 && x > 142 && y >= 97 && y <= 360)
        {
            a = 167; b = 335;
            c = 167; d = 48;
            e = 167; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 364 && x > 189 && y >= 48 && y <= 97)
        {
            a = 342; b = 71;
            c = 142; d = 71;
            e = 364; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 342 && Yb == 71)
    {
        if (x <= 319 && x > 142 && y >= 48 && y <= 97)
        {
            a = 167; b = 71;
            c = 364; d = 71;
            e = 142; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 364 && x > 319 && y >= 97 && y <= 360)
        {
            a = 342; b = 335;
            c = 342; d = 48;
            e = 342; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 342 && Yb == 335) {
        if (x <= 364 && x > 319 && y >= 48 && y <= 313)
        {
            a = 342; b = 71;
            c = 342; d = 360;
            e = 342; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 319 && x > 231 && y >= 313 && y <= 360) {
            a = 253; b = 335;
            c = 364; d = 334;
            e = 231; f = 334;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------- - */

    if (Xa == 253 && Yb == 335)
    {
        if (x <= 364 && x > 274 && y >= 313 && y <= 360)
        {
            a = 342; b = 335;
            c = 231; d = 334;
            e = 364; f = 334;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 274 && x > 231 && y >= 137 && y <= 313)
        {
            a = 253; b = 159;
            c = 254; d = 360;
            e = 254; f = 137;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 253 && Yb == 159)
    {
        if (x <= 274 && x > 231 && y >= 179 && y <= 360)
        {
            a = 253; b = 335;
            c = 253; d = 137;
            e = 253; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 451 && x > 274 && y >= 137 && y <= 179)
        {
            a = 428; b = 159;
            c = 231; d = 159;
            e = 451; f = 159;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 428 && Yb == 159)
    {
        if (x <= 405 && x > 231 && y >= 137 && y <= 179)
        {
            a = 253; b = 159;
            c = 452; d = 159;
            e = 231; f = 159;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 405 && y >= 48 && y <= 137)
        {
            a = 428; b = 71;
            c = 428; d = 137;
            e = 428; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 405 && y >= 179 && y <= 313)
        {
            a = 428; b = 292;
            c = 429; d = 179;
            e = 429; f = 313;
            c1 = 1; c2 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 428 && Yb == 71)
    {
        if (x <= 497 && x > 451 && y >= 48 && y <= 97)
        {
            a = 473; b = 71;
            c = 405; d = 71;
            e = 497; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 405 && y >= 97 && y <= 313)
        {
            a = 428; b = 292;
            c = 428; d = 48;
            e = 428; f = 313;
            c1 = 1; c2 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 473 && Yb == 71)
    {
        if (x <= 452 && x > 405 && y >= 48 && y <= 97)
        {
            a = 428; b = 71;
            c = 497; d = 71;
            e = 405; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 452 && y >= 97 && y <= 137)
        {
            a = 473; b = 117;
            c = 472; d = 48;
            e = 472; f = 137;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 473 && Yb == 117)
    {
        if (x <= 497 && x > 452 && y >= 48 && y <= 97)
        {
            a = 473; b = 71;
            c = 472; d = 137;
            e = 472; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 274 && y >= 97 && y <= 137)
        {
            a = 296; b = 117;
            c = 497; d = 115;
            e = 274; f = 115;
            c6 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 296 && Yb == 117)
    {
        if (x <= 319 && x > 274 && y >= 48 && y <= 97)
        {
            a = 296; b = 71;
            c = 296; d = 97;
            e = 296; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 319 && x > 274 && y >= 137 && y <= 271)
        {
            a = 296; b = 249;
            c = 298; d = 97;
            e = 298; f = 271;
            c7 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 319 && y >= 97 && y <= 137)
        {
            a = 473; b = 117;
            c = 274; d = 117;
            e = 497; f = 117;
            c6 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 296 && Yb == 71)
    {
        if (x <= 364 && x > 319 && y >= 48 && y <= 97)
        {
            a = 342; b = 71;
            c = 274; d = 71;
            e = 364; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 319 && x > 274 && y >= 97 && y <= 271)
        {
            a = 296; b = 249;
            c = 298; d = 48;
            e = 298; f = 271;
            c7 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 274 && x > 142 && y >= 48 && y <= 97)
        {
            a = 167; b = 71;
            c = 296; d = 71;
            e = 142; f = 71;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 296 && Yb == 249)
    {
        if (x <= 319 && x > 274 && y >= 48 && y <= 227)
        {
            a = 296; b = 71;
            c = 296; d = 271;
            e = 296; f = 48;
            c7 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 319 && y >= 227 && y <= 271)
        {
            a = 473; b = 249;
            c = 274; d = 247;
            e = 497; f = 247;
            c1 = 1; c3 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 274 && x > 231 && y >= 227 && y <= 271)
        {
            a = 253; b = 249;
            c = 319; d = 247;
            e = 231; f = 247;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 253 && Yb == 249)
    {
        if (x <= 274 && x > 231 && y >= 271 && y <= 360)
        {
            a = 253; b = 335;
            c = 254; d = 327;
            e = 254; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 274 && x > 231 && y >= 137 && y <= 227)
        {
            a = 253; b = 159;
            c = 254; d = 271;
            e = 254; f = 137;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 274 && y >= 227 && y <= 271)
        {
            a = 473; b = 249;
            c = 231; d = 247;
            e = 497; f = 247;
            c1 = 1; c3 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 473 && Yb == 249)
    {
        if (x <= 497 && x > 452 && y >= 271 && y <= 313)
        {
            a = 473; b = 292;
            c = 473; d = 271;
            e = 473; f = 313;
            c9 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 452 && y >= 179 && y <= 227)
        {
            a = 473; b = 203;
            c = 473; d = 227;
            e = 473; f = 179;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 231 && y >= 227 && y <= 271)
        {
            a = 253; b = 249;
            c = 497; d = 249;
            e = 231; f = 249;
            c1 = 1; c3 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 473 && Yb == 203)
    {
        if (x <= 497 && x > 452 && y >= 227 && y <= 313)
        {
            a = 473; b = 292;
            c = 473; d = 179;
            e = 473; f = 313;
            c9 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 142 && y >= 179 && y <= 227)
        {
            a = 167; b = 203;
            c = 497; d = 203;
            e = 142; f = 203;
            c2 = 1; c4 = 1; c7 = 1; c8 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 167 && Yb == 203)
    {
        if (x <= 189 && x > 142 && y >= 227 && y <= 360)
        {
            a = 167; b = 335;
            c = 167; d = 227;
            e = 167; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 189 && x > 142 && y >= 48 && y <= 179)
        {
            a = 167; b = 71;
            c = 167; d = 179;
            e = 167; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 189 && y >= 179 && y <= 227)
        {
            a = 473; b = 203;
            c = 142; d = 203;
            e = 497; f = 203;
            c2 = 1; c4 = 1; c7 = 1; c8 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 473 && Yb == 292)
    {
        if (x <= 497 && x > 452 && y >= 179 && y <= 271)
        {
            a = 473; b = 203;
            c = 473; d = 313;
            e = 473; f = 179;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 319 && y >= 271 && y <= 313)
        {
            a = 342; b = 292;
            c = 497; d = 291;
            e = 319; f = 291;
            c5 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 428 && Yb == 292)
    {
        if (x <= 405 && x > 319 && y >= 271 && y <= 313)
        {
            a = 342; b = 292;
            c = 405; d = 291;
            e = 319; f = 291;
            c5 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 452 && y >= 271 && y <= 313)
        {
            a = 473; b = 292;
            c = 452; d = 292;
            e = 497; f = 292;
            c9 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 452 && x > 405 && y >= 48 && y <= 271)
        {
            a = 428; b = 71;
            c = 428; d = 313;
            e = 428; f = 48;
            c1 = 1; c2 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 342 && Yb == 292)
    {
        if (x <= 364 && x > 319 && y >= 313 && y <= 360)
        {
            a = 342; b = 335;
            c = 342; d = 313;
            e = 342; f = 360;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 364 && x > 319 && y >= 48 && y <= 271)
        {
            a = 342; b = 71;
            c = 342; d = 271;
            e = 342; f = 48;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 497 && x > 364 && y >= 271 && y <= 313)
        {
            a = 473; b = 292;
            c = 319; d = 292;
            e = 497; f = 292;
            c5 = 1; c9 = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }

    if (c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1 && c5 == 1 && c6 == 1 && c7 == 1 && c8 == 1 && c9 == 1)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");

        //rebondissement
        auto jump = JumpBy::create(10, Vec2(0, 0), 20, 15);
        auto jumpforever = RepeatForever::create(jump);
        ball->runAction(jumpforever);

        
        auto visibleSize3 = Director::getInstance()->getVisibleSize();
        Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
        
        //afficher le boutton pour passer a credits
        auto menu_item_3 = MenuItemImage::create("tocredit.png", "tocreditselected.png", CC_CALLBACK_1(level6::next, this));
        menu_item_3->setPosition(Vec2(visibleSize3.width / 2, (visibleSize3.height / 2.5) * 2));
        auto* menu1 = Menu::create(menu_item_3, NULL);
        menu1->setPosition(Vec2(0, 0));
        this->addChild(menu1,1.5);

        //remetre les variables a 0 pour ne pas avoir de problems en rejouant le niveau
        c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
 
    }
    draw = DrawNode::create();
    draw->drawSegment(Vec2(c, d), Vec2(e, f), 22, Color4F::RED);
    this->addChild(draw, -0.5);
    auto moveto = MoveTo::create(0.10, Vec2(a, b));
    ball->runAction(moveto);
    return true;
}
 
//passer a credits
void level6::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = credit::createScene();
    Director::getInstance()->pushScene(scene);

}

// fonction pour rejouer le niveau
void level6::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level6::createScene();
    Director::getInstance()->pushScene(scene);
    c1-0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0;

}

//fonction pour retourner a home
void level6::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}