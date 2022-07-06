#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*1 - Defina um programa que le (usando a funcao scanf) uma sequencia de numeros inteiros 
      terminada com o numero 0 e imprime no ecran o maior elemento da sequencia.
*/

void maiorElen (){
	int maior;
	scanf("%d", &maior);
	int n = 1;
	int ninserido;
	while (n != 0){
		scanf("%d", &ninserido);
		if (ninserido >= maior) (maior = ninserido);
		n = ninserido;
	}
	printf("%d\n", maior);
}

/*2 - Defina um programa que le (usando a funcao scanf) uma sequencia de numeros inteiros
      terminada com o numero 0 e imprime no ecran a media da sequencia.
*/

void media (){
	int t = 0;
	int n = 0;
	int i = 1;
	while (i != 0){
		scanf("%d", &i);
		t += i;
		n++;
	}
	printf("%d\n", (t/n));
}

/*3 - Defina um programa que le (usando a funcao scanf) uma sequencia de numeros inteiros
      terminada com o numero 0 e imprime no ecran o segundo maior elemento.
*/

void segundoMaior (){
	int maior;
	scanf("%d", &maior);
	int segundo = 0;
	int n = 1;
	while (n != 0){
		scanf("%d", &n);
		if(n > maior){
			segundo = maior;
			maior = n;
		}
		else if(n > segundo) 
			segundo = n;
	}
	printf("%d\n", segundo);
}

/*4 - Defina uma funcao int bitsUm (unsigned int n) que calcula o numero de bits iguais a 1
	  usados na representacao binaria de um dado numero n. 
	  (https://codeboard.io/projects/13548)
*/

int bitsUm1 (unsigned int n){
	int i = 0;
	while (n != 0){
		if(n%2 == 1) i++;
		n = n/2;
	}
	return i;
}

/*5 - Defina uma funcao int trailingZ (unsigned int n) que calcula o numero de bits a 0
	  no final da representacao binaria de um numero (i.e., o expoente da maior potencia de 2
	  que e divisor desse numero).
	  (https://codeboard.io/projects/13549)
*/

int trailingZ1 (unsigned int n){
	int i = 0;
	int z = 0;
	while (z == 0){
		if (n == 0) 
			z = 1;
		if (n%2 == 0){
			i++;
			n = n/2;
		}
		else z = 1;
	}
	return i;
}

/*6 - Defina uma funcao int qDig (unsigned int n) que calcula o numero de digitos necessarios
	  para escrever o inteiro n em base decimal.
	  Por exemplo, qDig (440) deve retornar 3.
	  (https://codeboard.io/projects/13583)
*/

int qDig1 (unsigned int n){
	int i = 0;
	while (n != 0){
		n = n/10;
		i++;
	}
	return i;
}

/*7 - Apresente uma definicao da funcao pre-definida em C char *strcat (char s1[], char s2[]) 
	  que concatena a string s2 a s1 (retornando o endereco da primeira).
	  (https://codeboard.io/projects/14490)
*/

char *strcat1 (char s1[], char s2[]){
	int i = 0;
	while (s1[i] != '\0')
		i++;
	int n;
	for (n = 0; s2[n] != '\0'; n++){
		s1[i] = s2[n];
		i++;
	}
	s1[i] = '\0';
	return s1;
}

/*8 - Apresente uma definicao da funcao pre-definida em C char *strcpy (char *dest, char source[]) 
	  que copia a string source para dest retornando o valor desta ultima.
	  (https://codeboard.io/projects/14491)
*/

char *strcpy1 (char *dest, char source[]){
	int i;
	for (i = 0; source[i] != '\0'; i++){
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return dest;
}

/*9 - Apresente uma definicao da funcao pre-definida em C int strcmp (char s1[], char s2[]) 
	  que compara (lexicograficamente) duas strings. O resultado devera ser:
		0 se as strings forem iguais
		<0 se s1 < s2
		>0 se s1 > s2
	  (https://codeboard.io/projects/14492)
*/

int strcmp1 (char s1[], char s2[]){
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*10 - Apresente uma definicao da funcao pre-definida em C char *strstr (char s1[], char s2[])
	   que determina a posicao onde a string s2 ocorre em s1. 
	   A funcao devera retornar NULL caso s2 nao ocorra em s1.
	   (https://codeboard.io/projects/14493)
*/

char *strstr1 (char s1[], char s2[]){
	int i, j;
	j = 0;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++){
		if (s1[i] == s2[i])
			j++;
		else {
			i = -1;
			s1++;
		}	
	}
	if (s2[i] == '\0')
		return s1;
	return NULL;
}

/*11 - Defina uma funcao void strrev (char s[]) que inverte uma string.
	   (https://codeboard.io/projects/14494)
*/

void strrev1 (char s[]){
	int i, j, k;
	k = 0;
	for (i = 0; s[i] != '\0'; i++);
	char n[i + 1];
	for (j = i - 1; j >= 0; j--){
		n[j] = s[k];
		k++;
	}
	n[i] = '\0';
	for (i = 0; n[i] != '\0'; i++)
		s[i] = n[i];
	n[i] = '\0';
}

/*12 - Defina uma funcao void strnoV (char s[]) que retira todas as vogais de uma string.
	   (https://codeboard.io/projects/13661)
*/

int vogal1 (char s){
	if (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U')
		return 1;
	return 0;
}

void apaga (char s[]){
	int i;
	for (i = 0; s[i] != '\0'; i++)
		s[i] = s[i+1];
}

void strnoV (char s[]){
	int i = 0;
	while (s[i] != '\0'){
		if (vogal1 (s[i])) {
			(apaga (&(s[i])));
			i-=1;
		}
		i++;
	}
}

/*13 - Defina uma funcao void truncW (char t[], int n) que dado um texto t com varias palavras
	   (as palavras estao separadas em t por um ou mais espacos) e um inteiro n,
	   trunca todas as palavras de forma a terem no maximo n caracteres.
	   Por exemplo, se a string txt contiver "liberdade, igualdade e fraternidade",
	   a invocacao de truncW (txt, 4) deve fazer com que passe a estar la armazenada a string "libe igua e frat".
	   (https://codeboard.io/projects/13659)
*/

void truncW1 (char t[], int n){
	int i,j;
	j = 0;
	for (i = 0; t[i] != '\0'; i++){
		if (t[i] == ' ')
			j = 0;
		else {
			if (j == n){
				(apaga (&(t[i])));
				i -= 1;
			}
			if (j < n)
				j++;
		}
	}
}

/*14 - Defina uma funcao char charMaisfreq (char s[]) que determina qual o caracter mais frequente numa string.
	   A funcao devera retornar 0 no caso de s ser a string vazia.
	   (https://codeboard.io/projects/14577)
*/

int contaChar (char s[], char n){
	int i,j;
	j = 0;
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] == n)
			j++;
	}
	return j;
}

char charMaisfreq1 (char s[]){
	int i,j;
	i = j = 0;
	char a = s[i];
	while (s[i] != '\0'){
		if ((contaChar(s, s[i])) > j){
			a = s[i];
			j = (contaChar(s, s[i]));
		}
		i++;
	}
	return a;
}

/*15 - Defina uma funcao int iguaisConsecutivos (char s[]) que, dada uma string s 
	   calcula o comprimento da maior sub-string com caracteres iguais.
	   Por exemplo, iguaisConsecutivos ("aabcccaac") deve dar como resultado 3, correspondendo a repeticao "ccc".
	   (https://codeboard.io/projects/14578)
*/

int contaSeguidos (char s[], char n){
	int i, j;
	i = j = 0;
	while ((s[i] != '\0') && (s[i] == n)){
		j++;
		i++;
	}
	return j;
}

int iguaisConsecutivos1 (char s[]){
	int i, j;
	i = j = 0;
	while (s[i] != '\0'){
		if ((contaSeguidos (&(s[i]), s[i])) > j){
			j = (contaSeguidos (&(s[i]), s[i]));
		}
		i++;
	}
	return j;
}

/*16 - Defina uma funcao int difConsecutivos (char s[]) que, dada uma string s 
	   calcula o comprimento da maior sub-string com caracteres diferentes.
	   Por exemplo, difConsecutivos ("aabcccaac") deve dar como resultado 3, 
	   correspondendo a string "abc". 
	   (https://codeboard.io/projects/14579)
*/

int estaRep (char s[], int i){
	int j = i-1;
	while (j >= 0 && s[i] != s[j] && s[i] != '\0' && s[j] != '\0')
		j--;
	return (j >= 0);
}

int maiorPrefSR (char s[]){
	int i = 0;
	while (s[i] != '\0' && !estaRep(s,i))
		i++;
	return i;
}

int difConsecutivos1 (char s[]){
	int i, r, t;
	i = r = 0;
	while(s[i] != '\0'){
		t = maiorPrefSR (s+i);
		if (t > r) 
			r = t;
		i++;
	}
	return r;
}

/*17 - Defina uma funcao int maiorPrefixo (char s1 [], char s2 [])
	   que calcula o comprimento do maior prefixo comum entre as duas strings.
	   (https://codeboard.io/projects/14580)
*/

int maiorPrefixo1 (char s1[], char s2[]){
	int i;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
	return i;
}

/*18 - Defina uma funcao int maiorSufixo (char s1 [], char s2 [])
	   que calcula o comprimento do maior sufixo comum entre as duas strings. 
	   (https://codeboard.io/projects/14581)
*/

int maiorSufixo1 (char s1[], char s2[]){
	int i,j;
	for (i = 0; s1[i] != '\0'; i++);
	for (j = 0; s2[j] != '\0'; j++);
	i--;
	j--;
	int r;
	for (r = 0; s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j]; i-- && j--)
		r++;
	return r;
}

/*19 - Defina a funcao int sufPref (char s1[], char s2[]) 
	   que calcula o tamanho do maior sufixo de s1 que e um prefixo de s2.
	   Por exemplo sufPref("batota","totalidade") deve dar como resultado 4, 
	   uma vez que a string "tota" e um sufixo de "batota" e um prefixo de "totalidade".
	   (https://codeboard.io/projects/14582)
*/

int similar (char s1[], char s2[]){
	int i, j, l;
	for (l = 0; s1[l] != '\0'; l++);
	j = 0;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		j++;
	if (j == l)
		return j;
	return 0;
}

int sufPref1 (char s1[], char s2[]){
	int i, j, r;
	r = 0;
	for (i = 0; s1[i] != '\0'; i++){
		j = similar((&(s1[i])),s2);
		if (j > r)
			r = j; 
	}
	return r;
}

/*20 - Defina uma funcao int contaPal (char s[]) que conta as palavras de uma string.
	   Uma palavra e uma sequencia de caracteres (diferentes de espaco) terminada por um ou mais espacos.
	   Assim, se a string p tiver o valor "a a bb a", o resultado de contaPal (p) deve ser 4.
	   (https://codeboard.io/projects/14583)
*/

int contaPal1 (char s[]){
	int i, j;
	j = 0;
	for (i = 0; s[i] != '\0'; i++){
		if ( (s[i] != ' ') && (s[i] != '\n') && ( (s[i+1] == ' ') || (s[i+1] == '\0') || (s[i+1] == '\n') ) )
			j++;
		}
	return j;
}

/*21 - Defina uma funcao int contaVogais (char s[]) que retorna o numero de vogais da string s. 
	   Nao se esqueca de considerar tanto maiusculas como minusculas. 
	   (https://codeboard.io/projects/14585)
*/

int eVogal (char s){
	if (s == 'a' || s == 'A' || s == 'e' || s == 'E' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s == 'U')
		return 1;
	return 0;
}
int contaVogais1 (char s[]){
	int i, j;
	i = j = 0;
	while (s[i] != '\0'){
		if (eVogal(s[i])) 
			j++;
		i++;
	}
	return j;
}

/*22 - Defina uma funcao int contida (char a[], char b[]) 
	   que testa se todos os caracteres da primeira string tambem aparecem na segunda.
	   Por exemplo, contida "braga" "bracara augusta" deve retornar verdadeiro 
	   enquanto que contida "braga" "bracarense" deve retornar falso.
	   (https://codeboard.io/projects/14586)
*/

int pertece (char a, char b[]){
	int i, j;
	for (i = 0; b[i] != '\0'; i++){
		if (a == b[i])
			return 1;
	}
	return 0;
}

int contida1 (char a[], char b[]){
	int i;
	for (i = 0; a[i] != '\0'; i++){
		if ((pertece(a[i],b)) == 0)
			return 0;
	}
	return 1;
}

/*23 - Defina uma funcao int palindorome (char s[]) que testa se uma palavra e palindrome,
	   i.e., le-se de igual forma nos dois sentidos.
	   (https://codeboard.io/projects/14587)
*/

int palindorome1 (char s[]){
	int i, j;
	for (j = 0; s[j] != '\0'; j++);
	j--;
	for (i = 0; s[i] != '\0' && j >= i; i++){
		if (s[i] != s[j])
			return 0;
		j--;
	}
	return 1;
}

/*24 - Defina uma funcao int remRep (char x[]) que elimina de uma string
	   todos os caracteres que se repetem sucessivamente deixando la apenas uma copia.
	   A funcao devera retornar o comprimento da string resultante.
	   Assim, por exemplo, ao invocarmos a funcao com um vector contendo "aaabaaabbbaaa",
	   o vector deve passar a conter a string "ababa" e a funcao devera retornar o valor 5.
	   (https://codeboard.io/projects/13663)
*/

void eliminar (char s[]){
	int i;
	for (i = 0; s[i] != '\0'; i++){
		s[i] = s[i+1];
	}
}

int remRep1 (char s[]){
	int i, r;
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] == s[i+1]){
			eliminar(&(s[i]));
			i--;
		}
	}
	for (r = 0; s[r] != '\0'; r++);
	return r;
}

/*25 - Defina uma funcao int limpaEspacos (char t[]) que elimina repeticoes sucessivas de espacos por um unico espaco.
	   A funcao deve retornar o comprimento da string resultante.
	   (https://codeboard.io/projects/13733)
*/

int apagaEspaco (char s[]){
	int i;
	for (i = 0; s[i] != '\0'; i++){
		s[i] = s[i+1];
	}
	return 0;
}

int limpaEspacos1 (char s[]){
	int i;
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] == ' ' && s[i+1] == ' '){
			apagaEspaco(&(s[i]));
			i--;
		}
	}
	int r;
	for (r = 0; s[r] != '\0'; r++);
	return r;
}

/*26 - Defina uma funcao void insere (int v[], int N, int x) que insere um elemento (x) num vetor ordenado.
	   Assuma que as N primeiras posicoes do vetor estao ordenadas e que, por isso,
	   apos a insercao o vector, tera as primeiras N+1 posicoes ordenadas.
	   (https://codeboard.io/projects/14836)
*/

void adiciona (int v[], int N, int x){
	N++;
	int i, j;
	for (i = 0; i <= N; i++){
		j = v[i];
		v[i] = x;
		x = j;
	}
}

void insere1 (int v[], int N, int x){
	int i;
	for (i = 0; i <= N; i++){
		if (x < v[i]){
			adiciona(&(v[i]), (N-i), x);
			break;
		}
		if (i == N){
			v[N+1] = x;
			break;
		}
	}
	N++;
}

/*27 - Defina uma funcao void merge (int r [], int a[], int b[], int na, int nb) que, 
	   dados vectores ordenados a (com na elementos) e b (com nb elementos), 
	   preenche o vector r (com na+nb elementos) com os elementos de a e b ordenados.
	   (https://codeboard.io/projects/14837)
*/

void merge1 (int r[], int a[], int b[], int na, int nb){
	int i, tamanho = 1;
	r[0] = a[0]; 
	for(i = 1; i < na; i++){
	    insere1(r,tamanho++,a[i]);
	}
	for(i = 0; i < nb; i++){
	    insere1(r,tamanho++,b[i]);
	}
}

/*28 - Defina uma funcao int crescente (int a[], int i, int j) que testa se os elementos do vector a,
	   entre as posicoes i e j (inclusive) estao ordenados por ordem crescente.
	   A funcao deve retornar 1 ou 0 consoante o vector esteja ou nao ordenado.
	   (https://codeboard.io/projects/14838)
*/

int crescente1 (int a[], int i, int j){
	for ( ; i < j; i++){
		if (a[i+1] < a[i])
			return 0;
	}
	return 1;
}

/*29 - Defina uma funcao int retiraNeg (int v[], int N) que retira os numeros negativos de um vector com N inteiros.
	   A funcao deve retornar o numero de elementos que nao foram retirados.
	   (https://codeboard.io/projects/14839)
*/

void apagaa (int s[], int N){
	int i;
	N--;
	for(i = 0; i < N; i++){
		s[i] = s[i+1];
	}
}

int retiraNeg1 (int v[], int N){
	int i;
	for (i = 0; i < N; i++){
		if (v[i] < 0){
			apagaa(&(v[i]), (N-i));
			N--;
			i--;
		}
		return N;
	}
}

/*30 - Defina uma funcao int menosFreq (int v[], int N) que recebe um vector v com N elementos ordenado 
	   por ordem crescente e retorna o menos frequente dos elementos do vetor.
	   Se houver mais do que um elemento nessas condicoes deve retornar o que comeca por aparecer no indice mais baixo.
	   (https://codeboard.io/projects/14840)
*/

int contaFreq (int v[], int s, int N){
	int i, j;
	j = 0;
	for (i = 0; i < N; i++){
		if (v[i] == s)
			j++;
	}
	return j;
}

int menosFreq1 (int v[], int N){
	int i, j, l;
	j = contaFreq (v, v[0], N);
	l = v[0];
	for (i = 0; i < N; i++){
		if ((contaFreq (v, v[i], N)) < j){
			j = contaFreq (v, v[i], N);
			l = v[i];
		}
	}
	return l;
}

/*31 - Defina uma funcao int maisFreq (int v[], int N) que recebe um vector v com N elementos ordenado 
	   por ordem crescente e retorna o mais frequente dos elementos do vector.
	   Se houver mais do que um elemento nessas condicoes deve retornar o que comeca por aparecer no indice mais baixo.
	   (https://codeboard.io/projects/14841)
*/

int elContador (int v[], int s, int N){
	int i, j;
	for (i = j = 0; i < N; i++){
		if (s == v[i])
			j++;
	}
	return j;
}

int maisFreq1 (int v[], int N){
	int i, j, l;
	j = v[0];
	l = elContador (v, v[0], N);
	for (i = 0; i < N; i++){
		if ((elContador(v, v[i], N)) > l){
			j = v[i];
			l = elContador (v, v[i], N); 
		}
	}
	return j;
}

/*32 - Defina uma funcao int maxCresc (int v[], int N) que calcula o comprimento 
	   da maior sequencia crescente de elementos consecutivos num vector v com N elementos.
	   Por exemplo, se o vector contiver 10 elementos pela seguinte ordem: 1, 2, 3, 2, 1, 4, 10, 12, 5, 4,
	   a funcao devera retornar 4, correspondendo ao tamanho da sequencia 1, 4, 10, 12.
	   (https://codeboard.io/projects/14842)
*/

int contaCresc (int v[], int N){
	int i;
	for (i = 0; v[i] <= v[i+1] && i < N; i++);
	return (i+1);
}

int maxCresc1 (int v[], int N){
	int i, j;
	j = contaCresc (v, N);
	for (i = 0; i < N; i++){
		if ((contaCresc (&(v[i]), (N-i))) > j)
			j = contaCresc (&(v[i]), (N-i));
	}
	return j;
}

/*33 - Defina uma funcao int elimRep (int v[], int n) que recebe um vetor v com n inteiros e elimina as repeticoes.
	   A funcao devera retornar o numero de elementos do vetor resultante.
	   Por exemplo, se o vector v contiver nas suas primeiras 10 posicoes os numeros {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}
	   a invocacao elimRep (v,10) devera retornar 5 e colocar nas primeiras 5 posicoes do vetor os elementos {1,2,3,4,5}.
	   (https://codeboard.io/projects/14843)
*/

int checkRep (int v[], int i){
	int a;
	for (a = 0; a < i; a++){
		if (v[i] == v[a])
			return 1;
	}
	return 0;
}

int elimRep (int v[], int N){
	int i, j = 0;
	for (i = 0; i < N; i++){
		if (!checkRep(v, i)){
			v[j] = v[i];
			j++;
		}
	}
	return j;
}

/*34 - Defina uma funcao int elimRepOrd (int v[], int n) que recebe um vector v com n inteiros ordenado 
	    por ordem crescente e elimina as repeticoes.
	    A funcao devera retornar o numero de elementos do vector resultante.	 
	    (https://codeboard.io/projects/14844)
*/

void apagador (int v[], int n){
	int i;
	for (i = 0; i < n - 1; i++){
		v[i] = v[i + 1];
	}
}

int elimRepOrd (int v[], int n){
	int i;
	for (i = 0; i < n - 1; i++){
		if (v[i] == v[i + 1]){
			apagador (&(v[i]), (n-i));
			n--;
			i--;
		}
	}
	return (i+1);
}

/*35 - Defina uma funcao int comunsOrd (int a[], int na, int b[], int nb) que calcula
	   quantos elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum.
	   Assuma que os vectores a e b estao ordenados por ordem crescente.
	   (https://codeboard.io/projects/14845)
*/

int comunsOrd1 (int a[], int na, int b[], int nb){
	int i, j, r;
	i = j = r = 0;
	while((i < na) && (j < nb)){
		if (a[i] < b[j])
			i++;
		else if (a[i] > b[j])
			j++;
		else if (a[i] == b[j]){
			i++;
			j++;
			r++;
		}
	}
	return r;
}

/*36 - Defina uma funcao int comuns (int a[], int na, int b[], int nb) que calcula
	   quantos elementos os vectores a (com na elementos) e b (com nb elementos) tem em comum.
	   Assuma que os vectores a e b nao estao ordenados e defina a funcao sem alterar os vectores.
	   (https://codeboard.io/projects/14846)
*/

int ocorre2 (int a, int b[], int nb){
	int i;
	for (i = 0; i < nb; i++){
		if (b[i] == a)
			return 1;
	}
	return 0;
}

int comuns (int a[], int na, int b[], int nb){
	int i, j;
	j = 0;
	for (i = 0; i < na; i++){
		if (ocorre2 (a[i], b, nb))
			j++;
	}
	return j;
}

/*37 - Defina uma funcao int minInd (int v[], int n) que, dado um vector v com n inteiros,
 	   retorna o indice do menor elemento do vector.
 	   (https://codeboard.io/projects/14847)
*/

int minInd (int v[], int n){
	int i, j, l;
	j = v[0];
	l = 0;
	for (i = 0; i < n; i++){
		if (v[i] < j){
			j = v[i];
			l = i;
		}
	}
	return l;
}

/*38 - Defina uma funcao void somasAc (int v[], int Ac [], int N) que preenche o vector Ac
	   com as somas acumuladas do vector v.
	   Por exemplo, na posicao Ac[3] deve ser calculado como v[0]+v[1]+v[2]+v[3].
	   (https://codeboard.io/projects/14848)
*/
 
void somasAc1 (int v[], int Ac[], int N){
	int i, j;
	j = 0;
	for (i = 0; i <= N; i++){
		j += v[i];
		Ac[i] = j;
	}
}

/*39 - Defina uma funcao int triSup (int N, float m [N][N]) que testa se uma matriz quadrada e triangular superior,
	   i.e., que todos os elementos abaixo da diagonal sao zeros.
	   (https://codeboard.io/projects/14849)
*/

int triSup (int N, float m[N][N]){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < i; j++){
			if ((m[i][j]) != 0)
				return 0;
		}
	}
	return 1;
}

/*40 - Defina uma funcao void transposta (int N, float m [N][N])
	   que transforma uma matriz na sua transposta.
	   (https://codeboard.io/projects/14850)
*/

void transposta (int N, float m[N][N]){
	float t[N][N];
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			t[i][j] = m[j][i];
		}
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			m[i][j] = t[i][j];
		}
	}
}

/*41 - Defina uma funcao void addTo (int N, int M, int a [N][M], int b[N][M])
	   que adiciona a segunda matriz a primeira.
	   (https://codeboard.io/projects/14851)
*/

void addTo (int N, int M, int a[N][M], int b[N][M]){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			a[i][j] += b[i][j];
		}
	}
}

/*42 - Uma forma de representar conjuntos de indices consiste em usar um array de inteiros
	   contendo 1 ou 0 consoante esse indice pertenca ou nao ao conjunto.
	   Assim o conjunto {1; 4; 7} seria representado por um array em que as primeiras 8 posicoes conteriam {0,1,0,0,1,0,0,1}.
	   Apresente uma definicao da funcao int unionSet (int N, int v1[N], int v2[N], int r[N])
	   que coloca no array r o resultado da uniao dos conjuntos v1 e v2.
	   (https://codeboard.io/projects/14685)
*/

int unionSet (int N, int v1[N], int v2[N], int r[N]){
	int i;
	for (i = 0; i < N; i++){
		if (v1[i] == 0 && v2[i] == 0)
			r[i] = 0;
		if (v1[i] == 1 || v2[i] == 1)
			r[i] = 1;
	}
	return 0;
}

/*43 - Uma forma de representar conjuntos de indices consiste em usar um array de inteiros
	   contendo 1 ou 0 consoante esse indice pertenca ou nao ao conjunto.
	   Assim o conjunto {1; 4; 7} seria representado por um array em que as primeiras 8 posicoes conteriam {0,1,0,0,1,0,0,1}.
	   Apresente uma definicao da funcao int intersectSet (int N, int v1[N], int v2[N], int r[N])
	   que coloca no array r o resultado da intersecao dos conjuntos v1 e v2
	   (https://codeboard.io/projects/14694)
*/

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
	int i;
	for (i = 0; i < N; i++){
		if (v1[i] == 1 && v2[i] == 1)
			r[i] = 1;
		else 
			r[i] = 0;
	}
	return 0;
}

/*44 - Uma forma de representar multi-conjuntos de indices consiste em usar 
	   um array de inteiros contendo em cada posicao o numero de ocorrencias desse indice.
	   Assim o multi-conjunto {1; 1; 4; 7; 7; 7} seria representado por um array 
	   em que as primeiras 8 posicoes conteriam {0,2,0,0,1,0,0,3}.
	   Apresente uma definicao da funcao int intersectMSet (int N, int v1[N], int v2[N], int r[N])
	   que coloca no array r o resultado da intersecao dos multi-conjuntos v1 e v2.
	   (https://codeboard.io/projects/14733)
*/

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
	int i;
	for (i = 0; i < N; i++){
		if (v1[i] < v2[i])
			r[i] = v1[i];
		else 
			r[i] = v2[i];
	}
	return 0;
}