#include "MyQueryCallback.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

MyQueryCallback::MyQueryCallback(const b2Vec2 & point)
{
	m_point = point;
	m_pBody = nullptr;

}

MyQueryCallback::MyQueryCallback()
{
}

bool MyQueryCallback::ReportFixture(b2Fixture * fixture)
{
	b2Body* body = fixture->GetBody();
	if (body->GetType() == b2_dynamicBody)
	{
		bool inside = fixture->TestPoint(m_point);
		if (inside)
		{
			m_pBody = fixture->GetBody();
			return false;
		}
	}
	/*b2Shape* shape = fixture->GetShape();
	b2Transform transform;
	transform.SetIdentity();

	bool overlap = b2TestOverlap(shape, 0, m_pshape, 0, body->GetTransform(), transform);
	if (overlap)
	{
		log("HIt");
		m_pHitBody = fixture->GetBody();
	}*/
	
	return true;
}


MyQueryCallback::~MyQueryCallback()
{
}
