#include <iostream>
using namespace std;
enum C{R,B};
struct N{int d;C c;N* l,*r,*p;N(int v):d(v),c(R),l(nullptr),r(nullptr),p(nullptr){}};
N* nil = new N(0);
N* root = nil;

void leftR(N* x){
     N* y = x->r;
     x->r = y->l;
     if(y->l != nil) y->l->p = x;
     y->p = x->p;
     if(x->p == nil) root = y;
     else if(x == x->p->l) x->p->l = y;
     else x->p->r = y;
     y->l = x;
     x->p = y;
}

void rightR(N* x){
     N* y = x->l;
     x->l = y->r;
     if(y->r != nil) y->r->p = x;
     y->p = x->p;
     if(x->p == nil) root = y;
     else if(x == x->p->r) x->p->r = y;
     else x->p->l = y;
     y->r = x;
     x->p = y;
}

void fixI(N* z){
     while(z->p->c == R){
          if(z->p == z->p->p->l){
               N* y = z->p->p->r;
               if(y->c == R){
                    z->p->c = B; y->c = B; z->p->p->c = R;
                    z = z->p->p;
               } else {
                    if(z == z->p->r){
                         z = z->p;
                         leftR(z);
                    }
                    z->p->c = B;
                    z->p->p->c = R;
                    rightR(z->p->p);
               }
          } else {
               N* y = z->p->p->l;
               if(y->c == R){
                    z->p->c = B; y->c = B; z->p->p->c = R;
                    z = z->p->p;
               } else {
                    if(z == z->p->l){
                         z = z->p;
                         rightR(z);
                    }
                    z->p->c = B;
                    z->p->p->c = R;
                    leftR(z->p->p);
               }
          }
     }
     root->c = B;
}

void ins(int v){
     N* z = new N(v);
     z->l = z->r = z->p = nil;
     N* y = nil;
     N* x = root;
     while(x != nil){
          y = x;
          x = (z->d < x->d ? x->l : x->r);
     }
     z->p = y;
     if(y == nil) root = z;
     else if(z->d < y->d) y->l = z;
     else y->r = z;
     fixI(z);
}

N* srch(N* x, int v){
     while(x != nil && x->d != v)
          x = (v < x->d ? x->l : x->r);
     return x;
}

N* mn(N* x){
     while(x->l != nil) x = x->l;
     return x;
}

void tr(N* u, N* v){
     if(u->p == nil) root = v;
     else if(u == u->p->l) u->p->l = v;
     else u->p->r = v;
     v->p = u->p;
}

void fixD(N* x){
     while(x != root && x->c == B){
          if(x == x->p->l){
               N* w = x->p->r;
               if(w->c == R){
                    w->c = B; x->p->c = R; leftR(x->p); w = x->p->r;
               }
               if(w->l->c == B && w->r->c == B){
                    w->c = R;
                    x = x->p;
               } else {
                    if(w->r->c == B){
                         w->l->c = B;
                         w->c = R;
                         rightR(w);
                         w = x->p->r;
                    }
                    w->c = x->p->c;
                    x->p->c = B;
                    w->r->c = B;
                    leftR(x->p);
                    x = root;
               }
          } else {
               N* w = x->p->l;
               if(w->c == R){
                    w->c = B; x->p->c = R; rightR(x->p); w = x->p->l;
               }
               if(w->l->c == B && w->r->c == B){
                    w->c = R;
                    x = x->p;
               } else {
                    if(w->l->c == B){
                         w->r->c = B;
                         w->c = R;
                         leftR(w);
                         w = x->p->l;
                    }
                    w->c = x->p->c;
                    x->p->c = B;
                    w->l->c = B;
                    rightR(x->p);
                    x = root;
               }
          }
     }
     x->c = B;
     }

     void del(int v){
     N* z = srch(root, v);
     if(z == nil) return;
     N* y = z;
     C oc = y->c;
     N* x;
     if(z->l == nil){
          x = z->r;
          tr(z, z->r);
     } else if(z->r == nil){
          x = z->l;
          tr(z, z->l);
     } else {
          y = mn(z->r);
          oc = y->c;
          x = y->r;
          if(y->p == z) x->p = y;
          else{
               tr(y, y->r);
               y->r = z->r;
               y->r->p = y;
          }
          tr(z, y);
          y->l = z->l;
          y->l->p = y;
          y->c = z->c;
     }
     delete z;
     if(oc == B) fixD(x);
}

void ino(N* x){
    if(x != nil){
        ino(x->l);
        cout << x->d << " ";
        ino(x->r);
    }
}

int main(){
    nil->c = B;
    nil->l = nil->r = nil->p = nil;
    int n, v;
    cout << "No. to ins: ";
    cin >> n;
    cout << "Vals: ";
    for(int i = 0; i < n; i++){
        cin >> v;
        ins(v);
    }
    cout << "In: ";
    ino(root);
    cout << "\nSrch: ";
    cin >> v;
    cout << (srch(root, v) != nil ? "Found\n" : "Not Found\n");
    cout << "Del: ";
    cin >> v;
    del(v);
    cout << "In after del: ";
    ino(root);
}
