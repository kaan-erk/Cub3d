This project has been created as part of the 42 curriculum by <ktoraman>, <ysoyturk>.
Description

cub3D is a 42 school project that challenges students to create a "realistic" 3D graphical representation of a maze from a first-person perspective. Inspired by the world-famous 1992 game Wolfenstein 3D, this project serves as a deep dive into the world of Raycasting.

The primary goal is to explore the mathematical principles of perspective and geometry while managing a graphical window using the MiniLibX (MLX) library.
Key Features

    Raycasting Engine: Simulates a 3D environment from a 2D map using the DDA algorithm.

    Dynamic Movement: Smooth keyboard controls (WASD) and camera rotation.

    Texture Mapping: Different textures for North, South, East, and West walls to provide spatial orientation.

    Map Parsing: A robust system to read and validate .cub files, ensuring the map is enclosed by walls.

Instructions
Prerequisites

You must have the MiniLibX library (MLX) installed and configured for your specific operating system (Linux or macOS).
Compilation

To compile the project, navigate to the root directory and use the provided Makefile:
Bash

make

This will generate the cub3D executable.
Execution

The program requires a map file with the .cub extension as its only argument:
Bash

./cub3D maps/test_map.cub

Controls

    W / S: Move forward and backward.

    A / D: Strafe left and right.

    Left / Right Arrows: Rotate the camera.

    ESC: Exit the game.

Resources
Classic References

    Lode's Raycasting Tutorial: The foundational guide for understanding the math behind ray-camera planes and DDA.

    MiniLibX Documentation: Essential for pixel manipulation and event handling (hooks).

    Computer Graphics: Principles and Practice: For a broader understanding of rendering pipelines.

Use of AI

For this project, AI was utilized as a primary tool for documentation and resource acquisition. Specifically:

    Documentation Synthesis: AI was used to summarize complex technical manuals for the MiniLibX library, converting dense documentation into actionable implementation steps for window and image management.

    Resource Discovery: AI acted as a research assistant to locate specific articles, legacy game engine post-mortems, and mathematical proofs related to the "fisheye effect" correction.
