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
    int solve(const vector<int>& arr, const int& sum);
private:
    int helper(const vector<int>& arr, const int& sum, const int& curr_index, const int& curr_sum, vii& result);
};

int Solver::solve(const vector<int>& arr, const int& sum) {

    // two dimensional array to store intermediate results
    vii result(arr.size(), vi(sum + 1, INT32_MIN));

    return helper(arr, sum, 0, 0, result);
}

int Solver::helper(const vector<int>& arr, const int& sum, const int& curr_index, const int& curr_sum, vii& result) {

    // base case
    if (arr.size() == curr_index) return 0;

    // check if current case is already in computed results
    if (INT32_MIN != result[curr_index][curr_sum]) return result[curr_index][curr_sum];

    int curr_result = 0;

    // check for subset with given sum
    if (curr_sum + arr[curr_index] == sum) curr_result = 1;

    else {
        // check for edge cases
        if (curr_sum + arr[curr_index] > sum)
            // don't include current element
            curr_result = helper(arr, sum, curr_index + 1, curr_sum, result);

        else {
            // case 1 : add current element to subset
            int included = helper(arr, sum, curr_index + 1, curr_sum + arr[curr_index], result);

            // case 2 : don't add current element to subset
            int not_included = helper(arr, sum, curr_index + 1, curr_sum, result);

            // sum of both the cases
            curr_result = included + not_included;
        }
    }
    
    // store the intermediate result
    result[curr_index][curr_sum] = curr_result;

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
        int sum; cin >> sum;

        int result = solver->solve(arr, sum);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
