#include "GSCredit.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSCredit::GSCredit()
{
	m_time = 0;
}


GSCredit::~GSCredit()
{
}


void GSCredit::Init()
{
	//BackGround
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("my_bg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("my_button");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 400);
	button->SetSize(200, 70);
	button->SetOnClick([]()
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
	});
	m_listButton.push_back(button);

	//Credit:
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcadeclassic");
	m_CreditText = std::make_shared<Text>(shader, font, "Tran Xuan Dan", TEXT_COLOR::BLACK, 1.5);
	m_CreditText->Set2DPosition(Vector2(screenWidth / 2 - 110, 220));
	m_CreditText2 = std::make_shared<Text>(shader, font, "Internship Gameloft 2020", TEXT_COLOR::BLACK, 1.5);
	m_CreditText2->Set2DPosition(Vector2(screenWidth / 2 - 220, 320));

	m_Quit_Text = std::make_shared<Text>(shader, font, "Quit", TEXT_COLOR::BLACK, 1.5);
	m_Quit_Text->Set2DPosition(Vector2(screenWidth / 2 - 35, 410));
}

void GSCredit::Exit()
{

}


void GSCredit::Pause()
{

}

void GSCredit::Resume()
{

}


void GSCredit::HandleEvents()
{

}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
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

void GSCredit::Update(float deltaTime)
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

void GSCredit::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_CreditText->Draw();
	m_CreditText2->Draw();
	m_Quit_Text->Draw();
}
