#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SingleScene.h"

class HelloWorld : public cocos2d::LayerColor
{
private:
	Vector<SingleScene*> ss;
	Size size;
public:
	static HelloWorld* create(int stages);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(int stages);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	bool init(int stages);

	virtual void update(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
