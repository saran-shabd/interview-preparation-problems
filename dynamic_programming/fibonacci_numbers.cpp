#include <bits/stdc++.h>
using namespace std;

#define fi(a) for (int i = 0; i < a; ++i)
#define fj(a) for (int j = 0; j < a; ++j)
#define pb push_back
#define mp make_pair

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pi> vpi;

/**
 * this solution cannot deal with large numbers, for that same solution has been
 * written in Python
*/

class Solver {
public:
    vector<int> solve(const int& n);
};

vector<int> Solver::solve(const int& n) {
    vector<int> result;
    
    // edge cases

    if (0 == n) return result;

    result.pb(1);
    if (1 == n) return result;

    result.pb(1);
    if (2 == n) return result;

    // compute fibonacci numbers
    for (int i = 2; i < n; ++i)
        result.pb(result[i-1] + result[i-2]);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int n; cin >> n;

        vector<int> result = solver->solve(n);
        for (int item : result) cout << item << " "; cout << "\n";
    }

    delete solver;

    return 0;
}
