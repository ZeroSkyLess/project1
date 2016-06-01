
//Header file
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

//STURCTURE
struct profile
{
	char name[30];
	int mark;
	int mark2;
	
};

struct day
{
	string date;
};

profile intro[3];
day Time;

//function definition
void line()
{
	cout<<  "--------------------------------------------------------------------------\n";
}

//function prototype
void first();		 //main menu
void SG();			//start game	
void GS(int);		//game begin
int RD();			//roll dice
void score(int, int[], int[], int[]);		//after finish game
void HH();			//Help and Hint
void data();
void show();
void rematch();

char FIRST[30];
char SECOND[30];
char THIRD[30];

int *HIGH,
	*MEDIUM,
	*LOW;

int round;

//main function
void main()
{

	char o;

	cout<< "\t\t\t\tXYZ Game\n";
	cout<< "\t\tPress an alphabet to continue, press number to exit: ";
	cin>>o;

	if (isalpha(o))
		first();

}


//function main menu
void first()
{

	int choice;

	cout<< "\n\n\t\t\t\tWELCOME TO XYZ GAME\n";

	line();

	cout<< "\nPlease enter number of menu:\n";
	cout<< "1. Start Game\n";
	cout<< "2. Recently Statistic\n";
	cout<< "3. Help and Hint\n";
	cout<< "4. Quit\n";
	
	do
	{
		cout<< "Please enter your choice : ";
		cin>>choice;
	
		if ( choice == 1 )
		{
			SG();
		}

		else if (choice == 2 )
		{
			show();
		}

		else if ( choice == 3 )
		{
			HH();
		}

		else if ( choice == 4 )
		{
			break;
		}

		else
			cout<< "Please enter a valid number. (1 - 4)\n";

	}while ( choice <= 0 || choice > 4 );
}


//Function start game	
void SG()
{

	int sa;

	cout<< "\nBefore you start a game please enter three player name.";
	cout<< "\nAfter you enter your name, press twice enter to enter next player name.\n\n";
	
	for (int i = 0; i < 3; i++)
	{
		cin.get();
		cout<< i + 1<<"th player, please enter your name : ";
		cin.getline(intro[i].name,30);
	}

	cout<< "\nThe game is begin.\n";
	
	do
	{

		cout<< "Please enter how many round you want to play (1 - 30): ";
		cin>>sa;

		if (sa < 1 || sa >30 || isalpha(sa))
		{

			cout<< " Invalid value ";

		}
	}while (sa < 1 || sa >30 || isalpha(sa));
	
	
	GS(sa);

}

// function game start
void GS(int sa)
{

	int number;
	int p1[30],
		p2[30],
		p3[30];

	string gg;
	int dice;
	int total;
	
	int largest;
	int smallest;

	int highest, 
		medium,
		lowest;

	char highname[30];
	char lowname[30];
	char mediumname[30];

	char aa[30];
	char bb[30];

	intro[0].mark = 0;
	intro[1].mark = 0;
	intro[2].mark = 0;

	for ( int r = 0; r < sa; r++)
	{	
		cout<<endl<< r+1 << "th Round\n";
		
		intro[0].mark2 = 0;
		intro[1].mark2 = 0;
		intro[2].mark2 = 0;

		for (int h = 0; h < 3; h++)
		{
		
			cout<< endl << intro[h].name << "'s turn: \n Do you want to add 0 or 1 to change the result before roll?";

			do
			{
				
				cout<< "\nPlease enter 0 or 1: ";
				cin>>number;

			}while (number < 0 || number > 1);

			cout<< "\nEnter any key to roll your dice: ";
			cin>> gg;
			cout<< endl << endl;

			dice = RD();

			total = dice + number ;

			cout<< "\nThe total after u add the number to the sum of the two dice is "<< total << endl;

			if (total >= 2 && total <= 5)
			{

				cout<< intro[0].name << " get mark "<< endl;

				intro[0].mark += 5;

				intro[0].mark2 += 5;

			}

			else if (total >= 6 && total <= 9)
			{

				cout<< intro[1].name << " get mark "<< endl;

				intro[1].mark += 5;

				intro[1].mark2 += 5;
			}

			else if (total >= 10 && total <= 13)
			{

				cout<< intro[2].name << " get mark "<< endl;

				intro[2].mark += 5;
				
				intro[2].mark2 += 5;

			}

		}
	
		cout<< "\nThe "<< r+1 << "th round was end."<< endl;

		if ( intro[0].mark2 == intro[1].mark2 && intro[0].mark2 == intro[2].mark2)
		{
			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
			
			cout<< "\nAll players get the same marks.\n";
		}

		else if ( intro[0].mark2 == intro[1].mark2)
		{
			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}

			if ( intro[0].mark2 > intro[2].mark2)
			{
				cout<< endl << intro[0].name << " and " << intro[1].name << " got the same mark \n";
				cout<< endl << intro[2].name << " has the lowest mark for this game\n";
				cout<< endl << intro[0].name << " and " << intro[1].name << " are the winner for this game\n";
			}

			else 
			{
				cout<< endl << intro[0].name << " and " << intro[1].name << " got the same mark \n";
				cout<< endl << intro[2].name << " has the highest mark for this game\n";
				cout<< endl << intro[2].name << " is the winner for this game\n";
			}

		}
		
		else if(intro[0].mark2 == intro[2].mark2)
		{
		
			for ( int p = 0; p < 3; p++)
				{
		
					cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

				}
	
			if(intro[0].mark2 > intro[1].mark2)
			{
				cout<< endl << intro[0].name << " and " << intro[2].name << " got the same mark \n";
				cout<< endl << intro[1].name << " has the lowest mark for this game\n";
				cout<< endl << intro[0].name << " and " << intro[2].name << " are the winner for this game\n";
			}

			else 
			{
				cout<< endl << intro[0].name << " and " << intro[2].name << " got the same mark \n";
				cout<< endl << intro[1].name << " has the highest mark for this game\n";
				cout<< endl << intro[1].name << " is the winner for this game\n";
			}
		}

		else if(intro[1].mark2 == intro[2].mark2)
		{

			for ( int p = 0; p < 3; p++)
				{
		
					cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

				}

			if(intro[1].mark2 > intro[0].mark2)
			{
				cout<< endl << intro[1].name << " and " << intro[2].name << " got the same mark \n";
				cout<< endl << intro[0].name << " has the lowest mark for this game\n";
				cout<< endl << intro[1].name << " and " << intro[2].name << " are the winner for this game\n";
			}

			else 
			{
				cout<< endl << intro[1].name << " and " << intro[2].name << " got the same mark \n";
				cout<< endl << intro[0].name << " has the highest mark for this game\n";
				cout<< endl << intro[0].name << " is the winner for this game\n";
			}
		}

		else if (intro[0].mark2 == 15 )
		{
			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
			cout<< endl << intro[0].name << " get full marks in this round.\nCongratulation!!\n";
		}

		
		else if (intro[1].mark2 == 15 )
		{
			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
			cout<< endl << intro[1].name << " get full marks in this round.\nCongratulation!!\n";
		}

		else if (intro[2].mark2 == 15 )
		{
			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
			cout<< endl << intro[2].name << " get full marks in this round.\nCongratulation!!\n";
		}


		else
		{
			largest = intro[0].mark2 ;
			smallest = intro[0].mark2;
				
			strcpy_s(aa,intro[0].name);
			strcpy_s(bb,intro[0].name);

			for (int i = 0; i < 3;  i++)
			{

				if ( intro[i].mark2 > largest)
				{
					largest = intro[i].mark2;

					strcpy_s(aa,intro[i].name);
				}
			}


			for (int i = 0; i < 3;  i++)
			{
				if ( intro[i].mark2 < smallest)
				{
					smallest = intro[i].mark2;

					strcpy_s(bb,intro[i].name);
				}
			}

			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
		
			cout << endl <<  aa << " has the highest mark\n";
			cout << bb << " has the lowest mark\n\n";

		}


		p1[r] = intro[0].mark2;
		p2[r] = intro[1].mark2;
		p3[r] = intro[2].mark2;
			
	}

	if(intro[0].mark == intro[1].mark && intro[0].mark == intro[2].mark)
	{

				highest = intro[0].mark;
				medium = intro[1].mark;
				lowest = intro[2].mark;

				strcpy_s(highname,intro[0].name);
				strcpy_s(mediumname,intro[1].name);
				strcpy_s(lowname,intro[2].name);

		score(sa,p1,p2,p3);

		cout<< "\nAll player draw for this game\n";
		cout<< "Thank you for playing\n";
	}

	else if(intro[0].mark == intro[1].mark)
	{
		
				

		score(sa,p1,p2,p3);

		if(intro[0].mark > intro[2].mark)
		{
			highest = intro[0].mark;
			medium = intro[1].mark;
			lowest = intro[2].mark;

			strcpy_s(highname,intro[0].name);
			strcpy_s(mediumname,intro[1].name);
			strcpy_s(lowname,intro[2].name);

			cout<< endl << intro[0].name << " and " << intro[1].name << " got the same mark \n";
			cout<< endl << intro[2].name << " has the lowest mark for this game\n";
			cout<< endl << intro[0].name << " and " << intro[1].name << " are the winner for this game\n";
			cout<< "Thank you for playing\n";
		}

		else 
		{

				highest = intro[2].mark;
				medium = intro[0].mark;
				lowest = intro[1].mark;

				strcpy_s(highname,intro[2].name);
				strcpy_s(mediumname,intro[0].name);
				strcpy_s(lowname,intro[1].name);

			cout<< endl << intro[0].name << " and " << intro[1].name << " got the same mark \n";
			cout<< endl << intro[2].name << " has the highest mark for this game\n";
			cout<< endl << intro[2].name << " is the winner for this game\n";
			cout<< "Thank you for playing\n";
		}
	}

	else if(intro[0].mark == intro[2].mark)
	{
		
		score(sa,p1,p2,p3);

		if(intro[0].mark > intro[1].mark)
		{

			highest = intro[0].mark;
			medium = intro[2].mark;
			lowest = intro[1].mark;

			strcpy_s(highname,intro[0].name);
			strcpy_s(mediumname,intro[2].name);
			strcpy_s(lowname,intro[1].name);

			cout<< endl << intro[0].name << " and " << intro[2].name << " got the same mark \n";
			cout<< endl << intro[1].name << " has the lowest mark for this game\n";
			cout<< endl << intro[0].name << " and " << intro[2].name << " are the winner for this game\n";
			cout<< "Thank you for playing\n";
		}

		else 
		{
			
			highest = intro[1].mark;
			medium = intro[0].mark;
			lowest = intro[2].mark;

			strcpy_s(highname,intro[1].name);
			strcpy_s(mediumname,intro[0].name);
			strcpy_s(lowname,intro[2].name);

			cout<< endl << intro[0].name << " and " << intro[2].name << " got the same mark \n";
			cout<< endl << intro[1].name << " has the highest mark for this game\n";
			cout<< endl << intro[1].name << " is the winner for this game\n";
			cout<< "Thank you for playing\n";
		}
	}

	else if(intro[1].mark == intro[2].mark)
	{

		score(sa,p1,p2,p3);

		if(intro[1].mark > intro[0].mark)
		{
			highest = intro[1].mark;
			medium = intro[2].mark;
			lowest = intro[0].mark;

			strcpy_s(highname,intro[1].name);
			strcpy_s(mediumname,intro[2].name);
			strcpy_s(lowname,intro[0].name);

			cout<< endl << intro[1].name << " and " << intro[2].name << " got the same mark \n";
			cout<< endl << intro[0].name << " has the lowest mark for this game\n";
			cout<< endl << intro[1].name << " and " << intro[2].name << " are the winner for this game\n";
			cout<< "Thank you for playing\n";
		}

		else 
		{

			highest = intro[0].mark;
			medium = intro[1].mark;
			lowest = intro[2].mark;

			strcpy_s(highname,intro[0].name);
			strcpy_s(mediumname,intro[1].name);
			strcpy_s(lowname,intro[2].name);

			cout<< endl << intro[1].name << " and " << intro[2].name << " got the same mark \n";
			cout<< endl << intro[0].name << " has the highest mark for this game\n";
			cout<< endl << intro[0].name << " is the winner for this game\n";
			cout<< "Thank you for playing\n";
		}
	}

	
		else if (intro[0].mark == 45 )
		{

			highest = intro[0].mark;
			medium = intro[1].mark;
			lowest = intro[2].mark;

			strcpy_s(highname,intro[0].name);
			strcpy_s(mediumname,intro[1].name);
			strcpy_s(lowname,intro[2].name);

			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark << " mark in this round.\n";

			}
			cout<< endl << intro[0].name << " get full marks in this round.\nCongratulation!!\n";
		}

		
		else if (intro[1].mark == 45 )
		{

			highest = intro[1].mark;
			medium = intro[0].mark;
			lowest = intro[2].mark;

			strcpy_s(highname,intro[1].name);
			strcpy_s(mediumname,intro[0].name);
			strcpy_s(lowname,intro[2].name);

			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark << " mark in this round.\n";

			}
			cout<< endl << intro[1].name << " get full marks in this round.\nCongratulation!!\n";
		}

		else if (intro[2].mark == 45 )
		{

			highest = intro[2].mark;
			medium = intro[0].mark;
			lowest = intro[1].mark;

			strcpy_s(highname,intro[2].name);
			strcpy_s(mediumname,intro[0].name);
			strcpy_s(lowname,intro[1].name);

			for ( int p = 0; p < 3; p++)
			{
		
				cout<< intro[p].name << " got " << intro[p].mark2<< " mark in this round.\n";

			}
			cout<< endl << intro[2].name << " get full marks in this round.\nCongratulation!!\n";
		}

	else
	{
		highest = intro[0].mark;
		medium = intro[0].mark;
		lowest = intro[0].mark;

		strcpy_s(highname,intro[0].name);
		strcpy_s(mediumname,intro[0].name);
		strcpy_s(lowname,intro[0].name);

		for ( int q = 0; q < 3; q++)
		{

			if( highest < intro[q].mark)
			{

				highest = intro[q].mark;
				strcpy_s(highname,intro[q].name);

			}

		}
	
		for ( int q = 0; q < 3; q++)
		{
			if( lowest > intro[q].mark  )
			{

				lowest = intro[q].mark;
				strcpy_s(lowname,intro[q].name);

			}

		}

		for ( int q = 0; q < 3; q++)
		{ 
			
			if (intro[q].mark < highest && intro[q].mark > lowest)
			{

					medium = intro[q].mark;
	
					strcpy_s(mediumname,intro[q].name);

			}
		}
		
		score(sa,p1,p2,p3);

		cout<< endl << highname << " got the highest mark " << endl 
			<< mediumname << " got the second highest " << endl 
			<< lowname << " has the lowest mark "<< endl;

		cout<< "\nThank you for playing\n";
		
	}

		HIGH = &highest; 
		MEDIUM = &medium;
		LOW = &lowest;

		strcpy_s(FIRST,highname);
		strcpy_s(SECOND,mediumname);
		strcpy_s(THIRD,lowname);

		round = sa;

		data();
		rematch();
}
	
//Function roll dice
int RD()
{

	int d1,
		d2;

	srand((unsigned)time(NULL));

	d1 = rand()% 6 + 1;

	d2 = rand()% 6 + 1;

	if ( d1 == 1 || d2 == 1)
	{

		cout<< "_________"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|_______|"<<endl;

	}

	if ( d1 == 2 || d2 == 2)
	{

		cout<< "_________"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|_______|"<<endl;

	}

	if ( d1 == 3 || d2 == 3)
	{

		cout<< "_________"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|_______|"<<endl;

	}

	if ( d1 == 4 || d2 == 4)
	{

		cout<< "_________"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|_______|"<<endl;

	}

	if ( d1 == 5 || d2 == 5)
	{

		cout<< "_________"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "|   o   |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|_______|"<<endl;

	}

	if ( d1 == 6 || d2 == 6)
	{

		cout<< "_________"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|       |"<<endl;
		cout<< "| o   o |"<<endl;
		cout<< "|_______|"<<endl;

	}

	cout<< "\ndice 1 = " << d1 << "\ndice 2 = " << d2 <<endl;

	return (d1 + d2);

}

void score(int sa, int p1[], int p2[], int p3[])
{

	cout << "\nThe total score:\n";

	cout << right << setw(20) << intro[0].name << right << setw(10) << intro[1].name
		 << right << setw(10) << intro[2].name <<endl;

	for (int w = 0; w < sa; w++) 
	{
		cout  << endl <<  w + 1 << left << setw(10) << "th round : " ;

		cout << right << setw(10) << p1[w] << right << setw(9) 
			<< p2[w] << right << setw(9) << p3[w];
				 
	}

	cout << endl << right << setw(11) << "Total :" << right << setw(11) << intro[0].mark << right << setw(9) << intro[1].mark
		 << right << setw(9) << intro[2].mark <<endl<<endl;

}


//function help and hint
void HH()
{
	char yn;

	cout<< "\n\nRole: ";
	cout<< "\n1.	This game only consists 3 players.";
	cout<< "\n2.	Players will roll the dices alternately.";
	cout<< "\n3.	Players can choose to add either 0 or 1.";
	cout<< "\n4.	If  the sum of number of two dices and after adding the digit number choosen is between 2-5, ";
	cout<< "the player1 will get 5 marks, if between 6-9, player2 will get the marks, if between 10-13, player3 will get the marks.";
	cout<< "\n5.	Make sure the sum is in your limits to get the marks, otherwise it will be given to the other player.";
	cout<< "\n6.	Player 1 will start 1st.\n";

	cout<< "\nBack to menu?  (Press Y or y if Yes - N or n if no) :";
	cin>>yn;

	

	switch(yn)
	{
		case 'y' :
		case 'Y' : first();
					 break;

		case 'N' :
		case 'n' :	main();	
					break;
	}
}

void data()
{

	ofstream saveFile;
	
	cout<< "\n\nEnter today date : ";
	cin>>Time.date;

	saveFile.open("Satistic.txt", ios::out | ios::app);

	saveFile<< endl << Time.date << endl << round << endl << FIRST << "\t" << *HIGH << endl 
		<< SECOND << "\t" << *MEDIUM << endl << THIRD << "\t" << *LOW << endl;

	saveFile.close();
	show();

}

void show()
{
	ifstream File;

	cout<< endl;

	File.open("Satistic.txt", ios::in | ios::app);

	cout<< "\n\t\t\tSATISTIC\n\n";

	if(!File)
	cout<< "\nFile does not exist\n";

	
	
	else
	{
	

			cout<< right << setw(50) << "Player's name" << right << setw(20) << "Score\n";
			line();

			cout<< "Date : " << Time.date << endl << "Playing round : " << round << endl;
			cout<< left << setw(20) << "First (Winner) : "<< right << setw(30) << FIRST << right << setw(20) << *HIGH << endl;
			cout<< left << setw(20) << "Second : "<< right << setw(30) << SECOND << right << setw(20) << *MEDIUM << endl;
			cout<< left << setw(20) << "Third : "<< right << setw(30) << THIRD << right << setw(20) << *LOW << endl;
			
		
	}

	File.close();
	

}

void rematch()
{
	int ch;
		
	cout<< "\nDo you want replay?  (Press Y or y if Yes - N or n if no) :";
	cin>>ch;
	

	switch(ch)
	{
		case 'y' :
		case 'Y' : main();
					 break;

		case 'N' :
		case 'n' :	first();	
					break;
	}
}