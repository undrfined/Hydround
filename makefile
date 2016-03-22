all:
	@echo "\033[32m[Hydround] Compiling...\033[0m"
	@g++ -fdiagnostics-color=always -std=c++11 -g -I include -ldl -shared -fPIC Hydround.cpp utils/*.cpp -o lib/hydround.so || { echo "\033[31m[Hydround] Compilation aborted.\033[0m"; exit 1; }
	@g++ -I include HYS.cpp -o hydround -ldl
	@echo "\033[32m[Hydround] Succesfully compiled!\033[0m"
