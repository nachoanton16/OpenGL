all: prueba

prueba: prueba.cpp glad.c
	g++ -I glad/ -o prueba prueba.cpp glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -ldl


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<


