//Vector ADT

//linear, 제약x -> 임의의 위치에 모두 가능
//Array 개념 확장 - N개의 연속 공간을 예측해서 잡기
//임의의 object의 시퀀스를 저장
//Index - 연산 실행 위치 지정

#include <iostream>
using namespace std;
#include <string>

//예외처리
class IndexOutOfBounds //넘겨 받은 인덱스 값이 invalid할 때 메시지
{
private:
	string errorMsg;
public:
	IndexOutOfBounds(const string& err)
	{
		errorMsg = err;
	}
};

//Array나 LinkedList 구현

//메인
typedef int Elem;
class ArrayVector
{
private:
	Elem* A; //원소를 저장하는 배열
	int capacity; //배열의 크기
	int n; //Vector에 저장된 원소들의 수

public:
	//생성자
	ArrayVector();

	void reserve(int N); //N개의 공간을 확보

	int size() const;
	bool empty() const;

	Elem& operator[](int i); //인덱스에 있는 원소
	Elem& at(int i) throw(IndexOutOfBounds); //인덱스에 있는 원소

	void erase(int i); //인덱스에 있는 원소 삭제
	void insert(int i, const Elem& e); //인덱스에 원소 삽입
};