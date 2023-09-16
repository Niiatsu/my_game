#pragma once
class Player;
class Flag : public IGameObject
{
public:
	Flag();
	~Flag();
	void Move();
	void Update();
	void Render(RenderContext& rc);
		ModelRender modelRender;
	Vector3 position;
	Vector3 firstposition;
	int moveCount = 0;
	Player* player;
};

