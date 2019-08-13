//implement reference monitor class
#include "RM.h"

void ReferenceMonitor::out(obj object,sub subject)//current state every 10 lines
{
	cout<<"+---Current State---+"<<endl;
	cout<<"|-subject-|---temp--|"<<endl;
	subject.printsub();
	cout<<"|--object-|--value--|"<<endl;
	object.printobj();
	cout<<"+-------------------+"<<endl;

}

int ReferenceMonitor::insCount(int lines)//determine how many lines
{
	if(lines==10)
	{
		return 0;
	}
	else
	{
		return lines;
	}
}

int ReferenceMonitor::READ(string sub_name, string obj_name, int lines, obj object, sub subject)
{
	int countLine=lines;
	if(object.checkobj(obj_name)==0) //if obj found
	{
		if(subject.checksub(sub_name)==0)//if sub found
		{
			string obj_level=object.getlev(obj_name);//get levels of sub and obj
			string sub_level=subject.getLevel(sub_name);
			int access=accessr(getlevel(obj_level), getlevel(sub_level));
			if(access==0)//if given access
			{
				//DEAL WITH LEVELS
				check=0; //given access
				t=object.getval(obj_name); //assign value for temp will return in T function
				cout<<"Access Granted  : "<<sub_name<<" reads "<<obj_name<<endl;
				countLine++;
				return insCount(countLine); //is it 10 lines?
			}
			else if(access==1)
			{
				check=1; //not given access
				cout<<"Access Denied   : "<<sub_name<<" reads "<<obj_name<<endl;
				countLine++;
				return insCount(countLine);
			}
		}
		else
		{
			check=1;//not given access
			cout<<"Bad Instruction : read "<<sub_name<<" "<<obj_name<<endl;
			countLine++;
			return insCount(countLine);
		}
	}
	else
	{
		check=1;//not given access
		cout<<"Bad Instruction : read "<<sub_name<<" "<<obj_name<<endl;
		countLine++;
		return insCount(countLine);
	}
	//check=1; //default
		
}

int ReferenceMonitor::accessw(int obj_level, int sub_level)
{
	if(sub_level<=obj_level)
	{
		//you can write up if object is higher or equal to subject
		return 0;//give access	
	}
	if(sub_level>obj_level)
	{
		return 1; //cant write down from higher level
	}
	
}

int ReferenceMonitor::accessr(int obj_level, int sub_level)
{
	if(obj_level<=sub_level)
	{
		//you can read up
		return 0;//give access	
	}
	if(sub_level>obj_level)
	{
		return 1; //cant read up
	}
	
}

int ReferenceMonitor::WRITE(string sub_name, string obj_name, string value, int lines, obj object, sub subject)
{
	int countLine=lines;
	if(int_check(value)==1) //if value is an integer
	{
		if(object.checkobj(obj_name)==0) //if obj found
		{
			if(subject.checksub(sub_name)==0)
			{
				string obj_level=object.getlev(obj_name);//get levels for obj and sub
				string sub_level=subject.getLevel(sub_name);
				int access=accessw(getlevel(obj_level), getlevel(sub_level));
				if(access==0)//if access given
				{
					//DEAL WITH LEVELS
					check=0;//yes given access
					v=value; //value for obj will return in R function
					cout<<"Access Granted  : "<<sub_name<<" writes value "<<value<<" to "<<obj_name<<endl;
					countLine++;	
					return insCount(countLine);		
				}
				else if(access==1)
				{
					check=1; //no access
					cout<<"Access Denied   : write "<<sub_name<<" "<<obj_name<<" "<<value<<endl;
					countLine++;
					return insCount(countLine);
				}
			}
			else
			{
				check=1; //no access
				cout<<"Bad Instruction : write "<<sub_name<<" "<<obj_name<<" "<<value<<endl;
				countLine++;
				return insCount(countLine);
			}
		}
		else
		{
			check=1;//no access
			cout<<"Bad Instruction : write "<<sub_name<<" "<<obj_name<<" "<<value<<endl;
			countLine++;
			return insCount(countLine);
		}
	}
	else //false
	{
		check=1;//no access
		cout<<"Bad Instruction : write "<<sub_name<<" "<<obj_name<<" "<<value<<endl;
		countLine++;
		return insCount(countLine);
	}
	//check=1; //no access default
}
bool ReferenceMonitor::int_check(string value) //for WRITE only// if it is an integer
{
	string::const_iterator it = value.begin();
	while(it !=value.end() && isdigit(*it)) ++it;
	return !value.empty() && it == value.end();
}
int ReferenceMonitor::getlevel(string level) //what level are you
{
	if(level=="high")
	{
		return 2;//it is high
	}
	else if(level=="medium")
	{
		return 1;//it is medium
	}
	else if(level=="low")
	{
		return 0;//it is low
	}
}

string ReferenceMonitor::R()
{
	return v;//write v=value
}
string ReferenceMonitor::T()
{
	return t; //read t=newtemp
}
int ReferenceMonitor::C()
{
	return check;//return if line has access
}