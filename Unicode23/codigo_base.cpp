/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//    Archivo: codigo_base.cpp                                                 //
//    Fecha de última revisión: 08/09/2023                                     //
//    Autores: Francisco Javier Pizarro 821259                                 //
//    Comms:                                                                   //
//          Este archivo contiene el esqueleto para facilitar la implementación//
//          de la solución del 1º problema del Unicode 23                      //
//          Modificar el contenido de la función solve_problem_instance        //
//    Use:  g++ codigo_base.cpp                                                //
//          Lanzar el ejecutable generado                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> solve_problem_instance(const vector<int>& clases, int Maximum) {
    cout << "\tEjecutando el algoritmo para resolver el problema" << endl;
    int nClases = clases.size();
    
    ///////////////////////////////////////
    // IMPLEMENTAR AQUÍ VUESTRA SOLUCIÓN :D
    ///////////////////////////////////////
    
    // Este bucle muestra cómo acceder a cada una de las cifras de alumnos de las distintas clases
    for (int i = 0; i < nClases; ++i) {
        cout << clases[i] << endl;
    }

    // Dato útil para los de 1º
    // para añadir algo al vector de la solución emplead una linea de código similar a  la siguiente:
    // solucion.push_back(12);
    vector<int> solucion;
    int mayor_N_asistentes = 0;

    return solucion;
}

pair<vector<int>, int> read_file(const string& nombre_fichero) {
    cout << "\tCargando datos del fichero de entrada" << endl;
    ifstream file(nombre_fichero);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << nombre_fichero << endl;
        exit(1);
    }

    vector<int> clases;
    int capacidad_maxima;
    int num_enteros_a_leer;
    // Lectura de la capacidad máxima
    file >> capacidad_maxima;
    file >> num_enteros_a_leer;
    // Lectura de los alumnos de las distintas clases
    int num;
    while (file >> num) {
        clases.push_back(num);
    }

    return make_pair(clases, capacidad_maxima);
}

void write_file(const string& nombre_fichero, int num_clases_solucion, const vector<int>& clases_solucion) {
    cout << "\tEscribiendo resultados en el fichero de salida" << endl;
    ofstream file(nombre_fichero);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << nombre_fichero << endl;
        exit(1);
    }

    // Escritura del número de clases que asisten a la excursión
    file << num_clases_solucion << endl;
    // Escritura del número de alumnos de cada clase que asisten separados por espacios
    for (int i = 0; i < num_clases_solucion; ++i) {
        file << clases_solucion[i];
        if (i < num_clases_solucion - 1) {
            file << " ";
        }
    }
}

int main() {
    // Ejecutamos todo para cada uno de los ficheros
    vector<string> NOMBRES_FICHEROS = {"facil", "normal", "dificil", "aun_mas_dificil"};

    for (const string& nombre_fichero : NOMBRES_FICHEROS) {
        cout << "Ejecutando para el dataset: " << nombre_fichero << endl;
        // Leemos los datos
        pair<vector<int>, int> data = read_file("./datasets/" + nombre_fichero + ".txt");
        const vector<int>& clases = data.first;
        int capacidad_maxima = data.second;

        // Calculamos las soluciones
        vector<int> clases_solucion = solve_problem_instance(clases, capacidad_maxima);
        int num_clases_solucion = clases_solucion.size();

        // Escribimos las soluciones
        write_file("./soluciones/" + nombre_fichero + ".txt", num_clases_solucion, clases_solucion);
    }

    return 0;
}