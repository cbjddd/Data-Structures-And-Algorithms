#include<iostream>
#include<algorithm>


using namespace std;
typedef int ElemType;
typedef int Status;


# define MAXSIZE 20
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0

typedef struct{
    ElemType *e;
    int length;
    int data[MAXSIZE];
}Sqlist;

void InitList(Sqlist &L)
{
    L.length=0;
    cout<<"the sqlist is been created"<<endl;
}


Status ListCreat(Sqlist &L)   /*从屏幕逐位读入数据生成顺序表*/
{ 
	int  n , i;
	cout<<"Please enter the number of element in the Sqlist L\n" ;
	cin>>n ;
	if (n > MAXSIZE)
	{
		cout<<"\nthe number of element is too long.please less than"<<MAXSIZE;
		return ERROR;
	}
	else if(n<0)
	{
		cout<<"\nthis is illegel\n";
		return ERROR;
	}
	for(i=0 ; i < n ; i++)
	{ 
		cout<<"data["<<i<<"] =" ;
		cin>>L.data[i];
	}
	L.length=n;
	cout<<endl;
	return OK;
}

void ListPrint(Sqlist  &L)  /*输出顺序表 L*/
{ 
	int i ;
	if (L.length == 0) cout<<"this Sqlist is empty";
	else{
		for (i=0 ; i< L.length ; i++){
			cout<<"  data["<<i<<"]=";
			cout<< L.data[i];
		}
	}
	cout<<endl;
}

Status ListInsert(Sqlist &L,int i,ElemType e)
{
	int k;
	if ( L.length == MAXSIZE) /*顺序表已满*/
	{	cout<<"the sqlist is full"<<endl; 
        return ERROR;}
	if ( i < 1 || i > L.length + 1 ) /* i 不合法 */
	{   cout<<"the position is illegal"<<endl; 
        return ERROR;}
	if ( i <= L.length ) /* 插入位置不在表尾 */ 
    {
		for ( k = L.length - 1; k >=i-1; k-- ) 
            L.data [k+1] = L.data [k]; /* 从后向前逐位后移 */ }
    L.data [i-1] = e; /* 插入新元素 e */ 
    L.length++;
	cout<<"the element is inserted"<<endl; 
    return OK; 
}

Status ListDelete(Sqlist &L,int i)
{
    int k;
    if (L.length==0)
    {    cout<<"this is an empty list"<<endl;
        return ERROR;
	}
    if(i<1||i>L.length)
    {    cout<<"the position is illegal"<<endl;
        return ERROR;
	}
    if(1<i<L.length)
    {
        for(k=i-1;k<L.length;k++)
        L.data[k]=L.data[k+1];
    }
    L.length--;
    cout<<"the"<<i<<"th element has been deleted"<<endl;
    return OK;
}

int LocateElem(Sqlist L,ElemType e)
{
    int i;
    for(i=0;i<L.length-1;i++){
        if(e==L.data[i])
            return i+1;
		}	
		return ERROR;
}

Status ClearList(Sqlist &L)
{
    L.length=0;
    return OK;
}

Status ListEmpty(Sqlist L)
{
    if(L.length>0)
        return ERROR;
    else
        return OK;
}

int ListLength(Sqlist L)
{
    int k;
    if(L.length>0){
        k=L.length;
        return k;
    }  
    else
        return ERROR;
}

void ListDestory(Sqlist &L){
	ClearList(L);
	cout<<"the sqlist has been destoryed"<<endl;
}


Status ListReverse(Sqlist &L)
{
    int i,j,n,t;
    n=L.length;
    if(n==0||n==1)
    {
        return OK;
    }
    i=0,j=n-1;
    while(i<j){
        t=L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = t;
        i++;
        j--;
    }    
}

Status OrderInsert(Sqlist &L,ElemType e)
{
    int i;
    for(i=L.length-1;i>=0&&L.data[i]>e;i--){
        L.data[i+1]=L.data[i];
        L.data[i]=e;}
        L.length++; 
}

int Pos_Mid(Sqlist L,int &i)
{
    if((L.length)%2==1)
    {
        i=L.data[(L.length-1)/2];
        return 1;
    }
    else if((L.length)%2==0)
    {
        i=L.data[(L.length/2)-1];
        return 2;
    }    
}

int GetElem(Sqlist L, int i , ElemType &e) 
{
	if ( L.length == 0 || i <1 || i > L.length)
		return ERROR; 
	e = L.data [i-1]; 
	return OK; 
}


int main()
{
    	Sqlist L;
		InitList(L);
	    if (!ListCreat(L))
		    cout<<"\nnot successful!\n";
	    else
	    {
		    cout<<"\nsuccessful\n";
		    ListPrint(L);
            char cmd;
		    int i ,x;
		    do
		    {
			    cout<<"\ni , i ----- Insert\n" ;
			    cout<<"d , d ----- Delete\n" ;
				cout<<"z , z ----- Destory\n" ;
			    cout<<"l , l ----- Research\n";
			    cout<<"c,  c ----- Clear\n";
			    cout<<"e,  e----- Empty?\n";
				cout<<"g,  g----- getElem\n";
			    cout<<"v,  v----- Length\n";
			    cout<<"r,  r -----Reverse"<<endl;  
			    cout<<"o,  o-----InsertOrder"<<endl;   
			    cout<<"p,  p-----LocateOfMedian"<<endl;   
			    cout<<"q , q ----- Quit\n" ;
                do
			    {
				    cmd=getchar() ;
			    }while((cmd!='i')&&(cmd!='d')&&(cmd!='l')&&(cmd!='c')&&(cmd!='e')&&(cmd!='g')&&(cmd!='v')&&(cmd!='r')&&(cmd!='o')&&(cmd!='p')&&(cmd!='q')&&(cmd!='z'));
			    switch(cmd)
			    { 
				    case  'i':
					    cout<<"\nplease enter the element you want to insert";
					    cin>>x ;
					    printf("\nwhat position do you want to insert?");
					    cin>>i ;
					    ListInsert(L,i,x) ;
					    ListPrint(L);
					    break ;
				    case  'd' :
					    cout<<"\nwhich element do you want to delete";
                			cin>>i;
					    ListDelete(L,i);
					    ListPrint(L);
					    break ;
					case  'z':
						ListDestory(L);
						break;
				    case  'l' :
					    ElemType elem;
					    int pos;
					    cout<<"\nwhich element do you want to resreach";
                			    cin>> elem;
					    pos = LocateElem(L, elem);
					    if (pos)
						    cout<<"\n"<<elem<<"this first one is the"<<pos<<endl;
					    else
						    cout<<"\n"<<"there is no elements"<<elem<<endl;
					    break ;
				    case 'c':
					    ClearList(L);
					    cout<<"the sqlist is ";
					    ListPrint(L);
					    break;
				    case 'e':
					    if(ListEmpty(L))
						    cout<<"\nthe sqlist is empty\n";
					    else
						    cout<<"\nthe sqlist is not empty\n";
					    break;
					case 'g':
						int j;
						ElemType elem1;
					    cout<<"which element do you want to get.please enter the position"<<endl;
							cin>>j;
						if(j<=L.length)
						{
						GetElem(L,j,elem1);
						cout<<"the element is"<<elem1<<endl;}
						else
						{
							cout<<"the position is illegal"<<endl;
						}
						break;
				    case 'v':
					    cout<<"\nthe sqlist has "<<ListLength(L)<<" elements\n";
					    break;
				    case 'r':  /* 作业2新增*/
					    cout<<"\nafter reserving\n";
					    ListReverse(L);
					    ListPrint(L);
					    break;
				    case 'o':   /* 作业2新增*/
					    cout<<"\nthe element you want to insert is\n";
					    cin>>x ;
					    cout<<"\nafter inserting\n";
					    OrderInsert(L,x);
					    ListPrint(L);
				    case 'p':  /* 作业2新增*/
					    int i_mid;
					    if(Pos_Mid(L,i_mid)==1) cout<<"\nL has odd elements and the middle one is"<<i_mid<<endl;
					    else cout<<"\nL has even elements and the middle one is"<<i_mid<<"and"<<i_mid+1<<endl;
					    break;
			    }
		    }while((cmd!='q'));
	    }
    system("pause");
	return 0;
}