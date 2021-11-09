#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
struct client
{
    char name[100];
    signed long int pin;
    float net_worth;
};
void main()
{
    system("color 7D");
    char buffer[256];
    FILE* out;
    fopen_s(&out,"client.txt","a");
    
    int flag=1;
    while(flag==1)
    {
        struct client A1;
        struct client *ptr;
        ptr=&A1;
        printf("\nplease type the name you want to put: ");
        //gets(&ptr->name);
        scanf("%s",&ptr->name);
        printf("\n the name of the customer is %s",A1.name);
        printf("\n please enter the pin of %s : ",A1.name);
        scanf("%d",&ptr->pin);
        printf("\n the pin of %s is %d",A1.name,A1.pin);
        printf("\n please enter the salary of %s : ",A1.name);
        scanf("%f",&ptr->net_worth);
        printf("\n the net_worth of %s is %03f ",A1.name,A1.net_worth);
        sprintf_s(buffer,256,"\n%s , %d , %03f\n",A1.name,A1.pin,A1.net_worth);
        fwrite(buffer,sizeof(char),strlen(buffer),out);
        Beep(400,500);
        printf("\ndo you want to add another custoemr? if yes press '1' ");
        printf(" OR press any key if no press '0' : ");
        scanf("%d",&flag);
       
    }
    fclose(out);
}