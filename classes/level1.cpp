#include "methodes.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* level1::createScene()
{
    return level1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool level1::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize1 = Director::getInstance()->getVisibleSize();
    Vec2 origin1 = Director::getInstance()->getVisibleOrigin();

    //arriere plan niveau 1
    auto sprite = Sprite::create("level1.png");
    if (sprite == nullptr)
    {
        problemLoading("'level1.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize1.width / 2 + origin1.x, visibleSize1.height / 2 + origin1.y));
        this->addChild(sprite, -1);
    }

    //terrain du niveau 1
    black = Sprite::create("level1sprite.png");
    black->setPosition(Vec2(visibleSize1.width / 2 + origin1.x, visibleSize1.height / 2.3 + origin1.y));
    black->setScale(1);
    this->addChild(black,1);
    
    //ball
    ball = Sprite::create("ball.png");
    ball->setPosition(Vec2(270, 110));
    ball->setScale(1);
    this->addChild(ball,1);

    
    //boutton pour recommencer le niveau
    auto visibleSize3 = Director::getInstance()->getVisibleSize();
    Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_2 = MenuItemImage::create("retry.png", "retryselected.png", CC_CALLBACK_1(level1::retry, this));
    menu_item_2->setPosition(Vec2(visibleSize3.width / 7, (visibleSize3.height / 2.1) * 2));
    auto* menu1 = Menu::create(menu_item_2, NULL);
    menu1->setPosition(Vec2(0, 0));
    this->addChild(menu1, 1.5);

    //boutton pour aller vers la page home
    auto visibleSize4 = Director::getInstance()->getVisibleSize();
    Vec2 origin4 = Director::getInstance()->getVisibleOrigin();
    auto menu_item_3 = MenuItemImage::create("home.png", "homeselected.png", CC_CALLBACK_1(level1::gohome, this));
    menu_item_3->setPosition(Vec2(visibleSize4.width / 20, (visibleSize4.height / 2.1) * 2));
    auto* menu2 = Menu::create(menu_item_3, NULL);
    menu2->setPosition(Vec2(0, 0));
    this->addChild(menu2, 1.5);
    
    //click avec souris 
    auto Listener = EventListenerTouchOneByOne::create();
    Listener->setSwallowTouches(true);
    Listener->onTouchBegan = CC_CALLBACK_2(level1::touche, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);

    return true;
}
//definition de la fonction touche avec toytes les condition selon la position de la balle
bool level1::touche(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("x = %f ,y = %f", touch->getLocation().x, touch->getLocation().y);
    int a,b,c,d,e,f;

    //pour localiser la balle avec un clic
    a = ball->getPosition().x;
    b = ball->getPosition().y;
    float x = touch->getLocation().x;
    float y = touch->getLocation().y;
    float Xa = ball->getPosition().x;
    float Yb = ball->getPosition().y;
    CCLOG("Xa = %f Xb = %f", Xa, Yb);

    //conditions
    if (Xa == 270 && Yb == 110)//position de la balle
    {
        if (x <= 395 && x > 300 && y >= 84 && y <= 135)//position du clic
        {
            a = 370; b = 110; //position suivante de la balle

            //les positions pour peindre le chemin de la balle
            c = 235; d = 100;
            e = 400; f = 100;

            //effect sonor lors la ball touche le mur
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");

            //peindre le chemin
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        
        }   
    }
    if (Xa == 370 && Yb == 110)
    {
        if (x <= 335 && x > 245 && y >= 84 && y <= 135)
        {
            a = 270;
            b = 110;
            c = 235; d = 100;
            e = 400; f = 100;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
          
        }
        if (x <= 395 && x > 345 && y >= 140 && y <= 285)
        {
            a = 370;
            b = 260;
            c = 378; d = 80;
            e = 378; f = 290;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
        
    }
    if (Xa == 370 && Yb == 260)
    {
        if (x <= 395 && x > 345 && y >= 84 && y <= 230)
        {
            a = 370;
            b = 110;
            c = 378; d = 80;
            e = 378; f = 290;
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");
            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);
        }
        if (x <= 340 && x > 245 && y >= 235 && y <= 285)
        {
            a = 270;
            b = 260;
            c = 235; d = 260;
            e = 400; f = 260;

            draw = DrawNode::create();
            draw->drawSegment(Vec2(c, d), Vec2(e, f), 35, Color4F::BLUE);
            this->addChild(draw, -0.5);

            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("colision.mp3");

            //effet sonor de rebondissement
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bounce.mp3");

            //effet de rebondissement
            auto jump = JumpBy::create(10, Vec2(0, 0), 20, 15);
            auto jumpforever = RepeatForever::create(jump);
            ball->runAction(jumpforever);

            //afficher le bouton pour passer au niveau suivant
            auto visibleSize3 = Director::getInstance()->getVisibleSize();
            Vec2 origin3 = Director::getInstance()->getVisibleOrigin();
            auto menu_item_2 = MenuItemImage::create("next.png", "nextselected.png", CC_CALLBACK_1(level1::next, this));
            menu_item_2->setPosition(Vec2(visibleSize3.width / 2, (visibleSize3.height / 2.5) * 2));
            auto* menu1 = Menu::create(menu_item_2, NULL);
            menu1->setPosition(Vec2(0, 0));
            this->addChild(menu1,1.5);
        }
    }
    //pour bouger la balle
    auto moveto = MoveTo::create(0.10, Vec2(a, b));
    ball->runAction(moveto);
    return true;
}

//fonction pour passer au niveau suivant
void level1::next(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("next");
    auto scene = level2::createScene();
    Director::getInstance()->pushScene(scene);
}
//fonction pour ressayer le niveau
void level1::retry(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("retry");
    auto scene = level1::createScene();
    Director::getInstance()->pushScene(scene);
}
//fonction pour aller au menu 
void level1::gohome(cocos2d::Ref* pSender) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
    CCLOG("home");
    auto scene = HelloWorld::createScene();
    Director::getInstance()->pushScene(scene);
}

