#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace  std;

class Game
{
public:
	Game();
	char* getBoard(void);
	int setBoard(int pos, char player);
	char check_Rows();
	char check_Columns();
	char check_Diagonals();
	char declare_winner();
	
private:
       char positionSelected[9];
};

Game::Game()
{
	int i;
	for (i=0;i<9;i++)
	{
		positionSelected[i] = '_';
	}
}


char* Game::getBoard(void) 
{
	return positionSelected;
	
}

int Game::setBoard(int pos, char player)
{
	if(positionSelected[pos]=='_')
	{
		positionSelected[pos]=player;
	    return 0;
	}
	else
	{
		return -1;
	}
  return 0;   
}

char Game::check_Rows()
{
  int row;
  int col;
  int rowx;
  int rowo;
  int N = 3;
  for (row = 0; row<3; row++)
    {
      for (col=0;col<3;col++)
      {
      	if(positionSelected[row*N+col]=='x')
      		rowx++;
      	if(positionSelected[row*N+col]=='o')
      		rowo++;
      }
    if(rowx==3)
  	    return 'x';
  	if(rowo==3)
  	    return 'o';
  	rowx =0;
  	rowo =0;

    }
    return 'z';
}

char Game::check_Columns()
{
  int row;
  int col;
  int colx;
  int colo;
  int N = 3;

  for (row = 0; row<3;row++)
  {
  	for (col = 0; col<3;col++)
  	{
  		if(positionSelected[N*col+row]=='x')
  			colx++;
  		if(positionSelected[N*col+row]=='o')
  			colo++;
  	}	
  	if(colx==3)
  	    return 'x';
  	if(colo==3)
  	    return 'o';
  	colx =0;
  	colo =0;
  		
  }
  return 'z';
}

char Game::check_Diagonals()
{    
	int l;
	int r;
	int diax;
	int diao;
  int N = 3;
	for(l = 0; l<3;l++)
	{
		if(positionSelected[N*l+l]=='x')
			diax++;
		if(positionSelected[N*l+l]=='o')
			diao++;

	}
	if(diao!=3 and diax!=3)
	{
	for (r=1;r<4;r++)
	{
		if(positionSelected[N*r-r]=='x')
			diax++;
		if(positionSelected[N*r-r]=='o')
			diao++;
	}

   }
    if(diax==3)
   	 return 'x';
   	else if(diao==3)
   		return 'o';
   	else
   		return 'z';

}

char Game::declare_winner()
{
  char winner;
  winner = check_Rows();
  if(winner=='z')
  	winner=check_Columns();
  if(winner=='z')
  	winner=check_Diagonals();
  return winner;
}

