all:
	@echo "\033[32m[Hydround] Compiling...\033[0m"
	@g++ *.cpp utils/*.cpp -lboost_system -o Hydround -w -fdiagnostics-color=always -lpthread || { echo "\033[31m[Hydround] Compile aborted.\033[0m"; exit 1; }
	@echo "\033[32m[Hydround] Succesfully compiled!\033[0m"