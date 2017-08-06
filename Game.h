#pragma once
#include <Vulkengine\System\Window.h>
#include <Vulkengine\System\Vulkengine.h>

class Game
{
public:
	Game();
	~Game();
	// Starts the Game Loop
	void Start();
private:
	 // Allocate/Initialize anything we need to before the game loop
	void Init();
	// Game Loop
	void GameLoop();
	// Processes the given input
	// TODO: ProcessInput should be it's own class, as it should be managed properly, not loosely like it currently is
	void ProcessInput();
	// Render draws everything to the screen
	void Render();
	// End Game Loop
private:
	Window m_Window;
	Vulkengine m_Vulkan;
};