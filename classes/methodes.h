#ifndef  _NEW_SCENE1_H_
#define  _NEW_SCENE1_H_
#include "cocos2d.h"
#include "cocos/editor-support/cocostudio/SimpleAudioEngine.h"


class cre : public cocos2d::Scene {
public:
 cocos2d::Sprite* ball;
 cocos2d::Sprite* black;
 cocos2d::DrawNode* draw;
};

class level1 : public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level1);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);
};
class level2 : public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level2);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);
    

};
class level3 : public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level3);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);
};

class level4 : public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level4);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);
 

};
class level5 : public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level5);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);

};
class level6 :public cre
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(level6);
    void retry(Ref* pSender);
    void next(Ref* pSender);
    void gohome(Ref* pSender);
    bool touche(cocos2d::Touch* touch, cocos2d::Event* event);

};

class credit : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(credit);
};

class lobby : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(lobby);
    void level1(Ref* pSender);
    void level2(Ref* pSender);
    void level3(Ref* pSender);
    void level4(Ref* pSender);
    void level5(Ref* pSender);
    void level6(Ref* pSender);
};

#endif // _NEW_SCENE1_H_
