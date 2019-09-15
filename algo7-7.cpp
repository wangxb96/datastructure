#include"c1.h"
#include"func7-1.cpp"
#include"func7-4.cpp"
#include"c7-2'.h"
#include"bo7-2.cpp"
#include"func7-5.cpp"
typedef int SElemType;
#include"c3-1.h"
#include"bo3-1.cpp"
Status TopologicalSort(ALGraph G)
{//����ͼG�����ڽӱ��洢�ṹ����G�޻�·�������G�Ķ����һ���������в�����OK
   int i,k,count=0;
   int indegree[MAX_VERTEX_NUM];
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree);
   InitStack(S);
   for(i=0;i<G.vexnum;++i)
     if(!indegree[i])
	   Push(S,i);
   while(!StackEmpty(S))
   {
   	Pop(S,i);
   	printf("%s",G.vertices[i].data.name);
	++count;
	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
	{
		k=p->data.adjvex;
		if(!(--indegree[k]))//k����ȼ�1������Ϊ0����k��ջS
		  Push(S,k); 
	 } 
	} 
	if(count<G.vexnum)
	{
		printf("������ͼ�л�·\n");
		return ERROR;
	}
	else
	{
		printf("Ϊһ���������С�\n");
		return OK;
	}
}

int main()
{
	ALGraph f;
	printf("��ѡ������ͼ\n");
	CreateGraph(f);
	Display(f);
	TopologicalSort(f);
}