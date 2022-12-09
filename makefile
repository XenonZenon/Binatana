projdir := ..\Bintana
appname := Bintana
include := $(projdir)\include
source := $(projdir)\source
build_objects := $(projdir)\build\objects
build_debug := $(projdir)\build\debug

vklib := $(projdir)\libraries\VulkanSDK\1.3.231.1\Lib
vkinclude := $(projdir)\libraries\VulkanSDK\1.3.231.1\Include
glfwlib := $(projdir)\libraries\glfw\lib
glfwinclude := $(projdir)\libraries\glfw\include

c_flags := -O3 -Wall -std=c++17 -static-libstdc++ -static-libgcc
windows_flag := -mwindows
link := -lglfw3dll -lvulkan-1 -lgdi32 -luser32 -lkernel32

objects := main.o

build: $(objects)
	g++ -s $(c_flags) \
       $(build_objects)/main.o \
			 -o $(build_debug)/$(appname) \
			 -L $(glfwlib) \
			 -L $(vklib) \
			 $(link)

main.o:
	g++ -c -I $(include) -I $(vkinclude) -I $(glfwinclude) $(source)/main.cpp -o $(build_objects)/main.o


test:
	$(build_debug)/$(appname)

clean:
	del $(build_objects)\*.o
	del $(build_debug)\*.exe
