#include <bits/stdc++.h>

using namespace std;

map<char, char> maps;
const int WORD_INDEX = 4;

int dfs(int index, string curWord, string targetWord)
{
    if (curWord == targetWord)
    {
        return index;
    }

    if (curWord.length() < 5)
    {
        curWord += "A";
    }
    else
    {
        int i = WORD_INDEX;
        while (true)
        {
            if (curWord[i] == 'U')
            {
                curWord = curWord.substr(0, i);
                i--;
                continue;
            }
            else
            {
                curWord[i] = maps[curWord[i]];  
                break;
            }

        }
    }

    return dfs(index + 1, curWord, targetWord);
}

int solution(string word) 
{
    int answer = 0;

    maps['A'] = 'E';
    maps['E'] = 'I';
    maps['I'] = 'O';
    maps['O'] = 'U';


    return dfs(answer + 1, "A", word);
}
