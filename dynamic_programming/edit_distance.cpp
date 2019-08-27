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

class Solver {
public:
    int solve(const string& str1, const string& str2);
private:
    int helper(const string& str1, const string& str2, const int& index1, const int& index2, vii& result);
};

int Solver::solve(const string& str1, const string& str2) {

    // base case
    if (str1 == str2) return 0;
    
    // two dimensional array to store intermediate results
    vii result(str1.length(), vi(str2.length(), INT32_MAX));

    return helper(str1, str2, 0, 0, result);
}

int Solver::helper(const string& str1, const string& str2, const int& index1, const int& index2, vii& result) {

    // base case
    if (str1.length() == index1) return str2.length() - index2;
    if (str2.length() == index2) return str1.length() - index1;

    // check if current case has already been computed
    if (INT32_MAX != result[index1][index2]) return result[index1][index2];

    int curr_result;

    // current index value matches
    if (str1[index1] == str2[index2])
        curr_result = helper(str1, str2, index1 + 1, index2 + 1, result);
    
    else {
        // delete current index value from str1
        int curr_delete = helper(str1, str2, index1 + 1, index2, result);

        // insert current index str2 value into str1
        int curr_insert = helper(str1, str2, index1, index2 + 1, result);

        // replace current index str1 value from current index str2 value
        int curr_replace = helper(str1, str2, index1 + 1, index2 + 1, result);

        curr_result = 1 + min(curr_delete, min(curr_insert, curr_replace));
    }

    // store the result
    result[index1][index2] = curr_result;

    return curr_result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver* solver = new Solver();

    int testcase; cin >> testcase;
    while (testcase--) {
        int str1_len, str2_len; cin >> str1_len >> str2_len;
        string str1, str2; cin >> str1 >> str2;

        int result = solver->solve(str1, str2);
        cout << result << "\n";
    }

    delete solver;

    return 0;
}
