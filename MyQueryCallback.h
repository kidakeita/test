#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
class MyQueryCallback: public b2QueryCallback
{
public:
	b2Body* m_pBody;
	b2Vec2 m_point;
	bool ReportFixture(b2Fixture* fixture) override;
	bool flag = nullptr;
	b2Body* m_pHitBody;
	b2Shape* m_pshape;
	MyQueryCallback(const b2Vec2& point);
	MyQueryCallback();
	~MyQueryCallback();
	
};

