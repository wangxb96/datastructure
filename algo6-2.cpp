#include"c1.h"
#include"c6-5.h"
#include"func6-2.cpp"
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{//w���n���ַ���Ȩֵ(��>0)������շ�����HT�������n���ַ��ĺշ�������HC
  unsigned cdlen;
 #include"func6-3.cpp"
  HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
  cd=(char*)malloc(n*sizeof(char));
  c=m;
  cdlen=0;
  for(i=1;i<=m;++i)
     HT[i].weight=0;
  while(c)
  {
  	if(HT[c].weight==0)
  	{
  		HT[c].weight=1;
  		if(HT[c].lchild!=0)
  		{
  			c=HT[c].lchild;//��cΪ���������
			cd[cdlen++]='0'; 
		  }
		else if(HT[c].rchild==0)
		{
			HC[c]=(char*)malloc((cdlen+1)*sizeof(char));
			cd[cdlen]='\0';
			strcpy(HC[c],cd);
		}
		
	  }
	else if(HT[c].weight==1)
	{
		HT[c].weight=2;
		if(HT[c].rchild!=0)
		{
			c=HT[c].rchild;//��cΪ���Һ������ 
			cd[cdlen++]='1';
		}
	}
	else//���Һ��Ӿ������ʹ�(HT[c].weight==2),�����㷽����һ��
	{
		c=HT[c].parent;//��cΪ��˫�����
		--cdlen; 
	 } 
   } 
   free(cd);
 } 
 #include"func6-4.cpp"