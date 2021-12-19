#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

void getPlayerNames(string &, string &);
void display_board_format();
void Board_after_input();
int get_player_input();
void check_player_input();
void getGameWinner();
void get_player_prompt(string,char);



void getPlayerNames(string &x, string &y)
{
	cout << "name player to be X:" <<endl;
	cin >> x;
	cout << "name player to be o:"<<endl;
	cin >> y;

}

void display_board_format()
{
int N = 3;
int i,j;
cout <<"This is the format of board:"<<endl;
for (i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        cout<<i*N+j<<"| ";
        if(i*N+j<=9)
           cout<<" ";
        if((i*N+j+2)%3 == 1) 
         cout<<"\n";         
    }
    cout<<"\n\n";
}

}


void Board_after_input(class Game gm)
{
    cout <<"Your new moved:"<<endl;
    int i,j; 
    int N = 3;
    for (i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
      {
        cout<<gm.getBoard()[i*N+j]<<"| ";
        if(i*N+j<=9)
           cout<<" ";
        if((i*N+j+2)%3 == 1) 
         cout<<"\n";         
    }
    cout<<"\n\n";
}
}

int get_player_input()
{
  int pos;
  cout <<"Enter an integer between 0 and 9;"<<"\n";
  cin>>pos;
  while(pos > 9 or pos < 0)
  {
    cin.clear();
    cout <<"Enter the valid integer between 0 and 9"<<"\n";
    cin.clear();
    cin>>pos;
  }
  return pos;
}

void check_player_input(class Game &bg, char player)
{
    int pos;
    int check;
    do
    {
        pos = get_player_input();
        check = bg.setBoard(pos,player);
        if (check==-1)
        {
            cout<<"That position is occupied";
        }
    } while(check==-1);
}

void getGameWinner(class Game gb,string x, string y)
{
  char winner;
  winner = gb.declare_winner();
  if(winner=='x')
    cout<<"Congrats "<<x<<" you won!\n\n";
  if(winner=='o')
    cout<<"Congrats "<<y<<" you won!\n\n";
}

void get_player_prompt(string namein, char letter)
{
  cout<<namein<<" where would you like to place an " <<letter<<"?";
  cout<<"\n";
}