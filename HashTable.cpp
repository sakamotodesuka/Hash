#include"HashTable.h"

HashTable::HashTable()
{
	int i;
	count = 0; // 当前元素个数为0
	elem = new ElemType[50];
	for (i = 0; i < 50; i++)
	{
		elem[i].key = elem[i].hashkey = elem[i].searchlen = 0; 
	}
		
}

Status HashTable::SearchHash(int K, int &p)
{
	if (K){
		int c = 0;
		p = Hash(K); // 求得哈希地址
		while (elem[p].key != 0 && K != elem[p].key)
		{ // 该位置中填有记录．并且关键字不相等
			c++;
			if (c < 50)
				collision(p, c); // 求得下一探查地址
			else
				return UNSUCCESS; 
		}
		if (K == elem[p].key)
		{
			elem[p].searchlen = c + 1;
			return SUCCESS; 
		}
		else
			return UNSUCCESS;
	}
	return UNSUCCESS;
}

Status HashTable::InsertHash(ElemType e)
{ 
	int c, p;
	c = 0;
	if (SearchHash(e.key, p)) 
		return -1;
	elem[p] = e;
	elem[p].hashkey = p;
	++count;
	return 1;
}

int HashTable::Hash(int key)
{
	return key % 50;
}

void HashTable::collision(int &p, int d)
{
	p = p = (p + d) % 50;
}