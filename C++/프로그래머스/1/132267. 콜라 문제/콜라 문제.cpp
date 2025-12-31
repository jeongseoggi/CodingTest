#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
	int answer = 0;
	int value = 0;

	while (n >= a)
	{
		if (n % a != 0)
		{
			value += n % a;
		}

		n = (n / a) * b;
		answer += n;

		if (n < a)
		{
			n += value;
			value = 0;
		}
	}

	return answer;
}