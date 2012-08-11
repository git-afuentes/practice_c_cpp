/* Implement a function void reverse(char *str) in C or C++ which reverses a null terminating string */ 

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;

void reverse(char *cstr)
{
	int i = 0;
	string str = cstr;
	char *str_reverse = new char[str.size()+1];
	char *last;

	last = cstr + str.length()-1;
	while(i != str.length())
	{
		str_reverse[i] = *last;
		last--;
		i++;	
	}
	str_reverse[i] = '\0';
	printf("%s\n", str_reverse);
}


int main()
{
	string str = "This is my string123";
	char *cstr = new char [str.size()+1];
  	strcpy (cstr, str.c_str());		//contains a c copy of str


	reverse(cstr);

}
