#pragma once
#include "gamestatebase.h"
#include "GameButton.h"

class GSCredit :
	public GameStateBase
{
public:
	GSCredit();
	~GSCredit();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	std::shared_ptr<Text> m_CreditText;
	std::shared_ptr<Text> m_CreditText2;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>  m_Quit_Text;
	std::shared_ptr<Sprite2D> m_BackGround;
	float m_time;
};

