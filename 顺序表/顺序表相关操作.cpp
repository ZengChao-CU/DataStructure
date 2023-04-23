#include <stdio.h>
#include <iostream>
#define MaxSize 50		//定义顺序表的最大长度 

#define InitSize 100 

using namespace std;
typedef  int ElemType;

//一维数组可以是静态分配
//		(数组的大小和空间都已经固定，一旦空间占满，再加进新数据就会溢出)

//也可以是动态分配的
//		(存储数组的空间是在程序执行过程中通过动态存储分配语句分配的，一旦数据
//		空间占满，就另外开辟一块更大的存储空间，用以替换原来的存储空间)
typedef struct{ 		//静态方式 
	ElemType data[MaxSize];//顺序表的元素 
	int length;		//顺序表当前长度 
}SqList;

//typedef struct{       //动态方式 
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

//插入操作 
bool ListInsert(SqList &L,int j,ElemType e){
	if(L.length >= MaxSize) return false;
	if(j<1 || j>L.length+1) return false;
	for(int i=L.length;i>=j;i--)
		L.data[i]=L.data[i-1];
	L.data[j-1]=e;
	L.length++;
	return true;
}

//删除操作 
bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1 || i>L.length) return false;
	e=L.data[i-1];
	for(int j=i-1;j<L.length;j++)
		L.data[j]=L.data[j+1];
	L.length--;
	return true;
}

//按值查找 
int LocateElem(SqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
} 

int main()
{
	int n;			//需要输入的元素个数 
	int location;
	ElemType e;
	SqList SL1;
	SL1.length=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		SL1.data[i]=i+1;
		SL1.length++; 
	}
	cout<<"SL1中插入前的元素:";
	//printf("SL1中插入前的元素:");
	DisplaySqList(SL1);
	cout<<"插入前SL1的长度:"<<SL1.length<<endl;
	//printf("插入前SL1的长度:%d/n",SL1.length);
	cout<<"输入要插入的元素的位置:" ;
	//printf("输入要插入的元素的位置:");
	//scanf("%d",&location);
	cin>>location;
	cout<<"输入要插入的元素:" ;
	//printf("输入要插入的元素:");
	//scanf("%d",&e);
	cin>>e;
	bool res=ListInsert(SL1,location,e);
	if(res){
		cout<<"SL1中插入后的元素";
		//printf("SL1中插入后的元素:");
		DisplaySqList(SL1);
		cout<<"插入后SL1的长度:"<<SL1.length<<endl;
		//printf("插入后SL1的长度:%d/n",SL1.length);
	}else cout<<"插入失败！"<<endl; 
	
	cout<<"输入要删除的元素的位置：";
	cin>>location;
	res=ListDelete(SL1,location,e);
	if(res){
		cout<<"SL1中删除的元素:"<<e<<endl;
		cout<<"SL1中删除元素\""<<e<<"\"之后剩余的元素:"; 
		DisplaySqList(SL1);	
		cout<<"SL1中删除元素\""<<e<<"\"之后的长度:"<<SL1.length<<endl; 
	}else cout<<"删除失败！"<<endl; 
	
	cout<<"输入要查找元素的值:";
	cin>>e;
	location=LocateElem(SL1,e);
	if(location==0)cout<<"查找的元素不在SL1中！"<<endl;
	else cout<<"元素"<<e<<"在SL1顺序表的第"<<location<<"个位置上"<<endl; 
	
	return 0;
 } 
