#include "Edge.h"


bool Edge::init()
{
	Node::init();

	Size size = Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createEdgeBox(size));
	setContentSize(size);

	/*log("Edge :%f",size.width);
	log("Edge :%f",getBoundingBox().size.width);*/


	

	return true;
}