#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
     sort(numbers.begin(), numbers.end());

     int maVal = 45;


     int numbesAddValue = 0;
     for (auto it = numbers.begin(); it != numbers.end(); it++)
     {
         numbesAddValue += *it;
     }


     answer = maVal - numbesAddValue;


 return answer;
}