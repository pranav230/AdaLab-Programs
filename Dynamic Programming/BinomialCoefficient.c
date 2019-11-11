
play_arrow

brightness_4
#include<stdio.h> 

int binomialCoeff(int n, int k) 
{ 
	int C[n+1][k+1]; 
	int i, j; 
	for (i = 0; i <= n; i++) 
		for (j = 0; j <= min(i, k); j++) 
			if (j == 0 || j == i) 
				C[i][j] = 1;   
			else
				C[i][j] = C[i-1][j-1] + C[i-1][j]; 
	return C[n][k]; 
} 

int min(int a, int b) 
{ 
	return (a<b)? a: b; 
} 

int main() 
{ 
	int n = 15, k = 8; 
	printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) ); 
	return 0; 
}