#include <stdio.h>
#include <string.h>

//constantes 
#define Longitud_Nombre 50
#define Maximo_Productos 100

//variables globales
int cantidad_productos = 0;
char MatrizNombresProductos[Maximo_Productos][Longitud_Nombre];
float Precios_Productos[Maximo_Productos];
float PrecioTotal_Productos[Maximo_Productos];
int Cantidades_Productos[Maximo_Productos];
int i = 0;
char nombre_producto[Longitud_Nombre];

//funciones a usar en el programa
void IngresarProductos(); //funcion que ingresa los productos y los almacena
void ListarProductos(); //funcion que muestra los productos ingresados
void EditarProductos(); //funcion que edita los productos ingresados
void EliminarProductos(); //funcion que elimina los productos ingresados


void IngresarProductos() {
    if (cantidad_productos >= Maximo_Productos) {
        printf("El inventario esta lleno...\n");
        return;
    }
    printf("Ingrese el nombre del producto: \n");
    fgets(MatrizNombresProductos[cantidad_productos], Longitud_Nombre, stdin);
    printf("Ingrese la cantidad del producto: \n");
    scanf("%d", &Cantidades_Productos[cantidad_productos]);
    printf("Ingrese el precio del producto: \n");
    scanf("%f", &Precios_Productos[cantidad_productos]);
    cantidad_productos++;
    printf("------Se ha ingresado un nuevo producto------\n");
    printf("\n");
}

void EditarProductos() {
    printf("Ingrese el nombre del producto que desea editar: \n");
    fgets(nombre_producto, Longitud_Nombre, stdin);
    for (i = 0; i < cantidad_productos; i++) {
        if (strcmp(MatrizNombresProductos[i], nombre_producto) == 0) {
        //comparar la posicion actual de la matriz con el producto que se desea editar
            printf("------Producto encontrado------\n");
            printf("\n");
            printf("Ingrese el nuevo nombre del producto:\n");
            fgets(MatrizNombresProductos[i], Longitud_Nombre, stdin);
            printf("Ingrese la nueva cantidad: ");
            scanf("%d", &Cantidades_Productos[i]);
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &Precios_Productos[i]);
            printf("\n");
            printf("------Producto actualizado exitosamente------\n");
            printf("\n");
            return;
        }
    }
    printf("------Producto no encontrado------\n");
    printf("\n");
}

void ListarProductos() {
    if (cantidad_productos == 0) {
        printf("No hay productos aun...\n");
        printf("\n");
        return;
    }
    printf("------Listado de productos------\n");
  printf("\n");
    for (i = 0; i < cantidad_productos; i++) {
        printf("          PRODUCTO %d       \n", i + 1);
        printf("\n");
        printf("NOMBRE: %s\n", MatrizNombresProductos[i]);
        printf("CANTIDAD: %d\n", Cantidades_Productos[i]);
        printf("\n");
        printf("PRECIO UNITARIO: %.2f\n", Precios_Productos[i]);
        printf("\n");
        PrecioTotal_Productos[i]=Cantidades_Productos[i]*Precios_Productos[i];
        printf("PRECIO TOTAL: %.2f\n", PrecioTotal_Productos[i]);
        printf("\n");
    }
  printf("\n");
}

void EliminarProductos(){
    printf("Ingrese el nombre del producto que desea eliminar: \n");
    fgets(nombre_producto, Longitud_Nombre, stdin);

    for (i = 0; i < cantidad_productos; i++){
        if (strcmp(MatrizNombresProductos[i], nombre_producto) == 0){
            for (int j = i; j < cantidad_productos - 1; j++) {
                strcpy(MatrizNombresProductos[j], MatrizNombresProductos[j + 1]);
            //copiar la matriz en la posicion actual a la siguiente posicion para sobreescribir el producto eliminado
                Cantidades_Productos[j] = Cantidades_Productos[j + 1];
                Precios_Productos[j] = Precios_Productos[j + 1];
            }
            cantidad_productos--;
            printf("------Producto eliminado exitosamente------\n");
            printf("\n");
            return;
        }
    }
    printf("------Producto no encontrado------\n");
    printf("\n");
}
    
