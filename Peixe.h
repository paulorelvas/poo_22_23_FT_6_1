#include<iostream>
#include<sstream>

using namespace std;

#ifndef FT6_1_PEIXE_H
#define FT6_1_PEIXE_H

#include "Aquario.h"

class Peixe{
public:
    // Peixe();                         // construtor vazio
    Peixe(string especie, string cor);  // construtor do peixe (especie e cor) o peso é sempre 10 no início - depois varia consoante a comida/alimentação
    Peixe(const Peixe &peixe);          // construtor por cópia
    ~Peixe();                           // destrutor

    int obtemNumeroSerie() const;       // obtem o número de série de um dado peixe
    void come(unsigned int comida);     // função para alimentação do peixe
    //bool alteraPeso(int g);             // função que controla o peso do peixe
    bool isVivo() const;                // função que recalcula o ciclo/estado de vida do peixe
    bool ligaAaquario(Aquario *a);      // função que permite ligar o aquário e juntar peixes
    bool desligaAquario(Aquario *a);    // função que permite desligar um aquário - deixa de ter peixes

    string getAsString() const;         // obtem a informação do peixe (nome, cor, peso e número de série)
    void imprime();                     // imprime info do peixe - igual ao getAsstring - usado para testes - não é necessário - apagar

private:
    string especie;                     // espécie do peixe
    string cor{"cinzento"};          // cor do peixe - por omissão é cinzento
    int peso{10}; // gramas             // peso do peixe
    int numeroSerie;                    // número de série do peixe - inicia em 500
    static int nSerie;                  // contador de peixes - usado em conjugação com o número de série do peixe
    Aquario * aquario = nullptr;        // variável que permite associar peixes ao aquário
    unsigned int numVidas = 4;          // tempo de vida do peixe até morrer (alimentação)
    bool indigestao = false;            // variáveil usada para controlar o estado do peixe ao ser alimentado - vive - morre
};
ostream &operator<<(ostream &, const Peixe &);
#endif //FT6_1_PEIXE_H
