#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef char string[50];
struct date{
  int day;
  int month;
  int year;
};
struct passInfo{
  struct name{
    string First;
    string Last;
  }name;
  string tripNumber;
  string embarkPoint;
  int dropOffPoint;
  int priorityNumber;
  int idNumber;
  int seatNumber;

};
struct Bus{
  int MaxPass;
  struct passInfo passInfo[20];
  struct date Date;
  int isFull;
  int passCount;
  string date_s;
  string busName;
};

void sortPriority(struct Bus *a) {
  int step =0,i=0;
  struct passInfo temp;
  // loop to access each array element
  for (step = 0; step < a->passCount - 1; step++) {

    // loop to compare array elements
    for (i = 0; i < a->passCount - step - 1; i++) {

      if (a->passInfo[i].priorityNumber > a->passInfo[i+1].priorityNumber) {
        temp = a->passInfo[i];
        a->passInfo[i] = a->passInfo[i + 1];
        a->passInfo[i + 1] = temp;
      }
    }
  }

}
void takeInput(struct Bus a[]){
FILE *fp;
int i=0,j=0,totalPasscount=0,stop,counter[20];
struct passInfo passInfo[100];
fp=fopen("input.txt","r");
for(i=0;i<20;i++){
  a[i].passCount=0;
  counter[i]=0;
}
fscanf(fp,"%d %d %d",&a[0].Date.month,&a[0].Date.day,&a[0].Date.year);
//320 beacuse the max amount of possible passengers is 320,16 if full and 20 busses.
i=0;
while(!feof(fp)){
  fscanf(fp,"%s %s",passInfo[i].name.First,passInfo[i].name.Last);
  fscanf(fp,"%s",passInfo[i].tripNumber);
  fscanf(fp,"%d",&passInfo[i].priorityNumber);
  fscanf(fp,"%s",passInfo[i].embarkPoint);
  fscanf(fp,"%d",&passInfo[i].dropOffPoint);
  fscanf(fp,"%d",&passInfo[i].idNumber);
  i++;
  if(passInfo[i].priorityNumber!=0)
  printf("%d\n",totalPasscount );
  }
  totalPasscount=i;
  for(i=0;i<totalPasscount;i++){
    if(validateBusNumber(passInfo[i].tripNumber,a)){
      switch(validateBusNumber(passInfo[i].tripNumber,a)-1){
        case 0:
        if(a[0].passInfo[counter[0]].priorityNumber==0){
        a[0].passInfo[counter[0]]=passInfo[i];
        a[0].passCount++;
        }
        counter[0]++;
          break;
        case 1:
        a[1].passInfo[counter[1]]=passInfo[i];
        a[1].passCount++;
        counter[1]++;
          break;
        case 2:
        a[2].passInfo[counter[2]]=passInfo[i];
        a[2].passCount++;
        counter[2]++;
          break;
        case 3:
        a[3].passInfo[counter[3]]=passInfo[i];
        a[3].passCount++;
        counter[3]++;
          break;
        case 4:
        a[4].passInfo[counter[4]]=passInfo[i];
        a[4].passCount++;
        counter[4]++;
          break;
        case 5:
        a[5].passInfo[counter[5]]=passInfo[i];
        a[5].passCount++;
        counter[5]++;
          break;
        case 6:
        a[6].passInfo[counter[6]]=passInfo[i];
        a[6].passCount++;
        counter[6]++;
          break;
        case 7:
        a[7].passInfo[counter[7]]=passInfo[i];
        a[7].passCount++;
        counter[7]++;
          break;
        case 8:
        a[8].passInfo[counter[8]]=passInfo[i];
        a[8].passCount++;
        counter[8]++;
          break;
        case 9:
        a[9].passInfo[counter[9]]=passInfo[i];
        a[9].passCount++;
        counter[9]++;
          break;
        case 10:
        a[10].passInfo[counter[10]]=passInfo[i];
        a[10].passCount++;
        counter[10]++;
          break;
        case 11:
        a[11].passInfo[counter[11]]=passInfo[i];
        a[11].passCount++;
        counter[11]++;
          break;
        case 12:
        a[12].passInfo[counter[12]]=passInfo[i];
        a[12].passCount++;
        counter[12]++;
          break;
        case 13:
        a[13].passInfo[counter[13]]=passInfo[i];
        a[13].passCount++;
        counter[13]++;
          break;
        case 14:
        a[14].passInfo[counter[14]]=passInfo[i];
        a[14].passCount++;
        counter[14]++;
          break;
        case 15:
        a[15].passInfo[counter[15]]=passInfo[i];
        a[15].passCount++;
        counter[15]++;
          break;
        case 16:
        a[16].passInfo[counter[16]]=passInfo[i];
        a[16].passCount++;
        counter[16]++;
          break;
        case 17:
        a[17].passInfo[counter[17]]=passInfo[i];
        a[17].passCount++;
        counter[17]++;
          break;
        case 18:
        a[18].passInfo[counter[18]]=passInfo[i];
        a[18].passCount++;
        counter[18]++;
          break;
        case 19:
        a[19].passInfo[counter[19]]=passInfo[i];
        a[19].passCount++;
        counter[19]++;
          break;
      }
    }
  }

  fclose(fp);
}
void searchPassenger(struct Bus a,string input){
  int i=0;
  for(i=0;i<a.passCount;i++){
    if(strcmp(a.passInfo[i].name.Last,input)==0){
      printf("%s\n",a.busName);
      printf("%s\n",a.passInfo[i].embarkPoint);
      printf("%s %s\n",a.passInfo[i].name.First,a.passInfo[i].name.Last);
      printf("%d\n",a.passInfo[i].idNumber);
      printf("%d\n",a.passInfo[i].priorityNumber);
      printf("%s\n",a.date_s);
      if(strcmp(a.passInfo[i].embarkPoint,"Manila")==0){
        switch (a.passInfo[i].dropOffPoint) {
          case 1:
            printf("Mamplasan Toll Exit\n");
          break;
          case 2:
            printf("Phase 5, San Jose Village\n");
          break;
          case 3:
            printf("Milagros Del Rosario (MRR) Building – East Canopy\n");
          break;
        }
      }
      if(strcmp(a.passInfo[i].embarkPoint,"Laguna")==0){
        switch (a.passInfo[i].dropOffPoint) {
          case 1:
            printf("Petron Gasoline Station along Gil Puyat Avenue\n");
          break;
          case 2:
            printf("Gate 4: Gokongwei Gate\n");
          break;
          case 3:
            printf("Gate 2: North Gate (HSSH)\n");
          break;
          case 4:
            printf("Gate 1: South Gate (LS Building Entrance)\n");
          break;
        }
      }
    }
  }
}

void initBusNames(struct Bus a[20]){
  strcpy(a[0].busName,"AE101");
  strcpy(a[1].busName,"AE102");
  strcpy(a[2].busName,"AE103");
  strcpy(a[3].busName,"AE104");
  strcpy(a[4].busName,"AE105");
  strcpy(a[5].busName,"AE106");
  strcpy(a[6].busName,"AE107");
  strcpy(a[7].busName,"AE108");
  strcpy(a[8].busName,"AE109");
  strcpy(a[9].busName,"AE150");
  strcpy(a[10].busName,"AE151");
  strcpy(a[11].busName,"AE152");
  strcpy(a[12].busName,"AE153");
  strcpy(a[13].busName,"AE154");
  strcpy(a[14].busName,"AE155");
  strcpy(a[15].busName,"AE156");
  strcpy(a[16].busName,"AE157");
  strcpy(a[17].busName,"AE158");
  strcpy(a[18].busName,"AE159");
  strcpy(a[19].busName,"AE160");

}


//checks if seat number value equals the seat in the bus
int checkSeatCount(struct Bus a,int seatCount){
  int i=0,j=0;
  for(i=0;i<20;i++){
          if(a.passInfo[i].seatNumber==seatCount)
        return 1;
      }
}

void displaySeats(struct Bus *a){

  int i=0,j=0,seatCount=1;
  if(a->passCount<=13){
    printf("AMOUNT OF SEATS AVAILABLE %d\n",13-a->passCount );
    for(i=0;i<5;i++){
      for(j=0;j<3;j++){
        if(j>0&&i==4){
          if(j==2){
            printf("| DRIVER|");
          }
        }else{
          if(checkSeatCount(*a, seatCount)==1){
            printf("| O " );
            if(j==2){
              printf("|");
            }
          }else{
          printf("| X " );
          if(j==2){
            printf("|");
          }
        }
        }
        seatCount++;
      }
      printf("\n\n");
    }
  }else if(a->passCount>13){
    printf("AMOUNT OF SEATS AVAILABLE %d\n",16-a->passCount );
    for(i=0;i<5;i++){
      for(j=0;j<4;j++){
        if(j>=0&&i==4){
          if(j==0){
            printf("|    DRIVER     |");
          }
        }else{
          if(checkSeatCount(*a, seatCount)==1){
            printf("| O " );
            if(j==3){
              printf("|");
            }
          }else{
          printf("| X " );

          if(j==3){
            printf("|");
          }
        }
        }
        seatCount++;
      }
      printf("\n\n");
    }
  }
}
int validateBusNumber(string tripNumber,struct Bus a[20]){
  int i;
  for(i=0;i<20;i++){
    if(strcmp(tripNumber,a[i].busName)==0){
      return i+1;
    }
    }
    return 0;

}
void assignSeats(struct Bus a[20]){
  int i=0,j=0;
  int seatcount[20];
  for(i=0;i<20;i++){
    for(j=0;j<a[i].passCount;j++){
      a[i].passInfo[j].seatNumber=0;
      seatcount[i]=1;
    }
  }
  for(i=0;i<20;i++){
    for(j=0;j<a[i].passCount;j++){
      a[i].passInfo[j].seatNumber=seatcount[i];
      seatcount[i]++;
    }
  }
}
void printBusDetails(struct Bus a){
  int i=0;
  for(i=0;i<a.passCount;i++){
    printf("%s\n",a.busName);
    printf("%s\n",a.passInfo[i].embarkPoint);
    printf("%s %s\n",a.passInfo[i].name.First,a.passInfo[i].name.Last);
    printf("%d\n",a.passInfo[i].idNumber);
    printf("%d\n",a.passInfo[i].priorityNumber);
    printf("%s\n",a.date_s);
    if(strcmp(a.passInfo[i].embarkPoint,"Manila")==0){
      switch (a.passInfo[i].dropOffPoint) {
        case 1:
          printf("Mamplasan Toll Exit\n");
        break;
        case 2:
          printf("Phase 5, San Jose Village\n");
        break;
        case 3:
          printf("Milagros Del Rosario (MRR) Building – East Canopy\n");
        break;
      }
    }
    if(strcmp(a.passInfo[i].embarkPoint,"Laguna")==0){
      switch (a.passInfo[i].dropOffPoint) {
        case 1:
          printf("Petron Gasoline Station along Gil Puyat Avenue\n");
        break;
        case 2:
          printf("Gate 4: Gokongwei Gate\n");
        break;
        case 3:
          printf("Gate 2: North Gate (HSSH)\n");
        break;
        case 4:
          printf("Gate 1: South Gate (LS Building Entrance)\n");
        break;
      }
    }
    printf("-------------------------------------------------------\n" );
  }
}
void ExitPrint(struct Bus a[]){
  int i=0,j=0;
  FILE *fp;
  string fileName="trip-";
  strcat(fileName,a[0].date_s);
  strcat(fileName,".txt");
  fp =fopen(fileName,"w");
  for(i=0;i<20;i++){
    for(j=0;j<a[i].passCount;j++){

        fprintf(fp,"%s\n",a[i].busName);
        fprintf(fp,"%s\n",a[i].passInfo[j].embarkPoint);
        fprintf(fp,"%s %s\n",a[i].passInfo[j].name.First,a[i].passInfo[j].name.Last);
        fprintf(fp,"%d\n",a[i].passInfo[j].idNumber);
        fprintf(fp,"%d\n",a[i].passInfo[j].priorityNumber);
        fprintf(fp,"%s\n",a[i].date_s);
        if(strcmp(a[i].passInfo[j].embarkPoint,"Manila")==0){
          switch (a[i].passInfo[j].dropOffPoint) {
            case 1:
              fprintf(fp,"Mamplasan Toll Exit\n");
            break;
            case 2:
              fprintf(fp,"Phase 5, San Jose Village\n");
            break;
            case 3:
              fprintf(fp,"Milagros Del Rosario (MRR) Building – East Canopy\n");
            break;
          }
        }
        if(strcmp(a[i].passInfo[j].embarkPoint,"Laguna")==0){
          switch (a[i].passInfo[j].dropOffPoint) {
            case 1:
              fprintf(fp,"Petron Gasoline Station along Gil Puyat Avenue\n");
            break;
            case 2:
              fprintf(fp,"Gate 4: Gokongwei Gate\n");
            break;
            case 3:
              fprintf(fp,"Gate 2: North Gate (HSSH)\n");
            break;
            case 4:
              fprintf(fp,"Gate 1: South Gate (LS Building Entrance)\n");
            break;
          }
        }
        fprintf(fp, "-------------------\n" );
        fprintf(fp, "-------------------\n" );
    }



  }
  fprintf(fp, "-------------------\n" );
  fclose(fp);
}
void listTrips(){
  printf("AE101-109 Departing Manila-------\n1.Mamplasan Toll Exit \n2.Phase 5, San Jose Village \n3.Milagros Del Rosario (MRR) Building -- East Canopy\n" );

  printf( "AE150-160 Departing Laguna------\n1.Petron Gasoline Station along Gil Puyat Avenue \n2.Gate 4: Gokongwei Gate \n3.Gate 2: North Gate (HSSH) \n4.Gate 1: South Gate (LS Building Entrance)\n" );

}
int checkIfValidDropOff(struct passInfo a,int input){
  if(strcmp(a.embarkPoint,"Manila")==0){
    if(input>0&&input<4){
      return 1;
    }else{
      return  0;
    }
  }
  if(strcmp(a.embarkPoint,"Laguna")==0){
    if(input>0&&input<5){
      return 1;
    }else{
      return  0;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int i=0,j=0,Choice;
  char yes;
  string tripNumber,lastName;
  struct Bus bus[20];
  initBusNames(bus);
  printf("Take Input from file(y/n)? ");
  scanf("%c",&yes );
  if(yes=='y'||yes=='Y'){
    takeInput(bus);
    for(i=0;i<20;i++){
      sortPriority(&bus[i]);
    }
    assignSeats(bus);
  }else{
    printf("Enter date(DD MM YYYY): \n");
    scanf("%d %d %d",&bus[0].Date.day,&bus[0].Date.month,&bus[0].Date.year);
  }
  sprintf(bus[0].date_s,"%02d-%02d-%d",bus[0].Date.day,bus[0].Date.month,bus[0].Date.year);
  for(i=0;i<20;i++){
    bus[0].Date.month=bus[i].Date.month;
    bus[0].Date.day=bus[i].Date.day;
    bus[0].Date.year=bus[i].Date.year;
    strcpy(bus[i].date_s,bus[0].date_s);
  }
  while(Choice!=5){
  printf("-------------------------------------------------------\n");
  printf("WELCOME TO ARROWS EXPRESS\n");
  printf("1.Display bus seats\n");
  printf("2.Get Bus Details \n" );
  printf("3.New Passenger\n" );
  printf("4.Search Passenger Information \n" );
  printf("5.EXIT\n");
  scanf("%d",&Choice);
    printf("-------------------------------------------------------\n");
  while (Choice>5||Choice<=0) {
    printf("ERROR INVALID INPUT ENTER NEW CHOICE: " );
    scanf("%d",&Choice);
  }
  switch (Choice) {
    case 1:
      listTrips();
      printf("Enter Trip Number: " );
      scanf("%s",tripNumber);
        if(validateBusNumber(tripNumber,bus)){
          printf("AVAILABLE SEATS FOR BUS: %s \n",bus[validateBusNumber(tripNumber,bus)-1].busName);
          displaySeats(&bus[validateBusNumber(tripNumber,bus)-1]);
        }else{
          printf("ERROR INVALID BUS\n" );
        }
          printf("-------------------------------------------------------\n");
        break;
      case 2:
        printf("Enter Trip Number: " );
        scanf("%s",tripNumber);
        if(validateBusNumber(tripNumber,bus)){
          printBusDetails(bus[validateBusNumber(tripNumber,bus)-1]);
        }else{
          printf("ERROR INVALID BUS\n" );
        }
          printf("-------------------------------------------------------\n");
      break;
      case 3:
      listTrips();
      printf("Select Bus: \n");
      scanf("%s",tripNumber);
        if(validateBusNumber(tripNumber,bus)){
          printf("Enter Name: \n" );
          scanf("%s %s",bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].name.First,bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].name.Last);
          strcpy(bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].tripNumber, tripNumber);
          printf("Enter Priority Number\n" );
          scanf("%d",&bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].priorityNumber );
          if(strcmp(tripNumber,"AE101")==0||strcmp(tripNumber,"AE102")||strcmp(tripNumber,"AE103")==0||strcmp(tripNumber,"AE104")==0||strcmp(tripNumber,"AE105")==0||strcmp(tripNumber,"AE105")==0||strcmp(tripNumber,"AE106")==0||strcmp(tripNumber,"AE107")==0||strcmp(tripNumber,"AE108")==0||strcmp(tripNumber,"AE109")==0){
            strcpy(bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].embarkPoint,"Manila");
          }else{
            strcpy(bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].embarkPoint,"Laguna");
          }
          printf("Enter drop off point\n" );
          scanf("%d",&bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].dropOffPoint );
          while(checkIfValidDropOff(bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount], bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].dropOffPoint)!=1){
            printf("INVALID INPUT PLEASE INPUT AGAIN: " );
            scanf("%d",&bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].dropOffPoint );
          }
          printf("Enter id number\n" );
          scanf("%d",&bus[validateBusNumber(tripNumber,bus)-1].passInfo[bus[validateBusNumber(tripNumber,bus)-1].passCount].idNumber);
          bus[validateBusNumber(tripNumber,bus)-1].passCount++;
        }else{
          printf("ERROR INVALID BUS\n" );
        }
          printf("-------------------------------------------------------\n");
      break;
      case 4:
      printf("Enter Passenger's last name: " );
      scanf("%s",lastName);
      for(i=0;i<20;i++){
        searchPassenger(bus[i], lastName);
      }
      break;

  }

  for(i=0;i<20;i++){
    sortPriority(&bus[i]);
  }
  assignSeats(bus);


}



  ExitPrint(bus);
  return 0;
}
