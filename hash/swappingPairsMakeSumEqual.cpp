#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    int solve(vector<int>& arr1, vector<int>& arr2);
};

int Solver::solve(vector<int>& arr1, vector<int>& arr2) {
    int sum1 = 0, sum2 = 0;
    for (int item : arr1) sum1 += item;
    for (int item : arr2) sum2 += item;
    int diff = abs(sum1 - sum2);

    if (0 == diff) return 0;

    unordered_set<int> elements;
    for (int item : arr2) elements.insert(item);

    for (int item : arr1) {
        if (elements.end() != elements.find(diff/2 + item))
            return 1;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int arr1Size, arr2Size; cin >> arr1Size >> arr2Size;
        vector<int> arr1(arr1Size);
        vector<int> arr2(arr2Size);
        fi (arr1Size) cin >> arr1[i];
        fi (arr2Size) cin >> arr2[i];

        int result = solver->solve(arr1, arr2);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
