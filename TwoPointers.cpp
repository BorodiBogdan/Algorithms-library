//https://www.pbinfo.ro/probleme/1989/teatru    
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
#define IN ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define OUT fin.close();fout.close();return 0;
using namespace std;
 
ifstream fin("teatru.in");
ofstream fout("teatru.out");
 
 
int n, m;
char S[60001];
int F[201];
 
queue <char>Q;
 
int main(void) {
    IN
 
    fin >> n >> m;
    fin >> S;
 
    int sumlit = 0, maxi = -1, ii = 0, jj = 0;
 
    for (int i = 0; i < n; i++) {
        Q.push((int)S[i]);
        F[(int)S[i]]++;
 
 
        if (F[(int)S[i]] == 1)
            sumlit++;
 
        if (sumlit > m) {
            while (sumlit > m && !(Q.empty())) {
                int r = (int)Q.front();
 
                F[r]--;
 
                Q.pop();
 
                if (F[r] == 0)
                    sumlit--;
            }
        }
        int t = Q.size();
        if (t > maxi && sumlit == m) {
            maxi = t;
            jj = i;
            ii = i - t + 1;
        }
    }
    fout << maxi << "\n";
 
    for (int i = ii; i <= jj; i++)
        fout << S[i];
 
    OUT
}
