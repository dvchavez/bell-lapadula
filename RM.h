#include <iostream>
#include "obj.h"
#include "sub.h"
#include <string>

class ReferenceMonitor
{
	public:
	string v; //value
	string t; //temp
	int check=1;
	void out(obj object,sub subject);
	int insCount(int lines);
	int READ(string sub_name, string obj_name, int lines, obj object, sub subject);
	int WRITE(string sub_name, string obj_name, string value, int lines, obj object, sub subject);
	bool int_check(string value);
	int getlevel(string level);
	int accessw(int obj_level, int sub_level);
	int accessr(int obj_level, int sub_level);
	string R(); //return write value
	string T(); //return read temp 
	int C(); //check it is access
};
