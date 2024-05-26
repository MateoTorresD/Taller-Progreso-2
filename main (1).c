/*Se desea desarrollar un sistema de inventarios, el cual implemente las siguientes funcionalidades:
Ingresar, editar y eliminar productos.
Listar productos ingresados.
Los productos ingresados deberán tener mínimo las siguientes variables:
Nombre del producto, Cantidad, Precio*/

#include "funciones.h"
//header funciones con todas las opciones del programa

int main() {
    //declaracion de variables en la funcion main
    int opcion;
    do {
        //imprimir las opciones para el ingreso de datos:
        printf("INVENTARIO DE PAPELERIA: \n");
        printf("[1] Ingresar producto \n");
        printf("[2] Editar producto \n");
        printf("[3] Eliminar producto \n");
        printf("[4] Listar productos \n");
        printf("[5] Salir \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        getchar();

        //switch case para cada una de las opciones:
        switch (opcion) {
            case 1:
                IngresarProductos();
                break;
            case 2:
                EditarProductos();
                break;
            case 3:
                EliminarProductos();
                break;
            case 4:
                ListarProductos();
                break;
            case 5:
                printf("Saliendo...\n");
                printf("Gracias por su visita\n");
                break;
            default:
                printf("\n");
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 5);
    return 0;
}