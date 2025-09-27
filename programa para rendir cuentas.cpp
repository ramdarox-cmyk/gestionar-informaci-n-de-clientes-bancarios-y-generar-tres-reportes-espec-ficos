#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100
#define MAX_CUENTAS 100

typedef struct {
    char numeroCuenta[20];
    char tipoMoneda[10];
    float saldo;
} Cuenta;

typedef struct {
    char dni[12];
    char nombre[50];
    int cantidadCuentas;
    Cuenta cuentas[MAX_CUENTAS];
} Cliente;

void reporte4(Cliente clientes[], int n) {
    // Ordenar clientes por nombre
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(clientes[i].nombre, clientes[j].nombre) > 0) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
    printf("Reporte 4: Clientes y sus cuentas\n");
    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, DNI: %s\n", clientes[i].nombre, clientes[i].dni);
        for (int j = 0; j < clientes[i].cantidadCuentas; j++) {
            printf("\tNumero de Cuenta: %s, Saldo: %.2f\n", clientes[i].cuentas[j].numeroCuenta, clientes[i].cuentas[j].saldo);
        }
    }
}

void reporte5(Cliente clientes[], int n, char dniBusqueda[]) {
    printf("Reporte 5: Cuentas en dolares del cliente con DNI %s\n", dniBusqueda);
    for (int i = 0; i < n; i++) {
        if (strcmp(clientes[i].dni, dniBusqueda) == 0) {
            for (int j = 0; j < clientes[i].cantidadCuentas; j++) {
                if (strcmp(clientes[i].cuentas[j].tipoMoneda, "dolares") == 0) {
                    float saldoEnSoles = clientes[i].cuentas[j].saldo * 3.78;
                    printf("\tNumero de Cuenta: %s, Saldo en Dolares: %.2f, Saldo en Soles: %.2f\n",
                           clientes[i].cuentas[j].numeroCuenta, clientes[i].cuentas[j].saldo, saldoEnSoles);
                }
            }
            return;
        }
    }
    printf("\tCliente con DNI %s no encontrado.\n", dniBusqueda);
}

void reporte6(Cliente clientes[], int n, char numeroCuentaBusqueda[]) {
    printf("Reporte 6: Cliente que posee el numero de cuenta %s\n", numeroCuentaBusqueda);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < clientes[i].cantidadCuentas; j++) {
            if (strcmp(clientes[i].cuentas[j].numeroCuenta, numeroCuentaBusqueda) == 0) {
                printf("\tNombre: %s, DNI: %s\n", clientes[i].nombre, clientes[i].dni);
                return;
            }
        }
    }
    printf("\tCuenta no encontrada.\n");
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int n;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", clientes[i].nombre);
        printf("Ingrese el DNI del cliente %d: ", i + 1);
        scanf("%s", clientes[i].dni);

        printf("Ingrese la cantidad de cuentas del cliente %d: ", i + 1);
        scanf("%d", &clientes[i].cantidadCuentas);

        for (int j = 0; j < clientes[i].cantidadCuentas; j++) {
            printf("\tIngrese el numero de cuenta %d: ", j + 1);
            scanf("%s", clientes[i].cuentas[j].numeroCuenta);
            printf("\tIngrese el tipo de moneda (soles/dolares) de la cuenta %d: ", j + 1);
            scanf("%s", clientes[i].cuentas[j].tipoMoneda);
            printf("\tIngrese el saldo de la cuenta %d: ", j + 1);
            scanf("%f", &clientes[i].cuentas[j].saldo);
        }
    }

    reporte4(clientes, n);

    char dniBusqueda[12];
    printf("\nIngrese el DNI para Reporte 5: ");
    scanf("%s", dniBusqueda);
    reporte5(clientes, n, dniBusqueda);

    char numeroCuentaBusqueda[20];
    printf("\nIngrese el Numero de Cuenta para Reporte 6: ");
    scanf("%s", numeroCuentaBusqueda);
    reporte6(clientes, n, numeroCuentaBusqueda);

    return 0;
}
