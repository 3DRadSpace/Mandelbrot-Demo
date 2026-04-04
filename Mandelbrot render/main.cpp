#include <Engine3DRadSpace/Games/Game.hpp>
#include "MandelbrotEffect.hpp"

using namespace Engine3DRadSpace;
using namespace Engine3DRadSpace::Input;
using namespace Engine3DRadSpace::Math;
using namespace Engine3DRadSpace::Graphics;
using namespace Engine3DRadSpace::Graphics::Rendering;

class MyGame : public Engine3DRadSpace::Game
{
public:
	MyGame() : Game("MyGame") 
	{
	}

	void Load() override
	{
		Game::Load();
		PostProcesses->Add<MandelbrotEffect>();
	}

	void Update() override
	{
		Game::Update();
		auto& effect = PostProcesses->Get<MandelbrotEffect>();
		
		float panSpeed = effect.Data.Zoom * Update_dt;

		if(Keyboard.IsKeyDown(Key::LeftArrow))
		{
			effect.Data.Pan.X += panSpeed;
		}
		if(Keyboard.IsKeyDown(Key::RightArrow))
		{
			effect.Data.Pan.X -= panSpeed;
		}
		if(Keyboard.IsKeyDown(Key::UpArrow))
		{
			effect.Data.Pan.Y += panSpeed;
		}
		if(Keyboard.IsKeyDown(Key::DownArrow))
		{
			effect.Data.Pan.Y -= panSpeed;
		}

		float zoomSpeed = effect.Data.Zoom * Update_dt;

		if(Keyboard.IsKeyDown(Key::Q))
		{
			effect.Data.Zoom -= zoomSpeed;
		}

		if(Keyboard.IsKeyDown(Key::E))
		{
			effect.Data.Zoom += zoomSpeed;
		}

	}
	~MyGame() override = default;
};

int __stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
{
	MyGame game;
	game.Run();
}