#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;  /* Status �Ǻ������ͣ���ֵλ����ִ�н����״̬���룬��ERROR��OK��TRUE��FALSE�� */
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



Status Push(LinkStack& S, SElemType e)//����Ԫ��
{
	SNode* p = new SNode;
	p->data = e;
	p->next = S.top;
	S.top = p;
	S.length++;
	return OK;
}

Status Pop(LinkStack& S, SElemType e)//ѹ��Ԫ��
{
	SNode* p = new SNode;
	p = S.top;
	e = p->data;
	S.top = p->next;
	delete(p);
	return OK;
}

Status Destroy(LinkStack& S)//������ջ
{
	S.length = 0;
	return OK;
}

Status LinkStackCrt(LinkStack &S) //������ջ
{
	SNode* head = new SNode;
	S.length = 0;
	int n;
	cout << "��������ջ���ȣ�";
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

void LinkStackPrint(LinkStack &S)  /*�����ͷ������ջ*/
{
	SNode* p=new SNode;
	p->next=S.top;
	cout << "\nĿǰ��������Ϊ" << S.length << endl;
	int i;
	i = 0;
	cout << "\n�����Ԫ������Ϊ��";
	while (p->next != NULL)
	{
		++i;
		p = p->next;
		cout << " ���" << i << "=" << p->data;
	}
	cout << endl;
}

int main()
{
	LinkStack S;
	if (!LinkStackCrt(S))
		cout << endl << "��ջδ�ɹ����ɣ�" << endl;
	else
	{
		LinkStackPrint(S);
		char cmd;
		SElemType x = 0;
		do
		{
			cout << endl << "��ѡ�������" << endl;
			cout << "i , i ----- ѹ��Ԫ��" << endl;
			cout << "d , d ----- ����Ԫ��" << endl;
			cout << "q , q ----- �˳�����" << endl;
			do
			{
				cmd = getchar();
			} while ((cmd != 'i') && (cmd != 'd') && (cmd != 'q'));
			switch (cmd)
			{
			case  'i':
				cout << "\n������ѹջ���ݣ����ͣ�: ";
				cin >> x;
				if (Push(S, x))
					cout << "\n��ѹ��Ԫ��" << x << endl;
				else
					cout << "\nѹ��Ԫ��ʧ�ܣ�" << endl;
				LinkStackPrint(S);
				break;
			case  'd':
				Pop(S, x);
                cout << "\n�ѵ���ջ��Ԫ��" << x << endl;
				LinkStackPrint(S);
				break;
			}
		} while (cmd != 'q');
	}
    system("pause");
	return 0;
}