#include<iostream>
using namespace std;



struct cQueue/*队列结构体的定义*/
{
	int *a=NULL;
	int maxSize;
	int front,rear;
	 
 };

void init(cQueue* q, int sz)/*初始化一个队列*/
{
	q->a=new int[sz];//创建一个新的整型数组
	q->maxSize=sz;//队列的最大长度为队列的长度
	q->front=0;
	q->rear=0;
}


void flush(cQueue* q)/*删除队列*/
{
	delete q->a;	
}
bool empty(cQueue* q)/*判断队列是否为空*/
{
	return q->front==q->rear;
}
bool full(cQueue* q)/*判断队列是否为满*/
{
	return q->front==(q->rear+1)%q->maxSize;
}
void clear(cQueue* q)/*将队列清空*/
{
	q->front=0;
	q->rear=q->front;
}
int size(cQueue* q)/*计算队列的长度*/
{
	return (q->rear-q->front+q->maxSize)%q->maxSize;
}
bool push(cQueue* q, int x)/*将数据x入列*/
{
	if(full(q))return false;
	q->a[q->rear]=x;
	q->rear=(q->rear+1)%q->maxSize;
	return true;
}
void pop(cQueue* q)/*将数据出列*/
{
	q->front=(q->front+1)%q->maxSize;
}
int front(cQueue* q)/*得到开头的数据*/
{
	return q->a[q->front];	
}
int main()
{
	cQueue q;
	cQueue ou;
	
	cQueue *q1=&q;
	cQueue *out=&ou;
	cout<<"请分别输入总人数，开始的号数和每几个人淘汰一次"<<endl; 
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
    /*这段代码实现了根据约瑟夫问题的规则，将队列中的元素出队并重新入队，直到队列中只剩下最后一个元素。

具体的实现过程如下：

1.定义变量 i 和 w1，其中 i 表示当前的出队次数，w1 表示每轮出队的人数。

2.当 w1 不为 1 时，将队首元素出队并重新入队 w1 - 1 次，实现每轮出队的人数减少一个的功能。

3.当队列中元素个数大于 1 时，进行出队并重新入队操作，具体步骤如下：

a. 对于第 i + 1 个人（i 从 0 开始计数），如果 i + 1 不是每 w 个人出队的位置，则将队首元素出队并重新入队。

b. 对于第 i + 1 个人，如果 i + 1 是每 w 个人出队的位置，则将队首元素出队并加入另一个队列 out 中，实现每 w 个人出队的功能。

4.循环结束后，输出出队的顺序和最后剩下的人的编号。

总体来说，这段代码实现了约瑟夫问题的基本思路，即按照一定的规则不断出队和重新入队，直到最后只剩下一个人。其中利用队列的数据结构特点，方便地实现了每轮出队和每 w 个人出队的功能。*/
	int n0=size(out);
	cout<<"出列顺序为："; 
	for(int j=0;j<n0;j++)
	{
		cout<<front(out)<<' ';
		pop(out);
	}
	cout<<endl;
	cout<<"最后剩下的"<<front(q1)<<"号\n";
	flush(q1);
	flush(out);
    system("pause");
    return 0;
}
