//---------------------------------------------------------------------------

//#pragma hdrstop

#include "UCola.h"
#include <vcl.h>

typedef int Tipo;
const Max=50;
class Cola{
		private:
			Tipo V[Max+1];
			int Frente,Atras;
		public:
				Cola();
				// Produce un Self vac?o
				void Meter(Tipo dato);
				//Pre: La cola no est? llena
				//Inserta el dato al final de la Cola

				void Sacar(Tipo &dato);
				//Pre: La cola no est? vac?a
				// Obtiene en dato el primer elemento de la Cola, elimin?ndolo  de la misma.
				int SacarUltimo();

				int SacarUnEle(Tipo &dato);

				bool Vacia();
				// Retorna true si y solo si la Cola est? vac?a, y false en caso contrario.
				bool  Llena();
				// Retorna true si y solo si la Cola est? llena, y false en caso contrario.
				int Cant();
				//Retorna la cantidad de elementos del Self
				void Borrar();
				//Pre: La cola no est? vac?a
				// Borrar el primer elemento de la Cola
				Tipo Primero();
				// Retorna el primer elemento de la Cola
				String toString();
};

Cola::Cola(){
// Produce un Self vac?o
	Frente=Atras=-1;
}

void Cola::Meter(Tipo dato){
	if (Llena()) {
		ShowMessage("Error Cola llena");
		exit(1);
	}

	if((Frente==-1)&&(Atras==-1)){ // 1er inserci?n cuando la cola est? vac?a
		Frente=Atras=0;
		V[Atras]= dato;
	}
	else{
		Atras++;
		if (Atras>Max)
			Atras=0;
		V[Atras]=dato;
	}
}

void Cola::Sacar(Tipo &dato){
//Pre: La cola no est? vac?a
// Obtiene en dato el primer elemento de la Cola, elimin?ndolo  de la misma.

	if (Vacia()) {
		ShowMessage("Error: Cola vac?a");
		exit(1);
	}

	dato = V[Frente];
	if(Frente==Atras)
		Frente=Atras=-1;
	else{
		Frente++;
		if(Frente>Max)
			Frente=0;
	}
}

bool Cola::Vacia(){
// Retorna true si y solo si la Cola est? vac?a, y false en caso contrario.
	return((Frente==-1)&&(Atras==-1));
}

bool  Cola::Llena(){
// Retorna true si y solo si la Cola est? llena, y false en caso contrario.
   int aux = Atras;
   aux++;
   if (aux>Max)
		aux=0;
   return (aux==Frente);

}
/*bool Cola::Llena(){
	return (Cant()==Max+1);
} */

int Cola::Cant(){
//Retorna la cantidad de elementos del Self
	if(Atras>=Frente)
		return (Atras-Frente+1);
	else
		return(Atras+1)+(Max-Frente+1);
}

void Cola::Borrar(){
//Pre: La cola no est? vac?a
// Borrar el primer elemento de la Cola
	if (Vacia()) {
		ShowMessage("Error: Cola vac?a");
		exit(1);
	}
	if(Frente==Atras)
		Frente=Atras=-1;
	else{
		Frente++;
		if(Frente>Max)
			Frente=0;
	}
}
Tipo Cola::Primero(){
// Retorna el primer elemento de la Cola
	if (Vacia()) {
		ShowMessage("Error: Cola vac?a");
		exit(1);
	}

	return V[Frente];
}
Tipo Cola::SacarUltimo()
{
	if (Vacia())
	{
		ShowMessage("Error: Cola vac?a");
		exit(1);
	}
	return V[Atras];
}
Tipo Cola::SacarUnEle(Tipo &dato)
{
	if (Frente==Atras)
	{
		if (Frente==dato)
		{
			return V[Frente];
		}
	}else
	{   int aux=Frente-1;
		if (aux<Max)
		{
			aux++;
			if (dato==V[aux]) {
                return V[aux];
			}
		}
	}
}
String Cola::toString(){
	String cad="";
	int k = Frente;
	while(k!=Atras){
		cad = cad + IntToStr(V[k])+" , ";
		k++;
		if(k>Max)
			k=0;
	}
	cad = cad + IntToStr(V[Atras]);
	return cad;
}

//---------------------------------------------------------------------------
//#pragma package(smart_init)
