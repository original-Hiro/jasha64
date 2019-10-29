//Ural 1469 No Smoking
//扫描线算法 + 平衡树 
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 100001;
const double eps = 1e-6, C = acos(-1) / 60;
double xnow; //扫描线的当前坐标 

//线段、平衡树 
struct Segment
{
	int id;
	double x1, y1, x2, y2;
	double k, b;
	void Rotate(double& x, double& y)
	{
		double p = x, q = y;
		x = cos(C) * p - sin(C) * q; y = sin(C) * p + cos(C) * q;
	}
	void init()
	{
		cin >> x1 >> y1 >> x2 >> y2;
		Rotate(x1, y1); Rotate(x2, y2); //防止出现竖直线段，把线段旋转一个小角度 
		if (x1 > x2) {swap(x1, x2); swap(y1, y2);}
		k = (y2 - y1) / (x2 - x1);
		b = y1 - k * x1;
	}
	//解决竖直线段的另一个处理方法是把分母改为x2 - x1 + eps，但其他一些地方也需要相应修改 
	//还有一个方法是，if (x1 == x2) k = 1e9; 
	double y() const {return k * xnow + b;}
	friend bool operator < (const Segment& a, const Segment& b) {return a.y() < b.y() || (a.y() == b.y() && a.id < b.id);}
	//在pb_ds的tree中，判断元素是否相等是通过!(a < b) && !(b < a)来进行的，相等元素会插入失败 
	//亦即，键值相等但实际不等的元素也会插入失败 
	//set在序关系不"唯一"时，也会遇到奇奇怪怪的问题 
	//所以如果用这类不允许重复元素的标准库容器，我们需要建立一种"唯一"的序关系，使得任意两个元素都能比较大小 
} sg[N];
set<Segment> T;

//线段sg在平衡树上的前一名、后一名id 
inline int Prev(const Segment& sg)
{
	if (T.empty()) return -1;
	auto I = T.lower_bound(sg); //C++11中可以直接用auto代替迭代器类型，就不用写一大串tree<Type, null_type, ...>::iterator了 
	return I == T.begin() ? -1 : (--I) -> id;
	//lower_bound(val)返回不小于val的第一个元素的迭代器（如果val大于所有，则返回end()）
	//把求得的结果前移一位即得前驱（无论val在不在平衡树中） 
	//原始定义：lower_bound()返回一个iterator，它指向在[first,last)标记的有序序列中可以插入value而不破坏容器顺序的第一个位置 
	//注意：迭代器自减运算符涉及到一个问题，如果它已经指向begin，则它自减得到的是它自己。所以此处要在自减之前特判。 
}
inline int Next(const Segment& sg)
{
	if (T.empty()) return -1;
	auto I = T.upper_bound(sg);
	return I == T.end() ? -1 : I -> id;
	//upper_bound(val)返回大于val的第一个元素的迭代器（如果val不小于所有，则返回end()），即为后继（无论val在不在平衡树中） 
	//原始定义：upper_bound()返回一个iterator，它指向在[first,last)标记的有序序列中可以插入value而不破坏容器顺序的最后一个位置 
}
//当然，也可以用find实现 
//pb_ds的tree的优势在于有排名功能，但此题不需要用到排名，只需要用前驱后继，所以用set已经完全满足需求了 

//事件，id为对应线段编号，op为类型，op == 1表示线段开始，op == 0表示线段结束 
struct Event
{
	double x;
	int id, op;
	friend bool operator < (const Event& a, const Event& b)
	{
		if (a.x != b.x) return a.x < b.x;
		return a.op > b.op; //先插入，后删除（因为可能在端点处相交） 
	}
} ev[N+N];

//线段相交判定 
inline int dcmp(double x) //允许浮点误差前提下的符号函数 
{
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}
inline double Dot(double x1, double y1, double x2, double y2) {return x1 * x2 + y1 * y2;}
inline double Cross(double x1, double y1, double x2, double y2) {return x1 * y2 - x2 * y1;}
bool SegmentIntersect(int id1, int id2)
{
	if (id1 == -1 || id2 == -1 || id1 == id2) return false;
	const Segment& s1 = sg[id1]; //AB
	const Segment& s2 = sg[id2]; //CD
	int c1 = dcmp(Cross(s2.x1-s1.x1, s2.y1-s1.y1, s2.x1-s1.x2, s2.y1-s1.y2)), //CA ×CB的符号 
		c2 = dcmp(Cross(s2.x2-s1.x1, s2.y2-s1.y1, s2.x2-s1.x2, s2.y2-s1.y2)), //DA ×DB的 
		c3 = dcmp(Cross(s1.x1-s2.x1, s1.y1-s2.y1, s1.x1-s2.x2, s1.y1-s2.y2)), //AC ×AD
		c4 = dcmp(Cross(s1.x2-s2.x1, s1.y2-s2.y1, s1.x2-s2.x2, s1.y2-s2.y2)), //BC ×BD
		d1 = dcmp(Dot(s2.x1-s1.x1, s2.y1-s1.y1, s2.x1-s1.x2, s2.y1-s1.y2)), //CA ·CB
		d2 = dcmp(Dot(s2.x2-s1.x1, s2.y2-s1.y1, s2.x2-s1.x2, s2.y2-s1.y2)), //DA ·DB 
		d3 = dcmp(Dot(s1.x1-s2.x1, s1.y1-s2.y1, s1.x1-s2.x2, s1.y1-s2.y2)), //AC ·AD 
		d4 = dcmp(Dot(s1.x2-s2.x1, s1.y2-s2.y1, s1.x2-s2.x2, s1.y2-s2.y2)); //BC ·BD 
	if (c1 * c2 < 0 && c3 * c4 < 0) return true; //线段规范相交：每条线段的两端点恰在另一线段两侧 
	return (c1 == 0 && d1 <= 0) || (c2 == 0 && d2 <= 0) ||
		(c3 == 0 && d3 <= 0) || (c4 == 0 && d4 <= 0); //其他情况：只需判断一个线段的端点在不在另一线段上即可 
}

inline void PrintY(int id1, int id2) {cout << "YES" << endl << id1 << ' ' << id2 << endl;}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sg[i].init(); sg[i].id = i;
		ev[i] = (Event){sg[i].x1, i, 1}; ev[i+n] = (Event){sg[i].x2, i, 0};
	}
	
	sort(ev + 1, ev + n + n + 1);
	for (int i = 1; i <= n + n; i++)
	{
		xnow = ev[i].x;
		if (ev[i].op == 1)
		{
			int id = ev[i].id;
			T.insert(sg[id]);
			int pr = Prev(sg[id]), ne = Next(sg[id]);
			if (SegmentIntersect(pr, id)) {PrintY(id, pr); return 0;}
			if (SegmentIntersect(id, ne)) {PrintY(id, ne); return 0;}
		}
		else {
			int id = ev[i].id, pr = Prev(sg[id]), ne = Next(sg[id]);
			if (SegmentIntersect(pr, ne)) {PrintY(pr, ne); return 0;}
			T.erase(T.find(sg[id]));
		}
	}
	cout << "NO" << endl;
	return 0;
}
//参考资料：《算法竞赛入门经典训练指南》、《算法导论》、高大爷在vjudge上的标程 

