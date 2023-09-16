#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& rc);
	void PlayAnimation();
	void Rotation();
	void Move();
	void ManageState();
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	//�������烁���o�ϐ�
	ModelRender modelRender;
	//Hands On 1 ���W�f�[�^��ǉ�����B
	Vector3 position;
	Vector3 movespeed;
	CharacterController characterController;
	Quaternion rotation;
	int playerstate = 0;
	int flagCount = 0;
};

