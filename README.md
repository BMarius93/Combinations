Combinations
============

Enunt pe scurt:

Aflați numărul de matrice binare cu N linii și M coloane care respectă proprietatea
că pe orice coloană se află cel mult K valori de 1 consecutive.


Fișierul de intrare pentru această problemă va conține pe prima și singura linie
valorile N, M și K separate prin spațiu. 

Fișierul de ieșire conține pe prima linie numărul (modulo 40009) de cadre cu N
linii, M coloane și care au cel mult K valori de 1 consecutive pe orice coloană.




Implementare:


Pentru rezolvarea acestei probleme am pornit de la urmatoarea matrice de 
recurenta de dimensiuni (k+1) x (k+1):

	0 0 0 0 0.......1
	1 0 0 0 0.......1
	0 1 0 0 0.......1
	0 0 1 0 0.......1
	0 0 0 1 0.......1
	0 0 0 0 1.......1
	.................
	0 0 0 0 0.....1 1

	Aceasta matrice am ridicat-o la puterea n+1, obtinand astfel in coltul din 
dreapta-jos numarul de posibilitati in care se pot afla maxim k valori de 1
consecutive pe o singura coloana. Pentru a afla numarul de posibilitati in care se
pot afla maxim k valori de 1 consecutive pe o matrice de m coloane, am ridicat 
elementul din coltul matricei rezultate la puterea m, si am aflat rezultatul final.
	Pe parcursul acestor calcule, am avut in vedere ca rezultatul final trebuie sa
fie %40009.
