#include"c1.h"
#define N 6 //字符串的最大长度+1
typedef char ElemType[N];//定义ElemType为字符串类型
#include"c2-3.h"//线性表的静态单链表存储结构
int main()
{
	SLinkList s={{"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHENG",8},{"WANG",0}};
	int i=s[0].cur;//i指示第1各结点的位置
	while(i)
	{
		printf("%s ",s[i].data);//输出链表的当前值
		i=s[i].cur;//找到下一个数据的位置 
	 } 
	 printf("\n");
	 s[4].cur=9;
	 s[9].cur=5;
	 strcpy(s[9].data,"SHI");
	 s[6].cur=8;//删除"ZHENG"
	 i=s[0].cur;//i指示第1个结点的位置
	 while(i)
	 {
	 	printf("%s ",s[i].data);//输出链表的当前值
		i=s[i].cur;//找到下一个数据的位置 
	  } 
	  printf("\n");
 } 
