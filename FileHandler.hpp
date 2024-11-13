// FileHandler.hpp
#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "DataItem.hpp"

class FileHandler {
public:
    static std::vector<DataItem> readDataFromFile(const std::string &filename) {
        std::vector<DataItem> data;
        std::ifstream file(filename);
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string pais, continente;
            double felicidade, rendaPerCapita, expectativaDeVida, liberdadeDeEscolha, generosidade;

     
            if (std::getline(iss, pais, ',') &&
                std::getline(iss, continente, ',') &&
                (iss >> felicidade).ignore() &&
                (iss >> rendaPerCapita).ignore() &&
                (iss >> expectativaDeVida).ignore() &&
                (iss >> liberdadeDeEscolha).ignore() &&
                (iss >> generosidade).ignore()) {
                
                data.emplace_back(pais, continente, felicidade, rendaPerCapita,
                                  expectativaDeVida, liberdadeDeEscolha, generosidade);
            }
        }
        file.close();
        return data;
    }

     static void printData(const std::vector<DataItem> &data) {

        std::cout << std::fixed << std::setprecision(4);

        std::cout <<std::left<< std::setw(30) << "País"
                  << std::right<< std::setw(14) << "Continente"
                  << std::setw(15) << "Felicidade"
                  << std::setw(24) << "Renda per Capita"
                  << std::setw(23) << "Expectativa de Vida"
                  << std::setw(28) << "Liberdade de Escolha"
                  << std::setw(25) << "Generosidade" << "\n"<<std::endl;

        for (const auto &item : data) {
            std::cout <<  std::left<< std::setw(30) << item.pais
                      << std::right<< std::setw(15) << item.continente
                      << std::setw(15) << item.felicidade
                      << std::setw(20) << item.rendaPerCapita
                      << std::setw(20) << item.expectativaDeVida
                      << std::setw(25) << item.liberdadeDeEscolha
                      << std::setw(25) << item.generosidade << std::endl;
        }
    }
};

#endif
