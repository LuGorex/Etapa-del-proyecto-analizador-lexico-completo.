#include "lexico.h"

Lexico::Lexico(string fuente){
    ind = 0;
    this->fuente = fuente;
}

Lexico::Lexico(){
    ind = 0;
}

string Lexico::tipoAcad(int tipo){
    string cad = "";

    switch (tipo){
        case TipoSimbolo::IDENTIFICADOR:
            cad = "Identificador";
            break;

        case TipoSimbolo::OPADIC:
            cad = "Op. Adición";
            break;

        case TipoSimbolo::OPMULT:
            cad = "Op. Multiplicación";
            break;

        case TipoSimbolo::PESOS:
            cad = "Fin de la Entrada";
            break;

        case TipoSimbolo::ENTERO:
            cad = "Entero";
            break;

        case TipoSimbolo::REAL:
            cad = "Real";
            break;

        case TipoSimbolo::OPRELAC:
            cad = "Op. Relacional";
            break;

        case TipoSimbolo::OPOR:
            cad = "Op. Or";
            break;

        case TipoSimbolo::OPAND:
            cad = "Op. And";
            break;

        case TipoSimbolo::OPNOT:
            cad = "Op. Not";
            break;

        case TipoSimbolo::OPIGUALDAD:
            cad = "Op. Igualdad";
            break;

        case TipoSimbolo::PUNTOYCOMA:
            cad = "Punto y coma";
            break;

        case TipoSimbolo::COMA:
            cad = "Coma";
            break;

        case TipoSimbolo::PARENBAI:
            cad = "Paréntesis abierto";
            break;

        case TipoSimbolo::PARENCER:
            cad = "Paréntesis cerrado";
            break;

        case TipoSimbolo::CORCHETEABI:
            cad = "Corchete abierto";
            break;

        case TipoSimbolo::CORCHETECER:
            cad = "Corchete cerrado";
            break;

        case TipoSimbolo::IGUAL:
            cad = "Igual";
            break;

        case TipoSimbolo::IF:
            cad = "If";
            break;

        case TipoSimbolo::WHILE:
            cad = "While";
            break;

        case TipoSimbolo::RETURN:
            cad = "Return";
            break;

        case TipoSimbolo::ELSE:
            cad = "Else";
            break;

        case TipoSimbolo::CADENA:
            cad = "Cadena";
            break;

        case TipoSimbolo::TIPO:
            cad = "Tipo";
            break;
    }

    return cad;
}

void Lexico::entrada(string fuente){
    ind = 0;
    this->fuente = fuente;
}

int Lexico::sigSimbolo(){
    estado = 0; // inicializamos en estado 0
    continua = true;
    simbolo = "";
    bool entero = true;
    bool reales = true;
    bool cadena = false;
    string c;

    // Inicio del Automata
    while (continua){
        c = sigCaracter();
       // int longitud = c.length(); // obtenemos la longitud de la palabra
       int longitud = c.length();
        switch (estado){
            case 0:
                for (int i=0; i < longitud; i++){
                    bool x = isdigit(c[i]);
                    if(x == 0 && c[i] != '-' )entero = false;//si los caracteres de la palabra no son solo digitos significa que no es un entero
                    if(x == 0 && c[i] != '.' && c[i] != '-' )reales = false;//si uno de los caracteres no es digito y no es un punto no es un real
                    if(x == 0 && c[i] == '\"')cadena = true;//si el caracter no es digito, ni es punto pero es comilla entonces es cadena.
                }
                if (entero == true){
                    aceptacion(1);
                    break;
                } else if (reales == true){
                    aceptacion(2);
                    break;
                } else if (cadena == true){
                    aceptacion(3);
                    break;
                }
                else{//si al analizar la palabra no fue ni palabra reservada, ni entero, ni real, ni cadena entonces es identificador
                    aceptacion(1);
                    break;
                } if (c == "+" || c == "-"){
                    aceptacion(5);
                    break;
                } else if (c == "*" || c == "/"){
                    aceptacion(6);
                    break;
                } else if (c == "<" || c == "<=" || c == ">" || c == ">="){
                    aceptacion(7);
                    break;
                } else if (c == "||"){
                    aceptacion(8);
                    break;
                } else if (c == "&&"){
                    aceptacion(9);
                    break;
                } else if (c == "!"){
                    aceptacion(10);
                    break;
                } else if (c == "!=" || c == "=="){
                    aceptacion(11);
                    break;
                } else if (c == ";"){
                    aceptacion(12);
                    break;
                } else if (c == ","){
                    aceptacion(13);
                    break;
                } else if (c == "("){
                    aceptacion(14);
                    break;
                } else if (c == ")"){
                    aceptacion(15);
                    break;
                } else if (c == "{"){
                    aceptacion(16);
                    break;
                } else if (c == "}"){
                    aceptacion(17);
                    break;
                } else if ( c == "="){
                    aceptacion(18);
                    break;
                } else if (c == "if"){
                    aceptacion(19);
                    break;
                } else if (c == "while"){
                    aceptacion(20);
                    break;
                } else if (c == "return"){
                    aceptacion(21);
                    break;
                } else if (c == "else"){
                    aceptacion(22);
                    break;
                } else if (c == "int" || c == "float" || c == "void" || c == "char"){
                    aceptacion(24);
                    break;
                } else if (c == "$"){
                    aceptacion(23);
                    break;
                }

                break;
        }
    }
    // Fin del Automata

    switch (estado){
        case 2:
            tipo = TipoSimbolo::OPADIC;
            break;

        default:
            tipo = TipoSimbolo::ERROR;
    }

    return tipo;
}

char Lexico::sigCaracter(){
    char palabra;
    // revisamos si nos encontramos al final de la cadena
    if (terminado()){
        return '$';
    }
    // revisamos si hay un simbolo de $ antes del final de la cadena para terminar precipitadamente
    if (fuente[ind] == '$'){
        return '$';
    } else {
        // recorremos la cadena letra por letra y se suman en una variable, cuando hay un espacio
        // esta variable forma una "palabra" y esta se regresa para analizar de que tipo es
        while (fuente[ind] != ' '){
            palabra += fuente[ind];
            ind ++;
        }
        if (fuente[ind] == ' '){
            ind++;
        }
        return palabra;
    }
}

void Lexico::sigEstado(int estado){
    this->estado = estado;
    simbolo += c;
}

void Lexico::aceptacion(int estado){
    sigEstado(estado);
    continua = false;
}

bool Lexico::terminado(){ // fin de cadena
    if (ind >= fuente.length()){
        return true;
    }
    return false; // Agregar retorno de false si no se cumple la condición
}

bool Lexico::esLetra(char c){
    return isalpha(c) || c == '_';
}

bool Lexico::esDigito(char c){
    return isdigit(c);
}

bool Lexico::esEspacio(char c){
    return c == ' ' || c == '\t';
}
void Lexico::retroceso(){
    if ( c != '$') ind--;
        continua= false;

}

   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
