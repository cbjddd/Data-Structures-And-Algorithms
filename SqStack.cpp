#include <iostream>
using namespace std;

typedef char SElemType;
typedef int Status;  /* Status是函数类型，其值为函数执行结果的状态代码，如ERROR、OK、TRUE、FALSE*/
# define MAXSIZE 20
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
typedef struct  /* 定义字符顺序栈 */
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

typedef struct//定义数字顺序栈
{
	int data[MAXSIZE];
	int top;
}StackNum;


template<typename T1>
void DestroyStack(T1& S)//通过函数模板销毁符号栈和数字栈
{
	delete S;
}


void InitSqStack(SqStack*& s)//初始化符号栈
{
	s = new SqStack;
	s->top = -1;
}


void InitStackNum(StackNum*& s)//初始化数字栈
{
	s = new StackNum;
	s->top = -1;
}





int Push(SqStack* S, SElemType e) /* 插入函数将SElemType插入符号栈S */
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	if (S->top != MAXSIZE - 1) {
		S->top++;
		S->data[S->top] = e;
		return OK;
	}
	
}

int push(StackNum* S, int e) /* 插入函数将int变量插入数字栈S */
{
	if (S->top == MAXSIZE - 1)
		return ERROR;
	if (S->top != MAXSIZE - 1) {
		S->top++;
		S->data[S->top] = e;
		return OK;
	}

}

int Pop(SqStack*S, SElemType &e)  /* 弹出函数，将符号栈栈顶元素弹出并赋值给e */
{
	if (S->top == -1)
		return ERROR;
	e= S->data[S->top];
	S->top--;
	return OK;
}


int pop(StackNum* S, int& e)  /* 弹出函数将数字栈栈顶，并将数字栈栈顶元素弹出并赋值给e */
{
	if (S->top == -1)
		return ERROR;
	e = S->data[S->top];
	S->top--;
	return OK;
}


template<typename T1, typename T2 >
Status GetTop(T1& s, T2& e)//通过函数模板得到栈顶元素
{
	if (s->top == -1)
		return ERROR;
	e = s->data[s->top];
	return OK;
}

template<typename T1>
Status StackEmpty(T1& s)//通过函数模板判断栈是否为空
{
	if (s->top == -1)
		return OK;
	return ERROR;
}


void trans(char* exp, char postexp[])//得到逆波兰式
{

	char e;											//给Pop与Gettop函数使用
	SqStack* Optr;								    //定义符号运算栈指针
	int i = 0;										// i作为postexp下表
	InitSqStack(Optr);				                        //初始化运算符栈
	while (*exp != '\0')							//exp表示为扫描时循环
	{
		switch (*exp)
		{
		case '(':									//判定左括号
			Push(Optr, '(');
			exp++;									//exp指针前移，继续处理下一个字符
			break;
		case ')':									//判定为右括号
			Pop(Optr, e);							
			while (e != '(')						//直到遇到“（”为止
			{
				postexp[i++] = e;
				Pop(Optr, e);
			}
			exp++;
			break;
		case '+':									// 判定为“+”或“-”
		case '-':
			while (!StackEmpty(Optr))               //直到栈空或者栈顶为“（”，然后将其入栈
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
			Push(Optr, *exp);						 //最后将“+”或者“-”入栈
			exp++;
			break;
		case '*':									 //判定为“*”或“/”
		case '/':
			while (!StackEmpty(Optr))				 //直到栈顶为空或者为“（”“*”“/”，然后将其入栈·
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
			Push(Optr, *exp);						//最后将“*”“/”入栈
			exp++;
			break;
		default:									//处理数字字符
			while (*exp >= '0' && *exp <= '9')	    //循环处理多位数字
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = ' ';                     //以空格 表示一个数字串结束 
		}
	}
	while (!StackEmpty(Optr))                         //结束exp扫描，栈不空时循环
	{												  //将optr的所有运算符依次出栈保存到postexp
		Pop(Optr, e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';								 //给postexp添加结束标志
	DestroyStack(Optr);								//销毁栈
}


//计算后缀表达式的值
int compvalue(char* postexp)
{
	StackNum* Opnd;						//定义数字栈
	InitStackNum(Opnd);					//初始化数字栈
	int result;							//存放结果
	int a, b;							//弹出栈的两个数
	int c;								//计算弹出两个数的运算结果
	int d;							    //将连续的数字字符转化为十进制整数保存在d中
	while (*postexp != '\0')				//postexp未扫描完时循环
	{
		switch (*postexp)
		{
		case '+':                            //判定为加号
			pop(Opnd, a);                    //从Open中弹出两个数值a，b，c=a+b，将c压入栈
			c = b + a;
			push(Opnd, c);
			break;
		case '-':							//判定为减号
			pop(Opnd, a);					//从Open中弹出两个数值a，b，c=b-a,将c压入栈
			pop(Opnd, b);
			c = b - a;						//b-a因为b后出栈
			push(Opnd, c);
			break;
		case '*':							//判定为乘号
			pop(Opnd, a);					//从Opnd弹出两个数值a和b，c=a*b，将c入栈
			c = b * a;
			push(Opnd, c);
			break;
		case '/':							//判定为除号
			pop(Opnd, a);					//从Opnd中弹出两个数值a和b，若a不等于0，则c=b/a，将c入栈
			pop(Opnd, b);
			if (a != 0)                       //检查除数的合法性
			{
				c = b / a;
				push(Opnd, c);
				break;
			}
			else
			{
				cout << "\n除零错误！" << endl;
				exit(0);
			}

		default:									//处理数字字符
			d = 0;									//将连续的数字字符转换为对应数值存放到d中
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			push(Opnd, d);
			break;
		}
		postexp++;							//继续处理下一个字符
	}
	pop(Opnd, result);					//弹出运算最终的结果
	delete Opnd;							//销毁栈
	return result;							//返回结果
}



Status StackCrt(SqStack* S)   /*从屏幕逐位读入数据生成符号顺序栈*/
{
	S->top = -1;    /* 初始化栈 */
	int  n, i;
	cout << "正在构建字符型顺序栈S，请输入S的数据个数" << endl;
	cin >> n;
	if (n > MAXSIZE)
	{
		cout << endl << "数据个数超出，请不要超过" << MAXSIZE << endl;
		return ERROR;
	}
	else if (n < 0)
	{
		cout << endl << "输入不合法" << endl;
		return ERROR;
	}
	cout << "请依次输入元素：" << endl;
	for (i = 0; i < n; i++)
	{
		S->top++;
		cout << "data[" << i << "] =";
		cin >> S->data[i];
	}
	cout << endl;
	return OK;
}

Status stackcrt(StackNum* S)   /*从屏幕逐位读入数据生成数字顺序栈*/
{
	S->top = -1;    /* 初始化栈 */
	int  n, i;
	cout << "正在构建数字顺序栈，请输入S的数据个数" << endl;
	cin >> n;
	if (n > MAXSIZE)
	{
		cout << endl << "超过长度，请不要超过" << MAXSIZE << endl;
		return ERROR;
	}
	else if (n < 0)
	{
		cout << endl << "输入不合法" << endl;
		return ERROR;
	}
	cout << "请依次输入元素" << endl;
	for (i = 0; i < n; i++)
	{
		S->top++;
		cout << "data[" << i << "] =";
		cin >> S->data[i];
	}
	cout << endl;
	return OK;
}



void StackPrint(SqStack* S)  /*输入字符型顺序栈S*/
{
	int i;
	cout << endl << "目前栈内的元素从上到下依次为";
	for (i = S->top; i >= 0; i--)
	{
		cout << "data[" << i << "]=" << S->data[i] << "  ";
	}
	cout << endl;
}

void stackprint(StackNum* S)  /*输入数字顺序栈S*/
{
	int i;
	cout << endl << "目前栈内的元素从上到下依次为";
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
		cout << endl << "字符型顺序栈未成功生成" << endl;
	else
	{
		StackPrint(p);
		char cmd;
		SElemType x = 0;
		do
		{
			cout << endl << "请选择操作：" << endl;
			cout << "i , i ----- 压入字符型元素" << endl;
			cout << "d , d ----- 弹出字符型元素" << endl;
			cout << "c , c ----- 输入中缀表达式转换为逆波兰式表达式并计算结果" << endl;
			cout << "q , q ----- 退出程序" << endl;
			do
			{
				cmd = getchar();
			} while ((cmd != 'i') && (cmd != 'd') && (cmd != 'c') && (cmd != 'q'));
			switch (cmd)
			{
			case  'i':
				cout << "\n请输入要压入的元素: ";
				cin >> x;
				if (Push(p, x))
					cout << "\n已压入元素" << x << endl;
				else
					cout << "\n压入元素失败" << endl;
				StackPrint(p);
				break;
			case  'd':
				if (Pop(p, x))
					cout << "\n已弹出栈顶元素" << x << endl;
				else
					cout << "\n弹出元素失败" << endl;
				StackPrint(p);
				break;
			case  'c':
			    char exp[MAXSIZE];					//???????
				char postexp[MAXSIZE];				//????????
				cout << "请输入合法的中缀表达式:";
				cin >> exp;
				trans(exp, postexp);
				cout << "后缀表达式为：" << postexp << endl        //????????????????????
					<< "计算结果为：" << compvalue(postexp) << endl;
			}
		} while (cmd != 'q');
	}
	system("pause");
	return 0;
}
