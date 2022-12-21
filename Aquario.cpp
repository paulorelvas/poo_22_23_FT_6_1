#include "Aquario.h"
#include "Peixe.h"

Aquario::~Aquario(){
    for (auto p : peixes)
        delete p;
    peixes.clear();
}
bool Aquario::adicionaPeixe(Peixe * peixe) {        // adiciona um novo peixe ao aquário
    cout << "Adiciona Peixe" << endl;
    if (peixe == nullptr)
        return false;
    if (peixe->ligaAaquario(this) == false)
        return false;

    peixes.push_back(peixe);

    return true;
}
bool Aquario::peixeExiste(int numSerie) const{            // verifica se o peixe existe com base no número de série
    for(auto el: peixes){
        if(el->obtemNumeroSerie() == numSerie)
            return true;
        //el->imprime();
    }
    //cout << "Peixe exists?" << endl;
    return false;
}
void Aquario::alimentaPeixes(unsigned int dose) {    // alimentar os peixes todos - um a um
    cout << "Alimenta peixe" << endl;

    for(auto i = 0; i < peixes.size(); i++) {
        peixes[i]->come(dose);
    }

    /* // alternativa
   for(auto el: peixes)
       el->come(dose);
   */
}

void Aquario::limpaAquario(){
    auto it = peixes.begin();
    while(it < peixes.end()) {
        if ((*it)->isVivo()) {
            ++it;
        } else {
            delete (*it);
            it = peixes.erase(it);
        }
    }
}

Peixe *Aquario::removePeixe(unsigned int n) {
    auto it = peixes.begin();
    //while (it < peixes.end()) {
    while (it != peixes.end()) {
        if((*it)->obtemNumeroSerie() == n) {
            Peixe *out = *it;

            if ((*it)->desligaAquario(this) == false)
                return nullptr;

            peixes.erase(it);
            return out;
        }
        ++it;
    }
    return nullptr;
}


string Aquario::getAsString() const {
    ostringstream os;

    if (peixes.size() == 0)
        os << "---Aquário vazio---";
    else {
        os << "--- Peixes no aquário --- " << endl;
        for (auto p: peixes)
            os << " " << p->getAsString() << "\n";
    }
    return  os.str();
}

/*
void Aquario::imprime(){
    cout << "Total de peixes: " << totalPeixes << endl;
    for(auto &el:peixes)
        el->imprime();
}*/

ostream &operator<<(ostream &os, const Aquario &p) {
    os << p.getAsString();
    return os;
}

Aquario &Aquario::operator=(const Aquario &a){
    cout << "----- OPERATOR= ------ " << endl;
    if(this == &a)
        return *this;

    if(a.peixes.size() == 0)    // se a origem estiver vazia devolve a origem
        return *this;

    cout << "Size of peixes: " << this->peixes.size() << endl;
    if( this->peixes.size() > 0 ) { // se não estiver vazio -- deve preparar o aquário para receber uma cópia do aquário que se pretnde copiar
        cout << "--- Entrei em modo destrói peixe --- operador= ---" << endl;
        for(auto p:peixes){
            this->removePeixe(p->obtemNumeroSerie());
            delete p;
        }
        this->peixes.clear();
    }

    for(auto el: a.peixes){     // adicionar ao destino cada elemento da origem --> PROBLEMA:: o aquario de origem tem a posse dos peixes
        //Peixe *aux = a.peixe;
        if(!this->adicionaPeixe(el))
            cout << " ----- Peixe não adicionado::posse exclusiva -----" << endl; // ALTERNATIVA:: criar uma cópia do peixe (construtor por cópia) -- IMPLEMENTAR casa
    }
    // ALTERNATIVA:: redefinir o operador= para criar uma cópia do objeto de modo a colocar no aquário para onde pretende copiar os peixinhos

    return *this;
}

