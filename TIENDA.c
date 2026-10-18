
#include <stdio.h>
#include <string.h>

void Ingresaproductos (char nombres[][30], float precios[10], int cantidad)
{
    int i;
    for ( i = 0; i < cantidad; i++)
    {
        printf ("Escribe el nombre %d: ", i + 1);
        scanf  ("%29s",  nombres [i]);
        printf ("Escribe el precio:    " );
        scanf ("%f", &precios [i]);
    }

}

float Totalcalculo (float precios[], int cantidad)

{
    float total = 0;
    int i;
    for ( i = 0; i < cantidad; i++)
    {
        total = total + precios [i];
    }
    return total;
}
void PromedioCalculo (float precios[], int cantidad)

{
    float promedio = Totalcalculo (precios, cantidad )/ cantidad;
    printf ("precio promedio:  %.2f\n", promedio);
}

int PrecioMayor ( float precios[], int cantidad)

{
    int mayor=0;
    int i;

    for ( i = 1; i < cantidad; i++)
    {
        if (precios[i] > precios[mayor])
        {
            mayor = i;
        }
    }
    return mayor;
}

int PrecioMenor (float precios[], int cantidad)

{
    int menor=0;
    int i;

    for ( i = 1; i < cantidad; i++)

    {
        if (precios[i] < precios[menor])
        {
            menor = i;
        }
    }
    return menor;
}

void MayorMenor (char nombres[][30], float precios[10], int cantidad)
{
    int mayor = PrecioMayor (precios, cantidad);
    int menor = PrecioMenor (precios, cantidad);

    printf ("Producto mas caro: %s - %.2f\n", nombres[mayor], precios[mayor]);
    printf ("Producto mas barato: %s - %.2f\n", nombres[menor], precios[menor]);
}

void BuscarProducto (char nombres[][30], float precios[], int cantidad)
{
    char buscado[30];
    int i;
    int encontrado = 0;

    printf ("Escribe el nombre a buscar: ");
    scanf ("%29s", buscado);

    for (i = 0; i < cantidad; i++)
    {
        if (strcmp (nombres[i], buscado) == 0)
        {
            printf ("Encontrado: %s - %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf ("Producto no encontrado\n");
    }
}

int LeerCantidad ()
{
    int cantidad;

    do
    {
        printf ("Ingrese la cantidad de productos (1 a 10): ");
        scanf ("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);

    return cantidad;
}

int main ()
{
    char nombres[10][30];
    float precios[10];
    int cantidad, i;

    cantidad = LeerCantidad ();

    Ingresaproductos (nombres, precios, cantidad);
    printf ("\n Productos ingresados: \n");
    for ( i = 0; i < cantidad; i++)
    {
        printf ("%s - %.2f\n", nombres [i], precios[i]);
    }

    printf ("\n Total:  %.2f\n", Totalcalculo(precios, cantidad));
    printf ("\n");
    MayorMenor (nombres, precios, cantidad);
    printf ("\n");
    PromedioCalculo (precios, cantidad);
    printf ("\n");
    BuscarProducto (nombres, precios, cantidad);

    return 0;

}