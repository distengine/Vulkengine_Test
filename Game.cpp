#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
	Init();
	GameLoop();
	int ii = 1;
}

void Game::Init()
{
	m_Window.CreateSDLWindow("Vulkengine - Test", 1280, 720);
	auto winHandle = m_Window.GetWindowHandle();
	m_Vulkan.CreateInstance();
	m_Vulkan.GetPhysicalDeviceList();
	m_Vulkan.GetQueueFamilies();
	m_Vulkan.CreateDevice();
	m_Vulkan.CreateCommandPool();
	m_Vulkan.CreateSurface(winHandle.info.win.hinstance, winHandle.info.win.window);
	m_Vulkan.CreateSwapChain();
	m_Vulkan.CreateDepthBuffer();
	m_Vulkan.CreateUniformBuffer();
}

void Game::GameLoop()
{
	while (m_Window.IsOpen())
	{
		ProcessInput();
		Render();
	}
}

void Game::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			m_Window.Close();
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				m_Window.Close();
			}
		}
	}
}

void Game::Render()
{
}