//Considere o seguinte tipo para representar listas ligadas de inteiros

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

/*1. Apresente uma definicao nao recursiva da funcao int length (LInt) que calcula o comprimento
	 de uma lista ligada.
	 (https://codeboard.io/projects/16161)
*/

int length2 (LInt l){
	int i = 0;
	if (l == NULL)
		return i;
	for (i = 0; l != NULL; i++)
		l = l -> prox;
	return i;
}

/*2. Apresente uma definicao nao recursiva da funcao void freeL (LInt) que liberta o espaco
	 ocupado por uma lista.
*/

void freeL2 (LInt l){
	LInt aux;
	while (l != NULL){
		aux = l -> prox;
		free(l);
		l = aux;
	}
}

/*3. Apresente uma definicao nao recursiva da funcao void imprimeL (LInt) que imprime no
	 ecran os elementos de uma lista (um por linha).
*/

void imprimeL2 (LInt l){
	while (l != NULL){
		printf("%d\n", l -> valor);
		l = l -> prox;
	}
}

/*4. Apresente uma definicao nao recursiva da funcao LInt reverseL (LInt) que inverte uma lista 
	 (sem criar uma nova lista).
	 (https://codeboard.io/projects/16243)
*/

LInt reverseL2 (LInt l){
	LInt pro, aux = NULL;
	while(l){
		pro = l -> prox;
		l -> prox = aux;
		aux = l;
		l = pro;
	}
	return aux;
}

/*5. Apresente uma definicao nao recursiva da funcao void insertOrd (LInt *, int)
	 que insere ordenadamente um elemento numa lista ordenada.
	 (https://codeboard.io/projects/16244)
*/

void insertOrd2 (LInt *l, int x){
	LInt aux;
	while (*l && (x > (*l)->valor)){
		l = &((*l)->prox);
	}
	aux = (LInt) malloc (sizeof(struct lligada));
	aux->valor = x;
	aux->prox = *l;
	*l = aux;
}

/*6. Apresente uma definicao nao recursiva da funcao int removeOneOrd (LInt *, int)
	 que remove um elemento de uma lista ordenada.
	 Retorna 1 caso o elemento a remover nao exista, 0 no outro caso.
	 (https://codeboard.io/projects/16245)
*/

int removeOneOrd2 (LInt *l, int x){
	LInt aux;
	while (*l && (x != (*l)->valor))
		l = &((*l)->prox);
	if (*l){
		aux = (*l)->prox;
		free(*l);
		*l = aux;
		return 0;
	}
	return 1;
}

/*7. Defina uma funcao merge (LInt *r, LInt a, LInt b) que junta duas listas ordenadas (a e b)
	 numa unica lista ordenada (r).
	 (https://codeboard.io/projects/16246)
*/

void merge2 (LInt *r, LInt a, LInt b){
	while(a || b){
		if((!a) || (b && a->valor > b->valor)){
    		*r = b;
        	r = &(b->prox);
        	b = b->prox;
		}
		else{
        	*r = b;
        	r = &(a->prox);
        	a = a->prox;
    	}
    }
}

/*8. Defina uma funcao void splitQS (LInt l, int x, LInt *mx, LInt *Mx) que, dada uma lista ligada l e um inteiro x,
	 parte a lista em duas (retornando os enderecos dos primeiros elementos da lista em *mx e *Mx):
	 uma com os elementos de l menores do que x e a outra com os restantes.
	 Note que esta funcao nao devera criar copias dos elementos da lista.
	 (https://codeboard.io/projects/16247)
*/

void splitQS2 (LInt l, int x, LInt *mx, LInt *Mx){
	while (l){
		if (l -> valor < x){
			*mx = l;
			mx = &((*mx) -> prox);
		}
		else {
			*Mx = l;
			Mx = &((*Mx) -> prox);
		}
		l = l -> prox;
	}
	*Mx = NULL;
	*mx = NULL;
}

/*9. Defina uma funcao LLig parteAmeio (LLig *l) que parte uma lista nao vazia *l a meio.
	 Se x contiver os elementos {1,2,3,4,5}, apos a invocacao y=parteAmeio(&x)
	 a lista y devera conter os elementos {1,2} e a lista x os restantes {3,4,5}.
	 (https://codeboard.io/projects/17392)
*/

LInt parteAmeio2 (LInt *l){
    int i = length(*l)/2, j;
    LInt *p = l, u = *l;
    for(j = 0; j < i; ++j)
        p = &((*p)->prox);
    *l = *p;
    *p = NULL;
    if (i == 0) {
    	*l = u;
    	return NULL;
    }
    else
    	return u;
}

/*10. Apresente uma definicao nao recursiva da funcao int removeAll (LInt *, int)
	  que remove todas as ocorrencias de um dado inteiro de uma lista, retornando o numero de celulas removidas.
	  (https://codeboard.io/projects/16249)
*/

int removeAll2 (LInt *l, int i){
	int x = 0;
	LInt aux;
	while (*l){
		if ((*l) -> valor == i){
			aux = (*l) -> prox;
			free(*l);
			*l = aux;
			x++;
		}
		else
			l = &((*l) -> prox);
	}
	return x;
}

/*11. Apresente uma definicao da funcao int removeDups (LInt *) 
	  que remove os valores repetidos de uma lista (deixando apenas a primeira ocorrencia).
	  (https://codeboard.io/projects/16250).
*/

int removeElem (LInt *l, int x){
	int i = 0;
	LInt aux;
	while (*l){
		if ((*l) -> valor == x){
			aux = (*l) -> prox;
			free(*l);
			*l = aux;
			++i;
		}
		else
			l = &((*l) -> prox);
	}
	return i;
}

int removeDups2 (LInt *l){
	int i = 0;
	while (*l){
		i =+ removeElem (&((*l) -> prox), (*l) -> valor);
		l = &((*l) -> prox); 
	}
	return i;
}

/*12. Apresente uma definicao da funcao int removeMaiorL (LInt *) que remove (a primeira ocorrencia)
	  o maior elemento de uma lista nao vazia, retornando o valor desse elemento.
	  (https://codeboard.io/projects/16251)
*/

int removeMaiorL2 (LInt *l){
	int i = 0;
	LInt *aux = l, lis;
	while (*aux){
		if (((*aux) -> valor) > i)
			i = (*aux) -> valor;
		aux = &((*aux) -> prox);
	}
	while (*l){
		if (((*l) -> valor) == i){
			lis = (*l) -> prox;
			free(*l);
			*l = lis;
			break;
		}
		l = &((*l) -> prox);
	}
	return i;
}

/*13. Apresente uma definicao nao recursiva da funcao void init (LInt *) que remove o ultimo elemento
	  de uma lista nao vazia (libertando o correspondente espaco).
	  (https://codeboard.io/projects/16252)
*/

void init2 (LInt *l){
	while ((*l) -> prox)
		l = &((*l) -> prox);
	free(*l);
	*l = NULL;
}

/*14. Apresente uma definicao nao recursiva da funcao void appendL (LInt *, int)
	  que acrescenta um elemento no fim da lista.
	  (https://codeboard.io/projects/16253)
*/

void appendL2 (LInt *l, int x){
	while (*l)
		l = &((*l) -> prox);
	*l = (LInt) malloc (sizeof(struct lligada));
	(*l) -> valor = x;
	(*l) -> prox = NULL;
}

/*15. Apresente uma definicao da funcao void concatL (LInt *a, LInt b)
	  que acrescenta a lista b a lista *a.
	  (https://codeboard.io/projects/16254)
*/

void concatL2 (LInt *a, Lint b){
	while (*a)
		a = &((*a) -> prox;)
	*a = (LInt) malloc (sizeof(struct lligada));
	(*a) -> valor = b -> valor;
	(*a) -> prox = b -> valor;
}

/*16. Apresente uma definicao da funcao LInt cloneL (LInt) que cria uma nova lista ligada
	  com os elementos pela ordem em que aparecem na lista argumento.
*/

LInt cloneL2 (LInt l){
	LInt copy;
	copy = (LInt) malloc (sizeof(struct lligada));
	while (l){
		copy -> valor = l -> valor;
		LInt aux = (LInt) malloc (sizeof(struct lligada));
		copy -> prox = aux;
		copy = &(copy -> prox);
		l = l -> prox;
	}
	copy = NULL;
	return copy;
}

/*17. Apresente uma definicao nao recursiva da funcao LInt cloneRev (LInt)
	  que cria uma nova lista ligada com os elementos por ordem inversa.
	  Por exemplo, se a lista l tiver 5 elementos com os valores {1,2,3,4,5} por esta ordem,
	  a invocacao cloneRev(l) deve corresponder a uma nova lista com os elementos {5,4,3,2,1} por esta ordem.
	  (https://codeboard.io/projects/16256)
*/

LInt cloneRev2 (LInt l){
	LInt aux, rev;
	rev = aux = NULL;
	while (l){
		rev = (LInt) malloc (sizeof(struct lligada));
		rev -> valor = l -> valor;
		rev -> prox = aux;
		aux = rev;
		l = l -> prox;
	}
	return rev;
}

/*18. Defina uma funcao int maximo (LInt l) que calcula qual
	  o maior valor armazenado numa lista nao vazia.
	  (https://codeboard.io/projects/16257)
*/

int maximo2 (LInt l){
	int aux = 0;
	while (l){
		if (l -> valor > aux)
			aux = l -> valor;
		l = l -> valor;
	}
	return aux;
}

/*19. Apresente uma definicao iterativa da funcao int take (int n, LInt *l) que,
	  dado um inteiro n e uma lista ligada de inteiros l, apaga de l todos os nodos
	  para alem do n-esimo (libertando o respectivo espaco).
	  Se a lista tiver n ou menos nodos, a funcao nao altera a lista.
	  A funcao deve retornar o comprimento final da lista.
	  (https://codeboard.io/projects/16258)
*/

int comprimento2(LInt *l){
	int i = 0;
	while (*l){
		l = &((*l) -> prox);
		i++;
	}
	return i;
}

int take2 (int n, LInt *l){
	int aux = n;
	LInt acum, *init =l;
	while ((*l) && (aux != 0)){
		l = &((*l) -> prox);
		aux--;
	}
	while (*l){
		acum = (*l) -> prox;
		free (*l);
		*l = acum;
	}
	aux = comprimento(init);
	return aux;
}

/*20. Apresente uma definicao iterativa da funcao int drop (int n, LInt *l) que,
	  dado um inteiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista
	  (libertando o respectivo espaco).
	  Se a lista tiver n ou menos nodos, a funcao liberta a totalidade da lista.
	  A funcao deve retornar o numero de elementos removidos.
	  (https://codeboard.io/projects/16259)
*/

int drop2 (int n, LInt *l){
	int i;
	LInt aux;
	for (i = 0; (*l) && (i < n); i++){
		aux = (*l) -> prox;
		free(*l);
		*l = aux;
	}
	return i;
}

/*21. O tipo LInt pode ser usado ainda para implementar listas circulares.
	  Defina uma funcao LInt Nforward (LInt l, int N) que, dada uma lista circular, 
	  da como resultado o endereco do elemento da lista que esta N posicoes a frente.
	  (https://codeboard.io/projects/16260)
*/

LInt Nforward2 (LInt l, int N){
	int i;
	for (i = 0; i < N; i++)
		l = l -> prox;
	return l;
}

/*22. Defina uma funcao int listToArray (LInt l, int v[], int N) que,
	  dada uma lista l, preenche o array v com os elementos da lista.
	  A funcao devera preencher no maximo N elementos e retornar o numero de elementos preenchidos.
	  (https://codeboard.io/projects/16261)
*/

int listToArray2 (LInt l, int v[], int N){
	int i;
	for (i = 0; l && (i < N); i++){
		v[i] = l -> valor;
		l = l -> prox;
	}
	return i;
}

/*23. Defina uma funcao LInt arrayToList (int v[], int N) que constroi uma lista
	  com os elementos de um array, pela mesma ordem em que aparecem no array.
	  (https://codeboard.io/projects/16262)
*/

LInt arrayToList2 (int v[], int N){
	int i;
	LInt aux, *ns = &aux;
	for (i = 0; i < N; i++){
		*ns = (LInt) malloc (sizeof(struct lligada));
		(*ns) -> valor = v[i];
		ns = &((*ns) -> prox);
	}
	*ns = NULL;
	return aux;
}

/*24. Defina uma funcao LInt somasAcL (LInt l) que, dada uma lista de inteiros,
	  constroi uma nova lista de inteiros contendo as somas acumuladas da lista original
	  (que devera permanecer inalterada).
	  Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista contruida pela invocacao de somasAcL (l)
	  devera conter os valores [1,3,6,10].
	  (https://codeboard.io/projects/16263)
*/

LInt somasAcL2 (LInt l){
	LInt aux, ant, *fin = &aux; 
	if (l == NULL)
		return l;
	else {
		*fin = malloc(sizeof(struct lligada));
		(*fin) -> valor = l -> valor;
		ant = (*fin);
		fin = &((*fin) -> prox);
		l = l -> prox;
		while (l){
			*fin = malloc(sizeof(struct lligada));
			(*fin) -> valor = (l -> valor) + (ant -> valor);
			ant = (*fin);
			fin = &((*fin) -> prox);
			l = l -> prox;
		}
		*fin = NULL;
	}
	return aux;
}

/*25. Defina uma funcao void remreps (LInt l) que, dada uma lista ordenada de inteiros,
	  elimina dessa lista todos os valores repetidos assegurando que o espaco de memoria correspondente
	  aos nos removidos e correctamente libertado.
	  (https://codeboard.io/projects/16264)
*/

void remreps2 (LInt l){
	LInt aux1, aux2;
	while (l){
		aux1 = l -> prox;
		while (aux1 && ((aux1 -> valor) == (l -> valor))){
			aux2 = aux1 -> prox;
			free(aux1);
			aux1 = aux2;
		}
		l -> prox = aux1;
		l = l -> prox;
	}
}

/*26. Defina uma funcao LInt rotateL (LInt l) que coloca o primeiro elemento de uma lista no fim.
	  Se a lista for vazia ou tiver apenas um elemento, a funcao nao tem qualquer efeito pratico
	  (i.e., devolve a mesma lista que recebe como argumento).
	  Note que a sua funcao nao deve alocar nem libertar memoria. Apenas re-organizar as celulas da lista.
	  (https://codeboard.io/projects/16265)
*/

LInt rotateL2 (LInt l){
	LInt *aux1 = &l, aux2 = NULL;
	while (*aux1)
		aux1 = &((*aux1) -> prox);
	*aux1 = l;
	if(l){
		aux2 = l -> prox;
		l -> prox = NULL;
	}
	return aux2;
}

/*27. Defina uma funcao LInt parte (LInt l) que parte uma lista l em duas: na lista l ficam
	  apenas os elementos das posicoes impares; na lista resultante ficam os restantes elementos.
	  Assim, se a lista x tiver os elementos {1,2,3,4,5,6} a chamada y = parte (x) 
	  coloca na lista y os elementos {2,4,6} ficando em x apenas os elementos {1,3,5}.
	  (https://codeboard.io/projects/16266)
*/

LInt parte2 (LInt l){
    if(!l)
        return NULL;
    LInt aux = l, par = l->prox, fin= l->prox;
    while(aux && par){
        aux->prox = par->prox;
        aux = aux->prox;
        if(aux) {
            par->prox = aux->prox;
            par = par->prox;
        }
    }
    return fin;
}

typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
} *ABin;

/*28. Apresente uma definicao da funcao int altura (ABin)
	  que calcula a altura de uma arvore binaria.
	  (https://codeboard.io/projects/16220)
*/

int altura2 (ABin a){
	int dir, esq, ret = 0;
	if (a){
		dir = altura(a -> dir);
		esq = altura(a -> esq);
		if (dir > esq)
			ret = dir + 1;
		else 
			ret = esq + 1;
	}
	return ret;
}

/*29. Defina uma funcao ABin cloneAB (ABin) que cria uma copia de uma arvore.
	  (https://codeboard.io/projects/16267)
*/

ABin cloneAB2 (ABin a){
	ABin aux = NULL;
	if (a){
		aux = (ABin)malloc(sizeof(struct nodo));
		aux -> valor = a -> valor;
		aux -> dir = cloneAB2(a -> dir);
		aux -> esq = cloneAB2(a -> esq);
	}
	return aux;
}

/*30. Defina uma funcao void mirror (ABin *) que inverte uma arvore
	  (sem criar uma nova arvore).
	  (https://codeboard.io/projects/16268)
*/

void mirror (ABin *a){
	ABin aux;
	if(*a){
		aux = (*a) -> esq;
		(*a) -> esq = (*a) -> dir;
		(*a) -> dir = aux;
		mirror(&((*a) -> esq));
		mirror(&((*a) -> dir));
	}
}

/*31. Defina a funcao void inorder (ABin , LInt *) que cria uma lista ligada de inteiros
	  a partir de uma travessia inorder de uma arvore binaria.
	  (https://codeboard.io/projects/16269)
*/

LInt cabeca (LInt l, int x){
	LInt aux = (LInt) malloc (sizeof(struct lligada));
	if (aux != NULL){
		aux -> valor = x;
		aux -> prox = l;
	}
	return aux;	
}

void inorder2 (ABin a, LInt *l){
	if (a){
		inorder2(a -> dir, l);
		(*l) = cabeca(*l, a -> valor);
		inorder2(a -> esq, l);
	}
}

/*32. Defina a funcao void preorder (ABin , LInt *) que cria uma lista ligada de inteiros
	  a partir de uma travessia preorder de uma arvore binaria.
	  (https://codeboard.io/projects/16270)
*/

void preorder2(ABin a, LInt *l){
	if (a){
		preorder2(a -> dir, l);
		preorder2(a -> esq, l);
		(*l) = cabeca(*l, a -> valor);
	}
}

/*33. Defina a funcao void posorder (ABin , LInt *) que cria uma lista ligada de inteiros
	  a partir de uma travessia posorder de uma arvore binaria.
	  (https://codeboard.io/projects/16272)
*/

void posorder2(ABin a, LInt *l){
	if (a){
		(*l) -> cabeca(*l, a -> valor);
		posorder2(a -> dir, l);
		posorder2(a -> esq, l);
	}
}


/*34. Apresente uma definicao da funcao int depth (ABin a, int x) que calcula o nivel (menor)
	  a que um elemento esta numa arvore binaria (-1 caso nao exista).
	  (https://codeboard.io/projects/16273)
*/

int depth2 (ABin a, int x){
	if(!a)
		return -1;
	if(a -> valor == x)
		return 1;
	int auxesq = depth2(a -> esq, x), auxdir = depth2(a -> dir, x);
	if(auxesq == -1 && auxdir == -1)
		return -1;
	if(auxdir == -1)
		return 1 + auxesq;
	if(auxesq == -1)
		return 1 + auxdir;
	if(auxesq > auxdir)
		return 1 + auxdir;
	if(auxesq <= auxdir)
		return 1 + auxesq;
}

/*35. Defina uma funcao int freeAB (ABin a) que liberta o espaco ocupado por uma arvore binaria,
	  retornando o numero de nodos libertados.
	  (https://codeboard.io/projects/16274)
*/

int freeAB (ABin a){
	int i = 0;
	if (a != NULL){
		i += 1 + freeAB(a -> esq) + freeAB(a -> dir);
		free(a);
	}
	return i;
}

/*36. Defina uma funcao int pruneAB (ABin *a, int l) que remove (libertando o espaco respectivo)
	  todos os elementos da arvore *a que estao a uma profundidade superior a l,
	  retornando o numero de elementos removidos.
	  Assuma que a profundidade da raiz da arvore e 1, e por isso a invocacao pruneAB(&a,0)
	  corresponde a remover todos os elementos da arvore a.
	  (https://codeboard.io/projects/16275)
*/

int pruneAB (ABin *a, int l){
	
}