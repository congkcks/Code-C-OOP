#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int count_quadruples(vector<int>& A) {
    int N = A.size();
    unordered_map<int, vector<pair<int, int>>> sums;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int sum_ij = A[i] + A[j];
            sums[sum_ij].push_back({i, j});
        }
    }

    int count = 0;
    for (auto& kv : sums) {
        auto& pairs = kv.second;
        for (int i = 0; i < pairs.size(); ++i) {
            for (int j = i+1; j < pairs.size(); ++j) {
                if (pairs[i].second < pairs[j].first) {
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {
    // Test v?i m?t m?ng m?u
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x :v) cin>>x;
    cout << count_quadruples(v) << endl;

    return 0;
}

