#include <iostream>

using namespace std;

class AF{
	/*		Atributos		*/
	protected:
		char *alfabeto; //conjunto de caracteres de entrada validas
		int num_alfa; //numero de elemetos en el alfabeto
		int init_edo; //estado con el que se inicia
		int *end_edo; //conjunto de estados finales aceptables
		int edo_actual; //estado en el que se encuentra el automata en un t det.
	
	/*		Metodos		*/
	public:
		AF(char *alfa,int num,int init,int *end){
			alfabeto = alfa;
			num_alfa = num;
			init_edo = init;
			end_edo = end;
		};
		~AF(){};
		
};

class Trancicion{
	/*		Atributos		*/
	protected:
	int edo; //indica a que estado se esta describiendo
	int *edo_sig; //matriz que indica el estado sig. según la entrada
	
	/*		Metodos		*/
	public:
		Trancicion(int n,int *matrix){
			edo = n;
			edo_sig = matrix;
		}
		
		~Trancicion();
		int getEdoSig(int in); //retorna el estado siguiente segun la posición del caracter de entrada en el alfabeto
};


class AFD:AF{
	/*
		Nota aquí las tranciciones se procesan con una matriz
		unidimencional.
	*/
	
	/*		Atributos		*/
	protected:
		Trancicion *tabla_estados; //Array de tranciciones que describe las funciones de trancición
		int num_edos; //numero de estados
	/*		Metodos		*/
	public:
		AFD(char *alfa,int num,int init,int *end):AF(alfa,num,init,end){};
		~AFD(){};
		bool procCadena(string cadena); //procesa una cadena he indica si termino en un estado de aceptación
		
};

class AFN:AF{
	/*
		Nota aquí las tranciciones se procesan con una matriz
		bidimencional.
	*/
	
	/*		Atributos		*/
	protected:
		Trancicion *tabla_estados; //Matriz bidimencional que describe las funciones de trancición
		int num_edos; //numero de estados
	/*		Metodos		*/
	public:
		AFN(char *alfa,int num,int init,int *end):AF(alfa,num,init,end){};
		~AFN(){};
		bool procCadena(string cadena); //procesa una cadena he indica si termino en un estado de aceptación
		
};
