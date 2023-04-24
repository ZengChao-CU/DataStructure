#include<stdio.h>
#include<stdlib.h>
//单链表的相关操作

typedef int ElemType;

typedef struct LNode{
	ElemType date;
	struct LNode *next;
}LNode,*LinkList;

//初始化，防脏数据 
bool InitLinkList(LinkList &L){//不带头结点的单链表的初始化 
	L=NULL;
	return true;
} 

bool InitLinkListWithHeader(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL) return false;//内存不足，分配失败 
	L->next=NULL;//头结点之后无节点 
	return true; 
} 

// //打印单链表中的数据
void DisPlay(LinkList L){
	LNode *s;
	s=L->next;
	while(s){
		printf("%d ",s->date);
		s=s->next;	
	}
	putchar(10);
}

 
//前插法创建链表
LinkList List_HeadInsert(LinkList &L){
	LNode *s;
	int x;
	bool create=InitLinkListWithHeader(L);//创建并初始化头结点 
	if(!create){
		printf("创建失败，内存不足！");
		return NULL; 
	}
//	L=(LinkList)malloc(sizeof(LNode));
//	L->next=NULL;
	L->date=0;		//此处 头结点的数据域用来存放单链表当前长度 
	printf("第%d个数据:",(L->date)+1); 
	scanf("%d",&x);
	while(x!=-1){
		s=(LNode*)malloc(sizeof(LNode));
		s->date=x;
		s->next=L->next;
		L->next=s;
		L->date++;
		printf("第%d个数据:",(L->date)+1); 
		scanf("%d",&x);
		 
	}
	return L;
	
} 

int main(){
	LinkList L;
	LNode *s;
	printf("前插法创建单链表(输入元素以-1结束)\n"); 
	s=List_HeadInsert(L);
	DisPlay(s);  //打印单链表 
	
	return 0;
} 
