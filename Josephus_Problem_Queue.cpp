#include<iostream>
using namespace std;



struct cQueue/*���нṹ��Ķ���*/
{
	int *a=NULL;
	int maxSize;
	int front,rear;
	 
 };

void init(cQueue* q, int sz)/*��ʼ��һ������*/
{
	q->a=new int[sz];//����һ���µ���������
	q->maxSize=sz;//���е���󳤶�Ϊ���еĳ���
	q->front=0;
	q->rear=0;
}


void flush(cQueue* q)/*ɾ������*/
{
	delete q->a;	
}
bool empty(cQueue* q)/*�ж϶����Ƿ�Ϊ��*/
{
	return q->front==q->rear;
}
bool full(cQueue* q)/*�ж϶����Ƿ�Ϊ��*/
{
	return q->front==(q->rear+1)%q->maxSize;
}
void clear(cQueue* q)/*���������*/
{
	q->front=0;
	q->rear=q->front;
}
int size(cQueue* q)/*������еĳ���*/
{
	return (q->rear-q->front+q->maxSize)%q->maxSize;
}
bool push(cQueue* q, int x)/*������x����*/
{
	if(full(q))return false;
	q->a[q->rear]=x;
	q->rear=(q->rear+1)%q->maxSize;
	return true;
}
void pop(cQueue* q)/*�����ݳ���*/
{
	q->front=(q->front+1)%q->maxSize;
}
int front(cQueue* q)/*�õ���ͷ������*/
{
	return q->a[q->front];	
}
int main()
{
	cQueue q;
	cQueue ou;
	
	cQueue *q1=&q;
	cQueue *out=&ou;
	cout<<"��ֱ���������������ʼ�ĺ�����ÿ��������̭һ��"<<endl; 
	int n,m,w;//n:num of people;m:start people;w:outpost num;
	cin>>n>>m>>w;
	init(q1,n+5);
	init(out,n+5);
	for(int i=1;i<=n;i++)
	{
		push(q1,i);
	}
	int i=0;
	int w1=w;
	while(w1!=1){
		push(q1,front(q1));
		pop(q1);
		w1--;
	}
 
	while(size(q1)!=1)
	{
		i++;
		if(i%w!=0){
			push(q1,front(q1));
			pop(q1);
		}
		else{
			push(out,front(q1));
			pop(q1);
		}
		
	}
    /*��δ���ʵ���˸���Լɪ������Ĺ��򣬽������е�Ԫ�س��Ӳ�������ӣ�ֱ��������ֻʣ�����һ��Ԫ�ء�

�����ʵ�ֹ������£�

1.������� i �� w1������ i ��ʾ��ǰ�ĳ��Ӵ�����w1 ��ʾÿ�ֳ��ӵ�������

2.�� w1 ��Ϊ 1 ʱ��������Ԫ�س��Ӳ�������� w1 - 1 �Σ�ʵ��ÿ�ֳ��ӵ���������һ���Ĺ��ܡ�

3.��������Ԫ�ظ������� 1 ʱ�����г��Ӳ�������Ӳ��������岽�����£�

a. ���ڵ� i + 1 ���ˣ�i �� 0 ��ʼ����������� i + 1 ����ÿ w ���˳��ӵ�λ�ã��򽫶���Ԫ�س��Ӳ�������ӡ�

b. ���ڵ� i + 1 ���ˣ���� i + 1 ��ÿ w ���˳��ӵ�λ�ã��򽫶���Ԫ�س��Ӳ�������һ������ out �У�ʵ��ÿ w ���˳��ӵĹ��ܡ�

4.ѭ��������������ӵ�˳������ʣ�µ��˵ı�š�

������˵����δ���ʵ����Լɪ������Ļ���˼·��������һ���Ĺ��򲻶ϳ��Ӻ�������ӣ�ֱ�����ֻʣ��һ���ˡ��������ö��е����ݽṹ�ص㣬�����ʵ����ÿ�ֳ��Ӻ�ÿ w ���˳��ӵĹ��ܡ�*/
	int n0=size(out);
	cout<<"����˳��Ϊ��"; 
	for(int j=0;j<n0;j++)
	{
		cout<<front(out)<<' ';
		pop(out);
	}
	cout<<endl;
	cout<<"���ʣ�µ�"<<front(q1)<<"��\n";
	flush(q1);
	flush(out);
    system("pause");
    return 0;
}
