//problem link: https://www.pbinfo.ro/probleme/1861/topsort
#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define Nmax 100001
using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

int n, m, v1, v2, GI[Nmax], P[Nmax];
vector <int> V[Nmax];
queue <int> Q;

void BFS(){
    while(!Q.empty()){
        int v = Q.front();
        fout << v << " ";
        for(int i : V[v])
            if(!P[i]){
                GI[i]--;

                if(GI[i] == 0){ 
                    P[i] = 1;
                    Q.push(i);
                }
            }
        Q.pop(); 
    }
}

int main() {
    fin >> n >> m;

    for(int i = 1; i <= m; ++i){
        fin >> v1 >> v2;
        V[v1].push_back(v2);
        GI[v2]++;
    }

    for(int i = 1; i <= n; ++i)
        if(GI[i] == 0){
            P[i] = 1;
            Q.push(i);
    }
          
     BFS();
            
        
    return 0;
}
