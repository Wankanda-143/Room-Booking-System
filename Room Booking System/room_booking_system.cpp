#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

static int p = 0;

class rooms{
  char roomn[5], host[10], start[6], send[6], from[11], to[11], chair[2][5][10];
public:
  void book();
  void allotCh();
  void open();
  void show();
  void displayRoomAllot();
  void emptyRoom();
  void modifyAllot();
}room[10];


void vline(char ch){         
  for (int i=100;i>0;i--)
  cout<<ch;
  cout<<"\n";
}


void rooms::book(){    //Books room for host
 again:
 char k[5],ch;
 cout<<"\nEnter Room no: ";        //Gets input from Host
 cin>>k;

  int n;

  for(n=0;n<=p;n++)      //To make sure a booked room is not rebooked
  {
    if(strcmp(room[n].roomn,k)==0)               
    { cout<<"We are sorry to inform you that the requested room is occupied\n";
      cout<<"Please select another room\n";
      cout<<"You can also look through the allotment to know which rooms are empty\n\n";

      cout<<"Enter 'b' to go to main page, 'a' to view room allotment,'c' to book another room -> ";
      cin>>ch;
      if(ch=='b')
      return;
      else if(ch=='a')
      { displayRoomAllot();
        return;}
      else if(ch='c')
      goto again; 
      else return;
  }
 }

 
 strcpy(room[p].roomn,k);

 cout<<"\nEnter Host's name: ";
 cin>>room[p].host;

 cout<<"\nStart time(in 24-hour format): ";
 cin>>room[p].start;

 cout<<"\nEnd time(in 24-hour format): ";
 cin>>room[p].send;

 cout<<"\nFrom(in DD/MM/YYYY format): ";
 cin>>room[p].from;

 cout<<"\nTo:(in DD/MM/YYYY format): ";
 cin>>room[p].to;

 cout<<"\nYou've been allotted your requested room\n";
 room[p].open();
 p++;
}

void rooms::open()  //Opens up room for seat allocation
{
  for(int i=0; i<2;i++)
  {
    for(int j=0;j<5;j++)
    {
      strcpy(room[p].chair[i][j], "Empty");
    }
  }
}

void rooms::allotCh()   //Seat Reservation
{
  int chair;
  char number[5],ch,ch1;
  top:
  cout<<"\n Enter Room no: ";
  cin>>number;
  int n;

  for(n=0;n<=p;n++) //Get the value of n of requested room to access it's class
  {
    if(strcmp(room[n].roomn, number)==0)
    break;
  }
  
  chairalloc:
  while(n<=p)
  {
    cout<<"\nChair Number: ";
    cin>>chair;

    if(chair>10)
    {
      cout<<"\nThere are only 10 Chair available in this Room.";
    }

    else
    {
     if (strcmp(room[n].chair[chair/5][(chair%5)-1], "Empty")==0)   //chair array index starts from (0,0) and ends with (1,4) here and this way index of chair no. 3 = (0,2)<-10 chairs arranged in 2 rows and 5 columns
      {
        cout<<"Enter reservee's name: ";
        cin>>room[n].chair[chair/5][(chair%5)-1];
        cout<<"Enter 'c' if you want to continue, 'b' to go to main-> ";
        cin>>ch1;
        if(ch1=='c')
        goto chairalloc;
        else if(ch=='b')
        return;

        break;
      }

    else
      { cout<<"We're sorry to inform you that the requested chairs are reserved\n";
        cout<<"Enter 'm' to modify seat allocation, 'c' to continue and 'b' to go to main -> ";
        cin>>ch;
        cout<<"\n";
        if(ch=='m')
       {modifyAllot();
        return;
        }
        else if(ch=='c')
        goto chairalloc;
        else if(ch=='b')
        return;
      }
    }
  }
  if(n>p)
      cout<<"Enter correct Room  no.\n";
  
  }



void rooms::show()  //Displays requested room's allotment details and seat arrangement
{
  int n;
  char number[5];

  cout<<"\nEnter Room no: ";
  cin>>number;

  for(n=0;n<=p;n++)
  {
    if(strcmp(room[n].roomn, number)==0)
    break;
  }

while(n<=p)
{
  vline('*');

  cout<<"Room no: "<<room[n].roomn
  <<"\nHost: "<<room[n].host<<"\t\tStart time: "
  <<room[n].start<<"\t End time: "<<room[n].send
  <<"\nFrom: "<<room[n].from<<"\t\tTo: "<<
  room[n].to<<"\n";

  vline('*');

 int c=0,s=0;
   for (int i=0; i<2;i++)
  {
    cout<<"\n";

    for (int j = 0;j<5; j++)
    {
      s++;
          cout.width(5);

          cout<<s<<".";

          cout.width(10);

          cout<<room[n].chair[i][j];

         if(strcmp(room[n].chair[i][j], "Empty")==0)
        {
          c++;
        }
      }
    }

  cout<<"\n\nThere are "<<c<<" Chairs empty in Room No: "<<room[n].roomn<<"\n";

  int a=1;

  for (int i=0; i<2; i++)
  {
    for(int j=0;j<5;j++)
    {
      a++;
      if(strcmp(room[n].chair[i][j],"Empty")!=0)
      cout<<"\nThe Chair no. "<<(a-1)<<" is reserved for "<<room[n].chair[i][j]<<".";
    }
  }
  cout<<"\n";
  break;
  }

  if(n>p)
    cout<<"Enter correct Room no.\n";

}


void rooms::displayRoomAllot()    //Displays room allotment of all booked rooms
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"\nRoom no: "<<room[n].roomn<<"\nHost: "<<room[n].host
    <<"\t\tStart time: "<<room[n].start<<"\tEnd  Time: "
    <<room[n].send<<"\nFrom: "<<room[n].from<<"\t\tTo: "
    <<room[n].to<<"\n";

    vline('*');
    vline('_');
  }
}


void rooms::emptyRoom()    //Checks host out of room
{   char number[5],name[10];
    int n,k;

   cout<<"Enter room you want to check out from: ";
   cin>>number;
    for(n=0;n<=p;n++) //Get the value of n of requested room to access it's class
  {
    if(strcmp(room[n].roomn, number)==0)
    break;
  }

  cout<<"Enter your name to verify your identity: ";   //Allows only the host to check out of a room
  cin>>name;
  if(strcmp(room[n].host, name)==0)
  {
    cout<<"You have been checked out.\n";
    cout<<"Hope you enjoyed your stay with us! See you again!\n";
    for(k=n;k<p;k++)
  {
    room[k]=room[k+1];
  }
  p--;
  }
  else
  { cout<<"Please re-check your room allocation and come again. See you!\n";
  }

}


void rooms::modifyAllot()   //Allows host to modify seat arrangement of room
{  char number[5],name[10],ch;
    int n,chair;

   cout<<"Enter room no.: ";
   cin>>number;
    for(n=0;n<=p;n++) //Get the value of n of requested room to access it's class
  {
    if(strcmp(room[n].roomn, number)==0)
    break;
  }

  cout<<"Enter your name to verify your identity: ";  //Verifies that the person modifying is the host
  cin>>name;
  if(strcmp(room[n].host, name)==0)
  {
    cout<<"Enter chair no.: ";
    cin>>chair;
    if(chair<=10)
    { cout<<"This chair has been reserved for "<<room[n].chair[chair/5][(chair%5)-1]<<"\n";
      cout<<"Do you want re-allocate it (enter 'r') or do you want to cancel the seat reservation(enter 'c')-> ";
      cin>>ch;
      cout<<"\n";
      if(ch=='r')
      {
        cout<<"Enter name of the reservee you want to re-allocate it to: ";
        cin>>room[n].chair[chair/5][(chair%5)-1];
      }
    else if(ch=='c')
    {
      strcpy(room[n].chair[chair/5][(chair%5)-1],"Empty");
    }
        
    }
  }
  else
  { cout<<"Please re-check your room allocation and come again. See you!\n";
  }

}


int main(){ 
  system("cls");
  int choice;
while(1)
{  vline('*');
  cout<<"\n\t\t\t1.Book a room\n"<<"\t\t\t2.Seat Reservation\n"<<"\t\t\t3.Show Status Of Room\n"<<"\t\t\t4.Room Allotment\n"<<"\t\t\t5.Modify Seat Allotment\n"<<"\t\t\t6.Check Out Of Room\n"<<"\t\t\t7.Exit\n"<<"Enter Your Choice:-> ";
  cin>>choice;
  vline('*');
  switch(choice)
  {
    case 1:  room[p].book();
      break;
    case 2:  room[p].allotCh();
      break;
    case 3:  room[0].show();
      break;
    case 4:  room[0].displayRoomAllot();
      break;
    case 5: room[0].modifyAllot();
     break;
    case 6: room[0].emptyRoom();
     break;
    case 7:  exit(0);
    default:
    cout<<"Enter a valid option";
  }
}
return 0;
}