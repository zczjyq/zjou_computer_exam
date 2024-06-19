// CSDN抄的懒得再写一遍了
#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
	char name[9];
	int array[1000];
	int number;
	double average;
}Person;
Person a[101]; 			//如果为a[100]就会越界，后面三个测试点都段错误 
Person change;			//用以调整结构体数组顺序 
int main()
{
	int N,i,k,j,lei,s,temp;
	scanf("%d",&N);
	for (i=0;i<N;i++)
	{
		scanf("%s %d",a[i].name,&k);
		for (j=0;j<k;j++)
		{
			scanf("%d",&lei);
			a[i].array[j]=lei;
		}
		//对array按标签大小进行排序
		for (j=1;j<k;j++)
		{
			for (s=0;s<k-j;s++)
			{
				if (a[i].array[s]>a[i].array[s+1])
				{
					temp=a[i].array[s];
					a[i].array[s]=a[i].array[s+1];
					a[i].array[s+1]=temp;
				}
			}
		}
		//计算出每一组的number 和average 
		int count=0;
		for (j=0;j<k;j++)
		{
			if (a[i].array[j]!=a[i].array[j+1])
			{
				count++;
			}
		}
		a[i].number=count;
		a[i].average=1.0*k/count;
	}
	//按number进行冒小泡排序------大的在前，小的在后 
	for (i=1;i<N;i++)
	{
		for (j=0;j<N-i;j++)
		{
			if (a[j].number<a[j+1].number)
			{
				change=a[j];
				a[j]=a[j+1];
				a[j+1]=change;
			}
		}
	} 
	 //处理number相同的情况
	for (i=0;i<N;i++)
	{
	 	if (a[i].number==a[i+1].number)
	 	{
	 		if (a[i].average>a[i+1].average)
	 		{
	 			change=a[i];
	 			a[i]=a[i+1];
	 			a[i+1]=change;	
			}
		}
	}
	if (N==0) printf("- - -");
	else if (N==1)
	{
		printf("%s - -",a[0].name);
	}
	else if (N==2)
	{
		printf("%s %s -",a[0].name,a[1].name);
	}
	else
	{
		for (i=0;i<3;i++)
	   {
		if (i!=0)
		printf(" %s",a[i].name);
		else
		printf("%s",a[i].name);
	   }
	}

}

