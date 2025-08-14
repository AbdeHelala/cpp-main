#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

const int MATCH = 1;
const int MISMATCH = -1;
const int GAP = -1;

int score(char a, char b) {
  //helper function: give two characters, then return the score if its (match or mismatch)
    return (a == b) ? MATCH : MISMATCH;
}

int main(int argc, const char *argv[])
{
  // ARGUMENT CHECK, CHECK NUMBER OF ARGUMNETS ARE CORRECT, IF NOT RETURN A MESSAGE FOR THE CORRECT FORMAT
  // IF ITS CORRECT, THEN ASSIGN THE ARGUMENTS TO s1 for first sequence AND s2 for second sequence
    // AND ASSIGN THE LENGTH OF s1 TO m AND LENGTH OF s2 TO n
  if (argc != 3) {
        std::cerr << "Usage: ./task4 string1 string2\n";
        return 1;
    }
  std::string s1 = argv[1];
    std::string s2 = argv[2];
    int m = s1.size();
    int n = s2.size();
    // dp matrix to store the scores
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    //Fill in base cases (first row, first column)
    for (int i = 0; i <= m; ++i) dp[i][0] = i * GAP;
    for (int j = 0; j <= n; ++j) dp[0][j] = j * GAP;
    //fill in the dp matrix, for each cell, check diagonal(match or mismatch), up(gap in s2), left(gap in s1)
    //then take the best max score
        for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int match_mis = dp[i - 1][j - 1] + score(s1[i - 1], s2[j - 1]);
            int delete_s1 = dp[i - 1][j] + GAP;
            int delete_s2 = dp[i][j - 1] + GAP;
            dp[i][j] = std::max({match_mis, delete_s1, delete_s2});
        }
    }

    //prpare the traceback, a recursive fucntion, start from the bottom right corner, then 
    //walks backwards along all valid paths, and print the aligned sequences
      
    std::vector<std::pair<std::string, std::string>> alignments;

    std::function<void(int, int, std::string, std::string)> traceback =
     [&](int i, int j, std::string a1, std::string a2) {
            if (i == 0 && j == 0) {
                alignments.push_back({a1, a2});
                return;
            }
            if (i > 0 && dp[i][j] == dp[i - 1][j] + GAP) {
                traceback(i - 1, j, s1[i - 1] + a1, '-' + a2);
            }
            if (j > 0 && dp[i][j] == dp[i][j - 1] + GAP) {
                traceback(i, j - 1, '-' + a1, s2[j - 1] + a2);
            }
            if (i > 0 && j > 0 &&
                dp[i][j] == dp[i - 1][j - 1] + score(s1[i - 1], s2[j - 1])) {
                traceback(i - 1, j - 1, s1[i - 1] + a1, s2[j - 1] + a2);
            }
        };

        // run the traceback function starting from the bottom right corner of the dp matrix
        // print results
            traceback(m, n, "", "");

    std::cout << dp[m][n] << "\n";
    for (const auto& [a1, a2] : alignments) {
        std::cout << a1 << "\n" << a2 << "\n\n";
    }

    return 0;
}




