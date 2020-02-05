#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <time.h>
#define MAXLONG 10

typedef struct Pila{
    int istack[MAXLONG];
    int top;
}Stack;

//TODO: Update prototypes functions values
int valid_push(Stack *);
void push(int,Stack *);
void push_all(Stack *);
int valid_pop(Stack *);
void pop(Stack *);
void pop_all(Stack *);
void display(Stack *);



void main(){//Send a pointer to Struct array
    int ioption,inum, istack;
    Stack stck[2];
    Stack *ptstack;
    ptstack = stck;//This pointer point to the first element of the Struct array
    //printf("\nDireccion: %p",ptstack);
    //printf("\nDireccion++: %p",ptstack+1);
    stck[0].top = -1;
    stck[1].top = -1;
    do{
        Sleep(5000);
        system("cls");
        printf("Menu\n");
        printf ("------------------------------------------\n");
        printf ("1) PUSH\n");
        printf ("2) PUSH-ALL\n");
        printf ("3) POP\n");
        printf ("4) POP-ALL\n");
        printf ("5) DISPLAY\n");
        printf ("6) EXIT\n");
        printf ("------------------------------------------\n");
        printf("Elige la opcion que deseas: \n");
        scanf("%d",&ioption);
        switch(ioption){
            case 1:
                printf("Dato a insertar: ");
                scanf("%d",&inum);
                istack = seleccion_pila();
                if(istack == 1)
                    push(inum, ptstack);
                else
                    push(inum, ptstack+1);
            break;
            case 2:
                istack = seleccion_pila();
                if(istack == 1)
                    push_all(ptstack);
                else
                    push_all(ptstack+1);
            break;
            case 3:
                istack = seleccion_pila();
                if(istack == 1)
                    pop(ptstack);
                else
                    pop(ptstack+1);
            break;
            case 4:
                istack = seleccion_pila();
                if(istack == 1)
                    pop_all(ptstack);
                else
                    pop_all(ptstack+1);
            break;
            case 5:
                //system("cls");
                istack = seleccion_pila();
                if(istack == 1)
                    display(ptstack);
                else
                    display(ptstack+1);
            break;
            case 6:
                exit(0);
            break;
            default:
                printf("\nSomething is wrong");
        }

    }while(ioption != 5);
}
int seleccion_pila(){
    //TODO: Valid the stack value, just is allow 1 o 2
    int ipila;
    printf("Pila a trabajar: ");
    scanf("%d",&ipila);
    while(ipila > 2 || ipila < 1){
        printf("Elija la pila 1 o la pila 2: ");
        scanf("%d",&ipila);
    }
    return ipila;
}
int valid_push(Stack *ptpila){
    if(ptpila->top == (MAXLONG-1))//Stack is fill
        return 0;
    else //Stack has space
        return 1;
}
void push(int numero, Stack *ptstack){
    //printf("\nDireccion: %p",ptstack);
    switch(valid_push(ptstack)){
        case 0: // Stack is all fill
            printf("\nLa pila esta llena");
        break;
        case 1:// Stack has space
            ptstack->top++;
            ptstack->istack[ptstack->top] = numero;
            printf("\nSe ha agregado correctamente el nuevo dato\nTop: %d",ptstack->top);
        break;
    }
}
void push_all(Stack *ptstack){
    int i;
    valid_push(ptstack);
    //srand(time(0));
    if(ptstack->top < 0){//Stack is void
        for( ptstack->top+1 ; ptstack->top< (MAXLONG-1); ptstack->top++){
            ptstack->istack[ptstack->top] = rand() % -50;
            printf("\nTop: %d",ptstack->top);
        }
    }
    else{
        for( ptstack->top ; ptstack->top< MAXLONG ; ptstack->top++){
            ptstack->istack[ptstack->top] = rand() % -50;
            printf("\nDato: %d \nTop: %d",ptstack->istack[ptstack->top],ptstack->top);
        }
    }
}
int valid_pop(Stack *ptpila){
    if(ptpila->top == -1)//Stack is void
        return 0;
    else
        return 1;
}
void pop(Stack *ptstack){
    //printf("\nDireccion: %p",ptstack);
    switch(valid_pop(ptstack)){
        case 0: // Stack one is avoid
            printf("\nLa pila esta vacia");
        break;
        case 1:// Stack one has almost 1 element
            ptstack->istack[ptstack->top] = 0;
            ptstack->top--;
            printf("\nEl dato en el tope ha sido eliminado\nTop: %d",ptstack->top);
        break;
    }
}
void pop_all(Stack *ptstack){
    int i;
    //printf("\nDireccion: %p",ptstack);
    switch(valid_pop(ptstack)){
        case 0: // Stack one is avoid
            printf("\nLa pila ya esta vacia");
        break;
        case 1:// Stack one has almost 1 element
            for(ptstack->top; ptstack->top>=0; ptstack->top--){
                ptstack->istack[ptstack->top] == 0;//Cero means the element is deleted
                printf("\nEliminando...\nTop: %d",ptstack->top);
            }
        break;
    }
}
void display(Stack *ptstack){
    int i;
    //printf("\nDireccion: %p",ptstack);
    //printf("\nPila %d", pila);
    if(ptstack->top < 0){//Stack is void
        printf("\nLa pila esta vacia");
    }
    else{
        for(i = ptstack->top; i>=0; i--){
            printf("\n%d",ptstack->istack[i]);
        }
    }
    main();
}
