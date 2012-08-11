/*Write a method to replace all spaces in a string with %20. You may assume the string has sufficient space at the end of the string to hold additional characters. You are given the length of the string*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


void replaceSpaces(char * str, int len)
{
	int cnt = 0;
	for(int i=0; i< len-1; i++)
	{
		if(str[i] == ' ')
			cnt++;		
	}
	int newlength = len + cnt*2;
	str[newlength] = '\0';
	for(int i=len-1 ; i>=0; i--)
	{
		if(str[i]==' ')
		{
			str[newlength -1] = '0';
			str[newlength -2] = '2';
			str[newlength -3] = '%';
			newlength = newlength - 3;
		}
		else
		{
			str[newlength-1] = str[i];
			newlength = newlength -1;
		}
	}
	printf("%s\n", str);
}


int main()
{
	string str = "This is my string";

	int length = str.length();

	char *cstr = new char [str.size() +1];
	strcpy(cstr, str.c_str());

	replaceSpaces(cstr, length);

}

