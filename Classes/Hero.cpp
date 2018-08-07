#include "Hero.h"
#include "GameOver.h"
#define SCALE 1


bool Hero::init()
{
	Sprite::initWithFile("ball.png");

	//对图像进行缩小
	size = Size(54*SCALE,54*SCALE);
	//setScale(SCALE);
	setPhysicsBody(PhysicsBody::createCircle(size.height/2));
	//getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setVelocityLimit(500);
	setContentSize(size);

	runAction(RepeatForever::create(RotateBy::create(0.5,360)));

	getPhysicsBody()->setContactTestBitmask(1);
	auto listener1 = EventListenerPhysicsContact::create();
	listener1->onContactBegin = [](PhysicsContact& contact)
	{
			Director::getInstance()->replaceScene(
				TransitionCrossFade::create(0.5f, GameOver::createScene()));
		return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener1, this);

	return true;
}