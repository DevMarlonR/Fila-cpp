/*
   Objetivo: realizar uma simulação de fila.
   -> Definir tamanho da fila inicialmente e variávelmente;
   -> Checar fila cheia/vazia;
   -> Adicionar pessoa na fila: '+' <nome>;
   -> Remover pessoa da fila: '-' <nome> - Precisa estar na fila;
   -> Atender o próximo: 'a' - Todos darem um passo a frente;
   -> Mostrar o estado da fila 'f' - Mostra fila
   -> Colocar lista de comandos: 'c' - Para ajudar o usuário como utilizar
   -> Parar o programa ao escrever 'p'
*/

#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
   string nome;
};

int main() {

   // Criando a fila com valor variável
   cout << "Seja bem vindo(a)!" << endl;
   cout << "Para começar digite o tamanho de sua fila: ";
   int tamanhoFila;
   cin >> tamanhoFila;
   cout << "-------------------------------------------------------" << endl;
   cout << "Fila de " << tamanhoFila << " posições criada!" << endl;
   cout << "É sua primeira vez ? Digite c para acessar os comandos." << endl;


   Pessoa fila[tamanhoFila];
   int ultimoFila = -1; // Indicando sempre o último da fila
   char comando;
   string novaPessoa, desistente;

   while (cin >> comando && comando != 'p') {

      // Adicionando na fila
      if (comando == '+') {
         cin >> novaPessoa;

         if (ultimoFila+1 >= tamanhoFila) {
            cout << "No momento a fila está cheia." << endl;
         } else {
            fila[++ultimoFila].nome = novaPessoa;
            cout << novaPessoa << " entrou na fila!" << endl;
         }

      } else if (comando == '-') {
      // Removendo da fila
         cin >> desistente;
         int posDesistente = -1;

         for (int i = 0; i <= ultimoFila; i++) {
         
            if (desistente == fila[i].nome) {
               posDesistente = i;
               break;
            }
         }
         
         if (posDesistente == -1) {
            cout << desistente << " não está na fila." << endl;
         } else {
            for (int i = posDesistente; i <= ultimoFila; i++) {
               fila[i] = fila[i+1];
            }
            ultimoFila--;
            cout << desistente << " saiu da fila." << endl;
         }

      } else if (comando == 'a') {
      // Atendendo primeiro da fila
         if (ultimoFila != -1) {
            string atendendo = fila[0].nome;
            cout << "Atendendo: " << atendendo << "." << endl;

            for (int i = 0; i <= ultimoFila; i++) {
               fila[i] = fila[i+1];
            }
            ultimoFila--;
         } else {
            cout << "Não há ninguém para atender." << endl;
         }
      } else if (comando == 'f') {
      // Mostrar tamanho da fila
      cout << "Fila: " << tamanhoFila << " posições total." << endl; 
      if (tamanhoFila - (ultimoFila+1) > 1) {
         cout << tamanhoFila - (ultimoFila+1) << " posições vazias." << endl;
      } else if (tamanhoFila - (ultimoFila+1) <= 1) {
         cout << tamanhoFila - (ultimoFila+1) << " posição vazia." << endl;
      }
      cout << "-------------------------" << endl;
      // Mostrar toda a fila
         if (ultimoFila == -1) {
            cout << "A fila está vazia" << endl;
            continue;
         }

         for (int i = 0; i <= ultimoFila; i++) {
            cout << i+1 << " - " << fila[i].nome << endl;
         }

      } else if (comando == 'c') {
      // Mostrar a lista de comandos
         cout << "----- LISTA  DE  COMANDOS -----" << endl;
         cout << "- > + (nome) < Adicionar pessoa -" << endl;
         cout << "- > - (nome) < Remover pessoa   -" << endl;
         cout << "- > a < Atender próx. da fila   -" << endl;
         cout << "- > f < Mostrar toda a fila     -" << endl;
         cout << "- > c < Lista de Comandos       -" << endl;
         cout << "- > p < Encerrar Programa       -" << endl;
         cout << "---------------------------------" << endl;
      } else {
      // caso usuário digite um comando inválido
         cout << "Desculpe, não identificamos o comando..." << endl;
         cout << "Certifique-se se o comando foi digitado corretamente." << endl;
         cout << "Para acessar a lista de comandos digite: c." << endl;
         continue;
      }

   }

   cout << "Espero que tenha gostado." << endl;
   cout << "Criado por: @DevMarlonR." << endl;

   return 0;
}