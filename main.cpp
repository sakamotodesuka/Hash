#include"HashTable.h"
#include<iomanip>

int menu();

int getKey(char name[]){
	int key = 0;
	for (int i = 0; name[i] != '\0'; i++)
	{
			key += name[i];
	}
	return key;
}

void TraverseHash(HashTable H)
{ // 按哈希地址的顺序遍历哈希表
	int p = 0;
	printf("哈希地址0～%d\n", 50 - 1);
	cout << left << setw(15) << "地址" << setw(15) << "关键字" << setw(15)
		<< "搜索长度" << setw(15) << "H<key>" << "姓名" << endl;
	for (int i = 0; i < 50; i++)
	{
		if (H.elem[i].key != 0) // 有数据
		{
			H.SearchHash(H.elem[i].key, p);
			cout << left << setw(15) << i << setw(15) << H.elem[i].key << setw(15)
				<< H.elem[i].searchlen << setw(15) << H.elem[i].hashkey << H.elem[i].name << endl;
		}
		else cout << left << setw(15) << i << setw(15) << H.elem[i].key << setw(15)
			<< H.elem[i].searchlen << setw(15) << H.elem[i].hashkey << "" << endl;
	}
	
}

double getASL(HashTable h);

int main()
{
	int s ,p, option;
	char *name = new char[30];
	ElemType e[] = 
	{
		{ "WangKuan" }, { "ZhuDaKang" }, { "GuoYiQing" }, { "YangYaoTing" }, { "XieZiYu" },
		{ "ShenJiaLiang" }, { "ZhangYang" }, { "WeiYiLin" }, { "GaoQi" }, { "XieMuGan" },
		{ "DingRuiDi" }, { "YiFangQiu" }, { "LinManShan" }, { "LiDongLin" }, { "ZhangLiZhe" },
		{ "ChenJie" }, { "TanJie" }, { "ZuoTaiXu" }, { "WangMingZhe" }, { "WengTingYu" },
		{ "LiHaiMing" }, { "DuGuoMing" }, { "WangWenZhe" }, { "LiYiMing" }, { "LiuDingNing" },
		{ "LiLuYao" }, { "LiHongJia" }, { "HuangJingYu" }, { "WangBoAi" }, { "YinSiYi" }
	};
	HashTable h;
	for (int i = 0; i < 30; i++)
	{	
		e[i].key = getKey(e[i].name);
		h.InsertHash(e[i]);
	}
	do
	{
		option = menu();
		switch (option){
		case 1:{
				   TraverseHash(h);
				   cout << "ASL = " << getASL(h) << endl;
				   break;
		}
		case 2:{
				   cout << "请输入姓名：";
				   cin >> name;
				   s = getKey(name);
				   if (h.SearchHash(s, p))
						cout << "姓名：" << name << "  关键字：" << h.elem[p].key
							 << "  哈希地址：" << h.elem[p].hashkey << "   搜索长度："
							 << h.elem[p].searchlen << endl;
				   else cout << "无记录!\n";
				   break;
		}
		case 3: return 0;
		default: cout << "不存在该操作数， 请重新选择操作\n";
		}
	} while (option != 3);
	delete name;
	int a;
	cin >> a;

}

int menu()
{
	int option;
	cout << right << setw(25) << "" << setfill('*') << setw(30) << "\n";
	cout << right << setfill(' ') << setw(26) << "*" << setw(17) << "哈希表"
		<< right << setw(11) << "*" << endl;
	cout << right << setw(25) << "" << setfill('*') << setw(30) << "\n";
	cout.fill(' ');
	cout << left << setw(25) << " " << "1.显示哈希表\n";
	cout << setw(25) << " " << "2.查找人名\n";
	cout << setw(25) << " " << "3.退出\n";
	cout << setw(25) << " " << "选择：";
	cin >> option;
	return option;
}

double getASL(HashTable h)
{
	double ASL = 0;
	for (int i = 0; i < 50; i++)
	{
		ASL += h.elem[i].searchlen;
	}
	return ASL / 30;
}