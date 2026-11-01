#include <iostream>
using namespace std;

void MoveTower(int n, char start, char finish, char temp)
{
    // Tower of Hanoi
    /**
     * Base case
     *  The simple case occurs when n is equal to 1.
     *  If the tower only contains one disk, you can go
     *  ahead and move it.
     *
     * Recursive case
     *  For n disks, move n-1 disks to the temporary
     *  pole and the bottom disk n to the ending pole
     *  and then move the first n-1 from the temporary
     *  pole to the ending one.
     *      Ex: n = 7 in A, move 6 of them to B
     *      then move the last one to C and move all in B to C.
     */
    if (n == 1)
        cout << start << " -> " << finish << '\n';
    else
    {
        MoveTower(n - 1, start, temp, finish);
        MoveTower(1, start, finish, temp);
        MoveTower(n - 1, temp, finish, start);
    }
}

int main()
{
    MoveTower(4, 'A', 'C', 'B');
    return 0;
}