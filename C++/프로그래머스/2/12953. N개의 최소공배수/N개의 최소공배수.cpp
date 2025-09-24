#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    int index = 1;
    int value = 0;
    bool isFind = true;

    while (true)
    {
        isFind = true;
        value = index * arr[arr.size() - 1];

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (value % arr[i] != 0)
            {
                isFind = false;
                break;
            }
        }

        if (isFind)
        {
            break;
        }

        index++;
    }

    answer = value;

    return answer;
}