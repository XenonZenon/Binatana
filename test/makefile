program := test
home := ../Bintana
test := $(home)/test
vklib := $(home)/libraries/vulkan/lib32
vkinclude := $(home)/libraries/vulkan/include
glfwlib := $(home)/libraries/glfw/lib
glfwinclude := $(home)/libraries/glfw/include

c_flags := -O3 -Wall -std=c++17 -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lglfw3dll -lvulkan-1 -lgdi32 -luser32 -lkernel32

objects := main.o

build: $(objects)
	g++ -s \
		 $(c_flags) \
		 main.o \
	-o $(program) \
	-L $(glfwlib) \
	-L $(vklib) \
	   $(link)

main.o:
	g++ -c \
	 -I $(vkinclude) \
	 -I $(glfwinclude) \
	    main.cpp \
	 -o main.o
