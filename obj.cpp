//implement obj class
#include "obj.h"
#include <iterator>
#include <iomanip>
void obj::addobj(string name, string level, string value)
{
	//pair(object name, level, value)
	vec.push_back(make_tuple(name,level,"0"));	
}

int obj::checkobj(string name)//does obj exits
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

void obj::editobj(string name, string newval)//change value of obj
{
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			get<2>(vec[i]) = newval;
		}
	}
}

string obj::getlev(string name)//get level of obj
{
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			string store = get<1>(vec[i]);
			return store;
		}
	}
}

string obj::getval(string name)//get value of obj
{
	for(int i=0; i<vec.size(); i++)
	{
		if(get<0>(vec[i]).compare(name)==0)
		{
			string store= get<2>(vec[i]);
			return store;
		}
	}
}

void obj::printobj()
{
	for(int i=0; i<vec.size(); i++)
	{
		//obj_name, level, value	
		cout<<"| "<< get<0>(vec[i])<<" | "<< right << setw(7) <<get<2>(vec[i])<<" |"<<endl;
	}		
}