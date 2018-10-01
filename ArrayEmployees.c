#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

int menu()
{
    int op;
    printf("\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir\n\ningrese opcion: ");
    fflush(stdin);
    scanf("%d",&op);
    return op;
}
int isAdigit(Employee pers,int tam)
{   int flag;
    if(!isdigit(pers.sector))
    {
        flag=1;

    if(pers.sector==1||pers.sector==2||pers.sector==3)
    {
        flag=0;
    }
    }
    else
    {
    flag=0;
    }
    return flag;
}
void initEmploy(Employee* lista, int len)
{//marca todo como vacio solo la uso al inicio
    for(int i=0; i<len; i++)
    {
    lista[i].isEmpty=1;
    }
}
int initEmployees(Employee* lista, int len)
{
    int lugar=-1;
    for(int i=0; i<len; i++)
    {
    if(lista[i].isEmpty==1)
    {
    lugar=i;
    }

}return lugar;
}
int addEmployee(Employee* lista, int len, int id, char name[],char lastName[],float salary,int sector)
{
        int lugar,carga=-1;
        lugar=initEmployees(lista,len);
        if(lugar!=-1)
            {
            strcpy(lista[lugar].name,name);
            strcpy(lista[lugar].lastName,lastName);
            lista[lugar].salary=salary;
            lista[lugar].sector=sector;
            lista[lugar].id=id;
            lista[lugar].isEmpty=0;
            carga=0;
            }
        return carga;
}
void alta(Employee pers[],int len,int legajo)
{
        int r,sect,name,lastname;
        Employee auxPers;
        printf("ingrese nombre: ");
        fflush(stdin);
        gets(auxPers.name);
        name = isName(auxPers,len);
        {
         while(name==-1){
         printf("Reingrese Nombre");
         fflush(stdin);
         gets(auxPers.name);
         name = isName(auxPers,len);
         }
        }
        while(strlen(auxPers.name)>20)
        {
            printf("Nombre Muy Largo...Reingrese: ");
            fflush(stdin);
            gets(auxPers.name);
        }
        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(auxPers.lastName);
        lastname= isLastName(auxPers,len);
        while(lastname==-1){
        printf("Reingrese Apellido");
        fflush(stdin);
        gets(auxPers.lastName);
        lastname = isName(auxPers,len);
        }
        while(strlen(auxPers.lastName)>25)
        {
        printf("Apellido Muy Largo...Reingrese: ");
        fflush(stdin);
        gets(auxPers.lastName);
        }
        printf("ingrese salario: ");
        fflush(stdin);
        scanf("%f",&auxPers.salary);

        printf("ingrese sector: 1 2 3: ");
        fflush(stdin);
        scanf("%d",&auxPers.sector);
        sect=isAdigit(auxPers,len);
        while(sect!=0)
        {
            printf("error reingrese sector(solo numero): 1 2 3: ");
            fflush(stdin);
            scanf("%d",&auxPers.sector);
            sect=isAdigit(auxPers,len);
        }
        r=addEmployee(pers,len,legajo,auxPers.name,auxPers.lastName,auxPers.salary,auxPers.sector);
        if(r==0)//si se cargo sin ningun error addEmployee devuelve cero.
        {
        printEmployees(pers,len);
        }

}
/*int idAuto(Employee pers[],int tam,int legajo)
{
    for(int i=0;i<tam;i++)
    {
    if(pers[i].id==0)
    {
    legajo++;
    break;
    }
    }
    return legajo;
}*/
int printEmployees(Employee emp[],int len)
{
    printf("--NOMBRE-APELLIDO--SUELDO--SECTOR--ID-- \n");
    for(int i=0;i<len;i++)
    {
    if(emp[i].isEmpty==0){
    printf("%s    %s  %.2f\t  %d  \t %d \n", emp[i].name ,emp[i].lastName ,emp[i].salary ,emp[i].sector ,emp[i].id );
    }
    }
    return 0;
}

int findEmployeeById(Employee* lista,int len,int id)
{   int esta=-1;
    for(int i=0; i<len; i++)
    {
        if(lista[i].id==id&&lista[i].isEmpty==0)
          {
           esta=i;
           break;
          }

    }
    return esta;
}
int removeEmployee(Employee *lista, int len, int id)
{
    int lugar,baja=-1;
    char op;
    lugar = findEmployeeById(lista,len,id);
    if(lugar!=-1)
    {
        printf("persona encontrada %s %s Id: %d\n\n Desea Eliminarla?S/N...",lista[lugar].name,lista[lugar].lastName,id);
        fflush(stdin);
        scanf("%c",&op);
        if(op=='s'||op=='S')
        {
            lista[lugar].isEmpty=1;
            baja=0;
        }
        else
            {
            printf("cancelado");
            }
    }
    else
    {
        printf("persona no encontrada ");
    }
    return baja;
}

void baja(Employee per[],int len)
{
    int baja,id;
    printf("BAJA\n\nIngrese id: ");
    fflush(stdin);
    scanf("%d",&id);
    baja=removeEmployee(per,len,id);
    if(baja==0)
    {
    printf("persona eliminada ");
    }
    if(baja==-1)
    {
    printf(" eliminacion cancelada \n");
    }
}

int sortEmployeesbyName(Employee lista[],int len,int order)
{
    Employee aux;
    int retorno=-1;

        for(int i=0;i<len;i++)
        {
        for(int j=i+1;j<len;j++)
        {
        if(order==0)
        {
        if(strcmp(lista[i].lastName,lista[j].lastName)<0)
            {
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
            }retorno=0;
        }
        if(order==1)
        {
        if(strcmp(lista[i].lastName,lista[j].lastName)>0)
            {
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
            }retorno=0;

}
}

}
return retorno;
}

int sortEmployeesbySector(Employee lista[],int len,int order)
{
    Employee aux;
    int retorno=-1;
    for(int i=0;i<len;i++)
        {
        for(int j=i+1;j<len;j++)
        {
        if(order==0){
        if(lista[i].sector<lista[j].sector)
           {
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
           }
           retorno=0;
        }
        if(order==1){
        if(lista[i].sector>lista[j].sector)
           {
            aux=lista[i];
            lista[i]=lista[j];
            lista[j]=aux;
           }
           retorno=0;
        }
        }
        }
           return retorno;
}







void listar(Employee lista[],int len)
{
    int op,nomb,sal;
    printf("Ingrese Metodo De Ordemanimento\n 1-Ascendente 0-Descendente:");
    scanf("%d",&op);
    nomb=sortEmployeesbyName(lista,len,op);
    sal=sortEmployeesbySector(lista,len,op);
    printEmployees(lista,len);
    if(nomb==-1&&sal==-1)
        {
        printf("ERROR en el listado");
        }
}
void modificar(Employee pers[],int len)
{   int r,op,id;
    char resp,lowerResp;
        printf("ingrese ID");
        fflush(stdin);
        scanf("%d",&id);
        r = findEmployeeById(pers,len,id);
        if(r!=-1)
            {
            printf("%s %s. \nsalario: %.2f \nsector: %d\n",pers[r].name,pers[r].lastName,pers[r].salary,pers[r].id);
            printf("Persona Encontrada Desea Modificar? S/N");
            fflush(stdin);
            scanf("%c",&resp);
            lowerResp=tolower(resp);
            system("cls");
            if(lowerResp=='s')
                {
                do{
                printf("%s %s. \nSalario: %.2f \nSector: %d\n",pers[r].name,pers[r].lastName,pers[r].salary,pers[r].id);
                printf("1-NOMBRE\n 2-APELLIDO\n 3-SALARIO\n 4-SECTOR\n 5-SALIR\n");
                fflush(stdin);
                scanf("%d",&op);

                switch(op)
                {
            case 1:
                printf("Ingrese Nuevo Nombre ");
                fflush(stdin);
                gets(pers[r].name);
                system("cls");
                break;
            case 2:
                printf("Ingrese Nuevo Apellido ");
                fflush(stdin);
                gets(pers[r].lastName);
                system("cls");
                break;
            case 3:
                printf("Ingrese Nuevo Salario ");
                scanf("%f",&pers[r].salary);
                system("cls");
                break;
            case 4:
                printf("Ingrese Nuevo Sector: 1 2 3 ");
                scanf("%d",&pers[r].sector);
                while(pers[r].sector<0||pers[r].sector>3)
                {
                printf("Error Ingrese Sector(numeros): 1 2 3");
                fflush(stdin);
                scanf("%d",&pers[r].sector);
                }
                system("cls");
                break;
            case 5:
                resp='n';
                break;
            default:
                printf("Reingrese Opcion...");
                system("pause");
                break;
                }
                }while(resp=='s');

            }else
            {
            printf("cancelado");
            }
        }

}


void promSalEmp(Employee emp[],int len)
{
    float acum=0,prom;
    int cont=0,contMasPromedio=0,i;
    for(i=0;i<len;i++)
    {
    if(emp[i].isEmpty==0)
    {
    acum = acum + emp[i].salary;
    cont++;
    }
    }
    prom=acum/cont;
    for(i=0;i<len;i++)
    {
    if(emp[i].salary>prom&&emp[i].isEmpty==0)
        {
        contMasPromedio++;
        }
    }
    printf("\n\n El Total De Salarios Es: %.2f \n El promedio Es De %.2f \n hay %d Empleados Que superan el promedio\n\n ",acum,prom,contMasPromedio);
}


int isName(Employee emp,int len)
{   int name=0;
    for(int i=0;i<strlen(emp.name);i++){
    if(!isalpha(emp.name[i]))
    {
     printf("no es un nombre valido");
     system("pause");
     name=-1;
     break;

     }
     }
     return name;
}

int isLastName(Employee emp,int len)
{   int lastname=0;
    for(int i=0;i<strlen(emp.lastName);i++){
    if(!isalpha(emp.lastName[i]))
    {
     printf("No Es Un Apellido Valido\n");
     system("pause");
     lastname=-1;
     break;

     }
     }
     return lastname;
}
