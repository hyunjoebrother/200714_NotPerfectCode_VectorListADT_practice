#include "ArrayVector.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm> //max �Լ� ����

//Array�� LinkedList ���� �Լ�


//���� ���� �Լ�

//������
ArrayVector::ArrayVector()
	:A(NULL),capacity(0),n(0) { }

void ArrayVector::reserve(int N) //N���� ������ Ȯ��
{
	if (capacity >= N) //�̹� ����� ũ��
		return;
	Elem* B = new Elem[N]; //�� ū �迭 B�� �Ҵ�

	for (int j = 0; j < n; j++) //������ �� �迭 B�� ����
		B[j] = A[j];

	if (A != NULL) //���� �迭 A ����
		delete[] A;
	A = B; //B�� �� �迭�� �����
	capacity = N; //���ο� �뷮 ����
}

int ArrayVector::size() const
{
	return n;
}

bool ArrayVector::empty() const
{
	return (n < 0);
}

Elem& ArrayVector::operator[](int i) //�ε����� �ִ� ����
{
	return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) //�ε����� �ִ� ����
{
	if (i < 0 || i >= n)
		throw IndexOutOfBounds("illegal index in function at ()");
	return A[i];
}

void ArrayVector::erase(int i) //�ε����� �ִ� ���� ����
{
	for (int j = i + 1; j < n; j++) //���ҵ��� ������ �̵�
		A[j - 1] = A[j]; 
	n--; //���� ���� 1����
}

void ArrayVector::insert(int i, const Elem& e) //�ε����� ���� ����
{
	if (n >= capacity) //�����÷ο��ΰ�
		reserve(max(1, 2 * capacity)); //�迭 ũ�⸦ 2��� doubling
	for (int j = n - 1; j >= i; j--) //���Ҹ� �ڷ� �̵�
		A[j + 1] = A[j];
	A[i] = e; //�� �ڸ��� ����
	n++; //���� ���� 1����
}


//test �Լ� (int main)
int main()
{
	ArrayVector A;

	A.insert(13,1);

	cout << A.at(1) << endl;
	cout << A.empty() << endl;
	cout << A.size() << endl;
}