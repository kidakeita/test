#include"MyContactListner.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

// �R���^�N�g�����������Ƃ��ɌĂ΂��
// �����@contact:�R���^�N�g
void MyContactListner::BeginContact(b2Contact* contact)
{
	// �R���^�N�g�ɂ��Ă̏���

	void* bodyUserData;

	// �t�B�N�X�`��A�̕t���̃f�[�^�����o��
	bodyUserData = contact->GetFixtureA()->GetUserData();
	if (bodyUserData)
	{
		Sprite* spr = static_cast<Sprite*>(bodyUserData);
		// �X�v���C�g�̏���
		spr->setPosition(0, 0);
	}
}
// �R���^�N�g�����ł����Ƃ��ɌĂ΂��
// �����@contact: �R���^�N�g
void MyContactListner::EndContacat(b2Contact* contact)
{

}

// �Փ˂̉����������s���钼�O�ɌĂ΂��
// �����@contact:�R���^�N�g
// �����@oldManifold �ՓˑO�̃}�j�t�H�[���h
void MyContactListner::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

// �Փ˂̉����������s��ꂽ����ɌĂ΂��
// �����@contact:�R���^�N�g
// �����@impulse:���������Ŕ��������C���p���X
void MyContactListner::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}