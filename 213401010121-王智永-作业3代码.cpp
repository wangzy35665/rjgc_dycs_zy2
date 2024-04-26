#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct hu {
	int star;
	int end;
	int power;
};//边
typedef struct tu {
	int n;
	int m;
	string* q;
	hu* p;
};//图
typedef struct dui {
	int n;
	int* p;
	int base;
	int top;
};//队列
void getdui(dui& s1, tu& s2) {
	s1.p = new int[s2.n];
	s1.n = s2.n;
	s1.base = s1.top = 0;
}//初始化队列
void push(dui& s, int a) {
	s.p[s.top] = a;
	s.top = (s.top + 1) % s.n;
}//入队
void pop(dui& s, int& a) {
	a = s.p[s.base];
	s.base = (s.base + 1) % s.n;
}//出队
void gettu(tu& s) {
	s.q = new string[s.n + 1];
	s.p = new hu[s.m];
}//初始化图
void shen(tu& s, int* p, int a) {
	cout << a << "." << s.q[a] << " ";
	p[a] = 1;
	for (int i = 0; i < s.m; i++) {
		if (a == s.p[i].star && p[s.p[i].end] == 0) {
			shen(s, p, s.p[i].end);
		}
		if (a == s.p[i].end && p[s.p[i].star] == 0) {
			shen(s, p, s.p[i].star);
		}
	}
}//深度优先遍历
void guang(tu& s, int* p) {
	dui s1;
	int a = 0;
	getdui(s1, s);
	push(s1, s.p[0].star);
	p[s.p[0].star] = 1;
	while (s1.top != s1.base) {
		pop(s1, a);
		cout << a << "." << s.q[a] << " ";
		for (int i = 0; i < s.m; i++) {
			if (a == s.p[i].star && p[s.p[i].end] == 0) {
				p[s.p[i].end] = 1;
				push(s1, s.p[i].end);
			}
			if (a == s.p[i].end && p[s.p[i].star] == 0) {
				p[s.p[i].star] = 1;
				push(s1, s.p[i].star);
			}
		}
	}
	cout << endl;
}//广度优先遍历
void xi(int* p, int a) {
	for (int i = 1; i <= a; i++) {
		p[i] = 0;
	}
}
void shan(tu& s, int a) {
	for (int i = 0; i < s.m; i++) {
		if (a == s.p[i].star || a == s.p[i].end) {
			for (int j = i; j < s.m - 1; j++) {
				s.p[j] = s.p[j + 1];
			}
			s.m--;
			i--;
		}
	}
}//删除节点
void du(tu& s) {
	int a = 0;
	for (int i = 1; i <= s.n; i++) {
		a = 0;
		cout << i << endl;
		for (int j = 0; j < s.m; j++) {
			if (s.p[j].star == i || s.p[j].end == i) {
				cout << "关联边" << " " << s.p[j].star << " " << s.p[j].end << " " << s.p[j].power << endl;
				a++;
			}
		}
		cout << "度：" << a << endl;
	}
}//输出各节点的度及关联边
int main()
{
	tu s;
	int a = 0;
	cout << "请输入节点和边的个数：" << endl;
	cin >> s.n >> s.m;
	gettu(s);
	for (int i = 1; i <= s.n; i++) {
		cout << "请输入第" << i << "个节点的名称" << endl;
		cin >> s.q[i];
	}
	for (int i = 0; i < s.m; i++) {
		cout << "请输入第" << i + 1 << "条边的两个端点及其权值" << endl;
		cin >> s.p[i].star >> s.p[i].end >> s.p[i].power;
	}
	int* p = new int[s.n + 1];
	xi(p, s.n);
	int b = 0;
	while (1) {
		cout << "输出深度优先遍历，请输入1" << endl;
		cout << "输出广度优先遍历，请输入2" << endl;
		cout << "删除点，请输入3" << endl;
		cout << "输出各节点的度及关联边，请输入4" << endl;
		cout << "结束，请输入5" << endl;
		cin >> a;
		if (a == 1) {
			shen(s, p, s.p[0].star);
			cout << endl;
			xi(p, s.n);
		}
		else if (a == 2) {
			guang(s, p);
			xi(p, s.n);
		}
		else if (a == 3) {
			cout << "请输入删除的节点" << endl;
			cin >> b;
			shan(s, b);
			cout << "删除成功" << endl;
		}
		else if (a == 4) {
			du(s);
		}
		else if (a == 5) {
			break;
		}
	}
	return 0;
}





