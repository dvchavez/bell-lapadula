//implement sub class
#include "sub.h"
#include <iomanip>

void sub::addsub(string name, string level)
{
	//pair(subject name, level, temp value)
	vec.push_back(make_tuple(name,level,"0"));
}

void sub::editsub(string name, string newtemp)//change temp of subject
{
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			get<2>(vec[i])=newtemp;
		}
	}
}

string sub::getLevel(string name)//get level of subject
{
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			return get<1>(vec[i]);
		}
	}
}

int sub::checksub(string name)//does subject exists
{
	int check=1;//by default not found
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			check=0;//found
		}
	}
	return check;

}

void sub::printsub()
{
	for(int i=0; i<vec.size(); i++)
	{
		//sub_name, level, value	
		cout<<"| "<< get<0>(vec[i])<<" | "<< right<< setw(7) <<get<2>(vec[i])<<" |"<<endl;
	}	
}