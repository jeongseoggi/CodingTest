#include <string>
#include <vector>
#include <set>

using namespace std;
int solution(vector<int> elements) 
{
    int answer = 0;
    int add = 1;
    int allAddValue = 0;
    set<int> sets;

    for (const int& element : elements)
    {
        sets.insert(element);
    }

    for (const int& element : elements)
    {
        allAddValue += element;
    }
    sets.insert(allAddValue);

    for (int i = 0; i < elements.size() -1; i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int value = 0;
            for (int k = j; k <= j + add; k++)
            {
                if (k >= elements.size())
                {
                    value += elements[k % elements.size()];
                }
                else
                {
                    value += elements[k];
                }
            }
            sets.insert(value);
        }
        add++;
    }

    answer = sets.size();
    return answer;
}