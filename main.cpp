#include <iostream>
#include <random>

#include "Aquario.h"
#include "Peixe.h"

using namespace std;

double obtemRandom(double min, double max){
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main() {

    cout << "---- Ficha 6.1 -----" << endl;
    Aquario *aq1 = new Aquario();
    Peixe *px1 = new Peixe {"peixe Verde", "laranja"};
    Peixe *px2 = new Peixe {"peixe branco", "verde"};
    Peixe *px3 = new Peixe{"peixe azul", "azul"};
    Peixe *px4 = new Peixe{"peixe dourado", "prata"};

    aq1->adicionaPeixe(px1);
    aq1->adicionaPeixe(px2);
    aq1->adicionaPeixe(px3);
    // cout << px3->obtemNumeroSerie() << endl;
    // aq1->imprime();
    cout << "---- *aq1 -----" << endl;
    cout << *aq1 << endl;

    Peixe *px_temp = new Peixe(*px3);
    cout << "---- *aq1::*px_temp(*px3)::construtor por cópia -----" << endl;
    cout << *aq1 << endl;

    aq1->alimentaPeixes(5);
    cout << *aq1 << endl;

    Aquario *aq2 = new Aquario();
    aq2->adicionaPeixe(px4);
    cout << *aq2 << endl;
    *aq2 = *aq1; // chama o operador overloading (=)
    cout << endl << "---- aq2::operator= -----" << endl;
    cout << *aq2 << endl;

    //aq2 = aq1;  // usa o operador de atribuição por omissão e copia membro a membro---- e agora os peixes são de que aquário?
    cout << endl << "---- aq2::operator= -----" << endl;
    cout << *aq2 << endl;

    cout << endl << "---- aq2::operator=??? aq1 -----" << endl;
    cout << *aq1 << endl;

    cout << endl << "---- aq3::NOVO Aquário-----" << endl;
    Aquario *aq3 = new Aquario();
    Peixe *px5 = new Peixe{"peixe dourado", "prata"};
    aq3->adicionaPeixe(px5);
    cout << *aq3 << endl;
    *aq3 = *aq2;
    cout << endl << "---- aq3::operator= -----" << endl;
    cout << *aq3 << endl;

    /*
    aq1->limpaAquario();
    cout << *aq1 << endl;

    if (aq1->peixeExiste(501)){
     cout << "vou tirar o peixe\n";
     Peixe *out = aq1->removePeixe(501);
     cout << *out;
    }

    cout << aq1->peixeExiste(600) << endl;
    */

    delete aq1;
    delete aq2;

    return 0;

}
