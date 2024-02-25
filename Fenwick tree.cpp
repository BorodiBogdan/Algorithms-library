//https://www.pbinfo.ro/probleme/4019/pikachu
#include <fstream>
#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <stack>
#define Nmax 100001
#define MOD 666013
using namespace std;

ifstream fin("pikachu.in");
ofstream fout("pikachu.out");

int n, k, x, s;
long long aib[Nmax], aibs[Nmax];
int V[Nmax], S[Nmax], N[Nmax];

bool cmp(int i, int j){ return V[i] < V[j]; }

void update(int pos, long long aib[], int val){
    for(int i = pos; i < Nmax; i += i & -i)
        aib[i] += val;
}
long long Query(int pos, long long aib[]){
    long long sum = 0;

    for(int i = pos; i > 0; i -= i & -i)
        sum += aib[i];
    
    return sum;
}
int Binary_Search(int k){
    int st = 1, dr = n, ans = 0;

    while(st <= dr){
        int mid = (st + dr) / 2;

        int x = Query(mid, aib);

        if(x >= k){
            ans = mid;
            dr = mid - 1;
        }
        else st = mid + 1;
    }
    return ans;
}
int main() {
    fin >> n >> k;

    for(int i = 1; i <= n; ++i)
        fin >> V[i],
        S[i] = i;
    
    sort(S + 1, S + 1 + n, cmp);

    int pos = 1;

    for(int i = 1; i <= n; ++i) {
        N[S[i]] = pos;

        if(N[S[i]] != N[S[i + 1]])
            pos++;
    }

    for(int i = 1; i < k; ++i) {

        update(N[i], aib, 1);
        update(N[i], aibs, V[i]);
        s += V[i];
    }

    long long mini = 1LL << 62;

    for(int i = k; i <= n; ++i){
        s -= V[i - k];
        s += x;
        
        if(i > k){
            update(N[i - k], aib, -1);
            update(N[i - k], aibs, -V[i - k]);
        }

        update(N[i], aib, 1);
        update(N[i], aibs, V[i]);

        int med = Binary_Search((k + 2) / 2);
        
        int mici = Query(med - 1, aib);
        long long smici = Query(med - 1, aibs);
        int mari = Query(n, aib) - mici;
        long long smari = Query(n, aibs) - smici;

        med = V[S[med]];

        long long cost = 1LL * mici * med - smici + smari - 1LL * mari * med;

        if(cost < mini)
            mini = cost;
    }
    fout << mini;
    

    return 0;
}
