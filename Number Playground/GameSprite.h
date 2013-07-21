//
//  GameSprite.h
//  Number Playground
//
//  Created by Lana Sun on 6/28/13.
//
//

#ifndef Number_Playground_GameSprite_h
#define Number_Playground_GameSprite_h

#include "cocos2d.h"

using namespace cocos2d;

class GameSprite : public CCSprite
{
public:
    
    static GameSprite* createWithFrameName(const char *pszSpriteFrameName);
};

#endif
