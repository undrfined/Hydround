-> ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒<-  
->▒▒█▒▒█▒█▒▒█▒███▒▒███▒▒▒██▒▒█▒▒█▒█▒▒█▒███▒▒<-  
->▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒██▒█▒█▒▒█▒<-  
->▒▒████▒▒███▒█▒▒█▒███▒▒█▒▒█▒█▒▒█▒█▒██▒█▒▒█▒<-  
->▒▒█▒▒█▒▒▒▒█▒█▒▒█▒█▒█▒▒█▒▒█▒█▒▒█▒█▒▒█▒█▒▒█▒<-  
->▒▒█▒▒█▒▒██▒▒███▒▒█▒▒█▒▒██▒▒▒██▒▒█▒▒█▒███▒▒<-  
-> ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒<-  
[![Join the chat at https://gitter.im/undrfined/Hydround](https://badges.gitter.im/undrfined/Hydround.svg)](https://gitter.im/undrfined/Hydround?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)  
MC:PE server core written in C++.
# How to compile?
First of all, download sources from github.
```
git clone https://github.com/undrfined/Hydround.git
```
Next, start compiling using this commands. You need [boost](boost.org) to compile it.
```
cd Hydround
make
```
Also you can use install.sh script. It will be install all needed packages and libraries automatically. But we not recomendated use it.
```
sudo ./install.sh
```
# How to launch?
Once you compile Hydround, you should run the binary file named 'hydround':
```
./hydround
```
# Plugins?
There is TestPlugin in plugins directory. Just compile it using make in TestPlugin directory.
# Windows?
Hydround **_not_** supports windows right now. The reason is i have not windows yet.
