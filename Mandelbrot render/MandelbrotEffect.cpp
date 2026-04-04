#include "MandelbrotEffect.hpp"

ShaderDescFile mandelbrotShaderDescFile("MandelbrotEffect.hlsl", "Mandelbrot_PixelShader", ShaderType::Fragment, ShaderFeatureLevel::DX_V5);

MandelbrotEffect::MandelbrotEffect(IGraphicsDevice* device) : PostProcessEffect(device, mandelbrotShaderDescFile)
{
}

void MandelbrotEffect::Apply()
{
	PostProcessEffect::Apply();
	SetData(0, &Data, sizeof(Data));
}