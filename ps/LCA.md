### LCA(Lowest Common Ancestor) 알고리즘
---

1. 탐색을 제외하고 O(n)의 시간복잡도를 갖는 LCA
---

알고리즘 설명은 시간이 나면 언젠가 추가하겠죠...?

```cpp
const int SZ=100005; //maximum number of nodes, node is 1-n
vector<int> graph[SZ]; //tree
int par[SZ]; //parent, root's parent is 0
int lv[SZ]; //distance from root
int vst[SZ]; //check dfs
void dfs(int n, int parent, int level){
  lv[n]=level;
  par[n]=parent;
  for(int nxt:graph[n]){
    if(vst[nxt]==1) continue;
    dfs(nxt,n,level+1);
  }
}
int lca(int x, int y){
  if(lv[x]<lv[y]) swap(x,y);
  while(lv[x]>lv[y]){
    x=par[x];
  }
  while(x!=y){
    x=par[x];
    y=par[y];
  }
  return x;
}
```
---
2. 탐색을 제외하고 O(log(n))의 시간복잡도를 갖는 LCA
---

알고리즘 설명이 아마 들어올 자리

```cpp
const int SZ=100005; //maximum number of nodes, node is 1-n
const int MXH=20; // max number of log_2(level)
vector<int> graph[SZ]; //tree
int lv[SZ]; //equal
int par[MXH][SZ]; //dp for parent
int vst[SZ]; //equal
int n; // number of nodes
void dfs(int x, int parent, int level){
  par[0][x]=parent;
  lv[x]=level;
  for(int nxt: graph[x]){
    if(vst[nxt]==1) continue;
    dfs(nxt,x,level+1);
  }
}
void memo(){
  for(int i=1;i<MXH;i++){
    for(int j=1;j<=n;j++){
      par[j][i]=par[par[j][i-1]][i-1];
    }
  }
}
int level_up(int x, int d){ // d is a number for lv up!
  for(int i=MXH-1;i>=0;i--){
    if(d&(1<<i)) x=par[i][x];
  }
  return x;
}
int query(int x, int y){
  x=level_up(x,max(0,lv[x]-lv[y])); // x와 y level 맞추기
  y=level_up(y,max(0,lv[y]-lv[x]));
  for(int i=MXH-1;i>=0;i--){
    if(par[i][x]!=par[i][y]){
      x=par[i][x];
      y=par[i][y];
    }
  }
  x=par[0][x];
  y=par[0][y];
  return x;
}
```

---
코드가 컴파일이 되지 않거나 알고리즘적으로 오류가 있는 경우 문의 주시면 감사하겠습니다. 
