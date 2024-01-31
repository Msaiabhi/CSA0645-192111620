#include <stdio.h>
int calculateEvenSum(int n)
{

    // return 0 if n is equals or less than to 0

    if (n <= 0)

        return 0;
 

    int fibo[2 * n + 1];

    fibo[0] = 0, fibo[1] = 1;
 

    // Initialize the result

    int sum = 0;
 

    // Adding the remaining terms

    for (int i = 2; i <= 2 * n; i++) {

        fibo[i] = fibo[i - 1] + fibo[i - 2];
 

        // For even indices

        if (i % 2 == 0)

            sum += fibo[i];

    }
 

    // Return alternating sum

    return sum;
}
 
// Driver Code

int main()
{
 

    // Get n

    int n ;
    printf("enter the n value");
    scanf("%d",&n);
 

    // calculateEvenSum(n) function is computed and return

    // the sum of even-indices Fibonacci numbers.

    int sum = calculateEvenSum(n);
 

    // display result

    printf("Even indexed Fibonacci Sum upto %d terms = %d",

           n, sum);
 

    return 0;
}
