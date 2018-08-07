#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include "cocos2d.h"
USING_NS_CC;

class MainMenu:public LayerColor
{
private:
	static int singleCounts;
	std::string s[2];
public:
	CREATE_FUNC(MainMenu);
	virtual bool init();
	static Scene* createScene();
	void createUTF();
	static int getSingleCounts(){
		return singleCounts;
	}
	static void setSingleCounts(int count){
		singleCounts = count;
	}
};

//int MainMenu::singleCounts = 0;

#endif
