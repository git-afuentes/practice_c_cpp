/* Implement a function void reverse(char *str) in C or C++ which reverses a null terminating string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reverse(char *str)
{
	int i = 0;
	char *str_reverse = malloc(strlen(str)+1);
	char *last;
	last = str + strlen(str) -1;
	while (i != strlen(str)){
		str_reverse[i] = *last;
		last--;
		i++;
	}
	str_reverse[i] = '\0';
	printf("%s\n", str_reverse);
	
}


int main()
{
	char *input = "This is my string123";

	reverse(input);

}
