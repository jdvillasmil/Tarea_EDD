#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    Persona();
    Persona(std::string nombre, int edad);

    bool operator<(const Persona& other) const {
        return this->edad < other.edad;
    }

    // Sobrecarga del operador ==
    bool operator==(const Persona& other) const {
        return (this->nombre == other.nombre && this->edad == other.edad);
    }

    // Sobrecarga del operador !=
    bool operator!=(const Persona& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Persona& p) {
        os << "Nombre: " << p.nombre << ", Edad: " << p.edad;
        return os;
    }
};

#endif // PERSONA_H

