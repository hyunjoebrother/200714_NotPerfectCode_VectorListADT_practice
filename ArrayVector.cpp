#include "ArrayVector.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm> //max 함수 ㅇㅇ

//Array나 LinkedList 구현 함수


//메인 관련 함수

//생성자
ArrayVector::ArrayVector()
	:A(NULL),capacity(0),n(0) { }

void ArrayVector::reserve(int N) //N개의 공간을 확보
{
	if (capacity >= N) //이미 충분히 크다
		return;
	Elem* B = new Elem[N]; //더 큰 배열 B를 할당

	for (int j = 0; j < n; j++) //내용을 새 배열 B로 복사
		B[j] = A[j];

	if (A != NULL) //기존 배열 A 삭제
		delete[] A;
	A = B; //B를 새 배열로 만든다
	capacity = N; //새로운 용량 설정
}

int ArrayVector::size() const
{
	return n;
}

bool ArrayVector::empty() const
{
	return (n < 0);
}

Elem& ArrayVector::operator[](int i) //인덱스에 있는 원소
{
	return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds) //인덱스에 있는 원소
{
	if (i < 0 || i >= n)
		throw IndexOutOfBounds("illegal index in function at ()");
	return A[i];
}

void ArrayVector::erase(int i) //인덱스에 있는 원소 삭제
{
	for (int j = i + 1; j < n; j++) //원소들을 앞으로 이동
		A[j - 1] = A[j]; 
	n--; //원소 개수 1감소
}

void ArrayVector::insert(int i, const Elem& e) //인덱스에 원소 삽입
{
	if (n >= capacity) //오버플로우인가
		reserve(max(1, 2 * capacity)); //배열 크기를 2배로 doubling
	for (int j = n - 1; j >= i; j--) //원소를 뒤로 이동
		A[j + 1] = A[j];
	A[i] = e; //빈 자리에 삽입
	n++; //원소 개수 1증가
}


//test 함수 (int main)
int main()
{
	ArrayVector A;

	A.insert(13,1);

	cout << A.at(1) << endl;
	cout << A.empty() << endl;
	cout << A.size() << endl;
}