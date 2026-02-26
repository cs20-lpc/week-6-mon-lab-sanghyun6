#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Function prototype
 *******************************************************************************/
// time complexity is O(n) since it visits the whole array one time
template <typename T>
T findMaxHelper(const T arr[], const int size, T mx, int i)
{
    if (i == size)
    {
        return mx;
    }

    if (arr[i] > mx)
    {
        mx = arr[i];
    }
    return findMaxHelper(arr, size, mx, i + 1);
}

template <typename T>
T findMaxRecTail(const T arr[], const int size, int i = 0)
{
    // TO DO: Implement your code
    return findMaxHelper(arr, size, arr[0], i + 1);
}

// time complexity is O(n) since it visits the whole array one time
template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right)
{
    // TO DO: Implement your code
    if (left == right)
    {
        return arr[left];
    }
    int mid = (right + left) / 2;
    T leftmx = findMaxRecBinarySplit(arr, left, mid);
    T rightmx = findMaxRecBinarySplit(arr, mid + 1, right);

    if (leftmx > rightmx)
    {
        return leftmx;
    }
    else
    {
        return rightmx;
    }
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays, one fixed and the other
 * random. Determines the maximum value by calling the local function and the
 * standard function.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
 *******************************************************************************/

int main()
{
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6};

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl
         << "From Binary split:"
         << findMaxRecBinarySplit(myArray, 0, SIZE - 1)
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl
         << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int &elem : randArray)
    {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}
