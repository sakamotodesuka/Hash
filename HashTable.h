#define SUCCESS 1
#define UNSUCCESS 0
#include<iostream>
#include<string>
using namespace std;

typedef int Status;

typedef struct ElemType // ����Ԫ������
{
	char *name;
	int key;
	int hashkey;
	int searchlen;
};

class HashTable{
public:
	ElemType *elem; 
	int count; // ��ǰ����Ԫ�ظ���
	HashTable();
	Status SearchHash(int K, int &p);
	Status InsertHash(ElemType e);
	int Hash(int key);
	void collision(int &p, int d);
};