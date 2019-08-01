#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    int solve(vector<int>& arr);
private:
    int helper(vector<int>& arr, int start, int end);
};

int Solver::solve(vector<int>& arr) {
    if (1 == arr.size()) return 0;
    if (arr[0] >= arr[1]) return 0;
    if (arr[arr.size() - 1] >= arr[arr.size() - 2]) return arr.size() - 1;

    return this->helper(arr, 0, arr.size() - 1);
}

int Solver::helper(vector<int>& arr, int start, int end) {
    if (start > end) return -1;
    
    int middle = (start + end) / 2;
    if (arr[middle] >= arr[middle - 1] && arr[middle] >= arr[middle + 1])
        return middle;
    
    if (arr[middle] < arr[middle - 1])
        return this->helper(arr, start, middle - 1);
    
    return this->helper(arr, middle + 1, end);
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

        int result = solver->solve(arr);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
