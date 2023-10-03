//Here's what the code does:Its a Maze runner game
/*
We define a maze as a 2D array with walls, paths, start, and end points.
The player's initial position is set to where the start is.
The displayMaze() function prints the current state of the maze.
The movePlayer() function updates the player's position based on the input move and checks for reaching the endpoint.
The main loop keeps running till the player reaches the end of the maze.
how to play ?
Controls:
Use the W key to move UP.
Use the A key to move LEFT.
Use the S key to move DOWN.
Use the D key to move RIGHT.
Gameplay
At the start, the player (P) will be at the position marked by S.
The game will prompt you for a move. Input your desired direction (W, A, S, or D) and press Enter.
Your player will move in the specified direction if the path is clear (i.e., not blocked by walls).
If you move into a wall, your position remains unchanged.
Continue navigating until you reach the E point, signifying the end of the maze.*/
#include <iostream>
#include <vector>

using namespace std;

// Define the maze dimensions
const int WIDTH = 10;
const int HEIGHT = 10;

// Using characters to represent different elements in the maze
const char WALL = '#';
const char PATH = ' ';
const char START = 'S';
const char END = 'E';
const char PLAYER = 'P';

// Define the initial player position
int playerX = 1;
int playerY = 1;

char maze[HEIGHT][WIDTH] = {
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, START, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, PATH, WALL, WALL, WALL, PATH, PATH, PATH},
    {WALL, WALL, WALL, PATH, WALL, WALL, WALL, PATH, WALL, END},
    {WALL, WALL, WALL, PATH, PATH, PATH, PATH, PATH, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
};

void displayMaze() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(i == playerY && j == playerX) {
                cout << PLAYER;
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

bool movePlayer(char move) {
    int newX = playerX;
    int newY = playerY;
    
    switch(move) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: return false;
    }
    
    if(maze[newY][newX] == PATH || maze[newY][newX] == END) {
        playerX = newX;
        playerY = newY;
    }
    
    if(maze[newY][newX] == END) {
        return true; // Player reached the end
    }
    return false;
}

int main() {
    bool gameWon = false;
    while(!gameWon) {
        displayMaze();
        cout << "Move with W (up), A (left), S (down), D (right): ";
        char move;
        cin >> move;
        gameWon = movePlayer(move);
        if(gameWon) {
            displayMaze();
            cout << "Congratulations! You've completed the maze!" << endl;
        }
    }
    return 0;
}
