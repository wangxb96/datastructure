typedef struct QNode{
	QElemType data;
	QNode *next;
}*QueuePtr;
struct LinkQueue{
	QueuePtr front,rear;//��ͷ����βָ�� 
};


