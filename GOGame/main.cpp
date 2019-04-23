#include "Game.h"
#include <iostream>

const int ROWS = 40;
const int COLS = 20;
const int NUM_GAMES = 50;
int arr[ROWS][COLS];
int newArr[ROWS][COLS];

void setBoard(int startBoard)
{
  if (startBoard == 1)
    {
        arr[20][10] = 1;
        arr[20][11] = 1;
        arr[20][12] = 1;

    }
    else if (startBoard == 2)
    {
        arr[20][10] = 1;
        arr[21][11] = 1;
        arr[21][12] = 1;
        arr[20][12] = 1;
        arr[19][12] = 1;
    }
    else if (startBoard == 3)
    {
        arr[1][10] = 1;
        arr[1][11] = 1;
        arr[2][10] = 1;
        arr[12][8] = 1;
        arr[12][9] = 1;
        arr[12][13] = 1;
        arr[12][14] = 1;
        arr[14][9] = 1;
        arr[14][13] = 1;
        arr[15][10] = 1;
        arr[15][11] = 1;
        arr[15][12] = 1;
        arr[16][10] = 1;
        arr[16][11] = 1;
        arr[16][12] = 1;
        arr[19][13] = 1;
        arr[20][12] = 1;
        arr[20][13] = 1;
        arr[20][14] = 1;
        arr[21][11] = 1;
        arr[21][15] = 1;
        arr[22][13] = 1;
        arr[23][10] = 1;
        arr[23][26] = 1;
        arr[24][10] = 1;
        arr[24][26] = 1;
        arr[25][11] = 1;
        arr[25][15] = 1;
        arr[26][12] = 1;
        arr[26][13] = 1;
        arr[26][14] = 1;
        arr[35][12] = 1;
        arr[35][13] = 1;
        arr[36][12] = 1;
        arr[36][13] = 1;
    }
}

void printBoard()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            if (arr[i][j] == 1) //live cells
                std::cout << '0';
            else
                std::cout << '-'; //dead cells
        std::cout << std::endl << std::endl;
    }
}

int getNumLiveNeighbors(int R, int C)
{
    //get total number of live cells in 8 surrounding locations
    int total = 0;

    //look above left
    if (((R-1) >= 0) && ((C-1)>=0))
        if (arr[R-1][C-1] == 1) total++;

    //look straight above
    if ((R - 1) >= 0)
        if (arr[R-1][C] == 1) total++;

    //look above right
    if (((R - 1) >= 0) && ((C + 1) < COLS))
        if (arr[R-1][C+1] == 1) total++;

    //look left
    if ((C - 1) >= 0)
        if (arr[R][C-1] == 1) total++;

    //look right
    if ((C + 1) < COLS)
        if (arr[R][C+1] == 1) total++;

    //look below right
    if (((R + 1) < ROWS) && ((C + 1) < COLS))
        if (arr[R+1][C+1] == 1) total++;

    //look directly below
    if ((R + 1) < ROWS)
        if (arr[R+1][C] == 1) total++;

    //look below left
    if (((R + 1) < ROWS) && ((C - 1) >=0))
        if (arr[R+1][C-1] == 1) total++;

    return total;
}

void playGame()
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
			if (arr[i][j] == 1 && (neighbors == 1 || neighbors == 0))
			{
				newArr[i][j] = 0;
			}
			else if (arr[i][j] == 1 && neighbors > 3)
			{
				newArr[i][j] = 0;
			}
			else if (arr[i][j] == 0 && neighbors == 3)
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


int main(int argc, char* argv[])
{
	int num = 0;
	int play = 1;
    while (play == 1)
    {
        // play game
        std::cout << "press 1 to play: " << std::endl;
        std::cin >> play;

        if (play != 1)
            return 0;

        // ask for starting shape
        std::cout << "Choose a starting pattern" << std::endl;
        std::cout << "if you want an oscillator press 1; glider press 2; gliderCannon press 3" << std::endl;
        std::cin >> num;

        //begin initialize arrays to all zeros
        int i = 0;
        int j = 0;

        for (i = 0; i < ROWS; i++)
            for (j = 0; j < COLS; j++)
            {
                arr[i][j] = 0;
                newArr[i][j] = 0;
            }
        //end initialize arrays to all zeros

        setBoard(num);
        std::cout << "STARTING BOARD: \n";
        printBoard();

        for (int z = 0; z < NUM_GAMES; z++)
        {
            playGame();
            printBoard();
        }
    }
	return 0;
}
