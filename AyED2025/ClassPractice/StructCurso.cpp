#include <cassert>
#include <string>

enum struct Carrera:char {Sistemas = 'K', Electronica = 'R'};
enum struct Nivel:char {Primero = '1', Segundo = '2', Tercero = '3'};
enum struct Turno:char {Mañana = '1', Tarde = '3', Noche = '5'};
enum struct Dia:char {Lunes = '1', Martes = '2', Miercoles = '3', Jueves = '4', Viernes = '5', Sabado = '6'};
enum struct Modalidad:char {Anual='A' , Cuatrimestral='C'};

struct comision{
    Carrera carrera;
    Nivel nivel;
    unsigned desdoble:4;
    Turno turno;
    Dia dia;
    Modalidad modalidad;
};

// comision c1 {Sistemas,Primero,0,Noche,Miercoles,Anual};

/* hacer funcion que 
 A: ToString Comision -> String
 B: NewComition String -> Comision

    ToString(c1) -> "K1053"
    NewComition("K1053") -> c1
*/

std::string ComisionAString(comision c);
comision StringAComision(const std::string& str);



int main(){

    comision c1 {Carrera::Sistemas, Nivel::Primero, 0, Turno::Noche, Dia::Miercoles, Modalidad::Anual};
    std::string str1 {"K1053"}; 
    
    assert(c1.carrera == Carrera::Sistemas);
    assert(c1.nivel == Nivel::Primero);
    assert(c1.desdoble == 0);
    assert(c1.turno == Turno::Noche);
    assert(c1.dia == Dia::Miercoles);
    assert(c1.modalidad == Modalidad::Anual);

    assert (StringAComision(str1).carrera == Carrera::Sistemas);
    assert (StringAComision(str1).nivel == Nivel::Primero);
    assert (StringAComision(str1).desdoble == 0);
    assert (StringAComision(str1).turno == Turno::Noche);
    assert (StringAComision(str1).dia == Dia::Miercoles);
    // assert (StringAComision(str1).modalidad == Modalidad::Anual);

    assert (ComisionAString(c1) == "K1053");

}


comision StringAComision(const std::string& str) {
    comision c;
    
    c.carrera = static_cast<Carrera>(str[0]);
    c.nivel = static_cast<Nivel>(str[1]);
    c.desdoble = str[2] - '0'; // Convert char to unsigned
    c.turno = static_cast<Turno>(str[3]);
    c.dia = static_cast<Dia>(str[4]);
    // (c.modalidad == Modalidad::Anual)? 'A' : 'C'; 

    return c;
}

std::string ComisionAString(comision c) {
    std::string str;
    
    str += static_cast<char>(c.carrera);
    str += static_cast<char>(c.nivel);
    str += std::to_string(c.desdoble);
    str += static_cast<char>(c.turno);
    str += static_cast<char>(c.dia);
    // str += (c.modalidad == Modalidad::Anual) ? 'A' : 'C'; 

    return str;
}