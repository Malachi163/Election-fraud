
#include "voterrecord.h"



void VoterRecord::addNewVotes()
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

void VoterRecord::fillVector()
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

void VoterRecord::printVector()
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
void VoterRecord::modifyVote()
{
	
	int size = myclass.size();
	string add_vote1, add_vote2, add_vote3, add_vote4;
	string total_vote, add_id;
	string query;
	char r;
	

	std::cout << "Look up a vote by searching for an ID: ";
	cin >> query; //searches for the voter id



	for (int i = 0; i < size; i++)
	{
		if (query == myclass[i].getID())
		{
			std::cout << myclass[i].getVote();
			//find(0, size, "BEGI");
			std::cout << endl;
		}
	}
	std::cout << "This is your old voting record. Would you like to change it? (y/n)";
	cin >> r;

	if (r == 'y')
	{
		
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
		
		//VoterRecord add_in(query,total_vote);
		

		//cin >> modify;
		//modify = modify - 1;
		
		
	}
}

void VoterRecord::query()
{
	//VoterRecord x;
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

void VoterRecord::voterStats()
{
	
	
	double pp = 0.0;
	double ds = 0.0;
	double ps = 0.0;
	double p17 = 0.0;
	double n17 = 0.0;
	double m1 = 0.0;
	double n1 = 0.0;
	double m2 = 0.0;
	double n2 = 0.0;
	
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


string VoterRecord::getID()
{
	return id;
}

string VoterRecord::getVote()
{
	return votes;
}

VoterRecord::VoterRecord() {
	std::cout << "Doesn't work" << endl;
}



VoterRecord::VoterRecord(string newID, string newVote) {


	id = newID;

	votes = newVote;



}



