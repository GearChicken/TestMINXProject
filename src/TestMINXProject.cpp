
#include "TestMINXProject.h"

#include "Media/SoundFile.h"

using namespace MINX_TESTMINXPROJECT;

Media::SoundFile* clip;

TestMINXProject::TestMINXProject() : Game::Game()
{
	//This is the constructor. Put stuff here that should happen when the Game is created.

	isRunning = true;
	Game::SetVideoOptions(640, 480, 32, 0, "TestMINXProject");
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
	clip->Play();
	Game::LoadContent();
}

void TestMINXProject::UnloadContent()
{
	//Put stuff here that unloads content from your game.
	Game::UnloadContent();
}

void TestMINXProject::Update(GameTime * gameTime)
{
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void TestMINXProject::Draw(GameTime * gameTime)
{
	glClearColor( 100/255.0f, 149/255.0f, 237/255.0f, 1.0f );
    	glClear( GL_COLOR_BUFFER_BIT );

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
