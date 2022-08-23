objs= polyListADT_FC.o clientPolyADT_FC.o

a: $(objs)
	@echo "Generazione eseguibile..."
	@gcc -o a $(objs)
$(objs):
	@echo "Creazione file oggetto..."
	@gcc -c -D=intero $*.c
pulizia:
	@rm a $(objs)