//Shader source from https://blog.nostatic.org/2009/09/fractal-rendering-on-gpu-mandelbrot-and.html
//There are small modifications to adapt the source to 3DRadSpace including
// -- [loop] attribute
// -- Only Mandelbrot_PixelShader as the entry function
// -- Using a single constant buffer to pass the data.

cbuffer Data : register(b0)
{
	int Iterations = 128;
	float2 Pan = float2(0.5, 0);
	float Zoom = 3;
	float Aspect = 1;
	float2 JuliaSeed = float2(0.39, -0.2);
	float3 ColorScale = float3(4, 5, 6);
}

float ComputeValue(float2 v, float2 offset)
{
	float vxsquare = 0;
	float vysquare = 0;

	int iteration = 0;
	int lastIteration = Iterations;

	[loop]
	do
	{
		vxsquare = v.x * v.x;
		vysquare = v.y * v.y;

		v = float2(vxsquare - vysquare, v.x * v.y * 2) + offset;

		iteration++;

		if ((lastIteration == Iterations) && (vxsquare + vysquare) > 4.0)
		{
			lastIteration = iteration + 1;
		}
	}
	while (iteration < lastIteration);

	return (float(iteration) - (log(log(sqrt(vxsquare + vysquare))) / log(2.0))) / float(Iterations);
}

struct VertexOut
{
	float4 Position : SV_POSITION;
	float2 UV : TEXCOORD;
};

float4 Mandelbrot_PixelShader(VertexOut vert) : SV_TARGET
{
	float2 texCoord = vert.UV;
	float2 v = (texCoord - 0.5) * Zoom * float2(1, Aspect) - Pan;

	float val = ComputeValue(v, v);

	return float4(sin(val * ColorScale.x), sin(val * ColorScale.y), sin(val * ColorScale.z), 1);
}