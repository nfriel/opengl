main: src/main.cc
	clang++ src/main.cc dependencies/glad/src/glad.c -Idependencies -Idependencies/glad/include -Ldependencies/glfw -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
	./a.out
	rm a.out
