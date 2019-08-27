#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vii;

class Solver {
public:
    int solve(const vector<int>& arr, const int& change);
private:
    int helper(const vector<int>& arr, const int& change, const int& coin_index, vii& result);
};

int Solver::solve(const vector<int>& arr, const int& change) {

    // two dimensional array to store intermediate results
    vii result(change + 1, vi(arr.size(), INT32_MIN));

    return helper(arr, change, arr.size() - 1, result);
}

int Solver::helper(const vector<int>& arr, const int& change, const int& coin_index, vii& result) {

    // base case
    if (0 == change) return 1;
    
    // if change left is negetive
    if (0 > change) return 0;

    // if there are no coins left
    if (0 > coin_index and 0 < change) return 0;

    // check if this case has already been computed
    if (INT32_MIN != result[change][coin_index]) return result[change][coin_index];

    // computer result for current case
    int curr_result = helper(arr, change - arr[coin_index], coin_index, result) +
                        helper(arr, change, coin_index - 1, result);

    // store the result
    result[change][coin_index] = curr_result;

    return curr_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int n; cin >> n;
        vector<int> arr(n); fi (n) cin >> arr[i];
        int change; cin >> change;

        int result = solver->solve(arr, change);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
