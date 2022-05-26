// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//

#include <iostream>

class Battery{
    public:
        long long int uid;
        double soc;
        bool host; // 0 -> Moto 1 -> ETB ou Idle

        Battery(long long int new_uid, double new_soc, bool new_host) {
            uid = new_uid;
            soc = new_soc;
            host = new_host;
        }

        void associar(bool new_host);
        void desassociar();

        long long int get_uid();
        double get_soc();
        bool get_host();
};

class Moto{
    public:
        std::string plate;
        double speed;
        bool ligado; //0 -> Desligado 1 -> Ligado
        Battery bateria;

        Moto(std::string new_plate, double new_speed, Battery bateria) : bateria(bateria) {
            plate = new_plate;
            speed = new_speed;
        }

        void ligar(bool new_ligado);
        void associar(double new_uid, double cp_bateria);
        void desassociar();

        double gasto();
        double acelerar();
        double freiar();
        double get_speed();
        std::string get_plate();

};

class ETB{
public:
    long long int uid;
    double cps[7][3];

//    ETB(long long int new_uid, double new_cps[6]) {
//            uid = new_uid;
//            cps[6] = new_cps[6];
//    }

    void associar_cp( int num_cps, double uid, double per, double charge);
    void desassociar_cp(int num_cp);
    void ligar_cp(int num_cp);
    int num_presente();
    int num_carregando();
    double tempo_carregar(int num_cp);
    long long int get_uid();
    int get_cps(int num_cp);
};