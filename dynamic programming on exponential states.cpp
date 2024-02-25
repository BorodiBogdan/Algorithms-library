//https://www.pbinfo.ro/probleme/1069/ubuntzei
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define Nmax 10001
using namespace std;

ifstream fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

vector < pair < int, int > > V[Nmax];

int cities, roads, friends, spot1, spot2, length;
int F[Nmax];
int Dist[2001][2001];

int dp[40000][16];
const int oo = 1 << 28;

void BFS(int subset, int vertex, int Dist[][2001]){
    queue < int > Q;
    Q.push(vertex);

    while(!Q.empty()){
        vertex = Q.front();
        Q.pop();
        
        for(pair <int, int> new_v : V[vertex]){
            int new_vertex = new_v.first;
            int cost = new_v.second;
          
            if(Dist[subset][new_vertex] > Dist[subset][vertex] + cost){
                
                Dist[subset][new_vertex] = Dist[subset][vertex] + cost;
                Q.push(new_vertex);
            }
        }
    }
}

int main(){
    for(int i = 0; i < 32768; ++i)
        for(int j = 0; j < 2001; ++j)
            dp[i][j] = oo;

    for(int i = 0; i < 2001; ++i)
        for(int j = 0; j < 2001; ++j)
            Dist[i][j] = oo;

    fin >> cities >> roads;

    fin >> friends;

    for(int i = 1; i <= friends; ++i)
        fin >> F[i];

    for(int i = 1; i <= roads; ++i){
        fin >> spot1 >> spot2 >> length;
        V[spot1].push_back({ spot2, length });
        V[spot2].push_back({ spot1, length });
    }

    for(int i = 1; i <= friends; i++){
        Dist[i][F[i]] = 0;
        BFS(i, F[i], Dist);
        dp[1 << (i - 1)][i] = Dist[i][1];
    }

    for(int i = 1; i < (1 << friends); ++i)
        for(int k = 1; k <= friends; ++k)
            if((1 << (k - 1)) & i)
                for(int j = 1, f = 1; j < (1 << friends); j = j * 2, f++)
                    if(i & j && k != f){
                        int last_subset = i ^ j;
                        int where = F[f];
                        
                        dp[i][f] = min(dp[i][f], dp[last_subset][k] + Dist[k][F[f]]);
                    }
    
    if(friends > 0){
        int subset = (1 << friends) - 1;
        int ans = oo;

        for(int i = 1; i <= friends; ++i)
            ans = min(ans, dp[subset][i] + Dist[i][cities]);
        
        fout << ans;
    }
    else {
        Dist[1][1] = 0;
        BFS(1,1,Dist);
        
        fout<< Dist[1][cities];
    }
}
