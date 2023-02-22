/*You have been given a string 'STR'* of words. You need to replace all the spaces between words with "@40"*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n";

string replaceSpaces(string &str){

    //Space Complexity--> O(N);
    string temp = "";

	for(int i =0;i<str.length();i++)
	{
		if(str[i] == ' ')
		{
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}
		else
		{
			temp.push_back(str[i]);
		}
	}

	return temp;
	

    //Space Complexity -- > O(1)
	// for(int i =0;i<str.length();i++)
	// {
	// 	if(str[i] == ' ')
	// 	{
    //         string temp = "@40";
    //         str.replace(i,1,temp);
	// 	}
	// }

	// return str;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<replaceSpaces(s)<<endl;

    return 0;
}