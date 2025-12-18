// =========================================
// ej1.c
// Ejercicio 1 – Sistemas Operativos
// =========================================

#include <stdio.h>

#define SIZE 10

// =========================================
// Apartado 1
// Definición de la estructura y typedef
// =========================================

typedef struct {
    int arrInt[SIZE];   // Array de enteros
    int arrSize;        // Número de elementos válidos
    int arrAdd;         // Suma de los elementos
} arrayLength_t;

// =========================================
// Apartado 2
// Funciones initArray, printArr y addElement
// =========================================

// Inicializa la estructura
int initArray(arrayLength_t *a) {
    if (a == NULL) return -1;

    for (int i = 0; i < SIZE; i++) {
        a->arrInt[i] = -1;   // -1 indica posición vacía
    }

    a->arrSize = 0;
    a->arrAdd  = 0;

    return 0;
}

// Muestra el contenido de la estructura
void printArr(const arrayLength_t *a) {
    if (a == NULL) return;

    printf("{[");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", a->arrInt[i]);
        if (i < SIZE - 1) printf(", ");
    }
    printf("], %d, %d}\n", a->arrSize, a->arrAdd);
}

// Añade un elemento al array
int addElement(arrayLength_t *a, int value) {
    if (a == NULL) return -1;
    if (value <= 0) return -1;
    if (a->arrSize >= SIZE) return -1;

    a->arrInt[a->arrSize] = value;
    a->arrSize++;
    a->arrAdd += value;

    return 0;
}

// =========================================
// Apartado 3
// Funciones de consulta (getters)
// =========================================

int getArrSize(const arrayLength_t *a) {
    if (a == NULL) return -1;
    return a->arrSize;
}

int getArrAdd(const arrayLength_t *a) {
    if (a == NULL) return -1;
    return a->arrAdd;
}

int getElement(const arrayLength_t *a, int index) {
    if (a == NULL) return -1;
    if (index < 0 || index >= a->arrSize) return -1;

    return a->arrInt[index];
}

// =========================================
// Apartado 4
// Modificación de un elemento del array
// =========================================

int setElement(arrayLength_t *a, int index, int value) {
    if (a == NULL) return -1;
    if (value <= 0) return -1;
    if (index < 0 || index >= a->arrSize) return -1;

    a->arrAdd -= a->arrInt[index];
    a->arrInt[index] = value;
    a->arrAdd += value;

    return 0;
}

// =========================================
// Apartado 5
// Reinicio de la estructura
// =========================================

int resetArr(arrayLength_t *a) {
    if (a == NULL) return -1;

    for (int i = 0; i < SIZE; i++) {
        a->arrInt[i] = -1;
    }

    a->arrSize = 0;
    a->arrAdd  = 0;

    return 0;
}

// =========================================
// Apartado 6
// Programa principal de prueba
// =========================================

int main(void) {
    arrayLength_t al1, al2;

    // Inicialización de estructuras
    initArray(&al1);
    initArray(&al2);

    // 1) al1 almacena los valores 0, 10, 20, ..., 90
    for (int i = 0; i < SIZE; i++) {
        addElement(&al1, i * 10);
    }

    // 2) Mostrar al1
    printArr(&al1);

    // 3) Actualizar posiciones impares con 1, 3, 5, 7, 9
    for (int i = 1; i < al1.arrSize; i += 2) {
        setElement(&al1, i, i);
    }

    // 4) Mostrar de nuevo al1
    printArr(&al1);

    // 5) Copiar posiciones pares de al1 en al2
    for (int i = 0; i < al1.arrSize; i += 2) {
        addElement(&al2, getElement(&al1, i));
    }

    // 6) Actualizar las posiciones finales de al2 con valores de 0 a 4
    for (int i = 0; i < 5; i++) {
        setElement(&al2, al2.arrSize - 5 + i, i);
    }

    // 7) Mostrar al2
    printArr(&al2);

    return 0;
}
