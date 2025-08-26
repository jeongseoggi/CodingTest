#include <string>
#include <vector>

using namespace std;


string solution(string s, int n)
{
	string answer = "";

	for (int i = 0; i < s.length(); i++)
	{
		char c;
		if (s[i] == ' ')
		{
			answer += s[i];
			continue;
		}
		else if (isupper(s[i]))
		{
			if (s[i] + n > 'Z')
			{

				int test = s[i] + n;
				test -= 'A';
				test %= 26;
				answer += 'A' + test;
				continue;
			}
		}
		else if (islower(s[i]))
		{
			if (s[i] + n > 'z')
			{
				int test = s[i] + n;
				test -= 'a';
				test %= 26;
				answer += 'a' + test;
				continue;
			}
		}
		answer += s[i] + n;
	}


	return answer;
}