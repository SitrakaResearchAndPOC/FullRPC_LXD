# FullRPC_LXD
* Installation LXC de debian 10
* Exercices concernant les socket
* Exercices concernant RPC et Makefile
# installation LXD
# INSTALLING LXD
## For recent version by snap
```  
apt update
```  
```  
apt install snapd 
```  
```  
snap install lxd 
```  
```  
snap install lxd-client
```  
```  
sudo usermod -a G lxd $USER  
```  
```  
export PATH=$PATH:/usr/local/bin  
```  
## For old version by only apt
```  
apt update
```  
```  
apt-get install lxd 
```  
```  
apt-get install lxd-client
```  
```  
sudo usermod -a G lxd $USER  
```  
```  
export PATH=$PATH:/usr/local/bin  
```  

# Installation de Debian 10 dans LXC
```
lxc launch images:debian/10 FullRPC
```
```
lxc exec FullRPC -- bash
```
```
apt update
```
```
apt install git zip gcc
```
```
apt-get install nano mousepad
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
# GUI INSTALLING


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
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
#include <stdio.h>
#include <stdlib.h>

void main(){
	printf("hello world\n");
}
```
```
gcc -c helloworld.c
```
```
gcc -o helloworld helloworld.o
```
```
chmod +x helloworld
```
```
./helloworld
 ```
```
exit
```

# Reponse 3.2 
3.2 -> Affichage d’un variable ayant comme contenu 10
```
lxc exec FullRPC -- bash
```
```
nano affichageVar.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
#include <stdio.h> 
#include <stdlib.h> 

void main(){
	int var = 10;
	printf("le variable est donc %d \n", var);
}
```
```
gcc -c affichageVar.c
```
```
gcc -o affichageVar affichageVar.o
```
```
chmod +x affichageVar
```
```
./affichageVar
```
```
exit
```

# Reponse 3.3
3.3 -> Afffichage de texte entrée comme paramètre en ligne de commande </br>
La declaration de main deviant c.f [argc](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean) :  </br>
int main (int argc, char *argv[]); //first declaration </br>
int main (int argc, char **argv);  //RE-DECLARATION. Equivalent to the above declaration </br>
```
lxc exec FullRPC -- bash 
```
```
nano affichage.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c affichage.c 
```
```
gcc -o affichage affichage.o 
```
```
chmod +x affichage
```
Test après : 
```
./affichage
```
```
./affichage test
```
```
./affichage "test is ok"
```
```
./affichage test is ok
```
```
exit
```
 

# Reponse 3.4
3.4 -> Affichage de texte avec plusieurs arguments en ligne de commande
```
lxc exec FullRPC -- bash
```
```
nano affichageMultiple.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c affichageMultiple.c
```
```
gcc -o affichageMultiple affichageMultiple.o
```
```
chmod +x affichageMultiple
```
```
./affichageMultiple
```
``` 
./affichageMultiple test
```
``` 
./affichageMultiple "test is ok"
```
``` 
./affichageMultiple test is ok
```
```
exit
```


# Reponse 3.5
3.5 -> Déclaration d’un variable, saisie d’un nombre et affichage de ce nombre
```
lxc exec FullRPC -- bash
```
```
nano saisie.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
#include <stdio.h>
#include <stdlib.h>
void main(){
	int var = 0;
	printf("veuillez entrer un nombre entier\n");
	scanf("%d", &var);
	printf("vous avez entré? le nombre : %d \n", var);
}
```
```
gcc -c saisie.c 
```
```
gcc -o saisie saisie.o 
```
```
chmod +x saisie
```
```
./saisie
```
```
exit
```

# Reponse 3.6
3.6 -> Creation de fonction somme (entier)
```
lxc exec FullRPC -- bash
```
```
nano fonc_somme.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c fonc_somme.c 
```
```
gcc -o fonc_somme fonc_somme.o 
```
```
chmod +x fonc_somme
```
```
./fonc_somme
```
```
exit
```

# Reponse 3.7
3.7 -> Creation d’une fonction somme avec verification overflow
```
lxc exec FullRPC -- bash
```
```
nano overf_somme.c 
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c overf_somme.c 
```
```
gcc -o overf_somme overf_somme.o 
```
```
chmod +x overf_somme
```
```
./overf_somme 
```
Le nombre maximal unsigned int est : 4294967295 </br>
Note bonus pour la verification overf_somme en utilisant int et non unsigned int ? </br>
```
exit
```



# Reponse 3.8 :
cf.  [video_indication](https://www.youtube.com/watch?v=cByXgJXaTB4) </br>
3.8 -> Creation d’une structure pour faire une function somme avec verification de overflow
```
lxc exec FullRPC -- bash
```
```
nano somme_struct.c
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c somme_struct.c 
```
```
gcc -o somme_struct somme_struct.o 
```
```
chmod +x somme_struct
```
```
./somme_struct
```
Le nombre maximal unsigned int est : 4294967295 </br> 
Note BONUS : Pour un code en C, non signé avec verification overflow ?
```
exit
```

# Reponse 3.9 
3.9 -> passage par pointeur de la function somme
```
lxc exec FullRPC -- bash
```
```
nano pointeur_somme.c 
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c pointeur_somme.c 
```
```
gcc -o pointeur_somme pointeur_somme.o 
```
```
chmod +x pointeur_somme
```
```
./pointeur_somme
```
```
exit
```


# Reponse 3.10 :
3.10 ->  Création d’une de la function somme C en utilisant une passage par pointeur 
```
lxc exec FullRPC -- bash
```
```
nano somme_struct_pointeur.c 
```
Copier le code suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
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
```
```
gcc -c somme_struct_pointeur.c 
```
```
gcc -c somme_struct_pointeur.c 
```
```
gcc -o somme_struct_pointeur somme_struct_pointeur.o 
```
```
chmod +x somme_struct_pointeur
```
```
./somme_struct
```
Le nombre maximal unsigned int est : 4294967295 </br>
```
exit 
```

# Exercice 4.1 : RPC calcul
TP RPC cf.  lecons 
```
lxc exec FullRPC -- bash
```
```
mkdir RPC
```
```
cd RPC/
```
```
ls
```
```
mkdir somme
```
```
cd somme/
```
```
nano calcul.x
```
Copier la configuration IDL suivant puis tapez ctrl+x et Y et enter pour enregistrer
```
struct data {
  unsigned int arg1;
  unsigned int arg2;
};

typedef struct data data;

struct reponse {
  unsigned int somme;
  int errno;
};

typedef struct reponse reponse;

program CALCUL{
  version VERSION_UN{
    void CALCUL_NULL(void) = 0;
    reponse CALCUL_ADDITION(data) = 1;
  } = 1;
} = 0x20000001;
```
```
rpcgen -a calcul.x
```
```
ls
```
rpcgen a généré des code c et Makefile pour nous
```
gcc -c calcul_xdr.c
```
```
gcc -c calcul_clnt.c
```
```
gcc -c calcul_svc.c
```
En regardant dans le fichier  : 
```
nano calcul_server.c
```
Il faut modifier le code en implementant l’addition à faire au niveau de serveur en particulier dans la function calcul_addition_1_svc
``` 
#include "calcul.h"

void * 
calcul_null_1_svc(void *argp, struct svc_req *rqstp)
{
  static char* result;
  /* Ne rien faire */
  return((void*) &result);
}

reponse * 
calcul_addition_1_svc(data *argp, struct svc_req *rqstp)
{
  static reponse  result;
  unsigned int max;

  result.errno = 0; /* Pas d'erreur */

  /* Prend le max */
  max = argp->arg1 > argp->arg2 ? argp->arg1 : argp->arg2;

  /* On additionne */
  result.somme = argp->arg1 + argp->arg2; 

  /* Overflow ? */
  if ( result.somme < max ) {
    result.errno = 1;
  }
    
  return(&result);
}
```
```
gcc -c calcul_server.c
```
```
gcc -o server calcul_svc.o calcul_server.o calcul_xdr.o
```
```
./server &
``` 
ctrl +shift + t
```
lxc exec FullRPC -- bash
```
```
rpcinfo -p
```
```
cd RPC/somme
```
```
mkdir client
```
```
cp calcul.x client/
```
```
cd client
```
```
rpcgen -a calcul.x 
```
```
ls
```
```
gcc -c calcul_xdr.c
```
```
gcc -c calcul_clnt.c
```
```
gcc -c calcul_svc.c
```
Regardons d’abord le code calcul_client.c par : 
```
nano calcul_client.c
```
Changeons par le code adequate en particulier dans la fonction main tout en créant la function test_addition. </br>
Aprés modification, le code sera : (le mieux est d'effacer la fonction main est recopier le code) </br>
```
#include <limits.h>
#include "calcul.h"

CLIENT *clnt;

void
test_addition (uint param1, uint param2)
{	
  reponse  *resultat;
  data  parametre;

  /* 1. Preparer les arguments */
  
  parametre.arg1 = param1;
  parametre.arg2 = param2; 
  printf("Appel de la fonction CALCUL_ADDITION avec les parametres: %u et %u \n", parametre.arg1,parametre.arg2);

  /* 2. Appel de la fonction distante */
  
  resultat = calcul_addition_1 (&parametre, clnt);
  if (resultat == (reponse *) NULL) {
    clnt_perror (clnt, "call failed");
    clnt_destroy (clnt);
    exit(EXIT_FAILURE);
  }
  else if ( resultat->errno == 0 ) {
    printf("Le resultat de l'addition est: %u \n\n",resultat->somme);
  } else {
    printf("La fonction distante ne peut faire l'addition a cause d'un overflow \n\n");
  }
  
}

int
main (int argc, char *argv[])
{
  char *host;
  
  if (argc < 2) {
    printf ("usage: %s server_host\n", argv[0]);
    exit (1);
  }
  host = argv[1];
  
  clnt = clnt_create (host, CALCUL, VERSION_UN, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror (host);
    exit (1);
  }
  
  test_addition ( UINT_MAX - 15, 10 );
  test_addition ( UINT_MAX, 10 );
  
  clnt_destroy (clnt);
  exit(EXIT_SUCCESS);
}
```
```
gcc -c calcul_client.c
```
```
gcc -o client calcul_client.o calcul_clnt.o calcul_xdr.o
```
```
./client localhost
```
```
exit
```
# Exercice 4.2 : 
Ecrire le code en C pour faire  une Valeure absolue distante
```
lxc exec FullRPC -- bash
```
```
cd RPC
```
```
mkdir valeurabsolue
```
```
cd valeurabsolue
```
```
nano va.x
``` 
Copier et enregistrer la configuration
``` 
struct data {
	int entree;
};

typedef struct data data;

struct reponse {
	int sortie;
};

typedef struct reponse reponse;

program VA{
  version VERSION_UN{
    void VA_NULL(void) = 0;
    reponse VA_abs(data) = 1;
  } = 1;
} = 0x20000001;
```
```
rpcgen -a va.x
```
```
gcc -c va_xdr.c
```
```
gcc -c va_clnt.c
```
```
gcc -c va_svc.c
```
```
nano va_server.c
```
Verifions d’abord le code par défaut </br>
Modifions le code de la function abs </br>
```
nano va_server.c
```
Copier puis enregistrer le code
``` 
/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "va.h"

void *
va_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

reponse *
va_abs_1_svc(data *argp, struct svc_req *rqstp)
{
	static reponse  result;

	/*
	 * insert server code here
	 */
	if(argp->entree >= 0)
		result.sortie = argp->entree;
	else{
		result.sortie = -argp->entree;
	}

	return &result;
}
```
```
gcc -c va_server.c
```
```
gcc -o server va_svc.o va_server.o va_xdr.o
```
```
./server &
```
Tapez ctrl+shit+T
``` 
lxc exec FullRPC -- bash
```
```
rpcinfo
```
```
cd RPC/valeurabsolue 
```
```
mkdir client
```
```
cp va.x client/
```
```
cd client
```
```
rpcgen -a va.x
```
```
ls
```
```
gcc -c va_xdr.c
```
```
gcc -c va_clnt.c
```
```
gcc -c va_svc.c
```
```
nano va_client.c
```
Le code initial dans va_client est: </br>
Modifions le code dans le main pour faire l’appel de Valeur absolue </br>
```
nano va_client.c
```
```
/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <limits.h>
#include "va.h"

CLIENT *clnt;

void test_va(int nombre){
	reponse  *resultat;
 	data  parametre;
	
	parametre.entree = nombre;
	resultat = va_abs_1 (&parametre, clnt);
	if (resultat == (reponse *) NULL) {
    		clnt_perror (clnt, "call failed");
    		clnt_destroy (clnt);
    		exit(EXIT_FAILURE);
  	}
  	else {
  	  printf("la valeur de valeur %d est %d \n", parametre.entree, resultat->sortie);
  	} 



}
int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	/*adding code valeur absolue*/
	  clnt = clnt_create (host, VA, VERSION_UN, "udp");
	  if (clnt == NULL) {
    		clnt_pcreateerror (host);
   		  exit (1);
  	}
  	test_va ( -15);
  	test_va ( 15 );
  	clnt_destroy (clnt);	
exit (0);
}
```
```
gcc -c va_client.c
```
```
gcc -o client va_client.o va_clnt.o va_xdr.o
```
```
./client localhost
```
```
exit
```

# EXERCICE 4.3
Faire un code C RPC permettant de factoriser un nombre en produit de deux nombres premiers 
```
lxc exec FullRPC -- bash
```
```
cd RPC
```
```
mkdir factorisation
```
```
cd factorisation
```
```
nano factorisation.x
```
Copier et enregister la configuration
```
struct data {
	int n;
};

typedef struct data data;

struct reponse {
	int p;
	int q;
	int errno;
};

typedef struct reponse reponse;

program FACTORISATION{
  version VERSION_UN{
    void FACTORISATION_NULL(void) = 0;
    reponse FACTORISATION_UN(data) = 1;
  } = 1;
} = 0x20000001;
```
```
rpcgen -a factorisation.x
```
```
gcc -c factorisation_xdr.c
```
```
gcc -c factorisation_clnt.c
```
```
gcc -c factorisation_svc.c
```
```
nano factorisation_server.c
```
Verifions d’abord le code par défaut </br>
Modifions le code de la function factorisation </br>
```
nano factorisation_server.c
```
Copier et enregister le code
```
/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "factorisation.h"

void *
factorisation_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

/* 
fonction pour verifier si nombre premier
*/
int est_premier(int nbr){
    int i = 0;
    if(nbr == 2){
        return 1;
    }
    for(i=2; i < nbr-1; i++){
        if(nbr%2 == 0){
            return 0;
        }
    }
    return 1;
}


reponse *
factorisation_un_1_svc(data *argp, struct svc_req *rqstp)
{
	static reponse  result;

	result.p = -1;
	result.q = -1;
	result.errno = 1;
	int i = 0;
	for(i = 2; i< argp->n; i++){
		if(argp->n%i ==0){
			int p = i;
			int q = (argp->n)/i;
			if((p*q == argp->n)&&(est_premier(p))&&(est_premier(q))){
				result.p = p;
				result.q = q;
				result.errno = 0;
								
			}

		}
	}


	return &result;
}
```
```
gcc -c factorisation_server.c
```
```
gcc -o server factorisation_svc.o factorisation_server.o factorisation_xdr.o
```
```
./server &
```
ctrl + shift + t
```
lxc exec FullRPC -- bash
```
```
rpcinfo
```
```
cd RPC/factorisation 
```
```
mkdir client
```
```
cp factorisation.x client/
```
```
cd client
```
```
rpcgen -a factorisation.x
```
```
ls
```
```
gcc -c factorisation_xdr.c
```
```
gcc -c factorisation_clnt.c
```
```
gcc -c factorisation_svc.c
```
```
nano factorisation_client.c
```
Le code initial dans factorisation_client est: </br>
Modifions le code dans le main pour faire l’appel de la function factorisation </br>
```
nano factorisation_client.c
```
Copier et enregistrer le code
```
/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "factorisation.h"

CLIENT *clnt;


void test_factorisation(int nombre){
	reponse  *resultat;
 	data  parametre;
	
	parametre.n = nombre;
	resultat = factorisation_un_1 (&parametre, clnt);
	if (resultat == (reponse *) NULL) {
    		clnt_perror (clnt, "call failed");
    		clnt_destroy (clnt);
    		exit(EXIT_FAILURE);
  	}
  	else {
	  if(resultat->errno != 1){
	  	  printf("Donc %d = %d * %d \n", parametre.n, resultat->p, resultat->q);
  
           }else{
		printf("Erreur de factorisation\n");

	  }

  	} 
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	  clnt = clnt_create (host, FACTORISATION, VERSION_UN, "udp");
	  if (clnt == NULL) {
    		clnt_pcreateerror (host); 
   		  exit (1); 
  	} 
  	test_factorisation (77); 
  	test_factorisation ( 21 );
 	test_factorisation ( 12 );
 
  	clnt_destroy (clnt);	


exit (0);
}
```
```
gcc -c factorisation_client.c
```
```
gcc -o client factorisation_client.o factorisation_clnt.o factorisation_xdr.o
```
```
./client localhost
```
```
exit
```
# EXERCICE 5 : 
Vérifier vraiment que vous utilisez une tabulation et non
# Reponse 5.1 : Makefile type 1
```
lxc exec FullRPC -- bash
```
```
mkdir TP_MAKEFILE
```
```
cd TP_MAKEFILE
```
```
mkdir TP_MAKEFILE1
```
```
git clone https://github.com/SitrakaResearchAndPOC/FullRPC_LXD 
```
```
mv FullRPC_LXD/*.c TP_MAKEFILE1
```
```
mv FullRPC_LXD/*.h TP_MAKEFILE1
```
```
rm -rf FullRPC_LXD
```
```
cd TP_MAKEFILE1
```
```
nano Makefile
```
Copier et Enregistrer
```
all: exec

main.o: main.c tri.h
        gcc -c main.c -o main.o

fonction_tri.o: fonction_tri.c tri.h
                gcc -c fonction_tri.c -o fonction_tri.o

fonction_tableau.o: fonction_tableau.c tri.h
                        gcc -c fonction_tableau.c -o fonction_tableau.o

exec: fonction_tableau.o fonction_tri.o main.o
        gcc fonction_tableau.o fonction_tri.o main.o -o exec

clean:
        rm -rf *.o
        rm -rf exec
```
```
make all
```
```
chmod +x exec 
```
```
./exec 
```
```
make clean
```
```
cd ..
```
```
exit
```


# Reponse 5.2 : TP_MAKEFILE2
```
lxc exec FullRPC -- bash
```
```
cd TP_MAKEFILE
```
```
mkdir TP_MAKEFILE2
```
```
git clone https://github.com/SitrakaResearchAndPOC/FullRPC_LXD 
```
```
mv FullRPC_LXD/*.c TP_MAKEFILE2
```
```
mv FullRPC_LXD/*.h TP_MAKEFILE2
```
```
rm -rf FullRPC_LXD
```
```
cd TP_MAKEFILE2
```
```
nano Makefile
```
Copier et Enregistrer
```
all: exec

main.o: main.c tri.h
         gcc -c $< -o $@

fonction_tri.o: fonction_tri.c tri.h
         gcc -c $< -o $@

fonction_tableau.o: fonction_tableau.c tri.h
         gcc -c $< -o $@

exec: fonction_tableau.o fonction_tri.o main.o
        gcc $^ -o $@

clean:
        rm -rf *.o
        rm -rf exec
```
```
make all
```
```
chmod +x  exec
```
```
./exec 
```
```
make clean
```
```
cd ..
```
```
exit
```

# reponse 5.3 : TP_MAKEFILE3
```
lxc exec FullRPC -- bash
```
```
cd TP_MAKEFILE
```
```
mkdir TP_MAKEFILE3
```
```
git clone https://github.com/SitrakaResearchAndPOC/FullRPC_LXD
```
```
mv FullRPC_LXD/*.c TP_MAKEFILE3
```
```
mv FullRPC_LXD/*.h TP_MAKEFILE3
```
```
rm -rf FullRPC_LXD
```
```
cd TP_MAKEFILE3
```
```
nano Makefile
```
Copier et Enregistrer
```
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
all: exec

main.o: main.c tri.h
         $(CC) -c $< -o $@

fonction_tri.o: fonction_tri.c tri.h
         $(CC) -c $< -o $@

fonction_tableau.o: fonction_tableau.c tri.h
         $(CC) -c $< -o $@

exec: $(OBJ)
        $(CC) $^ -o $@

clean:
        rm -rf *.o
        rm -rf exec
```
```
make all
```
```
chmod +x exec 
```
```
./exec 
```
```
make clean
```
```
cd ..
```
```
exit
```

# reponse 5.4 : TP_MAKEFILE4
```
lxc exec FullRPC -- bash
```
```
cd TP_MAKEFILE
```
```
mkdir TP_MAKEFILE4
```
```
git clone https://github.com/SitrakaResearchAndPOC/FullRPC_LXD 
```
```
mv FullRPC_LXD/*.c TP_MAKEFILE4
```
```
mv FullRPC_LXD/*.h TP_MAKEFILE4
```
```
rm -rf FullRPC_LXD
```
```
cd TP_MAKEFILE4
```
```
nano Makefile
```
Copier et Enregistrer
```
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
all: exec

%.o: %.c tri.h
        $(CC) -c $< -o $@

exec: $(OBJ)
        $(CC) $^ -o $@

clean:
        rm -rf *.o
        rm -rf exec
```
```
make all
```
```
chmod +x exec
```
```
./exec 
```
```
make clean
```
```
cd ..
```
```
exit
```
# exercice 5.5 : à faire
* [Makefile](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
* [Makefile_pdf](https://github.com/SitrakaResearchAndPOC/FullRPC_LXD/blob/main/A%20Simple%20Makefile%20Tutorial.pdf)
# SAUVEGARDE FICHIER SYSTEM : 
```
lxc publish FullRPC --alias FullRPCimage -f
```
```
lxc image export FullRPCimage .
```
```
md5sum 7f896585044a87054e5da9aaa1a7b88d65618cbc47148741e90dedaca32c07f8.tar.gz
```
1ba687bee1cfb27bfe3fae0df9e6f03b
```
chmod 777 7f896585044a87054e5da9aaa1a7b88d65618cbc47148741e90dedaca32c07f8.tar.gz
```

# Quick Install
## Installation with LXC  using ubuntu if not yet installed
```
apt update
```
```
apt-get install lxd lxd-client
```


## Installation with LXC  using DragonOS if not yet installed
```
apt update
```
```
apt-get install snapd  
```
```
snap install lxd  
```

```
snap install lxd-client  
```

## Initialisation of LXD if not yet installed
```
lxd init  
```
For questions please follow the default option, an image illustration is at [image](https://github.com/SitrakaResearchAndPOC/QCSuper/blob/main/screen.jpg) 
  
User need to be in group lxd :
```
sudo usermod -a G lxd $USER  
```
or  
```
sudo /usr/sbin/usermod lxd $USER  
```

$PATH need to contains /usr/local/bin, verify with :  
```
echo $PATH  
```

if not, setup this, or add this in your .bashrc or .zshrc or ...  

```
export PATH=$PATH:/usr/local/bin  
```
# IMPORTING IMAGES FOR QUICK INSTALL
## downloading and importing image for Quick install
```
wget --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=1Dg7DjZhS9Ed_KjPV2cioQkbvsmOvLhiR' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=1Dg7DjZhS9Ed_KjPV2cioQkbvsmOvLhiR" -O 7f896585044a87054e5da9aaa1a7b88d65618cbc47148741e90dedaca32c07f8.tar.gz   && rm -rf /tmp/cookies.txt  
```
```
lxc image import 7f896585044a87054e5da9aaa1a7b88d65618cbc47148741e90dedaca32c07f8.tar.gz --alias FullRPCimage
```
```
lxc launch FullRPCimage FullRPC
```

# ADDING PROFILE GUI AND INSTALLING FOR MOUSEPAD
# Installing firefox for testing gui
Exit the container FullRPC
```
nano .gui.txt
```
Copy this config of.gui.txt
```
config:
  environment.DISPLAY: :0
  raw.idmap: both 1000 1000
description: GUI LXD profile
devices:
  X0:
    path: /tmp/.X11-unix/X0
    source: /tmp/.X11-unix/X0
    type: disk
  my_gpu:
    type: gpu
name: gui
```
SAVE THE FILE as .gui.txt </br>
Create the profile
```
lxc profile create gui
```
```
lxc profile edit gui < .gui.txt
```
```
rm .gui.txt
```
```
lxc profile add  FullRPC gui
```
```
lxc config set  FullRPC security.privileged=true
```
```
lxc start  FullRPC
```
Testing GUI mousepad
```
xhost +
```
```
lxc exec FullRPC -- mousepad
```
## Problem of display for Quick install
Problem display at [display](https://bbs.archlinux.org/viewtopic.php?id=221449) or [pdf_display](https://github.com/SitrakaResearchAndPOC/HackrfJAM_LXD/blob/main/How%20to%20resolve%20%E2%80%9CNo%20protocol%20specified%20Unable%20to%20init%20server__%20%5BSolved%5D%20_%20Newbie%20Corner%20_%20Arch%20Linux%20Forums.pdf) </br>

* reboot the real machine :
```
rm -rf /tmp/.X11-unix/X*
```
```
reboot
```
* please reboot the container images : 
```
lxc stop  FullRPC
```
```
lxc start  FullRPC
```
* listing the profile
```
lxc profile list
```
* adding the profile
```
lxc profile add  FullRPC gui
```
* Please verify if there are two x0 and choose following ;
You could verify using
```
lsof -U | grep X1
```

```
chmod +x /tmp/.X11-unix/X0
```
or xhost +local:
```
xhost +
```
non-network local connections being added to access control list
```
pgrep -a X
```
```
echo $DISPLAY
```
```
echo $TERM
```
* IF PROBLEM PERSIST
```
lxc profile edit gui
```
Change the number of dispaly as on the command echo $DISPLAY
```
config:
  environment.DISPLAY: :1
  raw.idmap: both 1000 1000
description: GUI LXD profile
devices:
  X1:
    path: /tmp/.X11-unix/X1
    source: /tmp/.X11-unix/X1
    type: disk
  my_gpu:
    type: gpu
name: gui
```
* remak all step on the PROBLEM OF DISPLAY
* if problem still persists ; change by other number and look at : </br> [link1](https://bbs.archlinux.org/viewtopic.php?id=221449) </br>[link2](https://bbs.archlinux.org/viewtopic.php?id=272491)  </br> [link3](https://bbs.archlinux.org/viewtopic.php?id=270585) </br> [link4](https://bbs.archlinux.org/viewtopic.php?id=281572) </br> [link5](https://bbs.archlinux.org/viewtopic.php?id=288581) </br>
```
lxc exec Full RPC -- mousepad
```



# Remarques 
LES CODES DE C ET RPC SERONT DANS GITHUB : </br>
•	https://github.com/ImsicatcherBastienbaranoff/RPC
•	https://github.com/ImsicatcherBastienbaranoff/TPC

POUR PLUS DE PRATIQUE ET COURS: VEUILLEZ FAIRE LA LECTURE DES DEUX CHAINES YOUTUBE: </br>
•	https://www.youtube.com/playlist?list=PLF7E20B552F65C51C
•	https://www.youtube.com/playlist?list=PLOholRFa862SX9Ypgk3vsByrfMT_hMq-l
