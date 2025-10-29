#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	map<int, int> map1;
	vector<int> v;

	int num1;
	int num2;

	cin >> num1;

	for (int i = 0; i < num1; ++i)
	{
		int value;
		cin >> value;
		map1[value]++;
	}

	cin >> num2;
	for (int i = 0; i < num2; ++i)
	{
		int value;
		cin >> value;

		if (map1.find(value) != map1.end())
		{
			v.push_back(1);
		}
		else
		{
			v.push_back(0);
		}
	}


	for (int num : v)
	{
		cout << num << " ";
	}

	return 0;
}
