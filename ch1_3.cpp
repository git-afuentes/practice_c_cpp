/* Given two strings, write a method to find out if one is a permutation of the other */ 

// assume that case does matter

#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

bool isStringPermutation(string str1, string str2)
{
	if(str1.length() != str2.length())
		return false;
	else
	{
		int charCount[256];
		for(int i; i<str1.length(); i++)
		{
			char c = str1.at(i); //returns char in this position
			int cval = c; //converts string to integer #
			charCount[cval]++; // add numbers of each char	
		}
		
		for(int i; i< str2.length(); i++)
		{
			char c = str2.at(i);
			int cval = c;
			charCount[cval]--; 
			if(charCount[cval] <0)
				return false;
		}
		return true;
	}
}

int main()
{
	string str1 = "Arcoiris";
	string str2 = "siriocrA";

	bool result = isStringPermutation(str1, str2);

	if(result == true)
		cout << "string is permutation\n";
	if(result == false)
		cout << "string is not permutation\n";

} 


