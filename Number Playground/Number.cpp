//
//  Number.cpp
//  Number Playground
//
//  Created by Lana Sun on 6/28/13.
//
//

#include "Number.h"

Number::~Number(){}

Number::Number(int digit, CCPoint position)
{
    _digit = digit;
    _startPosition = position;
}

Number* Number::create(int digit, CCPoint position)
{
    Number * sprite = new Number(digit, position);
    if (sprite)
    {
        sprite->initNumber();
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

void Number::initNumber()
{
    //set sprite texture
    switch (_digit)
    {
        case kNumberOne:
            this->initWithSpriteFrameName("one.png");
            break;
        case kNumberTwo:
            this->initWithSpriteFrameName("two.png");
            break;
        case kNumberThree:
            this->initWithSpriteFrameName("three.png");
            break;
        case kNumberFour:
            this->initWithSpriteFrameName("four.png");
            break;
        case kNumberFive:
            this->initWithSpriteFrameName("five.png");
            break;
        case kNumberSix:
            this->initWithSpriteFrameName("six.png");
            break;
        case kNumberSeven:
            this->initWithSpriteFrameName("seven.png");
            break;
        case kNumberEight:
            this->initWithSpriteFrameName("eight.png");
            break;
        case kNumberNine:
            this->initWithSpriteFrameName("nine.png");
            break;
        case kNumberZero:
            this->initWithSpriteFrameName("zero.png");
            break;
    }
    
    setPosition(_startPosition);
    //setVisible(false);
}

void Number::reset()
{
    setPosition(_startPosition);
    setVisible(true);
}

void Number::update(float dt)
{
    if (isVisible())
    {
        CCPoint position = this->getPosition();
        printf("position is %f %f",position.x,position.y);
        
        position.x += dt * PTM_RATIO;
        position.y += dt * PTM_RATIO;
    
        this->setPosition(position);
    }
    
}