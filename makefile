tiro.png : tiro.dat tiro.py
	python tiro.py
	
tiro.dat : tiro.out
	./tiro.out
	
tiro.out : tiro.cpp
	c++ tiro.cpp -o tiro.out
	
clear :
	rm tiro.dat tiro.out tiro.png