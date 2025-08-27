#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) 
{
    int answer = 0;

    map<string, int> kv;

    kv.insert(make_pair("zero", 0));
    kv.insert(make_pair("one", 1));
    kv.insert(make_pair("two", 2));
    kv.insert(make_pair("three", 3));
    kv.insert(make_pair("four", 4));
    kv.insert(make_pair("five", 5));
    kv.insert(make_pair("six", 6));
    kv.insert(make_pair("seven", 7));
    kv.insert(make_pair("eight", 8));
    kv.insert(make_pair("nine", 9));


    string temp;
    string temp1;
    for (int i = 0; i < s.length(); i++)
    {
        temp1 += s[i];
        auto item = kv.find(temp1);
        if (item != kv.end())
        {
            temp += to_string(item->second);
            temp1 = "";

        }
        else if(isdigit(s[i]))
        {
            temp += s[i];
            temp1 = "";
        }
    }
    answer = stoi(temp);

    return answer;
}
