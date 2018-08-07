#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Block :public Sprite
{
private:
	int width, heigth;
public:
	CREATE_FUNC(Block);
	virtual bool init();
	virtual void update(float dt);
};

