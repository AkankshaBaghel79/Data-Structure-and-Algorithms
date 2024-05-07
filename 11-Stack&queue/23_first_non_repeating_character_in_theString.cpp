#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string FirstNonRepeating(string A) {

    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
   
    for(int i = 0;i<A.length();i++) {
        char ch = A[i];

        //Increase the count of char
        count[ch]++;

        //push element into the queue
        q.push(ch);

        while (!q.empty())
        {
            if(count[q.front()] > 1) {
                q.pop();
            }
            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back('#');
        }
        
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;

    cout<<"Non repeating character : ";
    string ans = FirstNonRepeating(s);
    cout<<ans<<endl;
    return 0;
}