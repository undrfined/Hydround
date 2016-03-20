all:
	@echo "\033[32m[Hydround] Compiling...\033[0m"
	@g++ -std=c++1y -fdiagnostics-color=always -g -I include -ldl -shared -fPIC Hydround.cpp utils/*.cpp -o hydround.so || { echo "\033[31m[Hydround] Compilation aborted.\033[0m"; exit 1; }
	@g++ -I include HYS.cpp -o hydround -ldl
	@echo "\033[32m[Hydround] Succesfully compiled!\033[0m"
