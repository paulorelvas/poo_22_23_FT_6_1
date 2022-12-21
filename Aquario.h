#include <iostream>
#include <vector>
using namespace std;

#ifndef FT6_1_AQUARIO_H
#define FT6_1_AQUARIO_H

class Peixe;

class Aquario {
public:
    ~Aquario();                                      // destrutor
    bool adicionaPeixe(Peixe * peixe);               // adiciona um novo peixe ao aquário
    bool peixeExiste(int numSerie) const;            // verifica se o peixe existe dado o número de série
    void alimentaPeixes(unsigned int dose);          // alimentar os peixes todos - um a um
    Peixe *removePeixe(unsigned int numSerie);       // remove um peixe dado o numSerie
    void limpaAquario();                             // limpa do aquário os peixes que entretanto morreram
    // void imprime();
    string getAsString() const;                      // obtém uma string com a informação (aquário/peixe)

    Aquario &operator=(const Aquario &);
private:
    int totalPeixes{0};
    Peixe * peixe = nullptr;
    vector<Peixe*> peixes;
};

ostream &operator<<(ostream &os, const Aquario &p);

#endif //FT6_1_AQUARIO_H
