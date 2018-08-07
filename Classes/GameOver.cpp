#include "GameOver.h"
#include "GameStageScene.h"
#include "HelloWorldScene.h"
#include "MainMenu.h"

void GameOver::createUTF()
{
	CCConfiguration::sharedConfiguration()->loadConfigFile("strings.plist");
	CCConfiguration *conf = CCConfiguration::sharedConfiguration();
	s[0] = (conf->getValue("hello")).asString();
	s[1] = (conf->getValue("hi")).asString();
	s[2] = (conf->getValue("font")).asString();
}

bool GameOver::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	createUTF();

	Size size = Director::getInstance()->getVisibleSize();
	LabelTTF* label = LabelTTF::create();
	label->setFontFillColor(Color3B::BLACK);
	label->setString("Game Over");
	label->setFontSize(70);
	//label->setFontName(s[3]);
	label->setPosition(size.width/2,size.height*0.7);
	addChild(label);

	LabelTTF* main = LabelTTF::create();
	main->setFontFillColor(Color3B::BLACK);
	main->setString(s[0]);
	main->setFontSize(40);
	//main->setFontName(s[3]);
	main->setPosition(size.width / 2, size.height*0.4);
	addChild(main);

	LabelTTF* restart = LabelTTF::create();
	restart->setFontFillColor(Color3B::BLACK);
	restart->setString(s[1]);
	restart->setFontSize(40);
	//restart->setFontName(s[3]);
	restart->setPosition(size.width / 2, size.height*0.2);
	addChild(restart);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [](Touch* t,Event* e)
	{
		if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->replaceScene(
				TransitionFlipAngular::create(1, GameStageScene::createScene()));
		}
			return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener1,restart);

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->onTouchBegan = [](Touch* t, Event* e)
	{
		if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->replaceScene(
				TransitionFadeTR::create(1, MainMenu::createScene()));
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(listener2, main);

	return true;
}
Scene* GameOver::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOver::create();
	scene->addChild(layer);
	return scene;
}