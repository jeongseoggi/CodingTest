#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] % 2 == 0)
        {
            bitset<64> numberBit(numbers[i]);
            numberBit[0] = 1;
            long long value = numberBit.to_ullong();
            answer.push_back(value);
        }
        else
        {
            int index = 0;
            bitset<64> numberBit(numbers[i]);
            while (numberBit[index] != 0)
            {
                index++;
            }

            numberBit.reset();
            numberBit[index] = 1;
            long long value = numberBit.to_ullong() / 2;

            answer.push_back(value + numbers[i]);
        }

    }
    return answer;
}