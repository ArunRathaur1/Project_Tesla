#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; double w;
    cin >> n >> w;
    vector<pair<double, double>> a(n);
    for(int i = 0; i < n; i++){
        double v, wt;
        cin >> v >> wt;
        a[i] = {v/wt, wt};
    }
    sort(a.rbegin(), a.rend());
    double ans = 0;
    for(auto [r, wt] : a){
        double take = min(w, wt);
        ans += take * r;
        w -= take;
        if(w <= 0) break;
    }
    cout << ans << "\n";
}
