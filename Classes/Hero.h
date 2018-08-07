#pragma once

#include "cocos2d.h"  

USING_NS_CC;

class Hero : public Sprite
{
private:
	Size size;
public:
	//创建create方法，自动调用init和返回Hero类  
	virtual bool init();
	CREATE_FUNC(Hero);
};