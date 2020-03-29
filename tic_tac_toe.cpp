#include<iostream>
#include<unistd.h>
#include<stdio.h>
using namespace std;


class game
{
	int **number;
	char **value;

	public:
	game()
	{
		number=new int*[3];
		value=new char*[3];
		for(int i=0;i<3;i++)
		{
			number[i]=new int[3];
			value[i]=new char[3];
		}
		int count=1;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				number[i][j]=count;
				value[i][j]=' ';
				count++;
			}
		}
	}


	~game()
	{
		for(int i=0;i<3;i++)
		{
			delete [] number[i];
			delete [] value[i];
		}

		delete number;
		delete value;
	}

	void display_board();
	void demo();

	void one_player();
	void two_player();

	int check_win(int,char);

};	

void game::display_board()
{
	cout<<"\n\t\t "<<value[0][0]<<"  |  "<<value[0][1]<<"  |  "<<value[0][2]<<"\t\t\n";
	cout<<"\t\t----------------\t\t\n";
	cout<<"\t\t "<<value[1][0]<<"  |  "<<value[1][1]<<"  |  "<<value[1][2]<<"\t\t\n";
	cout<<"\t\t----------------\t\t\n";
	cout<<"\t\t "<<value[2][0]<<"  |  "<<value[2][1]<<"  |  "<<value[2][2]<<"\t\t\n";
	
}	

void game::demo()
{
	cout<<"\n\t\t "<<number[0][0]<<"  |  "<<number[0][1]<<"  |  "<<number[0][2]<<"\t\t\n";
        cout<<"\t\t----------------\t\t\n";
        cout<<"\t\t "<<number[1][0]<<"  |  "<<number[1][1]<<"  |  "<<number[1][2]<<"\t\t\n";
        cout<<"\t\t----------------\t\t\n";
        cout<<"\t\t "<<number[2][0]<<"  |  "<<number[2][1]<<"  |  "<<number[2][2]<<"\t\t\n";
}

int game::check_win(int last_turn,char who )
{
	if(who == 'X')
	{
		switch(last_turn)
		{
			case 1:
				if( value[0][0]=='X' && value[0][1]=='X' && value[0][2]=='X')
					return 1;
				else if( value[0][0]=='X' && value[1][1]=='X' && value[2][2]=='X')
					return 1;
				else if( value[0][0]=='X' && value[1][0]=='X' && value[2][0]=='X')
					return 1;
				else
					return 0;
				break;

			case 2:
				if( value[0][1]=='X' && value[0][0]=='X' && value[0][2]=='X')
					return 1;
				else if( value[0][1]=='X' && value[1][1]=='X' && value[2][1]=='X')
					return 1;
				else 
					return 0;
				break;

			case 3:
				if( value[0][0]=='X' && value[0][1]=='X' && value[0][2]=='X')
					return 1;
				else if ( value[0][2]=='X' && value[1][2]=='X' && value[2][2]=='X')
					return 1;
				else if( value[0][2]=='X' && value[1][1]=='X' && value[2][0]=='X')
					return 1;
				else
					return 0;
				break;

			case 4:
				if( value[0][0]=='X' && value[1][0]=='X' && value[2][0]=='X')
					return 1;
				else if ( value[1][0]=='X' && value[1][1]=='X' && value[1][2]=='X')
					return 1;
				else
					return 0;
				break;
				
			case 5:
				if( value[1][0]=='X' && value[1][1]=='X' && value[1][2]=='X')
					return 1;
				else if( value[0][1]=='X' && value[1][1]=='X' && value[2][1]=='X')
					return 1;
				else
					return 0;
				break;

			case 6:
				if ( value[0][2]=='X' && value[1][2]=='X' && value[2][2]=='X')
					return 1;
				else if( value[1][0]=='X' && value[1][1]=='X' && value[1][2]=='X')
					return 1;
				else
					return 0;
				break;

			case 7:
				if( value[0][0]=='X' && value[1][0]=='X' && value[2][0]=='X')
					return 1;
				else if( value[2][0]=='X' && value[2][1]=='X' && value[2][2]=='X')
					return 1;
				else if( value[0][2]=='X' && value[1][1]=='X' && value[2][0]=='X')
					return 1;
				else
					return 0;
				break;

			case 8:
				if( value[0][1]=='X' && value[1][1]=='X' && value[2][1]=='X')
					return 1;
				else if( value[2][0]=='X' && value[2][1]=='X' && value[2][2]=='X')
					return 1;
				else
					return 0;
				break;


			case 9:
				if( value[0][2]=='X' && value[1][2]=='X' && value[2][2]=='X')
					return 1;
				else if( value[0][0]=='X' && value[1][1]=='X' && value[2][2]=='X')
					return 1;
				else if( value[2][0]=='X' && value[2][1]=='X' && value[2][2]=='X')
					return 1;
				else
					return 0;
				break;

			default: cout<<"error";
		}
	}
	else
	{
		switch(last_turn)
		{
			case 1:
				if( value[0][0]=='O' && value[0][1]=='O' && value[0][2]=='O')
					return 1;
				else if( value[0][0]=='O' && value[1][1]=='O' && value[2][2]=='O')
					return 1;
				else if( value[0][0]=='O' && value[1][0]=='O' && value[2][0]=='O')
					return 1;
				else
					return 0;
				break;

			case 2:
				if( value[0][1]=='O' && value[0][0]=='O' && value[0][2]=='O')
					return 1;
				else if( value[0][1]=='O' && value[1][1]=='O' && value[2][1]=='O')
					return 1;
				else
					return 0;
				break;

			case 3:
				if( value[0][0]=='O' && value[0][1]=='O' && value[0][2]=='O')
					return 1;
				else if ( value[0][2]=='O' && value[1][2]=='O' && value[2][2]=='O')
					return 1;
				else if( value[0][2]=='O' && value[1][1]=='O' && value[2][0]=='O')
					return 1;
				else
					return 0;
				break;

			case 4:
				if( value[0][0]=='O' && value[1][0]=='O' && value[2][0]=='O')
					return 1;
				else if ( value[1][0]=='O' && value[1][1]=='O' && value[1][2]=='O')
					return 1;
				else
					return 0;
				break;

			case 5:
				if( value[1][0]=='O' && value[1][1]=='O' && value[1][2]=='O')
					return 1;
				else if( value[0][1]=='O' && value[1][1]=='O' && value[2][1]=='O')
					return 1;
				else
					return 0;
				break;

			case 6:
				if ( value[0][2]=='O' && value[1][2]=='O' && value[2][2]=='O')
					return 1;
				else if( value[1][0]=='O' && value[1][1]=='O' && value[1][2]=='O')
					return 1;
				else
					return 0;
				break;

			case 7:
				if( value[0][0]=='O' && value[1][0]=='O' && value[2][0]=='O')
					return 1;
				else if( value[2][0]=='O' && value[2][1]=='O' && value[2][2]=='O')
					return 1;
				else if( value[0][2]=='O' && value[1][1]=='O' && value[2][0]=='O')
                                        return 1;

				else
					return 0;
				break;

			case 8:
				if( value[0][1]=='O' && value[1][1]=='O' && value[2][1]=='O')
					return 1;
				else if( value[2][0]=='O' && value[2][1]=='O' && value[2][2]=='O')
					return 1;
				else
					return 0;
				break;


			case 9:
				if( value[0][2]=='O' && value[1][2]=='O' && value[2][2]=='O')
					return 1;
				else if( value[0][0]=='O' && value[1][1]=='O' && value[2][2]=='O')
					return 1;
				else if( value[2][0]=='O' && value[2][1]=='O' && value[2][2]=='O')
					return 1;
				else
					return 0;
				break;

			default:
				cout<<"error";
		}
	}
	return 0;
}



void game::one_player()
{
	static int draw=0;
	char *name;
	name=(char*)malloc(20*sizeof(char));
	int turn_1;
	int turn_2;
	int choice;
	char sign_player;
	char sign_cpu;

	cout<<"Enter Player name\n";
	scanf(" %[^\n]s",name);
repeat:
	cout<<"Press 1 to play as X\n";
	cout<<"Press 2 to play as O\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			sign_player='X';
			sign_cpu='O';
			break;
		case 2:
			sign_player='O';
			sign_cpu='X';
			break;
		default:
			cout<<"wrong choice\n";
			goto repeat;
	}


	cout<<"Welcome "<<name<<" you will play as "<<sign_player<<"\n\n";
	cout<<"\n\t\tGAME STARTS\t\t\n";
	cout<<"Demo is shown here\n";
	demo();
	cout<<endl;
	display_board();
	int count=0;

	while(!draw)
	{
		cout<<name<<" ,your turn["<<sign_player<<"]:";
wrong:		cin>>turn_1;
		switch(turn_1)
		{
			case 1: if(value[0][0]==' ')
					value[0][0]=sign_player;
				else
				{
					cout<<"wrong choice,input again";
					goto wrong;
				}
				break;

			case 2: if(value[0][1]==' ')
                                        value[0][1]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
	                        break;

			case 3: if(value[0][2]==' ')
                                        value[0][2]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
        	                break;

			case 4: if(value[1][0]==' ')
                                        value[1][0]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
                	        break;

			case 5: if(value[1][1]==' ')
                                        value[1][1]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
	                        break;

			case 6: if(value[1][2]==' ')
                                        value[1][2]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
                	        break;

			case 7: if(value[2][0]==' ')
                                        value[2][0]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
        	                break;

			case 8: if(value[2][1]==' ')
                                        value[2][1]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
	                        break;

			case 9: if(value[2][2]==' ')
                                        value[2][2]=sign_player;
                                else
                                {
                                        cout<<"wrong choice,input again";
                                        goto wrong;
                                }
                	        break;

			default: cout<<"wrong choice\n";
		}
		display_board();
		if(check_win(turn_1,sign_player)==1)
		{
			cout<<name<<", WINS\n";
			break;
		}

		if(count==4)
		{
			cout<<"MATCH DRAW\n";
			break;
		}

		cout<<"CPU, turn ["<<sign_cpu<<"]:";

randomise:	int random_no=1+(rand()%9);
		switch(random_no)
		{
			case 1:{
				if(value[0][0]!=' ')
					goto randomise;
				else
					break;
			       }
			case 2:{
				if(value[0][1]!=' ')
					goto randomise;
				else
					break;
			       }

			case 3:{
				 if(value[0][2]!=' ')
                                        goto randomise;
				 else
					 break;
			       }
			case 4:{
				 if(value[1][0]!=' ')
                                        goto randomise;
				 else
					 break;
			       }
			case 5:{
				 if(value[1][1]!=' ')
					 goto randomise;
				 else
					 break;
			       }
			case 6:{
				 if(value[1][2]!=' ')
					 goto randomise;
				 else
					 break;
			       }
			case 7:{
				 if(value[2][0]!=' ')
					 goto randomise;
				 else
					 break;
			       }
			case 8:{
				 if(value[2][1]!=' ')
					 goto randomise;
				 else
					 break;
			       }
			case 9:{
				 if(value[2][2]!=' ')
					 goto randomise;
				 else
					 break;
			       }
		}

		usleep(1000000);
		turn_2=random_no;

		switch(turn_2)
        	{
                	case 1:
                        	value[0][0]=sign_cpu;
	                        break;
    	        	case 2:
	                        value[0][1]=sign_cpu;
         	                break;
                	case 3:
                        	value[0][2]=sign_cpu;
                 		break;
                	case 4:
                        	value[1][0]=sign_cpu;
                        	break;
                	case 5:
                        	value[1][1]=sign_cpu;
                        	break;
                	case 6:
                        	value[1][2]=sign_cpu;
                        	break;
               		case 7:
                        	value[2][0]=sign_cpu;
                        	break;
                	case 8:
                        	value[2][1]=sign_cpu;
                        	break;
                	case 9:
                        	value[2][2]=sign_cpu;
                        	break;
                	default:
                        	cout<<"wrong choice\n";
        	}
		display_board();

		if(check_win(turn_2,sign_cpu)==1)
		{
			cout<<"YOU LOST\n";
			break;
		}
		count++;
	}


}




void game::two_player()
{
	int draw=0;
	char **name;
	name=new char*[2];
	name[0]=new char[50];
	name[1]=new char[50];
	int turn_1=0;
	int turn_2=0;
	cout<<"Enter the Player 1 Name\n";
	cin>>name[0];
        cout<<"Enter the Player 2 Name\n";
        cin>>name[1];
	cout<<endl;
	cout<<"welcome "<<name[0]<<" you are X"<<endl;
	cout<<"welcome "<<name[1]<<" you are O"<<endl;
	cout<<"\n\t\t Game Start\t\t\n";
	cout<<"Demo is shown her\n";
	demo();
	cout<<endl;
	display_board();
	int count=0;
	while(!draw)
	{
		cout<<name[0]<<" ,your turn[X]:";
		cin>>turn_1;
		switch(turn_1)
		{
			case 1: value[0][0]='X';
				break;
			case 2: value[0][1]='X';
	                        break;
			case 3: value[0][2]='X';
        	                break;
			case 4: value[1][0]='X';
                	        break;
			case 5: value[1][1]='X';
	                        break;
			case 6: value[1][2]='X';
                	        break;
			case 7: value[2][0]='X';
        	                break;
			case 8: value[2][1]='X';
	                        break;
			case 9: value[2][2]='X';
                	        break;
			default: cout<<"wrong choice\n";
		}
		display_board();
		if(check_win(turn_1,'X')==1)
		{
			cout<<name[0]<<", WINS\n";
			break;
		}

		if(count==4)
		{
			cout<<"MATCH DRAW\n";
			break;
		}

		cout<<name[1]<<" ,your turn [O]:";
		cin>>turn_2;
		switch(turn_2)
        	{
                	case 1:
                        	value[0][0]='O';
	                        break;
    	        	case 2:
	                        value[0][1]='O';
         	                break;
                	case 3:
                        	value[0][2]='O';
                 		break;
                	case 4:
                        	value[1][0]='O';
                        	break;
                	case 5:
                        	value[1][1]='O';
                        	break;
                	case 6:
                        	value[1][2]='O';
                        	break;
               		case 7:
                        	value[2][0]='O';
                        	break;
                	case 8:
                        	value[2][1]='O';
                        	break;
                	case 9:
                        	value[2][2]='O';
                        	break;
                	default:
                        	cout<<"wrong choice\n";
        	}
		display_board();

		if(check_win(turn_2,'O')==1)
		{
			cout<<name[1]<<", WINS\n";
			break;
		}
		count++;
	}


}


int main()
{
	game g;
	int choice;

	cout<<"\t\t\tW E L C O M E  T O  T H E  T I C  T A C  T O E  0.0\n";
	cout<<"\tPRESS (1) for 1 PLAYER\n";
	cout<<"\tPRESS (2) for 2 PLAYERS\n";
	cout<<"Enter your choice\n";
	cin>>choice;

	if(choice==2)
	{
		g.two_player();
	}
	else if(choice==1)
	{
		g.one_player();
	}
	else
	{
		cout<<"wrong choice";
	}

}


