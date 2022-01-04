#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level5::createScene()
{
    return level5::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level5::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize2 = Director::getInstance()->getVisibleSize();
    Vec2 origin2 = Director::getInstance()->getVisibleOrigin();

    //arriere plan
    auto sprite = Sprite::create("level5.png");
    if (sprite == nullptr)
    {
        problemLoading("'level5.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2 + origin2.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, -1);
    }


    //terrain
    black = Sprite::create("level5sprite.png");
    black->setPosition(Vec2(visibleSize2.width / 2 + origin2.x, visibleSize2.height / 2.4 + origin2.y));
    black->setScale(1);
    this->addChild(black, 1);

    //retry
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level5::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    //home
    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level5::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);

    //la balle
    ball = Sprite::create("ball.png");
    ball->setPosition(Vec2(220, 226));
    ball->setScale(1);
    this->addChild(ball, 1);

    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level5::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);

    return true;
}

//conditions
int i, j, k, l, m, n, p, q;
bool level5::touche(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("x = %f ,y = %f", touch->getLocation().x, touch->getLocation().y);
    int a, b, c, d, e, f;
    c = 220; d = 220;
    e = 220; f = 220;

    a = ball->getPosition().x;
    b = ball->getPosition().y;
    float x = touch->getLocation().x;
    float y = touch->getLocation().y;
    float Xa = ball->getPosition().x;
    float Yb = ball->getPosition().y;
    CCLOG("Xa = %f Xb = %f", Xa, Yb);
    if (Xa == 220 && Yb == 226)
    {
        if (x <= 245 && x > 194 && y >= 149 && y <= 198)
        {
            a = 220; b = 176;
            c = 220; d = 250;
            e = 220; f = 149;
            i = 1; j = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 445 && x > 245 && y >= 198 && y <= 251)
        {
            a = 420; b = 226;
            c = 194; d = 226;
            e = 445; f = 226;
            i = 1; l = 1; m = 1; n = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }

    }
    if (Xa == 220 && Yb == 176)
    {
        if (x <= 245 && x > 194 && y >= 198 && y <= 251)
        {
            a = 220; b = 226;
            c = 220; d = 149;
            e = 220; f = 250;
            j = 1; i = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 296 && x > 245 && y >= 149 && y <= 198)
        {
            a = 270; b = 176;
            c = 194; d = 176;
            e = 296; f = 176;
            j = 1; k = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }

    }
    if (Xa == 270 && Yb == 176)
    {
        if (x <= 296 && x > 245 && y >= 198 && y <= 251)
        {
            a = 270; b = 226;
            c = 270; d = 149;
            e = 270; f = 251;
            k = 1; l = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 245 && x > 194 && y >= 149 && y <= 198)
        {
            a = 220; b = 176;
            c = 296; d = 176;
            e = 194; f = 176;
            k = 1; j = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 270 && Yb == 226) {
        if (x <= 296 && x > 245 && y >= 149 && y <= 198)
        {
            a = 270; b = 176;
            c = 270; d = 149;
            e = 270; f = 251;
            l = 1; k = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 245 && x > 194 && y >= 198 && y <= 251) {
            a = 220; b = 226;
            c = 250; d = 226;
            e = 194; f = 226;
            i = 1; l = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 445 && x > 296 && y >= 198 && y <= 251)
        {
            a = 420; b = 226;
            c = 296; d = 226;
            e = 445; f = 226;
            l = 1; m = 1; n = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }

    }
    if (Xa == 420 && Yb == 226) {
        if (x <= 395 && x > 194 && y >= 198 && y <= 251)
        {
            a = 220; b = 226;
            c = 445; d = 226;
            e = 194; f = 226;
            n = 1; m = 1; l = 1; i = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 445 && x > 395 && y >= 149 && y <= 198) {
            a = 420; b = 176;
            c = 421; d = 251;
            e = 421; f = 149;
            n = 1; p = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 420 && Yb == 176)
    {
        if (x <= 445 && x > 395 && y >= 198 && y <= 251)
        {
            a = 420; b = 226;
            c = 420; d = 149;
            e = 420; f = 251;
            p = 1; n = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 395 && x > 345 && y >= 149 && y <= 198)
        {
            a = 370; b = 176;
            c = 445; d = 176;
            e = 345; f = 176;
            p = 1; q = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 370 && Yb == 176)
    {
        if (x <= 445 && x > 395 && y >= 149 && y <= 198)
        {
            a = 420; b = 176;
            c = 345; d = 176;
            e = 445; f = 176;
            q = 1; p = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 395 && x > 345 && y >= 198 && y <= 251)
        {
            a = 370; b = 226;
            c = 370; d = 149;
            e = 371; f = 251;
            q = 1; m = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
    }
    if (Xa == 370 && Yb == 226) {
        if (x <= 395 && x > 345 && y >= 149 && y <= 198)
        {
            a = 370; b = 176;
            c = 370; d = 251;
            e = 370; f = 149;
            m = 1; q = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 345 && x > 194 && y >= 198 && y <= 251) {
            a = 220; b = 226;
            c = 395; d = 226;
            e = 194; f = 226;
            m = 1; l = 1; i = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }
        if (x <= 445 && x > 395 && y >= 198 && y <= 251)
        {
            a = 420; b = 226;
            c = 345; d = 226;
            e = 445; f = 226;
            m = 1; n = 1;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
        }

    }
    //peindre le terrain
    draw = DrawNode::create();
    draw->drawSegment(Vec2(c, d), Vec2(e, f), 25, Color4F::BLUE);
    this->addChild(draw, -0.5);

    //bouger la balle
    auto moveto = MoveTo::create(0.10, Vec2(a, b));
    ball->runAction(moveto);

    //condition pour terminer le niveaux
    if (i == 1 && j == 1 && k == 1 && l == 1 && m == 1 && n == 1 && p == 1 && q == 1)
    { 
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");
        
        auto jump = JumpBy::create(10, Vec2(0, 0), 20, 15);
        auto jumpforever = RepeatForever::create(jump);
        ball->runAction(jumpforever);

        //niveau suivant
        auto visibleSize3 = Director::getInstance()->getVisibleSize();
        Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
        auto menu_item_3 = MenuItemImage::create("next.png", "nextselected.png", CC_CALLBACK_1(level5::next, this));
        menu_item_3->setPosition(Vec2(visibleSize3.width / 2, (visibleSize3.height / 2.5) * 2));
        auto* menu1 = Menu::create(menu_item_3, NULL);
        menu1->setPosition(Vec2(0, 0));
        this->addChild(menu1, 1.5);

        //remmetre a 0
        i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, p = 0, q = 0;
    }
    return true;
} 
//niveau suivant
void level5::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = level6::createScene();
    Director::getInstance()->pushScene(scene);

}
//retry
void level5::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level5::createScene();
    Director::getInstance()->pushScene(scene);
    i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, p = 0, q = 0;
}

//home
void level5::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}