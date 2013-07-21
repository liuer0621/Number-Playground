//
//  GameSprite.cpp
//  Number Playground
//
//  Created by Lana Sun on 6/28/13.
//
//

#include "GameSprite.h"

GameSprite* GameSprite::createWithFrameName(const char * pszSpriteFrameName)
{
    GameSprite * sprite = new GameSprite();
    if (sprite && sprite->initWithSpriteFrameName(pszSpriteFrameName))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}