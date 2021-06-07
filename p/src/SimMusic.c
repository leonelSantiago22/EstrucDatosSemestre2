
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

struct node
{
    int num;
    int anio;
    char cancion[MAX];
    char artista[MAX];
    char genero[MAX];

    struct node *next;
    struct node *prev;
};

time_t t;

struct node *insert(struct node *front, int n, char song[], char artist[], char gen[], int year)

{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\nError en la asignacion! \n");
        exit(2);
    }
    newnode->num = n;
    strcpy(newnode->cancion, song);
    strcpy(newnode->artista, artist);
    strcpy(newnode->genero, gen);
    newnode->anio = year;
    newnode->next = front;
    front = newnode;
    return(front);
} 

void printNode(struct node *p)
{
    
    printf("\n==>cancion: %d\n", p->num);
    printf("Nombre de la cancion: %s\n", p->cancion);
    printf("Nombre del artista: %s\n", p->artista);
    printf("Genero musical: %s\n", p->genero);
    printf("Año de lanzamiento: %d", p->anio);
    printf("\n==============================================================\n");

}

struct node* deleteNode(struct node *front, int n)
{
    struct node *ptr;
    struct node *bptr;

    if(front->num == n)
    {
        ptr = front;
        printNode(front);
        printf("Cancion %d eliminado... ", n);
        front = front->next;
        free(ptr);
        return(front);
    }
    for(ptr = front->next, bptr = front; ptr !=  NULL; ptr = ptr->next, bptr = bptr->next)
    {
        if(ptr->num == n)
        {
            printNode(ptr);
            printf("Cancion %d eliminado... ", n);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("Cancion %d no encontrado en la lista", n);
    return(front);
}

void display(struct node *front)
{
    struct node *ptr;

    for(ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}

void actually(struct node *front)
{
    time(&t);
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode=front;
    if(newnode != NULL){
        printf("\n\n\t Reproduciendo: %s %s %d %s", newnode->num, newnode->artista, newnode->anio, ctime(&t));
    }else{
        printf("");
    }
}

int main()
{
    struct node *linkList;
    char song[MAX], artist[MAX], gen[MAX];
    int n, eno;

    linkList = NULL;
    int option, op2, op3;
    do
    {
        printf("\n\t __________________________________\n");
        printf("\t|==> Alejandro Menoza Hernandez <==|\n");
        printf("\t|   Reproductor: Menu principal    |\n");
        printf("\t|__________________________________|\n");
        printf("\t|                                  |\n");
        printf("\t| 1.- Editar lista de reproduccion |\n");
        printf("\t| 2.- Reproducir                   |\n");
        printf("\t| 3.- Salir                        |\n");
        printf("\t|__________________________________|\n");
        printf("\n\n Ingresa una opcion(1-3): ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                do
                {
                    printf("\n\t ___________________________________\n");
                    printf("\t|=>Reproductor: Menu editar lista <=|\n");
                    printf("\t|___________________________________|\n");
                    printf("\t|                                   |\n");
                    printf("\t| 1.- Agregar una cancion           |\n");
                    printf("\t| 2.- Eliminar una cancion          |\n");
                    printf("\t| 3.- Mostrar lista de reproduccion |\n");
                    printf("\t| 4.- Regresar al menu principal    |\n");
                    printf("\t|___________________________________|\n");
                    printf("\n\n Ingresa una opcion(1-4): ");
                    scanf("%d", &op2);
                    switch(op2)
                    {
                        case 1:

                            printf("\nIngresa el numero de la cancion: ");
                            scanf("%d", &n);
                            printf("\nIngresa el nombre de la cancion: ");
                            fflush(stdin);
                            gets(song);
                            printf("\nIngresa el nombre del artista: ");
                            fflush(stdin);
                            gets(artist);
                            printf("\nIngresa el genero musical: ");
                            fflush(stdin);
                            gets(gen);
                            printf("\nIngresa el año de lanzamiento: ");
                            scanf("%d", &eno);
                            linkList = insert(linkList, n,  song, artist, gen, eno);
                            printf("\nCancion agregada exitosamente a la lista...\n");
                            break;

                        case 2:
                            
                            if(linkList == NULL)
                            {
                                printf("\n\tLa lista  esta Vacia");
                                break;
                            }
                            printf("\n\nIngrese el numero de la cancion a eliminar: ");
                            scanf("%d", &n);
                            printf("\n==============================================================");
                            linkList = deleteNode(linkList, n);
                            break;
                        case 3:
                            if(linkList == NULL)
                            {
                                printf("\n\tLa lista  esta Vacia");
                                break;
                            }
                            printf("\n==============================================================");
                            printf("\nLista de Reproduccion...\n");
                            printf("==============================================================");
                            display(linkList);
                            break;
                        case 4:
                            break;
                        default: printf("\nOpción inválida, intenta de nuevo...");
                    }
                } while (op2 != 4);
                
                break;
            case 2:
                do
                {
                    printf("\n\t _______________________________________________\n");
                    printf("\t|        =>Reproductor: Menu reproducir<=       |\n");
                    printf("\t Reproduciendo: Cancion=>%d=> %s=> %s \n", n,song, artist);
                    printf("\t|_______________________________________________|\n");
                    printf("\t|                                               |\n");
                    printf("\t| 1.- Reproducir(Play)                          |\n");
                    printf("\t| 2.- Siguiente                                 |\n");
                    printf("\t| 3.- Anterior                                  |\n");
                    printf("\t| 4.- Regresar al menu principal                |\n");
                    printf("\t|_______________________________________________|\n");
                    printf("\n\n Ingresa una opcion(1-4): ");
                    scanf("%d", &op3);
                    switch(op3)
                    {
                        case 1: 
                            
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        default: printf("\nOpción inválida, intenta de nuevo...");
                    }
                } while (op3 != 4);
                
                break;
            case 3:
                break;
            default: printf("Opción inválida, intenta de nuevo: ");
        }
    } while (option != 3);
    
}