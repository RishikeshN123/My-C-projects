#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For sleep() function (Linux/Unix only)

// 2D array board dimensions
#define height 20
#define width 60

// Global loop variables and board declaration
int i,j;
char board[height][width];

// Function to create the boundary and fill the inside with space
void make()
{
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            // Create border using '#' character
            if(i==0 || i==height-1 || j==0 || j==width-1)
                board[i][j]='#';
            else
                board[i][j]=' ';
        }
    }
}

// Function to generate random coordinates within max bounds
int coordinate(int max)
{    
    return rand()%max;
}
    
// Function to randomly place '*' stars on the board
void stars()
{
    for(i=0;i<=30;i++)
    {
        int x=coordinate(height-1);  // Random row
        int y=coordinate(width-1);   // Random column
        if(board[x][y]==' ')         // Place star only on empty space
            board[x][y]='*';        
    }
}

// Function to draw the board and update it periodically
void draw()
{
    // Print the 2D board
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            putchar(board[i][j]);  // Print each character
        }
        putchar('\n');  // Newline after each row
    }
    
    // Wait 1 second before next frame (animation effect)
    sleep(1);  // Works on Unix/Linux. Use Sleep(1000) in Windows with #include <windows.h>
    
    // Clear the terminal screen
    system("clear");  // For Linux/Unix
    // system("cls"); // Use this line instead for Windows
}

int main()
{
    srand(time(NULL));  // Seed the random generator once at the beginning
    
    // Infinite loop to refresh board continuously
    while(1)
    {
        make();   // Generate frame structure
        stars();  // Place stars
        draw();   // Render the board
    }
    return 0;
}