//
//  main.cpp
//  ConwaysGameOfLife
//
//  Created by Baolinh Nguyen on 9/16/17.
//  Copyright © 2017 Baolinh Nguyen. All rights reserved.
//

const int ROWS = 10;
const int COLS = 10;

#include <iostream>
#include <cmath>

using namespace std;

class gameOfLife
{
public:
    gameOfLife(int r);
    void play();
    
private:
    int rounds;
    const int rows = ROWS;
    const int cols = COLS;
    int board[ROWS][10];
    int checkNeighbors(int r, int c);
    void transition();
    void display(int r);
};

gameOfLife::gameOfLife(int r)
{
    rounds = r+1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int r = rand() % 100 + 1;
            if (r%2 == 0)
                board[i][j] = 1;
            else
                board[i][j] = 0;
            if (r%3 == 0)
                board[i][j] = 1;
        }
    }
    display(0);
}

void gameOfLife::play()
{
    for (int i = 0; i < rounds; i++)
    {
        transition();
        display(i);
    }
}

void gameOfLife::transition()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int n = checkNeighbors(i, j);
            if (board[i][j] == 1 && (n == 2 || n == 3))
            {
                board[i][j] = board[i][j] | 2;
            }
            if (board[i][j] == 0 && n == 3)
            {
                board[i][j] = board[i][j] | 2;
            }
        }
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            
        {
            board[i][j] = board[i][j] >> 1;
        }
    }
}

int gameOfLife::checkNeighbors(int r, int c)
{
    int n = 0;
    //north
    if (r > 0)
    {
        if ((board[r-1][c]&1) == 1)
            n++;
    }
    //northwest
    if (r > 0 && c > 0)
    {
        if ((board[r-1][c-1]&1) == 1)
            n++;
    }
    //west
    if (c > 0)
    {
        if ((board[r][c-1]&1) ==1)
            n++;
    }
    //southwest
    if (c > 0 && r < (rows-1))
    {
        if ((board[r+1][c-1]&1) ==1)
            n++;
    }
    //south
    if (r < (rows-1))
    {
        if ((board[r+1][c]&1) == 1)
            n++;
    }
    //southeast
    if (r < (rows-1) && c < (cols-1))
    {
        if ((board[r+1][c+1]&1) == 1)
            n++;
    }
    //east
    if (c < (cols-1))
    {
        if ((board[r][c+1]&1) == 1)
            n++;
    }
    //northeast
    if (c < (cols-1) && r > 0)
    {
        if ((board[r-1][c+1]&1) == 1)
            n++;
    }
    return n;
}

void gameOfLife::display(int r)
{
    cout << "---CURRENT ROUND #: " << r+1 << "---" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    gameOfLife game1(9);
    game1.play();
}
