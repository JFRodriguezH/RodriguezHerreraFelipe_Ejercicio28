friccion.png : tiro.dat friccion.dat tiro.py
	python tiro.py
	
tiro.dat : tiro.out
	./tiro.out
    
friccion.dat : tiro.out
	./tiro.out
	
tiro.out : tiro.cpp
	c++ tiro.cpp -o tiro.out
	
clear :
	rm tiro.dat tiro.out tiro.png