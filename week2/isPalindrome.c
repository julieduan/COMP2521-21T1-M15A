// a copy from UNSW comp2521 21T1 toturial answers

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool isPalindrome(char *S);

int main (int argc, char *argv[])
{
	if (argc == 2) {
		if (isPalindrome(argv[1]))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

static bool isPalindrome(char *S)
{
	int l = 0;
	int r = strlen(S) - 1;

	while (l < r) {
		if (S[l] != S[r])
			return false;
		l++;
		r--;
	}
	return true;
}