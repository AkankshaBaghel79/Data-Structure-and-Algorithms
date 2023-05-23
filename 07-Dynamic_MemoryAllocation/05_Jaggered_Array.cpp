#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

int main()
{
    int row;
    cin >> row;

    int **arr = new int *[row];
    int sizes[] = {4, 3, 2, 1}; // the size of row and the sizes array should be of same length

    // Creating 2D Jagged array
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[sizes[i]];
    }

    // Taking inputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Producing Outputs
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // relesing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}