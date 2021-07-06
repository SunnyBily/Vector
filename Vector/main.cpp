#include<iostream>
#include"Vector.h"
using namespace std;

void Test_Vec3() {
	Vec3 a(1, 1, 1), b(1, 2, 1), c = a;
	cout << "����a = " << a << "    ����b = " << b << endl;
	
	cout << "a��b = " << a.dot(b) << endl;
	c = a.cross(b);
	cout << "a��b = " << c << endl;
	c = a + b;
	cout << "a + b = " << c << endl;
	c = a - b;
	cout << "a - b = " << c << endl;
	c = a * 2;
	cout << "a * 2 = " << c << endl;
	c = a / 2;
	cout << "a / 2 = " << c << endl;
	double n = a.Lenth();
	cout << "a �ĳ��� = " << n << endl;
	c = a.Unitization();
	cout << "a��λ��= " << c << endl;

}
void Test_Vec4() {
	Vec4 a(1, 2, 3, 4), b(2, 2, 3, 4), c = a;
	cout << "����a = " << a << "    ����b = " << b << endl;
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
	cout << "a��b = " << n << endl;
	n = a.Lenth();
	cout << "a �ĳ��� = " << n << endl;
	c = a.Unitization();
	cout << "a��λ��= " << c << endl;
	
}
void Test_List() {
	
	Vec4 a(1, 2, 3, 4), b(2, 2, 3, 4), c(3, 4, 5, 6), d(9, 9, 9, 9);
	List L;
	cout << "����a = " << a << "    ����b = " << b << "    ����c = " << c << "    ����d = " << d << endl;
	
	cout << "ĩβ����a:" << endl;
	L.Insert(a);
	L.Iterate();
	cout << endl;
	cout << "ĩβ����b:" << endl;
	L.Insert(b);
	L.Iterate();
	cout << endl;
	cout << "ĩβ����c:" << endl;
	L.Insert(c);
	L.Iterate();
	cout << endl;

	cout << "λ��0����d:" << endl;
	L.Insert(0, d);
	L.Iterate();
	cout << endl;
	cout << "ɾ��λ��0:" << endl;
	L.Delete(0);
	L.Iterate();
	cout << endl;
	cout << "λ��1����d:" << endl;
	L.Insert(1, d);
	L.Iterate();
	cout << endl;
	cout << "ɾ��λ��1:" << endl;
	L.Delete(1);
	L.Iterate();
	cout << endl;
	cout << "λ��2����d:" << endl;
	L.Insert(2, d);
	L.Iterate();
	cout << endl;
	cout << "ɾ��λ��2:" << endl;
	L.Delete(2);
	L.Iterate();
	cout << endl;
	cout << "λ��3����d:" << endl;
	L.Insert(3, d);
	L.Iterate();
	cout << endl;
	cout << "ɾ��λ��3:" << endl;
	L.Delete(3);
	L.Iterate();
	cout << endl;

	cout << "�ͷ�����" << endl;
	L.Free();
	Iterate(L);
}

int main() {
	Test_Vec3();
	Test_Vec4();
	Test_List();
}