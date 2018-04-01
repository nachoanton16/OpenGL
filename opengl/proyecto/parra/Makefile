all: 2prueba

2prueba: 2prueba.cpp glad.c
	g++ -I glad/ -o 2prueba 2prueba.cpp glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -ldl


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<


