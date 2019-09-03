#include "voterrecord.h"
#include "voterlist.h"



void Menu();



int main() {



	

	Menu();



	system("pause");
	return 0;

}



//menu for different options
void Menu()
{
	
	VoterList add;
	add.fillVector();
	
	
	char response = 'y';

	
	while (response == 'y') {

		cout << "What choice would you like to make? " << endl;

		cout << "1. query a voters record given the voters ID" << endl;
		cout << "2. add a new voters record and print the receipt" << endl;
		cout << "3. modify a voters record given the voters ID and print the modified receipt" << endl;
		cout << "4. print the voting statistics to the screen" << endl;
		
		cout << "5. print the sorted list of voter records" << endl;



		char choice;
		cin >> choice;


		switch (choice)
		{
		case '1':

			add.query();
			
			break;

		case '2': //add voters to the vector

			add.addNewVotes();

			break;

		case '3':
			add.modifyVote();
			break;

		case '4':
			add.voterStats();
			break;

		case '5':
			//outputs everything in the file
			add.printVector();

			break;
		}
		cout << "What would you like to continue? (y/n)" << endl;
		cout << "Press y to continue or press n to exit" << endl;
		cin >> response;
		system("cls");
	}

}
