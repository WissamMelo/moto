// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//

#include <iostream>

class Battery{
    public:
        long long int uid;
        double soc;
        bool host; // 0 -> Moto 1 -> ETB

        void associar(bool new_host);
        void desassociar();
        long long int get_uid();
        double get_soc();
        bool get_host();
};

class Moto{
    public:
        std::string plate;
        int speed;
        Battery bateria;

//        void ligar();
//        void desligar();
        double acelerar();
        double freiar();
        double get_speed();
        std::string get_plate();

};

class ETB{
public:
    long long int uid;
    double cps[6];


    void associar_cp(int num_cp);
    void desassociar_cp(int num_cp);
    void ligar_cp(int num_cp);
    void desligar_cp(int num_cp);
    void num_presente();
    void num_carregando();
    void tempo_carregar(int num_cp);
    long long int get_uid();
    int get_cps(int num_cp);
};