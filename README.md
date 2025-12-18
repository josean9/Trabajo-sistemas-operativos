# Trabajo-sistemas-operativos
Enlace al repositorio en github: https://github.com/josean9/Trabajo-sistemas-operativos.git
Sistemas Operativos – Ejercicio Feedback 1

Este repositorio contiene la propuesta de solución al Ejercicio Feedback 1 de la asignatura Sistemas Operativos del Grado en Ingeniería Matemática.

📂 Contenido del repositorio

El repositorio incluye los siguientes elementos:

ej1.c
Implementación del Ejercicio 1, centrado en el uso de estructuras en C para la gestión de un array de enteros, junto con funciones de inicialización, inserción, consulta, modificación y reinicio de datos.

ej2.c
Implementación del Ejercicio 2, donde se trabaja con estructuras que representan potencias y se compara el cálculo de las mismas utilizando procesos (fork) y hebras (pthread), ejecutado en entorno Linux (WSL).

Memoria.pdf
Documento en formato PDF que recoge:

La explicación detallada del desarrollo de los Ejercicios 1 y 2

Capturas de la compilación y ejecución de los programas

La resolución completa del Ejercicio 3, incluyendo cronogramas y tiempos de espera y retorno

Un anexo final con el código completo de los ejercicios

🛠️ Entorno de desarrollo

Lenguaje: C

Compilador: gcc

Sistema operativo: Linux (WSL – Ubuntu)

Librerías utilizadas: stdio.h, stdlib.h, unistd.h, sys/wait.h, pthread.h

▶️ Compilación y ejecución

Para compilar y ejecutar los ejercicios:

gcc ej1.c -o ej1
./ej1

gcc ej2.c -o ej2 -pthread
./ej2

📌 Notas finales

Este repositorio ha sido desarrollado siguiendo las indicaciones proporcionadas en el enunciado del ejercicio, estructurando el código por apartados y documentando el proceso en la memoria entregada.
