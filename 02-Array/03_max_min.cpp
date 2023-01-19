#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the num : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxNO=INT_MIN;
    int minNO=INT_MAX;

    for(int i=0;i<n;i++)
    {
        maxNO=max(maxNO,arr[i]);
        minNO=min(minNO,arr[i]);
    }
    cout<<"Maximum : "<<maxNO<<endl;
    cout<<"Minimum : "<<minNO<<endl;
    return 0;
}

// output:
// Enter the num : 5
// Enter the elements : 1 2 3 4 5
// Maximum : 5
// Minimum : 1