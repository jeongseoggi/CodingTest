#include <string>
#include <vector>

using namespace std;

int test(int n, int m)
{
    if (n % m == 0)
    {
        return m;
    }
    else
    {
        return test(m, n % m);
    }

}

vector<int> solution(int n, int m) {
    vector<int> answer;

    int temp = test(n, m);
    answer.push_back(temp);
    answer.push_back((n * m) / temp);


    return answer;
}
