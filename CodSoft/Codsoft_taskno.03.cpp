#include<iostream>

using namespace std;
void printboard(char board[9])
{
	system("cls");
	cout<<"-----Board View----";
	cout<<"\n\n\n";
	cout<<"\b\b"<<" "<<board[0]<<" "<<"|"<<board[1]<<"  "<<"|"<<board[2]<<endl;
	cout<<"\b\b"<<"---|---|---"<<endl;
	cout<<"\b\b"<<" "<<board[3]<<" "<<"|"<<board[4]<<"  "<<"|"<<board[5]<<endl;;
	cout<<"\b\b"<<"---|---|---"<<endl;
	cout<<"\b\b"<<" "<<board[6]<<" "<<"|"<<board[7]<<"  "<<"|"<<board[8]<<endl;
}
bool inline playerOneWin(char board1[])
{	
	if((board1[0]=='X')&&(board1[1]=='X')&&(board1[2]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[3]=='X')&&(board1[4]=='X')&&(board1[5]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[6]=='X')&&(board1[7]=='X')&&(board1[8]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[0]=='X')&&(board1[3]=='X')&&(board1[6]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[1]=='X')&&(board1[4]=='X')&&(board1[7]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[2]=='X')&&(board1[5]=='X')&&(board1[8]=='X'))
	{
		cout << "Player X Wins!";
		
	}
	else if((board1[0]=='X')&&(board1[4]=='X')&&(board1[8]=='X'))
	{
		cout << "Player X Wins!"; 
		
	}
	else if((board1[2]=='X')&&(board1[4]=='X')&&(board1[6]=='X'))
	{
	
		cout << "Player X Wins!"; 
	}
	else 
	return false;
	return true;
}
		


bool inline playerTwoWin(char board1[])
{	
	if((board1[0]=='O')&&(board1[1]=='O')&&(board1[2]=='O'))
	{
		cout << "Player O Wins!"; 
	
	}
	else if((board1[3]=='O')&&(board1[4]=='O')&&(board1[5]=='O'))
	{
		cout << "Player O Wins!"; 
		
	}
	else if((board1[6]=='O')&&(board1[7]=='O')&&(board1[8]=='O'))
	{
		cout << "Player O Wins!";
		
	}
	else if((board1[0]=='O')&&(board1[3]=='O')&&(board1[6]=='O'))
	{
		cout << "Player O Wins!"; 
		
	}
	else if((board1[1]=='O')&&(board1[4]=='O')&&(board1[7]=='O'))
	{
		cout << "Player O Wins!";
		
	}
	else if((board1[2]=='O')&&(board1[5]=='O')&&(board1[8]=='O'))
	{
		cout << "Player O Wins!"; 
		
	}
	else if((board1[0]=='O')&&(board1[4]=='O')&&(board1[8]=='O'))
	{
		cout << "Player O Wins!"; 
		
	}
	else if((board1[2]=='O')&&(board1[4]=='O')&&(board1[6]=='O'))
	{
	
		cout << "Player O Wins!"; 
	
}
else
    return false;
    
	return true;
}
void inputgame(char board2[])
{
	
	char inputchar;
	int position;
	cout<<"Enter Input:\n";
	int turn;
	for( turn=0; turn<9; ++turn)
	{
		cout<<"Enter Position in input at from 1 to 9:";
		cin>>position;
		cout<<"\nX or O: ";
		cin>>inputchar;
		board2[position-1]=inputchar;
		printboard(board2);
		if(playerOneWin(board2))
		{
		
		break;
	}
		else if(playerTwoWin(board2))
		{
		
		break;
	}
	

	}
		if(turn==9)
	{
		cout<<"\nIt's a Draw";
	}
}
int main()
{
	cout<<"------------Tic-Tac-Toe-----------";
	cout<<"\n\n\nWelcome!!!!";
	cout<<"\nPlayer=X\nPlayer=O\n";
	cout<<"Note: Use Capital X and O";

	
	char consent;
	do{
			char grid[9]=
	{
	' ',' ',' ',
	' ',' ',' ',
	' ',' ',' '
	};
	
		sleep(2);
	
		printboard(grid);
		
		inputgame(grid);
	cout<<"\n\nDo you want to Continue (y/Y) or press 'Q' for Exit:";
	cin>>consent;
	if(consent=='Q')
	break;
}
while ((consent=='Y')||(consent=='y'));
		
	

	return 0;
	
	
}
