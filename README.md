# SO_LONG (with LINUX and MACOS support)
A simple 2D game written in C using MiniLibX, focused on grid-based world representation, state-driven rendering, and event handling—skills directly transferable to backend systems that manage state and business rules.

The onigiri concept was my original idea, but the custom sprites for the project were designed by [Bryan Zapata](https://www.linkedin.com/in/zapatabryan/).

## 🎯 Project Goal
The goal of so_long is to build a small 2D game using a minimal graphics library, without relying on a game engine or advanced abstractions.

The project requires:
- Parsing and validating a map file
- Representing a game world as a grid
- Handling player input and movement
- Updating game state and rendering accordingly

This project emphasizes state consistency, rule enforcement, and deterministic behavior.
Although not included in the project requirements, my version handles cross-platform setup and automated dependency configuration.

## 🧠 Backend-Relevant Skills
This project develops and reinforces several backend-relevant concepts:

- State management and rule-based logic
- Parsing and validating structured input
- Event-driven programming
- Separation of game logic from rendering
- Handling state transitions deterministically
- Cross-platform build configuration
- Automating dependency setup

Although visual, the core of the project is a state machine operating on structured data.

## 🛠 Tech Stack
- Language: C
- Graphics Library: MiniLibX
- Build System: Makefile
- Tooling: gcc, valgrind
- Environment: Linux (X11), macOS

## 🗺 Map & Game Rules

The game world is represented as a 2D grid parsed from a .ber map file

Each tile represents a fixed entity:
- Walls
- Floor
- Player start position
- Exit
- Collectibles

### Extended Gameplay Logic

In addition to the stated requirements, my implementation supports:
- **Two distinct types of collectibles**
- **Dynamic sprite changes**:
	- Player appearance updates as collectibles are gathered
 	- Exit appearance updates once collection requirements are met

All visual changes are driven by internal game state.

## 📐 Architecture & State Flow

- The map is stored as a structured 2D array
- Player input triggers:
  1. Move validation against game rules
  2. State updates (position, collectibles)
  3. Conditional rendering updates

The exit becomes usable only _after_ all required collectibles are collected. 
This also means parsing and validation of the map requires two distinct flood_fill processes:
- One first pass treating the exit as a wall, to ensure that all collectibles can be accessed
- A second pass treating the exit as an item, to ensure it can be reached after all collectibles are picked up.

Rendering is treated as a pure reflection of state, not the source of truth.

## 🧩 Cross-Platform Support

This project includes macOS support via a custom Makefile:
- Detects the operating system
- Automatically downloads the appropriate MiniLibX version
- Builds and configures the library locally
- Links against the correct system frameworks on macOS

This removes manual setup steps and ensures a consistent build process across environments.
The project implements OS-dependent logic in the code (since the library for macOS does not include the same functions as the library for Linux). 

## 📈 What I Learned

- How to design portable build systems
- Why automating dependency management reduces setup friction
- How platform-specific differences affect compilation and linking
- How to keep application logic independent from platform concerns

These lessons directly apply to maintaining cross-platform backend services and tooling.

## 📦 What's Included
- Game-ready sprites in png and xpm format
- Examples of ready-to-play valid maps in multiple sizes
- Example of invalid map
- Detailed error messages for invalid map files (easy to identify issues with provided map)


## 🚀 How to Build & Run

If using macOS, you will need to install Quartz for window management:

If using Linux, you will need to install

Build with the included Makefile - this will download the appropriate version of the rendering library based on your OS, and generate a `so_long` binary
```bash
make
```

Run using the path one of the provided maps in the map folder, or you can use the path to a map you have built yourself!
```bash
./so_long maps/valid_L1.ber
```

**Map Requirements:**

Only the following characters are valid in a map: 
- `0` - Floor (empty spaces)
- `1` - Walls (cannot be crossed by the player - the map needs to be entirely surrounded by walls to be valid
- `P` - Starting position for the onigiri (player) - there can be only 1 per map
- `C` - Collectible - Salmon for your onigiri! (there needs to be at least 1 per map)
- `A` - Alternative Collectible - Nori for your onigiri! (you can include as many as you want, or none)
- `E` - Exit - your bento box, which opens only for fully prepared onigiri with all their ingredients! (only one is allowed per map)
  
Make sure all your collectibles (`C` and `A`) and the exit can be accessed!
- All collectibles must be on a path that can be accessed by the player (`P`).
- The exit `E` will act as a wall (it will only open and be accessible when all collectibles are picked up), so make sure it's not blocking access to collectibles!
  
**Controls:**
- `UP`, `DOWN`, `LEFT` and `RIGHT` arrows - move onigiri around the map
	- alternatively, you can use the `W`, `A`, `S`, and `D` keys
- `ESC` — exit game

**Playing the game**
- Pick up ALL collectibles so the bento box will open and you can climb in.
- When you have picked up all the salmon, your onigiri will put on his salmon sashimi hat.
- When you have picked up all the nori, your onigiri will put on his nori dress.

The game will display in the terminal the total number of moves you have taken with the onigiri!

