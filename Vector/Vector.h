#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Vec
{
	virtual double dot(Vec&) = 0;
	virtual Vec& cross(Vec&) = 0;
	virtual double Lenth() = 0;
	virtual Vec& Unitization() = 0;
};

class Vec3 : public Vec
{
public:
	double a = 0, b = 0, c = 0;
public:
	Vec3() = default;
	Vec3(double x1, double x2, double x3):a(x1),b(x2),c(x3) {}
	Vec3(const Vec3 &v) {
		a = v.a;
		b = v.b;
		c = v.c;
	}
	~Vec3() {}

	Vec3 operator +(const Vec3& v) {
		Vec3 res;
		res.a = a + v.a;
		res.b = b + v.b;
		res.c = c + v.c;
		return res;
	}
	Vec3 operator -(const Vec3& v) {
		Vec3 res;
		res.a = a - v.a;
		res.b = b - v.b;
		res.c = c - v.c;
		return res;
	}
	Vec3 operator *(double n) {
		Vec3 res;
		res.a = n * a;
		res.b = n * b;
		res.c = n * c;
		return res;
	}
	Vec3 operator /(double n) {
		Vec3 res;
		res.a = a / n;
		res.b = b / n;
		res.c = c / n;
		return res;
	}
	Vec3& operator =(const Vec3& v) {
		a = v.a;
		b = v.b;
		c = v.c;
		return *this;
	}
	bool operator ==(const Vec3& v) {
		if (a == v.a && b == v.b && c == v.c) return true;
		return false;
	}
	friend ostream& operator <<(ostream& out, Vec3& v) {
		out << "{" << v.a << ", " << v.b << ", " << v.c << "}";
		return out;
	}

	double dot(Vec& V1){
		Vec* v1 = &V1;
		Vec3* v = static_cast<Vec3*>(v1);
		
		double res = 0;
		res = a * v->a + b * v->b + c * v->c;
		return res;
	}
	Vec3& cross(Vec& V1) {
		Vec* v1 = &V1;
		Vec3* v = static_cast<Vec3*>(v1);
		
		Vec3* res = new Vec3;
		res->a = b * v->c - c * v->b;
		res->b = c * v->a - a * v->c;
		res->c = a * v->b - b * v->a;
		return *res;
	}
	double Lenth() {
		return sqrt(a * a + b * b + c * c);
	}
	Vec3& Unitization(){
		double Len = Lenth();
		a = a / Len;
		b = b / Len;
		c = c / Len;
		return *this;
	}
};

class Vec4 : public Vec
{
public:
	Vec3* v3;
	double d;
	Vec4() {
		v3 = new Vec3();
		d = 0;
	}
	Vec4(Vec3* V3, double D){
		v3 = new Vec3(*V3);
		d = D;
	}
	Vec4(Vec3 V3, double D) {
		v3 = new Vec3(V3);
		d = D;
	}
	Vec4(double A,double B, double C, double D){
		v3 = new Vec3(A, B, C);
		d = D;
	}
	Vec4(const Vec4& v) {
		v3 = new Vec3(*v.v3);
		d = v.d;
	}
	~Vec4() {
		free(v3);
	}

	Vec4 operator +(const Vec4& v) {
		Vec4 res;
		res.v3->a = v3->a + v.v3->a;
		res.v3->b = v3->b + v.v3->b;
		res.v3->c = v3->c + v.v3->c;
		res.d = d + v.d;
		return res;
	}
	Vec4 operator -(const Vec4& v) {
		Vec4 res;
		res.v3->a = v3->a - v.v3->a;
		res.v3->b = v3->b - v.v3->b;
		res.v3->c = v3->c - v.v3->c;
		res.d = d - v.d;
		return res;
	}
	Vec4 operator *(double n) {
		Vec4 res;
		res.v3->a = v3->a * n;
		res.v3->b = v3->b * n;
		res.v3->c = v3->c * n;
		res.d = d * n;
		return res;
	}
	Vec4 operator /(double n) {
		Vec4 res;
		res.v3->a = v3->a / n;
		res.v3->b = v3->b / n;
		res.v3->c = v3->c / n;
		res.d = d / n;
		return res;
	}
	Vec4& operator =(const Vec4& v) {
		*v3 = *v.v3;
		d = v.d;
		return *this;
	}
	bool operator ==(const Vec4& v) {
		if (*v3 == *v.v3 && d == v.d)return true;
		return false;
	}
	friend ostream& operator <<(ostream& out, Vec4& v) {
		out << "{" << v.v3->a << ", " << v.v3->b << ", " << v.v3->c << ", " << v.d << "}";
		return out;
	}

	double dot(Vec& V1) {
		Vec* v1 = &V1;
		Vec4* v = static_cast<Vec4*>(v1);
		double res = v3->dot(*v->v3) + d * d;
		return res;
	}
	Vec4& cross(Vec& v1) {
		return *this;
	}
	double Lenth() {
		return sqrt(v3->a * v3->a + v3->b * v3->b + v3->c * v3->c + d * d);
	}
	Vec4& Unitization() {
		double Len = Lenth();
		*v3 = *v3/(Len);
		d = d / Len;
		return *this;
	}
};

class ListNode
{
public:
	Vec4 v;
	ListNode* next;
	ListNode(Vec4 V) :v(V) { next = NULL; }
};

class List
{
private:
	ListNode* head;
	ListNode* trail;
	int counter;
public:
	List() { 
		head = NULL; 
		trail = NULL;
		counter = 0;
	}

	ListNode* gethead() { return head; }

	int getsum() { return counter; }

	//链表末尾位置插入节点
	void Insert(Vec4 v) {
		ListNode* p = new ListNode(v);
		if (counter == 0) {
			head = p;
			trail = p;
			counter++;
		}
		else {
			trail->next = p;
			trail = p;
			counter++;
		}
	}

	//在索引位置之前插入节点，头节点索引为0
	void Insert(int index, Vec4 v) {
		//超出索引范围则末尾插入
		if (index >= counter) {
			Insert(v);
			return;
		}

		ListNode* cur = head;
		ListNode* p = new ListNode(v);

		if (index == 0) {
			p->next = head;
			head = p;
			counter++;
			return;
		}
		
		int step = 0;
		while (step < index - 1) {
			cur = cur->next;
			step++;
		}
		p->next = cur->next;
		cur->next = p;
		counter++;
	}

	//末尾删除节点
	void Delete() {
		if (counter == 0) return;
		if (counter == 1) {
			free(head);
			head = NULL;
			trail = NULL;
			counter--;
			return;
		}
		ListNode* p = head;
		while (!(p ->next->v==trail->v)) {	p = p->next;}
		p->next = NULL;
		free(trail);
		trail = p;
		counter--;
	}

	//删除索引位置节点，头节点索引为0
	void Delete(int index) {
		//超出索引范围则末尾删除
		if (index >= counter) {
			Delete();
			return;
		}

		if (index == 0) {
			ListNode* p = head;
			head = head->next;
			free(p);
			counter--;
			return;
		}
		
		int step = 0;
		ListNode* cur = head;
		while (step < index - 1) {
			cur = cur->next;
			step++;
		}
		ListNode* p = cur->next;
		cur->next = cur->next->next;
		free(p);
		counter--;
	}

	void Free() {
		counter = 0;
		ListNode* p;
		while (head != NULL) {
			p = head;
			head = head->next;
			free(p);
		}
	}

	void Iterate() {
		ListNode* p = head;
		while (p != NULL) {
			cout << p->v.v3->a << "    " << p->v.v3->b << "    " << p->v.v3->c << "    " << p->v.d << endl;
			p = p->next;
		}
	}

	friend void Iterate(List L) {
		ListNode* p = L.gethead();
		while (p != NULL) {
			cout << p->v.v3->a << "    " << p->v.v3->b << "    " << p->v.v3->c << "    " << p->v.d << endl;
			p = p->next;
		}
	}
};