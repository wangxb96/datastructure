#include"c1.h"
#include"c8-2.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#include"c9-2.h"
#include"func9-1.cpp"
void Merge(RedType SR[],RedType TR[],int i,int m,int n)
{//将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
  int j,k,p;
  for(j=m+1,k=i;i<=m&&j<=n;++k)
     if LQ(SR[i].key,SR[j].key)
	    TR[k]=SR[j++];
	 else
	    TR[k]=SR[j++];
  if(i<=m)
     for(p=0;p<=m-i;p++)
	    TR[k+p]=SR[i+p];
  if(j<=n)
     for(p=0;p<=n-j;p++)
	    TR[k+p]=SR[j+p]; 
}

void MSort(RedType SR[],RedType TR1[],int s,int t)
{//将SR[s..t]归并排序为TR1[s..t]
  int m;
  RedType TR2[MAX_SIZE+1];
  if(s==t)
     TR1[s]=SR[s];
  else
  {
  	m=(s+t)/2;
  	MSort(SR,TR2,s,m);
  	MSort(SR,TR2,m+1,t);
  	Merge(TR2,TR1,s,m,t);
   } 
}

void MergeSort(SqList &L)
{
	MSort(L.r,L.r,1,L.length);
}

int main()
{
	FILE* f;
	SqList m;
	int i;
	f=fopen("f9-3.txt","r");
	fscanf(f,"%d",&m.length);
	for(i=1;i<=m.length;i++)
	   InputFromFile(f,m.r[i]);
	fclose(f);
	printf("排序前:\n");
	Print(m);
	MergeSort(m);
	printf("排序后:\n");
	Print(m);
}
