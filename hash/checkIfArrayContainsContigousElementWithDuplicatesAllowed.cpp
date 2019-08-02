#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    string solve(vector<int>& arr);
};

string Solver::solve(vector<int>& arr) {
    unordered_set<int> set;
    fi(arr.size()) set.insert(arr[i]);

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int item : set) minHeap.push(item);

    int prev = minHeap.top(); minHeap.pop();
    while (!minHeap.empty()) {
        int curr = minHeap.top(); minHeap.pop();
        if (1 != curr - prev) return "No";
        prev = curr;
    }

    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int arrSize; cin >> arrSize;
        vector<int> arr(arrSize);
        fi (arrSize) cin >> arr[i];

        string result = solver->solve(arr);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
