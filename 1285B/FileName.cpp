#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 왼쪽에서 오른쪽으로 누적합 검사 (전체 원소 선택 제외를 위해 n-1까지)
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += a[i];
        if (sum <= 0) {
            cout << "NO\n";
            return;
        }
    }

    // 오른쪽에서 왼쪽으로 누적합 검사 (전체 원소 선택 제외를 위해 인덱스 1까지)
    sum = 0;
    for (int i = n - 1; i > 0; --i) {
        sum += a[i];
        if (sum <= 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}