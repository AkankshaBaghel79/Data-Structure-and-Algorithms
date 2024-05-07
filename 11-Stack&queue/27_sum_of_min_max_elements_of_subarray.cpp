#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

int solve(vector<int>& arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // for first window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // calculate for the remaining window
    for (int i = k; i < n; i++)
    {
        // Removal
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Sum : " << solve(arr, n, k) << endl;

    return 0;
}