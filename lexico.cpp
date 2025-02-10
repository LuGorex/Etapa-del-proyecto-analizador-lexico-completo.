#include "lexico.h"

  Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente;
  }

  Lexico::Lexico(){
    ind= 0;
  }

  string Lexico::tipoAcad(int tipo){
         string cad= "";

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
       ind= 0;
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){

    estado=0;
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
      c= sigCaracter();

      switch (estado){
        case 0:
             if ( c == '+' || c=='-'){ aceptacion(5);
             break;
             }else if (c == '*' || c == '/'){
                    aceptacion(6);
                    break;
                } else if (c == '<' || c == '<=' || c == '>' || c == '>='){
                    aceptacion(7);
                    break;
                } else if (c == '||'){
                    aceptacion(8);
                    break;
                } else if (c == '&&'){
                    aceptacion(9);
                    break;
                } else if (c == '!'){
                    aceptacion(10);
                    break;
                } else if (c == '!=' || c == '=='){
                    aceptacion(11);
                    break;
                } else if (c == ';'){
                    aceptacion(12);
                    break;
                } else if (c == ','){
                    aceptacion(13);
                    break;
                } else if (c == '('){
                    aceptacion(14);
                    break;
                } else if (c == ')'){
                    aceptacion(15);
                    break;
                } else if (c == '{'){
                    aceptacion(16);
                    break;
                } else if (c == '}'){
                    aceptacion(17);
                    break;
                } else if ( c == '='){
                    aceptacion(18);
                    break;
                } else if (c == 'if'){
                    aceptacion(19);
                    break;
                } else if (c == 'while'){
                    aceptacion(20);
                    break;
                } else if (c == 'return'){
                    aceptacion(21);
                    break;
                } else if (c == 'else'){
                    aceptacion(22);
                    break;
                } else if (c == 'int' || c == 'float' || c == 'void' || c == 'char'){
                    aceptacion(24);
                    break;
                } else if (c == '$'){
                    aceptacion(23);
                    break;
                }





      }

   }
    //Fin del Automata

      switch (estado){
        case -1:
            tipo = TipoSimbolo::ERROR;
            break;
        case 0:
            tipo = TipoSimbolo::IDENTIFICADOR;
            break;
        case 1:
            tipo = TipoSimbolo::IDENTIFICADOR;
            break;
        case 2:
            tipo = TipoSimbolo::ENTERO;
            break;
        case 3:
            tipo = TipoSimbolo::REAL;
            break;
        case 4:
            tipo = TipoSimbolo::CADENA;
            break;
        case 5:
            tipo = TipoSimbolo::OPADIC;
            break;
        case 6:
            tipo = TipoSimbolo::OPMULT;
            break;
        case 7:
            tipo= TipoSimbolo::OPRELAC;
            break;
        case 8:
            tipo = TipoSimbolo::OPOR;
            break;
        case 9:
            tipo = TipoSimbolo::OPAND;
            break;
        case 10:
            tipo = TipoSimbolo::OPNOT;
            break;
        case 11:
            tipo = TipoSimbolo::OPIGUALDAD;
            break;
        case 12:
            tipo = TipoSimbolo::PUNTOYCOMA;
            break;
        case 13:
            tipo = TipoSimbolo::COMA;
            break;
        case 14:
            tipo = TipoSimbolo::PARENBAI;
            break;
        case 15:
            tipo = TipoSimbolo::PARENCER;
            break;
        case 16:
            tipo = TipoSimbolo::CORCHETEABI;
            break;
        case 17:
            tipo = TipoSimbolo::CORCHETECER;
            break;
        case 18:
            tipo = TipoSimbolo::IGUAL;
            break;
        case 19:
            tipo = TipoSimbolo::IF;
            break;
        case 20:
            tipo = TipoSimbolo::WHILE;
            break;
        case 21:
            tipo = TipoSimbolo::RETURN;
            break;
        case 22:
            tipo = TipoSimbolo::ELSE;
            break;
        case 23:
            tipo = TipoSimbolo::PESOS;
            break;

        dafault:
              tipo= TipoSimbolo::ERROR;
      }

	return tipo;
}

 char Lexico::sigCaracter(){
      if (terminado()) return '$';

      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){
       this->estado= estado;
       simbolo+= c;
  }

  void Lexico::aceptacion(int estado){
       sigEstado(estado);
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){
        return isalpha(c) || c=='_';
   }


   bool Lexico::esDigito(char c){
        return isdigit(c);
   }

   bool Lexico::esEspacio(char c){
        return c== ' ' || c== '\t';
   }


   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
