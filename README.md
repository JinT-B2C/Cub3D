*This project has been created as part of the 42 curriculum by frazakar, torasolo.*

# cub3D — My first RayCaster with miniLibX

## Description

cub3D is a 3D maze exploration project inspired by Wolfenstein 3D, the first true First Person Shooter in video game history. The goal is to render a realistic first-person view inside a maze defined by a `.cub` scene file, using ray-casting techniques implemented from scratch in C.

The project covers window management, pixel-level rendering, texture mapping, keyboard event handling, and map parsing — all built without any game engine, using only the miniLibX graphics library.

## Features

- First-person 3D ray-casting rendering (DDA algorithm)
- Textured walls with different textures per face (North, South, East, West)
- Configurable floor and ceiling colors via the `.cub` file
- Smooth player movement: forward, backward, strafe left/right
- Camera rotation via left/right arrow keys
- Wall collision detection with a 4-corner hitbox
- Robust `.cub` file parser with full error handling
- Clean exit on ESC or window close button

## Instructions

### Requirements

- Linux (tested on Ubuntu / 42 school machines)
- miniLibX (included in `minilibx-linux/`)
- X11 development libraries: `libX11`, `libXext`

### Compilation

```bash
# Compile miniLibX first (required once)
make -C minilibx-linux

# Compile the project
make

# Recompile from scratch
make re

# Clean objects
make clean

# Full clean (objects + binary)
make fclean
```

### Execution

```bash
./cub3D maps/simple.cub
./cub3D maps/complex.cub
```

### Map format (.cub)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 50,100,150
C 200,200,200

111111
10N001
100001
111111
```

- `NO/SO/WE/EA` : paths to XPM wall textures
- `F R,G,B` : floor color (0–255 each channel)
- `C R,G,B` : ceiling color (0–255 each channel)
- Map characters: `1` = wall, `0` = empty, `N/S/E/W` = player spawn + orientation
- Map must be closed (surrounded by walls), player must appear exactly once
- Map must be the last element in the file

### Controls

| Key | Action |
|-----|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Quit |

## Resources

### Ray-casting references
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — main reference for DDA algorithm and texture mapping
- [miniLibX Linux documentation](https://harm-smits.github.io/42docs/libs/minilibx) — mlx functions reference
- [Wolfenstein 3D original source code](https://github.com/id-Software/wolf3d) — historical reference

### AI usage
Claude (Anthropic) was used during this project for the following tasks:
- Reviewing and correcting memory management (detecting leaks and undefined behavior)
- Explaining the DDA raycasting algorithm step by step and helping translate it into correct C code
- Reviewing the flood-fill validation and replacing the recursive version with an iterative stack-based implementation to avoid stack overflow on large maps
- Identifying edge cases in the `.cub` parser (duplicate identifiers, multiple spaces, identifiers after map start)
- Generating the structure of this README

All AI-generated code was reviewed, tested, and understood by the team before integration.
