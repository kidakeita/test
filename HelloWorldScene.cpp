#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define PTM_RATIO 32

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	// 重力設定
	b2Vec2 gravity;

	// 毎フレーム加速
	gravity.Set(0.0f, -3.0f);
	// ワールド生成
	m_pWorld = new b2World(gravity);
	m_pWorld->SetAllowSleeping(true);
	DebugDrawNode* draw = DebugDrawNode::create(m_pWorld);
	this->addChild(draw,10000);
	//// 表示用インスタンス作成
	//m_pDraw = new GLESDebugDraw(PTM_RATIO);
	//// 全種類表示
	//uint32 flags = 0xffffff;
	//m_pDraw->SetFlags(flags);
	//// ワールドにセット
	//m_pWorld->SetDebugDraw(m_pDraw);

	// 変数初期化
	//m_flag = 0;

	// ===================================== //
	// 壁
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);

	groundBody = m_pWorld->CreateBody(&groundBodyDef);

	b2Vec2 leftb(97, 200);
	b2Vec2 rightb(544, 200);
	b2Vec2 leftt(97, 767);
	b2Vec2 rightt(544, 767);

	leftb.x /= PTM_RATIO;
	leftb.y /= PTM_RATIO;
	leftt.x /= PTM_RATIO;
	leftt.y /= PTM_RATIO;
	rightb.x /= PTM_RATIO;
	rightb.y /= PTM_RATIO;
	rightt.x /= PTM_RATIO;
	rightt.y /= PTM_RATIO;

	b2EdgeShape groundBox;

	groundBox.Set(leftb, rightb);
	groundBody->CreateFixture(&groundBox, 0);


	groundBox.Set(leftt, rightt);
	groundBody->CreateFixture(&groundBox, 0);


	groundBox.Set(leftt, leftb);
	groundBody->CreateFixture(&groundBox, 0);


	groundBox.Set(rightb, rightt);
	groundBody->CreateFixture(&groundBox, 0);

	// さんかく
	b2BodyDef sankakuBodyDef;
	sankakuBodyDef.position.Set(0, 0);

	b2Body* groundBody2 = m_pWorld->CreateBody(&sankakuBodyDef);

	b2Vec2 leftb2(97, 200);
	b2Vec2 rightb2(400, 200);
	b2Vec2 rightt2(400, 310);

	leftb2.x /= PTM_RATIO;
	leftb2.y /= PTM_RATIO;
	rightb2.x /= PTM_RATIO;
	rightb2.y /= PTM_RATIO;
	rightt2.x /= PTM_RATIO;
	rightt2.y /= PTM_RATIO;

	b2EdgeShape sankakuBox;

	sankakuBox.Set(leftb2, rightb2);
	groundBody2->CreateFixture(&sankakuBox, 0);


	sankakuBox.Set(leftb2, rightt2);
	groundBody2->CreateFixture(&sankakuBox, 0);


	sankakuBox.Set(rightb2, rightt2);
	groundBody2->CreateFixture(&sankakuBox, 0);

	// しかく
	b2BodyDef groundBodyDef3;
	groundBodyDef3.position.Set(0, 0);

	sikakuBody = m_pWorld->CreateBody(&groundBodyDef3);

	b2Vec2 leftb3(200, 400);
	b2Vec2 rightb3(260, 400);
	b2Vec2 leftt3(200, 460);
	b2Vec2 rightt3(260, 460);

	leftb3.x /= PTM_RATIO;
	leftb3.y /= PTM_RATIO;
	leftt3.x /= PTM_RATIO;
	leftt3.y /= PTM_RATIO;
	rightb3.x /= PTM_RATIO;
	rightb3.y /= PTM_RATIO;
	rightt3.x /= PTM_RATIO;
	rightt3.y /= PTM_RATIO;

	b2EdgeShape groundBox3;

	groundBox3.Set(leftb3, rightb3);
	sikakuBody->CreateFixture(&groundBox3, 0);


	groundBox3.Set(leftt3, leftb3);
	sikakuBody->CreateFixture(&groundBox3, 0);


	groundBox3.Set(rightb3, rightt3);
	sikakuBody->CreateFixture(&groundBox3, 0);

	// しかく
	b2BodyDef groundBodyDef4;
	groundBodyDef4.position.Set(0, 0);

	b2Body* sikakuBody2 = m_pWorld->CreateBody(&groundBodyDef4);

	b2Vec2 leftb4(300, 500);
	b2Vec2 rightb4(360, 500);
	b2Vec2 leftt4(300, 560);
	b2Vec2 rightt4(360, 560);

	leftb4.x /= PTM_RATIO;
	leftb4.y /= PTM_RATIO;
	leftt4.x /= PTM_RATIO;
	leftt4.y /= PTM_RATIO;
	rightb4.x /= PTM_RATIO;
	rightb4.y /= PTM_RATIO;
	rightt4.x /= PTM_RATIO;
	rightt4.y /= PTM_RATIO;

	b2EdgeShape groundBox4;

	groundBox4.Set(leftb4, rightb4);
	sikakuBody2->CreateFixture(&groundBox4, 0);


	groundBox4.Set(leftt4, leftb4);
	sikakuBody2->CreateFixture(&groundBox4, 0);


	groundBox4.Set(rightb4, rightt4);
	sikakuBody2->CreateFixture(&groundBox4, 0);








	// ===================================== //
	// 画面サイズ
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 背景
	background_ = Sprite::create("HelloWorld.png");
	background_->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background_, -1);

	// 輪設定
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(40.0f / 2 / PTM_RATIO, 5.0f / 2 / PTM_RATIO);
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(300 / PTM_RATIO, 350 / PTM_RATIO);
	fixtureDef.friction = 0.5f;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	//fixtureDef.restitution = 0.2f;
	//wa_[0] = m_pWorld->CreateBody(&bodyDef);
	//wa_[0]->CreateFixture(&fixtureDef);
	//// スプライト
	//waspr_[0] = Sprite::create("wa1.png");
	//this->addChild(waspr_[0]);
	//bodyDef.userData = waspr_[0];
	//// 輪追加
	//wa_[0] = m_pWorld->CreateBody(&bodyDef);
	//wa_[0]->CreateFixture(&fixtureDef);
	// スプライト
	for (int i = 0; i <= 15; i++) {
		if (i % 3 == 1) {
			waspr_[i] = Sprite::create("wa1.png");
		}
		else if (i % 3 == 0) {
			waspr_[i] = Sprite::create("wa2.png");
		}
		else if (i % 3 == 2) {
			waspr_[i] = Sprite::create("wa3.png");
		}
		this->addChild(waspr_[i]);
		bodyDef.userData = waspr_[i];
		wa_[i] = m_pWorld->CreateBody(&bodyDef);
		wa_[i]->CreateFixture(&fixtureDef);

	}

	// ========================================================================= //
	b2PolygonShape dynamicBox2;
	dynamicBox2.SetAsBox(50.0f / 2 / PTM_RATIO, 2.0f / 2 / PTM_RATIO);
	b2FixtureDef fixtureDef2;
	b2BodyDef bodyDef2;
	bodyDef2.type = b2_staticBody;

	fixtureDef2.friction = 0.5f;
	fixtureDef2.shape = &dynamicBox2;
	fixtureDef2.density = 5.0f;
	fixtureDef2.restitution = 0.2f;
	for (int i = 0; i < 2; i++)
	{
		if (i % 2)
		{
			bodyDef2.position.Set(230.4f / PTM_RATIO, 406.4f / PTM_RATIO);
		}
		else
		{
			bodyDef2.position.Set(330.4f / PTM_RATIO, 506.4f / PTM_RATIO);
		}
		mocobody[i] = m_pWorld->CreateBody(&bodyDef2);
		mocobody[i]->CreateFixture(&fixtureDef2);
	}

	// ========================================================================= //


	// ボタン
	auto button = ui::Button::create("b_1.png", "b_2.png");
	button->setPosition(Vec2(visibleSize.width / 2, 250));
	this->addChild(button);
	button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touchEvent, this));


    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	// タッチを有効にする
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	// アップデート
	scheduleUpdate();

	m_pWorld->SetContactListener(this);

    return true;
}

void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	// 物理ワールドをデバッグ表示
	//m_pWorld->DrawDebugData();
}


void HelloWorld::BeginContact(b2Contact * contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* A = fixtureA->GetBody();
	if (A != groundBody)
	{
		m_pbodyA = fixtureA->GetBody();
		m_pbodyB = fixtureB->GetBody();
	}
	for (int i = 0; i < 2; i++)
	{
		if (m_pbodyA == mocobody[i] || m_pbodyB == mocobody[i])
		{
			m_flag = 1;
		}
	}
	

}
void HelloWorld::EndContact(b2Contact * contact)
{

}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	//Vec2 p = touch->getLocation();
	//b2Vec2 impulse;
	//for (int i = 0; i <= 15; i++)
	//{
	//	b2Vec2 point = wa_[i]->GetWorldCenter();
	//	impulse.x = point.x - p.x / PTM_RATIO;
	//	impulse.y = point.x - p.y / PTM_RATIO;
	//	impulse.Normalize();
	//	impulse *= wa_[i]->GetMass() * 5.0f;
	//	wa_[i]->ApplyLinearImpulse(impulse, point, true);
	//	wa_[i]->ApplyAngularImpulse(5 , true);
	//}

	// パーティクル
	//CCParticleSystemQuad* particleStar = CCParticleSystemQuad::create("particletouch.plist");
	//particleStar->resetSystem();
	//particleStar->setPosition(Vec2(p));
	//this->addChild(particleStar, 5);

	m_mousepos = touch->getLocation();
	location = b2Vec2(m_mousepos.x / PTM_RATIO, m_mousepos.y / PTM_RATIO);
	b2AABB aabb;
	b2Vec2 d;
	d.Set(0.001f, 0.001f);
	aabb.lowerBound = location - d;
	aabb.upperBound = location + d;

	MyQueryCallback callback(location);

	m_pWorld->QueryAABB(&callback, aabb);


	if (callback.m_pBody)
	{

		b2MouseJointDef md;
		// 画面の壁（動かないオブジェクトとして定義）
		md.bodyA = groundBody;
		// 移動したいボディオブジェクト
		md.bodyB = callback.m_pBody;
		// タッチした場所
		md.target = location;
		// 衝突有効
		//md.collideConnected = true;
		// 反応の速さ
		md.maxForce = 100.0f * callback.m_pBody->GetMass();
		// インスタンス変数として保持
		m_mouseJoint = (b2MouseJoint*)m_pWorld->CreateJoint(&md);
	}
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
	if (m_mouseJoint == NULL)
	{
		return;
	}
	m_mousepos = touch->getLocation();
	location = b2Vec2(m_mousepos.x / PTM_RATIO, m_mousepos.y / PTM_RATIO);
	// 座標更新
	m_mouseJoint->SetTarget(location);
	//m_mousepos = touch->getLocation();
}
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (m_mouseJoint == NULL)
	{
		return;
	}
	m_pWorld->DestroyJoint(m_mouseJoint);
	m_mouseJoint = nullptr;
	//this->schedule(schedule_selector(HelloWorld::onMousePushed));
}
void HelloWorld::onTouchCancelled(Touch *touch, Event *unused_event)
{
	//this->schedule(schedule_selector(HelloWorld::onMousePushed));
}

void HelloWorld::touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	b2Vec2 impulse;

	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		//Vec2 p = touch->getLocation();
		//b2Vec2 impulse;
		for (int i = 0; i <= 15; i++)
		{
			b2Vec2 point = wa_[i]->GetWorldCenter();

			impulse.x = point.x - 97 / PTM_RATIO;
			impulse.y = point.y - 200 / PTM_RATIO;

			impulse.Normalize();

			impulse *= wa_[i]->GetMass() * 5.0f;

			wa_[i]->ApplyLinearImpulse(impulse, point, true);
		}

		break;
	case ui::Widget::TouchEventType::MOVED:
		break;
	case ui::Widget::TouchEventType::ENDED:
		break;
	}
}
void HelloWorld::update(float dt)
{
	m_pWorld->Step(1.0f / 60.0f, 8, 3);

	// 物理ワールド内のボディの処理
	for (b2Body* body = m_pWorld->GetBodyList();
	body != nullptr;
		body = body->GetNext())
	{
		// しまっておいたスプライトを取得
		Sprite* spr = (Sprite*)body->GetUserData();
		// あらかじめしまってある場合のみ
		if (spr != nullptr)
		{
			b2Vec2 pos = body->GetPosition();
			spr->setPosition(pos.x * PTM_RATIO, pos.y * PTM_RATIO);

			float rot = body->GetAngle();
			spr->setRotation(-CC_RADIANS_TO_DEGREES(rot));
		}
	}

	//m_callback.m_pHitBody = m_pbodyA;
	//m_pWorld->QueryAABB(&m_callback, m_aabb);
	for (int i = 0; i < 2; i++)
	{
		if (m_flag == 1 && mocobody[i] != nullptr)
		{
			log("hIt");
			weldjointdef.Initialize(m_pbodyA, m_pbodyB, m_pbodyA->GetPosition() - (m_pbodyA->GetPosition() - m_pbodyB->GetPosition()));
			weldjointdef.dampingRatio = 2.0f;
			weldjointdef.frequencyHz = 2;

			joint = m_pWorld->CreateJoint(&weldjointdef);

			/*		m_pbodyA = nullptr;
			m_pbodyB = nullptr;*/
			m_flag = 0;
		}
	}

}