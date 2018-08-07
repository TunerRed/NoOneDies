#include "GameStageScene.h"
#include "MainMenu.h"


Scene* GameStageScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = GameStageScene::create();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
bool GameStageScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);
	Size size = Director::getInstance()->getVisibleSize();
	LabelTTF* label[5];
	std::string s[5] = {"1","2","3","4","5"};
	EventListenerTouchOneByOne* listener[5];
	for (int i = 0; i < 5; i++) 
	{
		label[i] = LabelTTF::create();
		label[i]->setString(s[i]);
		label[i]->setFontFillColor(Color3B::BLACK);
		label[i]->setFontSize(30);
		label[i]->setAnchorPoint(Point(0,0));
		listener[i] = EventListenerTouchOneByOne::create();
		listener[i]->onTouchBegan = [i](Touch* t,Event* e)
		{
			if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()))
			{
				//MainMenu::setSingleCounts(3);
				Director::getInstance()->replaceScene(TransitionFlipAngular::create(1,HelloWorld::createScene(i + 1)));
			}
			return false;
		};
		Director::getInstance()->getEventDispatcher()
			->addEventListenerWithSceneGraphPriority(listener[i],label[i]);
		label[i]->setPosition(size.width/2,size.height-((size.height/5)*(i+1))+100);
		addChild(label[i]);
	}
	return true;
}