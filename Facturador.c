#include <stdio.h>
#include <stdlib.h>
//Facturadora Realizada Por Pablo Vargas//
int main(void) {

  char nombre [20];
  char cedula[14];
  char Direccion [100];
  char telefono [20];

  int opcion;

  printf("Nombre: ");
  fgets(nombre,20,stdin);
  printf("Numero de Cedula: ");
  do{
        scanf("%s", cedula);
        if(validarCedula(cedula)==0){
            printf("Su numero de cedula no es valido. Ingrese de nuevo: ");
        }else{
            printf("Numero de cedula valido.\n");
        }
    }while(validarCedula(cedula)==0);
    getchar();
  printf("Direccion: ");
  fgets(Direccion,100,stdin);
  printf("Numero de telefono: ");
  fgets(telefono,20,stdin);
  printf("DETALLE\n");

  int cantidadllantas = 0;
  int preciollantas = 150;
  char detllantas [10] = "Llantas";

  int cantidadfreno = 0;
  int preciofreno = 55;
  char detfreno [30] = "Kit freno";

  int cantidadembrague = 0;
  int precioembrague = 180;
  char detembrague [20] = "Kit embrague";

  int cantidadfaro = 0;
  int preciofaro = 70;
  char detfaro [10] = "Faro";

  int cantidadradiador = 0;
  int precioradiador = 120;
  char detradiador [10] = "Radiador";

  do{

    int llantas = 0;
    int frenos = 0;
    int embrague = 0;
    int faros = 0;
    int radiadores = 0;

    printf("Seleccione el producto que desea comprar\n");
    printf("1. Llantas\n");
    printf("2. Kit Pastillas de freno\n");
    printf("3. Kit de embrague\n");
    printf("4. Faro\n");
    printf("5. Radiador\n");
    printf("6. Salir y Generar Factura\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
      case 1:

        printf("Cantidad de llantas que desea comprar: ");
        scanf("%d", &llantas);
        cantidadllantas+=llantas;
        break;

      case 2:

        printf("Cantidad de pastillas de freno que desea comprar: ");
        scanf("%d", &frenos);
        cantidadfreno+=frenos;
        break;

      case 3:

        printf("Cantidad de kits de embrague que desea comprar: ");
        scanf("%d", &embrague);
        cantidadembrague+=embrague;
        break;

      case 4:

        printf("Cantidad de faros que desea comprar: ");
        scanf("%d", &faros);
        cantidadfaro+=faros;
        break;

      case 5:

        printf("Cantidad de radiadores que desea comprar: ");
        scanf("%d", &radiadores);
        cantidadradiador+=radiadores;
        break;

      case 6:
        printf("Gracias por usar\n");
        break;

      default:
        printf("Incorrecto, vuelva a ingresar.");
        break;
    }
  }while(opcion!=6);

  int tllantas = cantidadllantas*preciollantas;
  int tfreno = cantidadfreno*preciofreno;
  int tembrague = cantidadembrague*precioembrague;
  int tfaro = cantidadfaro*preciofaro;
  int tradiador = cantidadradiador*precioradiador;

  int subtotal = tllantas + tfreno + tembrague + tfaro + tradiador;


  printf("\n------------------------FACTURA------------------------\n" );
  printf("\nNombre y Apellido: ");
  puts (nombre);
  printf("\nC.I.: " );
  puts (cedula);
  printf("\nDireccion: ");
  puts(Direccion);
  printf("\nTelf.: ");
  puts(telefono);
  printf("----------------DETALLE---------------\n");
 printf("\nCantidad \t Codigo \t Detalle \t P/U \t Precio Total \n");
  if(cantidadllantas>=1){
    printf("%d\t\t L1NT\t\t %s\t $%d\t\t $%d\n", cantidadllantas, detllantas, preciollantas, tllantas);
  }
  if(cantidadfreno>=1){
    printf("%d\t\t KF1N\t\t %s\t $%d\t\t $%d\n", cantidadfreno, detfreno, preciofreno, tfreno);
  }
  if(cantidadembrague>=1){
    printf("%d\t\t K3M8\t\t %s\t $%d\t\t $%d\n", cantidadembrague, detembrague, precioembrague, tembrague);
  }
  if(cantidadfaro>=1){
    printf("%d\t\t F4R05\t\t %s\t\t $%d\t\t $%d\n", cantidadfaro, detfaro, preciofaro, tfaro);
  }
  if(cantidadradiador>=1){
    printf("%d\t\t RDDR\t\t %s\t $%d\t\t $%d\n", cantidadradiador, detradiador, precioradiador, tradiador);
  }
  printf("Subtotal:\t\t\t\t\t\t\t $%d\n", subtotal);
  int descuento;
  if(subtotal < 501){
    if(subtotal < 101){
      descuento=0;
      printf("Descuento 0%:\t\t\t\t\t\t\t -$%d\n", descuento);
    }else{
      descuento = subtotal*0.05;
      printf("Descuento 5%:\t\t\t\t\t\t\t -$%d\n", descuento);
    }
  }else{
    if(subtotal < 1000){
      descuento = subtotal*0.07;
      printf("Descuento 7%:\t\t\t\t\t\t\t -$%d\n", descuento);
    }else{
      descuento = subtotal*0.1;
      printf("Descuento 10%:\t\t\t\t\t\t\t -$%d\n", descuento);
    }
  }
  int des_total = subtotal - descuento;
  printf("Subtotal con descuento:\t\t\t\t\t\t $%d\n", des_total);
  int iva = subtotal*0.12;
  printf("Total iva 12%:\t\t\t\t\t\t\t +$%d\n", iva);
  int total = subtotal - descuento + iva;
   printf("_____________________________________________________________________\n");
  printf("Total: \t\t\t\t\t\t\t\t $%d\n", total);
  printf("_____________________________________________");
  return 0;
}   
int validarCedula(const char* cedula){
    int tamaño;
    int caracteres = 0;
    int numeros[10];
    int suma = 0;
    int verificador;

    tamaño = strlen(cedula);

    if(tamaño != 10){
        return 0;
    }else{
        caracteres = 0;
        for(int i = 0; i < 10; i++){
          if(isdigit(cedula[i])==0){
           caracteres++;
          }
        }
        if (caracteres > 0){
          return 0;
        }
    }

    for(int i = 0; i < 10; i++){
        numeros[i] = cedula[i] - '0';
    }

    for(int i = 0; i < 9; i++){
        if(i % 2 == 0){
            if(numeros[i]*2 > 9){
                suma += (numeros[i]*2) - 9;
            }else{
                suma += (numeros[i]*2);
            }
        }else{
            suma += numeros[i];
        }   
    }

    verificador = suma + numeros[9];

    if(verificador % 10 == 0){
        return 1;
    }else{
        return 0;}
}