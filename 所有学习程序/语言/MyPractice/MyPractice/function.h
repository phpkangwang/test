#pragma warning( disable : 4996) //消除4996类型的警告

//循环练习
void CirclateTest()
{
	int myNum[]={1991,2,2};
	char cArray[]="my name is sunhao.";
	printf("%s",cArray);
	printf("\n");
	printf(cArray);
	printf("\n");
	int nPoint=0;

	//for循环
	for(; nPoint < 3; nPoint++ )
	{
		//printf("%d\n",myNum[nPoint]);
		printf("%4c ",(char)myNum[nPoint]);
	}

	//while循环
	while(nPoint < 3)
	{
		printf("%4d ",myNum[nPoint]);
		nPoint++;
	}

	//do-while循环
	nPoint = 0;
	do
	{
		printf("%4d ",myNum[nPoint]);
		nPoint++;

	}while(nPoint < 3);
	int n=20;
	printf("%c\n",(char)n);
}

//输出偶数
void OutputEven()
{	
	int nStart,nEnd,CulNum;
	printf("输入开始的数与结束的数:");
	scanf("%d,%d",&nStart,&nEnd);
	printf("输入每行输出的个数:");
	scanf("%d",&CulNum);
	//输入非数字所做的处理
	/*if(CulNum)
	{

	}*/
	if(nStart>=nEnd)
	{
		printf("error!");
	}
	int nCount=0;
	for(int n=nStart;n<=nEnd;n++)
	{
		if(n%2==0)
		{
			printf("%-4d",n);
			nCount++;
			if(nCount==CulNum)
			{
				nCount=0;
				printf("\n");
			}
		}
	}
}

//求1！+2！+3！+...+n!
void SigmaFactorial()
{
	int n = 5;
	int nSum = 0;
	int temp = 1;
	//scanf("%d",n);
	//方法1
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			temp *= j;//i的阶乘
		//相加
		nSum += temp;
		temp = 1;
	}
	//方法2，较方法1快
	/*
	temp = 1;
	nSum = 0;
	for(int i=1;i<=n;i++)
	{
		temp *=i;
		nSum += temp;
	}
	*/
	printf("Sigma(%d!)=%d",n,nSum);
	
}

//偶数阶乘之和
void EvenSigmaFactorial()
{
	int n ;
	printf("请输入n的值:");
	scanf("%d",&n);
	int nSum = 0;
	int temp = 1;
	for(int i=1;i<=n;i++)
	{
		temp *=i;
		if(i%2==0)
		{
			nSum += temp;
		}
	}
	printf("%d内所有偶数的阶乘之和=%d",n,nSum);
}

//判断是否为素数
void JudgePrime()
{
	int n;
	printf("请输入一个整数:");
	scanf_s("%d",&n);
	bool bIsPrime = true;
	if(n==1)
	{
		printf("%d既不是质数也不是素数",n);
	}
	else
	{
		for(int i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				bIsPrime = false;
				break;
			}
		}
	}
	/*if(bIsPrime == true)
		printf("%d是素数",n);
	else
		printf("%d不是素数",n);*/

	printf((bIsPrime==true)?"%d是素数":"%d不是素数",n);

}

//求整数各位位数字之和，各位位数字之间加空格输出
void IntSum()
{
	int n = 123456;
	int temp = n;
	int nSum = 0;
	int nNum = 0;
	while(n)
	{
		nSum += n%10;
		n /= 10;
		nNum ++;
	}
	printf("%d的各位位数字之和是:%d\n",temp,nSum);
	char nArray[30];
	for(int i = 2*nNum - 1;i >= 0; i--)
	{
		if(i%2==0)
		{
			nArray[i] = (char)(temp % 10 + 48);
			temp /= 10;
		}
		else 
		{
			nArray[i] = ' ';
		}
	}
	nArray[2*nNum-1]='\0';
	printf("%s",nArray);

}

//输出菱形图案
void OutputGraph(int nGraphSize)
{
	int nBlackNum;
	int nRowGraphSize;
	for(int i=0;i<nGraphSize;i++)
	{
		if(i < nGraphSize/2 + 1)
		{
			nRowGraphSize = 2*i + 1;
			nBlackNum = nGraphSize/2 + 1 - (i + 1);
		}
		else
		{
			nBlackNum =i - nGraphSize/2;
			nRowGraphSize = nGraphSize - 2*nBlackNum;
		}
		for(int j = 0; j < nBlackNum;j++)
			printf(" ");
		for(int j = 0; j < nRowGraphSize;j++)
			printf("*");//☆★●○◎◇◆*
		printf("\n");
		//printf("\n");

	}
}
