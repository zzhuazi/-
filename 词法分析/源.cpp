# include  <stdio.h> ���� I / O�����õ�ĳЩ��ͱ���
# include  <string.h>  ���� �ַ����⺯��
char   prog[80], token[8];
char   ch;
int  syn, p, m, n, sum;
char   *rwtab[10] = { "fi", "if", "then", "while", "do" ,"end", "read", "write", "else", "to" };

void scaner()
{
	for (n = 0; n < 8; n++) token[n] = NULL;
	ch = prog[p++];
	while (ch == ' ')  ch = prog[p++];
	if (ch >= 'a' && ch <= 'z'){
		m = 0;
		while ((ch >= 'a' && ch <= 'z') || ((ch >= 'A'&&ch <= 'Z') || (ch >= '0' && ch <= '9')))
		{
			token[m++] = ch;
			ch = prog[p++];  //��ȡ��һ���ַ�
		}
		token[m++] = '\0';   p--;   syn = 10;
		for (n = 0; n < 10; n++)    //6->10
			if (strcmp(token, rwtab[n]) == 0)  //��ͬ
			{
				syn = n + 1;//���� syn ֵ;    fi Ϊ1
				break;
			}
	}
	else if (ch >= '0' && ch <= '9'){
		sum = 0;
		while (ch >= '0' && ch <= '9')//ch Ϊ�����ַ�
		{
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;   syn = 11;
	}
	else {
		switch (ch)
		{
		case '<':
			m = 0; token[m++] = ch;
			ch = prog[p++];
			if (ch == '>')    //<>
			{
				syn = 21;
				token[m++] = ch;
			}
			else if (ch == '=')  //<=
			{
				syn = 22;
				token[m++] = ch;
			}
			else {				//<
				syn = 20;
				p--;
			}
			break;
		case '>':
			m = 0;
			token[m++] = ch;	//ch = > token;
			ch = prog[p++];
			if (ch == '=')		//>=
			{
				syn = 24;		//�� >= ���ֱ��� = > syn;
				token[m++] = ch; //ch = > token;
			}
			else				//>
			{
				syn = 23;//�� > ���ֱ��� = > syn;
				p--;
			}
			break;
		case ':':
			m = 0;
			token[m++] = ch;			//ch = > token;
			ch = prog[p++];			//����һ���ַ�;
			if (ch == '=')			//:=
			{
				syn = 18;			//��: = ���ֱ��� = > syn;
				token[m++] = ch;	//ch = > token;
			}
			else					//:
			{
				syn = 19;					//��:���ֱ��� = > syn;
				p--;
			}
			break;
		case '+':	syn = 14; token[0] = ch; break;
		case '-':	syn = 15; token[0] = ch; break;
		case '*':	syn = 16; token[0] = ch; break;
		case '/':	syn = 17; token[0] = ch; break;
		case '#':	syn = 0;  token[0] = ch; break;
		case ';':	syn = 26;  token[0] = ch; break;
		case '(':	syn = 27;  token[0] = ch; break;
		case ')':	syn = 28;  token[0] = ch; break;
		default:
			syn = -1;
		}
	}
}


void main()
{
	p = 0;
	printf("\n please input  string : \n");
	do {
		ch = getchar();
		prog[p++] = ch;
	} while (ch != '#');
	p = 0;
	do
	{
		scaner();
		switch (syn)
		{
		case 11:  printf("(% 2d, % 8d)\n", syn, sum); break;
		case -1:  printf("input error\n");  break;
		default:   printf("(% 2d, % 8s)\n", syn, token);
		}
	} while (syn != 0);
}



