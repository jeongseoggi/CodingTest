#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<char, int> maps;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        maps[str[0]]++;
    }
    
    bool isFind = false;
    for(auto& ch : maps)
    {
        if(ch.second >= 5)
        {
            cout << ch.first;
            isFind = true;
        }
    }
    
    if(!isFind)
    {
        cout << "PREDAJA";
    }
    
    return 0;
}