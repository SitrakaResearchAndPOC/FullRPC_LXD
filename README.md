# FullRPC_LXD
* Installation LXC de debian 10
* Exercices concernant les socket
* Exercices concernant RPC et Makefile

# Installation de Debian 10 dans LXC
```
lxc launch images:debian/10 FullRPC
```
```
lxc exec FullRPC -- bash
```
# EXERCICE 1 : SOCKET 
```
mkdir SOCKET
```
```
cd SOCKET/
```
```
git clone https://github.com/ImsicatcherBastienbaranoff/tpsocket
```
```
cd tpsocket
```
```
unzip client-server.zip
```
```
gcc -o tcpclient tcpclient.c
```
```
chmod +x tcpclient
```
```
gcc -o tcpserver tcpserver.c
```
```
chmod +x tcpserver
```
```
exit
```
# Lanchement de FullRPC comme socket
```
lxc exec FullRPC -- bash
```
```
./SOCKET/tpsocket/tcpserver
```
Ctrl + shift + t
```
lxc exec FullRPC -- bash
```
```
./SOCKET/tpsocket/tcpclient
 ```
Dans l’autre terminal :  </br>
Tapez hey :  </br>
Dans l’autre terminal : </br>
Tapez : ok </br>
Dans l’autre terminal : </br>
Quittez </br>
```
exit
```




Exercice 2 :  TP RPC
Installation des dependances  </br>
Essai de RPC pour hello world code predefine : [RPC_Helloworld](https://github.com/riyazathali/RPC-HelloWorld) 
```
lxc exec FullRPC -- bash
```
```
apt update
```
```
sudo apt install rpcbind
```
```
/etc/init.d/rpcbind start
```
```
sudo apt install build-essential
```
```
sudo apt-get install manpages-dev
```
```
sudo apt install libc-dev-bin
```
```
apt-get install zip
```
```
apt-get install git

```
```
apt-get install nano mousepad
```
rpcgen devrait marcher correctement : 
```
git clone https://github.com/riyazathali/RPC-HelloWorld
```
```
cd RPC-HelloWorld/
```
```
rpcgen -a -C hw.x
```
```
make -f Makefile.hw
```
```
sudo ./hw_server 
```
Tapez ctrl-shift T 
```
lxc exec FullRPC -- bash
```
```
cd RPC-HelloWorld/
```
```
sudo ./hw_client localhost
```

