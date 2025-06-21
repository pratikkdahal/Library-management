/*we are going to make a project on library managementsystem */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
/* lets declare global structure variable as:*/
struct books
{
	int book_id;
	char book_name[30];
	char author_name[50];
	int price;
	char reader[30];
	// you can add other member as per your need here
}lib[300];

int main()
{
//	FILE *fp, ft;
	//char next, choice;
	long int resize;
	printf( "\t \t \t \t...... Library record management system.......\n");
	printf( "=========================================================================================================");
	cases();
	getch();
}
int cases()                                                               
{
	char choice, yr;
	system("cls");
	// you can create main manu such as add record display edit delete and exit
	label:
	printf("[1] to add Record \n");
	printf("[2] to Display \n");
	printf("[3] to Delete \n");
	printf("[4] to exit \n");
	printf("please enter one of the above number to make your choice \n");
	choice=getche();
	fflush(stdin);
	switch(choice)
	{
	case '1':
		add();
		printf("enter y to repeat");
		scanf("%s",&yr);
		if(yr=='y')
		goto label;
		break;
	case '2':
		display();
		printf("enter y to repeat");
		scanf("%s",&yr);
		if(yr=='y')
		goto label;
		break;
	case '3':
		del();
		printf(" \n enter y to repeat");
		scanf("%s",&yr);
		if(yr=='y')
		goto label;
		break;
	case '4':
		Exit();
		break;	
	}
	return 0;
}

/*here we wrire code to add record*/
int add()
{
	int i,n;
	FILE *fp;

	fp=fopen("library_rec.txt","a");
	printf("how many books record you want: ");
	scanf("%d",&n);
for(i=0; i<n; i++)
{
printf("\n enter book id: ");
scanf("%d",&lib[i].book_id);
printf("\n enter book name: ");
scanf("%s",lib[i].book_name);
printf("\n enter author name: ");
scanf("%s",lib[i].author_name);
printf("\n enter price: ");
scanf("%d",&lib[i].price);
printf("\n enter reader name: ");
scanf("%s",lib[i].reader);
fprintf(fp,"\n %d \t %s \t %s \t %d \t %s",lib[i].book_id,lib[i].book_name,lib[i].book_name,lib[i].price,lib[i].reader);
}
fclose(fp);
return 0;
}
// to display
int display()
{
FILE *fp;
int book_id;
char book_name[30];
char author_name[50];
int price;
char reader[30];
fp=fopen("library_rec.txt","r");
printf("\n \t book_id \t book_name \t author_name \t price \t reader");
while(fscanf(fp,"%d%s%s%d%s",&book_id,book_name,author_name,&price,&reader)!=EOF)
{
	printf("\n \t %d \t %s \t %s",book_id,book_name,author_name,price,reader);
}
fclose(fp);
return 0;
	/*printf("\n please write a code to display the content in file");
	return 0;*/
}

int del()
{
	//printf("\n please write a code to display the content in file");
FILE *f;
FILE *fp;
int dn;
	int book_id;
	char book_name[30];
	char author_name[50];
    int price;
    char reader[30]; 
	printf("enter the book_no for deleting the file");
	scanf("%d",&dn);
	fp=fopen("library_rec.txt","r");
	while
	(fscanf(fp,"%d%s%d",&book_id,book_name,author_name,price,&reader)!=EOF)
	{
		if(book_id!=dn)
		{
		f=fopen("lib_record.txt","a");
		fprintf(f,"%d%s%d",book_id,book_name,author_name,price,reader);
		fclose(f);
	}
}fclose(fp);
printf("\n data deleted");
remove("library_rec.txt");
rename("lib_record.txt","rec.txt");
	return 0;
}
int Exit()
{
	printf("\n Thank you for performing operation on the content in file");
	return 0;
}
