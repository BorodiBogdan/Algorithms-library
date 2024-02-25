//https://www.pbinfo.ro/probleme/1584/spirala2
#include <bits/stdc++.h>
#define Oji2020 ios::sync_with_stdio(false); fin.tie(0);fout.tie(0);
using namespace std;

ifstream fin("spirala2.in");
ofstream fout("spirala2.out");

int M[1001][1001];

int main()
{
    Oji2020

    long long n , j = 1 , i = 1 , x1 = 1 , c = 0 , con , k , s = 0;
    bool ok = 1;

    fin >> con;
    fin >> n >> k;

    while(ok)
    {
        i = x1;
        for(j = x1 ; j <= n - x1 + 1; j++)
            c++, M[i][j] = c;
        j = n - x1 + 1;
        for(int i = x1 + 1 ; i <= n - x1 + 1 ; i++)
            c++ , M[i][j] = c;
        i = n - x1 + 1;
        for(int j = n - x1  ; j >= x1 ; j--)
            c++ , M[i][j] = c;
            j = x1;
        for(int i = n - x1  ; i >= x1 + 1; i--)
            c++ , M[i][j] = c;
        x1++;
        if(c >= n * n)
        ok = 0;
    }
    if(con == 1)
    {
        for(int i = 1 ; i <= n ; i++)
            s = s + M[k][i]% 100003;
        for(int i = 1 ; i <= n ; i++)
            s = s + M[i][k] % 100003;
            s = s - 2 * (M[k][k] % 100003);
            fout << s;
    }
    else
    {
         for(int i = 1 ; i <= n ; i++)
            swap(M[i][k] , M[k][i]);
         for(int i = 1 ; i <= n ; i++)
         {
             for(int j = 1 ; j <= n ; j++)
                fout << M[i][j] << " ";

            fout <<  "\n";
        }
    }
}
