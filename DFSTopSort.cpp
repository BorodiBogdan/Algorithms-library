//problem link: https://www.pbinfo.ro/probleme/1861/topsort
#include <fstream>
#include <queue>
#include <vector>
#define Nmax 100001
using namespace std;

ifstream fin("topsort.in");
ofstream fout("topsort.out");

typedef vector<int> VI;
typedef vector<vector<int>> VVI;

bool F[Nmax];
int Node[Nmax], MaxPath[Nmax], l;
VVI V;

void Dfs(int node){
     F[node] = 1;

     for(int i = 0; i < V[node].size(); ++i)
          if(!F[V[node][i]])
               Dfs(V[node][i]);
     
     Node[l--] = node;
}

int main() {
     int n, m, v1, v2;

     fin >> n >> m;

     V.resize(n + 5);
     l = n;

     for(int i = 1; i <= m; ++i){
          fin >> v1 >> v2;

          V[v1].push_back(v2);
     }

     for(int i = 1; i <= n; ++i)
          if(!F[i])
               Dfs(i);
     
     for(int i = 1; i <= n; ++i)
         fout << Node[i] << " ";
}
