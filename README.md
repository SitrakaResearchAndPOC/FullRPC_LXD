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

