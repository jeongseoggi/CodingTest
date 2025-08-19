#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int temp = phone_number.length() - 4;

    string s;

    for (int i = 0; i < temp; i++)
    {
        s += "*";
    }

    answer = phone_number.replace(0, temp, s);

    return answer;
}