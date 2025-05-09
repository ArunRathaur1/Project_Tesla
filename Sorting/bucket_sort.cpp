#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float a[], int n) {
     vector<float> b[n];
     for (int i = 0; i < n; i++) {
          int bi = n * a[i];
          b[bi].push_back(a[i]);
     }
     for (int i = 0; i < n; i++)
          sort(b[i].begin(), b[i].end());
     int idx = 0;
     for (int i = 0; i < n; i++)
          for (float v : b[i])
               a[idx++] = v;
}

int main() {
     int n;
     cin >> n;
     float a[n];
     for (int i = 0; i < n; i++) cin >> a[i];
     bucketSort(a, n);
     for (int i = 0; i < n; i++) cout << a[i] << " ";
}
