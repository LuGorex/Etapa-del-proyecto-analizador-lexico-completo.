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
                cad= "Identificador";
                break;

           case TipoSimbolo::OPADIC:
                cad= "Op. Adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "Op. Multiplicacion";
                break;

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;

           case TipoSimbolo::ENTERO:
                cad= "Entero";
                break;

            case TipoSimbolo::REAL:
                cad= "Real";
                break;

            case TipoSimbolo::OPRELAC:
                cad= "Op. Relacional";
                break;

            case TipoSimbolo::OPOR:
                cad= "Op. Or";
                break;

            case TipoSimbolo::OPAND:
                cad= "Op. And";
                break;

            case TipoSimbolo::OPNOT:
                cad= "Op. Not";
                break;

            case TipoSimbolo::OPIGUALDAD:
                cad= "Op. Igualdad";
                break;

            case TipoSimbolo::PUNTOYCOMA:
                cad= "Punto y coma";
                break;

            case TipoSimbolo::COMA:
                cad= "Coma";
                break;

            case TipoSimbolo::PARENBAI:
                cad= "Parentesis abierto";
                break;

            case TipoSimbolo::PARENCER:
                cad= "Parentesis cerrado";
                break;

            case TipoSimbolo::CORCHETEABI:
                cad= "Corchete abierto";
                break;

            case TipoSimbolo::CORCHETECER:
                cad= "Corchete cerrado";
                break;

            case TipoSimbolo::IGUAL:
                cad= "Igual";
                break;

            case TipoSimbolo::IF:
                cad= "If";
                break;

            case TipoSimbolo::IF:
                cad= "If";
                break;

            case TipoSimbolo::WHILE:
                cad= "While";
                break;

            case TipoSimbolo::RETURN:
                cad= "Return";
                break;

            case TipoSimbolo::ELSE:
                cad= "Else";
                break;

            case TipoSimbolo::CADENA:
                cad= "Cadena";
                break;

            case TipoSimbolo::TIPO:
                cad= "Tipo";
                break;
            }

            return cad;
    }


  void Lexico::entrada(string fuente){
       ind= 0;
      this->fuente= fuente;
  }

int Lexico::sigSimbolo(){

    estado=0;// inicializamos en estado 0
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
    //llamamos a la funcion que separa las palabras de la cadena
      c= sigCaracter();
      int longitud = c.length(); // obtenemos la longitud de la palabra
      switch (estado){
        case 0:
             if ( c == '+' || c=='-'){
                aceptacion(2);
                break;
             }
            else
            if(c == "*" || cas"/"){
                aceptacion(5);
                break;
            }
            else
            if (c == "<" || c == "<=" || c == ">" || c == "=>"){
                aceptacion(7);
                break;
            }
            else
            if (c == "||")
                aceptacion(8);
                break;
            }
            else
            if (c == "&&"){
                aceptacion(9);
                break;
            }
            if ( c == "!" ){
                aceptacion(10);
                break;
            }
            else
            if ( c == "!=" || c == "==" ){
                aceptacion(11);
                break;
            }
            else
            if ( c == ";" ){
                aceptacion(12);
                break;
            }
            else
            if ( c == "," ){
                aceptacion(13);
                break;
            }
            else
            if ( c == "("){
                aceptacion(14);
                break;
            }
            else
            if ( c == ")"){
                aceptacion(15);
                break;
            }
            else
            if ( c == "{"){
                aceptacion(16);
                break;
            }
            else
            if ( c == "}"){
                aceptacion(17);
                break;
            }
            if ( c == "}" ){
                aceptacion(17);
                break;
            }
            else
            if ( c == "{" ){
                aceptacion(18);
                break;
            }
            else
            if ( c == "if" ){
                aceptacion(19);
                break;
            }
            else
            if ( c == "while" ){
                aceptacion(20);
                break;
            }
            else
            if ( c == "return" ){
                aceptacion(21);
                break;
            }
            else
            if ( c == "else" ){
                aceptacion(22);
                break;
            }
            else
            if ( c == "int" || c== "float" || c == "void" || c== "char"){
                aceptacion(24);
                break;
            }
            else
            if ( c == "$" ){
                aceptacion(3);
                break;
            }


   }
    //Fin del Automata



      switch (estado){

         case 2:
              tipo= TipoSimbolo::OPADIC;
              break;


        dafault:
              tipo= TipoSimbolo::ERROR;
      }

	return tipo;
}

string Lexico::sigCaracter(){
    string palabra;
    // revisamos si nos encontramos al final de la cadena
    if (terminado()){
        return "$";
    }
    // revisamos si hay un simbolo de $ antes del final de la cadena para terminar precipitadamente
    if(fuente[ind] == '$'){
        return "$";
    }
    // recorremos la cadena letra por letra y se suman en una variable, cuando hay un espacio
    // esta variable forma una "palabra" y esta se regresa para analizar de que tipo es
    else{
        while(fuente[ind] != ' '){
            palabra += fuente[ind];
            ind++;
        }
        if(fuente[ind] == ' '){
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
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         if(ind >= fuente.length()){
            return true;
         }
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
