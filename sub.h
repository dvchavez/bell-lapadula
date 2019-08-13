//subject class header file
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class sub
{
	public:
	vector< tuple<string, string, string> > vec;
	void addsub(string name, string level);
	void editsub(string name, string newtemp);
	string getLevel(string name);
	int checksub(string name);
	void printsub();
};