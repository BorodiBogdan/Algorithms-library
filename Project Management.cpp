//link: https://www.pbinfo.ro/probleme/1101/project-management
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#define Nmax 1201
using namespace std;

ifstream fin("pm.in");
ofstream fout("pm.out"); 

int n, g, x, ans;
int T[Nmax], G[Nmax], dp[Nmax], mdp[Nmax];
vector <int> V[Nmax];
vector <int> VT[Nmax];
queue <int> Q;

void BFS(){
    while(!Q.empty()){
        int vertex = Q.front();
        Q.pop();
        
        if(dp[vertex] + T[vertex] > ans)
            ans = dp[vertex] + T[vertex];

        for(int new_vertex : V[vertex]){
            G[new_vertex]--;
            dp[new_vertex] = max(dp[new_vertex], dp[vertex] + T[vertex]);

            if(G[new_vertex] == 0)
                Q.push(new_vertex);
        }
    }
}
void DFS(int vertex){
    
    for(int new_vertex : VT[vertex]){
        
        if(mdp[new_vertex] > mdp[vertex] - T[new_vertex]){
            mdp[new_vertex] = min(mdp[new_vertex], mdp[vertex] - T[new_vertex]);
            DFS(new_vertex);
        }
    }
}
int main(){
    fin >> n;

    for(int i = 1; i <= n; ++i)
        fin >> T[i];    

    for(int i = 1; i <= n; ++i){
        mdp[i] = 1 << 28;
        fin >> g;
        G[i] = g;
        
        if(g == 0)
            Q.push(i);

        for(int j = 1; j <= g; ++j){
            fin >> x;

            V[x].push_back(i);
            VT[i].push_back(x);
        }
    }

    BFS();

    for(int i = 1; i <= n; ++i)
        if(V[i].size() == 0){
            mdp[i] = ans - T[i];
            DFS(i);
        }

    fout << ans << "\n";

    for(int i = 1; i <= n; ++i)
        fout << dp[i] << " " << mdp[i] <<  "\n";
}
