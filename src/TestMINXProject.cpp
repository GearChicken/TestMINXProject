
#include "TestMINXProject.h"

#include <MINX/Media/SoundFile.h>
#include <MINX/Input/GamePad.h>
#include <MINX/Graphics/Color.h>
#include <MINX/Graphics/Font.h>
#include <MINX/Graphics/ShaderFactory.h>
#include <MINX/Graphics/TextureBatch.h>
#include <MINX/Input/Keyboard.h>

using namespace MINX_TESTMINXPROJECT;
using namespace MINX::Graphics;
Font* myFont;
Media::SoundFile* clip;
Input::GamePad* gamePad;
Input::Keyboard* keyboard;
bool hasPlayed = false;
TextureBatch* texBatch;
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
	texBatch = new TextureBatch(ShaderFactory::GetInstance()->GetShaderAtIndex(0));
}

void TestMINXProject::LoadContent()
{
	//Put stuff here that loads content for your game.
	ShaderFactory::GetInstance();
	//Sound Stolen Shamelessly from:
	//http://www.pdsounds.org/sounds/dial_up_connection
	clip = new Media::SoundFile("../content/beer_splash.wav");
	myFont = new Font(freeTypeLibrary, "Ubuntu-B.ttf", ShaderFactory::GetInstance()->GetShaderAtIndex(1));
	gamePad = new Input::GamePad(0,this);
	keyboard = new Input::Keyboard(this);
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

	if(keyboard->GetKey(Input::Keys::KEY_SPACE).state)
	{
		isRunning=false;
	}
	//Put stuff here to update the logic in your game each tick.
	Game::Update(gameTime);
}

void TestMINXProject::Draw(GameTime * gameTime)
{
	gameWindow->ClearColor(Color(0,0,0));

	Texture2D* myFontTex = myFont->RenderText("labcdefghiklmnopqrstuvwxyz1234567890", 0, 0, 16, Color(255,255,255,255));

	texBatch->Draw(myFontTex, 10, 10, 1, 1);
	texBatch->DrawLoadedTextures();

	//Put stuff here to draw your game each frame.
	Game::Draw(gameTime);
}
