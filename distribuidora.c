#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//arreglo

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

//estructuras

typedef struct  
{
    int ProductoID;         //Numerado en ciclo iterativo
    int Cantidad;           //entre 1 y 10
    char *TipoProducto;     //Algún valor del arreglo TiposProductos
    float PrecioUnitario;   //entre 10 - 100
}Producto;

typedef struct 
{
    int ClienteID;                      //Numerado en el ciclo iterativo
    char *NombreCliente;                //Ingresado por usuario
    int CantidadProductosAPedir;        //(aleatorio entre 1 y 5)
    Producto *Productos;         //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}distribuidora;

//funciones

float calcularCostoTotal(Producto p);

//main

int main() 
{
    //i
    srand(time(NULL)); 
    int cantClientes;
    char buff[100];
    distribuidora listaClientes[100];
    do
    {
        printf("Ingrese la cantidad de clientes a cargar(max 100): ");
        scanf("%d", &cantClientes);
        while ((getchar()) != '\n');
    }while(cantClientes>100);

    //ii
    for(int i=0;i<cantClientes;i++)
    {
        listaClientes[i].ClienteID=i+1;
        printf("\ncliente %d\n",listaClientes[i].ClienteID);
        printf("ingrese el nombre del cliente: ");
        gets(buff);     //leo el nombre en el buffer temporal
        listaClientes[i].NombreCliente=(char*)malloc((strlen(buff)+1)*sizeof(char));    //reserva de memoria dinamica para el nombre
        strcpy(listaClientes[i].NombreCliente,buff);
        printf("cliente: %s cargado exitoso\n",listaClientes[i].NombreCliente);
        
        //iii
        listaClientes[i].CantidadProductosAPedir=rand()%5+1;        //entre 1 y 5
        listaClientes[i].Productos=(Producto*)malloc(listaClientes[i].CantidadProductosAPedir*sizeof(Producto));
        for(int j=0;j<listaClientes[i].CantidadProductosAPedir;j++)
        {
            listaClientes[i].Productos[j].ProductoID=j+1;           //secuencia 1, 2, 3, ...
            listaClientes[i].Productos[j].Cantidad=rand()%10+1;     //del 1 al 10
            int indiceAzar=rand()%5;
            listaClientes[i].Productos[j].TipoProducto=TiposProductos[indiceAzar];      //geenrar diferentes tipos de productos
            listaClientes[i].Productos[j].PrecioUnitario=(float)(rand()%91+10);      //precio unitario random entre 10 y 100
        }
        if(listaClientes[i].CantidadProductosAPedir==1)
        {
            printf("se genero %d producto para este cliente\n\n",listaClientes[i].CantidadProductosAPedir);
        }
        else
        {
            printf("se generaron %d productos para este cliente\n\n",listaClientes[i].CantidadProductosAPedir);
        }
    }

    //v
    printf("\nresumen de preventa\n");
    for(int i=0;i<cantClientes;i++)
    {
        float totalCliente = 0;
        printf("\ncliente: %s (ID: %d)\n", listaClientes[i].NombreCliente, listaClientes[i].ClienteID);
        printf("\n%-15s %-15s %-15s %-10s\n\n", "Producto", "Cantidad", "P. Unitario", "Subtotal");
        for(int j=0;j<listaClientes[i].CantidadProductosAPedir;j++)
        {
            // iv) uso la función para calcular el costo
            float subtotal = calcularCostoTotal(listaClientes[i].Productos[j]);
            totalCliente += subtotal;
            printf("%-15s %-15d $%-15.2f $%-9.2f\n\n", listaClientes[i].Productos[j].TipoProducto, listaClientes[i].Productos[j].Cantidad, listaClientes[i].Productos[j].PrecioUnitario, subtotal);
        }
        printf("\ntotal a pagar del cliente: %.2f\n\n",totalCliente);
    }
    //libero memoria
    for(int i=0;i<cantClientes;i++)
    {
        free(listaClientes[i].NombreCliente);
        free(listaClientes[i].Productos);
    }
    return 0;
}

//desarrollo de funciones

//iv
float calcularCostoTotal(Producto p) 
{
    return p.Cantidad*p.PrecioUnitario;
}