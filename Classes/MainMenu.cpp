#include "MainMenu.h"
#include "GameStageScene.h"


bool MainMenu::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	Size size = Director::getInstance()->getVisibleSize();
	createUTF();

	auto title = Sprite::create("back.png");
	title->setScale(size.width/(title->getContentSize().width));
	title->setPosition(size.width/2,size.height/2);
	addChild(title);

	auto start = LabelTTF::create();
	start->setString(s[0]);
	start->setFontFillColor(Color3B::GRAY);
	start->setFontSize(50);
	start->setPosition(size.width / 2, (size.height / 8)*3);
	addChild(start);

	auto end = LabelTTF::create();
	end->setString(s[1]);
	end->setFontFillColor(Color3B::GRAY);
	end->setFontSize(50);
	end->setPosition(size.width / 2, size.height / 6);
	addChild(end);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [](Touch* t, Event* e)
	{
		if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->replaceScene(
				TransitionFlipAngular::create(1, GameStageScene::createScene()));
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener1, start);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->onTouchBegan = [](Touch* t, Event* e)
	{
		if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->end();
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener2, end);

	return true;
}

Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);

	return scene;
}

void MainMenu::createUTF()
{
	CCConfiguration::sharedConfiguration()->loadConfigFile("strings.plist");
	CCConfiguration *conf = CCConfiguration::sharedConfiguration();
	s[0] = (conf->getValue("start")).asString();
	s[1] = (conf->getValue("end")).asString();
}