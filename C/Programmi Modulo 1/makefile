objs= esercizio1_lezione41_castronovo.o mysortinglibrary.o

a: $(objs)
	@echo "Generazione eseguibile..."
	@gcc -o a $(objs)
$(objs):
	@echo "Creazione file oggetto..."
	@gcc -c -D=virgola $*.c
pulizia:
	@rm a $(objs)