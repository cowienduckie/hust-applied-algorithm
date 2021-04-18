#include <bits/stdc++.h>
using namespace std;

const int N = 106;
const int M = 5000;

int n, m;
int c[N];
int r[N][N];
int res = INT_MAX;
int dress[3];
bool choose[N];
int curr = 0;

void duyet(int u){
if (u > 3){
res = min (res, curr);
return;
}

for (int i = 1; i <= n; i++){
if (!choose[i]){
bool avail = true;
for (int j = 1; j <= 3; j++){
if (dress[j] != 0 && r[i][dress[j]] == 0){
avail = false;
break;
}
}

if (avail){
choose[i] = true;
curr += c[i];
dress[u] = i;

duyet(u + 1);
choose[i] = false;
curr -= c[i];
dress[u] = 0;
}
}
}
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
cin >> n >> m;
for (int i = 1; i <= n; i++)
cin >> c[i];
for (int i = 1; i <= m; i++){
int u, v;
cin >> u >> v;
r[u][v] = r[v][u] = 1;
}
duyet(1);
if (res == INT_MAX)
cout << -1;
else cout << res;
return 0;
}