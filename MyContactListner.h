#ifndef __MYCONTACTLISTNER_H__
#define __MYCONTACTLISTNER_H__

#include "cocos2d.h"
#include "GLES-Render.h"
#include "Box2D/Box2D.h"
#include<stdint.h>

class MyContactListner :public b2ContactListener
{
public:

	void BeginContact(b2Contact* contact);
	
	void EndContacat(b2Contact* contact);
	
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};

#endif 