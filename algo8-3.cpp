#include"c1.h"
#include"func8-3.cpp"
#include"c8-1.h"
#include"c8-2.h"
#include"bo8-1.cpp"
typedef ElemType TElemType;
#include"c6-2.h"
#include"bo6-2.cpp"
#define N 100
Status SecondOptimal(BiTree &T,ElemType R[],int sw[],int low,int high)
{//�������R[low..high]�����ۼ�Ȩֵ��sw(����sw[0]==0)�ݹ鹹����Ų�����T
  int j,i=low;
  double dw=sw[high]+sw[low-1];
  double min=fabs(sw[high]-sw[low]);
  for(j=low+1;j<=high;++j)
     if(fabs(dw-sw[j]-sw[j-1])<min)
	 {
	 	i=j;
	 	min=fabs(dw-sw[j]-sw[j-1]);
	  } 
	if(!(T=(BiTree)malloc(sizeof(BiTNode))))
	   return ERROR;
	T->data=R[i];
	if(i==low)
	  T->lchild=NULL;
	else
	  SecondOptimal(T->lchild,R,sw,low,i-1);
	if(i==high)
	  T->rchild=NULL;
	else
	  SecondOptimal(T->rchild,R,sw,i+1,high);
	return OK;
 } 
 
void FindSW(int sw[],SSTable ST)
{//���������ST�и�����Ԫ�ص�Weight�����ۼ�Ȩֵ����sw��CreateSOSTree()����
  int i;
  sw[0]=0;//�ñ߽�ֵ
  printf("\nsw=0");
  for(i=1;i<=ST.length;i++)//��С��������ۼ�Ȩֵsw[i]����� 
  {
  	sw[i]=sw[i-1]+ST.elem[i].weight;//�ۼ�Ȩֵ[i]=�ۼ�Ȩֵ[i-1]+[i]��Ȩֵ
	printf("%5d",sw[i]); 
   } 
}

typedef BiTree SOSTree;
void CreateSOSTree(SOSTree &T,SSTable ST)
{//�������ST����һ�Ŵ��Ų�����T��ST������Ԫ�غ���Ȩ��weight��
  int sw[N+1];
  if(ST.length==0)
     T=NULL;
  else
  {
  	FindSW(sw,ST);
  	SecondOptimal(T,ST.elem,sw,1,ST.length);
  	//�������ST[1..ST.length]�����ۼ�Ȩֵ��sw(����sw[0]==0)�ݹ鹹����Ų�����T 
   } 
}

Status Search_SOSTree(SOSTree &T,KeyType key)
{//�ڴ��Ų�����T�в������ؼ��ֵ���key��Ԫ�ء��ҵ��򷵻�OK��Tָ���Ԫ��
   while(T)
      if(T->data.key==key)
	     return OK;
	  else if(T->data.key>key)
	     T=T->lchild;
	  else
	     T=T->rchild;
	return FALSE; 
}

int main()
{
	SSTable st;
	SOSTree t;
	Status i;
	KeyType s;
	Creat_OrdFromFile(st,"f8-3.txt");
	printf("     ");
	Traverse(st,Visit);
	CreateSOSTree(t,st);
	printf("\n����������ҵ��ַ�:");
	InputKey(s);
	i=Search_SOSTree(t,s);
	if(i)
	  printf("%c��Ȩֵ��%d\n",s,t->data.weight);
	else
	  printf("���в����ڴ��ַ�\n");
	DestroyBiTree(t); 
}