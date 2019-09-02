
#include "voterrecord.h"





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



