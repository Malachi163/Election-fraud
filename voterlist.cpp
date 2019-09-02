#include "voterlist.h"

void VoterList::addNewVotes()
{

	string add_vote1, add_vote2, add_vote3, add_vote4;
	string total_vote, add_id;


	std::cout << "Who do you want to vote for " << endl;


	std::cout << "1. VOTE FOR MAYOR" << endl;
	std::cout << "	A. Pincher, Penny" << endl;
	std::cout << "	B. Dover, Skip" << endl;
	std::cout << "	C. Perman, Sue" << endl;
	cin >> add_vote1;

	std::cout << "2. PROP 17" << endl;
	std::cout << "	D. Yes" << endl;
	std::cout << "	E. No" << endl;
	cin >> add_vote2;

	std::cout << "3. MEASURE 1" << endl;
	std::cout << "	F. Yes" << endl;
	std::cout << "	G. No" << endl;
	cin >> add_vote3;

	std::cout << "4. MEASURE 2" << endl;
	std::cout << "	H. Yes" << endl;
	std::cout << "	I. No" << endl;
	cin >> add_vote4;

	total_vote = add_vote1 + add_vote2 + add_vote3 + add_vote4;

	std::cout << total_vote << endl;
	std::cout << "Add the ID: ";
	cin >> add_id;



	//outFS << add_id << endl;
	//outFS << total_vote << endl;



	VoterRecord text(add_id, total_vote);
	myclass.push_back(text);




}

void VoterList::fillVector()
{

	string id, votes;

	ifstream inFS;

	inFS.open("C:\\Users\\Onepi\\Documents\\comp1525\\Demo\\HW1-votes.txt");

	while (!inFS.eof())
	{

		inFS >> id;
		inFS >> votes;
		if (inFS.good()) {

			VoterRecord line(id, votes);
			myclass.push_back(line);
		}

	}


	inFS.close(); //closing the text file
}

void VoterList::printVector()
{


	unsigned int size = myclass.size();

	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << "ID: " << myclass[i].getID() << endl; //outputs the id
		std::cout << "Votes: " << myclass[i].getVote(); // output the votes
		std::cout << endl;
	}
	std::cout << endl;
}

//changes an existing vote within the vector
void VoterList::modifyVote()
{
	string x = myclass.at(0).getVote(); //used to cycle through each row of votes (The first voter will always be at 0)
	string y;// will be used to find and match each sting
	string sel; //The ID # a user will enter for the seach
	char m;//mayor
	char p;//Proposition
	char m1;//Measure 1
	char m2;//Measure 2
	int size = myclass.size();

	cout << "\nPlease enter your 4-digit voter ID\n";
	cin >> sel;

	for (int i = 0; i < size; i++)
	{
		

		if (sel == myclass[i].getID())
		{
			std::cout << myclass[i].getVote();
			std::cout << endl;
	
			//*Testing Purposes* cout << endl << endl << y << endl<<"True\n\n";
			cout << "1. Vote for Mayor\nA. Pintcher, Penny\nB. Dover, Skip\nC. Perman, Sue\n";
			cin >> m;
			cout << "\n2.PROPOSITION 17\nD. Yes\nE. No\n";
			cin >> p;
			cout << "\n3. MEASURE 1\nF. Yes\nG. No\n";
			cin >> m1;
			cout << "\n4. MEASURE 2\nH. Yes\nI. No\n";
			cin >> m2;

			myclass[i].getVote() =  m + p + m1 + m2; //Will change the vector at this location 
			
			
			//myclass[i].getVote() = total;

			cout << "\nNew ID = " << myclass[i].getVote() << endl;


			i = 5;

			break;
		}
		else
		{
			//Testing cout << "\nFalse\n";
			y = "";
		}
	}
	

	if (sel != y)
		cout << "\nCould not find a match\n";
	
	
}

void VoterList::query()
{
	
	int size = myclass.size();
	string query;
	std::cout << size << " voted." << endl; //put how many people voted by getting the size of the vector

	std::cout << "Look up a vote by searching for an ID: ";
	cin >> query; //searches for the voter id



	for (int i = 0; i < size; i++)
	{
		if (query == myclass[i].getID())
		{
			std::cout << myclass[i].getVote();
			std::cout << endl;
		}
	}

}

void VoterList::voterStats()
{


	double pp = 0.0; //Pintcher, Penny
	double ds = 0.0; //Dover, Skip
	double ps = 0.0; //Perman, Sue
	double p17 = 0.0; //PROPOSITION 17
	double n17 = 0.0; //Against PROPOSITION 17
	double m1 = 0.0; // For MEASURE 1
	double n1 = 0.0; //Against MEASURE 1
	double m2 = 0.0; //For MEASURE 2
	double n2 = 0.0; //Against MEASURE 2
	


	for (int i = 0; i < myclass.size(); i++)
	{
		string x = myclass.at(i).getVote(); //used to cycle through each row of votes (The first voter will always be at 0)
		if (x[0] == 'A' || x[0] == 'a')
		{
			pp++;
		}

		if (x[0] == 'B' || x[0] == 'b')
		{
			ds++;
		}

		if (x[0] == 'C' || x[0] == 'c')
		{
			ps++;
		}

		if (x[1] == 'D' || x[0] == 'd')
		{
			p17++;
		}
		if (x[1] == 'E' || x[0] == 'e')
		{
			n17++;
		}

		if (x[2] == 'F' || x[0] == 'f')
		{
			m1++;
		}
		if (x[2] == 'G' || x[0] == 'g')
		{
			n1++;
		}
		if (x[3] == 'H' || x[0] == 'h')
		{
			m2++;
		}
		if (x[3] == 'I' || x[0] == 'i')
		{
			n2++;
		}

	}

	std::cout << "\nPintcher, Penny = " << pp << " Votes (" << (pp / myclass.size() * 100) << "% of the votes)";
	std::cout << "\nDover, Skip = " << ds << " Votes (" << (ds / myclass.size() * 100) << "% of the votes)";
	std::cout << "\nPerman, Sue = " << ps << " Votes (" << (ps / myclass.size() * 100) << "% of the votes)";
	std::cout << "\n\nFor PROPOSITION 17 = " << p17 << " Votes (" << (p17 / myclass.size() * 100) << "%)";
	std::cout << "\nAgainst PROPOSITION 17 = " << n17 << " Votes (" << (n17 / myclass.size() * 100) << "%)";
	std::cout << "\n\nFor MEASURE 1 = " << m1 << " Votes (" << (m1 / myclass.size() * 100) << "%)";
	std::cout << "\nAgainst MEASURE 1 = " << n1 << " Votes (" << (n1 / myclass.size() * 100) << "%)";
	std::cout << "\n\nFor MEASURE 2 = " << m2 << " Votes (" << (m2 / myclass.size() * 100) << "%)";
	std::cout << "\nAgainst MEASURE 2 = " << n2 << " Votes (" << (n2 / myclass.size() * 100) << "%)" << endl;



}
