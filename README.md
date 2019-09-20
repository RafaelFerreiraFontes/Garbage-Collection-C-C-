# Garbage-Collection-C-C-
Coletor de lixo para a linguagem C/C++.

Basta incluir a "lib" memoria.hpp e utilizar a estrutura de dado GCtype<(tipo de dado)>, como demostrado no exemplo.

Tutorial:

Para utilizar a biblioteca deve-se primeiro incluir a biblioteca memoria.hpp e depois utilizar a estrutura de dados GCtype<(defini o tipo de dado)>:
  
GCtype< tipo >
  
Campos:

tipo *ed : ponteiro para àrea de memória da estrutura.

Funções internas:

void malloc2(size_t size) : aloca uma àrea de memória para o campo ed.

void atribuir(type *a) : atribui um endereço de memória para o campo ed,caso o valor seja NULL libera a àrea de memória e o contador de referencias seja igual a zero. 

void atribuir2(type a) : atribui um valor à àrea de memória do campo ed.

Obs:Atenção para liberar a memória necessario é usar a função atribuir com o valor NULL(exemplo: varExemplo.atribuir(NULL)).
