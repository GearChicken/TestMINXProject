
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
	Game::SetVideoOptions(640, 480, false, "TestMINXProject");
}

void TestMINXProject::Initialize()
{
	//Put stuff here that should happen when the Game is initialized.
	Game::Initialize();
}

void TestMINXProject::LoadContent()
{
	//Put stuff here that loads content for your game.
	
	//Sound Stolen Shamelessly from:
	//http://www.pdsounds.org/sounds/dial_up_connection
	clip = new Media::SoundFile("../content/dial-up_connection.mp3", this);
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
	Graphics::Color backgroundColor = Graphics::Color((gamePad->GetAxis(1).val+1)*128-1, gamePad->GetButton(3).state*255, (gamePad->GetAxis(3).val+1)*128+1);
	gameWindow->ClearColor(backgroundColor);

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
