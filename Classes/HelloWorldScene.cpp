#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameOver.h"

USING_NS_CC;

using namespace cocostudio::timeline;

HelloWorld* HelloWorld::create(int stages)
{
	HelloWorld *pRet = new HelloWorld();
	pRet->init(stages);
	pRet->autorelease(); 
	return pRet;
}

Scene* HelloWorld::createScene(int stages)
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create(stages);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init(int stages)
{
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
	size = Director::getInstance()->getVisibleSize();

	for (int i = 0; i < stages; i++)
	{
		ss.insert(0, SingleScene::create( this, 10 + i * ( size.height / stages) ) );
	}


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* t, Event* e)
	{
		for (auto s = ss.begin(); s != ss.end(); s++)
		{
			if ((*s)->containPoint(t->getLocation()))
			{
				
				log("get!!!!!!");
				(*s)->jump();
				break;
			}
		}
		
		return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

    return true;
}

void HelloWorld::update(float dt)
{
	for (auto s = ss.begin(); s != ss.end(); s++)
	{
		(*s)->update();
	}
	
}
