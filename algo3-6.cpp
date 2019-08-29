typedef int SElemType;//����ջԪ������Ϊ����
#include"c1.h"
#include"c3-1.h"//˳��ջ�Ĵ洢�ṹ
#include"bo3-1.cpp"//˳��ջ�Ļ�������
#include"func3-1.cpp"//����Precede()��In()��Operate()����
SElemType EvaluateExpression()
{//��������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
  SqStack OPTR,OPND;
  SElemType a,b,d,x;
  char c;
  InitStack(OPTR);//��ʼ�������ջOPTR��������ջOPND
  InitStack(OPND);
  Push(OPTR,'\n');//�����з�ѹ�������ջOPTR��ջ�ס��޸�
  c=getchar();//�ɼ��̶���1���ַ���c
  GetTop(OPTR,x);//�������OPTR��ջ��Ԫ�ظ���x
  while(c!='\n'||x!='\n')//c��x�����ǻ��з�
  {
  	if(In(c))//c��7�������֮һ
	   switch(Precede(x,c))//�ж�x��c������Ȩ
	   {
	   	case'<':Push(OPTR,c);//�����ջOPTR��ջ��Ԫ��x������Ȩ�ͣ���ջc
		        c=getchar();//�ɼ��̶�����һ���ַ���c
				break;
		case'=':Pop(OPTR,x);//x='('��c=')'���������'('��x(�����ӵ���
		        c=getchar();//�ɼ��̶�����һ���ַ���c(�ӵ�cԭ�е�')')
				break;
		case'>':Pop(OPTR,x);//ջ��Ԫ��x������Ȩ�ߣ����������ջOPTR��ջ��Ԫ�ظ�x���޸�
		        Pop(OPND,b);//���ε���������ջOPND��ջ��Ԫ�ظ�b,a
				Pop(OPND,a);
				Push(OPND,Operate(a,x,b));//������a x b������������������ջ 
		} 
	else if(c>='0'&&c<='9')///c�ǲ�����
	{
		d=0;
		while(c>='0'&&c<='9')//����������
		{
			d=d*10+c-'0';
			c=getchar();
		 } 
		Push(OPND,d);//��dѹ��������ջOPND 
	 } 
	 else//c�ǷǷ��ַ�
	 {
	 	printf("���ַǷ��ַ�\n");
		 exit(OVERFLOW); 
	  } 
	GetTop(OPTR,x);//�������ջOPTR��ջ��Ԫ�ظ����� 
   } 
   Pop(OPND,x);//�������ջOPTR��ջ��Ԫ�ظ���x 
   if(!StackEmpty(OPND))//������ջOPND����(�����ջOPTR��ʣ'\n')
   {
   	printf("����ʽ����ȷ\n");
	   exit(OVERFLOW); 
   }
   return x;
  }  

int main()
{
	printf("��������������ʽ������Ҫ�ã�0-��������ʾ\n");
	printf("%d\n",EvaluateExpression()); 
}
  