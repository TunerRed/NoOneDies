#pragma once
#include "cocos2d.h"
USING_NS_CC;

class GameOver:public LayerColor
{
private:
	std::string s[3];
public:
	CREATE_FUNC(GameOver);
	virtual bool init();
	static Scene* createScene();
	void createUTF();
};

