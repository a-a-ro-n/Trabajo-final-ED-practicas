                        	PROYECTO FINAL ED - PRÁCTICAS

--------------------------------------------------------------------------------------------------------------
			AUTORES: Aaron López Molino y Pablo Bertos Mateos
--------------------------------------------------------------------------------------------------------------
DESCRIPCIÓN:
--------------------------------------------------------------------------------------------------------------
Este proyecto implementa las estructuras de datos y algoritmos que hemos visto mas necesarios y eficientes 
para resolver partidas del juego de cifras y letras.

El programa trabaja con diccionarios de palabras, conjuntos de letras con puntuaciones específicas y bolsas
de letras para generar partidas aleatorias.
Ademas de un programa que modifica el conjunto de letras y otro que hace las comprobaciones necesarias para 
poder corregir/comprobar el resultado digitado por el usuario del juego de letras


ARCHIVOS PRINCIPALES:
--------------------------------------------------------------------------------------------------------------
1. Dictionary (dictionary.h / dictionary.cpp):
   - Usa una estructura eficiente (basada en set<string>) para almacenar las palabras válidas del diccionario 
     que se le pasa.
   - Permite búsqueda, inserción, borrado y comprobación de prefijos mediante la llamada a funciones.
     	Más Rápido (Mejor Caso)			O(1)			size, empty...
	Más Lento (Peor Caso)			O(n⋅Longitud)		getOccurrences, getTotalLetters...
	Demás (Caso Promedio)			O(Longitud⋅log(n))	exists, find..

2. LetterSet (letters_set.h / letters_set.cpp):
   - Gestiona la información de las letras del juego, leyendo de archivo la cantidad de repeticiones permitidas 
     y la puntuación de cada letra.
   - Utiliza un mapa (map<char, LetterInfo>) para acceso rápido.
	Más Rápido (Mejor Caso)			O(1)	Todos los métodos.
	
3. LettersBag (letters_bag.h / letters_bag.cpp):
   - Representa una bolsa de letras mezcladas, permitendo extraer letras de forma aleatoria para formar el 
     conjunto de letras con el que jugara el usuario.
	Más Rápido (Mejor Caso)	O(1)	getLetter(), size(), empty(), clear(), begin(), end()
	Más Lento (Peor Caso)	O(N)	erase(const char), toString()

4. Solver (solver.h / solver.cpp):
   - Motor de resolución del juego, encontrando todas las palabras válidas que se pueden formar dado un 
     conjunto de letras (lettersBag).
   - Soporta dos modos de juego:
     - Por longitud: Gana la palabra más larga.
     - Por puntuación: Gana la palabra que suma más puntos según el LetterSet.
     	Más Rápido (Mejor Caso)	O(1)	 		Solver()
	Más Lento (Peor Caso)	O(n⋅Longitud⋅vector)	getSolutions()
	Demás (Caso Promedio)	O(Longitud⋅vector)	poderConstruir()

5.Cantidad letras:
   -Recibe un diccionario, un fichero de letras y un fichero de salida por el que muestra, por cada letra
del fichero letras, sus ocurrencias y su puntuación.
   -Utilizamos un struct letra para guardar la información que necesitaremos de cada letra (caracter, apariciones, porcentaje).
   -Por cada letra, calculamos los campos anteriores y los guardamos en un vector (como sabemos de antemano el
tamaño, no hay que hacer inserciones, lo que haría menos eficiente esta implementación). Calculamos el porcentaje
mínimo y hacemos -log10(min) para no utilizar tantos decimales. Finalmente, guardamos en el fichero de salida la
información que se nos pedía.

6. Cifras
   -Utiliza los siguientes elementos:
	-struct solucion. Guarda los campos relativos a la solución (valor,op,cantidad). Hemos optado por guardar
las operaciones en un único string ya que tan solo las imprimiremos y no hay borrados (no hace falta un TDA que las
almacene por separado). La única desventaja sería contabilizar el número de operaciones, pero para ello utilizamos
cantidad, que se actualizará al añadir operaciones. 
	-función GeneraOperaciones: añade todas las posibles operaciones con un número n a una solucion dada (evitamos
que al restar haya números negativos).
	-función Cifras:devuelve la mejor solución dados un conjunto de números, un objetivo, una solución actual y la
mejor. Cuando encuentra una solución mejor a la actual, actualiza best y lo devuelve. Recorre el conjunto S y, por cada
número, llama a GeneraOperaciones para saber las operaciones que se pueden hacer. Por cada una de las operaciones, se
llama a sí misma recursivamente. De este modo, acabará devolviendo la mejor solución. Esta implementación no termina al
encontrar el exacto, lo que supondría menor carga computacional, porque buscamos el exacto con el menor número de operaciones
(o, si no se puede alcanzar, el más cercano con el menor número de operaciones).
	-main: utilizamos un vector para guardar los posibles números que pueden "tocar" para alcanzar el objetivo y un
multiset para los que "tocan". Elegimos este segundo porque sí necesitaremos hacer inserciones y borrados, por lo que será
más eficiente que un vector. Le pedimos al usuario que nos diga cómo llegaría al resultado. Cuando introduzca algún valor
erróneo, se dejará de preguntar y se tomará la respuesta hasta donde era correcta. La comprobación se hace después de ambas
lecturas, por lo que si se falla en el signo, esperará un valor más (aunque no vaya a contar). Finalmente, muestra la respuesta
del usuario y la que calcula Cifras.


COMPILACIÓN
--------------------------------------------------------------------------------------------------------------
El proyecto incluye un archivo makefile para facilitar la compilación, automatizandola.
Esto crea los archivos objeto (.o) y posterior mente los ejecutables de cada programa.

