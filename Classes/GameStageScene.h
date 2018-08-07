#pragma once
#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class GameStageScene:public LayerColor
{
public:
	CREATE_FUNC(GameStageScene);

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	bool init();
};

