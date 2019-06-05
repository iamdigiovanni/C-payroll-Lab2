
lab2Make: PageBreak.o calcGross.o calcFICA.o newPage.o
	gcc -o lab2Make PageBreak.o calcGross.o calcFICA.o newPage.o

PageBreak.o: /home/amberdigiovanni/lab2Files/lab2Src/PageBreak.c
	gcc -c -o PageBreak.o /home/amberdigiovanni/lab2Files/lab2Src/PageBreak.c

calcGross.o: /home/amberdigiovanni/lab2Files/lab2Src/calcGross.c
	gcc -c -o calcGross.o /home/amberdigiovanni/lab2Files/lab2Src/calcGross.c

calcFICA.o:  /home/amberdigiovanni/lab2Files/lab2Src/calcFICA.c
	gcc -c -o calcFICA.o /home/amberdigiovanni/lab2Files/lab2Src/calcFICA.c

newPage.o: /home/amberdigiovanni/lab2Files/lab2Src/newPage.c
	gcc -c -o newPage.o /home/amberdigiovanni/lab2Files/lab2Src/newPage.c


