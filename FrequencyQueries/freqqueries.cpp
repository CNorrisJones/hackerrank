#include <bits/stdc++.h>
using namespace std;
https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int,int> current_map;
    map<int, int> freq_map;
    vector<int> ret_vals;
    int new_freq;
    int pre_val;

    for (int iter = 0; iter < queries.size(); ++iter) {
        switch(queries[iter][0]) {
            case (1) :
                // update current
                ++current_map[queries[iter][1]];
                // update frequency
                new_freq = current_map[queries[iter][1]];
                freq_map[new_freq-1] = max(0, freq_map[new_freq-1]-1);
                ++freq_map[new_freq];
                break;
            case 2 :
                // update current
                pre_val = current_map[queries[iter][1]];
                current_map[queries[iter][1]] = max(0, current_map[queries[iter][1]]-1);
                // update frequency
                if (pre_val!=0) {
                    new_freq = current_map[queries[iter][1]];
                    freq_map[new_freq+1] = max(0, freq_map[new_freq+1]-1);
                    ++freq_map[new_freq];
                }
                break;
            case 3 :
                // Check freq map if freq exists
                if (freq_map[queries[iter][1]] > 0 ) {
                    ret_vals.emplace_back(1);
                } else ret_vals.emplace_back(0);
        }
    }
    return ret_vals;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}