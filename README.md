Nombre del Proyecto: "Análisis de Datos de Violencia y Bienestar en América Latina"

El programa tiene varias funciones, no tiene base en otra
página ya que son datos reales y por lo tanto tampoco se
pueden agregar datos por el usuario.
Las funciones que va a
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

Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

g++ -o programa main.cpp bst.cpp buscarDatos.cpp buscarDatosAnio.cpp

./programa

Descripción de las Entradas del Proyecto
El programa requiere un archivo de entrada en formato CSV que contiene los datos de cada país, año y los indicadores relevantes. Este archivo debe estar estructurado en columnas específicas, cada una separada por comas. Los campos esperados son:

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

Ejemplo del Archivo CSV de Entrada:
csv
,iso3,year,le_f,country_sp,fem_pop,mmr,gpi,femicides_number
0,ARG,2008,78.9268,Argentina,20387718.0,53.0,1.82,0
1,ATG,2008,79.088,Antigua y Barbuda,43883.0,50.0,0,0
2,BHS,2008,75.9615,Bahamas,186970.0,77.0,0,0

Cada línea representa un registro único para un país en un año específico, y todos los campos deben completarse en el formato especificado para asegurar el correcto funcionamiento del programa.

Descripción de las Salidas del Proyecto
Los resultados de la ejecución del programa incluyen:

Visualización de Datos para un País Específico:

Al consultar todos los datos de un país específico, el programa muestra en pantalla cada registro de ese país, incluyendo todos los indicadores por año.
Visualización de Datos para un País y Año Específicos:

Para una consulta de un país y año determinados, el programa muestra todos los indicadores de ese registro, permitiendo una revisión detallada de los datos de ese año.
Cálculo de Medias para Indicadores de un País:

Cuando se solicita la media de un indicador específico para un país (como le_f, mmr, gpi o femicides_number), el programa calcula y muestra el promedio de ese indicador para el país seleccionado en todos los años disponibles.
Archivo CSV de Salida:

Ejemplo de Salida en Consola para una Consulta de Año y País:

Abreviatura: MEX, Nombre: México, Año: 2019, Esperanza de vida femenina: 77.5736, Población femenina: 63898082.0, Mortalidad materna: 33.0, Índice de paz global: 2.46, Feminicidios: 945.0

La media de la esperanza de vida femenina de Chile es: 81.9766

La media del índice de paz global de Panamá es: 1.83279

Resumen de Salidas
Salidas en consola para consultas específicas.

SICT0301: Evalúa los Componentes

Análisis de Complejidad para Algoritmos de Ordenamiento

Para este proyecto, decidí utilizar el algoritmo de ordenamiento Merge Sort debido a su rendimiento consistente y su naturaleza estable. Dado que manejo registros que podrían contener valores iguales en campos como el año, la estabilidad de Merge Sort es clave: garantiza que el orden relativo de estos elementos se mantenga, lo que facilita el análisis de datos y asegura coherencia en los resultados. Merge Sort tiene una complejidad temporal de O(n log n) en el mejor, promedio y peor de los casos, lo cual es importante para manejar conjuntos de datos grandes sin experimentar ralentizaciones.

Análisis detallado de la complejidad de Merge Sort es el siguiente:

Mejor Caso (O(n log n)): Esto sucede porque, independientemente del orden inicial de los datos, el algoritmo siempre sigue dividiendo y fusionando los elementos en log(n) niveles.

Caso Promedio (O(n log n)): La mayoría de las distribuciones de datos requieren una cantidad de trabajo similar para dividir y fusionar elementos.

Peor Caso (O(n log n)): Aun en el caso de una lista ordenada en orden inverso o sin ningún patrón de orden, Merge Sort mantiene un rendimiento estable.

Opté por Merge Sort porque su rendimiento uniforme me ayuda a evitar problemas de rendimiento a medida que el tamaño de los datos aumenta, lo cual es crucial en este programa donde el BST se construye después de ordenar los datos.

Análisis de Complejidad para las Estructuras de Datos

La estructura de datos principal en este programa es un árbol binario de búsqueda (BST). Elegí el BST porque sus características de búsqueda y recorrido son adecuadas para las operaciones que necesito: buscar registros, mostrar datos y calcular promedios rápidamente. El BST ofrece una estructura jerárquica, lo que me permite organizar los datos de manera que cada operación sea eficiente.

La complejidad del BST en mi programa se analiza como sigue:

Mejor Caso (O(log n)): Se da en un árbol balanceado, en el cual el número de niveles es log(n), y tanto la búsqueda como la inserción son eficientes.

Caso Promedio (O(log n)): Un BST generalmente tiende a mantenerse balanceado en datos aleatorios, logrando un rendimiento eficiente en promedio.

Peor Caso (O(n)): Ocurre si el BST se desbalancea completamente, asemejándose a una lista, lo que degrada el rendimiento. Aunque no implementé un mecanismo de balanceo, al ordenar los datos con Merge Sort antes de insertarlos, reduzco la posibilidad de que el árbol se desbalancee severamente.

La elección de un BST me permite organizar y buscar datos en tiempo logarítmico en el mejor y promedio de los casos, lo cual es una gran ventaja cuando se manejan grandes cantidades de registros. Implementé el BST en bst.h, definiendo funciones como insertar y buscar para cumplir con las necesidades del programa.

Análisis de Complejidad General del Programa

La complejidad total del programa combina la eficiencia de Merge Sort y la estructura de BST, resultando en una complejidad general de O(n log n) para la carga y organización de datos. 

Elegí esta combinación porque asegura un rendimiento consistente y manejable incluso con volúmenes de datos grandes.

En detalle:

Mejor Caso (O(n log n) + O(log n)): Esto ocurre cuando los datos están listos para ser organizados de forma ordenada y el BST está bien balanceado.

Caso Promedio (O(n log n) + O(log n)): La mayoría de los datos pueden manejarse en log(n) niveles en el BST, garantizando una eficiencia similar.

Peor Caso (O(n log n) + O(n)): Si el BST se vuelve muy desbalanceado, la complejidad puede degradarse. Este escenario sigue siendo manejable en el programa, dado que se ordenan previamente los datos.

Se observa este análisis en la función cargarDatos en buscarDatos.cpp, la cual organiza y carga los registros en el BST, y en bst.h que define la estructura y funcionalidades principales del BST.

SICT0302: Toma de Decisiones

Selección de Algoritmo de Ordenamiento

Decidí implementar Merge Sort por su estabilidad y complejidad temporal de O(n log n). Este algoritmo fue la mejor elección para ordenar los registros antes de insertarlos en el BST, ya que me asegura que incluso en los peores escenarios de datos desordenados, la eficiencia se mantendrá estable. Además, al mantener el orden relativo de los elementos iguales, me permite tener una estructura de datos coherente y fiable, que refleja de manera consistente los registros del archivo. La implementación de Merge Sort se encuentra en buscarDatos.cpp, donde la función mergeSort organiza los registros.

Selección de Estructura de Datos

Elegí un BST porque sus operaciones de búsqueda y recorrido son rápidas y adecuadas para las consultas específicas del programa. Esta estructura me permite organizar los datos de manera jerárquica, facilitando la consulta y el acceso eficiente a la información de cada país y año. El BST me da flexibilidad en términos de cálculo de estadísticas y acceso a datos, logrando una mayor eficiencia en el manejo de datos. Esta decisión se encuentra reflejada en el archivo bst.h, donde se implementan funciones clave como insertar y buscar.

SICT0303: Implemento Acciones Científicas

Implementa Mecanismos para Consultar Información de las Estructuras Correctos

Para realizar consultas específicas, he implementado varios métodos en el BST. Por ejemplo, mostrarDatosDeUnAnio permite acceder a datos de un año particular y país determinado. Esta decisión garantiza que el programa pueda proporcionar información detallada según la necesidad del usuario, optimizando el BST para la consulta rápida de datos. El diseño jerárquico del BST facilita la consulta eficiente y específica, aprovechando las búsquedas rápidas de este árbol.

Implementa Mecanismos de Lectura de Archivos para Cargar Datos

Desarrollé una función para leer archivos CSV y cargar la información directamente en el BST. En buscarDatos.cpp, la función cargarDatos extrae, procesa y almacena cada registro en un vector de datos, que luego se ordena e inserta en el BST. Este flujo asegura que los datos se organicen de manera adecuada y se mantengan accesibles para las operaciones de consulta en el árbol. La estructura jerárquica resultante del BST permite un acceso rápido a los datos.

Implementa Mecanismos de Escritura de Archivos para Guardar Datos

Para conservar los resultados del programa, implementé un método guardarDatos que permite guardar los datos en un archivo CSV, brindando persistencia y acceso futuro a la información estructurada en el BST. Esto garantiza que los datos consultados y calculados por el programa se almacenen de manera fiable, facilitando el análisis y la reutilización de información.


Y ya se que esta parte no la pides pero por si se me fue algo mejor completo aquí jaja:

Análisis de Complejidad Correcto y Completo de Estructuras de Datos y Usos en el Programa

Estructura de Datos Principal: Árbol Binario de Búsqueda (BST)

Elegí el árbol binario de búsqueda (BST) como estructura de datos principal debido a sus propiedades jerárquicas, que son adecuadas para las búsquedas y recorridos eficientes necesarios en este programa.

El BST permite realizar operaciones como inserción, búsqueda y recorrido de manera eficiente, con una complejidad temporal de O(log n) en el mejor caso (cuando el árbol está balanceado) y de O(n) en el peor caso (cuando el árbol se desbalancea y se asemeja a una lista). Esto es especialmente relevante cuando se manejan datos grandes y se realizan consultas específicas, ya que el BST brinda un acceso estructurado a los datos de cada país y año.

Para mitigar posibles desbalanceos en el BST, primero ordené los datos con Merge Sort, lo cual ayuda a crear un árbol más equilibrado durante la inserción inicial. Este diseño maximiza la eficiencia en las consultas y asegura que el BST funcione de manera óptima en la mayoría de los casos.

Análisis Completo de la Complejidad del BST

Mejor Caso (O(log n)): En un árbol balanceado, el número de niveles del árbol es log(n), lo que permite realizar inserciones y búsquedas de forma eficiente. Este es el caso más deseado y garantiza la máxima eficiencia del BST.

Caso Promedio (O(log n)): Con datos aleatorios, el BST tiende a mantenerse equilibrado, asegurando que la mayoría de las operaciones de búsqueda e inserción sean rápidas y eficientes.

Peor Caso (O(n)): En casos donde el árbol se vuelve muy desbalanceado, la eficiencia se degrada. Sin embargo, el uso de Merge Sort antes de la inserción inicial reduce esta posibilidad en este proyecto.

Análisis de Complejidad Correcto y Completo de Otros Componentes y Complejidad Final del Programa

Algoritmo de Ordenamiento (Merge Sort)

Decidí utilizar Merge Sort para ordenar los registros antes de insertarlos en el BST. Merge Sort tiene una complejidad temporal de O(n log n) en el mejor, promedio y peor caso, lo cual asegura un rendimiento estable y predecible.

Este algoritmo fue elegido por su estabilidad y eficiencia, lo que ayuda a crear una estructura más equilibrada en el BST después de la inserción, mejorando el rendimiento general del programa.

La complejidad de Merge Sort se analiza en los tres casos:

Mejor, Promedio y Peor Caso (O(n log n)): Merge Sort siempre sigue la misma serie de divisiones y fusiones, asegurando un rendimiento constante.

Complejidad General del Programa

La complejidad global del programa combina la eficiencia de Merge Sort (O(n log n)) y la complejidad del BST (O(log n) en el mejor caso), lo que resulta en una complejidad final de O(n log n) para la carga y organización de los datos.

La estructura del programa asegura que las consultas y las operaciones se realicen de manera eficiente, permitiendo que el sistema maneje grandes volúmenes de datos de manera efectiva.

Selección de Algoritmo de Ordenamiento y su Uso

Algoritmo de Ordenamiento Seleccionado: Merge Sort

Merge Sort fue seleccionado para ordenar los datos antes de insertarlos en el BST. Esto asegura que la inserción en el BST sea más equilibrada, mejorando el rendimiento en términos de complejidad y eficiencia de búsqueda.

Su estabilidad es crucial para mantener el orden relativo de los registros con valores idénticos en ciertos campos, como el año, y la elección fue correcta ya que logra un rendimiento consistente sin importar la distribución inicial de los datos.

Selección de Estructura de Datos y su Uso

BST como Estructura de Datos Principal

La elección del BST permite realizar operaciones de búsqueda, consulta y cálculo de manera rápida y jerárquica, acorde a las necesidades de análisis de datos específicos por año y país.

La estructura jerárquica del BST permite una organización natural de los datos y un acceso eficiente a la información necesaria. Esta estructura cumple con las demandas del programa y asegura que las consultas específicas se realicen de manera óptima.

Implementación de Mecanismos para Consultar Información de las Estructuras

Consultas Específicas con el BST

Implementé mecanismos en el BST para realizar consultas de datos específicos, como mostrarDatosDeUnAnio, lo cual permite acceder rápidamente a información detallada sobre un año y país determinados. La estructura del BST hace que estas consultas sean eficientes y rápidas.

Este mecanismo de consulta refleja una estructura optimizada que asegura un acceso estructurado y jerárquico, adecuado para los análisis que requiere el programa.

Implementación de Mecanismos de Lectura de Archivos para Cargar Datos

Función de Lectura de Archivos

Implementé una función en el programa para leer archivos CSV y cargar los registros en el vector de datos y, posteriormente, en el BST. Este proceso de lectura permite que los datos sean cargados y organizados adecuadamente en la estructura de datos, asegurando que cada registro se procese y almacene de manera correcta.

La función se diseñó para manejar posibles errores de lectura, garantizando que los datos se carguen de forma segura y fiable, listos para las operaciones de consulta y análisis del BST.

Implementación de Mecanismos de Escritura de Archivos para Guardar Datos

Función de Escritura de Archivos

Implementé un método guardarDatos para exportar los resultados a un archivo CSV, lo que permite conservar los datos consultados y analizados por el programa para futuras referencias.

Este mecanismo asegura la persistencia de la información y facilita el acceso futuro, permitiendo que los resultados del análisis sean reutilizables y compartibles, garantizando así un flujo completo de datos desde la entrada hasta la salida del programa.
