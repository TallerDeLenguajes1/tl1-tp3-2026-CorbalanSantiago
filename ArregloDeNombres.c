#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cant_nombres 5
#define max_buffer 100

//declaracion de funciones

void MostrarPersonas(char *V[], int n);
void buscarNombrePorId(char *V[], int id);
int buscaNombrePorPalabra(char *V[], char *palabra); 

//main 

int main() 
{
    //parte 1
    char *V[cant_nombres];      //vector de punteros
    char Buff[max_buffer];      //variable auxiliar temporal
    printf("Ingreso de Nombres\n");
    for(int i=0;i<cant_nombres;i++) 
    {
        printf("Ingrese el nombre [%d]: ",i+1);
        gets(Buff);     //leo el nombre en el buffer temporal
        V[i]=(char*)malloc((strlen(Buff)+1)*sizeof(char));      //reservo memoria dinámica para el nombre + 1  (por el /0)
        strcpy(V[i], Buff);     //copio el buffer al bloque de memoria reservado
    }
    printf("\nListado de Nombres\n\n");
    MostrarPersonas(V, cant_nombres);
    
    //interfaz de consulta
    printf("\ndesea buscar un nombre por ID o por una palabra?\n");
    printf("opcion 1 (buscar por ID)\n opcion 2 (buscar por palabra)\n");
    int opcion;
    do
    {
        printf("eliga la opcion (1 | 2): ");
        scanf("%d",&opcion);
    }while(opcion<1||opcion>2);
    
    if(opcion==1)
    {
        int idBusqueda;
        printf("\nIngrese el ID: ");
        scanf("%d", &idBusqueda);
        buscarNombrePorId(V, idBusqueda);
    }
    else
    {
        char palabraBusqueda[50];
        printf("\nbusqueda por palabra clave\n");
        printf("Ingrese la palabra o letras a buscar: ");
        while ((getchar()) != '\n');
        gets(palabraBusqueda);
        int nombreEncontrado = buscaNombrePorPalabra(V, palabraBusqueda);
        if(nombreEncontrado!=-1) 
        {
            printf("coincidencia encontrada: %s\n", V[nombreEncontrado]);
        } 
        else 
        {
            printf("no se encontro el valor buscado\n");
        }
    }
    
    //libero memoria
    for(int i=0;i<cant_nombres;i++) 
    {
        free(V[i]);
    }

    return 0;
}

//desarrollo de funciones

void MostrarPersonas(char *V[], int n) 
{
    for(int i=0;i<n;i++) 
    {
        printf("Persona %d: %s\n", i+1, V[i]);
    }
}

int buscaNombrePorPalabra(char *V[], char *palabra) 
{
    for(int i=0;i<cant_nombres;i++) 
    {
        if(strstr(V[i], palabra)!=NULL) 
        {
            return i; 
        }
    }
    return -1;
}

void buscarNombrePorId(char *V[], int id) 
{
    if(id>0&&id<6) 
    {
        printf("Nombre en ID %d: %s\n", id, V[id-1]);
    } 
    else 
    {
        printf("no se encontro el valor buscado\n");
    }
}