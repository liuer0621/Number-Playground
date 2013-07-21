#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "cocos2d.h"
#include "Number.h"

using namespace cocos2d;

class Number;

enum
{
    kBackground,
    kMiddleground,
    kForeground
};

class GameLayer : public CCLayer
{
private:
    CCSize _screenSize;
    bool _running;
    
    void createGameScreen(void);
    void createNumberBlocks(void);
    void updateGame(float dt);
    
    //all the numbers stored in one array, individual one is one numberBlock
    CCArray * _numbers;
    
    //record all the visible number blocks
    CCArray * _visibleNumbers;
    
    CCSpriteBatchNode * _gameBatchNode;
    
    
    //the total amount of number blocks
    int _totalCount = 10;
    
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
};

#endif // __HELLOWORLD_SCENE_H__
