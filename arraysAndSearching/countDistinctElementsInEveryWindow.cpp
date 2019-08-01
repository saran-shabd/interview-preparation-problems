#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

class Solver {
public:
    void solve(vector<int>& arr, int windowSize);
};

void Solver::solve(vector<int>& arr, int windowSize) {
    unordered_map<int, int> hashTable;

    fi(windowSize) ++hashTable[arr[i]];
    cout << hashTable.size() << " ";

    for (int i = 1; i <= arr.size() - windowSize; ++i) {
        // remove first element from hash table
        --hashTable[arr[i - 1]];
        if (0 == hashTable[arr[i - 1]])
            hashTable.erase(arr[i - 1]);
            
        // add last element into the hash table
        ++hashTable[arr[i + windowSize - 1]];

        cout << hashTable.size() << " ";
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
        int windowSize; cin >> windowSize;
        vector<int> arr(arrSize);
        fi(arrSize) cin >> arr[i];

        solver->solve(arr, windowSize);
    }

    delete solver;

    return 0;
}
