program := Bintana
projdir := ../Bintana
include := $(projdir)/include
source := $(projdir)/source
build_objects := $(projdir)/build/objects
build_debug := $(projdir)/build/debug

vklib := $(projdir)/libraries/VulkanSDK/1.3.231.1/Lib32
vkinclude := $(projdir)/libraries/VulkanSDK/1.3.231.1/Include
glfwlib := $(projdir)/libraries/glfw/lib
glfwinclude := $(projdir)/libraries/glfw/include

c_flags := -O3 -Wall -std=c++17 -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lglfw3dll -lvulkan-1 -lgdi32 -luser32 -lkernel32

objects := main.o makina.o game.o variables.o

build: $(objects)
	g++ -s \
	       $(c_flags) \
	       $(build_objects)/main.o \
	       $(build_objects)/makina.o \
	       $(build_objects)/game.o \
	       $(build_objects)/variables.o \
	    -o $(build_debug)/$(program) \
	    -L $(glfwlib) \
	    -L $(vklib) \
	       $(link)

main.o:
	g++ -c \
	    -I $(include) \
	    -I $(vkinclude) \
	    -I $(glfwinclude) \
	       $(source)/main.cpp \
	    -o $(build_objects)/main.o

makina.o:
	g++ -c \
	    -I $(include) \
	    -I $(vkinclude) \
	    -I $(glfwinclude) \
	       $(source)/makina.cpp \
	    -o $(build_objects)/makina.o

game.o:
	g++ -c \
	    -I $(include) \
	    -I $(vkinclude) \
	    -I $(glfwinclude) \
	       $(source)/game.cpp \
	    -o $(build_objects)/game.o

variables.o:
	g++ -c \
	    -I $(include) \
	    -I $(vkinclude) \
	    -I $(glfwinclude) \
	       $(source)/variables.cpp \
	    -o $(build_objects)/variables.o

debug:
	gdb $(build_debug)/$(program)

test:
	$(build_debug)/$(program)

clean:
	rm $(build_objects)/*.o
	rm $(build_debug)/*.exe
