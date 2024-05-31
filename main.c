#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char nombresproduc[10][3][30] = {{"Leche", "22", "2025-12-01"},
                                    {"Queso", "10", "2025-01-15"},
                                    {"Agua", "35", "2025-05-20"},
                                    {"Aceite", "25", "2025-11-30"},
                                    {"Atun", "50", "2025-07-25"},
                                    {"Yogurt", "32", "2025-02-10"}};
    char nombreAbuscar[30];
    double precio[6] = {1.50, 5, 4.3, 6.65, 4.23, 2.25};
    int n = 6;
    int opcion1, opcion2;

    do {
        printf("Seleccione una opcion:\n1. Ingresar Productos\n2. Imprimir Inventario\n3. Buscar Productos\n4. Editar Productos\n5. Agregar Producto\n6. Eliminar Producto\n>>");
        scanf("%d", &opcion1);
        switch (opcion1) {
            case 1:
                ingresarProductos(nombresproduc, precio, n);
                break;
            case 2:
                imprimirInventario(nombresproduc, precio, n);
                break;
            case 3:
                printf("Ingrese el producto que desea buscar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar); 
                int index = buscarProductoXNombre(nombresproduc, nombreAbuscar, n);
                imprimirProductoXIndice(nombreAbuscar, nombresproduc, precio, index);
                break;
            case 4:
                printf("Ingrese el nombre del producto que desea editar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar); 
                editarProducto(nombreAbuscar, nombresproduc, precio, n);
                break;
            case 5:
                agregarProducto(nombresproduc,precio,&n);
                break;
            case 6:
                printf("Ingrese el nombre del producto que desea eliminar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar);
                eliminarProducto(nombresproduc, precio, &n, nombreAbuscar);
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
        printf("Desea elegir una nueva opcion: 1.Si / 2.No\n>>");
        scanf("%d", &opcion2);
    } while (opcion2 == 1);

    return 0;
}