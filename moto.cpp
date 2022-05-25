// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//
#include <iostream>
#include "moto.hpp"

//Métodos de moto

double Moto::acelerar() {

    if (speed <= 60) {
        speed += 0.2;
    }
}

double Moto::freiar() {

    if (speed >= 0) {
        speed -= 2;
    }
}

double Moto::get_speed() {return speed;};
std::string Moto::get_plate() {return plate;};

//double Moto::get_speed() {
//    return speed;
//};

//Métodos da bateria

void Battery::associar(bool new_host) {
    host = new_host;
};

void Battery::desassociar() {
    host = !host;
};

long long int Battery::get_uid() {return uid;};
double Battery::get_soc() {return soc;};
bool Battery::get_host() {return host;};

//Métodos do ETB
void associar_cp(int num_cp) {};

void desassociar_cp(int num_cp) {};

void ligar_cp(int num_cp) {};

void desligar_cp(int num_cp) {};

void num_presente() {};

void num_carregando() {};

void tempo_carregar(int num_cp) {};

long long int ETB::get_uid() {return uid;};
int ETB::get_cps(int num_cp) {return cps[num_cp];};