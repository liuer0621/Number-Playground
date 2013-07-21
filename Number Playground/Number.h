//
//  Number.h
//  Number Playground
//
//  Created by Lana Sun on 6/28/13.
//
//

#ifndef Number_Playground_Number_h
#define Number_Playground_Number_h

#define PTM_RATIO 32.0

#include "cocos2d.h"
#include "GameLayer.h"
#include "GameSprite.h"

using namespace cocos2d;

enum  {
    kNumberOne = 1,
    kNumberTwo = 2,
    kNumberThree = 3,
    kNumberFour = 4,
    kNumberFive = 5,
    kNumberSix = 6,
    kNumberSeven = 7,
    kNumberEight = 8,
    kNumberNine = 9,
    kNumberZero = 0
    };

class Number : public GameSprite
{
private:
    int _digit;
    
    void initNumber();
    CCPoint _startPosition;

    
public:
    
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    CC_SYNTHESIZE(CCPoint, _speed, Speed);
    
    Number(int digit, CCPoint position);
    ~Number();
    
    static Number* create(int digit, CCPoint position);
    
    virtual void update(float dt);
    
    virtual void reset(void);
    
};



#endif
