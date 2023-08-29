// Q: https://www.eolymp.com/en/problems/975
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mat[n+1][n+1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    int maximum = 0;
    for (int i = 0; i < n; i++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if(mat[u][i] != -1 && mat[i][v] != -1)
                {
                    if (mat[u][v] == -1 || mat[u][i] + mat[i][v] < mat[u][v])
                        mat[u][v] = mat[u][i] + mat[i][v];
                }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            maximum = max(maximum, mat[i][j]);
    cout << maximum;
    return 0;
}