all:
	@echo "\033[32m[Hydround] Compiling...\033[0m"
	@g++ -ldl -shared -fPIC Hydround.cpp -w -fdiagnostics-color=always -o hydround.so || { echo "\033[31m[Hydround] Compilation aborted.\033[0m"; exit 1; }
	@g++ HYS.cpp -o hydround -ldl
	@echo "\033[32m[Hydround] Succesfully compiled!\033[0m"
