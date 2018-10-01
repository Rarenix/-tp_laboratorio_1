#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define CANT 30
int main()
{
    char seguir='s';
    int op,flag=0,legajo=1;
    Employee emp[CANT];
    initEmploy(emp,CANT);
    do
    {
        switch(op = menu())
        {
        case 1:
            alta(emp,CANT,legajo);
            system("pause");
            system("cls");
            legajo++;//LEGAJO AUTOINCREMENTAL
            flag=1;
            break;
        case 2:
            modificar(emp,CANT);
            if(flag==0)
            {
                printf("Error Realice Un Alta");
                system("pause");
                system("cls");
                break;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flag==0)
            {
                printf("Error Realice Un Alta");
                system("pause");
                system("cls");
                break;
            }
            baja(emp,CANT);
            system("pause");
            system("cls");
            break;
        case 4:
            if(flag==0)
            {
                printf("Error Realice Un Alta");
                system("pause");
                system("cls");
                break;
            }
            listar(emp,CANT);
            promSalEmp(emp,CANT);
            system("pause");
            system("cls");

            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("reingrese opcion\n\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
