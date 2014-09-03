#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
static int buffer,g;
int getop( double s[]);
void push(double b);
double pop(void);
void swap(void);
void clear(void);
double save(void);
main()
{
	double s[1],z[26];
	int flag[26];
	double a;
	double b,op;
	int op1,op2,n,xp;
	int type,i=0,j;
	for(j=0;j<26;++j)
		flag[j]='\0';
l: printf("start");
	while((type=getop(s))!=EOF){
printf("%f\t%d",s[i],type);
		if(type=='~'){loo: printf("exiting");goto l;break;}
		b=s[i];
		if(type>='a'&&type<='z'){
			if(flag[type-'a']!=1){
				z[type-'a']=save();
				flag[type-'a']=1;
//				printf("%f\n",z[type-'a']);
			}
			else 
				push(z[type-'a']);
}
		switch(type){
			
			case 0:
				push(b);
				break;
			case '+':
				push(pop()+pop());
				break;
			case '#':
				op1=pop();
                                op=sin(op1);
				push(op);
                                break;
                        case '!':
                                op1=pop();
                                op=cos(op1);
                                push(op);
                                break;
			case '@':
                                op1=pop();
                                op=exp(op1);
                                push(op);
                                break;
                        case '$':
                                op1=pop();
                                op=tan(op1);
                                push(op);
                                break;
			case '^':
                                op1=pop();
				op2=pop();
				xp=op2;
                                op=op1;
				op=pow(xp,op);
                                push(op);
                                break;


			case '*': 
                                push(pop()*pop());
                                break;
			case '/': 
				op=pop();
                                push(pop()/op);
                                break;
			case '-': 
				op=pop();
                                push(pop()-op);
                                break;
			case '%': 
				op1=pop();
				op2=pop();
				op=op2%op1;
                                push(op);
                                break;
			case '\n':
				printf("\nSUM=%f\n",pop());
//				swap();
				printf("clear satck?");
				scanf("%d",&n);
				if(n==1){
					clear();
					type=EOF;
					n=0;
					for(j=0;j<26;++j){
                				flag[j]='\0';
						z[j]='\0';
					}
					while(getchar()!='\n');
					goto loo;
				}
				else{
					type=getop(s);
					while(getchar()!='\n');
					goto loo;
				}
				break;
			default:
				break;
		}	
	}
}


#define M 100
int sp=0;
double valu[M];
double c;
void push(double b)
{
	if(sp<M){
		valu[sp++]=b;//printf("\n%d\t%f\n",sp-1,valu[sp-1]);
	}
	else
		printf("overflow");
}

double pop(void)
{
	if(sp>0){
		return valu[--sp];
	}
	else{
 		printf("empty");
		return 0.0;
	}
}
void swap(void)
{
	c=valu[sp];
	valu[sp]=valu[sp-1];
	valu[sp-1]=c;
	printf("%f\t%f",valu[sp],valu[sp-1]);
}
void clear(void)
{
	for(sp=0;sp<100;sp++)
		valu[sp]='\0';
}
double save(void)
{
	return valu[sp-1];
}
int getop(double k[])
{
	int i=0,j,pow=1,c,sign=1;
	double val;
	if(buffer==1){
		buffer=0;
		return g;
	}
	else
		while((c=getchar())==' '||c=='\t')
			;
	while(!isdigit(c)&&c!='.'&&c!='-'&&c!='c'&&c!='e'&&c!='s'&&c!='t'&&c!='p')
		return c;
	if(c=='c'||c=='e'||c=='s'||c=='t'||c=='p'){
		int mat=c;
		c=getchar();
		if(c=='i'||c=='o'||c=='a'||c=='x'||c=='o'){
			switch(mat){
				case 'c':
					return '!';
					break;
				case 'e':
                                        return '@';
                                        break;
				case 's':
                                        return '#';
                                        break;
				case 't':
                                        return '$';
                                        break;
				case 'p':
                                        return '^';
                                        break;
			}
		}
		else{
			buffer=1;
			g=c;
			return mat;}
	}
	if(c=='-'){
		c=getchar();
		sign=(isdigit(c))?-1:1;
	
	if(sign==1)
		return '-';
	}
	if(isdigit(c)||c=='.'){
		for(val=0.0;isdigit(c);++j){
			val=val*10.0+(c-'0');
			c=getchar();
			buffer=1;
			g=c;
		}
		if(c=='.'){
			c=getchar();
			for(pow=1;isdigit(c);++j){
				val=val*10+(c-'0');
				pow=pow*10;
				c=getchar();
				buffer=1;
				g=c;
			}
		
		}
		k[i]=sign*val/pow;
	}

	return 0;
	
		
}

