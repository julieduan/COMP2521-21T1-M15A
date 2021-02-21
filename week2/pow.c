#include <stdio.h>
#include <stdlib.h>

int thanos_pow(int x, unsigned int n);

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    int n = atoi(argv[2]);
    int result = thanos_pow(x, n);
    printf("%d^%d is %d\n",x ,n, result);
	return 0;
}

int thanos_pow(int x, unsigned int n)
{
	// int res = 1;
	// for (int i = 1; i <= n; i++) {
	// 	res = res * x; 
	// }
	// return res;
    if (n == 0) return 1;
	if (n == 1) return x;
	if (n % 2 == 0) { // n is even
		return pow(x * x, n / 2);
	} else { // n is odd
		return x * pow(x * x, n / 2);
	}
}