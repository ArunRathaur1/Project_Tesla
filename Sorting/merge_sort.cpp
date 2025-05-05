#include <iostream>
using namespace std;

void mg(int a[], int l, int m, int r) {
     int n1 = m - l + 1, n2 = r - m;
     int x[n1], y[n2];
     for(int i = 0; i < n1; i++) x[i] = a[l + i];
     for(int i = 0; i < n2; i++) y[i] = a[m + 1 + i];
     int i = 0, j = 0, k = l;
     while(i < n1 && j < n2) a[k++] = (x[i] <= y[j]) ? x[i++] : y[j++];
     while(i < n1) a[k++] = x[i++];
     while(j < n2) a[k++] = y[j++];
}

void ms(int a[], int l, int r) {
     if(l < r) {
          int m = (l + r) / 2;
          ms(a, l, m);
          ms(a, m + 1, r);
          mg(a, l, m, r);
     }
}

int main() {
     int n;
     cin >> n;
     int a[n];
     for(int i = 0; i < n; i++) cin >> a[i];
     ms(a, 0, n - 1);
     for(int i = 0; i < n; i++) cout << a[i] << " ";
}
