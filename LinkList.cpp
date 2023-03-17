#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;  /* Status 是函数类型，其值位函数执行结果的状态代码，如ERROR、OK、TRUE、FALSE等 */
# define MAXSIZE 20
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
# define Null 0

struct Node{
    int data;
    Node *next;
};

typedef Node Node;// Node表示单链表的一个结点
typedef Node *Linklist;//Linklist表示一个单链表，一个结点（头结点）也可以表示单链表


void InitList(Linklist &L){//初始化链表
    L = new Node;
    L->next=NULL;//生成了一个空表
}

void ListPrint(Linklist L)  /*输出带头结点的链表 L*/
{ 
	Node *p;
	int GetLength(Linklist &L);
	p = L;
	cout<<"\n目前该链表长度为"<<GetLength(L)<<endl;
	int i;
	i = 0;
	cout<<"\n链表的元素依次为：";
	while ( p->next!=Null )
	{ 
		++i;
		p = p->next;
		cout<<" 结点"<<i<<"="<<p->data ;
	}
	cout << endl;
}

Status Empty(Linklist &L){// 判断单链表是否为空
    if(L->next==NULL)
        {return OK;}
    else
        {return ERROR;}
}

int GetLength(Linklist &L) {// 获取单链表长度
    Node *p = L->next;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

Node* GetElem(Linklist &L, int i) {// 按位查找：查找第i个结点
    int k;//k为计数器
    Node *p;//指针p指向当前节点
    p=L;//指针p指向第一个结点
    k=1;
    while(k<i)
    {
        p=p->next; //p指向下一个结点
        ++k;//计数器加1
    }
    if(k==i)
        return p;
    else 
    return NULL;
}

Node* GetNode(Linklist &L, ElemType e) {// 按值查找：查找数据域为e的结点
    Node *p;
    p=L;
    while(p&&p->data!=e)
    {
        p=p->next;
    }
    if(!p)//结点p不存在
        return NULL;
    else   
        return p;
}

void ListDestory(Linklist &L)
{
	Node *p=L;
	while (p)
	{
		L=L->next;
		delete(p);
		p=L;
	}
}

void ListClear(Linklist &L)
{
	Node *p;
	while (L->next)
	{
		p=L->next;
		L->next=p->next;
		delete(p);
	}
}
	
Status ListInsert(Linklist L, int i, ElemType e) /* 插入函数,将新结点e插入到带头结点链表L第i个位置：一定，二建，三后，四前 */
{
    Node * p, *q;
    p = GetElem ( L, i-1 );
    if ( p == NULL) /*定位失败*/
        return ERROR;
    q = new Node; //C 语言为 q = (Node*) malloc (sizeof (Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
        return OK;
}



// 删除指定结点
Status ListDelete(Linklist L ,int i,ElemType &e)  /* 删除函数,从带头结点的链表L中删除第i个结点:一定，二连，三放 */
{ 
    Node * p, *q; 
    p = GetElem ( L, i-1 );
    if ( p == NULL || p -> next ==NULL) /*结点不存在*/ 
        return ERROR; 
    q = p -> next; 
    e = q->data; 
    p->next = q->next;
    delete(q); // 释放结点空间，C 语言为 free (q); 
        return OK;
}


Node* ListCreatTail()   /*尾插法建立带头结点的单链表，链表长度为n，链表元素从屏幕读取,返回头结点位置*/
{
	int n;
	Linklist L;
	cout<<"how many number of elements do you want?"<<endl;
	cin>>n;
	Node *p,*r;
	L=new Node;
	r=L;
	for(int i=0;i<n;i++)
	{
		p=new Node;
		int k;
		cin>>k;
		p->data=k;
		r->next=p;
		r=p;
	}
	r->next=NULL;
	return L;
}

Node* ListCreatHead()   /*头插法建立带头结点的单链表，链表长度为n，链表元素从屏幕读取,返回头结点位置*/
{
	int n;
	Linklist L;
	cout<<"how many number of elements do you want?"<<endl;
	cin>>n; 
	L=new Node;
	L->next=NULL;
	Node *p;
	for(int i=0;i<n;i++)
	{
		p=new Node;
		int k;
		cin>>k;
		p->data=k;
		p->next=L->next;
		L->next=p;
	}
	return L;
}

Node* ListReverse(Linklist &L) /* 思路：逐个反向。从第一个结点开始逐个反向，直到最后一个结点完成。*/
{
    Node *p;
    p = L->next;
    L->next = NULL;
    while(p != NULL){
        Node *tmp;
        tmp = p->next;
        p->next = L->next;
        L->next = p;
        p = tmp;
    }
	return L;
}


Node * OrderInsert(Linklist &L,ElemType e) /* 将e插入升序排列的链表中，并保持顺序关系,链表带有头节点 */
{
	Node *prev=L;
	Node *cur=L->next;
	while(cur->next!=NULL&&cur->data<e)
	{
		prev=cur;
		cur=cur->next;
	}
	Node *newNode = new Node;
    prev->next = newNode;
    newNode->next = cur;
	newNode->data = e;
	return L;
}



int Pos_Mid (Linklist L,int &i)   /* 未知长度链表的中间结点定位，计算中间结点位序用i返回,并返回链表结点数量，1为奇数，0为偶数 */
{
    int l;
    l=GetLength(L);
    if(l%2==0)
    {
        cout<<"the linklist has even elements"<<endl;
        i=l/2;
        return 0;
    }
    else if(l%2==1)
    {
        i=(l+1)/2;
        cout<<"the linklist has odd elements"<<endl;
        return 1;
    }
}

int main()  
{ 
	Linklist L1=Null, L2=Null;
	L1 = ListCreatTail();  
	L2 = ListCreatHead(); 
	ListPrint(L1);
	ListPrint(L2);
	char cmd;
	int i=0,k=0;
	ElemType x=0;

	do
	{
		cout<<endl<<"请选择操作："<<endl;
		cout<<"h ,  h----- 头插法创建链表"<<endl;
		cout<<"t ,  t----- 尾插法创建链表"<<endl;
		cout<<"i , i ----- 插入"<<endl;
		cout<<"d , d ----- 删除"<<endl;
		cout<<"r,  r -----转置"<<endl;
		cout<<"o,  o-----有序表插入"<<endl;
		cout<<"p,  p-----中间结点定位"<<endl;
		cout<<"q , q ----- 退出"<<endl;
		cout<<"c,  c---- 清空单链表"<<endl;
		cout<<"e,  e---- 按位查找"<<endl;
		cout<<"n,  n---- 按值查找"<<endl;
		cout<<"z,  z---- 销毁单链表"<<endl;
		cout<<"q,  q---- 退出"<<endl;
		cout<<endl;

		do
		{
			cmd=getchar() ;
		}while((cmd!='i')&&(cmd!='d')&&(cmd!='q')&&(cmd!='r')&&(cmd!='o')&&(cmd!='p')&&(cmd!='h')&&(cmd!='t')&&(cmd!='c')&&(cmd!='z')&&(cmd!='e')&&(cmd!='n'));
		switch(cmd)
		{ 
			case  'h':
				L1 = ListCreatHead();
				ListPrint(L1);
				break ;
			case  't' :  
				L2 = ListCreatTail();
				ListPrint(L2);
				break ;
			case 'c'  :
				cout<<"你想清空哪个表：清空L1请输入1，清空L2请输入2："<<endl;
				cin>>x;
				if(x==1)
				{
					ListClear(L1);
					cout<<"L1表已经被清空"<<endl;
					ListPrint(L1);
				}
				if(x==2)
				{
					ListClear(L2);
					cout<<"L2表已经被清空"<<endl;
					ListPrint(L2);
				}
				break;
			case 'z' :
				cout<<"你想销毁哪个表：销毁L1请输入1，销毁L2请输入2："<<endl;
				cin>>x;
				if(x==1)
				{
					ListDestory(L1);
					cout<<"L1表已经被销毁"<<endl;
				}
				if(x==2)
				{
					ListDestory(L2);
					cout<<"L2表已经被销毁"<<endl;
				}
				break;
			case  'e':
				cout<<"你想要查找的元素的位序是"<<endl;
				cin>>x;
				cout<<"\n需要插入哪个链表：插入L1请输入1，插入L2请输入2：";
				cin>>k;
				if(k==1)
				{
					if(x>GetLength(L1))
					{
						cout<<"超过了表元素的数量"<<endl;
					}
					else{
					Node *p;
					p=new Node;
					p=GetElem(L1,x+1);
					cout<<"你要查找的元素是"<<p->data<<endl;}
				}
				if(k==2)
				{
					if(x>GetLength(L1))
					{
						cout<<"超过了表元素的数量"<<endl;
					}
					else{
					Node *p;
					p=new Node;
					p=GetElem(L2,x+1);
					cout<<"你要查找的元素是"<<p->data<<endl;}
				}
				break;
			case  'n':
				cout<<"你想要查找的元素的值是"<<endl;
				cin>>x;
				cout<<"\n需要插入哪个链表：插入L1请输入1，插入L2请输入2：";
				cin>>k;
				if(k==1)
				{
					Node *p;
					p=new Node;
					p=GetNode(L1,x);
					cout<<"你要查找的元素位置是"<<p<<endl;
				}
				if (k==2)
				{
					Node *p;
					p=new Node;
					p=GetNode(L2,x);
					cout<<"你要查找的元素位置是"<<p<<endl;
				}
				break;
			case  'i':
				cout<<"\nplease input the data: ";
				cin >> x ;
				cout<<"\n需要插入哪个链表：插入L1请输入1，插入L2请输入2：";
				cin >> k ;
				cout<<"\n要插入链表L"<<k<<"的第几位：";
				cin >> i ;
				if(k==1){
					if(ListInsert(L1,i+1,x)) {	
						cout<<"\n已将元素"<<x<<"插入链表L1的第"<<i<<"位\n";
						ListPrint(L1);
					}
					else cout<<"数据插入失败！";
				}
				else if(k==2){
					if(ListInsert(L2,i+1,x)) {	
						cout<<"\n已将元素"<<x<<"插入链表L2的第"<<i<<"位\n";
						ListPrint(L2);
					}
					else cout<<"数据插入失败！";
				}
				else cout<<"查无此表！";
				break ;
			case  'd' :
				cout<<"\n需要删除哪个链表中的元素：输入1表示L1，输入2表示L2：";
				cin >> k ;
				cout<<"\n删除第几个元素："; 
				cin>>i;
				if(k==1){
					if(ListDelete(L1,i+1,x)){
					//	cout<<"\n已将链表L1的第"<<i<<"位元素删除，其值为"<<x<<endl;  
						ListPrint(L1);
					}						
					else cout<<"删除失败！";
				}
				else if(k==2){
					if(ListDelete(L2,i+1,x)){
				//	cout<<"\n已经链表L2的第"<<i<<"位元素删除，其值为"<<x<<endl; 
						ListPrint(L2);
					}						
					else cout<<"删除失败！";
				}
				else cout<<"查无此表！";
				break ;
			case 'r':
				cout<<"\n需要翻转哪个链表：输入1表示L1，输入2表示L2：";
				cin >> k ;
				if(k==1){
					cout<<"\n链表转置后：\n";
					L1 = ListReverse(L1);  
					ListPrint(L1);
				}
				else if(k==2){
					cout<<"\n链表转置后：\n";
					L2 = ListReverse(L2);
					ListPrint(L2);
				}
				else cout<<"查无此表！";
				break;
			case 'o':
				cout<<"\n请输入需要插入的新元素: ";
				cin>>x ;
				cout<<"\n需要将该元素插入哪个链表：输入1表示L1，输入2表示L2：";
				cin>>k;
				if(k==1){				
					cout<<"\n有序链表L1插入新元素后\n";
					L1 = OrderInsert(L1,x);
					ListPrint(L1);
				}
				else if(k==2){				
					cout<<"\n有序链表L2插入新元素后\n";
					L2 = OrderInsert(L2,x);
					ListPrint(L2);
				}
				else cout<<"查无此表！";
				break;
			case 'p':
				cout<<"\n需要查找哪个链表的中间位置：输入1表示L1，输入2表示L2：";
				cin>>k;
				int i_mid;
				if(k==1){  
					if(Pos_Mid(L1,i_mid)==1) cout<<"\n链表L1含有奇数个结点，中间结点位置为："<<i_mid<<endl;
					else cout<<"\n链表L1含有偶数个结点，中间结点位置为："<<i_mid<<"和"<<i_mid+1<<endl;
				}else if(k==2){
					if(Pos_Mid(L2,i_mid)==1) cout<<"\n链表L2含有奇数个结点，中间结点位置为："<<i_mid<<endl;
					else cout<<"\n链表L2含有偶数个结点，中间结点位置为："<<i_mid<<"和"<<i_mid+1<<endl;
				}  
				else  cout<<"查无此表！";
				break;
		}
	}while((cmd!='q'));  

	Node *p1=Null, *p2=Null; 
	while(L1){ //从头结点开始，逐个删除链表L1结点
		p1 = L1->next;
		delete L1;
		L1 = p1;
	}
	while(L2){ //从头结点开始，逐个删除链表L2结点
		p2 = L2->next;
		delete L2;
		L2 = p2;
	}
    system("pause");
	return 0;
}