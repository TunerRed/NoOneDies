#pragma once
#include "cocos2d.h"
#include "Edge.h"
#include "Block.h"
#include "Hero.h"
USING_NS_CC;

class SingleScene:public Ref
{
private:
	Size size;
	Edge* edge;
	Hero* hero;
	//HelloWorld Layer
	Layer* layer;
	//Whether the hero is jumping
	//Whether the hero is adjusting its position after jumping
	bool isJumping,isAdjusting;
	//The Vertical position of panel
	//the proper horizital position of hero
	float positionY,heroPositionX;
	//record the time of the blocks producing
	int currentTime, timeLimit;
public:
	SingleScene();
	~SingleScene();
	static SingleScene* create(Layer* layer, int positionY);
	virtual bool init(Layer* layer, int positionY);
	void update();
	bool containPoint(Vec2 p);
	void jump();
	void setAdjusting(bool adjusting);
};

