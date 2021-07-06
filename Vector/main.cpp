#include<iostream>
#include"Vector.h"
using namespace std;

void Test_Vec3() {
	Vec3 a(1, 1, 1), b(1, 2, 1), c = a;
	cout << "向量a = " << a << "    向量b = " << b << endl;
	
	cout << "a·b = " << a.dot(b) << endl;
	c = a.cross(b);
	cout << "a×b = " << c << endl;
	c = a + b;
	cout << "a + b = " << c << endl;
	c = a - b;
	cout << "a - b = " << c << endl;
	c = a * 2;
	cout << "a * 2 = " << c << endl;
	c = a / 2;
	cout << "a / 2 = " << c << endl;
	double n = a.Lenth();
	cout << "a 的长度 = " << n << endl;
	c = a.Unitization();
	cout << "a单位化= " << c << endl;

}
void Test_Vec4() {
	Vec4 a(1, 2, 3, 4), b(2, 2, 3, 4), c = a;
	cout << "向量a = " << a << "    向量b = " << b << endl;
	double n;
	c = a + b;
	cout << "a + b = " << c << endl;
	c = a - b;
	cout << "a - b = " << c << endl;
	c = a * 2;
	cout << "a * 2 = " << c << endl;
	c = a / 2;
	cout << "a / 2 = " << c << endl;
	n = a.dot(b);
	cout << "a·b = " << n << endl;
	n = a.Lenth();
	cout << "a 的长度 = " << n << endl;
	c = a.Unitization();
	cout << "a单位化= " << c << endl;
	
}
void Test_List() {
	
	Vec4 a(1, 2, 3, 4), b(2, 2, 3, 4), c(3, 4, 5, 6), d(9, 9, 9, 9);
	List L;
	cout << "向量a = " << a << "    向量b = " << b << "    向量c = " << c << "    向量d = " << d << endl;
	
	cout << "末尾插入a:" << endl;
	L.Insert(a);
	L.Iterate();
	cout << endl;
	cout << "末尾插入b:" << endl;
	L.Insert(b);
	L.Iterate();
	cout << endl;
	cout << "末尾插入c:" << endl;
	L.Insert(c);
	L.Iterate();
	cout << endl;

	cout << "位置0插入d:" << endl;
	L.Insert(0, d);
	L.Iterate();
	cout << endl;
	cout << "删除位置0:" << endl;
	L.Delete(0);
	L.Iterate();
	cout << endl;
	cout << "位置1插入d:" << endl;
	L.Insert(1, d);
	L.Iterate();
	cout << endl;
	cout << "删除位置1:" << endl;
	L.Delete(1);
	L.Iterate();
	cout << endl;
	cout << "位置2插入d:" << endl;
	L.Insert(2, d);
	L.Iterate();
	cout << endl;
	cout << "删除位置2:" << endl;
	L.Delete(2);
	L.Iterate();
	cout << endl;
	cout << "位置3插入d:" << endl;
	L.Insert(3, d);
	L.Iterate();
	cout << endl;
	cout << "删除位置3:" << endl;
	L.Delete(3);
	L.Iterate();
	cout << endl;

	cout << "释放链表" << endl;
	L.Free();
	Iterate(L);
}

int main() {
	Test_Vec3();
	Test_Vec4();
	Test_List();
}