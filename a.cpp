#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, A, B, C;
        cin >> N >> A >> B >> C;
        bool possible = false;

        for (int x = 0; x <= N; ++x) {
            int y = N - x;
            if (x <= A && x <= B && y <= B - x && y <= C) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}