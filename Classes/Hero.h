#pragma once

#include "cocos2d.h"  

USING_NS_CC;

class Hero : public Sprite
{
private:
	Size size;
public:
	//����create�������Զ�����init�ͷ���Hero��  
	virtual bool init();
	CREATE_FUNC(Hero);
};