#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Longest Common Substring
void LCS(string A, string B)
{
    // A.len * B.len matrix
    int l[50][50];

    // initialization
    for (int i = 0; i < B.length(); i++)
    {
        if (A[0] == B[i])
        {
            for (int k = i; k < B.length(); k++)
                l[0][k] = 1;
            break;
        }
        l[0][i] = 0;
    }
    for (int i = 0; i < A.length(); i++)
    {
        if (B[0] == A[i])
        {
            for (int k = i; k < A.length(); k++)
                l[k][0] = 1;
            break;
        }
        l[i][0] = 0;
    }

    // caculation
    for (int i = 1; i < A.length(); i++)
    {
        for (int j = 1; j < B.length(); j++)
        {
            if (A[i] == B[j])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
            {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }

    // print out l
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << l[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    string A = "1356";
    string B = "123456";
    LCS(A, B);
}