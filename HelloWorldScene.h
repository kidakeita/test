#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Box2D\Box2D.h"
#include "cocos2d.h"
#include "GLES-Render.h"
#include<stdint.h>
#include"DebugDrawNode.h"
#include "MyQueryCallback.h"

// ボタン用
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer,b2ContactListener
{
private:
	// ワールド
	b2World*  m_pWorld;
	
	// 背景
	cocos2d::Sprite* background_;
	// 輪
	b2Body* wa_[15];
	cocos2d::Sprite* waspr_[15];
	// さんかく
	cocos2d::Sprite* sankaku_;
	
	MyQueryCallback m_callback;
	b2AABB m_aabb;
	b2Body* sikakuBody;
	b2Body* sikakuBody3;
	b2Body* mocobody[2];
	b2Body* groundBody;

	b2Body* m_pbodyA;
	b2Body* m_pbodyB;
	b2WeldJointDef weldjointdef;
	b2Joint* joint;

	cocos2d::Vec2 m_mousepos;
	b2Vec2 location;
	b2MouseJoint* m_mouseJoint;

	int m_flag;
	int m_posflag;


public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	void update(float dt);

	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	// ボタンイベ
	void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

};

#endif // __HELLOWORLD_SCENE_H__
