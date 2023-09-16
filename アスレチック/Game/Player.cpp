#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);

	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	Move();

	Rotation();

	ManageState();

	PlayAnimation();

	modelRender.Update();
}



void Player::Move()
{
	movespeed.x = 0.0f;
	movespeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	right.y = 0.0f;
	forward.y = 0.0f;

	//ベクトルの正規化(数学)
	right.Normalize();
	forward.Normalize();

	right *= stickL.x * 300.0f;
	forward *= stickL.y * 300.0f;

	movespeed.x *= stickL.x * 250.0f;
	movespeed.z *= stickL.y * 250.0f;

	movespeed += right + forward;

	if (characterController.IsOnGround())
	{
		movespeed.y = 0.0f;
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			movespeed.y = 500.0f;
		}
	}
	else
	{
		movespeed.y -= 100.0f;
	}

	position = characterController.Execute(movespeed, 1.0f / 60.0f);

	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	if (fabsf(movespeed.x) >= 0.001f || fabsf(movespeed.z) >= 0.001f)
	{
		rotation.SetRotationYFromDirectionXZ(movespeed);

		modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	if (characterController.IsOnGround() == false)
	{
		playerstate = 1;
		return;
	}

	if (fabsf(movespeed.x) >= 0.001f || fabsf(movespeed.z) >= 0.001f)
	{
		playerstate = 2;
	}
	else
	{
		playerstate = 0;
	}
}

void Player::PlayAnimation()
{
	if (playerstate == 0)
	{
		modelRender.PlayAnimation(enAnimationClip_Idle);
	}
	else if (playerstate == 1)
	{
		modelRender.PlayAnimation(enAnimationClip_Jump);
	}
	else if (playerstate == 2)
	{
		modelRender.PlayAnimation(enAnimationClip_Walk);
	}
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}

