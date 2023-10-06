
//rail way reservation project by using c programming language
//header file
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
//user define function 
void admin_T4TutorialsDotCom();
void Security();
void WriteTicketBooking();
void write();
void read();
void DetailsView();
void TicketBooking();
void TicketCancellation();
void PassengerListView();
void Insert_NewTrain();
void Delete_ExistingTrain();
void PassengerListViews_read();
//structure 
struct adddata
{
	
	char destination[10];
	char si[10];
	char NameOfTrain[20];
	char TrainIdentity[10];
	char start[10];
	char TicketPrice[10];
	int seat;
	char time[10];
} add[1000];
struct TicketBooking
{
	char TrainIdentity[20];
	char name[20];
	char phone[20];
	char date[20];
	int seat;
}book[1000];
//global variable
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
int main()
{
	read();
	PassengerListViews_read();
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t     %s\n",ctime(&currentTime));
	
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM Project in C++^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t*********************************\n");
	printf("\n\t\t\tWELCOME USERS>>>>>>>>>>\n");
	printf("\n\n\t\t\t\t      MENU\n");
	printf("\t\t\t             ******");
	printf("\n\t\t\t(1) VIEW INFORMATION\n\n");
	printf("\n\t\t\t(2) BOOK TICKET\n\n");
	printf("\n\t\t\t(3) CANCEL TICKET\n\n");
	printf("\n\t\t\t(4) admin_T4TutorialsDotCom");
	printf("\n\n\t\t\t(5) EXIT\n\n");
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t\t Please ENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			DetailsView();
			break;
			case 2:
				TicketBooking();
				break;
				case 3:
					TicketCancellation();
					break;
					case 4:
						Security();
						break;
						case 5:
							system("cls");
							printf("\n\t\t\t ^^^^^^^^^^^^^^^^^^^^^\n");
							printf("\t\t\t ^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM^^^^^^^^^^^^^^^^^^^^^\n");
							printf("\t\t\t ^^^^^^^^^^^^^^^^^^^^^\n");
							getch();
							exit(0);
							break;
							default:
								system("cls");
								printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
								printf("\t\t\t   ^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM IN C++^^^^^^^^^^^^^^^^^^^^^\n");
								printf("\t\t\t  ^^^^^^^^^^^^^^^^^^^^^\n");
								printf("\n\n\t\t\t<<<Sorry YOU ENTERED WRONG CHOICE>>>>>>>>\n");
								printf("\t\t\t<<<Hello! PLEASE ENTER the suitable choice>>>>>>>>\n");
								getch();
								system("cls");
								main();
	}
	return 0;
}
//book ticket function
void TicketBooking()
{
	int c,j,n,i,found=-1;
	char v,TrainIdentity[10];
	system ("cls");
	read();
	printf("\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\n\t\t\total number of tickets you want to buy? ");
	scanf("%d",&n);
	for(j=u;j<u+n;j++)
	{
	printf("\n\n\t\t\tEnter train number: ");
	scanf("%s", book[j].TrainIdentity);
	for(i=0;i<k;i++)
	{
	if(strcmp(book[j].TrainIdentity,add[i].TrainIdentity)==0)
	{
	if(add[i].seat==0)
	{
		printf("\n\n\t\t\tSorry! no seat available");
		
		getch();
		system("cls");
		main();
	}
	else
	{
	    found=1;
		printf("\n\t\t\tenter book %d no ticket: ",j+1);
		printf("\n\t\t\tenter date: ");
		scanf("%s",book[j].date);
		printf("\n\t\t\tenter your name: ");
		scanf("%s",book[j].name);
		printf("\n\t\t\tenter your phone number: ");
		scanf("%s",book[j].phone);
		printf("\n\t\t\tseat number is: %d",add[i].seat );
		book[j].seat=add[i].seat;
		WriteTicketBooking();
		add[i].seat--;
		write();
		}
	}
}
	if(found==-1)
	{
		printf("\n\n\t\t\ttrain not found. Sorry!");
		getch();
		system("cls");
		main();
	}
 
	}
		u=j;
		WriteTicketBooking();
		printf("\n\n\t\t\tpress '1' for main menu & press any key to exit: ");
		scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				main();
			}
			if(c!=1)
			{
				exit;
			}			
}
//cancel ticket function
void TicketCancellation()
{
	PassengerListViews_read();
    char pnnmbr[100];
    int location = -1,e;
    printf ("\n\n\t\t\tPlease enter phone number: ");
    scanf ("%s",pnnmbr);
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<Data Not Found^^^^^^^^^^^^^^^^^^^^^ \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e=location;e<u;e++)
        {
            strcpy(book[e].date,book[e+1].date);
            strcpy(book[e].TrainIdentity,book[e+1].TrainIdentity);
            strcpy(book[e].name,book[e+1].name);
            strcpy(book[e].phone,book[e+1].phone);
            WriteTicketBooking();
        }
        u--;
        WriteTicketBooking();
        printf("\n\n\t\t\tticket cancelled successfully>>>>>>>>>>>>");
        getch();
        system("cls");
        main();
    }
}
//admin_T4TutorialsDotCom portal function
void admin_T4TutorialsDotCom()
{
	int chhh;
	system("cls");
	printf("\n     ==================================================================");
	printf("\n     ********************RAILWAY RESERVATION SYSTEM*******************");
	printf("\n     ====================================================================");
	printf("\n\n");
	printf("           WELCOME_admin_T4TutorialsDotCom>>>>>>>>>>>>>>>\n");
	printf("\n\n");
	printf("              ************************************\n");
	printf("              ||      CHOOSE YOUR OPERATION     ||\n");
	printf("              ||--------------------------------||\n");
	printf("              ||      [1] VIEW PASSENGERS       ||\n");
	printf("              ||      [2] ADD TRAIN             ||\n");
	printf("              ||      [3] DELETE TRAIN          ||\n");
	printf("              ||      [4] BACK                  ||\n");
	printf("              ||                                ||\n");
	printf("              ************************************\n\n");
	printf("     **********************************************************\n");
	printf("\n\t\tENTER YOUR CHOICE: ");
	scanf("%d",&chhh);
 
	switch(chhh)
	{
		case 1:
			PassengerListView();
			break;
			case 2:
				Insert_NewTrain();
				break;
				case 3:
					Delete_ExistingTrain();
					break;
					case 4:
						system("cls");
						getch();
						main();
						break;
						default:
							getch();
							printf("\n\t\t\tyou entered wrong KEY!!!!");
							getch();
							system("cls");
							main();
	}
	getch();
}
//Security function
void Security()
{
	int number=1234567;
	int pass;
	printf("\n\t\t\tenter Security: ");
	scanf("%d",&pass);
	if(pass==number)
	{
		printf("\n\n\t\t\tlogin successfully^^^^^^^^^^^^^^^^^^^^^");
		getch();
		system("cls");
		admin_T4TutorialsDotCom();
	}
	else
	{
		printf("\n\n\t\t\t\t   ERROR!!!!!");
		printf("\n\n\t\t\t<<<wrong Security^^^^^^^^^^^^^^^^^^^^^");
		getch();
		system("cls");
		main();
	}
}
//delete train function
void Delete_ExistingTrain()
{
	read();
    char train[100];
    int location = -1,f;
    printf ("\n\n\tenter train number: ");
    scanf ("%s",train);
    for (f=0;f<k;f++)
    {
        if (strcmp(train,add[f].TrainIdentity)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t^^^^^^^^^^^^^^^^^^^^^Data Not Found>^^^^^^^^^^^^^^^^^^^^^ \n");
        getch();
        system("cls");
        admin_T4TutorialsDotCom();
    }
    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].TrainIdentity,add[f+1].TrainIdentity);
            strcpy(add[f].NameOfTrain,add[f+1].NameOfTrain);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].TicketPrice,add[f+1].TicketPrice);
 
            strcpy(add[f].time,add[f+1].time);
            write();
        }
        k--;
        write();
		printf("\n\n\t^^^^^^^^^^^^^^^^^^^^^train deleted successfully^^^^^^^^^^^^^^^^^^^^^");
		getch();
		system("cls");
		admin_T4TutorialsDotCom();
    }
}
//view passengers function
void PassengerListView()
{
	int a,j;
	system("cls");
	PassengerListViews_read();
	printf("\n\t\t\t       ^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t\t       ^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t\t      ^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\n\t\t\ttrain number\t\tname\t\tphone number\t\tdate\t\tseat\n");
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
	for(j=0;j<u;j++)
	{
		printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d",book[j].TrainIdentity,book[j].name,book[j].phone,book[j].date,book[j].seat);
		book[j].seat++;
	}
	printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		main();
	}
	if(a==0)
	{
		system("cls");
		admin_T4TutorialsDotCom();
	}
}
//book ticket file start
void WriteTicketBooking()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);
 
	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
//add train function
void Insert_NewTrain()
{
	system("cls");
	int ch;
	read();
	int i,a;
	printf("\n\t\t     ^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t     ^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\t\t     ^^^^^^^^^^^^^^^^^^^^^");
	printf("\n\n\t\t\thow many trains do you want to add: ");
	scanf("%d",&a);
	for(i=k;i<k+a;i++)
	{
		printf("\n\t\t\tenter %d train details: ",i+1);
		printf("\n\t\t\tenter serial number: ");
		scanf("%s",add[i].si);
		printf("\n\t\t\tenter train number: ");
		scanf("%s",add[i].TrainIdentity);
		printf("\n\t\t\tenter train name: ");
		scanf("%s",add[i].NameOfTrain);
		printf("\n\t\t\tenter start place: ");
		scanf("%s",add[i].start);
		printf("\n\t\t\tenter destination place: ");
		scanf("%s",add[i].destination);
		printf("\n\t\t\t enter TicketPrice: ");
		scanf("%s",add[i].TicketPrice);
		printf("\n\t\t\t enter seat: ");
		scanf("%d", & add[i].seat);
		printf("\n\t\t\t enter time: ");
		scanf("%s",add[i].time);
	}
 
		printf("\n\n\t\t\tconfirm train: (y=1/n=0):- ");
		scanf("%d",&ch);
		if(ch==1)
		{
			write();
			k=i;
			write();
			system("cls");
			printf("\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^");
			printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^RAILWAY RESERVATION SYSTEM in c++");
			printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^");
			printf("\n\n");
			printf("\n\t\t\t\t  ^^^^^^^^^^^^^^^^^^^^^");
			printf("\n\t\t\t\t   *train add successfully>>>>>*");
			printf("\n\t\t\t\t   ^^^^^^^^^^^^^^^^^^^^^");
			getch();
			system("cls");
			main();
		}
			if(ch==0)
			{
				system("cls");
				admin_T4TutorialsDotCom();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main();
			}
}
//view information function
void DetailsView()
{
	int ch,i;
	system("cls");
	read();
	printf("\n\n\n    SI\ttrain number\ttrain name\tstart place\tdestination place\tTicketPrice\tseat\ttime\n\n");
	for(i=0;i<k;i++)
	{
		printf("    %s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%d\t%s\n",add[i].si,add[i].TrainIdentity,add[i].NameOfTrain,add[i].start,add[i].destination,add[i].TicketPrice,add[i].seat,add[i].time);
	}
	printf("\n\t\t\tpress '1' for main menu & press any key for exit:  ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");
			main();
			break;
				default:
					exit(0);
	}
}
 
void PassengerListViews_read()
{
	
 
	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book,sizeof(book),1,booklist);
	fclose(booklist);
}
void read()
{
	FILE *Train_File;
	Train_File = fopen("Train_File.txt","r");
	fread(&add,sizeof(add),1,Train_File);
	fclose(Train_File);
 
	FILE *ReportFile;
	ReportFile = fopen("ReportFile.txt","r");
	fread(&k,sizeof(k),1,ReportFile);
	fclose(ReportFile);
}
void write()
{
	
 
	FILE *ReportFile;
	ReportFile = fopen("ReportFile.txt","w");
	fwrite(&k,sizeof(k),1,ReportFile);
	fclose(ReportFile);
	FILE *Train_File;
	Train_File = fopen("Train_File.txt","w");
	fwrite(&add,sizeof(add),1,Train_File);
	fclose(Train_File);
}
