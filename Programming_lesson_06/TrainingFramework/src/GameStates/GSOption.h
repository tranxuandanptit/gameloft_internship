#pragma once
#include "gamestatebase.h"
#include"GameButton.h"

class GSOption :
	public GameStateBase
{
public:
	GSOption();
	~GSOption();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();
	void ChangeSoundOption();

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>  m_Text_GameOption;
	std::shared_ptr<Text>  m_SoundButton_Text;
	std::shared_ptr<Text>  m_Quit_Text;
	float m_time;
	bool m_IsSoundOn;
};

