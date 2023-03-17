#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;  /* Status �Ǻ������ͣ���ֵλ����ִ�н����״̬���룬��ERROR��OK��TRUE��FALSE�� */
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

typedef Node Node;// Node��ʾ�������һ�����
typedef Node *Linklist;//Linklist��ʾһ��������һ����㣨ͷ��㣩Ҳ���Ա�ʾ������


void InitList(Linklist &L){//��ʼ������
    L = new Node;
    L->next=NULL;//������һ���ձ�
}

void ListPrint(Linklist L)  /*�����ͷ�������� L*/
{ 
	Node *p;
	int GetLength(Linklist &L);
	p = L;
	cout<<"\nĿǰ��������Ϊ"<<GetLength(L)<<endl;
	int i;
	i = 0;
	cout<<"\n�����Ԫ������Ϊ��";
	while ( p->next!=Null )
	{ 
		++i;
		p = p->next;
		cout<<" ���"<<i<<"="<<p->data ;
	}
	cout << endl;
}

Status Empty(Linklist &L){// �жϵ������Ƿ�Ϊ��
    if(L->next==NULL)
        {return OK;}
    else
        {return ERROR;}
}

int GetLength(Linklist &L) {// ��ȡ��������
    Node *p = L->next;
    int length = 0;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

Node* GetElem(Linklist &L, int i) {// ��λ���ң����ҵ�i�����
    int k;//kΪ������
    Node *p;//ָ��pָ��ǰ�ڵ�
    p=L;//ָ��pָ���һ�����
    k=1;
    while(k<i)
    {
        p=p->next; //pָ����һ�����
        ++k;//��������1
    }
    if(k==i)
        return p;
    else 
    return NULL;
}

Node* GetNode(Linklist &L, ElemType e) {// ��ֵ���ң�����������Ϊe�Ľ��
    Node *p;
    p=L;
    while(p&&p->data!=e)
    {
        p=p->next;
    }
    if(!p)//���p������
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
	
Status ListInsert(Linklist L, int i, ElemType e) /* ���뺯��,���½��e���뵽��ͷ�������L��i��λ�ã�һ����������������ǰ */
{
    Node * p, *q;
    p = GetElem ( L, i-1 );
    if ( p == NULL) /*��λʧ��*/
        return ERROR;
    q = new Node; //C ����Ϊ q = (Node*) malloc (sizeof (Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
        return OK;
}



// ɾ��ָ�����
Status ListDelete(Linklist L ,int i,ElemType &e)  /* ɾ������,�Ӵ�ͷ��������L��ɾ����i�����:һ�������������� */
{ 
    Node * p, *q; 
    p = GetElem ( L, i-1 );
    if ( p == NULL || p -> next ==NULL) /*��㲻����*/ 
        return ERROR; 
    q = p -> next; 
    e = q->data; 
    p->next = q->next;
    delete(q); // �ͷŽ��ռ䣬C ����Ϊ free (q); 
        return OK;
}


Node* ListCreatTail()   /*β�巨������ͷ���ĵ�����������Ϊn������Ԫ�ش���Ļ��ȡ,����ͷ���λ��*/
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

Node* ListCreatHead()   /*ͷ�巨������ͷ���ĵ�����������Ϊn������Ԫ�ش���Ļ��ȡ,����ͷ���λ��*/
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

Node* ListReverse(Linklist &L) /* ˼·��������򡣴ӵ�һ����㿪ʼ�������ֱ�����һ�������ɡ�*/
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


Node * OrderInsert(Linklist &L,ElemType e) /* ��e�����������е������У�������˳���ϵ,�������ͷ�ڵ� */
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



int Pos_Mid (Linklist L,int &i)   /* δ֪����������м��㶨λ�������м���λ����i����,������������������1Ϊ������0Ϊż�� */
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
		cout<<endl<<"��ѡ�������"<<endl;
		cout<<"h ,  h----- ͷ�巨��������"<<endl;
		cout<<"t ,  t----- β�巨��������"<<endl;
		cout<<"i , i ----- ����"<<endl;
		cout<<"d , d ----- ɾ��"<<endl;
		cout<<"r,  r -----ת��"<<endl;
		cout<<"o,  o-----��������"<<endl;
		cout<<"p,  p-----�м��㶨λ"<<endl;
		cout<<"q , q ----- �˳�"<<endl;
		cout<<"c,  c---- ��յ�����"<<endl;
		cout<<"e,  e---- ��λ����"<<endl;
		cout<<"n,  n---- ��ֵ����"<<endl;
		cout<<"z,  z---- ���ٵ�����"<<endl;
		cout<<"q,  q---- �˳�"<<endl;
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
				cout<<"��������ĸ������L1������1�����L2������2��"<<endl;
				cin>>x;
				if(x==1)
				{
					ListClear(L1);
					cout<<"L1���Ѿ������"<<endl;
					ListPrint(L1);
				}
				if(x==2)
				{
					ListClear(L2);
					cout<<"L2���Ѿ������"<<endl;
					ListPrint(L2);
				}
				break;
			case 'z' :
				cout<<"���������ĸ�������L1������1������L2������2��"<<endl;
				cin>>x;
				if(x==1)
				{
					ListDestory(L1);
					cout<<"L1���Ѿ�������"<<endl;
				}
				if(x==2)
				{
					ListDestory(L2);
					cout<<"L2���Ѿ�������"<<endl;
				}
				break;
			case  'e':
				cout<<"����Ҫ���ҵ�Ԫ�ص�λ����"<<endl;
				cin>>x;
				cout<<"\n��Ҫ�����ĸ���������L1������1������L2������2��";
				cin>>k;
				if(k==1)
				{
					if(x>GetLength(L1))
					{
						cout<<"�����˱�Ԫ�ص�����"<<endl;
					}
					else{
					Node *p;
					p=new Node;
					p=GetElem(L1,x+1);
					cout<<"��Ҫ���ҵ�Ԫ����"<<p->data<<endl;}
				}
				if(k==2)
				{
					if(x>GetLength(L1))
					{
						cout<<"�����˱�Ԫ�ص�����"<<endl;
					}
					else{
					Node *p;
					p=new Node;
					p=GetElem(L2,x+1);
					cout<<"��Ҫ���ҵ�Ԫ����"<<p->data<<endl;}
				}
				break;
			case  'n':
				cout<<"����Ҫ���ҵ�Ԫ�ص�ֵ��"<<endl;
				cin>>x;
				cout<<"\n��Ҫ�����ĸ���������L1������1������L2������2��";
				cin>>k;
				if(k==1)
				{
					Node *p;
					p=new Node;
					p=GetNode(L1,x);
					cout<<"��Ҫ���ҵ�Ԫ��λ����"<<p<<endl;
				}
				if (k==2)
				{
					Node *p;
					p=new Node;
					p=GetNode(L2,x);
					cout<<"��Ҫ���ҵ�Ԫ��λ����"<<p<<endl;
				}
				break;
			case  'i':
				cout<<"\nplease input the data: ";
				cin >> x ;
				cout<<"\n��Ҫ�����ĸ���������L1������1������L2������2��";
				cin >> k ;
				cout<<"\nҪ��������L"<<k<<"�ĵڼ�λ��";
				cin >> i ;
				if(k==1){
					if(ListInsert(L1,i+1,x)) {	
						cout<<"\n�ѽ�Ԫ��"<<x<<"��������L1�ĵ�"<<i<<"λ\n";
						ListPrint(L1);
					}
					else cout<<"���ݲ���ʧ�ܣ�";
				}
				else if(k==2){
					if(ListInsert(L2,i+1,x)) {	
						cout<<"\n�ѽ�Ԫ��"<<x<<"��������L2�ĵ�"<<i<<"λ\n";
						ListPrint(L2);
					}
					else cout<<"���ݲ���ʧ�ܣ�";
				}
				else cout<<"���޴˱�";
				break ;
			case  'd' :
				cout<<"\n��Ҫɾ���ĸ������е�Ԫ�أ�����1��ʾL1������2��ʾL2��";
				cin >> k ;
				cout<<"\nɾ���ڼ���Ԫ�أ�"; 
				cin>>i;
				if(k==1){
					if(ListDelete(L1,i+1,x)){
					//	cout<<"\n�ѽ�����L1�ĵ�"<<i<<"λԪ��ɾ������ֵΪ"<<x<<endl;  
						ListPrint(L1);
					}						
					else cout<<"ɾ��ʧ�ܣ�";
				}
				else if(k==2){
					if(ListDelete(L2,i+1,x)){
				//	cout<<"\n�Ѿ�����L2�ĵ�"<<i<<"λԪ��ɾ������ֵΪ"<<x<<endl; 
						ListPrint(L2);
					}						
					else cout<<"ɾ��ʧ�ܣ�";
				}
				else cout<<"���޴˱�";
				break ;
			case 'r':
				cout<<"\n��Ҫ��ת�ĸ���������1��ʾL1������2��ʾL2��";
				cin >> k ;
				if(k==1){
					cout<<"\n����ת�ú�\n";
					L1 = ListReverse(L1);  
					ListPrint(L1);
				}
				else if(k==2){
					cout<<"\n����ת�ú�\n";
					L2 = ListReverse(L2);
					ListPrint(L2);
				}
				else cout<<"���޴˱�";
				break;
			case 'o':
				cout<<"\n��������Ҫ�������Ԫ��: ";
				cin>>x ;
				cout<<"\n��Ҫ����Ԫ�ز����ĸ���������1��ʾL1������2��ʾL2��";
				cin>>k;
				if(k==1){				
					cout<<"\n��������L1������Ԫ�غ�\n";
					L1 = OrderInsert(L1,x);
					ListPrint(L1);
				}
				else if(k==2){				
					cout<<"\n��������L2������Ԫ�غ�\n";
					L2 = OrderInsert(L2,x);
					ListPrint(L2);
				}
				else cout<<"���޴˱�";
				break;
			case 'p':
				cout<<"\n��Ҫ�����ĸ�������м�λ�ã�����1��ʾL1������2��ʾL2��";
				cin>>k;
				int i_mid;
				if(k==1){  
					if(Pos_Mid(L1,i_mid)==1) cout<<"\n����L1������������㣬�м���λ��Ϊ��"<<i_mid<<endl;
					else cout<<"\n����L1����ż������㣬�м���λ��Ϊ��"<<i_mid<<"��"<<i_mid+1<<endl;
				}else if(k==2){
					if(Pos_Mid(L2,i_mid)==1) cout<<"\n����L2������������㣬�м���λ��Ϊ��"<<i_mid<<endl;
					else cout<<"\n����L2����ż������㣬�м���λ��Ϊ��"<<i_mid<<"��"<<i_mid+1<<endl;
				}  
				else  cout<<"���޴˱�";
				break;
		}
	}while((cmd!='q'));  

	Node *p1=Null, *p2=Null; 
	while(L1){ //��ͷ��㿪ʼ�����ɾ������L1���
		p1 = L1->next;
		delete L1;
		L1 = p1;
	}
	while(L2){ //��ͷ��㿪ʼ�����ɾ������L2���
		p2 = L2->next;
		delete L2;
		L2 = p2;
	}
    system("pause");
	return 0;
}