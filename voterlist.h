
#ifndef VOTERLIST_H
#define VOTERLIST_H
#include "voterrecord.h"


class VoterList {

public:
	void addNewVotes();
	void fillVector();
	void printVector();
	void modifyVote();
	void query();
	void voterStats();
	vector<VoterRecord> myclass;
	
};




#endif





 





