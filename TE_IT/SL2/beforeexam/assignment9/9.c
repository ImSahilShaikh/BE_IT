#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct student
{
	int roll,marks;
	char name[30];
}student;

void createFile()
{
	int fd=open("mydb.dat",O_CREAT|O_WRONLY,0777);
	if(fd==-1)
	{
		printf("\nERROR");
	}
	printf("FILE created successfully!");
}
void insertRecords()
{
	student s;
	printf("\nEnter the roll no:");
	scanf("%d",&s.roll);

	printf("\nEnter the name:");
	scanf("%s",&s.name);
	
	printf("\nEnter marks:");
	scanf("%d",&s.marks);
	
	int fd=open("mydb.dat",O_WRONLY | O_APPEND);
	if(fd<0)
		printf("\nError while inserting records");
	else
	{
		write(fd,&s,sizeof(s));
		printf("Records written");
	}
	close(fd);
}
void display()
{
	student s;
	int fd=open("mydb.dat",O_RDONLY);
	if(fd<0)
		printf("ERROR");
	else
	{
		printf("\nROLL NO\tNAME\tMARKS");
		while(read(fd,&s,sizeof(s)))
		{
			printf("\n%d\t%s\t%d",s.roll,s.name,s.marks);
		}
	}
	close(fd);
}
void search()
{
	int flag=0,key=0;
	student s;
	int fd= open("mydb.dat",O_RDONLY);
	printf("\nEnter a key to be searched");
	scanf("%d",&key);
	if(fd<0)
		printf("ERROR");
	else
	{
		printf("\nROLL NO\tNAME\tMARKS");
		while(read(fd,&s,sizeof(s)))
		{
			if(s.roll == key)
			{
				printf("\n%d\t%s\t%d",s.roll,s.name,s.marks);
				flag=1;
			}
		}
		if(flag==0)
			printf("\nNo data found");
	}
	close(fd);
}
void delete(int key)
{
	
	student s;
	int fd1=open("mydb.dat",O_RDONLY);
	int fd2=open("temp.dat",O_CREAT|O_WRONLY);
	
	if(fd1<0)
	{printf("\nERROR in reading file");}
	else
	{
		while(read(fd1,&s,sizeof(s)))
		{
			if(s.roll==key)
			{
				
			}
			else
				write(fd2,&s,sizeof(s));
		}
	}
	remove("mydb.dat");
	rename("temp.dat","mydb.dat");
	close(fd1);
	close(fd2);
}
void modify(int key)
{
	student s1,s2;
	int fd1=open("mydb.dat",O_RDONLY);
	int fd2=open("temp.dat",O_CREAT|O_WRONLY);
	if(fd1<0)
	{
		printf("\nError in reading file");
	} 	
	else
	{
		while(read(fd1,&s1,sizeof(s1)))
		{
			if(s1.roll!=key)
			{
				write(fd2,&s1,sizeof(s1));
			}
			else
			{
				printf("\nEnter new roll no:");
				scanf("%d",&s2.roll);

				printf("\nEnter new name:");			
				scanf("%s",&s2.name);
	
				printf("\nEnter new marks:");
				scanf("%d",&s2.marks);
				write(fd2,&s2,sizeof(s2));
			}	
		}
	}
	remove("mydb.dat");
	rename("temp.dat","mydb.dat");
	close(fd1);
	close(fd2);
}
int main()
{
	int ch=0,key=0;
	while(1)
	{
		printf("\n-------------------STUDENT DATABASE-------------------");
		printf("\n-------------------------MENU-------------------------");
		printf("\n1.Create File\n2.Insert Records\n3.Display records\n4.Search Records\n5.Modify Record\n6.Delete Records\n7.Delete File\n8.Exit");
		printf("\nINFO: Enter Your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				createFile();
				break;
			case 2:
				insertRecords();
				break;
			case 3:
				display();
				break;
			case 4:				
				search();
				break;
			case 5:
				printf("Enter the roll no you want to modify\n");
				scanf("%d",&key);
				modify(key);
				break;
			case 6:
				
				printf("Enter the roll no you want to delete\n");
				scanf("%d",&key);
				delete(key);
				break;
			case 7:
				remove("student_database.txt");
				printf("\nINFO: FILE DELETED SUCCESSFULLY!!");
				break;	
			case 8:
				exit(0);
			default:
				printf("\nWARNING: Please Enter valid choice!");
		}
	}
}
