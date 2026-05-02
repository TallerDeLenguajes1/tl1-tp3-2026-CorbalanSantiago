#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cant_nombres 5
#define max_buffer 100

//declaracion de funciones

void MostrarPersonas(char *V[], int n);
void buscarNombrePorPalabra(char *V[], char *palabra);
void buscarNombrePorId(char *V[], int id);

//main 

int main() 
{
    char *V[cant_nombres];      //vector de punteros
    char Buff[max_buffer];      //variable auxiliar temporal
    
    printf("Ingreso de Nombres\n");
    
    for (int i=0;i<cant_nombres;i++) 
    {
        printf("Ingrese el nombre [%d]: ",i+1);
        gets(Buff);     //leo el nombre en el buffer temporal
        V[i]=(char*)malloc((strlen(Buff)+1)*sizeof(char));      //reservo memoria dinámica para el nombre + 1  (por el /0)
        strcpy(V[i], Buff);     //copio el buffer al bloque de memoria reservado
    }
    
    printf("\nListado de Nombres\n\n");
    MostrarPersonas(V, cant_nombres);
    
    char palabraBusqueda[50]; // Buffer para la palabra
    printf("\nbusqueda por palabra clave\n");
    printf("Ingrese la palabra o letras a buscar: ");
    
    fflush(stdin); 
    gets(palabraBusqueda);
    buscarNombrePorPalabra(V, palabraBusqueda);
    
    int idBusqueda;
    printf("\nIngrese el ID: ");
    scanf("%d", &idBusqueda);
    buscarNombrePorId(V, idBusqueda);
    
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

void buscarNombrePorPalabra(char *V[], char *palabra)
{
    int encontrado=0; 
    for (int i = 0; i < 5; i++) 
    {
        if (strstr(V[i], palabra)!=NULL) 
        {
            printf("Coincidencia encontrada: %s (ID: %d)\n", V[i], i+1);
            encontrado = 1; 
            break; // Sale del bucle
        }
    }
    if (encontrado==0) 
    {
        printf("no se encontro el nombre\n");
    }
}

void buscarNombrePorId(char *V[], int id) 
{
    if (id>0&&id<6) 
    {
        printf("Nombre en ID %d: %s\n", id, V[id-1]);
    } 
    else 
    {
        printf("no se encontro la persona\n");
    }
}