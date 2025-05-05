#include <iostream>
using namespace std;

struct N {
    int d;
    N *l, *r;
};

N* newN(int v) {
    N* n = new N;
    n->d = v;
    n->l = n->r = NULL;
    return n;
}

N* ins(N* r, int v) {
    if(!r) return newN(v);
    if(v < r->d) r->l = ins(r->l, v);
    else if(v > r->d) r->r = ins(r->r, v);
    return r;
}

N* srch(N* r, int v) {
    if(!r || r->d == v) return r;
    if(v < r->d) return srch(r->l, v);
    return srch(r->r, v);
}

N* minN(N* r) {
    while(r->l) r = r->l;
    return r;
}

N* del(N* r, int v) {
    if(!r) return NULL;
    if(v < r->d) r->l = del(r->l, v);
    else if(v > r->d) r->r = del(r->r, v);
    else {
        if(!r->l) return r->r;
        if(!r->r) return r->l;
        N* m = minN(r->r);
        r->d = m->d;
        r->r = del(r->r, m->d);
    }
    return r;
}

void ino(N* r) {
    if(!r) return;
    ino(r->l);
    cout << r->d << " ";
    ino(r->r);
}

int main() {
    N* r = NULL;
    int n, x;

    cout << "No. of nodes to insert: ";
    cin >> n;
    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        r = ins(r, x);
    }

    cout << "Inorder: ";
    ino(r);
    cout << "\n";

    cout << "Search: ";
    cin >> x;
    cout << (srch(r, x) ? "Found\n" : "Not Found\n");

    cout << "Delete: ";
    cin >> x;
    r = del(r, x);

    cout << "Inorder after delete: ";
    ino(r);
}
