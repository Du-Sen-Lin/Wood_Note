// LCS:The longest common subsequence 最长公共子序列
/*示例
对于给定的两个字符串，它们之间的相同序列的最大长度是多少,并输出最长公共子序列 字符串长度为n。
Input:
    abchifkdacb
    bcacbhiab
Output:
    6 bchiab

Input:
    AGGTAB
    GXTXAYB
Output:
    4 GTAB

题解：动态规划。
时间复杂度:O(m*n)。
状态转移方程：dp[i][j] 表示字符串 X 的前 i 个字符与字符串 Y 的前 j 个字符的最长公共子序列的长度。
动态规划表：
  Y G X T X A Y B
X 0 0 0 0 0 0 0 0
A 0 0 0 0 0 1 1 1
G 0 1 1 1 1 1 1 1
G 0 1 1 1 1 1 1 1
T 0 1 1 2 2 2 2 2
A 0 1 1 2 2 3 3 3
B 0 1 1 2 2 3 3 3

初始化：将第一行和第一列的值设为0，表示当一个字符串为空时，与另一个字符串的最长公共子序列长度为0。
更新 dp[i][j] 的值, 状态转移方程：如果 X[i-1] 等于 Y[j-1]，则 dp[i][j] = dp[i-1][j-1] + 1，表示最长公共子序列长度加1。否则，dp[i][j] = max(dp[i-1][j], dp[i][j-1])，取左方和上方的最大值。

打印最长公共子序列：回溯找到最长公共子序列：从右下角开始，根据表格的信息，逆向回溯，构造最长公共子序列。

如果忽略大小写：如果X[i-1] == Y[j-1] || abs(X[i-1] - Y[j-1])==32, 则 dp[i][j] = dp[i-1][j-1] + 1

如果需要打印所有最长公共子序列：findAllLCS
*/


#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<set>

using namespace std;


// 动态规划
void LCSdp(string X, string Y, int m, int n) {
    int dp[m+1][n+1];
    string lcs;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << "Length of LCS is " << dp[m][n] << endl;

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS is " << lcs << endl;

}

void findAllLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    set<string> lcsList; // 用于存储所有找到的最长公共子序列，这里使用集合是为了自动去重。

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int length = dp[m][n]; // 最长公共子序列的长度

    if (length == 0) {
        cout << "No LCS found" << endl;
        return;
    }

    string currentLCS = ""; //  创建一个空字符串 currentLCS 用于在回溯过程中存储当前的LCS。

    function<void(int, int)> backtrack = [&](int i, int j) { // lambda函数，它使用递归方式进行回溯，以找到所有的最长公共子序列。
        if (i == 0 || j == 0) {
            lcsList.insert(currentLCS);
            return;
        }

        if (X[i-1] == Y[j-1]) { // 当前字符相等，将当前字符加入 currentLCS 中，然后继续向前回溯。
            currentLCS = X[i-1] + currentLCS;
            backtrack(i-1, j-1);
            currentLCS = currentLCS.substr(1);
        } else { // 当前字符不相等，则根据 dp 数组的值选择向左回溯还是向上回溯，以找到其他的可能的LCS。
            if (dp[i-1][j] >= dp[i][j-1]) {
                backtrack(i-1, j);
            }

            if (dp[i][j-1] >= dp[i-1][j]) {
                backtrack(i, j-1);
            }
        }
    };

    backtrack(m, n); // 开始回溯的入口，从字符串的最后一个字符开始

    cout << "Length of LCS is " << length << endl;
    cout << "All LCS are:" << endl;

    for (const string& lcs : lcsList) { // 输出所有找到的最长公共子序列。
        cout << lcs << endl;
    }
}

int main() {
    // string X = "AGGTaB";
    // string Y = "GXTXAYB";
    string X = "abchifkdacb";
    string Y = "bcacbhiab";
    int m = X.length();
    int n = Y.length();

    LCSdp(X, Y, m, n);
    findAllLCS(X, Y);

    return 0;
}

// g++ LCS_dp.cpp -o LCS_dp
// ./LCS_dp
