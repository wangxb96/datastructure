#define MAX_QSIZE 5//�����г���+1
struct SqQueue
{
	QElemType *base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һλ�� 
 };
 