#include"c1.h"
typedef int QElemType;//定义队列元素为整型
#include"c3-3.h"
#include"bo3-4.cpp"
#define ElemType QElemType
#include"func2-2.cpp"
int main()
{
	Status j;
	int i=0,m;
	QElemType d;
	SqQueue Q;
	InitQueue(Q);
	printf("初始化队列后，队列空否?%u(1:空 0:否)\n",QueueEmpty(Q));
	printf("请输入整型队列元素（不超过%d个）,-1为提前结束符:",MAX_QSIZE-1);
	do
	{
		scanf("%d",&d);
		if(d==-1)
		  break;
		i++;
		EnQueue(Q,d);//入队输入的元素 
	 } while(i<MAX_QSIZE-1);//队列元素的个数不超过允许的范围
	 printf("队列长度为%d,",QueueLength(Q));
	 printf("现在队列空否?%u(1:空  0：否)\n",QueueEmpty(Q));
	 printf("连续%d次由队头删除元素，队尾插入元素:\n",MAX_QSIZE);
	 for(m=1;m<=MAX_QSIZE;m++)
	 {
	 	DeQueue(Q,d);
	 	printf("删除的元素是%d,请输入待插入的元素:",d);
	 	scanf("%d",&d);
	 	EnQueue(Q,d); 
	  } 
	  m=QueueLength(Q);//m为队列Q的长度
	  printf("现在队列中的元素为");
	  QueueTraverse(Q,print);
	  printf("共向队尾插入了%d个元素，",i+MAX_QSIZE);
	  if(m-2>0)
	    printf("现在由队头删除%d个元素,",m-2);
	  while(QueueLength(Q)>2)
	  {
	  	DeQueue(Q,d);
	  	printf("删除的元素值为%d，",d); 
	  }
	  j=GetHead(Q,d);//将队头元素赋给d
	  if(j)
	    printf("现在队头元素为%d\n",d);
	  ClearQueue(Q);//清空队列Q
	  printf("清空队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));
	  DestroyQueue(Q);//销毁队列Q 
	   } 
