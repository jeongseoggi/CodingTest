#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    
    cin >> N >> M;

    vector<int> v;
    v.resize(N, 0);

    for(int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
 
    int start = 0;
    long long sum = 0;
    int val = INT_MAX;

    for(int i = 0; i < N; ++i)
    {
        sum += v[i];

        while(sum >= M)
        {
            val = min(val, i - start + 1);
            sum -= v[start];
            start++;
        }
    }   

    cout << (val == INT_MAX ? 0 : val) << "\n";
    return 0;
}