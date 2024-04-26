#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct hu {
	int star;
	int end;
	int power;
};//��
typedef struct tu {
	int n;
	int m;
	string* q;
	hu* p;
};//ͼ
typedef struct dui {
	int n;
	int* p;
	int base;
	int top;
};//����
void getdui(dui& s1, tu& s2) {
	s1.p = new int[s2.n];
	s1.n = s2.n;
	s1.base = s1.top = 0;
}//��ʼ������
void push(dui& s, int a) {
	s.p[s.top] = a;
	s.top = (s.top + 1) % s.n;
}//���
void pop(dui& s, int& a) {
	a = s.p[s.base];
	s.base = (s.base + 1) % s.n;
}//����
void gettu(tu& s) {
	s.q = new string[s.n + 1];
	s.p = new hu[s.m];
}//��ʼ��ͼ
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
}//������ȱ���
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
}//������ȱ���
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
}//ɾ���ڵ�
void du(tu& s) {
	int a = 0;
	for (int i = 1; i <= s.n; i++) {
		a = 0;
		cout << i << endl;
		for (int j = 0; j < s.m; j++) {
			if (s.p[j].star == i || s.p[j].end == i) {
				cout << "������" << " " << s.p[j].star << " " << s.p[j].end << " " << s.p[j].power << endl;
				a++;
			}
		}
		cout << "�ȣ�" << a << endl;
	}
}//������ڵ�Ķȼ�������
int main()
{
	tu s;
	int a = 0;
	cout << "������ڵ�ͱߵĸ�����" << endl;
	cin >> s.n >> s.m;
	gettu(s);
	for (int i = 1; i <= s.n; i++) {
		cout << "�������" << i << "���ڵ������" << endl;
		cin >> s.q[i];
	}
	for (int i = 0; i < s.m; i++) {
		cout << "�������" << i + 1 << "���ߵ������˵㼰��Ȩֵ" << endl;
		cin >> s.p[i].star >> s.p[i].end >> s.p[i].power;
	}
	int* p = new int[s.n + 1];
	xi(p, s.n);
	int b = 0;
	while (1) {
		cout << "���������ȱ�����������1" << endl;
		cout << "���������ȱ�����������2" << endl;
		cout << "ɾ���㣬������3" << endl;
		cout << "������ڵ�Ķȼ������ߣ�������4" << endl;
		cout << "������������5" << endl;
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
			cout << "������ɾ���Ľڵ�" << endl;
			cin >> b;
			shan(s, b);
			cout << "ɾ���ɹ�" << endl;
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





