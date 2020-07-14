//Vector ADT

//linear, ����x -> ������ ��ġ�� ��� ����
//Array ���� Ȯ�� - N���� ���� ������ �����ؼ� ���
//������ object�� �������� ����
//Index - ���� ���� ��ġ ����

#include <iostream>
using namespace std;
#include <string>

//����ó��
class IndexOutOfBounds //�Ѱ� ���� �ε��� ���� invalid�� �� �޽���
{
private:
	string errorMsg;
public:
	IndexOutOfBounds(const string& err)
	{
		errorMsg = err;
	}
};

//Array�� LinkedList ����

//����
typedef int Elem;
class ArrayVector
{
private:
	Elem* A; //���Ҹ� �����ϴ� �迭
	int capacity; //�迭�� ũ��
	int n; //Vector�� ����� ���ҵ��� ��

public:
	//������
	ArrayVector();

	void reserve(int N); //N���� ������ Ȯ��

	int size() const;
	bool empty() const;

	Elem& operator[](int i); //�ε����� �ִ� ����
	Elem& at(int i) throw(IndexOutOfBounds); //�ε����� �ִ� ����

	void erase(int i); //�ε����� �ִ� ���� ����
	void insert(int i, const Elem& e); //�ε����� ���� ����
};