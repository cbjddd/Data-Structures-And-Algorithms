#include <iostream>
using namespace std;

typedef char SElemType;
typedef int Status;  /* Status�Ǻ������ͣ���ֵΪ����ִ�н����״̬���룬��ERROR��OK��TRUE��FALSE*/
# define MAXSIZE 20
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
typedef struct  /* �����ַ�˳��ջ */
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

typedef struct//��������˳��ջ
{
	int data[MAXSIZE];
	int top;
}StackNum;


template<typename T1>
void DestroyStack(T1& S)//ͨ������ģ�����ٷ���ջ������ջ
{
	delete S;
}


void InitSqStack(SqStack*& s)//��ʼ������ջ
{
	s = new SqStack;
	s->top = -1;
}


void InitStackNum(StackNum*& s)//��ʼ������ջ
{
	s = new StackNum;
	s->top = -1;
}





int Push(SqStack* S, SElemType e) /* ���뺯����SElemType�������ջS */
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	if (S->top != MAXSIZE - 1) {
		S->top++;
		S->data[S->top] = e;
		return OK;
	}
	
}

int push(StackNum* S, int e) /* ���뺯����int������������ջS */
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	if (S->top != MAXSIZE - 1) {
		S->top++;
		S->data[S->top] = e;
		return OK;
	}

}

int Pop(SqStack*S, SElemType &e)  /* ����������������ջջ��Ԫ�ص�������ֵ��e */
{
	if (S->top == -1)
		return ERROR;
	e= S->data[S->top];
	S->top--;
	return OK;
}


int pop(StackNum* S, int& e)  /* ��������������ջջ������������ջջ��Ԫ�ص�������ֵ��e */
{
	if (S->top == -1)
		return ERROR;
	e = S->data[S->top];
	S->top--;
	return OK;
}


template<typename T1, typename T2 >
Status GetTop(T1& s, T2& e)//ͨ������ģ��õ�ջ��Ԫ��
{
	if (s->top == -1)
		return ERROR;
	e = s->data[s->top];
	return OK;
}

template<typename T1>
Status StackEmpty(T1& s)//ͨ������ģ���ж�ջ�Ƿ�Ϊ��
{
	if (s->top == -1)
		return OK;
	return ERROR;
}


void trans(char* exp, char postexp[])//�õ��沨��ʽ
{

	char e;											//��Pop��Gettop����ʹ��
	SqStack* Optr;								    //�����������ջָ��
	int i = 0;										// i��Ϊpostexp�±�
	InitSqStack(Optr);				                        //��ʼ�������ջ
	while (*exp != '\0')							//exp��ʾΪɨ��ʱѭ��
	{
		switch (*exp)
		{
		case '(':									//�ж�������
			Push(Optr, '(');
			exp++;									//expָ��ǰ�ƣ�����������һ���ַ�
			break;
		case ')':									//�ж�Ϊ������
			Pop(Optr, e);							
			while (e != '(')						//ֱ������������Ϊֹ
			{
				postexp[i++] = e;
				Pop(Optr, e);
			}
			exp++;
			break;
		case '+':									// �ж�Ϊ��+����-��
		case '-':
			while (!StackEmpty(Optr))               //ֱ��ջ�ջ���ջ��Ϊ��������Ȼ������ջ
			{
				GetTop(Optr, e);
				if (e == '(')
					break;
				else
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
			}
			Push(Optr, *exp);						 //��󽫡�+�����ߡ�-����ջ
			exp++;
			break;
		case '*':									 //�ж�Ϊ��*����/��
		case '/':
			while (!StackEmpty(Optr))				 //ֱ��ջ��Ϊ�ջ���Ϊ��������*����/����Ȼ������ջ��
			{
				GetTop(Optr, e);
				if (e == '/' || e == '*')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else
					break;
			}
			Push(Optr, *exp);						//��󽫡�*����/����ջ
			exp++;
			break;
		default:									//���������ַ�
			while (*exp >= '0' && *exp <= '9')	    //ѭ�������λ����
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = ' ';                     //�Կո� ��ʾһ�����ִ����� 
		}
	}
	while (!StackEmpty(Optr))                         //����expɨ�裬ջ����ʱѭ��
	{												  //��optr��������������γ�ջ���浽postexp
		Pop(Optr, e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';								 //��postexp��ӽ�����־
	DestroyStack(Optr);								//����ջ
}


//�����׺���ʽ��ֵ
int compvalue(char* postexp)
{
	StackNum* Opnd;						//��������ջ
	InitStackNum(Opnd);					//��ʼ������ջ
	int result;							//��Ž��
	int a, b;							//����ջ��������
	int c;								//���㵯����������������
	int d;							    //�������������ַ�ת��Ϊʮ��������������d��
	while (*postexp != '\0')				//postexpδɨ����ʱѭ��
	{
		switch (*postexp)
		{
		case '+':                            //�ж�Ϊ�Ӻ�
			pop(Opnd, a);                    //��Open�е���������ֵa��b��c=a+b����cѹ��ջ
			c = b + a;
			push(Opnd, c);
			break;
		case '-':							//�ж�Ϊ����
			pop(Opnd, a);					//��Open�е���������ֵa��b��c=b-a,��cѹ��ջ
			pop(Opnd, b);
			c = b - a;						//b-a��Ϊb���ջ
			push(Opnd, c);
			break;
		case '*':							//�ж�Ϊ�˺�
			pop(Opnd, a);					//��Opnd����������ֵa��b��c=a*b����c��ջ
			c = b * a;
			push(Opnd, c);
			break;
		case '/':							//�ж�Ϊ����
			pop(Opnd, a);					//��Opnd�е���������ֵa��b����a������0����c=b/a����c��ջ
			pop(Opnd, b);
			if (a != 0)                       //�������ĺϷ���
			{
				c = b / a;
				push(Opnd, c);
				break;
			}
			else
			{
				cout << "\n�������" << endl;
				exit(0);
			}

		default:									//���������ַ�
			d = 0;									//�������������ַ�ת��Ϊ��Ӧ��ֵ��ŵ�d��
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			push(Opnd, d);
			break;
		}
		postexp++;							//����������һ���ַ�
	}
	pop(Opnd, result);					//�����������յĽ��
	delete Opnd;							//����ջ
	return result;							//���ؽ��
}



Status StackCrt(SqStack* S)   /*����Ļ��λ�����������ɷ���˳��ջ*/
{
	S->top = -1;    /* ��ʼ��ջ */
	int  n, i;
	cout << "���ڹ����ַ���˳��ջS��������S�����ݸ���" << endl;
	cin >> n;
	if (n > MAXSIZE)
	{
		cout << endl << "���ݸ����������벻Ҫ����" << MAXSIZE << endl;
		return ERROR;
	}
	else if (n < 0)
	{
		cout << endl << "���벻�Ϸ�" << endl;
		return ERROR;
	}
	cout << "����������Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
	{
		S->top++;
		cout << "data[" << i << "] =";
		cin >> S->data[i];
	}
	cout << endl;
	return OK;
}

Status stackcrt(StackNum* S)   /*����Ļ��λ����������������˳��ջ*/
{
	S->top = -1;    /* ��ʼ��ջ */
	int  n, i;
	cout << "���ڹ�������˳��ջ��������S�����ݸ���" << endl;
	cin >> n;
	if (n > MAXSIZE)
	{
		cout << endl << "�������ȣ��벻Ҫ����" << MAXSIZE << endl;
		return ERROR;
	}
	else if (n < 0)
	{
		cout << endl << "���벻�Ϸ�" << endl;
		return ERROR;
	}
	cout << "����������Ԫ��" << endl;
	for (i = 0; i < n; i++)
	{
		S->top++;
		cout << "data[" << i << "] =";
		cin >> S->data[i];
	}
	cout << endl;
	return OK;
}



void StackPrint(SqStack* S)  /*�����ַ���˳��ջS*/
{
	int i;
	cout << endl << "Ŀǰջ�ڵ�Ԫ�ش��ϵ�������Ϊ";
	for (i = S->top; i >= 0; i--)
	{
		cout << "data[" << i << "]=" << S->data[i] << "  ";
	}
	cout << endl;
}

void stackprint(StackNum* S)  /*��������˳��ջS*/
{
	int i;
	cout << endl << "Ŀǰջ�ڵ�Ԫ�ش��ϵ�������Ϊ";
	for (i = S->top; i >= 0; i--)
	{
		cout << "data[" << i << "]=" << S->data[i] << "  ";
	}
	cout << endl;
}



int main()
{
	SqStack S, * p;
	StackNum s, * P;
	p = &S;
	P = &s;
	if (!StackCrt(p))
		cout << endl << "�ַ���˳��ջδ�ɹ�����" << endl;
	else
	{
		StackPrint(p);
		char cmd;
		SElemType x = 0;
		do
		{
			cout << endl << "��ѡ�������" << endl;
			cout << "i , i ----- ѹ���ַ���Ԫ��" << endl;
			cout << "d , d ----- �����ַ���Ԫ��" << endl;
			cout << "c , c ----- ������׺���ʽת��Ϊ�沨��ʽ���ʽ��������" << endl;
			cout << "q , q ----- �˳�����" << endl;
			do
			{
				cmd = getchar();
			} while ((cmd != 'i') && (cmd != 'd') && (cmd != 'c') && (cmd != 'q'));
			switch (cmd)
			{
			case  'i':
				cout << "\n������Ҫѹ���Ԫ��: ";
				cin >> x;
				if (Push(p, x))
					cout << "\n��ѹ��Ԫ��" << x << endl;
				else
					cout << "\nѹ��Ԫ��ʧ��" << endl;
				StackPrint(p);
				break;
			case  'd':
				if (Pop(p, x))
					cout << "\n�ѵ���ջ��Ԫ��" << x << endl;
				else
					cout << "\n����Ԫ��ʧ��" << endl;
				StackPrint(p);
				break;
			case  'c':
			    char exp[MAXSIZE];					//???????
				char postexp[MAXSIZE];				//????????
				cout << "������Ϸ�����׺���ʽ:";
				cin >> exp;
				trans(exp, postexp);
				cout << "��׺���ʽΪ��" << postexp << endl        //????????????????????
					<< "������Ϊ��" << compvalue(postexp) << endl;
			}
		} while (cmd != 'q');
	}
	system("pause");
	return 0;
}
