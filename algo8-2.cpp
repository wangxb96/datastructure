#include"c1.h"
#include"func8-2.cpp"
#include"c8-1.h"
#include"c8-2.h"
#include"bo8-1.cpp"
int main()
{
	SSTable st;
	int i;
	KeyType s;
	Creat_OrdFromFile(st,"f8-2.txt");
	printf("�����Ϊ: ");
	Traverse(st,Visit);
	printf("\n");
	printf("��������������ݵĹؼ���");
	InputKey(s);
	i=Search_Bin(st,s);
	//������ľ�̬���ұ�st���۰���Һ��йؼ���sx��������
    if(i)
	  printf("%d�ǵ�%d�����ݵĹؼ���\n",st.elem[i].key,i);
	else
	  printf("δ�ҵ�\n");
	Destroy(st); 
}