/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2230                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: hv4564 <boj.kr/u/hv4564>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2230                           #+#        #+#      #+#    */
/*   Solved: 2025/12/23 12:03:45 by hv4564        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> numbers;
    for(int i = 0; i < N; ++i)
    {
        int value = 0;
        cin >> value;
        numbers.push_back(value);
    }
    sort(numbers.begin(), numbers.end());

    int start = 0;
    int end = 0;
    int sum = INT_MAX;

    while(start < N)
    {
        int count =  numbers[end] - numbers[start] ;
        if(count < M)
        {
            end++;

        }
        else if(count >= M)
        {
            sum = min(sum, count);
            start++;
        }

        if(end >= N)
        {
            end = N - 1;
            start++;
        }
    }

    cout << sum << endl;


    return 0;
}