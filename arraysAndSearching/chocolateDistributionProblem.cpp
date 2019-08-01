#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    int solve(vector<int>& arr, int studentsCount);
};

int Solver::solve(vector<int>& arr, int studentsCount) {
    sort(arr.begin(), arr.end());

    int minDiff = INT32_MAX;
    for (int i = 0; i <= arr.size() - studentsCount; ++i)
        minDiff = min(minDiff, arr[i + studentsCount - 1] - arr[i]);

    return minDiff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int arrSize; cin >> arrSize;
        vector<int> arr(arrSize);
        fi(arrSize) cin >> arr[i];
        int studentsCount; cin >> studentsCount;

        int result = solver->solve(arr, studentsCount);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
