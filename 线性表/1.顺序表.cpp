#include <iostream>
using namespace std;
#define MaxLen 100
typedef int DataType;
typedef struct Struct
{
	DataType data[MaxLen];
	int Length;
}Seqlist;
Seqlist L;//定义顺序表L
void InitList(Seqlist* L)//对顺序表长度赋0值初始化
{
	L->Length = 0;
}
void CreateList(Seqlist* L, int n)//建立顺序表
{
	int i;
	cout << "请输入" << n << "个整数"<<endl;
	for ( i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个:";
		cin >> L->data[i];
	}
	L->Length = i;
}
int GetElem(Seqlist* L, int i, DataType* x)//按顺序序号查找，查找顺序表中第 i 个值（从1 -> i进行遍历）
{
	if (i<1 || i>L->Length)//若i值小于1或大于顺序表长度则返回0
	{
		return 0;
	}
	else
	{
		*x = L->data[i - 1];//将顺序表中第i个值赋给指针x所指的变量
		return i;
	}
}
int Locate(Seqlist* L, DataType* x)//通过给定x值进行遍历查找与给定值x相等的数据元素的位置
{

	int i = 0;
	while (i < L->Length && L->data[i] != *x)//通过长度及对比data与需要查找的值进行循环遍历
	{
		i++;
	}
	if (i >= L->Length)//当i大于或等于表L的长度时返回0
	{
		return 0;
	}
	else
	{
		return i + 1;//放回的是元素的位置（数组从0开始）
	}
}
int InsElem(Seqlist* L, int i,DataType* x)
{
	int j;
	if (L->Length >= MaxLen)//判断表长是否达到上限
	{
		cout << "顺序表已满，无法插入值！";
		return -1;
	}
	if (i <1 || i > L->Length + 1)//若插入位置小于1或大于顺序表长度最后一位则放回错误
	{
		cout << "插入位置出错";
		return 0;
	}
	if (i == L->Length + 1)//若插入位置在顺序表尾则直接在顺序标尾插入给定x值，其余数据元素不变，表长加1
	{
		L->data[i - 1] = *x;
		L->Length++;
		return 1;
	}
	else//插入中间位置则从表尾往前进行
	{
		for (j = L->Length - 1; j >= i - 1; j--)//插入表中某一位置，插入位置后各个元素节点位置后移（通过for循环将节点数据赋予后一个数据）
		{
			L->data[j + 1] = L->data[j];
		}
			L->data[i - 1] = *x;//对插入位置赋值
			L->Length++;//表长加1
			return 1;
	}
}
int DelElem(Seqlist* L, int i, DataType* x)
{
	int j;
	if (L->Length == 0)//判断顺序表是否为空
	{
		cout << "顺序表为空，无法进行操作";
		return 0;
	}
	if (i <1 || i > L->Length + 1)//若删除位置小于1或大于表长则返回0
	{
		cout << "不存在第" << i << "个元素";
		return 0;
	}
	else
	{
		*x = L->data[i - 1];//通过指针变量返回删除的元素
		for ( j = i; j < L->Length; j++)//通过for循环从第i个位置往后的节点向前移动
		{
			L->data[j - 1] = L->data[j];
		}
		L->Length--;//表长减1
		return 1;//删除成功，返回
	}
}
void DispList(Seqlist* L)
{
	int i;
	for ( i = 0; i < L->Length; i++)
	{
		cout << L->data[i];
		if (i < L->Length-1)
		{
			cout << ",";
		}
	}
}
void Menu()
{
	cout << "\n=============================================" << endl;
	cout << "|                1.建立顺序表               |" << endl;
	cout << "|                2.插入元素                 |" << endl;
	cout << "|                3.删除元素                 |" << endl;
	cout << "|                4.按位置查找元素           |" << endl;
	cout << "|                5.按元素值查找元素位置     |" << endl;
	cout << "|                6.求顺序表长度             |" << endl;
	cout << "|                0.返回                     |" << endl;
	cout << "=============================================" << endl;

}
int main()
{
	Seqlist L;
	DataType x;
	int n, i, loc;
	char ch1, ch2, a;
	ch1 = 'y';
	while (ch1 == 'y' || ch1 =='Y')
	{
		Menu();
		cout << "请选择:";
		cin >> ch2;
		getchar();
		switch (ch2)
		{
		case '1':
		{
			InitList(&L);
			cout << "请输入建立顺序表的数据个数:";
			cin >> n;
			CreateList(&L, n);
			cout << "建立的顺序表为:" ;
			DispList(&L);
			cout << endl;
			break;
		}
		case '2':
		{
			cout << "需要插入的位置:";
			cin >> i;
			cout << "需要插入的值:";
			cin >> x;
			if (InsElem(&L, i, &x))
			{
				cout << "\n操作成功，当前顺序表为:" << endl;
				DispList(&L);
			}
			else
			{
				cout << "\n操作失败";
			}
			break;
		}
		case '3':
		{
			cout << "需要删除的值的位置:";
			cin >> i;
			if (DelElem(&L,i,&x))
			{
				cout << "\n操作成功";
				DispList(&L);
			}
			else
			{
				cout << "\n操作失败";
			}
			break;
		}
		case '4':
		{
			cout << "请输入要查看表中元素:";
			cin >> i;
			if (GetElem(&L, i, &x))
			{
				cout << "\n当前第" << i << "个元素的值为:" << x;
			}
			else
			{
				cout << "输入的位置错误" << endl;
			}
			break;
		}
		case '5':
		{
			cout << "请输入要查找的元素:";
			cin >> x;
			loc = Locate(&L, &x);
			if (loc)
			{
				cout << "查找的元素值为" << x << "的位置为:" << loc << endl;
			}
			else
			{
				cout << "表中无该元素" << endl;
			}
			break;
		}
		case '6':
		{
			cout << "当前顺序表长度为" << L.Length << endl;
			break;
		}
		case '0':
		{
			ch1 = 'n';
			break;
		}
		
		default:
		{
			cout << "输入有误，请重新输入" << endl;
		}
			break;
		}
	}
	if (ch2 != '0')
	{
		cout << "\n按回车继续，按任意键返回主菜单\n";
		a = getchar();
		if (a != '\xA')
		{
			getchar();
			ch1 = 'n';
		}
	}
}