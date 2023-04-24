#include<stdio.h>
#include<stdlib.h>
//���������ز���

typedef int ElemType;

typedef struct LNode{
	ElemType date;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ������������ 
bool InitLinkList(LinkList &L){//����ͷ���ĵ�����ĳ�ʼ�� 
	L=NULL;
	return true;
} 

bool InitLinkListWithHeader(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL) return false;//�ڴ治�㣬����ʧ�� 
	L->next=NULL;//ͷ���֮���޽ڵ� 
	return true; 
} 

// //��ӡ�������е�����
void DisPlay(LinkList L){
	LNode *s;
	s=L->next;
	while(s){
		printf("%d ",s->date);
		s=s->next;	
	}
	putchar(10);
}

 
//ǰ�巨��������
LinkList List_HeadInsert(LinkList &L){
	LNode *s;
	int x;
	bool create=InitLinkListWithHeader(L);//��������ʼ��ͷ��� 
	if(!create){
		printf("����ʧ�ܣ��ڴ治�㣡");
		return NULL; 
	}
//	L=(LinkList)malloc(sizeof(LNode));
//	L->next=NULL;
	L->date=0;		//�˴� ͷ����������������ŵ�����ǰ���� 
	printf("��%d������:",(L->date)+1); 
	scanf("%d",&x);
	while(x!=-1){
		s=(LNode*)malloc(sizeof(LNode));
		s->date=x;
		s->next=L->next;
		L->next=s;
		L->date++;
		printf("��%d������:",(L->date)+1); 
		scanf("%d",&x);
		 
	}
	return L;
	
} 

int main(){
	LinkList L;
	LNode *s;
	printf("ǰ�巨����������(����Ԫ����-1����)\n"); 
	s=List_HeadInsert(L);
	DisPlay(s);  //��ӡ������ 
	
	return 0;
} 
