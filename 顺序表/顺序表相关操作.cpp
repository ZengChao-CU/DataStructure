#include <stdio.h>
#include <iostream>
#define MaxSize 50		//����˳������󳤶� 

#define InitSize 100 

using namespace std;
typedef  int ElemType;

//һά��������Ǿ�̬����
//		(����Ĵ�С�Ϳռ䶼�Ѿ��̶���һ���ռ�ռ�����ټӽ������ݾͻ����)

//Ҳ�����Ƕ�̬�����
//		(�洢����Ŀռ����ڳ���ִ�й�����ͨ����̬�洢����������ģ�һ������
//		�ռ�ռ���������⿪��һ�����Ĵ洢�ռ䣬�����滻ԭ���Ĵ洢�ռ�)
typedef struct{ 		//��̬��ʽ 
	ElemType data[MaxSize];//˳����Ԫ�� 
	int length;		//˳���ǰ���� 
}SqList;

//typedef struct{       //��̬��ʽ 
//	ElemType *data;
//	int length;
//	int maxsize; 
//	
//}DSqList; 


void DisplaySqList(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d ",L.data[i]);
	}
	putchar(10);
	
}

//������� 
bool ListInsert(SqList &L,int j,ElemType e){
	if(L.length >= MaxSize) return false;
	if(j<1 || j>L.length+1) return false;
	for(int i=L.length;i>=j;i--)
		L.data[i]=L.data[i-1];
	L.data[j-1]=e;
	L.length++;
	return true;
}

//ɾ������ 
bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1 || i>L.length) return false;
	e=L.data[i-1];
	for(int j=i-1;j<L.length;j++)
		L.data[j]=L.data[j+1];
	L.length--;
	return true;
}

//��ֵ���� 
int LocateElem(SqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
} 

int main()
{
	int n;			//��Ҫ�����Ԫ�ظ��� 
	int location;
	ElemType e;
	SqList SL1;
	SL1.length=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		SL1.data[i]=i+1;
		SL1.length++; 
	}
	cout<<"SL1�в���ǰ��Ԫ��:";
	//printf("SL1�в���ǰ��Ԫ��:");
	DisplaySqList(SL1);
	cout<<"����ǰSL1�ĳ���:"<<SL1.length<<endl;
	//printf("����ǰSL1�ĳ���:%d/n",SL1.length);
	cout<<"����Ҫ�����Ԫ�ص�λ��:" ;
	//printf("����Ҫ�����Ԫ�ص�λ��:");
	//scanf("%d",&location);
	cin>>location;
	cout<<"����Ҫ�����Ԫ��:" ;
	//printf("����Ҫ�����Ԫ��:");
	//scanf("%d",&e);
	cin>>e;
	bool res=ListInsert(SL1,location,e);
	if(res){
		cout<<"SL1�в�����Ԫ��";
		//printf("SL1�в�����Ԫ��:");
		DisplaySqList(SL1);
		cout<<"�����SL1�ĳ���:"<<SL1.length<<endl;
		//printf("�����SL1�ĳ���:%d/n",SL1.length);
	}else cout<<"����ʧ�ܣ�"<<endl; 
	
	cout<<"����Ҫɾ����Ԫ�ص�λ�ã�";
	cin>>location;
	res=ListDelete(SL1,location,e);
	if(res){
		cout<<"SL1��ɾ����Ԫ��:"<<e<<endl;
		cout<<"SL1��ɾ��Ԫ��\""<<e<<"\"֮��ʣ���Ԫ��:"; 
		DisplaySqList(SL1);	
		cout<<"SL1��ɾ��Ԫ��\""<<e<<"\"֮��ĳ���:"<<SL1.length<<endl; 
	}else cout<<"ɾ��ʧ�ܣ�"<<endl; 
	
	cout<<"����Ҫ����Ԫ�ص�ֵ:";
	cin>>e;
	location=LocateElem(SL1,e);
	if(location==0)cout<<"���ҵ�Ԫ�ز���SL1�У�"<<endl;
	else cout<<"Ԫ��"<<e<<"��SL1˳���ĵ�"<<location<<"��λ����"<<endl; 
	
	return 0;
 } 
