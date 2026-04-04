#include <Engine3DRadSpace/Graphics/Rendering/PostProcessEffect.hpp>
#include <Engine3DRadSpace/Math/Vector2.hpp>
#include <Engine3DRadSpace/Math/Vector3.hpp>

using namespace Engine3DRadSpace;
using namespace Engine3DRadSpace::Math;
using namespace Engine3DRadSpace::Graphics;
using namespace Engine3DRadSpace::Graphics::Rendering;

class MandelbrotEffect : public PostProcessEffect
{
public:
	MandelbrotEffect(IGraphicsDevice* device);

	struct alignas(16) MandelbrotData
	{
		int Iterations = 128;
		Vector2 Pan = Vector2(0.5, 0);
		float Zoom = 3;
		float Aspect = 1;
		Vector2 JuliaSeed = Vector2(0.39, -0.2);
		float _padding0 = 0;
		Vector3 ColorScale = Vector3(4, 5, 6);
	} Data;

	void Apply() override;

	~MandelbrotEffect() override = default;
};