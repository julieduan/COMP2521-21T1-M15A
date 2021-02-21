#include <stdio.h>

int n = 5;
int A[5] =  {1,2,3,0,5};
int x = 2;

int evalPolynomial(int* A, int n, int x);

int main(int argc, char *argv[])
{
    for(int i = 0; i < n;i++){
        if(i == 0){
            printf("%d*%d^%d", A[i], x, n-i);
        }else{
            printf(" + %d*%d^%d", A[i], x, n-i);
        }
        
    }
    printf(" = %d\n", evalPolynomial(A,n,x));
}

int evalPolynomial(int* A, int n, int x)
{
    int result = 0;
    int last_x_pow = 1;
    for(int i = n-1; i >= 0;i--){
        result += A[i] * last_x_pow * x;
        last_x_pow*=x;
    }
	return result;
}