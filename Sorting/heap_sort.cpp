#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
     int l = 2*i + 1, r = 2*i + 2, m = i;
     if(l < n && a[l] > a[m]) m = l;
     if(r < n && a[r] > a[m]) m = r;
     if(m != i) {
          swap(a[i], a[m]);
          heapify(a, n, m);
     }
}

void hs(int a[], int n) {
     for(int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
     for(int i = n - 1; i >= 0; i--) {
          swap(a[0], a[i]);
          heapify(a, i, 0);
     }
}

int main() {
     int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) cin >> a[i];
     hs(a, n);
     for(int i = 0; i < n; i++) cout << a[i] << " ";
}
