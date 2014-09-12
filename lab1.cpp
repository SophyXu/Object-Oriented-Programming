//author:Xu Xiaoyao
#include <stdio.h>
int main()
{
	int i, j, p, min1, min2, min3, max1, max2, max3;
	int score1[11], score2[11], score3[11];
	float avg1=0, avg2=0, avg3=0;
	char name[11][13], t; 
//read in
//the total length of the name is suggested to be shorter than 12
	for(i=1;i<=10;i++)
	{
		j=1;	
		while(1)
		{
			scanf("%c", &t);	
			if(t!=' ' && t!='\n')
				break;			
		}	
		while(1)
		{		
			if(t==' ')
				break;
			name[i][j]=t;
			j++;
			scanf("%c", &t);
		}
		name[i][j] = '\0';
		scanf("%d", &score1[i]);
		scanf("%d", &score2[i]);
		scanf("%d", &score3[i]);
	}
//calculate
	min1=1;
	max1=1;
	for(i=1;i<=10;i++)
	{
		if(score1[i]<score1[min1])
			min1=i;
		if(score1[i]>score1[max1])
			max1=i;
		avg1=avg1+score1[i];
	}
	avg1=avg1/10;
	min2=1;
	max2=1;
	for(i=1;i<=10;i++)
	{
		if(score2[i]<score2[min2])
			min2=i;
		if(score2[i]>score2[max2])
			max2=i;
		avg2=avg2+score2[i];
	}
	avg2=avg2/10;
	min3=1;
	max3=1;
	for(i=1;i<=10;i++)
	{
		if(score3[i]<score3[min3])
			min3=i;
		if(score3[i]>score3[max3])
			max3=i;
		avg3=avg3+score3[i];
	}
	avg3=avg3/10;
//output
	printf("no      name       score1   score2   score3   average\n");
	for(i=1;i<=10;i++)
	{
		if(i!=10)
			printf("%d       ", i);
		else	printf("%d      ", i);
		j=1;
		while(1)
		{
			t=name[i][j];
			if(t=='\0')
				break;
			printf("%c",t);
			j++;
		}
		j=12-j;
		for(p=1;p<=j;p++)	printf(" ");
		if((score1[i]+score2[i]+score3[i])/3*3==(score1[i]+score2[i]+score3[i]))
			printf("%d        %d        %d        %d\n",score1[i],score2[i],score3[i],(score1[i]+score2[i]+score3[i])/3);		
		else
			printf("%d        %d        %d        %.5f\n",score1[i],score2[i],score3[i],(float)(score1[i]+score2[i]+score3[i])/3);	
	}
	printf("        average    %.1f      %.1f      %.1f\n", avg1,avg2,avg3);
	printf("        min        %d        %d        %d\n", score1[min1],score2[min2],score3[min3]);
	printf("        max        %d        %d        %d\n", score1[max1],score2[max2],score3[max3]);	
	return 0;
}
