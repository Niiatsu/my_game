#pragma once

#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

class Player;
class BackGround;
class GameCamera;
class Flag;

class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;
	Vector3 m_pos;
	BackGround* backGround;
	Flag* flag;
	GameCamera* m_gamecamera;
	Player* player;
	Vector3 position;
	SoundSource* gameBGM;
};

