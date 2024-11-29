# So Long
## Description

So Long is a small 2D game created as part of the 42 School curriculum. This project serves as an introduction to graphical programming and game development in C, using the MiniLibX, a simple graphical library.

The game places the player in a maze-like map where the goal is to collect all the collectibles and reach the exit. The map is loaded from a .ber file and is represented using a grid system. The player can move in four directions (up, down, left, right) while avoiding obstacles such as walls and invalid paths.

The project emphasizes:

  - Map Validation: Ensuring the map is properly formatted, closed with walls, and contains valid paths and elements.
  - Graphics and Event Handling: Rendering the game environment in a window, managing textures and sprites, and handling user input like key presses.
  - Memory Management: Carefully allocating and freeing resources to avoid leaks or crashes.
  - Gameplay Mechanics: Implementing movement logic, tracking the player's actions, and providing feedback such as move counts.

The game uses a top-down 2D view, where each element on the map is displayed as a sprite in the game window. The player's position updates in response to keyboard inputs, and the program keeps track of the total number of moves, displayed in the terminal (or on-screen for bonus features).

All the game assets, including textures and sprites, were designed and created by me, giving the game a unique and personal aesthetic.

You can customize the game by creating your own maps, characters, and themes, making it a flexible and engaging way to explore basic game mechanics.
## Installation

Clone the repository:
```
git clone https://github.com/your-account/so_long.git
```
Navigate to the project directory and compile the program:
```
make
```
To compile with bonus features:
```
make bonus
```
This will generate the so_long executable.
## Usage

Run the game with a .ber map file:
```
./so_long path_to_map.ber
```
## Controls

  - W / A / S / D (or Z / Q / S / D): Move the player up, left, down, or right.
  - ESC: Exit the game.

## Map Format

The map must follow these rules to be valid:

  Represented as a rectangular grid using the following characters:
      1: Wall
      0: Empty space
      C: Collectible
      E: Exit
      P: Player's starting position
  Must include at least one E, one C, and one P.
  Must be surrounded entirely by walls (1).
  There must be a valid path from the player’s starting position to the exit while collecting all collectibles.

Example of a valid map:
```
111111
1P00C1
1000E1
111111
```
If the map is invalid or misconfigured, the program will terminate with an error message.
