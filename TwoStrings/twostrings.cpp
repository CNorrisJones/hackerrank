#include <bits/stdc++.h>
using namespace std;
https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    unordered_map<char, bool> sub_map;
    string ret_str = "NO";

    for (int iter = 0; iter < s1.size(); ++iter) {
        sub_map[s1[iter]] = true;
    }
    for (int iter = 0; iter < s2.size(); ++iter) {
        if (sub_map[s2[iter]] == true) {
            ret_str = "YES";
            break;
        }
    }
    return ret_str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}