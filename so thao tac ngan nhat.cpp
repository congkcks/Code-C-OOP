#include<bits/stdc++.h>
using namespace std;

int solve(int s, int t) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({s, 0});
    visited.insert(s);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == t) {
            return steps;
        }

        int next = current * 2;
        if (next <= t && visited.find(next) == visited.end()) {
            q.push({next, steps + 1});
            visited.insert(next);
        }

        next = current - 1;
        if (next > 0 && visited.find(next) == visited.end()) {
            q.push({next, steps + 1});
            visited.insert(next);
        }
    }

    return -1;
}

int main() {
    int s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}

