#include "Game.h"
#include <iostream>
#include <math.h>

Game::Game(int startBoard)
{
  if (startBoard == 1)
    {
        arr[20][10] = 1;
        arr[20][11] = 1;
        arr[20][12] = 1;

    }
    elseif (startBoard == 2)
    {
        arr[20][10] = 1;
        arr[21][11] = 1;
        arr[21][12] = 1;
        arr[20][12] = 1;
        arr[19][12] = 1;
    }
    elseif (startBoard == 3)
    {
        //??
    }
}

void Game::printBoard()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            if (arr[i][j] == 1) //live cells
                cout << '0';
            else
                cout << ' '; //dead cells
        cout << endl;
    }
}

int Game::getNumLiveNeighbors(int R, int C)
{
    //get total number of live cells in 8 surrounding locations
    int total = 0;

    //look above left
    if (((R-1) >= 0) && ((C-1)>=0))
        if (curr[R-1][C-1] == 1) total++;

    //look straight above
    if ((R - 1) >= 0)
        if (curr[R-1][C] == 1) total++;

    //look above right
    if (((R - 1) >= 0) && ((C + 1) < COLS))
        if (curr[R-1][C+1] == 1) total++;

    //look left
    if ((C - 1) >= 0)
        if (curr[R][C-1] == 1) total++;

    //look right
    if ((C + 1) < COLS)
        if (curr[R][C+1] == 1) total++;

    //look below right
    if (((R + 1) < ROWS) && ((C + 1) < COLS))
        if (curr[R+1][C+1] == 1) total++;

    //look directly below
    if ((R + 1) < ROWS)
        if (curr[R+1][C] == 1) total++;

    //look below left
    if (((R + 1) < ROWS) && ((C - 1) >=0))
        if (curr[R+1][C-1] == 1) total++;

    return total;
}

int Game::play()
// loop to each cell and check neighbors.
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
            int neighbors = getNumLiveNeighbors(i,j);

			// rules for the game of life
			newArr[i][j] = arr[i][j]; //copy the current value into the new array

			//set the new value based on the rules
			if (arr[i][j] == 1 && (neighbors = 1 || neighbors = 0))
			{
				newArr[i][j] = 0;
			}
			else if (arr[i][j] == 1 && neighbors > 3)
			{
				newArr[i][j] = 0;
			}
			else (arr[i][j] == 0 && neighbors = 3)
			{
				newArr[i][j] = 1;
			}
		}
	} //the new board IS the board

	//copy the new board into the current
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
		    arr[i][j] = newArr[i][j];
		}
	}

}
