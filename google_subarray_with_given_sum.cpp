/*
Problem statement: Sub array with given sum

Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of two lines. 
The first line of each test case is N and S, where N is the size of array 
and S is the sum. The second line of each test case contains N space separated 
integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) 
of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15

*/

#include <iostream>
#include <vector>
using namespace std;

void sub_array_index(vector <long> & a, long N, long S, long & start_id, long & end_id)
{
    long i = 0, j = 0;
    long sum = a[0];

    while(i < N && j < N)
    {
        if(sum == S)
        {
            start_id = i+1;
            end_id = j+1;
            return;
        }
        else if(sum < S)
        {
            j++;
            sum += a[j];
        }
        else //if(sum > S)
        {
            sum -= a[i];
            i++;
        }
    }

    //not found
    start_id = -1;
    end_id = -1;
}


int main() {
	//code
	//T = no. of test cases
	//N = array size
	//S = sum


	long T = 0;
	long N = 0;
	long S = 0;

	long start_id, end_id;

	long i, j, k;

	cin >> T;
	for (i = 0; i < T; i++)
	{
	    cin >> N >> S;

	    vector <long> a;
	    for(j = 0; j < N; j++)
	    {
	        cin >> k;
	        a.push_back(k);
	    }
	    /*
	    cout << endl << T << " " << N << " " << S << endl;
	    for(j = 0; j < N; j++)
	    {
	        cout << a[j] << " ";
	    }
	    cout << endl;
	    */

	    sub_array_index(a, N, S, start_id, end_id);

	    if (start_id == -1)
	        cout << -1 <<  endl;
	    else
	        cout << start_id << " " << end_id<< endl;
	}
	return 0;
}
