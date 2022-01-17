#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);
}

void Game::Update()
{
	GEngine->Render();
}
