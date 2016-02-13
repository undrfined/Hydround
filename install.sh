#!/bin/sh

# installer for Hydround #
echo "\n\n\n"
echo "	\033[36m ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\033[0m"
echo "	\033[36m▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒\033[0m"
echo "	\033[36m▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒\033[0m"
echo "	\033[36m▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒\033[0m"
echo "	\033[36m▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒\033[0m"
echo "	\033[36m▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒\033[0m"
echo "	\033[36m ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\033[0m"
echo "\n\n\n			Installer."
if [ $(dpkg-query -W -f='${Status}' g++ 2>/dev/null | grep -c "ok installed") -eq 0 ];
then
  echo "\033[31m[Hydround] G++ package is not installed! Install it now? [y/n]\033[0m"
  read gcc
  if [ "$gcc" = "y" ]; then 
  apt-get install gcc-c++
  else
  echo "\033[31m[Hydround] Install aborted(g++ package is not installed).\033[0m"
  exit 1;
fi
else echo "\033[32m[Hydround] G++ package found!\033[0m"
if [ $(dpkg-query -W -f='${Status}' git 2>/dev/null | grep -c "ok installed") -eq 0 ];
then
  echo "\033[31m[Hydround] Git package is not installed! Install it now? [y/n]\033[0m"
  read git
  if [ "$git" = "y" ]; then 
    apt-get install git
  else
  echo "\033[31m[Hydround] Install aborted(git package is not installed).\033[0m"
  exit 1;
fi
else echo "\033[32m[Hydround] Git package found!\033[0m"
fi
fi
if [ $(dpkg-query -W -f='${Status}' libboost-all-dev 2>/dev/null | grep -c "ok installed") -eq 0 ];
then
  echo "\033[31m[Hydround] Boost library is not installed! Install it now? [y/n]\033[0m"
  read boost
  if [ "$boost" = "y" ]; then 
      apt-get install libboost-all-dev

  else
  echo "\033[31m[Hydround] Install aborted(Boost library is not installed).\033[0m"
  exit 1;
fi
else echo "\033[32m[Hydround] Boost library found!\033[0m"
fi
echo "\033[32m[Hydround] All packages & libraries are found, downloading Hydround...\033[0m"
echo "\033[36m[Hydround] Please, enter path to install Hydround: \033[0m"
read path
mkdir -p $path || {
echo "\033[31m[Hydround] Install aborted(can't create directory).\033[0m"
exit 1
}
files=$path
if [ ! ${#files[@]} -gt 0 ]; then 
echo "\033[31m[Hydround] Install aborted(directory not empty).\033[0m"
exit 1
fi
cd $path
git clone https://github.com/undrfined/Hydround.git || {
  echo "\033[31m[Hydround] Install aborted(Git can't download source files).\033[0m"
  exit 1;
}
echo "\033[32m[Hydround] Downloaded! Compiling...\033[0m"
cd Hydround
if ! make; then 
echo "\033[31m[Hydround] Install aborted(can't compile).\033[0m"
exit 1
fi
echo "\033[32m[Hydround] Hydround succesfully installed! Run server right now? [y/n]\033[0m"
read run
if [ "$run" = "y" ]; then
./Hydround
else
echo "\033[32m[Hydround] Exit.\033[0m"
exit 0
fi 
fi