#include"DebugDrawNode.h"

USING_NS_CC;

DebugDrawNode* DebugDrawNode::create(b2World*world) {
	DebugDrawNode *pRet = new(std::nothrow) DebugDrawNode();
	if (pRet && pRet->init(world))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool DebugDrawNode::init(b2World* world) {
	if (!Node::init())
	{
		return false;
	}
	m_pWorld = world;
	m_pDraw = new GLESDebugDraw(PTM_RATIO);
	uint32 flags = 0xffffffff;
	m_pDraw->SetFlags(flags);
	m_pWorld->SetDebugDraw(m_pDraw);

	return true;
}

void DebugDrawNode::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
	m_pWorld->DrawDebugData();
}