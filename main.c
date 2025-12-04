#include <stdio.h>
#include "common.h"          // Para ContextoPvv
#include "command_parser.h"  // Para loop_principal

void mostrar_bienvenida() {
    printf("\n");
    printf("-------------------------------------------------------\n");
    printf("       SISTEMA DE GESTION DE RUTAS (PVV) - TAREA 4     \n");
    printf("-------------------------------------------------------\n");
    printf(" INSTRUCCIONES:\n");
    printf(" El sistema mostrara el prompt '>pvv'. A continuacion,\n");
    printf(" ingresa uno de los siguientes comandos:\n\n");
    
    printf("  1. INICIAR EL GRAFO:\n");
    printf("     start <N>       -> Crea un grafo vacio de N nodos (Max %d)\n", PVV_MAX_NODOS);
    printf("     Ejemplo: start 5\n\n");
    
    printf("  2. CARGAR DATOS:\n");
    printf("     read <archivo>  -> Carga las conexiones desde un .txt\n");
    printf("     Ejemplo: read ruta.txt\n\n");
    
    printf("  3. VISUALIZAR:\n");
    printf("     graph           -> Muestra la matriz de adyacencia\n\n");
    
    printf("  4. SALIR:\n");
    printf("     exit            -> Cierra el programa\n");
    printf("-------------------------------------------------------\n\n");
}

int main() {
    // Es importante iniciar el puntero en NULL para que memory_manager sepa que está vacío.
    ContextoPvv contexto;
    contexto.grafo_actual = NULL; 

    // Muestra pantalla de bienvenida e instrucciones
    mostrar_bienvenida(); 

    // El programa se queda atrapado aquí dentro hasta que el usuario escriba 'exit'
    loop_principal(&contexto);

    // Salida del sistema
    // Cuando loop_principal termina, el main termina.
    return 0;
}