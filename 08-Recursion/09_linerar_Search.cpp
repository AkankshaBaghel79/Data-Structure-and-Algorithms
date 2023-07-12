#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

bool linearSerach(int *arr, int size, int k)
{
    //Base Case
    if(size == 0)
       return false;
    if(*arr == k)
       return true;
    else{
        bool ans = linearSerach(arr+1, size-1,k);
        return ans;
    }
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int key = 3;

    bool ans = linearSerach(arr, size, key);
    if(ans)
    {
        cout<<"Element "<<key<<" is present in the array"<<endl;
    }
    else{
            cout<<"Element "<<key<<" is Absent from the array"<<endl;

    }
    
    return 0;
}