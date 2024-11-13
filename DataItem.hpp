// DataItem.hpp
#ifndef DATAITEM_HPP
#define DATAITEM_HPP

#include <string>

class DataItem {
public:
    string pais;
    string continente;
    double felicidade;
    double rendaPerCapita;
    double expectativaDeVida;
    double liberdadeDeEscolha;
    double generosidade;

    DataItem(const string &pais, const string &continente, double felicidade,
             double rendaPerCapita, double expectativaDeVida, double liberdadeDeEscolha, double generosidade)
        : pais(pais), continente(continente), felicidade(felicidade), rendaPerCapita(rendaPerCapita),
          expectativaDeVida(expectativaDeVida), liberdadeDeEscolha(liberdadeDeEscolha), generosidade(generosidade) {}
};

#endif
