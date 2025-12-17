#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> numbers;
vector<int> opers;

int maxResult = INT_MIN;
int minResult = INT_MAX;

int calc(vector<int>& numbers, vector<int>& curOpers)
{
    int result = numbers[0];
    
    for(int i = 0; i < N - 1; ++i)
    {
        if(curOpers[i] == 0)
        {
            result += numbers[i + 1];
        }
        else if(curOpers[i] == 1)
        {
            result -= numbers[i + 1];
        }
        else if(curOpers[i] == 2)
        {
            result *= numbers[i + 1];
        }
        else if(curOpers[i] == 3)
        {
            if(result < 0)
            {
                result = -(-result / numbers[i + 1]);
            }
            else
            {
                result /= numbers[i + 1];
            }
        }
    }
    return result;
}

void dfs(int depth, vector<int>& curOpers)
{
    if(depth == N - 1)
    {
        int result = calc(numbers, curOpers);
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
    }
    
    for(int i = 0; i < 4; ++i)
    {
        if(opers[i] > 0)
        {
            opers[i]--;
            curOpers.push_back(i);
            dfs(depth + 1, curOpers);
            opers[i]++;
            curOpers.pop_back();
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    numbers.resize(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }
    
    opers.resize(4);
    
    for(int i = 0; i < 4; ++i)
    {
        cin >> opers[i];
    }
    
    
    vector<int> curOpers;
    dfs(0, curOpers);
    
    cout << maxResult << endl;
    cout << minResult << endl;
    return 0;
}
