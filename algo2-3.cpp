#include"c1.h"
typedef int ElemType;
#include"c2-2.h"//���Ա��ĵ������洢�ṹ
#include"bo2-2.cpp"//����ͷ��㵥�����洢�ṹ�Ļ�������
#include"func2-2.cpp"
void CreateList(LinkList &L,int n)
{//��λ�򣨽����ڱ�ͷ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
  int i;
  LinkList p;
  L=(LinkList)malloc(sizeof(LNode));//����ͷ���
  L->next=NULL;//�Ƚ���һ����ͷ���Ŀյ�����
  printf("������%d������\n",n);
  for(i=n;i>0;--i)
  {p=(LinkList)malloc(sizeof(LNode));
   scanf("%d",&p->data);
   p->next=L->next;//���½����ڱ�ͷ 
   L->next=p;//ͷ���ָ���½�� 
   }
 } 
 
 void CreateList1(LinkList &L,int n)
 {//��λ��
   int i;
   LinkList p,q;
   L=(LinkList)malloc(sizeof(LNode));
   L->next=NULL;//�Ƚ���һ����ͷ���Ŀյ����� 
   q=L;//qָ��ձ���ͷ��㣨�൱��β�ڵ㣩
   printf("������%d������\n",n);
   for(i=1;i<=n;i++)
   {p=(LinkList)malloc(sizeof(LNode));
    scanf("%d",&p->data);
    q->next=p;//���½����ڱ�β
	q=q->next; 
	} 
	p->next=NULL;
 }

void MergeList(LinkList La,LinkList &Lb,LinkList &Lc)
{//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����� 
//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
  LinkList pa=La->next,pb=Lb->next,pc;//pa��pb�ֱ�ָ��La��Lb����Ԫ���
  Lc=pc=La;//�� La��ͷ�����ΪLc��ͷ��㣬pcָ��La��ͷ���
  while(pa&&pb) //La��Lb�е�Ԫ�ض�δ�Ƚ���
  {
  	if(pa->data<=pb->data)//La�ĵ�ǰԪ�ز�����Lb�ĵ�ǰԪ��
	{
		pc->next=pa;//��pa��ָ���鲢��Lc��
		pc=pa;//pcָ���Lc�����һ�����
		pa=pa->next;//��La����һ������Ϊ���ȽϽ�� 
	 } 
	 else//Lb�ĵ�ǰԪ��С��La�ĵ�ǰԪ��
	 {
	 	pc->next=pb;//��pb��ָ���鲢��Lc��
		pc=pb;//pcָ���Lc�����һ�����
		pb=pb->next;//��Lb����һ������Ϊ���ȽϽ�� 
	 }
  }
	pc->next=pa?pa:pb;//����ʣ���
	free(Lb);//�ͷ�Lb��ͷ���
	Lb=NULL;//Lb����ָ���κν�� 
}

int main()
{
	int n=5;
	LinkList La,Lb,Lc;
	printf("���ǵݼ�˳��");
	CreateList1(La,n);//��������˳����λ�������Ա�
	printf("La=");
	ListTraverse(La,print);//�������La��nr
	printf("���ǵ���˳��");
	CreateList(Lb,n);//��������˳����λ�������Ա�
	printf("Lb=");
	ListTraverse(Lb,print);//�������Lb������
	MergeList(La,Lb,Lc);//���ǵݼ�˳��鲢La��Lb���õ��±�Lc
	printf("Lc=");
	ListTraverse(Lc,print);//�������Lc������ 
}