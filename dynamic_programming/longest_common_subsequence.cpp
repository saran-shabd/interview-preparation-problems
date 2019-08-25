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
    int solve(const string& str1, const string& str2);
private:
    int helper(const string& str1, const string& str2, int index1, int index2, vii& result);
};

int Solver::solve(const string& str1, const string& str2) {

    // check for empty strings
    if (0 == str1.length() or 0 == str2.length()) return 0;

    // two dimensional array to store intermediate results
    vii result(str1.length(), vi(str2.length(), INT32_MIN));

    return helper(str1, str2, str1.length() - 1, str2.length() - 1, result);
}

int Solver::helper(const string& str1, const string& str2, int index1, int index2, vii& result) {

    // base case
    if (index1 < 0 or index2 < 0) return 0;

    // check if current case is already in intermediate results
    if (INT32_MIN != result[index1][index2]) return result[index1][index2];

    int curr_result = 0;

    // compare last characters of both the strings
    if (str1[index1] == str2[index2])
        // characters match
        curr_result = 1 + helper(str1, str2, index1 - 1, index2 - 1, result);
    
    else {
        // case 1 : decrease string 1 index
        int str1_decreased = helper(str1, str2, index1 - 1, index2, result);

        // case 2 : decrease string 2 index
        int str2_decreased = helper(str1, str2, index1, index2 - 1, result);

        // return maximum of both the cases
        curr_result = max(str1_decreased, str2_decreased);
    }

    result[index1][index2] = curr_result;

    return curr_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int str1_size, str2_size; cin >> str1_size >> str2_size;
        string str1, str2; cin >> str1 >> str2;

        int result = solver->solve(str1, str2);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
