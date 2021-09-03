#include <iostream>

using namespace std;

class AF{
	/*		Atributos		*/
	protected:
		char *alfabeto; //conjunto de caracteres de entrada validas
		int num_alfa; //numero de elemetos en el alfabeto
		int init_edo; //estado con el que se inicia
		int num_final; //numero de estados finales
		int *end_edo; //conjunto de estados finales aceptables
		int edo_actual; //estado en el que se encuentra el automata en un t det.
	
	/*		Metodos		*/
	public:
		AF(char *alfa,int num,int init,int *end,int num_end){
			alfabeto = alfa;
			num_alfa = num;
			init_edo = init;
			end_edo = end;
			num_final = num_end;
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
		AFD(char *alfa,int num,int init,int *end,int num_end):AF(alfa,num,init,end,num_end){};
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
		AFN(char *alfa,int num,int init,int *end,int num_end):AF(alfa,num,init,end,num_end){};
		~AFN(){};
		bool procCadena(string cadena); //procesa una cadena he indica si termino en un estado de aceptación
		
};










class Generador{
	private:
		string reg_exp;
		AFN *automata;
	
	public:
		Generador(string exp){
			/* Construcción del automata principal*/
			int i,num_caracteres,edo_final;
			num_caracteres = 'z' - 'a'; //alfabeto desde 'a' hasta 'z'
			char alfabeto[ num_caracteres ];
			
			for(i = 0; i < num_caracteres; i++){
				alfabeto[i] = i + 'a';
			}
			
			reg_exp = exp;
			edo_final = 1;
			
			automata = new AFN((char *)(&alfabeto),num_caracteres,0,&edo_final,1);
			/*inicia analizis de los caracteres*/
			readRegExp(reg_exp);
		}
		~Generador();
		
		void readRegExp(string cadena){
			
		}
};

int main(){
	string Reg;
			//Generador *constructorAFN = new Generador(Reg);
			cout<<" ingrese la expresion regular";
			cin>>Reg;
			
			Generador *constructorAFN = new Generador(Reg);
}
