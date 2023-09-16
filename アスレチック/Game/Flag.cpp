#include "stdafx.h"
#include "Flag.h"
#include "Player.h"

Flag::Flag()
{
	modelRender.Init("Assets/modelData/flag.tkm");
	player = FindGO<Player>("player");
	
}

Flag::~Flag()
{

}

void Flag::Move()
{
	//ŠG•`‚«‚³‚ñ‚ÉÀ•W‚ð‹³‚¦‚éB
	modelRender.SetPosition(position);
}

void Flag::Update()
{
	Move();


	modelRender.Update();

	Vector3 diff = position - player->position;
	if (diff.Length() <= 110.0f)
	{
		player->flagCount += 1;

		DeleteGO(this);
	}

}

void Flag::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}