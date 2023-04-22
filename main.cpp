#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

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
using namespace std;
//CREA UN GRUPO QUE SEA NULO, OSEA, UN "SIN GRUPO" (nota propia)


char grupo[50];
char nombre[50];
char apellido[50];
int telefono;
char correo_electronico[50];

char nombre_arch[20] = "contactos.txt"; //nombre del archivo a ser creado
char nombre_indi[20] = "indice.txt";

void guardar_datos();
string lectura();
void menu();
void menu_dos(int &opcion);
void buscar(string palabra);
void cambio();
char * datos();


int main() {
    guardar_datos();
    lectura();

    return 0;
}

void guardar_datos() {
    datos();
    FILE *arch = fopen(nombre_arch, "a+");  //creacion de archivo en modo en que  permite leer y agregar información en un archivo que existe. Si no existe se crea.
    fprintf(arch, "%s %s \n %s %s \n",      //Imprimimos en el archvio .txt los guardar solicitados
            "Grupo: ", datos(),
            "Nombre: ", nombre);
    fprintf(arch, "%s %s \n %s %d \n",
            "Apellido: ", apellido,
            "Telefono: ", telefono);
    fprintf(arch, "%s %s \n ",
            "Correo electronico: ", correo_electronico);
    fprintf(arch, "%s \n", "-----------------");

    fclose(arch);                                      //cerramos el archivo
}
char * datos(){
    cout << "Ingrese los datos del contacto que desea guardar_datos \n";
    cout << "Grupo: ";
    scanf("%s", grupo);
    cout << "Nombre: ";
    scanf("%s", nombre);                       //llenado de dato previamente creado, con formato solicitado
    cout << "Apellido: ";
    scanf("%s", apellido);
    cout << "Telefono: ";
    scanf("%u", &telefono);
    cout << "Correo electronico: ";
    scanf("%s", correo_electronico);
    cout << "<<-------------------------------->>"<< endl; // el end1 es para asegurar que el texto se muestre antes de continuar con la siguiente instrucción.
    return grupo, nombre, apellido, telefono, correo_electronico;
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
string lectura() {
    ifstream archivo;
    string texto;
    archivo.open(nombre_arch, ios::in);//abrimos un archivo en modo lectura
    if (archivo.fail()) {
        cout<<"ERROR, no se puedo encontrar el archivo con el nombre ingresado\n";
    }
    while (!archivo.eof()) {//mientras no sea el final del archivo
        getline(archivo, texto);
        cout<< texto.c_str()<<endl;
    }
    archivo.close();
    cout<<"Fin lectura"<<endl;
    return texto;
}
void buscar(string palabra){
    string texto = lectura();
    if(texto.find(palabra) != string::npos){
        cout<<texto.find(palabra);

    }
}
void cambio() {
        // Abrir archivo en modo de escritura
        ofstream archivo(nombre_arch, ios::app);

        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo" << endl;
        }

        // Escribir una nueva línea en el archivo
        archivo << "Nueva línea de texto" << endl;

        // Cerrar el archivo
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
void editar(char* nombre_arch, int linea, char* nuevo_texto) {
    char aux[100];
    FILE* arch = fopen(nombre_arch, "r+");
    if (arch == nullptr) {
        printf("No se pudo abrir el archivo\n");
    }
    // Buscar la línea que queremos editar
    for (int i = 1; i < linea; i++) {
        if (fgets(aux, sizeof(aux), arch) == nullptr) {
            printf("No se pudo leer la línea.\n");
        }
    }
    long int posicion = ftell(arch);
    sprintf(aux, "%s\n", nuevo_texto);
    fseek(arch, posicion, SEEK_SET);// Copiar la nueva línea de texto en la posición adecuada del archivo
    fputs(aux, arch);
    fclose(arch);
}