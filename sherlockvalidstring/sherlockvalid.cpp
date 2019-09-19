#include <string>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    // First sort, at cost of O(nlog(n))

    if (s.size() == 1) {
        return "YES";
    }

    sort(s.begin(), s.end());
    for (int iter = 0; iter < s.size(); ++iter) {
    }
    char current = s[0];
    unsigned cur_count = 1;
    unsigned min = 0;
    unsigned max = 0;
    unsigned min_count = 0;
    unsigned max_count = 0;
    set<int> freq;

    // Iterate through sorted string, holding min and max frequencies, and counts of both
    // Cost of O(n)
    
    for (int iter = 1; iter < s.size(); ++iter) {
        if (s[iter] == current) {
            ++cur_count;
        } else {
            current = s[iter];
            if (min == 0) {
                min = cur_count;
                max = cur_count;
                min_count = 1;
                max_count = 1;
                freq.insert(cur_count);
                cur_count = 1;

                continue;
            }

            if (cur_count == min) {
                ++min_count;
            } else if (cur_count < min) {
                min = cur_count;
                min_count = 1;
            }
            if (cur_count == max) {
                ++max_count;
            } else if (cur_count > max) {
                max = cur_count;
                max_count = 1;
            }
            freq.insert(cur_count);
            cur_count = 1;
        }
    }
    // Enter in last step
    freq.insert(cur_count);
    if (cur_count == min) {
                ++min_count;
            } else if (cur_count < min) {
                min = cur_count;
                min_count = 1;
            }
            if (cur_count == max) {
                ++max_count;
            } else if (cur_count > max) {
                max = cur_count;
                max_count = 1;
            }

    cout << "Min: " << min << endl << "Max: " << max << endl << "Min count: " << min_count << endl << "Max count: " << max_count << endl;
    cout << "Freq is " << freq.size() << endl;
    if(freq.size() > 2) {
        return "NO";
    }
    if (min != max) {
        if ((max-min) != 1) {
            if (min == 1 && min_count == 1) {
                return "YES";
            }
            return "NO";
        } else if (min_count != 1 && max_count != 1) {
            return "NO";
        }
    }
    return "YES";
}
