//problem link: https://www.pbinfo.ro/probleme/4116/superhedgy
#include <fstream>
#include <cmath>
#define int long long
using namespace std;

ifstream fin("superhedgy.in");
ofstream fout("superhedgy.out");

int n, m;

struct cladire{
    int l, h, e;
}C1[100001], C2[100001];


int32_t main(){
    fin >> n;

    for(int i = 1; i <= n; ++i)
        fin >> C1[i].l >> C1[i].h >> C1[i].e;
    
    fin >> m;

    for(int i = 1; i <= m; ++i)
        fin >> C2[i].l >> C2[i].h >> C2[i].e;

    //in i si j pe ce cladiri ne aflam
    //i -> cladirea de pe lv 1
    //j -> cladirea de pe lv 2

    int i = 0, j = 0;

    int dp1 = 0, dp2 = 0;//energia minima de a ajunge pe blocul i

    while(i <= n && j <= m){
        int lift = C1[i].e + C2[j].e;
        int d_parcursa = min(C1[i].l, C2[j].l);

        C1[i].l -= d_parcursa;
        C2[j].l -= d_parcursa;

        int h1 = 0;

        if(C1[i].l == 0)
            h1 = abs(C1[i].h - C1[i + 1].h);//inaltime care trebuie parcursa
        
        int h2 = 0;

        if(C2[j].l == 0)
            h2 = abs(C2[j].h - C2[j + 1].h);//inaltime care trebuie parcursa

        int aux1 = dp1;
        int aux2 = dp2;

        dp1 = min(aux1 + d_parcursa + h1, aux2 + d_parcursa + h1 + lift);
        dp2 = min(aux2 + d_parcursa + h2, aux1 + d_parcursa + h2 + lift);
    
        i = i + (C1[i].l == 0);
        j = j + (C2[j].l == 0);
    }

    fout << min(dp1, dp2);
}
