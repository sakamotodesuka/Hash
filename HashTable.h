#define SUCCESS 1
#define UNSUCCESS 0
#include<iostream>
#include<string>
using namespace std;

typedef int Status;

typedef struct ElemType // 数据元素类型
{
	char *name;
	int key;
	int hashkey;
	int searchlen;
};

class HashTable{
public:
	ElemType *elem; 
	int count; // 当前数据元素个数
	HashTable();
	Status SearchHash(int K, int &p);
	Status InsertHash(ElemType e);
	int Hash(int key);
	void collision(int &p, int d);
};