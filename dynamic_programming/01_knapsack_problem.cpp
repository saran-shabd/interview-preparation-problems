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
    int solve(const vi& values, const vi& weights, int knapsack_weight);
};

int Solver::solve(const vi& values, const vi& weights, int knapsack_weight) {
    
    // create two dimensional array for storing intermediate results
    int result[values.size() + 1][knapsack_weight + 1];

    fi (values.size() + 1) {
        fj (knapsack_weight + 1) {
            // base case
            if (0 == i or 0 == j)
                // either there are no items left or the knapsack is full
                result[i][j] = 0;
            
            else {
                // check if weight of current item is larger than knapsack space left
                if (weights[i - 1] > j)
                    // don't include current item
                    result[i][j] = result[i - 1][j];
    
                else {
                    // case 1 : include current item
                    int included = values[i - 1] + result[i - 1][j - weights[i - 1]];

                    // case 2 : don't include current item
                    int not_included = result[i - 1][j];

                    // maximum of both cases
                    result[i][j] = max(included, not_included);
                }
            }
        }
    }

    return result[values.size()][knapsack_weight];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int values_count; cin >> values_count;
        vector<int> values(values_count);
        vector<int> weights(values_count);
        fi (values_count) cin >> values[i];
        fi (values_count) cin >> weights[i];
        int knapsack_weight; cin >> knapsack_weight;

        int result = solver->solve(values, weights, knapsack_weight);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
