CC = g++
CFLAGS = -I.

Calculator:	main.o	regex.o	deletehash.o	inserthash.o	searchHash.o	updateHash.o	eval.o	otherHash.o	htable.h
	$(CC)	-o	Calculator.exe	main.o	regex.o	deletehash.o	inserthash.o	searchHash.o	updateHash.o	eval.o	otherHash.o	htable.h

regex:	regex.cpp	regex.h
	$(CC)	-o	regex	regex.cpp

deletehash:	deletehash.cpp	htable.h
	$(CC)	-o	deletehash	deletehash.cpp

inserthash:	inserthash.cpp	htable.h
	$(CC)	-o	inserthash	inserthash.cpp

searchHash: searchHash.cpp	htable.h
	$(CC)	-o	searchHash	searchHash.cpp

updateHash: updateHash.cpp	htable.h
	$(CC)	-o	updateHash	updateHash.cpp

otherHash:	otherHash.cpp	htable.h
	$(CC)	-o	otherHash	otherHash.cpp

eval:	eval.cpp	eval.h
	$(CC)	-o	eval	eval.cpp

clean:
	rm	*.o	*.exe
