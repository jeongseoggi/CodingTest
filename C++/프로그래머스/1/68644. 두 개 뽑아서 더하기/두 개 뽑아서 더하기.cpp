#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    set<int> setV;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            setV.insert(numbers[i] + numbers[j]);
        }
    }

    for (int num : setV)
    {
        answer.push_back(num);
    }

    return answer;
}