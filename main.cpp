#include <iostream>
#include <fstream>
#include <cstdio>
/*
 * ENTRADAS:
 *          -grupo*
 *          -nombre*
 *          -apellido*
 *          -telefono*
 *          -correo electronico*
 *PROCESOS:
 *          -crear archivo txt contacto*
 *          -crear archivo txt indice
 *                                    -grupo, apellido y posicion
 *          -editar contacto/eliminar
 *          -buscar por nombre/apellido
 */

//CREA UN GRUPO NULO, OSEA UN "SIN GRUPO"
struct Datos{
    char grupo[50];
    char nombre[50];
    char apellido[50];
    int telefono;
    char correo_electronico[50];
};
char nombre_arch[30]; //nombre del archivo a ser creado
void datos(Datos *pedir);
void guardar_datos();
void lectura();
void menu();
void menu_dos(int &opcion);

using namespace std;

int main() {
    int opcion;
    menu();
    cin>> opcion;
    menu_dos(opcion);

    return 0;
}
/*
* Nombre de la función: guardar_datos
* Tipo de función: void
* Parámetros: sin parametros
* Dato de retorno: sin retorno
* Descripción de la función: Crea un archivo.txt y almacena
*                            los datos solicitados en la funcion
*                            datos_contacto usando *&, que se
*                            utiliza para obtener la dirección de
*                            memoria de la variable
*/
void guardar_datos() {
    Datos guardar{};
    FILE *arch = fopen(nombre_arch, "a+");  //creacion de archivo en modo en que  permite leer y agregar información en un archivo que existe. Si no existe se crea.
    datos(&guardar);
    fprintf(arch, "%s %s \n %s %s \n",      //Imprimimos en el archvio .txt los guardar solicitados
            "Grupo: ", *&guardar.grupo,
            "Nombre: ", *&guardar.nombre);
    fprintf(arch, "%s %s \n %s %d \n",
            "Apellido: ", *&guardar.apellido,
            "Telefono: ", *&guardar.telefono);
    fprintf(arch, "%s %s \n ",
            "Correo electronico: ", *&guardar.correo_electronico);
    fprintf(arch, "%s \n", "-----------------");

    fclose(arch);                                      //cerramos el archivo
}
/*
* Nombre de la función: datos
* Tipo de función: void
* Parámetros: puntero de Datos "contactos" struct
* Dato de retorno: sin retorno
* Descripción de la función: Solicita los datos del
*                            contacto y los almacena
*                            en la estructura Datos mediante
*                            el uso de punteros
*/
void datos(Datos *pedir) {                                     //funcion para solicitar datos de usuario creados en un struct
    cout << "Ingrese los datos del contacto que desea guardar_datos \n";
    cout << "Grupo: ";
    scanf("%s", pedir->grupo);
    cout << "Nombre: ";
    scanf("%s", pedir->nombre);                       //llenado de dato previamente creado, con formato solicitado
    cout << "Apellido: ";
    scanf("%s", pedir->apellido);
    cout << "Telefono: ";
    scanf("%u", &(pedir->telefono));
    cout << "Correo electronico: ";
    scanf("%s", pedir->correo_electronico);
    cout << "--------------------------------"<< endl; // el end1 es para asegurar que el texto se muestre antes de continuar con la siguiente instrucción.
}
/*
* Nombre de la función: lectura
* Tipo de función: void
* Parámetros: sin parametros
* Dato de retorno: sin retorno
* Descripción de la función: Abre el archivo txt con el nombre
*                            que ingresemos, copia los archivos
*                            en una variable temporal llamado texto
*                            y los lee, además de corroborar su existencia
*/
void lectura() {
    char nombre_lista[20];
    cin>> nombre_lista;
    ifstream archivo;
    string texto;
    archivo.open(nombre_lista, ios::in);//abrimos un archivo en modo lectura
    if (archivo.fail()) {
        cout<<"ERROR, no se puedo encontrar el archivo con el nombre ingresado\n";
    }
    while (!archivo.eof()) {//mientras no sea el final del archivo
        getline(archivo, texto);
        cout<< texto.c_str();
    }
    archivo.close();
}
/*
* Nombre de la función: menu
* Tipo de función: void
* Parámetros: sin parametros
* Dato de retorno: sin retorno
* Descripción de la función: Muestra en pantalla las opciones
*/
void menu(){
    cout << "Que funcion desea realizar: \n";
    cout << "[1] Crear nuevo registro  \n";
    cout << "[2] Mostrar contactos \n"; // Agenda o Grupo
    cout << "[3] Mostrar grupos \n";
    cout << "[4] Editar contacto \n";
    cout << "[5] Buscar contacto \n"; // Nombre o Apellido
    cout << "[6] Eliminar contacto \n";
}
void menu_dos(int &opcion){
    if(opcion==4){
        cout << "Seleccione una opción: \n";
        cout << "[1] Editar contacto \n";
        cout << "[2] Eliminar contacto \n";    }
    else if (opcion == 5) {
        cout << "Seleccione una opción: \n";
        cout << "[1] Buscar por nombre \n";
        cout << "[2] Buscar por apellido \n";
    }
    cin>> opcion;
}
