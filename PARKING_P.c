#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void login();
void new_vehicle();
void slot();
void bill();

void history();
struct vehicle
{
    int no;               //unique number for every incoming vehicle.
    char vec_num[50]; 
    int hh1,mm1;
    int type;
    int floorNo;
    int slotNo;
    int parked;
}
 s[100];   // array of structure for storing 100 vehicles inforamation.
int slots[5][20]={0};
int i=0;
char date[20];
  void main( )
{
     login();
     int choice;
     while(choice !=4)
     {
     printf("\n*********Main Menu*********\n");
	 printf("\nChoose one option from the following list ...\n");
	 printf("\n===============================================\n");
     printf("1.New vehicle details and parking ticket.\n");
     printf("2.History of vehicle parked today.\n");
     printf("3.Parking exit bill.\n");
     printf("4.Exit\n");
      scanf("%d",&choice);
     switch(choice)
     {
         case 1:
         new_vehicle(); // addition of a new vehicle
         getch();        
         break;
         case 2:
         history();
         break;
         case 3:
         bill();
         break;
         case 4:
         exit(0);
         break;
         default:
		     printf("Please enter valid choice..");
       }
     }

}
	
    void login()
    {
           int x=0;
           char name[50];     
           char password[50];
           char name1[50]="xyz";
           char password1[50]="1234";
           while(x!=1)
   {
      printf("enter the username:\n");
      gets(name);
      printf("enter the password:\n");
       int p=0;
    do
    {
        password[p]=getch(); // to take input password as ******* 
        if(password[p]!='\r')
        { 
            printf("*");
        }
        p++;
    }
    while(password[p-1]!='\r');
    password[p-1]='\0';
      // printf("\nYou have entered %s as password.",password);
      if(strcmp(name,name1) ==0 && strcmp(password,password1)==0)
      {
          printf("\nThe password is correct.");
          x=1;    
          getch(); //holds the screen
      }
      else 
      {
          printf("\n wrong password or username\n");
          printf("Please enter the correct password\n");
           x=0;
      }
   }
system("cls"); //clean the screen 
}
    void new_vehicle()
    {
        int h1,m1;
        int t;
        char number[20];
        printf("Enter the date\n");
        scanf("\n");
        gets(date);
        printf("Enter 1 for bike \n");
        printf("Enter 2 for car \n");
        printf("Enter any number for heavy vehicles\n");
        scanf("%d",&t); 
        s[i].type=t;
        printf("enter the vehicle number :\n");
        scanf("\n");
        gets(number);
        strcpy(s[i].vec_num,number);
        printf("Enter the time of arrival of the vehicle in hh:mm\n");
        scanf("%d %d",&h1,&m1);
        s[i].hh1=h1;
        s[i].mm1=m1;
        s[i].no=i+1;
        system("cls");
          printf("*********PARKING TICKET*********\n");
          printf("\n===============================================\n");
          printf("Sno.%d\n",i+1);
          printf("date-%s",date);
          printf("\n");
          printf("vehicle No-%s\n",number);
          printf("In time of vehicle-\n%d:%d\n",h1,m1);
          int a,b;
       int count=0;
      for(a=0;a<5;a++) // 5floors
      {
        for(b=0;b<20;b++) // 20 slots in each floor
        {
            if(slots[a][b]!=1)
             {
               slots[a][b]=1;
               s[i].floorNo=a+1;
               s[i].slotNo=b+1;
               count++;
               break;
             }
        }
        if(slots[a][b]==1)
        break;
      }
      printf("The vehicle is parked in\nFloor:%d Slot No:%d",a+1,b+1);
    if(count==0)
    printf("\nhere is no vacant space for parking\n");
    s[i].parked=1;
    i++;
    }

    void history()
    {
         system("cls");
         
        printf("SNo\t");
        printf("Date\t\t");
        printf("vehicle number\t\t");
        printf("intime  \t");
        printf("Floor  \t");
        printf("slot   \n");
        for(int a=0;a<i;a++)
        {
           printf("%d\t",a+1);
           printf("%s\t",date);
           printf("%s\t\t",s[a].vec_num);
           printf("%d:%d\t\t",s[a].hh1,s[a].mm1);
           printf("%d\t\t",s[a].floorNo);
           printf("%d\t   ",s[a].slotNo);
           printf("\n");
        }
        getch();
    }
    void bill()
    {
       int min;
       int b1,b2,ho1,mo1;
       int c1,c2;
       float price=0;
       printf("Enter the Serial number of vechile which is getting parked out.\n");
       scanf("%d",&b1);
       b2=b1-1;
       printf("Enter the out time of the %d no vechile in hh:mm\n",b1);
       scanf("%d",&ho1);
       scanf("%d",&mo1);
       printf("%d",s[b2].type);
       if(mo1<s[b2].mm1)
      {
          mo1+=60;
          ho1-=1;
          min=(ho1-s[b2].hh1)*60+(mo1-s[b2].mm1);
      }
      else
      {
          min=(ho1-s[b2].hh1)*60+(mo1-s[b2].mm1);
      }
    if(s[b2].type==1)
    {
      if(min<=60)
      {
        price=10.0;
      }
      else if(min >60 &&min <=300)
      {
        price=0.2*min;
      }
      else
      {
        price=0.15*min;
      }
    }
    else if(s[b2].type==2)
    {
          if(min<=60)
      {
         price=20.0;
      }
      else if(min >60 && min <=300)
      {
        price=0.3*min;
      }
      else
      {
        price=0.25*min;
      }
    }
    else
      {   if(min<=60)
      {
         price=25.0;
      }
      else if(min >60 && min <=300)
      {
        price=0.4*min;
      }
      else
      {
        price=0.35*min;
      }

    }
        system("cls");
        printf("\t\t*********PARKING BILL*********\n");
        //Printf("\t\t\tSno-%d\n",s[b2].no);
        printf("\t\tVechile No-%s\n",s[b2].vec_num);
        printf("\t\tIn time-%d:%d\n",s[b2].hh1,s[b2].mm1);
        printf("\t\tOut time-%d:%d\n",ho1,mo1);
        printf("\t\tThe vehicle was parked for %d minutes\n",min);
        printf("\t\tBill amount-Rs.%.2f\n",price);
           int del1=s[b2].floorNo-1;
           int del2=s[b2].slotNo-1;
           slots[del1][del2]=0;
           // printf("%d",slots[del1][del2]);
           
        getch();
    }