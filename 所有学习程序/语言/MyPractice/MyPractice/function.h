#pragma warning( disable : 4996) //����4996���͵ľ���

//ѭ����ϰ
void CirclateTest()
{
	int myNum[]={1991,2,2};
	char cArray[]="my name is sunhao.";
	printf("%s",cArray);
	printf("\n");
	printf(cArray);
	printf("\n");
	int nPoint=0;

	//forѭ��
	for(; nPoint < 3; nPoint++ )
	{
		//printf("%d\n",myNum[nPoint]);
		printf("%4c ",(char)myNum[nPoint]);
	}

	//whileѭ��
	while(nPoint < 3)
	{
		printf("%4d ",myNum[nPoint]);
		nPoint++;
	}

	//do-whileѭ��
	nPoint = 0;
	do
	{
		printf("%4d ",myNum[nPoint]);
		nPoint++;

	}while(nPoint < 3);
	int n=20;
	printf("%c\n",(char)n);
}

//���ż��
void OutputEven()
{	
	int nStart,nEnd,CulNum;
	printf("���뿪ʼ�������������:");
	scanf("%d,%d",&nStart,&nEnd);
	printf("����ÿ������ĸ���:");
	scanf("%d",&CulNum);
	//��������������Ĵ���
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

//��1��+2��+3��+...+n!
void SigmaFactorial()
{
	int n = 5;
	int nSum = 0;
	int temp = 1;
	//scanf("%d",n);
	//����1
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			temp *= j;//i�Ľ׳�
		//���
		nSum += temp;
		temp = 1;
	}
	//����2���Ϸ���1��
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

//ż���׳�֮��
void EvenSigmaFactorial()
{
	int n ;
	printf("������n��ֵ:");
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
	printf("%d������ż���Ľ׳�֮��=%d",n,nSum);
}

//�ж��Ƿ�Ϊ����
void JudgePrime()
{
	int n;
	printf("������һ������:");
	scanf_s("%d",&n);
	bool bIsPrime = true;
	if(n==1)
	{
		printf("%d�Ȳ�������Ҳ��������",n);
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
		printf("%d������",n);
	else
		printf("%d��������",n);*/

	printf((bIsPrime==true)?"%d������":"%d��������",n);

}

//��������λλ����֮�ͣ���λλ����֮��ӿո����
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
	printf("%d�ĸ�λλ����֮����:%d\n",temp,nSum);
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

//�������ͼ��
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
			printf("*");//��������*
		printf("\n");
		//printf("\n");

	}
}
