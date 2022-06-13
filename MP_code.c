/* Kharl Vincent V. Lim (12116003)
   Matthew Theodore T. Borromeo (12118672)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char string[50];

// Structure for storing the date
struct date {
    int month;
    int date;
    int year;
};

// Structure for all the info of the passengers
struct ECard {
    int tripNum;
    int ePoint;
    string LastName;
    string FirstName;
    int id;
    int prioNum;
    int dPoint;
    int busNum;
    int seatNum;
};

//the structure for all the bussys
struct Bus {
    int passCount;
    struct ECard info[20];
    struct date date;
    string dateString;
    int busName;
};

// Initialize both busName and passCount
void initBus(struct Bus bus[])
{
    int i, tempBusname=101;
    for (i = 0; i < 20; i++)
    {
        bus[i].passCount = 0;
        bus[i].info[bus->passCount].seatNum = bus[i].passCount + 1;
        bus[i].busName = tempBusname;
        tempBusname++;
        if(tempBusname == 110)
            tempBusname = 150;
    }
}

// returns the bus index+1 based on the trip number : IE: 101 returns 1
int getBusName (struct Bus bus[], int tripNum)
{
    int i;

    for (i = 0; i < 20; i++)
    {
        if (bus[i].busName == tripNum)
            return i + 1;
    }
    return 0;
}

// Manual passenger input
void passInput (struct Bus *bus)
{
    if (bus->busName >= 101 && bus->busName <= 109)
        bus->info[bus->passCount].ePoint = 0;
    if (bus->busName >= 150 && bus->busName <= 160)
        bus->info[bus->passCount].ePoint = 1;

    printf("What is your Name?\n");
    scanf("%s %s", bus->info[bus->passCount].FirstName, bus->info[bus->passCount].LastName);
    printf("What is your ID number?\n");
    scanf("%d", &bus->info[bus->passCount].id);
    printf("What priority group are you in?\n");
    printf("(1): Faculty and ASF with Inter-campus assignments\n");
    printf("(2): Students with Inter-campus enrolled subjects or enrolled in thesis using Inter-campus facilities\n");
    printf("(3): Researchers\n");
    printf("(4): School Administrators\n");
    printf("(5): University Fellows\n");
    printf("(6): Employees and Students with official business\n");
    scanf("%d", &bus->info[bus->passCount].prioNum);
    printf("Which drop-off point are you going to?\n");

    if (bus->busName >= 101 && bus->busName <= 109)
    {
        printf("(1): Mamplasan Toll Exit\n");
        printf("(2): Phase 5, San Jose Village\n");
        printf("(3): Milagros Del Rosario Building - East Canopy\n");
        scanf("%d", &bus->info[bus->passCount].dPoint);
    }

    if (bus->busName >= 150 && bus->busName <= 160)
    {
        printf("(1): Petron Gasoline Station along Gil Puyat Avenue\n");
        printf("(2): Gate 4: Gokongwei Gate\n");
        printf("(3): Gate 2: North Gate (HSSH)\n");
        printf("(4): Gate 1: South Gate (LS Building Entrance)\n");
        scanf("%d", &bus->info[bus->passCount].dPoint);
    }

    printf("Your seat number is %d\n", bus->info[bus->passCount].seatNum);
    bus->info[bus->passCount].seatNum++;
    bus->passCount++;
    bus->info[bus->passCount].seatNum = bus->passCount + 1;
    printf("Thank you for using Arrow Express Line!\n");
}

void inputFromText (struct Bus bus[])
{
    FILE *fp;
    int i = 0, totalPasscount;

    fp = fopen("input.txt", "r");
    struct ECard temp[150];
    i = 0;
    while (!feof(fp))
    {
        fscanf(fp,"%s %s",temp[i].FirstName, temp[i].LastName);
        fscanf(fp,"%d", &temp[i].busNum);
        if (temp[i].busNum >= 101 && temp[i].busNum <= 109)
            temp[i].ePoint = 0;
        if (temp[i].busNum >= 150 && temp[i].busNum <= 160)
            temp[i].ePoint = 1;
        fscanf(fp,"%d", &temp[i].dPoint);
        fscanf(fp,"%d", &temp[i].id);
        i++;

    }
    totalPasscount = i;

    for (i = 0; i < totalPasscount; i++)
    {
        bus[getBusName(bus, temp[i].busNum)-1].info[bus[getBusName(bus, temp[i].busNum)-1].passCount] = temp[i];
        bus[getBusName(bus, temp[i].busNum)-1].passCount++;
        bus[i].info[bus->passCount].seatNum = bus[i].passCount + 1;
    }
}

int main (int argc, char const *argv[])
{
    struct Bus bus[20];
    int busNum, passBool;
    initBus(bus);

    // printf("Enter (1) if you are a passenger or (0) if you are an AE personnel\n");
    // scanf("%d", &passBool);

    inputFromText(bus);

    printf("Which bus would you ride on\nAE");
    scanf("%d", &busNum);
    passInput (&bus[getBusName(bus, busNum)-1]);
}
