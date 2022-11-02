#include<stdio.h>
#include<windows.h>
#include<conio.h>
void message();
void mainmenu();
void add();
void search();
void view();
void delete();
void updatepassword();
void message1();
void login();
int isValidDate(int ,int ,int );
int isValidName(char []);
COORD coord={0,0};
struct date
{
	int day;
	int mon;
	int year;
};
typedef struct credentials
{
	char username[30];
	char password[20];
}credentials;
typedef struct student
{
	int bid;
	char bname[30];
	char bauthor[30];
	char sname[30];
	struct date d;
}student;
void gotoxy(int x,int y)
{
	coord.X=x;//x==columns and y==rows 
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
credentials s={"godugushruthi","shruthi@lbs"};
void main()
{
	message();
	//mainmenu();
}
void mainmenu()
{
	/*system("cls");
    gotoxy(40,3);
    printf("*********************************************************************************************************************************************");
    gotoxy(40,5);
	printf("************************************                                                                 ****************************************");
    gotoxy(40,7);
	printf("************************************                                                                 ****************************************");
	gotoxy(40,9);
	printf("************************************                  LIBRARY MANAGEMENT SYSTEM  IN C                ****************************************");
    gotoxy(40,11);
	printf("************************************                                                                 ****************************************");
    gotoxy(40,13);
	printf("************************************                                                                 ****************************************");
	gotoxy(40,15);
	printf("*********************************************************************************************************************************************"); */
	message1();
    gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                              MAIN MENU                                                                      ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");   
	char key;
	gotoxy(47,25);
	printf("1.Add Books");
	gotoxy(47,27);
	printf("2.Search Books");
	gotoxy(47,29);
	printf("3.View Books");
	gotoxy(47,31);
	printf("4.Delete Book");
	gotoxy(47,33);
	printf("5.Update Password");
	gotoxy(47,35);
	printf("6.Exit");
	gotoxy(47,37);
	printf("enter your choice : ");
	key=getch();
	switch(key)
	{
		case '1':add();
		         break;
		case '2':search();
		         break;
		case '3':view();
		         break;
		case '4':delete();
	             break;
		case '5':updatepassword();
		         break;
		case '6':exit(0);
		         break;
		default:gotoxy(47,40);
		        printf("incorrect input please enter any option to continue ............");
				if(getch())
				  mainmenu();		 		 		 			          	         
	}
}
void message()
{
	gotoxy(50,3);
    printf("************************************************************************************************************");
    gotoxy(50,5);
	printf("************************************************************************************************************");
    gotoxy(50,7);
	printf("************************************************************************************************************");
	gotoxy(50,9);
	printf("************************************************************************************************************");
	gotoxy(50,11);
	printf("************************************               WELCOME             *************************************");
	gotoxy(50,13);
	printf("************************************                 TO                *************************************");//	printf("***********   WELCOME TO LIBRARY MANAGEMENT   **********");
    gotoxy(50,15);
    printf("************************************               LIBRARY             *************************************");//	printf("***********                                   **********");
	gotoxy(50,17);
	printf("************************************              MANAGEMENT           *************************************");//printf("********************************************************");
	gotoxy(50,19);
	printf("************************************                SYSTEM             *************************************");//printf("********************************************************");
	gotoxy(50,21);	
	printf("************************************************************************************************************");//printf("********************************************************");
	gotoxy(50,23);
    printf("************************************************************************************************************");//printf("********************************************************");
    gotoxy(50,25);
    printf("************************************************************************************************************");
    gotoxy(50,27);
    printf("************************************************************************************************************");
    gotoxy(50,30);
    printf("enter any key to continue.......");
	sleep(5);
    if(getch())
    {
    	login();//mainmenu();
	}
}
void add()
{
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                               ADD NEW BOOKS                                                                 ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");  
	gotoxy(40,24);
	printf(" ENTER YOUR DETAILS BELOW:                                                                                                                   ");
	gotoxy(40,25);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");    
	int i,c,n;
	FILE *fp;
	fp=fopen("newarticlestudent.txt","w");
	if(fp==NULL)
	{
		//gotoxy(40,26);
		printf("\n\n\t\t\t\t\terror in file opening\n");
	}
	//gotoxy(40,27);
	printf("\n\n\t\t\t\t\tenter no of records to be inserted : ");
	scanf("%d",&n);
	student *s;
	s=(student*)calloc(n,sizeof(student));
	for(i=0;i<n;i++)
	{
		//gotoxy(40,29);
		printf("\n\t\t\t\t\tenter book id: ");
		scanf("%d",&s[i].bid);
		fflush(stdin);
		do{
		//gotoxy(40,31);	
		printf("\n\t\t\t\t\tenter book name: ");
		fflush(stdin);
		scanf("%[^\n]s",s[i].bname);
	    }
	    while(isValidName(s[i].bname)!=1);
		do{
		//gotoxy(40,33);	
		printf("\n\t\t\t\t\tenter book author: ");
		fflush(stdin);
		scanf("%[^\n]s",s[i].bauthor);
	    }
	    while(isValidName(s[i].bauthor)!=1);
		do{
		//gotoxy(40,35);	
		printf("\n\t\t\t\t\tenter student name: ");
		fflush(stdin);
		scanf("%[^\n]s",s[i].sname);
	    }
	    while(isValidName(s[i].sname)!=1);
	    do{
	    //gotoxy(40,37);	
		printf("\n\t\t\t\t\tenter date in format(day/month/year): ");
		scanf("%d/%d/%d",&s[i].d.day,&s[i].d.mon,&s[i].d.year);
	    }
	    while(isValidDate(s[i].d.day,s[i].d.mon,s[i].d.year)!=1);
		fwrite(&s[i],sizeof(struct student),1,fp);
	}
	fclose(fp);
	printf("\n\t\t\t\t\tPress any Key to Continue........");
	if(getch())
	{
		mainmenu();
	}
}
void search()
{
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                             SEARCH BOOKS                                                                    ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------"); 
    student s1;
	int i,id,c=0;
	FILE *fp;
	char bookname[30];
	fp=fopen("newarticlestudent.txt","r");
	if(fp==NULL)
	{
		printf("\n\t\t\t\t\t\t \n");
	}
	printf("\n\n\t\t\t\t\t\tEnter Book Name to search :");
	fflush(stdin);
	scanf("%[^\n]s",bookname);
    while(fread(&s1,sizeof(student),1,fp))
	{
	 if(strcmp(s1.bname,bookname)==0)
	 {
	    c=1; 
	   	printf("\n\t\t\t\t\t\tBook id = %d",s1.bid);
		printf("\n\t\t\t\t\t\tBook name = %s",s1.bname);
		printf("\n\t\t\t\t\t\tBook authorName = %s",s1.bauthor);
		printf("\n\t\t\t\t\t\tBook issue date(day/month/year) = %d/%d/%d\n",s1.d.day,s1.d.mon,s1.d.year);
		break;
	   //printf("%d       %d        %s        %s         %d         %d\n",s1.sid,s1.bid,s1.bname,s1.bauthor,s1.cost,s1.t_books);
	 }
    }
    if(c==0)
    {
    	printf("\n\t\t\t\t\t\tBook not found\n");
	} 
	fclose(fp);
	printf("\n\t\t\t\t\t\tPress any Key to Continue........");
	if(getch())
	{
		mainmenu();
	}  
}
void view()
{
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                              VIEW BOOKS                                                                     ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");  
	student s1;
	FILE *fp;
	int i,count=0;
	fp=fopen("newarticlestudent.txt","r");
	//printf("\n\t\t\t\t\tin view function");
	if(fp==NULL)
	{
		printf("\n\n\t\t\t\t\t \n");
	}
	while(fread(&s1,sizeof(student),1,fp))
	{
		//printf("\n\t\t\t\t\tin read function");
		count++;
		printf("\n\n\t\t\t\t\t\tBook Count = %d\n",count);
		printf("\n\t\t\t\t\t\tBook id = %d",s1.bid);
		printf("\n\t\t\t\t\t\tBook name = %s",s1.bname);
		printf("\n\t\t\t\t\t\tBook authorName = %s",s1.bauthor);
		printf("\n\t\t\t\t\t\tBook issue date(day/month/year) = %d/%d/%d\n",s1.d.day,s1.d.mon,s1.d.year);
	    //printf("%d       %s        %s     %d/%d/%d\n",s1.bid,s1.bname,s1.bauthor,s1.d.day,s1.d.mon,s1.d.year);
	} 
	if(count==0)
	{
		printf("\n\n\t\t\t\t\t\tNo Records.\n");
	}
	fclose(fp);
	printf("\n\t\t\t\t\t\tPress any Key to Continue........");
	if(getch())
	{
		mainmenu();
	} 
}
void delete()
{
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                             DELETE BOOKS                                                                    ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");    
	student s1;
	int i,id,c=0;
	FILE *fp,*fp1;
	fp=fopen("newarticlestudent.txt","r");
	fp1=fopen("newarticletemp.txt","w");
	if(fp==NULL)
	{
		printf("\n\t\t\t\t\t\t \n");
	}
	printf("\n\n\t\t\t\t\t\tEnter Book Id you want to Delete : ");
	scanf("%d",&id);
    while(fread(&s1,sizeof(student),1,fp))
	{
	 if(s1.bid==id)
	 {
	   	 	c=1;
	 }
	 else
	     fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(c==1)
    {
      fp1=fopen("newarticletemp.txt","r");
	  fp=fopen("newarticlestudent.txt","w");
	   while(fread(&s1,sizeof(student),1,fp1))
	   {
	     fwrite(&s1,sizeof(student),1,fp);	
	   }	
	  fclose(fp);
      fclose(fp1);
	}   
	else
	  printf("\n\t\t\t\t\t\tBook Not Found \n");
	printf("\n\t\t\t\t\t\tPress any Key to Continue........");
	if(getch())
	{
		mainmenu();
	}   
}
void updatepassword()
{
	credentials s;
	char un[30],pwd[20];
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                         UPDATE CREDENTIALS                                                                  ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");    
    printf("\n\n\t\t\t\t\t\tEnter Username : ");
	fflush(stdin);
	scanf("%[^\n]s",un);
	printf("\n\n\t\t\t\t\t\tEnter Password : ");
	fflush(stdin);
	scanf("%[^\n]s",pwd);
	strcpy(s.username,un);
	strcpy(s.password,pwd);
	printf("\n\n\t\t\t\t\t\tYour Password has been changed successfully\n");
	printf("\n\n\t\t\t\t\t\tLogin Again\n");
	sleep(2);
	login();
}
void message1()
{
	system("cls");
	gotoxy(40,3);
    printf("*********************************************************************************************************************************************");
    gotoxy(40,5);
	printf("************************************                                                                 ****************************************");
    gotoxy(40,7);
	printf("************************************                                                                 ****************************************");
	gotoxy(40,9);
	printf("************************************                  LIBRARY MANAGEMENT SYSTEM  IN C                ****************************************");
    gotoxy(40,11);
	printf("************************************                                                                 ****************************************");
    gotoxy(40,13);
	printf("************************************                                                                 ****************************************");
	gotoxy(40,15);
	printf("*********************************************************************************************************************************************");	
}
void login()
{
	message1();
	gotoxy(40,18);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");
	gotoxy(40,20);
	printf("                                                                  LOGIN                                                                      ");
	gotoxy(40,22);
	printf("---------------------------------------------------------------------------------------------------------------------------------------------");    
    //credentials s;
    int c=0;
    char un[30],pwd[10];
     FILE *fp;
	fp=fopen("newarticlestudentcredentials.txt","w");
	if(fp==NULL)
	{
		//gotoxy(40,26);
		printf("\n\n\t\t\t\t\terror in file opening\n");
	}
	
	do{
	printf("\n\n\t\t\t\t\t\tEnter Username : ");
	fflush(stdin);
	scanf("%[^\n]s",un);
	printf("\n\n\t\t\t\t\t\tEnter Password : ");
	fflush(stdin);
	scanf("%[^\n]s",pwd);
	if((strcmp(s.username,un)==0)&&(strcmp(s.password,pwd)==0))
	{
		c=1;
		mainmenu();
	}
	else
	{
		printf("%s,%s",un,pwd);
		printf("\n\n\t\t\t\t\t\tIncorrect Credentials Please Enter Again.....\n");
		sleep(2);
		login();
	}
    }
    while(c!=1);
}
int isValidDate(int date,int mon,int year)
{
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int l=0,d=month[mon-1];
     if (year % 400 == 0) 
       l=1;
     else if (year % 100 == 0)
       l=0;
     else if (year % 4 == 0)
       l=1;
     else 
       l=0;
    if(mon<=12&&mon>=1)
    {
        if(l==1&&mon==2)
        {
          d=d+1;
        }  
        if(date<=d)
        {    
          return 1;
        }  
         else
        {
          printf("\n\t\t\t\t\tplease enter a valid date\n");    
          return 0;
        } 
    }
    else 
    {
      printf("\n\t\t\t\t\tplease enter a valid month\n");
      return 0;
    } 
}
int isValidName(char s[])
{	
    int i,c=0;
    for(i=0;i<strlen(s);i++)
    {
        if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
          c=1;
        else
        {
          //gotoxy()	
          printf("\n\t\t\t\t\tentered name contains special characters,please enter again\n");
          return 0;
       }
    }
    if(c==1)
     return 1;
}
