#include"c1.h"
#define N 6 //�ַ�������󳤶�+1
typedef char ElemType[N];//����ElemTypeΪ�ַ�������
#include"c2-3.h"//���Ա��ľ�̬�������洢�ṹ
int main()
{
	SLinkList s={{"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHENG",8},{"WANG",0}};
	int i=s[0].cur;//iָʾ��1������λ��
	while(i)
	{
		printf("%s ",s[i].data);//��������ĵ�ǰֵ
		i=s[i].cur;//�ҵ���һ�����ݵ�λ�� 
	 } 
	 printf("\n");
	 s[4].cur=9;
	 s[9].cur=5;
	 strcpy(s[9].data,"SHI");
	 s[6].cur=8;//ɾ��"ZHENG"
	 i=s[0].cur;//iָʾ��1������λ��
	 while(i)
	 {
	 	printf("%s ",s[i].data);//��������ĵ�ǰֵ
		i=s[i].cur;//�ҵ���һ�����ݵ�λ�� 
	  } 
	  printf("\n");
 } 