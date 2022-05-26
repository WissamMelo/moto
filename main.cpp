// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//

#include <iostream>
#include "moto.hpp"

const int TEMPO_TOTAL = 1810; //ciclo total onde cada interação é 1 segundo (30 min e 10 seg)
const int TEMPO_MOSTRAR = 10;

int main() {
    Moto origem("A76JR90", 0, Battery(111, 85, true));
    ETB etb;
    etb.uid = 0;

    origem.ligar(true);

    etb.associar_cp(0, 200, 100, 1);
    etb.associar_cp(1, 300, 100, 1);
    etb.associar_cp(2, 400, 100, 1);
    etb.associar_cp(3, 500, 70, 1);
    etb.associar_cp(4, 600, 60, 1);
    etb.associar_cp(5, 700, 50, 1);
    etb.associar_cp(6, 0, 0, 0);

    for (int i = 0; i <= TEMPO_TOTAL; i++) {
        if(i%TEMPO_MOSTRAR == 0 || i == 0) {
            std::cout << "Motorcycle plate: " << origem.get_plate() << "\n";
            std::cout << "Speed: " << origem.get_speed() << "\n";
            std::cout << "Attached battery UID: " << origem.bateria.get_uid() << "\n";
            std::cout << "Motorcycle battery SoC: " << origem.bateria.get_soc() << "\n";

            std::string charge1 = (etb.cps[0][2])?"YES":"NO";
            std::string charge2 = (etb.cps[1][2])?"YES":"NO";
            std::string charge3 = (etb.cps[2][2])?"YES":"NO";
            std::string charge4 = (etb.cps[3][2])?"YES":"NO";
            std::string charge5 = (etb.cps[4][2])?"YES":"NO";
            std::string charge6 = (etb.cps[5][2])?"YES":"NO";
            std::string charge7 = (etb.cps[6][2])?"YES":"NO";

            std::cout << "ETB ID: " << etb.get_uid() << "\n";
            std::cout << "CP 1: [battery UID " << etb.cps[0][0] << " | battery SoC " << etb.cps[0][1] << " | charging: " << charge1 << "]\n";
            std::cout << "CP 2: [battery UID " << etb.cps[1][0] << " | battery SoC " << etb.cps[1][1] << " | charging: " << charge2 << "]\n";
            std::cout << "CP 3: [battery UID " << etb.cps[2][0] << " | battery SoC " << etb.cps[2][1] << " | charging: " << charge3 << "]\n";
            std::cout << "CP 4: [battery UID " << etb.cps[3][0] << " | battery SoC " << etb.cps[3][1] << " | charging: " << charge4 << "]\n";
            std::cout << "CP 5: [battery UID " << etb.cps[4][0] << " | battery SoC " << etb.cps[4][1] << " | charging: " << charge5 << "]\n";
            std::cout << "CP 6: [battery UID " << etb.cps[5][0] << " | battery SoC " << etb.cps[5][1] << " | charging: " << charge6 << "]\n";
            std::cout << "CP 7: [battery UID " << etb.cps[6][0] << " | battery SoC " << etb.cps[6][1] << " | charging: " << charge7 << "]\n";
            std::cout << "\n";
        }

        if(i <= 1800){
            origem.gasto();
            etb.ligar_cp(0);
            etb.ligar_cp(1);
            etb.ligar_cp(2);
            etb.ligar_cp(3);
            etb.ligar_cp(4);
            etb.ligar_cp(5);
        }
        if (i == 1800){
            origem.ligar(false);
            etb.associar_cp(6,origem.bateria.get_uid(),origem.bateria.get_soc(),1);
            origem.desassociar();
            origem.associar(etb.cps[0][0],etb.cps[0][1]);
            etb.desassociar_cp(0);
            etb.ligar_cp(6);
        }

        // 6 ciclos - Acelera por 3 minutos e  freia por 10 segundos
        if(i <= 180 ){origem.acelerar();}
        else if(i > 180 and i <= 190){origem.freiar();}
        else if(i > 190 and i <= 370){origem.acelerar();}
        else if(i > 370 and i <= 380){origem.freiar();}
        else if(i > 380 and i <= 560){origem.acelerar();}
        else if(i > 560 and i <= 570){origem.freiar();}
        else if(i > 570 and i <= 750){origem.acelerar();}
        else if(i > 750 and i <= 760){origem.freiar();}
        else if(i > 760 and i <= 940){origem.acelerar();}
        else if(i > 940 and i <= 950){origem.freiar();}
        else if(i > 950 and i <= 1130){origem.acelerar();}
        else if(i > 1130 and i <= 1140){origem.freiar();}

        // 4 ciclos - Acelera por 3 minutos e  freia por 10 segundos
        if(i > 1140 and i <= 1260){origem.acelerar();}
        else if(i > 1260 and i <= 1272){origem.freiar();}
        else if(i > 1272 and i <= 1392){origem.acelerar();}
        else if(i > 1392 and i <= 1404){origem.freiar();}
        else if(i > 1404 and i <= 1524){origem.acelerar();}
        else if(i > 1524 and i <= 1536){origem.freiar();}
        else if(i > 1536 and i <= 1656){origem.acelerar();}
        else if(i > 1656 and i <= 1668){origem.freiar();}

        //Acelera por 1 minuto e 40 segundos e Freia por 32 segundos
        else if(i > 1668 and i <= 1768){origem.acelerar();}
        else if(i > 1768 and i <= 1800){origem.freiar();}



    }

    return 0;
}
