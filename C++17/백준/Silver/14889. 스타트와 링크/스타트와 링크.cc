#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> S;
int min_diff = INT_MAX;

int calc(vector<bool>& team)
{
    int startTeam = 0;
    int linkTeam = 0;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j )
        {
            if (team[i] && team[j])
            {
                startTeam += S[i][j];
            }
            else if (!team[i] && !team[j])
            {
                linkTeam += S[i][j];  
            }
        }
    }
    
    return abs(startTeam - linkTeam);
}


void dfs(vector<bool>& team, int index, int count) // team, 현재 위치, 스타트팀 카운트
{
    if (count == N /2) // 스타트팀이 N/2 팀이면 자동으로 반반 나뉘었다고 판단
    {
        int result = calc(team);
        min_diff = min(min_diff, result);
        return;
    }
    
    if (index == N)
    {
        return;
    }
    
    team[index] = true;
    dfs(team, index + 1, count + 1);
    
    team[index] = false;
    dfs(team, index+ 1, count);
    
    return;
    
    // 시작 N == 4 가정 {false, false, false, false} -> 스타트팀은 0팀, 링크 팀은 4팀
    // {true, false, false, false}, index = 1, count = 1 -> 스타트팀 1팀, 링크 팀 3팀 dfs(호출)
    // {ture, true, false, false}, index = 2, count = 2 -> 스타트팀 2팀, 링크 팀 2팀 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {true, true, false, false} 이 위치로 돌아옴 index = 1, count = 1
    // {true, false, false, false} -> index = 2, count = 1 dfs(호출)
    // {true, false, true, false} -> index = 3, count = 2 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {true, false, true, false} 이 위치로 돌아옴 index = 2, count = 1
    // {true, false, false, false} -> index = 2, count = 1 dfs(호출)
    // {true, false, false, true} -> index = 3 , count = 2 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {true, false, false, true} 이 위치로 돌아옴 index = 3, count = 1 
    // {true, false, false, false} -> index = 4, count = 1 dfs(호출)
    // 두번째 if 조건문 부합 return
    // {true, false, false, false} 최종적으로 이 부분으로 돌아오게 된다. index = 0, count = 0
    // {false, false, false, false} -> index = 1, count = 0 dfs(호출)
    // {false, true, false, false} -> index = 2, count = 1 dfs(호출)
    // {false, true, true, false} -> index = 3, count = 2 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {false, true, true, false} 이 위치로 돌아옴 index = 2, count = 1
    // {false, true, false, false} -> index= 3, count = 1 dfs(호출)
    // {false, ture, false, true} -> index= 4, count = 2 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {false, true, false, true} 이 위치로 돌아옴 index= 3, count = 1
    // {false, true, false, false} -> index= 4, count = 1 dfs(호출)
    // 두번째 if 조건문 부합하여 return
    // {false, true, false, false} 이 위치로 돌아옴 index = 1, count = 0
    // {false, false, false, false} -> index = 2, count = 0 dfs (호출)
    // {false, false, true, false} -> index = 3, count = 1 dfs(호출)
    // {false, false, true, true} -> index = 4, count = 2 dfs(호출)
    // if 조건문 부합 능력치 계산
    // return
    // {false, false, true, true} 이 위치로 돌아옴 index = 3, count =  1
    // {false, false, true, false} -> index = 4, count =  1 dfs(호출)
    // 두번째 if 조건문 부합 return
    // {false, false, true, false} 이 위치로 돌아옴 index = 2, count = 0
    // {false, false, false, false} -> index = 3, count = 0 dfs(호출)
    // {false, false, false, true} -> index = 4, count = 1 dfs(호출)
    // 두번째 조건문 부합 return
    // {false, false, false, true} 이 위치로 돌아옴 index= 3, count = 0
    // {false, false, false, false} -> index = 4, count = 0 dfs(호출)
    // 두번째 if조건문 부합 return
    // 종료
}

int main()
{
    cin >> N;
    S.resize(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }
    
    // 스타트(true)
    // 링크(false)
    vector<bool> team(N, false); // 시작 시에는 모든 팀이 링크 팀(false)
    
    dfs(team, 0, 0);
    cout << min_diff << endl;
    return 0;    
}
