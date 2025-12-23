#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> numbers;
    int X;
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int value = 0;
        cin >> value;
        numbers.push_back(value);
    }
    sort(numbers.begin(), numbers.end());
    cin >> X;
    
    int start = 0;
    int end = N - 1;
    int sum = 0;

    while (start < end) 
    {
        int count = numbers[start] + numbers[end];

        if (count < X) 
        {
            start++;
        } 
        else if (count > X) 
        {
            end--;
        } 
        else 
        { 
            sum++;
            start++;
            end--;   
        }
    }
    cout << sum << endl;
    return 0;
}