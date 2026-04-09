# 3DRadSpace - Mandelbrot demo

This is an example application demonstrating a Mandelbrot shader written in C++ and HLSL. 

Video here: https://youtu.be/Et76ZaDpUaQ

This project demonstrates low level capabilities of the game engine such as low level access to the GAPIs (Graphics APIs) and the inclusion of shaders in an C++ project using a class inheriting `PostProcessEffect`.

Unlike an usual `PostProcessEffect` instance, this effect doesn't read the main render target, but directly writes to the backbuffer.

The shader is rendered by the game engine by submitting the effect into the list of post processes by calling `PostProcesses->Add<E>()`.

# Playing the project
Use arrow keys to move the screen, Q and E to zoom.

# Building the project
You'll need a compiled copy of 0.1.0Alpha of 3DRadSpace. 

Edit the linker settings to the path of 3DRadSpace installation directory (There will be a method in the future to use PATH variables or VS solution macros).
