#include <iostream>
#include <cstdlib>
using namespace std;
  
const int N = 80007, MOD = 1000000;
struct Node *P, *null;
struct Node
{
    int v, s;
    Node* ch[2];
      
    Node(int v = 0):v(v) {ch[0] = ch[1] = null; s = 1;}
    int cmp(int k) const
    {
        int d = k - ch[0] -> s;
        if (d == 1) return -1;
        else return d <= 0 ? 0 : 1;
    }
    void Maintain() {s = ch[0] -> s + ch[1] -> s + 1;}
      
    void* operator new (size_t) {return P++;} //*动态内存分配慢，重载new运算符加快速度 
} a[N];
Node* Root;
int v, Cache;
  
void Rotate(Node* &o, int d) //BST旋转 
{
    Node* k = o -> ch[d ^ 1]; o -> ch[d ^ 1] = k -> ch[d]; k -> ch[d] = o;
    o -> Maintain(); k -> Maintain(); o = k;
}
void Splay(Node* &o, int k) //找出序列第k小元素，并旋转到根 
{
    int d = o -> cmp(k);
    if (d == 1) k -= o -> ch[0] -> s + 1;
    if (d != -1)
    {
        Node* p = o -> ch[d];
        int d2 = p -> cmp(k);
        int k2 = d2 ? k - p -> ch[0] -> s - 1 : k;
        if (d2 != -1)
        {
            Splay(p -> ch[d2], k2);
            if (d == d2) Rotate(o, d ^ 1); else Rotate(o -> ch[d], d);
        }
        Rotate(o, d ^ 1);
    }
}
void Fit() //*题目需要 
{
    Cache = 2147483647;
    int d;
    Node* o = Root;
      
    while (o != null)
    {
        Cache = min(Cache, abs(o -> v - v));
        if (o -> ch[0] != null) Cache = min(Cache, abs(o -> ch[0] -> v - v));
        if (o -> ch[1] != null) Cache = min(Cache, abs(o -> ch[1] -> v - v));
        if (o -> v == v) {Cache = 0; return;}
        else {d = o -> v > v ? 0 : 1; o = o -> ch[d];}
    }
}
int Find() //计算值对应的名次 
{
    int r = 0, d;
    Node* o = Root;
      
    while (o != null)
    {
        d = v < o -> v ? 0 : 1;
        if (d) r += o -> ch[0] -> s + 1;
        if (o -> v == v) return r;
        o = o -> ch[d];
    }
      
    return 0;
}
Node* Merge_(Node* Left, Node* Right) //Left任意元素小于Right任意元素时，O(n)直接合并 
{
    Splay(Left, Left -> s);
    Left -> ch[1] = Right;
    Left -> Maintain();
    return Left; 
}
void Split(Node* o, int k, Node* &Left, Node* &Right) //将序列左边k个元素分裂出来 
{
    Splay(o, k);
    Right = o -> ch[1];
    o -> ch[1] = null;
    o -> Maintain();
    Left = o;
}
void Insert(Node* &o) //插入 
{
    if (Root == null) {Root = new Node(v); return;}
      
    int k;
    Fit(); v -= Cache;
    k = Find();
    if (!k) {v = v + (Cache << 1); k = Find() - 1; v -= Cache;}
    else v += Cache;
    Node *c1 = null, *c2 = o;
      
    if (k) Split(o, k, c1, c2);
    o = new Node(v); o -> ch[0] = c1; o -> ch[1] = c2;
}
Node* Merge(Node* Left, Node* Right) //O(nlogn)启发式合并 
{
    if (Left && !Right) return Left;
    if (Right && !Left) return Right;
    if (Left -> s > Right -> s) return Merge(Right, Left);
      
    while (Left != null)
    {
        Splay(Left, 1);
        v = Left -> v; Left = Left -> ch[1];
        Insert(Right);
    }
      
    return Right;
}
void Remove() //删除元素 
{
    int k = Find();
    Node *l, *r;
      
    Splay(Root, k);
    l = Root -> ch[0]; r = Root -> ch[1];
    //    delete Root;
    Root = l == null ? r : Merge_(l, r);
}
  
int main()
{
    int q, c, Res = 0;
    bool p = false;
      
    ios::sync_with_stdio(false);
    P = a;
    null = new Node(); null -> s = 0; Root = null;
      
    cin >> q;
    while (q--)
    {
        cin >> c >> v;
        if (Root == null) {Insert(Root); p = c;}
        else if (c ^ p)
        {
            Fit(); v -= Cache;
            if (Find()) Remove();
            else {v = v + (Cache << 1); Remove();}
            Res = (Res + Cache) % MOD;
        }
        else Insert(Root);
    }
      
    cout << Res << endl;
      
    return 0;
}

