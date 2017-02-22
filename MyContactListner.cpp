#include"MyContactListner.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

// コンタクトが発生したときに呼ばれる
// 引数　contact:コンタクト
void MyContactListner::BeginContact(b2Contact* contact)
{
	// コンタクトについての処理

	void* bodyUserData;

	// フィクスチャAの付属のデータを取り出す
	bodyUserData = contact->GetFixtureA()->GetUserData();
	if (bodyUserData)
	{
		Sprite* spr = static_cast<Sprite*>(bodyUserData);
		// スプライトの処理
		spr->setPosition(0, 0);
	}
}
// コンタクトが消滅したときに呼ばれる
// 引数　contact: コンタクト
void MyContactListner::EndContacat(b2Contact* contact)
{

}

// 衝突の解決処理が行われる直前に呼ばれる
// 引数　contact:コンタクト
// 引数　oldManifold 衝突前のマニフォールド
void MyContactListner::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

// 衝突の解決処理が行われた直後に呼ばれる
// 引数　contact:コンタクト
// 引数　impulse:解決処理で発生したインパルス
void MyContactListner::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}