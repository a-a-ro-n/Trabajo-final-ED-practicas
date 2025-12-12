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


COMPILACIÓN
--------------------------------------------------------------------------------------------------------------
El proyecto incluye un archivo makefile para facilitar la compilación, automatizandola.
Esto crea los archivos objeto (.o) y posterior mente los ejecutables de cada programa.

