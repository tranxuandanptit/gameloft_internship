#include "GSOption.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSOption::GSOption()
{
	m_time = 0;
	m_IsSoundOn = true;
}


GSOption::~GSOption()
{
}


void GSOption::Init()
{
	//BackGround
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("my_bg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//Sound button
	texture = ResourceManagers::GetInstance()->GetTexture("my_button");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 200);
	button->SetSize(200, 70);
	button->SetOnClick([]()
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
	});
	m_listButton.push_back(button);

	//Quit button
	texture = ResourceManagers::GetInstance()->GetTexture("my_button");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 300);
	button->SetSize(200, 70);
	button->SetOnClick([]()
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
	});
	m_listButton.push_back(button);

	//Credit:
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcadeclassic");
	m_Text_GameOption = std::make_shared<Text>(shader, font, "Option", TEXT_COLOR::CYAN, 2);
	m_Text_GameOption->Set2DPosition(Vector2(screenWidth / 2 - 80, 120));

	m_SoundButton_Text = std::make_shared<Text>(shader, font, "Sound", TEXT_COLOR::BLACK, 1.5);
	m_SoundButton_Text->Set2DPosition(Vector2(screenWidth / 2 - 45, 210));

	m_Quit_Text = std::make_shared<Text>(shader, font, "Quit", TEXT_COLOR::BLACK, 1.5);
	m_Quit_Text->Set2DPosition(Vector2(screenWidth / 2 - 35, 310));
}

void GSOption::ChangeSoundOption()
{
	if (m_IsSoundOn)
	{
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcadeclassic");
		m_SoundButton_Text = std::make_shared<Text>(shader, font, "Sound Off", TEXT_COLOR::BLACK, 1.5);
		m_IsSoundOn = false;
	}
	else
	{
		auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
		std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcadeclassic");
		m_SoundButton_Text = std::make_shared<Text>(shader, font, "Sound On", TEXT_COLOR::BLACK, 1.5);
		m_IsSoundOn = true;
	}
}

void GSOption::Exit()
{

}


void GSOption::Pause()
{

}

void GSOption::Resume()
{

}


void GSOption::HandleEvents()
{

}

void GSOption::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSOption::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_time > 0.25)
	{
		for (auto it : m_listButton)
		{
			(it)->HandleTouchEvents(x, y, bIsPressed);
			if ((it)->IsHandle()) break;
		}
	}
}

void GSOption::Update(float deltaTime)
{
	if (m_time > 0.25)
	{
		m_BackGround->Update(deltaTime);
		for (auto it : m_listButton)
		{
			it->Update(deltaTime);
		}
	}
	else
	{
		m_time += deltaTime;
	}
}

void GSOption::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_GameOption->Draw();
	m_SoundButton_Text->Draw();
	m_Quit_Text->Draw();
}
