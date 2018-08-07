#include "SingleScene.h"


SingleScene::SingleScene()
{
}


SingleScene::~SingleScene()
{
}

SingleScene* SingleScene::create(Layer* layer, int positionY)
{
	auto ss = new SingleScene();
	if (ss&&ss->init(layer,positionY))
	{
		ss->autorelease();
		return ss;
	}
	else
	{
		delete ss;
		return nullptr;
	}
}
bool SingleScene::init(Layer* layer, int positionY)
{
	this->layer = layer;
	this->positionY = positionY;
	size = Director::getInstance()->getVisibleSize();
	timeLimit = CCRANDOM_0_1() * 150 + 200;
	currentTime = 0;
	heroPositionX = size.width / 10;
	isJumping = false;
	isAdjusting = false;

	edge = Edge::create();
	edge->setPosition(size.width / 2, positionY + size.height / 2);
	edge->setContentSize(size);
	layer->addChild(edge);

	hero = Hero::create();
	hero->setPosition( heroPositionX, positionY + hero->getContentSize().height / 2 );
	layer->addChild(hero);

	auto block = Block::create();
	block->setPosition(size.width-50+CCRANDOM_0_1()*200, positionY + block->getContentSize().height / 2);
	layer->addChild(block);

	auto ground = Sprite::create();
	ground->setTextureRect(Rect(0,0,size.width,10));
	ground->setColor(Color3B::BLACK);
	ground->setPosition(size.width / 2, positionY - ground->getContentSize().height / 2);
	layer->addChild(ground);

	return true;
}

void SingleScene::update()
{
	currentTime++;
	if (currentTime >= timeLimit)
	{
		auto block = Block::create();
		block->setPosition(size.width, positionY + block->getContentSize().height / 2);
		layer->addChild(block);
		currentTime = 0;
		timeLimit = CCRANDOM_0_1() * 150 + 200;
	}
	if ( !isAdjusting && abs(hero->getPositionX() - heroPositionX)>3 && (hero->getPositionY() - (positionY + hero->getContentSize().height / 2)) < 10 )
	{
		isJumping = false;
		hero->runAction(Sequence::create(	MoveTo::create(1, Vec2(heroPositionX, positionY + hero->getContentSize().height / 2)),
			CallFunc::create([this](){
			this->setAdjusting(false);
		}), NULL));
		isAdjusting = true;
	}
}

void SingleScene::setAdjusting(bool adjust)
{
	isAdjusting = adjust;
}

bool SingleScene::containPoint(Vec2 p)
{
	if (p.y >= positionY)
	{
		return true;
	}
	return false;
}

void SingleScene::jump()
{
	if (!isJumping)
	{
		hero->getPhysicsBody()->setVelocity(Vec2(120, 500));
		isJumping = true;
	}
}