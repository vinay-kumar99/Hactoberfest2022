#include <stdio.h> 

/* Recursive way to find fibonacci numbers.
    int fib(int n) 
    { 
        if (n <= 1) 
            return n; 
        return fib(n - 1) + fib(n - 2); 
    }
*/

// More efficient way to find fibonacci numbers.
int fib(int n)
{
    int f[n+2];   // 1 extra to handle case, n = 0
    
    f[0] = 0;
    f[1] = 1;
    int i;
    
    for (i = 2; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    
    return f[n];
}
  
int main() 
{ 
    int n = 9; 
    printf("%d", fib(n)); 
    getchar(); 
    return 0; 
} 
