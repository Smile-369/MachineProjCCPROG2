/*
    Kharl Vincent V. Lim (12116003)
    S18B
    Machine Project code
*/

#include <stdio.h>
#include <string.h>

#define MAX_PASS 320

typedef char string[50];

struct Date {
    int year;
    int month;
    int date;
};

struct ECard {
    int tripNum;
    int ePoint;
    string passName;
    int id;
    int prioNum; 
    int dPoint;
};

struct Bus {
    char seatNum [16];
    struct ECard info [16];
    int passCount;
};

// WIP
struct ECard LoadInfo (int nPass)
{
    struct ECard PassInfo;
    int i;
    FILE * fp;
    fp = fopen("INPUT.txt", "r");

    for (i = 0; i < nPass; i++)
    {
        fscanf(fp, "%d\n", &PassInfo.tripNum);
        fscanf(fp, "%s\n", &PassInfo.passName);
        fscanf(fp, "%d\n", &PassInfo.id);
        fscanf(fp, "%d\n", &PassInfo.prioNum);
        fscanf(fp, "%[^\n]%s\n", &PassInfo.dPoint);
    }
    fclose(fp); 

    return PassInfo;   
}

// Find the index of the bus using the trip number
int FindBusNum (int nTripNum)
{
    switch (nTripNum)
    {
    case 101:
        return 0;
        break;
    case 102:
        return 1;
        break;
    case 103:
        return 2;
        break;
    case 104:
        return 3;
        break;
    case 105:
        return 4;
        break;
    case 106:
        return 5;
        break;
    case 107:
        return 6;
        break;
    case 108:
        return 7;
        break;
    case 109:
        return 8;
        break;
    case 150:
        return 0;
        break;
    case 151:
        return 1;
        break;
    case 152:
        return 2;
        break;
    case 153:
        return 3;
        break;
    case 154:
        return 4;
        break;
    case 155:
        return 5;
        break;
    case 156:
        return 6;
        break;
    case 157:
        return 7;
        break;
    case 158:
        return 8;
        break;
    case 159:
        return 9;
        break;
    case 160:
        return 10;
        break;
    }
}

// Finds the seatnumber using the ID
int SeatNumFinder (struct Bus bus[], int tripNum, int idKey)
{
    int i, busNum, seatNum;
    busNum = FindBusNum(tripNum);

    for (i = 0; i < 13; i++)
    {
        if(bus[busNum].info[i].id == idKey)
            return i + 1;
    }
}

// Passenger manual entry
void IfPass (struct Bus bus[], int tripNum)
{
    int i, busNum, seatNum;
    busNum = FindBusNum(tripNum);

    bus[busNum].info[i].tripNum = tripNum;
    printf("What is your Last name?\n");
    scanf("%s", &bus[busNum].info[i].passName);

    if (tripNum >= 101 && tripNum <= 109)
        bus[busNum].info[i].ePoint = 0;
    if (tripNum >= 150 && tripNum <= 160)
        bus[busNum].info[i].ePoint = 1;
        
    printf("What is your ID number?\n");
    scanf("%d", &bus[busNum].info[i].id);
    printf("What priority group are you?\n");
    printf("(1): Faculty and ASF with Inter-campus assignments\n");
    printf("(2): Students with Inter-campus enrolled subjects or enrolled in thesis using Inter-campus facilities\n");
    printf("(3): Researchers\n");
    printf("(4): School Administrators\n");
    printf("(5): University Fellows\n");
    printf("(6): Employees and Students with official business\n");
    scanf("%d", &bus[busNum].info[i].prioNum);
    printf("Which drop-off point are you going to?\n");

    if (tripNum >= 101 && tripNum <= 109)
    {
        printf("(1): Mamplasan Toll Exit\n");
        printf("(2): Phase 5, San Jose Village\n");
        printf("(3): Milagros Del Rosario Building - East Canopy\n");
        scanf("%d", &bus[busNum].info[i].dPoint);
    }

    if (tripNum >= 150 && tripNum <= 160)
    {
        printf("(1): Petron Gasoline Station along Gil Puyat Avenue\n");
        printf("(2): Gate 4: Gokongwei Gate\n");
        printf("(3): Gate 2: North Gate (HSSH)\n");
        printf("(4): Gate 1: South Gate (LS Building Entrance)\n");
        scanf("%d", &bus[busNum].info[i].dPoint);
    }
    seatNum = SeatNumFinder(bus, tripNum, bus[busNum].info[i].id);
    bus[busNum].seatNum[seatNum - 1] = 'X';
    bus[busNum].passCount++;
    printf("Your seat number is number %d\n", seatNum);
    printf("Thank you for using Arrow Express Line!\n"); 
}

// WIP
void PrintBus (struct Bus bus[], int tripNum)
{
    int i, j, k, busNum;
    busNum = FindBusNum(tripNum);
    int normBus[3][5], worstBus[4][5];
    
    if


}

// Prints the number of passengers at certain drop-off points
void PrintDropPointCount (struct Bus bus[], int tripNum)
{
    int i, busNum, mTollCount = 0, p5Count = 0, mDRBCount = 0, pGSCount = 0, g4Count = 0, g2Count = 0, g1Count = 0;
    busNum = FindBusNum(tripNum);

    for (i = 0; i < bus[busNum].passCount; i++)
    {
        if (tripNum >= 101 && tripNum <= 109)
        {
            switch (bus[busNum].info[i].dPoint)
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
            printf("Passengers going down at:\n");
            if (mTollCount != 0)
                printf("Mamplasan Toll Exit: %d Passengers\n", mTollCount);
            if (p5Count != 0)
                printf("Phase 5, San Jose Village: %d Passengers\n", p5Count);
            if (mDRBCount != 0)
                printf("Milagros Del Rosario Building - East Canopy: %d\n", mDRBCount);

        }

        if (tripNum >= 150 && tripNum <= 160)
        {
            switch (bus[busNum].info[i].dPoint)
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
            printf("Passengers going down at:\n");
            if (pGSCount != 0)
                printf("Petron Gasoline Station along Gil Puyat Avenue: %d Passengers\n", pGSCount);
            if (g4Count != 0)
                printf("Gate 4: Gokongwei Gate: %d Passengers\n", g4Count);
            if (g2Count != 0)
                printf("Gate 2: North Gate (HSSH): %d Passengers\n", g2Count);
            if (g1Count != 0)
                printf("Gate 1: South Gate (LS Building Entrance): %d Passengers\n", g1Count);
        }
    }

}

// Prints the info of a certain passenger in a specific trip
void SearchPass (struct Bus bus[], int tripNum)
{
    int i, busNum;
    string name;
    busNum = FindBusNum(tripNum);
    
    printf("Input last name of the passenger\n");
    scanf("%s", &name);

    for (i = 0; i < bus[busNum].passCount; i++)
    {
        if (bus[busNum].info[i].passName == name)
        {
            printf("Trip number: AE%d", bus[busNum].info[i].tripNum);
            if (bus[busNum].info[i].ePoint == 0)
                printf("Embarkation point: Manila");
            else
                printf("Embarkation point: Laguan");
            printf("Passenger Last Name: %s". bus[busNum].info[i].passName);
            printf("ID number: %d", bus[busNum].info[i].id);
            printf("Priority Number: %d", bus[busNum].info[i].prioNum);
            if (tripNum >= 101 && tripNum <= 109)
            {
                switch (bus[busNum].info[i].dPoint)
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
            }

            if (tripNum >= 150 && tripNum <= 160)
            {
                switch (bus[busNum].info[i].dPoint)
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

void ShowAllPass (struct Bus bus[], int tripNum)
{
    struct Bus sorted;
    int i, temp, busNum;
    busNum = FindBusNum(tripNum);
    sorted = bus[busNum];


    for (i = 0; i < bus[busNum].passCount; i++)
    {
        if ()
    }
}

int main ()
{
    int i, nPass = 1, passBool, mTripNum, option;
    string mName;
    struct Bus MNL_to_LAG[9];
    struct Bus LAG_to_MNL[11];
    
    for (i = 0; i < 9; i++)
        MNL_to_LAG[i].passCount = 0;
    for (i = 0; i < 11; i++)
        LAG_to_MNL[i].passCount = 0;


    printf("Enter (1) if you are a passenger or (0) if you are an AE personnel\n");
    scanf("%d", &passBool);

    if (passBool == 1)
    {
        printf("What trip number do you want to be on?\nAE");
        scanf("%d", &mTripNum);

        if (mTripNum >= 101 && mTripNum <= 109)
            IfPass(MNL_to_LAG, mTripNum, nPass);
        if (mTripNum >= 150 && mTripNum <= 160)
            IfPass(LAG_to_MNL, mTripNum, nPass);
    }

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
        printf("(0): Exit");
        scanf("%d", &option);
    }
    
    return 0;
}