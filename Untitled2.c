#include<stdio.h>


int MergeSort(int arr[],int lb,int ub);

int Merge(int a[],int lb,int mid,int ub);

int main()
{
	
	int n=0,m=0,i;
	
	printf("Enter the size of Array : \n");
	scanf("%d",&n);
	
	printf("Enter the elements of unsorted array: \n");
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\n Elements of unsorted array are : \n");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}

	MergeSort(arr,0,n);
	

	printf("\n Elements AFTER SORTING array are : \n");
	for(i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}

	
}
int MergeSort(int arr[],int lb,int ub)
{
	int mid;
	
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		MergeSort(arr,lb,mid);
		MergeSort(arr,mid+1,ub);
		Merge(arr,lb,mid,ub);
	}
}

int Merge(int a[],int lb,int mid,int ub)
{
	int i,j,k,b[100];
	
	i=lb;
	j=mid+1;
	k=lb;
	
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
			k++;	
		}	
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	
			while(i<=mid)
			{
				b[k]=a[i];
				i++;
				k++;
			}
			
			while(j<=ub)
			{
				b[k]=a[j];
				j++;
				k++;
			}
			
			for(k=lb;k<=ub;k++)
			{
				a[k]=b[k];
			}
}





















