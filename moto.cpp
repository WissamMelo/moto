// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//
#include <iostream>
#include <math.h>
#include "moto.hpp"

//Métodos de moto

double Moto::acelerar() {(speed < 60)?speed += 0.2: speed = 60;}
double Moto::freiar() {(speed > 0)?speed -= 2:speed = 0;}
double Moto::gasto(){
    if(ligado == true){
        bateria.soc = bateria.soc - 0.01 - (pow((speed/60), 2))*0.05;
    } else {
        bateria.soc -= 0.01;
    }
};

void Moto::associar(double new_uid, double cp_bateria) {
    bateria.uid = new_uid;
    bateria.soc = cp_bateria;
};

void Moto::desassociar() {
    bateria.uid = 0;
    bateria.soc = 0;
};

void Moto::ligar(bool new_ligado) {ligado = new_ligado;}

double Moto::get_speed() {return speed;};
std::string Moto::get_plate() {return plate;};

//double Moto::get_speed() {
//    return speed;
//};

//Métodos da bateria

long long int Battery::get_uid() {return uid;};
double Battery::get_soc() {return soc;};
bool Battery::get_host() {return host;};

//Métodos do ETB
void ETB::associar_cp( int num_cps, double uid, double per, double charge) {
    cps[num_cps][0] = uid;
    cps[num_cps][1] = per;
    cps[num_cps][2] = charge;
};

void ETB::desassociar_cp( int num_cps) {
    cps[num_cps][0] = 0;
    cps[num_cps][1] = 0;
    cps[num_cps][2] = 0;
};


void ETB::ligar_cp(int num_cp) {(cps[num_cp][1] < 100)?cps[num_cp][1] += 0.05: cps[num_cp][1] = 100;};

int ETB::num_presente() {
    int res = 0;
    for (int i=0; i<7; i++)
        if (cps[i][0] != 0)
            res++;
    return res;
};

int ETB::num_carregando() {
    int res = 0;
    for (int i=0; i<7; i++)
        if (cps[i][2] == 1)
            res++;
    return res;
};

double ETB::tempo_carregar(int num_cp) {
    double tempo = (100 - cps[num_cp][1])/0.05;
    return tempo;
};

long long int ETB::get_uid() {return uid;};
int ETB::get_cps(int num_cp) {return *cps[num_cp];};