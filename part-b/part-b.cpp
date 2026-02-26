#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
 *******************************************************************************/

// time complexity is O(2^n) since one more call generates two more recursive call
void towerHanoi(int num, string source, string buffer, string target, int &numMoves)
{
    if (num <= 0)
    {
        return;
    }

    // 2. n-1개의 원반을 Source에서 Buffer로 옮긴다 (Target을 보조 기둥으로 활용)
    towerHanoi(num - 1, source, target, buffer, numMoves);

    // 3. 가장 밑에 있는(가장 큰) 원반을 Target으로 옮긴다
    numMoves++; // 이동 횟수 기록
    cout << "Moving disc " << num << " from " << source << " to " << target << endl;

    // 4. Buffer에 치워뒀던 n-1개의 원반을 다시 Target으로 옮긴다 (Source를 보조 기둥으로 활용)
    towerHanoi(num - 1, buffer, source, target, numMoves);
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
 *******************************************************************************/

int main()
{
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0)
    {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl
             << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl
             << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}
