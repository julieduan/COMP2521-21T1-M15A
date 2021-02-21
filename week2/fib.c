#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fib(int n);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
	printf("----------Finding %dth Fibonacci number----------\n",n);
    int result = fib(n);
    printf("----------%dth Fibonacci number is %d----------\n",n,result);
	return 0;
}

int fib(int n)
{
	assert(n > 0);
    printf("fib(%d) is called\n",n);
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}