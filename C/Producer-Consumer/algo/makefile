program: main.o producer.o consumer.o
	gcc -o program Main.o Producer.o Consumer.o
	printf "0" > TURN.txt
	printf "" > DATA.txt
	
main.o: Main.c
	gcc -c Main.c

producer.o: Producer.c
	gcc -c Producer.c

consumer.o: Consumer.c
	gcc -c Consumer.c

clean:
	rm *.o
