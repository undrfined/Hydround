# Hydround
[![Join the chat at https://gitter.im/undrfined/Hydround](https://badges.gitter.im/undrfined/Hydround.svg)](https://gitter.im/undrfined/Hydround?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)  
MC:PE server core written in C++. Work in progress.
# How to compile?
First of all, download sources from github.
```
git clone https://github.com/undrfined/Hydround.git
```
Next, start compiling using this commands. You need [boost](https://boost.org) to compile it.
```
cd Hydround
make
```
Also you can use install.sh script. It will be install all needed packages and libraries automatically. **Warning!** It's need to be updated, don't use it.
```
sudo ./install.sh
```
Once you compiled Hydround, you should run the binary file named 'hydround':
```
./hydround
```
You need launch exactly 'hydround', not 'hydround.so'.
# Plugins?
There is TestPlugin in plugins directory. Just compile it using make in TestPlugin directory.  
If you want write your own plugin, go [here](https://github.com/undrfined/Hydround/wiki/Plugin-documentation)
# Windows?
Hydround **_not_** supports windows right now. Sorry.
