#include "AF.cpp"

class Generador{
	protected:
		string reg_exp;
		AFN automata;
	
	public:
		Generador(string exp){
			reg_exp = exp;
			AFN = AFN();
		}
};
