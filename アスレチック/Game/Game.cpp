#include "stdafx.h"
#include "Game.h"

#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Title.h"
#include "GameClear.h"
#include "Flag.h"
#include "sound/SoundSource.h"

Game::Game()
{
	player = NewGO<Player>(0, "player");
	
	flag =NewGO<Flag>(0);
	flag->position = { -1250.0f,1350.0f,950.0f };

	m_gamecamera = NewGO<GameCamera>(0, "gamecamera");

	backGround = NewGO<BackGround>(0);

	g_soundEngine->ResistWaveFileBank(1, "Assets/BGMÅESE/vallery.wav");

	gameBGM = NewGO<SoundSource>(1);
	gameBGM->Init(1);
	gameBGM->Play(true);
	gameBGM->SetVolume(2.0f);

	g_camera3D->SetFar(20000.0f);

	g_renderingEngine->SetDirectionLight(0, Vector3(-0.2f, -1.0f, -0.2f), Vector3(0.5f, 0.5f, 0.5f));
}

Game::~Game()
{
	DeleteGO(player);
	DeleteGO(m_gamecamera);
	DeleteGO(gameBGM);
	DeleteGO(backGround);
}

void Game::Update()
{
	if (player->flagCount == 1)
	{
		NewGO<GameClear>(0, "gameclear");
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{
	
}