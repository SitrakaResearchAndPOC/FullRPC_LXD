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

# Exercice 2 :  TP RPC
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

# Exercice 3 : Entrainnement C, 
3.1 -> Affichage Hello world </br>
3.2 -> Affichage d’un variable ayant comme contenu 10 </br>
3.3 -> Afffichage de texte entrée comme paramètre en ligne de commande </br>
3.4 -> Affichage de texte avec plusieurs arguments en ligne de commande </br>
3.5 -> Déclaration d’un variable, saisie d’un nombre et affichage de ce nombre </br>
3.6 -> Creation de fonction somme (entier) </br>
3.7 -> Creation d’une fonction somme avec verification overflow </br>
3.8 -> Creation de fonction somme de deux structures points en utilisant une passage par copie </br>
3.9 -> passage par pointeur de la function somme </br>
3.10 ->  Création d’une de la function somme C en utilisant une passage par pointeur </br>

# Reponse 3.1
3.1 -> Affichage Hello world
INSTALLER : apt install mousepad
```
lxc exec FullRPC -- bash
```
```
mkdir TPC
```
```
cd TPC/
```
```
nano helloworld.c
```
```
#include <stdio.h> </br>
#include <stdlib.h> </br>

void main(){ </br>
	&nbsp; printf("hello world\n"); </br>
} </br>
```

gcc -c helloworld.c
gcc -o helloworld helloworld.o
chmod +x helloworld
./helloworld
 

REPONSE 3.2 
3.2 -> Affichage d’un variable ayant comme contenu 10
nano affichageVar.c
 

#include <stdio.h> 
#include <stdlib.h> 

void main(){
	int var = 10;
	printf("le variable est donc %d \n", var);
}


gcc -c affichageVar.c
gcc -o affichageVar affichageVar.o
chmod +x affichageVar
./affichageVar
 

REPONSE 3.3
3.3 -> Afffichage de texte entrée comme paramètre en ligne de commande
La declaration de main deviant c.f https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean : 
int main (int argc, char *argv[]); //first declaration
int main (int argc, char **argv);  //RE-DECLARATION. Equivalent to the above declaration

 
Le code final sera donc : 
nano affichage.c
 
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
	if(argc == 1){
		printf("pas de paramètre\n");
        }
	else if(argc == 2){
		printf("le paramètre est %s \n", argv[1]);
	} else {
		printf("le nombre de paramètre est invalide \n");	
	}

}

gcc -c affichage.c 
gcc -o affichage affichage.o 
chmod +x affichage

Test après : 
./affichage
 
./affichage test
 
./affichage "test is ok"
 
./affichage test is ok
 

REPONSE 3.4
3.4 -> Affichage de texte avec plusieurs arguments en ligne de commande
nano affichageMultiple.c
 
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
	int i = 0;
	if(argc == 1){
		printf("pas de paramè?tre\n");
        }
	else if(argc >= 2){
		for(i = 1; i < argc ; i++){
			printf("le paramè?tre numero %d est %s \n", i, argv[i]);
		}
	} else {
		printf("le nombre de paramè?tre est invalide \n");	
	}
}

gcc -c affichageMultiple.c
gcc -o affichageMultiple affichageMultiple.o
chmod +x affichageMultiple
./affichageMultiple
 
./affichageMultiple test
 
./affichageMultiple "test is ok"
 
./affichageMultiple test is ok
 

REPONSE 3.5
3.5 -> Déclaration d’un variable, saisie d’un nombre et affichage de ce nombre
nano saisie.c
 
#include <stdio.h>
#include <stdlib.h>


void main(){
	int var = 0;
	printf("veuillez entrer un nombre entier\n");
	scanf("%d", &var);
	printf("vous avez entré? le nombre : %d \n", var);

}


gcc -c saisie.c 
gcc -o saisie saisie.o 
chmod +x saisie
./saisie
 

REPONSE 3.6
3.6 -> Creation de fonction somme (entier)
nano fonc_somme.c
 
#include <stdio.h>
#include <stdlib.h>


int somme(int nb1, int nb2){
	return nb1 + nb2;
}


void main(){
	int nombre1;
	int nombre2;
	int resultat; 

	printf("Entrer un nombre\n");
	scanf("%d", &nombre1);


	printf("Entrer un autre nombre\n");
	scanf("%d", &nombre2);

	
	resultat = somme(nombre1, nombre2);
	printf("la somme de %d et de %d est donc : %d\n", nombre1, nombre2, resultat);
}


gcc -c fonc_somme.c 
gcc -o fonc_somme fonc_somme.o 
chmod +x fonc_somme
./fonc_somme
 


REPONSE 3.7
3.7 -> Creation d’une fonction somme avec verification overflow
nano overf_somme.c 
 
#include <stdio.h>
#include <stdlib.h>

typedef struct result{
	unsigned int resultat;
	unsigned int errno;
}result;
result somme(unsigned int nb1, unsigned int nb2){
	result rr;
	rr.resultat = nb1 + nb2;
	//obtenir maximal 
	unsigned int max = nb1;
	if(nb2 > max){
		max = nb2;
	}
	if(rr.resultat > max){
		rr.errno = 0;
	}else {
		rr.errno = 1;
	}
	return rr;
}

void main(){
	unsigned int nombre1;
	unsigned int nombre2;
	result r; 
	printf("Entrer un nombre\n");
	scanf("%u", &nombre1);

	printf("Entrer un autre nombre\n");
	scanf("%u", &nombre2);

	r = somme(nombre1, nombre2);
	if (r.errno ==0){
		printf("la somme de %d et de %d est donc : %d\n", nombre1, nombre2, r.resultat);
	} else{
		printf("erreur de la somme\n");
	}
}


gcc -c overf_somme.c 
gcc -o overf_somme overf_somme.o 
chmod +x overf_somme

./overf_somme 
Le nombre maximal unsigned int est : 4294967295
 
Note bonus pour la verification overf_somme en utilisant int et non unsigned int ?



REPONSE 3.8 : cf. https://www.youtube.com/watch?v=cByXgJXaTB4
3.8 -> Creation d’une structure pour faire une function somme avec verification de overflow
nano somme_struct.c
 
#include <stdio.h>
#include <stdlib.h>

typedef struct result{
	unsigned int resultat;
	unsigned int errno; //la fonction somme retourne -1 comme errno si c'est faux, retourne 1 sinon 
}result;

typedef struct entree{
	unsigned int nombre1;
	unsigned int nombre2;

}entree;

// une addition possè?de un overflow quand la somme des deux nombre est infè?rieure au maximal des deux nombres dont la somme est à faire 
result fonc_somme(entree e){
	result r;
	r.resultat  = e.nombre1 + e.nombre2;
	//obtenir maximal entre e.nombre1 et e.nombre2
	unsigned int max = e.nombre1;
	if(e.nombre2 > e.nombre1){
		max = e.nombre1;
	}
	
	if(r.resultat > max){
		r.errno = 0;
	}else{
		r.errno = 1;
	}
	return r;
}
void main(){
	unsigned int nb1;
	unsigned int nb2;
	printf("veuillez entrer un nombre \n");
	scanf("%u", &nb1);
	printf("veuillez entrer un autre nombre \n");
	scanf("%u", &nb2);
	
	entree t;
	t.nombre1 = nb1;
	t.nombre2 = nb2;
	result rr = fonc_somme(t);
	if( rr.errno ==  0){
		printf("la somme de %u et de %u donne %u\n", t.nombre1, t.nombre2, rr.resultat);
	}else{
		printf("erreur de la somme\n");
	}

}

gcc -c somme_struct.c 
gcc -o somme_struct somme_struct.o 
chmod +x somme_struct
./somme_struct
 
Le nombre maximal unsigned int est : 4294967295
 
	Note BONUS : Pour un code en C, non signé avec verification overflow ?

REPONSE 3.9 
3.9 -> passage par pointeur de la function somme
 nano pointeur_somme.c 
 

#include <stdio.h>
#include <stdlib.h>


void somme(int *result, int nb1, int nb2){
	(*result) =  nb1 + nb2;
}


void main(){
	int nombre1;
	int nombre2;
	int resultat = -1; 

	printf("Entrer un nombre\n");
	scanf("%d", &nombre1);


	printf("Entrer un autre nombre\n");
	scanf("%d", &nombre2);

	
	somme(&resultat, nombre1, nombre2);
	printf("la somme de %d et de %d est donc : %d\n", nombre1, nombre2, resultat);
}

gcc -c pointeur_somme.c 
gcc -o pointeur_somme pointeur_somme.o 
chmod +x pointeur_somme
./pointeur_somme
 

REPONSE 3.10 :
3.10 ->  Création d’une de la function somme C en utilisant une passage par pointeur
nano somme_struct_pointeur.c 
 
#include <stdio.h>
#include <stdlib.h>


typedef struct info{
	unsigned int nombre1;
	unsigned int nombre2;
	unsigned int resultat;
	unsigned int errno; //la fonction somme retourne -1 comme errno si c'est faux, retourne 1 sinon 
	 

}info;


// une addition possè?de un overflow quand la somme des deux nombre est infè?rieure au maximal des deux nombres dont la somme est à? faire 
void fonc_somme(info *i){
	i->resultat  = i->nombre1 + i->nombre2;
	//obtenir maximal entre i->nombre1 et i->nombre2
	unsigned int max = i->nombre1;
	if(i->nombre2 > i->nombre1){
		max = i->nombre1;
	}
	
	if(i->resultat > max){
		i->errno = 0;
	}else{
		i->errno = 1;
	}
}
void main(){
	unsigned int nb1;
	unsigned int nb2;
	printf("veuillez entrer un nombre \n");
	scanf("%u", &nb1);
	printf("veuillez entrer un autre nombre \n");
	scanf("%u", &nb2);
	
	info data;
	data.nombre1 = nb1;
	data.nombre2 = nb2;
	fonc_somme(&data);
	if(data.errno ==  0){
		printf("la somme de %u et de %u donne %u\n", data.nombre1, data.nombre2, data.resultat);
	}else{
		printf("erreur de la somme\n");
	}

}

gcc -c somme_struct_pointeur.c 
gcc -c somme_struct_pointeur.c 
gcc -o somme_struct_pointeur somme_struct_pointeur.o 
chmod +x somme_struct_pointeur
./somme_struct
 
Le nombre maximal unsigned int est : 4294967295

exit 


