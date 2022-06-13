/* Kharl Vincent V. Lim (12116003)
   Matthew Theodore T. Borromeo (12118672)

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef char string[50];
//fuck
struct FullName {
    string firstName;
    char midIni;
    string lastName;
};

struct Date {
    int year;
    int month;
    int day;
};

struct PassInfo {
    int tripNumber;
    string embarkPoint;
    string passName;
    int idNum;
    int prioNum;
    string dropPoint;
};

struct Bus {
    int seats[5][6];
    int row;
    int column;
    struct PassInfo PassengerInfo[20];

};

struct CurrentDay {
    struct Date Date;
    struct Bus Buses[20];
    int maxBus;
    int maxPass;
    string sDate;
};


void getInput(struct CurrentDay *a)
{
    FILE* Ticket;
    Ticket=fopen("input","r");
    //counter
    int i, j;


}

void PrintTicketLog (struct CurrentDay a) //print to console for now, print to txt file later
{
    FILE* Ticket;
    int i=0,j=0;


    Ticket = fopen(a.sDate, "w");
    for(i=0;i<a.maxBus;i++){
      for(j=0;i<a.maxPass;j++){
        fprintf (Ticket, "%d\n" , a.Buses[i].PassengerInfo[j].tripNumber);
        fprintf (Ticket, "%s\n" , a.Buses[i].PassengerInfo[j].embarkPoint);
        fprintf (Ticket, "%s\n" , a.Buses[i].PassengerInfo[j].passName);
        fprintf (Ticket, "%d\n" , a.Buses[i].PassengerInfo[j].idNum);
        fprintf (Ticket, "%d\n" , a.Buses[i].PassengerInfo[j].prioNum);
        fprintf (Ticket, "%s\n" , a.Buses[i].PassengerInfo[j].dropPoint);
        fprintf (Ticket, "\n");
      }
  }
    fclose(Ticket);
}
void
 convertToString(struct CurrentDay a)
{
  string day,month,year;
  sprintf(day,"%d",a.Date.day);
  sprintf(month,"%d",a.Date.month);
  sprintf(year,"%d",a.Date.year);
  strcat(day,"-");
  strcat(day,month);
  strcat(day,"-");
  strcat(day,year);
  strcat(day,".txt");
  strcpy(a.sDate,day);
}
int main (int argc, char const *argv[])
{
    struct CurrentDay today;
    struct PassInfo info;
    today.Date.day=10;
    today.Date.month=11;
    today.Date.year=2022;
    PrintTicketLog(today);
    int i, j; //will be used as counter variables

    return 0;
}
