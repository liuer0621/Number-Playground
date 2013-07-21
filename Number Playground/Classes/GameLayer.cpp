#include "GameLayer.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    //get screen size
    _screenSize = CCDirector::sharedDirector()->getWinSize();
    
    _running = false;
    
    //create game screen
    createGameScreen();
    
    //create number blocks
    createNumberBlocks();
    
    //init number animation
    this->schedule(schedule_selector(GameLayer::updateGame));
    
//    setTouchEnabled(true);
    
    return true;
}

void GameLayer::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameLayer::createGameScreen()
{
    //add bg
    CCSprite * bg = CCSprite::create("bg_small.png");
    bg->setPosition(ccp(_screenSize.width*0.5f,_screenSize.height*0.5f));
    this->addChild(bg,kBackground);
    
}


void GameLayer::createNumberBlocks()
{
    //create the number sprites
    
    //add number blocks
    _numbers = CCArray::createWithCapacity(10);
    _visibleNumbers = CCArray::createWithCapacity(10);
    _visibleNumbers->retain();
    _numbers->retain();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("number_sheet.plist");
    _gameBatchNode = CCSpriteBatchNode::create("number_sheet.png", 50);
    this->addChild(_gameBatchNode, kMiddleground);
    
    //the total number of blocks
    int digitCnt = 10;
    
    for(int i = 0; i < digitCnt; i++)
    {
        Number * numberBlock;
        
        numberBlock = Number::create(i, ccp(_screenSize.width*(i*0.1), _screenSize.height));
        _gameBatchNode->addChild(numberBlock,kMiddleground);
        _numbers->addObject(numberBlock);
    }
    
    //ready to create block sprite
}

void GameLayer::updateGame(float dt)
{
    if(_visibleNumbers->count() == 0)
    {
        //update state , decide if it's visible or not
        int count = 2;
        for (int i = 0; i < count; i++ )
        {
            int randNumber = rand()%_numbers->count();
            Number * visibleNumber;
            visibleNumber = (Number *)_numbers->objectAtIndex(randNumber);
            _visibleNumbers->addObject(visibleNumber);
        }
    }
    
    //updated visible numbers, next step is to update the position
    for (int i = 0; i < _visibleNumbers->count(); i++)
    {
        Number * singleNumber;
        singleNumber = (Number *)_visibleNumbers->objectAtIndex(i);
        singleNumber->setPositionY(singleNumber->getPositionY() - dt*10);
    }

    //check if it reaches the bottom of the screen
    for (int i = 0; i < _visibleNumbers->count(); i++)
    {
        Number * singleNumber;
        singleNumber = (Number *)_visibleNumbers->objectAtIndex(i);
        if (singleNumber->getPositionY() <= 0)
        {
            _visibleNumbers->removeObjectAtIndex(i);
            _visibleNumbers->removeObjectsInArray();
        }
    }
}