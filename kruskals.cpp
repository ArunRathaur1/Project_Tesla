#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[100];
int f(int x){ return p[x]==x ? x : p[x]=f(p[x]); }
void u(int a, int b){ p[f(a)] = f(b); }
int main(){
     int n, e, a, b, w;
     cin >> n >> e;
     vector<tuple<int,int,int>> ed;
     for(int i = 0; i < e; i++){
          cin >> a >> b >> w;
          ed.push_back({w, a, b});
     }
     sort(ed.begin(), ed.end());
     for(int i = 0; i < n; i++) p[i] = i;
     for(auto [w,a,b] : ed)
          if(f(a) != f(b)) u(a,b), cout << a << " - " << b << "\n";
}
