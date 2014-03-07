
#include "TestMINXProject.h"

#include <MINX/Media/SoundFile.h>
#include <MINX/Input/GamePad.h>
#include <MINX/Graphics/Color.h>

using namespace MINX_TESTMINXPROJECT;

Media::SoundFile* clip;
Input::GamePad* gamePad;
bool hasPlayed = false;
TestMINXProject::TestMINXProject()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	isRunning = true;
	Game::SetVideoOptions(640, 480, "TestMINXProject");
}

void TestMINXProject::Initialize()
{
	//Put stuff here that should happen when the Game is initialized.
	Game::Initialize();
}

void TestMINXProject::LoadContent()
{
	//Put stuff here that loads content for your game.
	clip = new Media::SoundFile("this_is_the_end_x.wav", this);
	gamePad = new Input::GamePad(0,this);
	Game::LoadContent();
}

void TestMINXProject::UnloadContent()
{
	//Put stuff here that unloads content from your game.
	Game::UnloadContent();
}

void TestMINXProject::Update(GameTime * gameTime)
{
	if(!hasPlayed)
	{
		clip->Play();
		hasPlayed=true;
	}
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void TestMINXProject::Draw(GameTime * gameTime)
{
	gameWindow->ClearColor(Graphics::Color(100, 149, 237));

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
