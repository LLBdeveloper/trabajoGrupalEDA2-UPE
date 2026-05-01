///////////////////
//TP EDA2 GRUPAL//
/////////////////             

/*



INSTITUCION: 
    Universidad Provincial de Ezeiza (UPE).


MATERIA: 
    Estructura de Datos y algoritmos II.


DOCENTE: 
    Osvaldo Pini


INTEGRANTES: 
    Lautaro bertera
    Ornella Gomez 
    Pol y
    Juan y


CICLO: 
    2026.


PROYECTO: 
    Sistema Inteligente de Gestion Logistica y Optimizacion de Rutas.


TECNICA: 
    Implementacion de Algoritmos de Optimizacion de Caminos Minimos en Redes Logisticas Provinciales.


PROVINCIA A TRABAJAR: 
    Cordoba.


CIUDADES INCLUIDAS:
    ID#0 Cordoba Capital (Nodo Central / Origen)

    ID#1 Rio Cuarto (Sur)

    ID#2 San Francisco (Este)

    ID#3 Villa Doleres (Oeste / Traslasierra)

    ID#4 Huinca Renanco (Extremo Sur)


DISTANCIAS APROXIMADAS: 
    Cordoba Cap. <---> Rio Cuarto: ~215 km (RN36)
    Cordoba Cap. <---> Villa Dolores: ~210 km (Cam altas cumbres)
    Cordoba Cap. <---> Huinca Renanco: ~410 km (opcional)
    San Francisco    <---> Rio Cuarto: ~260 km (RN158)
    Rio Cuarto   <---> Huinca Renanco: ~200 km (RN35)


MATRIZ DE ADYACENCIA:
    https://ibb.co/TqTM6dbm (Es el cuadro para entender de manera visual las rutas disponibles existentes)
    Teniendo en cuenta que:
        Muestra los km entre de distancia entre ciudades con rutas existentes
        INF es ruta inexistente 
        0 es no hay distancia 

        ( Archivo EXCEL para modificar la matriz:
        https://docs.google.com/spreadsheets/d/1KiXl4b21iklXM6bNE7EyRsbYQkO33nuaGxyI3LuT79M/edit?usp=sharing )

*/



/////////
//Headers
#include <iostream>
#include <stdlib.h>

using namespace std;


/////////
//Consts
#define INF 99999 //No existe ruta o ruta cortada


/////////
//Class

//Clase de la Matriz de adyacencia
class GrafoLogistico {
    //Atributos
    private:
        int matriz[5][5]; //Usamos 5 por el ejemplo del anexo

    //Metodos    
    public:
        
        GrafoLogistico() { //Constructor (pone todas las distancias en INF y las diagonales en 0)
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(i == j) matriz[i][j] = 0;
                    else matriz[i][j] = INF;
                }
            }
        }

    //Conectar dos ciudades con una distancia
    void agregarRuta(int origen, int destino, int distancia) {
        matriz[origen][destino] = distancia;
        matriz[destino][origen] = distancia; //Si es ida y vuelta
    }

    //Cortar una ruta 
    void cortarRuta(int origen, int destino) {
        matriz[origen][destino] = INF;
        matriz[destino][origen] = INF;
    }

    //Mostrar rutas
    void mostrarMatriz() {
        cout << "\n===========================================================" << endl;
        cout << "  RUTAS (MATRIZ DE ADYACENCIA) - RED LOGISTICA CORDOBA (km)" << endl;
        cout << "===========================================================" << endl;
        cout << "\t[0]\t[1]\t[2]\t[3]\t[4]" << endl;
        cout << "\tCba\tR-IV\tS-Fco\tV-Dol\tHuinca" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for(int i = 0; i < 5; i++) {
            cout << "[" << i << "]\t"; // Muestra el ID de la fila
            for(int j = 0; j < 5; j++) {
                if(matriz[i][j] == INF) {
                    cout << "INF\t";
                } else {
                    cout << matriz[i][j] << "\t";
                }
            }
            cout << endl;
        }
        cout << "===========================================================" << endl;
    }

};


//Clase ciudad
class Ciudad {
    
    //Atributos
    private:
        int id;
        string nombre;
        int x, y;//Coordenadas
    
    //Metodos
    public: 
        Ciudad(int, string, int, int); //Constructor
        ~Ciudad();//Destructor
        void mostrarCiudad();

        //Getter y Setter
        string getNombre();
        int getId ();
};

        //Constructor
    Ciudad::Ciudad(int _id, string _nombre, int _x, int _y){
        id = _id;
        nombre = _nombre;
        x = _x;
        y = _y;
    }

        //Destructor
    Ciudad::~Ciudad(){
    }

    void Ciudad::mostrarCiudad(){
        cout << "La ciudad que estoy creando es: " << nombre << endl;
    }

        //Getters y Setters
    string Ciudad::getNombre(){
        return nombre;
    }

    int Ciudad::getId(){
        return id;
    }


/////////
//Function prototypes


/////////
//Main
int main(){
        cout << "===========================================================" << endl;
        cout << "===========================================================" << endl;
        cout << "             INICIANDO SISTEMA . . ." <<endl;
        cout << "===========================================================" << endl;
        cout << "===========================================================" << endl;

    //Cargamos las ciudades
    Ciudad c0(0, "Cordoba Capital", 100, 150);
    Ciudad c1(1, "Rio Cuarto", 120, 400);
    Ciudad c2(2, "San Francisco", 350, 180);
    Ciudad c3(3, "Villa Dolores", 30, 220);
    Ciudad c4(4, "Huinca Renanco", 110, 550);
    
    cout << "===========================================================" << endl;
    cout << "       SISTEMA LOGISTICO CORDOBA - DATOS INICIALES" << endl;
    cout << "===========================================================" << endl;
    c0.mostrarCiudad();
    c1.mostrarCiudad();
    c2.mostrarCiudad();
    c3.mostrarCiudad();
    c4.mostrarCiudad();


    //Cargamos la matriz con las respectivas rutas disponibles
    GrafoLogistico mapaCordoba;
    mapaCordoba.agregarRuta(0, 1, 215);
    mapaCordoba.agregarRuta(0, 3, 210);
    mapaCordoba.agregarRuta(0, 4, 410);
    mapaCordoba.agregarRuta(2, 1, 260);
    mapaCordoba.agregarRuta(1, 4, 200);
    
    cout << "Datos de la red logistica de Cordoba cargados correctamente." << endl;
    mapaCordoba.mostrarMatriz();
    



    return 0;
}


/////////
//Functions






////////////////////////////////////
// NOTAS
// Ejemplo de Gestión de Contingencia: Se corta la ruta directa a Huinca Renanco
// mapaCordoba.cortarRuta(0, 4);
//Entonces tenemos que tomar la ruta que va desde cordoba cap hasta rio cuarto y luego la ruta de rio cuarto hasta huinca renanco, aunque son 5 km mas de distancia.





//
// mas adelante agregar mas rutas... arrancamos simple para entenderlo bieen :D
// nuevas rutas para "Contingencias" (Plan B y C)
//    mapaCordoba.agregarRuta(0, 2, 210); // Cba - San Francisco
//    mapaCordoba.agregarRuta(3, 1, 280); // V. Dolores - Rio IV
//