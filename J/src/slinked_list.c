#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../include/slinkedlist.h"

// Crear la lista ligada simple, head = NULL, cuando el head apenas se va a iniciar
Slinked_list* create_slinked_list(){
    Slinked_list *slinked_list = (Slinked_list *) malloc (sizeof(Slinked_list));
    slinked_list->head = NULL;
    return slinked_list;
}

//Crear un nodo para ser agregado a la lista
Node* create_node(int item){
    Node *new_node = (Node *) malloc (sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    return new_node;
}

// Detruir(borrar) la lista
void destroy_slinked_list(Node *slinked_list){
    Node *node = slinked_list;
    while(node != NULL){
        Node *temp = node; 
        node = node->next;
        free(temp);
    }   
    free(node); 
}

//Insertar elemento en lista al inicio (head)
void insert_head(Node **head_ref, int item){
    Node *new_node = create_node(item);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int delete_head(Node **head_ref){
    int data;
    if(*head_ref == NULL){
        //printf("Lista vac�a...\n");
        return INT_MIN;
    } else {
        Node *temp = *head_ref;
        *head_ref = temp->next;
        temp->next = NULL;
        data = temp->data;
        free(temp);
    }
    return data;
}

void display(Slinked_list *slinked_list){
    Node *node = slinked_list->head;
    while(node != NULL){
        printf("  %d", node->data);
        node = node->next;
    }
}

void insert_end(Node **head_ref, int item){
    if (*head_ref == NULL){
        insert_head(head_ref, item);
        return;
    }
    Node *new_node = create_node(item);
    Node *last = *head_ref;
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->next =NULL;
}

// Insertar en orden ascendete los numeros enteros
void insert(Node **head, int item){
    Node *new_node = create_node(item);
    Node *aux = *head;
    if (*head == NULL){
        *head = new_node;
    }else {
        if (item<=(*head)->data){
            insert_head(&*head,item);
        }else{
            while((aux->next != NULL) && (aux->next->data < new_node->data))
                aux = aux->next;
            if (aux->next != NULL){
            new_node->next = aux->next;
            aux->next = new_node;
            }else{
                insert_end(&*head,item);
            }
            
        }
    }
}

//Eliminar el primer nodo que contega el valor de item

int delete_node(Node **head, int item){
    if (item == (*head)->data ){
        delete_head(&*head);
        return item;
    }else{
        int data=item;
        Node *prev = *head;
        while((prev->next != NULL) && (prev->next->data != item)){
            prev = prev->next;}
        if (prev->next->data == item){
            Node *ax = prev->next;
            prev->next = ax->next;
            ax->next=NULL;
            data = ax->data;
            free(ax);
        }else{
            data = INT_MAX;
        }
        return data;
    }
    return INT_MIN;
}
