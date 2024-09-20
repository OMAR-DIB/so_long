# So Long

## Overview
**So Long** is a simple 2D game developed using the MiniLibX graphics library. The goal is to collect all items on the map and exit through the designated portal, all while navigating obstacles and avoiding invalid moves. 

## Features
- Player movement using W, A, S, D keys (or arrow keys).
- Collectible items scattered across the map.
- A top-down view of the game world.
- Movement counter displayed in the shell.
- Exits the game when ESC is pressed or the window is closed.

## Project Structure
- **Main Program:** The game logic and player movement.
- **Graphic Management:** Displays the game world and responds to user input.
- **Map Handling:** Manages the map's structure, ensuring the player can move within defined boundaries.

## How to Build
1. Clone the repository.
2. Ensure the MiniLibX library is installed on your machine.
3. Use the provided `Makefile` to build the project by running:
   ```bash
   make
   ./so_long [path_to_map_file]

