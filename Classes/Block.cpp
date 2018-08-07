#include "Block.h"


bool Block::init()
{
	Sprite::init();

	setTextureRect(Rect(0, 0, CCRANDOM_0_1() * 30 + 10, CCRANDOM_0_1() * 70 + 35));
	setColor(Color3B::BLACK);
	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	getPhysicsBody()->setDynamic(false);
	getPhysicsBody()->setContactTestBitmask(1);

	scheduleUpdate();

	return true;
}

void Block::update(float dt)
{
	setPosition(getPositionX()-3,getPositionY());
	if (getPositionX() < -10)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}