#pragma once
#include"GLES-Render.h"

#define PTM_RATIO 32

class DebugDrawNode : public cocos2d::Node
{
private:
	b2World* m_pWorld;

	GLESDebugDraw* m_pDraw;

public:
	static DebugDrawNode* DebugDrawNode::create(b2World* world);

	bool init(b2World* world);

	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags)override;

	GLESDebugDraw* getGLESDebugDraw() { return m_pDraw; }
};