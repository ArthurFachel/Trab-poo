#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class LinkedList {
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}

  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  void addPerson(const Person &person) {
    Node *newNode = new Node(person);
    newNode->next = head;
    head = newNode;
  }
 
  void loadFromFile(const std::string &filePaís) {
    std::ifstream infile(filePaís);
    if (!infile) {
      std::cerr << "Erro ao abrir o arquivo!" << std::endl;
      return;
    }

  string País;
  string Continente;
  double felicidade;
  double gdp;
  double vida;
  double liberdade;
  double generosidade;
    while (infile >> País >> Continente >> felicidade >> gdp >>  vida >>   liberdade >> generosidade) {
      addPerson(Person(País,  Continente,  felicidade,  gdp,  vida,  liberdade, generosidade));
    }
    infile.close();
  }

  void printList() const {
    Node *current = head;
    while (current != nullptr) {
      std::cout << "País: " << current->person.País
                << ", Continente: " << current->person.Continente
                << ", Felicidade: " << current->person.felicidade
                << ", Renda per capita: " << current->person.gdp
                << ", Expectativa de vida: " << current->person.vida
                << ", Liberdade de escolha: " << current->person.liberdade
                << ", Generosidade: " << current->person.generosidade
                << std::endl;

      current = current->next;
    }
  }
}
;

#endif // LINKEDLIST_H
