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
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	//ここからメンバ変数
	ModelRender modelRender;
	//Hands On 1 座標データを追加する。
	Vector3 position;
	Vector3 movespeed;
	CharacterController characterController;
	Quaternion rotation;
	int playerstate = 0;
	int flagCount = 0;
};

