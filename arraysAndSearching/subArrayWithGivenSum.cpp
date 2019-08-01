#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

typedef pair<int, int> pi;

class Solver {
public:
    pi solve(vector<int>& arr, int& sum);
};

pi Solver::solve(vector<int>& arr, int& sum) {
    int currSum = 0;

    int start = 0, end = 0;
    while (true) {
        while (end < arr.size() && currSum < sum)
            currSum += arr[end++];
        
        if (end == arr.size()) break;

        if (sum == currSum) return { start + 1, end };

        while (start <= end && currSum > sum)
            currSum -= arr[start++];
    }

    while (start < end && currSum > sum)
        currSum -= arr[start++];
        
    if (sum == currSum) return { start + 1, end };

    return { -1, -1 };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int arrSize; cin >> arrSize;
        int sum; cin >> sum;
        vector<int> arr(arrSize);
        fi (arrSize) cin >> arr[i];

        pi result = solver->solve(arr, sum);
        if (-1 != result.first)
            cout << result.first << " " << result.second << "\n";
        else
            cout << -1 << "\n";
    }

    delete solver;

    return 0;
}
