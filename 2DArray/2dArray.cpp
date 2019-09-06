#include <bits/stdc++.h>
using namespace std;
// https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    // Set initial hourglass locations and value
    int vert_l, ht_l = 0;
    int max_val = arr[ht_l][vert_l] + arr[ht_l][vert_l+1] + arr[ht_l][vert_l+2] + arr[ht_l+1][vert_l+1] + arr[ht_l+2][vert_l] + arr[ht_l+2][vert_l+1] + arr[ht_l+2][vert_l+2], temp_val;

    // Iterate through possible hourglasses, O((n-2)*(m-2))
    while (ht_l < arr.size()-2) {
        vert_l = 0;
        vector<int> inner_arr = arr[ht_l];
        while (vert_l < inner_arr.size()-2) {
            temp_val = arr[ht_l][vert_l] + arr[ht_l][vert_l+1] + arr[ht_l][vert_l+2] + arr[ht_l+1][vert_l+1] + arr[ht_l+2][vert_l] + arr[ht_l+2][vert_l+1] + arr[ht_l+2][vert_l+2];
            max_val = (temp_val > max_val) ? temp_val : max_val;
            ++vert_l;
        }
        ++ht_l;
    }
    
    return max_val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}