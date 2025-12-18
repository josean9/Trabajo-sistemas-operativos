// =========================================
// Ejercicio 2
// Sistemas Operativos
// =========================================

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>   

#define SIZE 10

// =========================================
// Apartado 3.1
// =========================================

// Estructura potencia_t
typedef struct {
    int base;
    int exp;
    int potencia;
} potencia_t;

// Tipo puntero a potencia_t
typedef potencia_t* potenciaP_t;

// Inicializa base y exp, y pone potencia a -1
void setBaseExp(potenciaP_t p, int base, int exp) {
    if (p == NULL) return;
    p->base = base;
    p->exp = exp;
    p->potencia = -1;
}

// Calcula base^exp SIN usar pow
int getPotencia(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

// Guarda en la estructura el valor base^exp
void setPotenciaEst(potenciaP_t p) {
    if (p == NULL) return;
    p->potencia = getPotencia(p->base, p->exp);
}

// =========================================
// Apartado 3.2
// =========================================

// Inicializa el array de estructuras
// base = indice + 1
// exp = 0
// potencia = 1
void initArrayEst(potencia_t arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i].base = i + 1;
        arr[i].exp = 0;
        arr[i].potencia = 1;
    }
}

// Muestra el contenido del array
void printArrayEst(potencia_t arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d]: base: %d exp: %d potencia %d\n",
               i, arr[i].base, arr[i].exp, arr[i].potencia);
    }
}

// Función para hebra (thread)
void* calculoPotHeb(void* arg) {
    potencia_t* p = (potencia_t*) arg;

    int res = 1;
    for (int i = 0; i < p->exp; i++) {
        res *= p->base;
    }

    p->potencia = res;
    return NULL;
}

// =========================================
// Apartado 3 – main() completo
// =========================================
int main(void) {

    potencia_t arr1[SIZE];
    potencia_t arr2[SIZE];
    pthread_t hilos[SIZE];
    pid_t pid;
    int status;

    // ---------- ARR1: procesos (fork) ----------
    initArrayEst(arr1);

    printf("\nARR1 inicial:\n");
    printArrayEst(arr1);

    // Modificar exponentes
    for (int i = 0; i < SIZE; i++) {
        arr1[i].exp = i;
    }

    printf("\nARR1 con exponentes modificados:\n");
    printArrayEst(arr1);

    // Cálculo con procesos
    for (int i = 0; i < SIZE; i++) {
        pid = fork();

        if (pid == 0) {  // Proceso hijo
            int res = getPotencia(arr1[i].base, arr1[i].exp);
            exit(res);
        }
        else {
            wait(&status);
            arr1[i].potencia = WEXITSTATUS(status);
        }
    }

    printf("\nARR1 tras fork():\n");
    printArrayEst(arr1);

    // ---------- ARR2: hebras (pthread) ----------
    initArrayEst(arr2);

    printf("\nARR2 inicial:\n");
    printArrayEst(arr2);

    // Modificar exponentes
    for (int i = 0; i < SIZE; i++) {
        arr2[i].exp = i;
    }

    printf("\nARR2 con exponentes modificados:\n");
    printArrayEst(arr2);

    // Cálculo con hebras
    for (int i = 0; i < SIZE; i++) {
        pthread_create(&hilos[i], NULL, calculoPotHeb, &arr2[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("\nARR2 tras pthread:\n");
    printArrayEst(arr2);

    return 0;
}
