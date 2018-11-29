#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int counter=0;

//structure
char filename[50];
struct Student
{
	char name[100];
	int roll;
	int maths;
	int comp;
	int eng;
	int ele;
	int chem;
	int evs;
	int total;
	float per;
	int rank;
}s[100];
//function to sort the array
int sort()
{
	int i, pos, max, j, t, m, c, e, el, ch, ev;
	float p;
	char n[20];
	for(i=0;i<counter-1;i++)
	{
		max=s[i].total;
		pos=i;
		for(j=i+1;j<counter;j++)
		{
			if(s[j].total>max)
			{
				max=s[j].total;
				pos=j;
			}
		}
		t=s[i].total;
		s[i].total=s[pos].total;
		s[pos].total=t;
		
		m=s[i].maths;
		s[i].maths=s[pos].maths;
		s[pos].maths=m;
		
		c=s[i].comp;
		s[i].comp=s[pos].comp;
		s[pos].comp=c;
		
		e=s[i].eng;
		s[i].eng=s[pos].eng;
		s[pos].eng=e;
		
		el=s[i].ele;
		s[i].ele=s[pos].ele;
		s[pos].ele=el;
		
		ch=s[i].chem;
		s[i].chem=s[pos].chem;
		s[pos].chem=ch;
		
		ev=s[i].evs;
		s[i].evs=s[pos].evs;
		s[pos].evs=ev;
		
		p=s[i].per;
		s[i].per=s[pos].per;
		s[pos].per=p;
		
		strcpy(n,s[i].name);
		strcpy(s[i].name,s[pos].name);
		strcpy(s[pos].name,n);
	}
}
//function to perform operations of adminstrator
int admin()
{
	int i,j,limit;
	char c;
	FILE *ft;
	FILE *fs;
	for(i=0;i<100;i++)
	{
		printf("Enter the name of the student : ");
		gets(s[i].name);
		printf("Enter the enrollment number of the student : ");
		scanf("%d",&s[i].roll);
		printf("Enter the marks obtained by the student in mathematics : ");
		scanf("%d",&s[i].maths);
		printf("Enter the marks obtained by the student in computer science : ");
		scanf("%d",&s[i].comp);
		printf("Enter the marks obtained by the student in english : ");
		scanf("%d",&s[i].eng);
		printf("Enter the marks obtained by the student in electronics : ");
		scanf("%d",&s[i].ele);
		printf("Enter the marks obtained by the student in chemistry : ");
		scanf("%d",&s[i].chem);
		printf("Enter the marks obtained by the student in enviromental studies : ");
		scanf("%d",&s[i].evs);
		s[i].total=s[i].maths+s[i].comp+s[i].eng+s[i].ele+s[i].chem+s[i].evs;
		s[i].per=(float)s[i].total/6;
		counter++;
		
		printf("\nAre you completed with the Enteries?");
		printf("\nIF YES PLEASE ENTER 0 & IF NOT YOU CAN ENTER ANY INTEGAR : ");
		scanf("%d",&limit);
		if(limit==0)
		{
			break;
		}
		printf("\n\n");
		scanf("%c",&c);
	}
	sort();
	for(j=0;j<counter;j++)
	{
		s[j].rank=j+1;	
		
		sprintf(filename,"%d",s[j].roll);
		fs=fopen(strcat(filename,".doc"),"w");
		fprintf(fs," WELCOME %s \n\n\n\n",s[j].name);
		fprintf(fs,"MATHEMATICS = %d\n",s[j].maths);
		fprintf(fs,"ELECTRONICS = %d\n",s[j].ele);
		fprintf(fs,"CHEMISTRY = %d\n",s[j].chem);
		fprintf(fs,"COMMPUTER SCIENCE = %d\n",s[j].comp);
		fprintf(fs,"ENVIROMENTAL STUDIES = %d\n",s[j].evs);
		fprintf(fs,"ENGLISH = %d\n\n",s[j].eng);
		fprintf(fs,"TOTAL = %d\n",s[j].total);
		fprintf(fs,"PERCENTAGE = %f\n",s[j].per);
		fprintf(fs,"RANK : %d\n",s[j].rank);
		
		ft=fopen("TEACHER.doc","a+");
		if(j==0)
		{
			fputs(" WELCOME SIR/MADAM \n\n\n\n",ft);
		}
		fprintf(ft,"NAME : %s\n",s[j].name);
		fprintf(ft,"MATHEMATICS = %d\n",s[j].maths);
		fprintf(ft,"ELECTRONICS = %d\n",s[j].ele);
		fprintf(ft,"CHEMISTRY = %d\n",s[j].chem);
		fprintf(ft,"COMMPUTER SCIENCE = %d\n",s[j].comp);
		fprintf(ft,"ENVIROMENTAL STUDIES = %d\n",s[j].evs);
		fprintf(ft,"ENGLISH = %d\n\n",s[j].eng);
		fprintf(ft,"TOTAL = %d\n",s[j].total);
		fprintf(ft,"PERCENTAGE = %f\n",s[j].per);
		fprintf(ft,"RANK : %d\n\n\n\n",s[j].rank);		
		fclose(fs);
		fclose(ft);
	}
	printf("\nTHANKS! IT WOULD DEFENITELY HELP A NUMBER OF STUDENTS.\n\n");
	main();
}
//function to perform operations of teacher
int teacher()
{
	FILE *f;
	printf("	WELCOME SIR/MADAM	\n");
	int pass;
	printf("Enter the passcode : ");
	scanf("%d",&pass);
	if(pass==1234)
	{
		printf("ACCESS GRANTED!\n");
		f=fopen("TEACHER.doc","r");
		if(f == NULL)
		{
			printf("SORRY BUT THE RESULT HAS NOT YET BEEN UPDATED.");
		}
		else
		{
			char line[200];
			while(fgets(line,200,f)!=NULL)
			{			
				printf("%s ",line);
			}
			fclose(f);
		}
		
	}
	else
	{
		printf("HACKING IS NOT GRANTED ON THIS DATABASE!");
	}
}
//function to perform operations of a student
int student()
{
	FILE *f;
	int roll,i,check=0;
	printf("Enter your enrollment number : ");
	scanf("%d",&roll);
	sprintf(filename,"%d",roll);
	f=fopen(strcat(filename,".doc"),"r");
	if(f == NULL)
	{
		printf("YOU DON'T SEEM TO BE A STUDENT OF HERE\n");
		printf("EITHER THE ENROLLMENT NUMBER ENTERED IS WRONG OR THE RESULT HAS NOT YET BEEN UPDATED.");
	}
	else
	{
		char line[200];
		while(fgets(line,200,f)!=NULL)
		{			
			printf("%s ",line);
		}
		fclose(f);
	}
}
//main function
int main()
{
	int n;
	char s;
	printf("ENTER : \n");
	printf("		1 if you are the administrator\n");
	printf("		2 if you are a teacher\n");
	printf("		3 if you are a student\n");
	scanf("%d",&n);
	scanf("%c",&s);
	switch(n)
	{
		case 1 : admin();
				 break;
		case 2 : teacher();
				 break;
		case 3 : student();
				 break;
		default : printf("ARE YOU AN IDIOT?\n");
				  printf("SEE THE INPUT YOU ENTERED!\n");
	}
	printf("\n\n\n");	
}
