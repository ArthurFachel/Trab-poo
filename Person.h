#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person {
public:
  string País;
  string Continente;
  double felicidade;
  double gdp;
  double vida;
  double liberdade;
  double generosidade;


  Person(string País, string Continente, double felicidade, double gdp, double vida, double liberdade, double generosidade)
      : País(País), Continente(Continente), felicidade(felicidade), gdp(gdp), vida(vida), liberdade(liberdade), generosidade(generosidade) {}

  Person()
      : País("Desconhecido"), Continente("Desconhecido"), felicidade(0), gdp(0), vida(0), liberdade(0), generosidade(0) {}
};

#endif // PERSON_H
