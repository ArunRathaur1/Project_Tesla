#include <iostream>
using namespace std;

int main() {
     int n;
     cin >> n;
     int a[n], m = 0;
     for(int i = 0; i < n; i++) {
          cin >> a[i];
          if(a[i] > m) m = a[i];
     }
     int c[m+1] = {0};
     for(int i = 0; i < n; i++) c[a[i]]++;
     for(int i = 1; i <= m; i++) c[i] += c[i-1];
     int o[n];
     for(int i = n-1; i >= 0; i--) o[--c[a[i]]] = a[i];
     for(int i = 0; i < n; i++) cout << o[i] << " ";
}
