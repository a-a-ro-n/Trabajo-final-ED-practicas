all: bin/cifras bin/letras #bin/cant_letras

bin/cifras: obj/cifras.o
	g++ -o bin/cifras obj/cifras.o -I include

bin/letras: obj/letras.o obj/dictionary.o obj/letters_set.o obj/letters_bag.o obj/solver.o
	g++ obj/letras.o obj/dictionary.o obj/letters_set.o obj/letters_bag.o obj/solver.o -o bin/letras

#bin/cant_letras:
#	g++ obj/cant_letras.o obj/dictionary.o obj/letter_set.o -o bin/cant_letras

##############################################################################################

obj/cifras.o:
	g++ -c src/cifras.cpp -o obj/cifras.o -I include

obj/solver.o:
	g++ -c src/solver.cpp -o obj/solver.o -I include

obj/letras.o:
	g++ -c src/letras.cpp -o obj/letras.o -I include

obj/letters_set.o:
	g++ -c src/letters_set.cpp -o obj/letters_set.o -I include

obj/letters_bag.o:
	g++ -c src/letters_bag.cpp -o obj/letters_bag.o -I include

obj/dictionary.o:
	g++ -c src/dictionary.cpp -o obj/dictionary.o -I include

#obj/cant_letras.o:
#	g++ -c src/cantidad_letras.cpp src/dic -o obj/cant_letras.o -I include

#############################################################################################

clear:
	rm -rf obj/*

clearall: clear
	rm -rf bin/*
