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
    bus->info[bus->passCount].seatNum = bus->passCount + 1;
    printf("Your seat number is %d\n", bus->info[bus->passCount].seatNum);
    bus->info[bus->passCount].seatNum++;
    bus->passCount++;
    printf("Thank you for using Arrow Express Line!\n");
}

// Load passenger input feature
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
        bus[i].info[bus->passCount].seatNum = bus[i].passCount;
    }

    fclose(fp);
}

// View no. of passengers dropping off at certain points
void printDPointCount (struct Bus bus)
{
    int i, mTollCount = 0, p5Count = 0, mDRBCount = 0, pGSCount = 0, g4Count = 0, g2Count = 0, g1Count = 0;

    for (i = 0; i < 20; i++)
    {
        if (bus.info[i].ePoint == 0)
        {
            switch (bus.info[i].dPoint)
            {
            case 1:
                mTollCount++;
                break;
            case 2:
                p5Count++;
                break;
            case 3:
                mDRBCount++;
                break;
            }
        }

        if (bus.info[i].ePoint == 1)
        {
            switch (bus.info[i].dPoint)
            {
            case 1:
                pGSCount++;
                break;
            case 2:
                g4Count++;
                break;
            case 3:
                g2Count++;
                break;
            case 4:
                g1Count++;
                break;
            }
        }
    }
    printf("Passengers going down at:\n");
    if (mTollCount)
        printf("Mamplasan Toll Exit: %d Passenger(s)\n", mTollCount);
    if (p5Count)
        printf("Mamplasan Toll Exit: %d Passenger(s)\n", mTollCount);
    if (mDRBCount)
        printf("Milagros Del Rosario Building - East Canopy: %d Passenger(s)\n", mDRBCount);
    if (pGSCount)
        printf("Petron Gasoline Station along Gil Puyat Avenue: %d Passenger(s)\n", pGSCount);
    if (g4Count)
        printf("Gate 4: Gokongwei Gate: %d Passenger(s)\n", g4Count);
    if (g2Count)
        printf("Gate 2: North Gate (HSSH): %d Passenger(s)\n", g2Count);
    if (g1Count)
        printf("Gate 1: South Gate (LS Building Entrance): %d Passenger(s)\n", g1Count);
    printf("\n\n");
}

int checkSeatCount(struct Bus Bus,int seatCount)
{
    int i=0,j=0;
    for(i=0;i<20;i++){
        if(Bus.info[i].seatNum==seatCount)
            return 1;
      }
}

void printBus(struct Bus bus)
{
    int i,j,seatCount=1;
    if(bus.passCount<=13)
    {
        printf("AMOUNT OF SEATS AVAILABLE %d\n",13 - bus.passCount );
        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(j > 0 && i == 4)
                {
                    if(j == 2)
                        printf("| DRIVER|");
                }
                else
                {
                    if(checkSeatCount(bus, seatCount))
                    {
                        printf("| X " );
                        if(j == 2)
                            printf("|");
                    }
                    else
                    {
                        printf("| O " );
                        if(j == 2)
                            printf("|");
                    }
                }
                seatCount++;
            }
            printf("\n\n");
        }
    }

else if(bus.passCount>13)
{
    printf("AMOUNT OF SEATS AVAILABLE %d\n",16-bus.passCount );
    for(i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (j >= 0 && i == 4)
            {
                if (j == 0)
                    printf("|    DRIVER     |");
            }
            else
            {
                if(checkSeatCount(bus, seatCount))
                {
                    printf("| X " );
                    if(j == 3)
                        printf("|");
                }
                else
                {
                    printf("| O " );
                    if(j == 3)
                        printf("|");
                }
        }
        seatCount++;
      }
      printf("\n\n");
    }
  }

}

int main (int argc, char const *argv[])
{
    struct Bus bus[20];
    int busNum, option, passBool;
    initBus(bus);

        printf("Enter (1) if you are a passenger or (0) if you are an AE personnel\n");
        scanf("%d", &passBool);

        if (passBool == 1)
        {
            printf("Which bus would you ride on\nAE");
            scanf("%d", &busNum);
            passInput (&bus[getBusName(bus, busNum)-1]);
        }

    while (option != 7)
    {
        if (passBool == 0)
        {
            printf("Welcome Arrow Express Personnel!\n");
            printf("What would you like to do?\n");
            printf("(1): View number of passengers\n");
            printf("(2): View count of passengers at drop-off points\n");
            printf("(3): View passenger information\n");
            printf("(4): Load passenger information\n");
            printf("(5): Search passenger information\n");
            printf("(6): Load trip file\n");
            printf("(7): Exit\n");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                printf("Enter trip number\nAE");
                scanf("%d", &busNum);
                printBus(bus[getBusName(bus, busNum)-1]);
                break;
            case 2:
                printf("Enter trip number\nAE");
                scanf("%d", &busNum);
                printDPointCount(bus[getBusName(bus, busNum)-1]);
                break;
            case 4:
                inputFromText(bus);
                break;
            case 7:
                return 0;
                break;
            }
        }
    }
    return 0;
}
