//object class header file
#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

class obj
{
	public:
	friend class ReferenceMonitor;
	vector< tuple<string, string, string> > vec;
	void addobj(string name, string level, string value);
	void editobj(string name, string newval); //when write
	int checkobj(string name);
	void printobj();
	string getval(string name); //get value for read
	string getlev(string name);
};
