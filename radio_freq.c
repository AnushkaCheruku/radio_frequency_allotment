#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int freq=1;
void assign_freq(bool** graph,int vertex,int* freqs,int devices)
{
	int i;
	for(i=0 ; i<devices; i++)
	{
		if(graph[vertex][i] && freqs[i]==freq)
			freq++;
	}
 	freqs[vertex]=freq;
}
int main()
{
 	int n,i,j;
 	printf("Enter no. of towers:");
 	scanf("%d",&n);
 	bool** graph = (bool **)malloc(sizeof(bool*)*n);
 	for(i=0;i<n;i++) 
		graph[i]=(bool *)malloc(sizeof(bool)*n);
 	bool** visited = (bool **)malloc(sizeof(bool*)*n);
 	for(i=0;i<n;i++) 
		visited[i]=(bool *)malloc(sizeof(bool)*n);
 	char c;
 	for(i=0;i<n;i++)
	{
 		for(j=0;j<n;j++)
		{
     			if(i==j)
			{ 
				graph[i][j]=0;
     				continue;
			}
     			if(visited[i][j]) 
				continue;
printf("Do towers %d and %d lie in the same range?(y/n):",i+1,j+1);
 			scanf(" %c",&c);
 			if(c=='y')
			{
				graph[i][j]=1; 
				graph[j][i]=1; 
				visited[i][j]=1;
				visited[j][i]=1;
			}
 			else if(c=='n') 
			{
				graph[i][j]=0; 
				graph[j][i]=0;
				visited[i][j]=1;
				visited[j][i]=1;
			}
 			else 
			{
				printf("Invalid input error!");
				break;
			}
 		}
 	}
 	printf("\nThe network topology is:\n");
 	for(int i=0;i<n;i++)
	{
 		for(int j=0;j<n;j++)
 			printf("%3d",graph[i][j]);
		printf("\n");
	}
 	int freqs[n];
 	for(i=0;i<n;i++)
	{
		freqs[i]=0;
 	}
	for(i=0;i<n;i++)
	{
 		assign_freq(graph,i,freqs,n);
	}
 	printf("\nThe minimum number of frequencies required in order to avoid interference in communication are:%2d\n\n",freq);
 	for(i=0;i<n;i++)
	{
 		printf("frequency assigned to tower %d is: Freq%d\n",i+1,freqs[i]);
 	}
	for(i=0;i<n;i++) 
	{	
		free(graph[i]);
	}
	return 0;
}
