#include <stdio.h>
#include <string.h>
#include <time.h>
typedef char string[50];
struct passInfo{

  int tripNumber;
  int embarkPoint;
  string dropOffPoint;
  int priorityNumber;
  int idNumber;
  int seatNumber;

};
struct name{
  string First;
  string Middle;
  string Last;
};

int main(int argc, char const *argv[]) {
  FILE *out;
  FILE *in;
  time_t t;
  int i=0,bus,count=0;
  struct name name[100];
  srand((unsigned) time(&t));
  in=fopen("in.txt","r");
  i=0;
  while(!feof(in)){
    fscanf(in,("%s %s"),name[i].First,name[i].Last);
    count++;
    i++;
  }
  fclose(in);

  out=fopen("out.txt","w");
  for(i=0;i<count-1;i++){
    fprintf(out, "%s %s\n",name[i].First,name[i].Last);
    bus=rand()%20;
    switch(bus){
      case 0:fprintf(out, "AE101\n" );
        break;
      case 1:fprintf(out, "AE102\n" );
        break;
      case 2:fprintf(out, "AE103\n" );
        break;
      case 3:fprintf(out, "AE104\n" );
        break;
      case 4:fprintf(out, "AE105\n" );
        break;
      case 5:fprintf(out, "AE106\n");
        break;
      case 6:fprintf(out, "AE107\n" );
        break;
      case 7:fprintf(out, "AE108\n" );
        break;
      case 8:fprintf(out, "AE109\n" );
        break;
      case 9:fprintf(out, "AE150\n" );
        break;
      case 10:fprintf(out, "AE151\n" );
        break;
      case 11:fprintf(out, "AE152\n" );
        break;
      case 12:fprintf(out, "AE153\n" );
        break;
      case 13:fprintf(out, "AE154\n" );
        break;
      case 14:fprintf(out, "AE155\n" );
        break;
      case 15:fprintf(out, "AE156\n" );
        break;
      case 16:fprintf(out, "AE157\n" );
        break;
      case 17:fprintf(out, "AE158\n" );
        break;
      case 18:fprintf(out, "AE159\n" );
        break;
      case 19:fprintf(out, "AE160\n" );
        break;
    }
    switch(rand()%6){
      case 0:fprintf(out, "1\n" );
        break;
      case 1:fprintf(out, "2\n" );
        break;
      case 2:fprintf(out, "3\n" );
        break;
      case 3:fprintf(out, "4\n" );
        break;
      case 4:fprintf(out, "5\n" );
        break;
      case 5:fprintf(out, "6\n");
        break;
      }

      if(bus<9){
        fprintf(out, "Manila\n" );strcpy(name[i].Middle,"Manila");
      }else if(bus>8&&bus<20){
        fprintf(out, "Laguna\n" );strcpy(name[i].Middle,"Laguna");
      }

        if(strcmp(name[i].Middle,"Manila")==0){
          switch(rand()%3){
            case 0:fprintf(out, "1\n" );
              break;
            case 1:fprintf(out, "2\n" );
              break;
            case 2:fprintf(out, "3\n" );
              break;
            }
        }
        if(strcmp(name[i].Middle,"Laguna")==0){
          switch(rand()%4){
            case 0:fprintf(out, "1\n" );
              break;
            case 1:fprintf(out, "2\n" );
              break;
            case 2:fprintf(out, "3\n" );
              break;
            case 3:fprintf(out, "4\n" );
              break;
            }
        }
        switch(rand()%6){
          case 0:fprintf(out, "121%d\n",rand()%9999 );
            break;
          case 1:fprintf(out, "120%04d\n",rand()%9999 );
            break;
          case 2:fprintf(out, "119%04d\n",rand()%9999 );
            break;
          case 3:fprintf(out, "118%04d\n" ,rand()%9999);
            break;
          case 4:fprintf(out, "116%04d\n" ,rand()%9999);
              break;
          case 5:fprintf(out, "117%04d\n",rand()%9999);
              break;

          }
  }
  


  fclose(out);
  return 0;
}
