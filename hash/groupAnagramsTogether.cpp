#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    void solve(vector<string>& arr);
};

void Solver::solve(vector<string>& arr) {
    unordered_map<int, int> hashtable;
    for (string word : arr) {
        int value = 0;
        for (char item : word) value += (item - 'a') * (item - 'a') * (item - 'a');
        ++hashtable[value];
    }

    priority_queue<int, vector<int>, greater<int>> result;
    for (pair<int, int> item : hashtable)
        result.push(item.second);
    
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int arrSize; cin >> arrSize;
        vector<string> arr(arrSize);
        fi(arrSize) cin >> arr[i];

        solver->solve(arr);
    }

    delete solver;

    return 0;
}
