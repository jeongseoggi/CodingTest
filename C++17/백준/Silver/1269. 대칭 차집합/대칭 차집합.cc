#include <iostream>
#include <map>

using namespace std;

int main()
{
	int A, B;
	int count = 0;
	map<int, int> maps;
	while (true)
	{
		cin >> A >> B;

		for (int i = 0; i < A; ++i)
		{
			int value;
			cin >> value;
			maps[value]++;
		}

		for (int i = 0; i < B; ++i)
		{
			int value;
			cin >> value;
			maps[value]++;
		}


		
		for (auto it = maps.begin(); it != maps.end(); ++it)
		{
			if (it->second < 2)
			{
				count++;
			}
		}

		break;

	}


	cout << count << endl;


	return 0;
}