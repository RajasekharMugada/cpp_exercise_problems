/*
Problem statement: Prime permutations

You are given a number N. Write a program to find all the arrangements of
the natural numbers from 1 to N in which the indices (starting from 1) of
prime numbers are also prime numbers modulo 1000000007.
Ex: for N = 5, there can be 12 possible arrangements
Solution : no_of_primes! x no_of_composites!
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    int res = 1;

    if (n <= 1)
        return 1;

    while(n)
    {
        res *= n;
        n--;
    }

    return res;
}

int check_prime(int n)
{
    if (n <= 1)
    {
        return 0; //not a prime number
    }

    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            return 0; // not a prime
        }
    }
    return 1; //prime
}

//count number of primes from [1 - N]
int count_primes(int N)
{
    int count = 0;

    for(int i = 1; i <= N; i++)
    {
        count += check_prime(i);
    }

    return count;
}


int num_prime_arrangements(int N)
{
   int num_primes = count_primes(N);
   return  factorial(num_primes)*factorial(N - num_primes);
}


int main()
{
    //cout << "factorial of 3 = " << factorial(3) << endl;
    //cout << "Is 107 a prime number ? " << check_prime(107) << endl;
    //cout << "No. of primes from 1 to 10 = " << count_primes(10);

    cout << "No. of prime arrangements in N = 5 is " << num_prime_arrangements(5);

    return 0;
}
