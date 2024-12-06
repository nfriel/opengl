main: src/main.cc
	clang++ src/main.cc -Idependencies -Ldependencies/glfw -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
	./a.out
	rm a.out
