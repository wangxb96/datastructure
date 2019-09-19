int SelectMinKey(SqList L,int i)
{//������L.r[i..L.length]��key��С�ļ�¼�����
  int  j,k=i;//��ʼ��[i]�Ĺؼ���Ϊ��С����i��k
  KeyType min=L.r[i].key;//[i]�Ĺؼ��ִ���min
  for(j=i+1;j<=L.length;j++)
     if(L.r[j].key<min)
	 {
	 	k=j;//�ֱ𽫸�С�ĸ���k��min
		min=L.r[j].key; 
	  } 
   return k;
}

void SelectSort(SqList &L)
{//��˳���L����ѡ������ 
	int i,j;
	RedType t;
	for(i=1;i<L.length;++i)
	{
		j=SelectMinKey(L,i);//��L.r[i..L.length]��ѡ��key��С�ļ�¼ 
		if(i!=j)
		{
			t=L.r[i];//���i����¼������ʹ�õ�iС�Ĵ���[i]
			L.r[i]=L.r[j];
			L.r[j]=t; 
		}
	 } 
}

void TreeSort(SqList &L)
{//����ѡ������  
	int i,n;
	RedType* t;
	t=(RedType*)malloc((2*L.length-1)*sizeof(RedType));//����������˳��洢�ṹ
	for(i=1;i<=L.length;i++)//��L.r����Ҷ�ӽ��(���ϵ��£�������)
	  t[L.length-2+i]=L.r[i];
	for(i=L.length-2;i>=0;i--)
	  t[i]=t[2*i+1].key<=t[2*i+2].key?t[2*i+1]:t[2*i+2];
	  //��Ҷ�ӽ���ֵΪ�����Һ����йؼ���С��
	for(i=0;i<L.length;i++)
	{
		L.r[i+1]=t[0];//����ǰ��Сֵ����L.r[i]
		n=0;//��������
		do{
			n=t[2*n+1].key==t[n].key?2*n+1:2*n+2;
		}while(n<L.length-1);
	    t[n].key=INT_MAX;
		while(n)//n���Ǹ���� 
		{
			n=(n+1)/2-1;//���Ϊn�Ľ���˫�׽�����
			t[n]=t[2*n+1].key<=t[2*n+2].key?(t[2*n+1]):(t[2*n+2]);
			//��Ҷ�ӽ���ֵΪ�����Һ����йؼ���С�� 
		 } 
	 } 
	 free(t);
}

void HeapAdjust(HeapType &H,int s,int m)
{//��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������󶥶ѵĶ��壬����������H.r[s]�Ĺؼ��֣�ʹH.r[s..m]�м�¼�Ĺؼ��־�����󶥶ѵĶ���
  int j;
  H.r[0]=H.r[s];
  for(j=2*s;j<=m;j*=2)//jָ���������¼[s]�����ӣ���key�ϴ�ĺ��ӽ������ɸѡ
  {
  	if(j<m&&LT(H.r[j].key,H.r[j+1].key))
  	  ++j;//jָ��[s]��youhaiz
	if(!LT(H.r[0].key,H.r[j].key))//[s]�Ĺؼ��ֲ�С��[j]�Ĺؼ��֣��޸�
	  break;
	H.r[s]=H.r[j];//����[j]Ϊ�󶥣�����[s]
    s=j; 
   } 
   H.r[s]=H.r[0];
}

void HeapSort(HeapType &H)
{//��˳���H���ж����� 
	int i;
	for(i=H.length/2;i>0;--i)
	   HeapAdjust(H,i,H.length);//����H.r[i]��ʹH.r[i..H.length]��Ϊ�󶥶�
	for(i=H.length;i>1;--i)
	{
		H.r[0]=H.r[1];//���Ѷ���¼[1]��δ��ȫ�����H.r[1..i]�е����һ����¼[i]����
		H.r[1]=H.r[i];
		H.r[i]=H.r[0];
		HeapAdjust(H,1,i-1);//����H.r[1..i-1]���³�Ϊ�󶥶� 
	 } 
}