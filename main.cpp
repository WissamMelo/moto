// Desafio Origem
// Created by Wissam Melo on 24/05/2022.
//

#include <iostream>
#include "moto.hpp"

int main() {
    Moto origem;
    origem.speed = 20;
    origem.acelerar();
    std::cout << origem.get_speed() << std::endl;
    origem.freiar();
    std::cout << origem.get_speed() << std::endl;

    std::cout << "Motorcycle plate: " << origem.get_plate() << "\n";
    std::cout << "Speed: " << origem.get_speed() << "\n";
    std::cout << "Attached battery UID: None\n";
    std::cout << "Motorcycle battery SoC: " << origem.bateria.get_soc() << "\n";

    std::cout << "ETB ID: XXX\n";
    std::cout << "CP 1: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";
    std::cout << "CP 2: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";
    std::cout << "CP 3: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";
    std::cout << "CP 4: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";
    std::cout << "CP 5: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";
    std::cout << "CP 6: [battery UID (or NONE) | battery SoC (or NONE) | charging: YES or NO]\n";

    return 0;
}
