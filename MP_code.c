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
    int i = 0, totalPasscount,count[20];

    fp = fopen("input.txt", "r");
    struct ECard temp[150];
    for(i=0;i<20;i++){
        count[i]=bus[i].passCount;
    }
    i = 0;
    while (!feof(fp))
    {
        fscanf(fp,"%s %s",temp[i].FirstName, temp[i].LastName);
        fprintf(stdout,"%s %s\n",temp[i].FirstName, temp[i].LastName);
        fscanf(fp,"%d", &temp[i].busNum);
        if (temp[i].busNum >= 101 && temp[i].busNum <= 109)
            temp[i].ePoint = 0;
        if (temp[i].busNum >= 150 && temp[i].busNum <= 160)
            temp[i].ePoint = 1;
        fscanf(fp,"%d", &temp[i].dPoint);
        fscanf(fp,"%d", &temp[i].prioNum);
        fscanf(fp,"%d", &temp[i].id);
        i++;

    }
    totalPasscount = i;

    for (i = 0; i < totalPasscount; i++)
    {
        switch (temp[i].busNum) {
          case 101:
            bus[0].info[count[0]]=temp[i];
            bus[0].info[count[0]].seatNum=count[0]+1;
            count[0]++;
            bus[0].passCount=count[0];
          break;
          case 102:
            bus[1].info[count[1]]=temp[i];
            bus[1].info[count[1]].seatNum=count[1]+1;
            count[1]++;;
            bus[1].passCount=count[1];
          break;
          case 103:
            bus[2].info[count[2]]=temp[i];
            bus[2].info[count[2]].seatNum=count[2]+1;
            count[2]++;
            bus[2].passCount=count[2];
          break;
          case 104:
            bus[3].info[count[3]]=temp[i];
            bus[3].info[count[3]].seatNum=count[3]+1;
            count[3]++;
            bus[3].passCount=count[3];
          break;
          case 105:
            bus[4].info[count[4]]=temp[i];
            bus[4].info[count[4]].seatNum=count[4]+1;
            count[4]++;
            bus[4].passCount=count[4];
          break;
          case 106:
            bus[5].info[count[5]]=temp[i];
            bus[5].info[count[5]].seatNum=count[5]+1;
            count[5]++;
            bus[5].passCount=count[5];
          break;
          case 107:
            bus[6].info[count[6]]=temp[i];
            bus[6].info[count[6]].seatNum=count[6]+1;
            count[6]++;
            bus[6].passCount=count[6];
          break;
          case 108:
            bus[7].info[count[7]]=temp[i];
            bus[7].info[count[7]].seatNum=count[7]+1;
            count[7]++;
            bus[7].passCount=count[7];
          break;
          case 109:
            bus[8].info[count[8]]=temp[i];
            bus[8].info[count[8]].seatNum=count[8]+1;
            count[8]++;
            bus[8].passCount=count[8];
          break;
          case 150:
            bus[9].info[count[9]]=temp[i];
            bus[9].info[count[9]].seatNum=count[9]+1;
            count[9]++;
            bus[9].passCount=count[9];
          break;
          case 151:
            bus[10].info[count[10]]=temp[i];
            bus[10].info[count[10]].seatNum=count[10]+1;
            count[10]++;
            bus[10].passCount=count[10];
          break;
          case 152:
            bus[11].info[count[11]]=temp[i];
            bus[11].info[count[11]].seatNum=count[11]+1;
            count[11]++;
            bus[10].passCount=count[10];
          break;
          case 153:
              bus[12].info[count[12]]=temp[i];
              bus[12].info[count[12]].seatNum=count[12]+1;
              count[12]++;
              bus[12].passCount=count[12];
          break;
          case 154:
              bus[13].info[count[13]]=temp[i];
              bus[13].info[count[13]].seatNum=count[13]+1;
              count[13]++;
              bus[13].passCount=count[13];
          break;
          case 155:
              bus[14].info[count[14]]=temp[i];
              bus[14].info[count[14]].seatNum=count[14]+1;
              count[14]++;
              bus[14].passCount=count[14];
          break;
          case 156:
              bus[15].info[count[15]]=temp[i];
              bus[15].info[count[15]].seatNum=count[15]+1;
              count[15]++;
              bus[15].passCount=count[15];
          break;
          case 157:
              bus[16].info[count[16]]=temp[i];
              bus[16].info[count[16]].seatNum=count[16]+1;
              count[16]++;
              bus[16].passCount=count[16];
          break;
          case 158:
              bus[17].info[count[17]]=temp[i];
              bus[17].info[count[17]].seatNum=count[17]+1;
              count[17]++;
              bus[17].passCount=count[17];
          break;
          case 159:
              bus[18].info[count[18]]=temp[i];
              bus[18].info[count[18]].seatNum=count[18]+1;
              count[18]++;
              bus[18].passCount=count[18];
          break;
          case 160:
              bus[19].info[count[19]]=temp[i];
              bus[19].info[count[19]].seatNum=count[19]+1;
              count[19]++;
              bus[19].passCount=count[19];
          break;
      }
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

// Print bus function
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

void SearchPass (struct Bus bus[])
{
    int i, j;
    string name;

    printf("Input last name of the passenger\n");
    scanf("%s", &name);

    for (i = 0; i < 20; i++)
    {
        for(j = 0; j < bus[i].passCount; j++)
        {
            if(strcmp(name,bus[i].info[j].LastName) == 0)
            {
                printf("Trip number: AE%d\n", bus[i].busName);
                if (bus[i].info[j].ePoint == 0)
                    printf("Embarkation point: Manila\n");
                else
                    printf("Embarkation point: Laguna\n");

                printf("Passenger Name: %s %s\n",bus[i].info[j].FirstName,bus[i].info[j].LastName);
                printf("ID number: %d\n", bus[i].info[j].id);

                if(bus[i].busName>=101&&bus[i].busName<=109);
                        switch (bus[i].info[j].dPoint)
                        {
                        case 1:
                            printf("Drop-off point: Mamplasan Toll Exit");
                        break;
                        case 2:
                            printf("Drop-off point: Phase 5, San Jose Village");
                        break;
                        case 3:
                            printf("Drop-off point: Milagros Del Rosario Building - East Canopy");
                        break;
                        }
                if (bus[i].busName >= 150 && bus[i].busName <= 160)
                {
                    switch(bus[i].info[j].dPoint)
                    {
                    case 1:
                        printf("Drop-off point: Petron Gasoline Station along Gil Puyat Avenue");
                        break;
                    case 2:
                        printf("Drop-off point: Gate 4: Gokongwei Gate");
                        break;
                    case 3:
                        printf("Drop-off point: Gate 2: North Gate (HSSH)");
                        break;
                    case 4:
                        printf("Drop-off point: Gate 1: South Gate (LS Building Entrance)");
                        break;
                    }

                }
            }
        }
    }
    printf("\n\n");
}

int main (int argc, char const *argv[])
{
    struct Bus bus[20];
    string input;
    int busNum, option, passBool,i;
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
            case 5:
                SearchPass(bus);
                break;
            case 7:
                return 0;
                break;
            }
        }
    }
    return 0;
}
