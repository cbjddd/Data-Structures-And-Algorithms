#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;  /* Status 是函数类型，其值位函数执行结果的状态代码，如ERROR、OK、TRUE、FALSE等 */
# define MAXSIZE 20
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
# define NUll 0

typedef struct SNode
{
	SElemType data;
	struct SNode* next;
}SNode;

typedef struct LinkStack
{
	SNode* top;
	int length;
}LinkStack;



Status Push(LinkStack& S, SElemType e)//插入元素
{
	SNode* p = new SNode;
	p->data = e;
	p->next = S.top;
	S.top = p;
	S.length++;
	return OK;
}

Status Pop(LinkStack& S, SElemType e)//压出元素
{
	SNode* p = new SNode;
	p = S.top;
	e = p->data;
	S.top = p->next;
	delete(p);
	return OK;
}

Status Destroy(LinkStack& S)//销毁链栈
{
	S.length = 0;
	return OK;
}

Status LinkStackCrt(LinkStack &S) //创建链栈
{
	SNode* head = new SNode;
	S.length = 0;
	int n;
	cout << "请输入链栈长度：";
	cin >> n;
	SElemType a;
	head->next = NULL;
	for (int i = 1; i <= n; i++) {
		SNode* p = new SNode;
		cin >> a;
		p->data = a;
		p -> next = head->next;
		S.top = p;
		head->next = S.top;
		S.length++;
	}
	return OK;
}

void LinkStackPrint(LinkStack &S)  /*输出带头结点的链栈*/
{
	SNode* p=new SNode;
	p->next=S.top;
	cout << "\n目前该链表长度为" << S.length << endl;
	int i;
	i = 0;
	cout << "\n链表的元素依次为：";
	while (p->next != NULL)
	{
		++i;
		p = p->next;
		cout << " 结点" << i << "=" << p->data;
	}
	cout << endl;
}

int main()
{
	LinkStack S;
	if (!LinkStackCrt(S))
		cout << endl << "链栈未成功生成！" << endl;
	else
	{
		LinkStackPrint(S);
		char cmd;
		SElemType x = 0;
		do
		{
			cout << endl << "请选择操作：" << endl;
			cout << "i , i ----- 压入元素" << endl;
			cout << "d , d ----- 弹出元素" << endl;
			cout << "q , q ----- 退出程序" << endl;
			do
			{
				cmd = getchar();
			} while ((cmd != 'i') && (cmd != 'd') && (cmd != 'q'));
			switch (cmd)
			{
			case  'i':
				cout << "\n请输入压栈数据（整型）: ";
				cin >> x;
				if (Push(S, x))
					cout << "\n已压入元素" << x << endl;
				else
					cout << "\n压入元素失败！" << endl;
				LinkStackPrint(S);
				break;
			case  'd':
				Pop(S, x);
                cout << "\n已弹出栈顶元素" << x << endl;
				LinkStackPrint(S);
				break;
			}
		} while (cmd != 'q');
	}
    system("pause");
	return 0;
}