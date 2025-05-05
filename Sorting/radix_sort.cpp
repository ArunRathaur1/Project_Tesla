#include <iostream>
using namespace std;

int getMax(int a[], int n) {
     int m = a[0];
     for(int i = 1; i < n; i++) if(a[i] > m) m = a[i];
     return m;
}

void countSort(int a[], int n, int exp) {
     int o[n], c[10] = {0};
     for(int i = 0; i < n; i++) c[(a[i]/exp)%10]++;
     for(int i = 1; i < 10; i++) c[i] += c[i-1];
     for(int i = n-1; i >= 0; i--) {
          o[c[(a[i]/exp)%10] - 1] = a[i];
          c[(a[i]/exp)%10]--;
     }
     for(int i = 0; i < n; i++) a[i] = o[i];
}

void rs(int a[], int n) {
     int m = getMax(a, n);
     for(int exp = 1; m/exp > 0; exp *= 10)
          countSort(a, n, exp);
}

int main() {
     int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) cin >> a[i];
     rs(a, n);
     for(int i = 0; i < n; i++) cout << a[i] << " ";
}
