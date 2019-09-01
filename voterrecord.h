#pragma once
#ifndef VOTERRECORD_H
#define VOTERRECORD_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class VoterRecord {

public:
	//void input();
	VoterRecord();
	VoterRecord(string newID, string newVote);
	//accessor functions
	string getID();
	string getVote();
	void addNewVotes();
	void fillVector();
	void printVector();
	void modifyVote();
	void query();
	void voterStats();
	vector<VoterRecord> myclass;
	
	


private:

	   string id;
	   string votes;





};








#endif