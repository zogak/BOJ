// the number of connected components

#define CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define MAX 1001

using namespace std;

int n, m, a, b;
int cnt=0;
vector <int> map[MAX];
int v[MAX];

void input(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
}

void dfs(int node){
    v[node] = 1;
    for(int i=0; i<map[node].size(); i++){
        if(v[map[node][i]] == 1){
            continue;
        }
        dfs(map[node][i]);
    }
}

int main(){
    input();
    for(int i=1; i<=n; i++){
        if(v[i]==0){
            cnt++;
            dfs(i);
        }
    }
    printf("%d", cnt);
    
    return 0;
}
