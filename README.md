# Terminal Snake in C

## Table of Contents
+ [About](#about)
+ [Getting Started](#getting_started)
+ [Usage](#usage)

## About <a name = "about"></a>
This project is a terminal-based implementation of the classic Snake game, written in C. The purpose of this project is to create a fun, nostalgic game that can be played directly from the terminal. It also serves as a simple example for those learning C programming and wanting to understand the basics of game development.

## Getting Started <a name = "getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need the following software to run the game:

* GCC (GNU Compiler Collection)
* Make (optional, for ease of compilation)
* You can install them using the following commands:

For GCC:

```
sudo apt-get update
sudo apt-get install gcc
```
For Make:

```
sudo apt-get install make
```

### Installing

Follow these steps to set up the development environment:

1. Clone the repository
  ```
  git clone https://github.com/patryksztuczka/snake-c.git
  cd snake-c
  ```
2. Compile the game
  If you have Make installed, simply run:
  ```
  make
  ```
  Alternatively, you can compile the game using GCC directly:
  ```
  gcc -o snake snake.c
  ```
3. Run the game
  ```
  ./snake
  ```

Once you run ./snake, you can control the snake using the WSAD keys. The objective is to eat the food that appears randomly on the screen without colliding with the walls or the snake itself. 

## Usage <a name = "usage"></a>

To use the system, simply run the executable file as shown in the installation steps. Use the WSAD keys to navigate the snake. The game will display your score based on the number of food items the snake has consumed. The game ends when the snake collides with itself or the boundaries of the terminal window.
