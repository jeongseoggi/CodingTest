#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    set<string> subs;

    for (int i = 0; i < s.size(); ++i) 
    {
        string temp = "";
        for (int j = i; j < s.size(); ++j) 
        {
            temp += s[j];
            subs.insert(temp);
        }
    }

    cout << subs.size() << endl;
}
