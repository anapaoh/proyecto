Nombre del Proyecto: "Análisis de Datos de Violencia y Bienestar en América Latina"

Este conjunto de datos contiene:
1- La abreviación de cada país - iso3
2- El año registrado - year
3- La esperanza de vida femenina (años) - le_f
4- El nombre del país - country_sp
5- La población femenina en ALC - fem pop
6- Tasa de mortalidad materna (muertes por 100.000 nacidos
vivos) - mmr
7- Índice de paz global (Índice compuesto que mide el grado de
paz de los países, formado por 23 indicadores cuantitativos y
cualitativos, cada uno ponderado en una escala de 1 a 5.
Cuanto menor sea la puntuación, más pacíficos son los países.
Cuanto menor es la puntuación, más pacífico es el país) - gpi
8- Número de feminicidios (valor absoluto) - femicides_number
El programa tiene varias funciones, no tiene base en otra
página ya que son datos reales y por lo tanto tampoco se
pueden agregar datos por el usuario. Las funciones que va a
poder implementar son las siguientes:

Buscar los datos completos de todos los años de un país.
Buscar los datos completos de un país de un año en específico.
Calcular la media de le_f, o mmr, o gpi, o feminicidios de un país en específico tomando todos los años.

Descripción Detallada del Funcionamiento:
El proyecto implementa una estructura de árbol binario de búsqueda (BST) para almacenar los registros de datos. Esta estructura se elige por su eficiencia en las operaciones de inserción, búsqueda y recorrido de los datos. Los registros son objetos que contienen información sobre un país y año específico, así como los indicadores mencionados.

El programa incluye las siguientes funcionalidades:

Cargar Datos (cargarDatos):

Los datos se cargan desde un archivo CSV que contiene información sobre cada país y su correspondiente año, junto con los indicadores relevantes.
Los datos son procesados y almacenados en registros individuales, los cuales se insertan en el BST.
Para garantizar que los datos se encuentren en un orden adecuado para su procesamiento, se aplica un algoritmo de ordenamiento Merge Sort antes de la inserción en el árbol.
Mostrar Todos los Datos de un País (mostrarTodosLosDatos):

Esta función permite recuperar y mostrar todos los datos disponibles para un país específico en el árbol. El recorrido se realiza de manera recursiva.
Mostrar Datos de un País y Año Específico (mostrarDatosDeUnAnio):

Dado un país y un año, esta función muestra los datos asociados a esa combinación de país y año. Se realiza una búsqueda eficiente en el árbol para encontrar el nodo correspondiente.
Calcular la Media de un Indicador para un País (calcularMediaX):

Las funciones calcularMediaLeF, calcularMediaMmr, calcularMediaGpi, y calcularMediaFemicidios permiten calcular la media de indicadores específicos para un país en particular.
El cálculo se realiza mediante un recorrido recursivo del árbol, sumando los valores de los indicadores y contando las instancias correspondientes para luego calcular el promedio.
Búsqueda de Datos de un Año y País (buscarDatosAnio):

Similar a la función para mostrar datos de un año específico, esta función busca de manera eficiente los datos de un país en un año determinado, leyendo directamente desde el archivo CSV.

Métodos Implementados:

Métodos de Inserción:

insertar: Inserta un nuevo registro en el árbol. La inserción sigue un orden específico basado en el año y nombre del país (alfabéticamente en caso de empate).
insertarRecursivo: Realiza la inserción recursiva de un nodo en el árbol, comparando el año y el nombre del país.
Métodos de Consulta:

mostrarTodosLosDatos: Muestra todos los registros de un país recorriendo el árbol de forma recursiva.
mostrarRecursivo: Método auxiliar recursivo que ayuda a mostrar los datos de un país en todo el árbol.
mostrarDatosDeUnAnio: Muestra los datos de un país en un año específico, utilizando una búsqueda recursiva en el árbol.
buscar: Realiza una búsqueda en el árbol para encontrar un registro basado en el país y el año.
buscarRecursivo: Método auxiliar recursivo que implementa la búsqueda en el árbol.
Métodos de Cálculo:

calcularMediaLeF: Calcula la media de la esperanza de vida femenina para un país.
calcularMediaMmr: Calcula la media de la tasa de mortalidad materna para un país.
calcularMediaGpi: Calcula la media del índice de paz global para un país.
calcularMediaFemicidios: Calcula la media del número de feminicidios para un país.
calcularMediaRecursivo: Método recursivo que permite calcular la media de un indicador específico en el árbol.
Métodos de Ordenación y Carga:

merge: Función que implementa el algoritmo de Merge Sort para ordenar los registros en función del año.
mergeSort: Aplica el algoritmo de Merge Sort sobre un vector de registros.
cargarDatos: Carga los datos desde un archivo CSV, ordena los registros y los inserta en el árbol binario de búsqueda.
Importancia del Proyecto:
Este proyecto es crucial para realizar un análisis de datos sobre indicadores clave relacionados con la salud y la violencia, especialmente en una región como América Latina, donde estos temas son de alta relevancia. Con herramientas de análisis como la capacidad de calcular promedios y consultar datos por país y año, el sistema facilita la toma de decisiones informadas en políticas públicas, investigación social y análisis de tendencias.
