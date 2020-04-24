/*
Problem statement: Maximum index

Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then T test case follows. First line of each test case contains an integer N denoting the size of the array. Next line contains N space separated integeres denoting the elements of the array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1018

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).



*/

//NOTE : Solution T(n) = O(n2) //Need to improve - can be done in O(n)


#include <iostream>
using namespace std;

#include <vector>


long max_index(vector <long> & a, long N)
{
	//i->    <-j
    long i = 0; //starting index
    long j = N-1; //last index

    long max_diff = 0;

    for(i = 0; i < N; i++)
    {
        for(j = N - 1; j > i; j--)
        {
            if(a[i] <= a[j])
            {
                if(max_diff < (j - i))
                    max_diff = (j - i);

                break;
            }
        }
    }

    return max_diff;
}


int main() {
	//code

	int T;
	long N;

	cin >> T;

	for(int i = 0; i < T; i++)
	{
	    cin >> N;
	    vector <long> a;
	    for (int j = 0; j < N; j++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);

	    }

	    cout <<  max_index(a, N) << endl;
	}



	return 0;
}
