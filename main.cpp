#include "classes_tic_tac_toe.cpp"
#include "function_tic_tac_toe.cpp"



int main()
{
	int nTurn = 0;
	char gwinner='z';
	string namex;
	string nameo;
	Game game;
    getPlayerNames(namex, nameo);

    while(nTurn<5)
    {
    display_board_format();
    get_player_prompt(namex, 'x');
    check_player_input(game, 'x');
    Board_after_input(game);
    gwinner = game.declare_winner();
    if(gwinner!='z')
    {
    	getGameWinner(game,namex, nameo);
    	Board_after_input(game);
    	break;
    }
    get_player_prompt(nameo, 'o');
    check_player_input(game, 'o');
    Board_after_input(game);
    gwinner = game.declare_winner();
    if(gwinner!='z')
    {
    	getGameWinner(game,namex, nameo);
    	Board_after_input(game);
    	break;
    }
    }nTurn++;
    if(nTurn>=5)
    {
    	cout<<"Tie game"<<"\n\n";
    }
	return 0;
}