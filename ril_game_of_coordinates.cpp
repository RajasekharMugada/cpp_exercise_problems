/*
Problem statement: Game of coordinates
You are given the coordinates (x, y). Initially, you are at (1, 1) and are
required to go to (x, y) using the following rules: If the current position
is (a, b) then in the next move you could only move to (a+b, b) or (a, a+b).
Write a program to check if you can reach (x, y) using only the moves
described above.
*/


#include <iostream>
using namespace std;

bool reach(int start_x, int start_y, int end_x, int end_y)
{
    //reached end position
    if(start_x == end_x && start_y == end_y)
    {
        return true;
    }
    //can not reach end position
    else if (start_x > end_x || start_y > end_y)
    {
        return false;
    }
    //Recursively check for end position
    else
    {
        if( reach(start_x + start_y, start_y, end_x, end_y) ||
            reach(start_x, start_x + start_y, end_x, end_y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{

    cout << "Starting point : (1,1)" ;

    cout << endl << "can you reach (3,2)" << " ";
    cout << reach(1,1, 3, 2);

    cout << endl << "can you reach (4,2)" << " ";
    cout << reach(1,1, 4, 2);

    cout << endl << "can you reach (4,6)" << " ";
    cout << reach(1,1, 4, 6);

    cout << endl << "can you reach (5,7)" << " ";
    cout << reach(1,1, 5, 7);

    return 0;
}

