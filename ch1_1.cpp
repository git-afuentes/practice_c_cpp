/* Implement and algorithm to determine if a string has all unique characters */
/* What if you cannot use additional data structures */


//Time Complexity: O(n)
//Space Complexity O(1)

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

bool isUnique(string str)
{
	int i;
	bool myarray[256];

	for(i=0; i<256; i++)
		myarray[i] = false;	
 
	if(str.length() > 256)
		return false;

	for(i=0; i<str.length(); i++)
	{
		char c = str.at(i);
		cout << c << "\n";
		int cha_i = c;
		cout << cha_i << "\n";
		if(myarray[cha_i] == true)
		{
			return false;
		}

		myarray[cha_i] = true;
	}
	return true;	
}


int main()
{
	bool ans = isUnique("poiuyrlkjhmnbvaqzwee");

	if(ans == false)
	{
		printf("String is not unique\n");
	}
	else if(ans == true)
	{
		printf("String is unique\n");
	}

}


