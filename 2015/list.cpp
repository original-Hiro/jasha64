#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std; 

list<int> List;

inline void Show()
{
	if (List.empty()) {cout << "Link list is empty" << endl; return;}
	list<int>::iterator I;
	for (I = List.begin(); I != List.end(); I++)
	{
		if (I != List.begin()) cout << ' ';
		cout << *I;
	}
	cout << endl;
}
inline void Delete(const int& pos)
{
	if (pos > List.size()) {cout << "delete fail" << endl; return;}
	if (pos == 1) {List.pop_front();}
	else if (pos == List.size()) {List.pop_back();}
	else {
		int i;
		list<int>::iterator I;
		for (i = 1, I = List.begin(); i <= pos; i++) I++;
		List.erase(--I);
	}
	cout << "delete OK" << endl;
}
inline void Insert(const int& pos, const int& cache)
{
	if (pos > List.size() + 1) {cout << "insert fail" << endl; return;}
	if (pos == 1) {List.push_front(cache);}
	else if (pos == List.size() + 1) {List.push_back(cache);}
	else {
		int i;
		list<int>::iterator I;
		for (i = 1, I = List.begin(); i <= pos; i++) I++;
		List.insert(--I, cache);
	}
	cout << "insert OK" << endl;
}
inline void Get(const int& pos)
{
	int i;
	list<int>::iterator I;
	if (pos > List.size()) {cout << "get fail" << endl; return;}
	if (pos == 1) {cout << List.front() << endl; return;}
	if (pos == List.size()) {cout << List.back() << endl; return;}
	for (i = 1, I = List.begin(); i <= pos; i++) I++;
	cout << *(--I) << endl;
}

int main()
{
	int n;
	int pos, cache;
	string argv;
	
	cin >> n;
	while (n--)
	{
		cin >> cache;
		List.push_front(cache);
	}
	cin >> n;
	while (n--)
	{
		cin >> argv;
		if (argv == "show") Show();
		else if (argv == "delete") {cin >> cache; Delete(cache);}
		else if (argv == "insert") {cin >> pos >> cache; Insert(pos, cache);}
		else {cin >> cache; Get(cache);}
	}
	
	return 0;
}

