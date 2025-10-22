#include <iostream>
#include <cmath>
#include <iomanip>  // for setw, setfill
using namespace std;

int main() {
    while (true) {
        int M, A, B;
        cin >> M >> A >> B;
        if (M == 0 && A == 0 && B == 0) {
            break;
        }
        // 시간 차이(초 단위) 계산
        double timeTrain = static_cast<double>(M) / A;      // 시간 단위
        double timePlane = static_cast<double>(M) / B;
        double diffHours = timeTrain - timePlane;
        double diffSecondsDouble = diffHours * 3600.0;
        long diffSeconds = static_cast<long>(round(diffSecondsDouble));

        long h = diffSeconds / 3600;
        long m = (diffSeconds % 3600) / 60;
        long s = diffSeconds % 60;

        // 출력: 시:분:초, 분과 초 두 자리
        cout << h << ":"
            << setw(2) << setfill('0') << m << ":"
            << setw(2) << setfill('0') << s << "\n";
    }
    return 0;
}