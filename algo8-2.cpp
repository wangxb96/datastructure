#include"c1.h"
#include"func8-2.cpp"
#include"c8-1.h"
#include"c8-2.h"
#include"bo8-1.cpp"
int main()
{
	SSTable st;
	int i;
	KeyType s;
	Creat_OrdFromFile(st,"f8-2.txt");
	printf("有序表为: ");
	Traverse(st,Visit);
	printf("\n");
	printf("请输入待查找数据的关键字");
	InputKey(s);
	i=Search_Bin(st,s);
	//在有序的静态查找表st中折半查找含有关键字sx的项的序号
    if(i)
	  printf("%d是第%d个数据的关键字\n",st.elem[i].key,i);
	else
	  printf("未找到\n");
	Destroy(st); 
}
