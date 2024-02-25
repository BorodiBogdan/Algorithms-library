//https://www.pbinfo.ro/probleme/4112/falkland
#include <fstream>
#include <queue>
#include <vector>
#define Nmax 150001
using namespace std;

ifstream fin("falkland.in");
ofstream fout("falkland.out");

typedef vector < pair < int, int > > VIP;
typedef vector < int > VI;
 
const int oo = 1 << 28;
int St[Nmax], Dr[Nmax], Vis[Nmax];
int m, n, e, x, y;
VI V[Nmax];
 
bool cuplaj(int i){
    if(Vis[i])
        return 0;
 
    Vis[i] = 1;
 
    for(int vertex : V[i])
        if(Dr[vertex] == 0){
            St[i] = vertex;
            Dr[vertex] = i;
            return 1;
        }
    
    for(int vertex : V[i])
        if(cuplaj(Dr[vertex])){
            St[i] = vertex;
            Dr[vertex] = i;
            return 1;
        }
    return 0;
}
 
int main() {
    fin >> n >> m >> e;
        
    for(int i = 1; i <= e; ++i){
        fin >> x >> y;
 
        V[x].push_back(y);
    }
 
    int done = 1, ans = 0;
 
    while(done){
        done = 0;
 
        for(int i = 0; i <= n; ++i)
            Vis[i] = 0;
 
        for(int i = 1; i <= n; ++i)
            if(St[i] == 0 && cuplaj(i)) {
                done = 1;
                ans++;    
            }
    }
 
    fout << ans << "\n";
 
    return 0;   
}
