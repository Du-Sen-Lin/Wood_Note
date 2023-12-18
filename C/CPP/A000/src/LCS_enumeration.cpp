// ----------- 时间复杂度的理解与计算 ---------------
// LCS:The longest common subsequence 最长公共子序列
/*示例
对于给定的两个字符串，它们之间的相同序列的最大长度是多少,并输出最长公共子序列 字符串长度为n。
Input:
    abchifkdacb
    bcacbhiab
Output:
    6 bchiab

题解：枚举法（用于理解时间复杂度），对于第一个字符串，枚举所有子序列复杂度 2^n, 对于第二个字符串，枚举复杂度 2^n, 最大长度为n, 比较的复杂度为n。
因此时间复杂度为2^n*2^n*n, 为指数级的复杂度，如果n的长度为100，2^100*2^100*100 = 10^62; 竞赛普通计算机每秒的操作次数为10^7, 所以运行时间为 10^62/10^7=10^55秒=10^47年。
长度为10, 2^10=1024; 10^3*10^3*10=10^7，也基本要超时了。
*/
#include<iostream>
#include<string>

using namespace std;

// 递归方式
int lcsRecursive(string X, string Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcsRecursive(X, Y, m-1, n-1);
    else
        return max(lcsRecursive(X, Y, m, n-1), lcsRecursive(X, Y, m-1, n));
}

void printLCSRecursive(string X, string Y, int m, int n) {
    if (m == 0 || n == 0)
        return;

    if (X[m-1] == Y[n-1]) {
        printLCSRecursive(X, Y, m-1, n-1);
        cout << X[m-1];
    } else if (lcsRecursive(X, Y, m, n-1) > lcsRecursive(X, Y, m-1, n)) {
        printLCSRecursive(X, Y, m, n-1);
    } else {
        printLCSRecursive(X, Y, m-1, n);
    }
}

// 输出所有的最长公共子序列
void printAllLCS(string X, string Y, int m, int n, string lcs) {
    if (m == 0 || n == 0) {
        cout << lcs << endl;
        return;
    }

    if (X[m-1] == Y[n-1]) {
        printAllLCS(X, Y, m-1, n-1, X[m-1] + lcs);
    } else {
        if (m > 0 && n > 0 && lcsRecursive(X, Y, m, n-1) >= lcsRecursive(X, Y, m-1, n)) {
            printAllLCS(X, Y, m, n-1, lcs);
        }

        if (m > 0 && n > 0 && lcsRecursive(X, Y, m-1, n) >= lcsRecursive(X, Y, m, n-1)) {
            printAllLCS(X, Y, m-1, n, lcs);
        }
    }
}


int main() {
    // string X = "AGGTAB";
    // string Y = "GXTXAYB"; // GTAB
    string X = "abchifkdacb";
    string Y = "bcacbhiab"; // bchiab; abhiab
    int m = X.length();
    int n = Y.length();

    int length = lcsRecursive(X, Y, m, n);
    cout << "Length of LCS (Recursive) is " << length << endl;

    cout << "LCS (Recursive) is ";
    printLCSRecursive(X, Y, m, n);
    cout << std::endl;

    cout << "All LCS (Recursive) are:" << endl;
    printAllLCS(X, Y, m, n, "");
    cout << std::endl;

    return 0;
}

// g++ LCS_enumeration.cpp -o LCS_enumeration
// ./LCS_enumeration
