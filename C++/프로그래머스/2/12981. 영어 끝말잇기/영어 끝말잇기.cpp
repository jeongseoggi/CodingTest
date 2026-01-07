#include <bits/stdc++.h>

using namespace std;

// vector<int> solution(int n, vector<string> words) 
// {
//     vector<int> answer;
//     set<string> sets;

//     int count = 0;
//     for (int i = 0; i < words.size(); ++i)
//     {
//         count = i % n;

//         if (i == 0)
//         {
//             sets.insert(words[i]);
//             continue;
//         }

//         if (sets.find(words[i]) != sets.end())
//         {
//             answer.push_back(count + 1);
//             answer.push_back((i / n) + 1);

//             break;
//         }
//         else if (words[i - 1].size() == 1)
//         {
//             answer.push_back(count + 1);
//             answer.push_back((i / n) + 1);
//             break;
//         }
//         else
//         {
//             string lastWord = words[i - 1];
//             string curWord = words[i];

//             if (lastWord[lastWord.size() - 1] != curWord[0])
//             {
//                 answer.push_back(count + 1);
//                 answer.push_back((i / n) + 1);
//                 break;
//             }
//         }
      

//         sets.insert(words[i]);
//     }

//     if (answer.size() == 0)
//     {
//         answer.push_back(0);
//         answer.push_back(0);
//     }

//     return answer;
// }

// 좀 더 최적화된 방법
vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    unordered_set<string> sets;

    sets.insert(words[0]);

    for (int i = 1; i < words.size(); ++i)
    {
        string lastWord = words[i - 1];
        string curWord = words[i];

        if (lastWord.back() != curWord.front())
        {
            return { i % n + 1, i / n + 1 };
        }

        if (sets.find(curWord) != sets.end())
        {
            return { i % n + 1, i / n + 1 };
        }

        sets.insert(curWord);
    }

    return { 0, 0 };
}

