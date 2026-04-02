#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int initial_ones = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) initial_ones++;
    }

    int max_gain = -1; // 무조건 한 번은 뒤집어야 하므로 최솟값을 -1로 설정
    int current_gain = 0;

    for (int i = 0; i < n; ++i) {
        // 0을 뒤집으면 1이 되므로 이득(+1), 1을 뒤집으면 0이 되므로 손실(-1)
        int val = (a[i] == 1) ? -1 : 1;

        current_gain = max(val, current_gain + val);
        max_gain = max(max_gain, current_gain);
    }

    cout << initial_ones + max_gain << "\n";

    return 0;
}