################################################################################
#                                                                              #
#     Archivo: codigo_base.py                                                  #
#     Fecha de última revisión: 08/09/2023                                     #
#     Autores: Francisco Javier Pizarro 821259                                 #
#     Comms:                                                                   #
#           Este archivo contiene el esqueleto para facilitar la implementación#
#           de la solución del problema del Unicode 23                         #
#           Modificar el contenido de la función solve_problem_instance        #
#     Use:  python3 codigo_base.py                                             #
#                                                                              #
################################################################################

def solve_problem_instance(clases, Maximum):
    print("\tEjecutando el algoritmo para resolver el problema")
    nClases = len(clases)
    
    #######################################
    # IMPLEMENTAR AQUÍ VUESTRA SOLUCIÓN :D
    #######################################
    # Este bucle muestra como acceder a cada una de las cifras de alumnos de las distintas clases
    for clase in clases:  
        print(clase)

    solucion = []
    mayor_N_asistentes = 0

    return mayor_N_asistentes, solucion, len(solucion)

def read_file(nombre_fichero):
    print("\tCargando datos del fichero de entrada")
    with open(nombre_fichero, 'r') as file:
        # Lectura de los enteros de la primera linea
        first_line = file.readline().strip()
        first_ints = first_line.split()
        capacidad_maxima = int(first_ints[0])
        num_ints_to_read = int(first_ints[1])

        # Lectura de los enteros de la segunda línea separados por espacios
        second_line = file.readline().strip()
        second_ints = second_line.split()

        # Almacenamos los enteros en una lista
        clases = [int(num) for num in second_ints]

    return clases, capacidad_maxima

def write_file(nombre_fichero,num_clases_solucion, clases_solucion):
    print("\tEscribiendo resultados en el fichero de salida")
    with open(nombre_fichero, 'w') as file:
        # Escritura del número de clases que asisten a la excursión
        file.write(str(num_clases_solucion)+'\n')
        # Escritura del número de alumnos de cada clase que asisten separados por espacios
        file.write(" ".join(map(str,clases_solucion)))
    return

NOMBRES_FICHEROS = ["facil","normal","dificil","aun_mas_dificil"]

def main():
    # Ejecutamos todo para cada uno de los ficheros
    for nombre_fichero in NOMBRES_FICHEROS:
        print("Ejecutando para el dataset:",nombre_fichero)
        # Leemos los datos
        clases, capacidad_maxima = read_file("./datasets/"+nombre_fichero+ ".txt")
        # Calculamos las soluciones
        mayor_N_asistentes, clases_solucion, num_clases_solucion = solve_problem_instance(clases, capacidad_maxima)
        # Escribimos las soluciones
        write_file("./soluciones/"+nombre_fichero+ ".txt",num_clases_solucion,clases_solucion)

if __name__ == "__main__":
    main()