//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrincipal.h"
#include "UCola.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Cola Q;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Q.Vacia())
		ShowMessage("La Cola est? vac?a");
	else
		ShowMessage("La Cola no est? vac?a");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (Q.Llena())
		ShowMessage("La Cola est? llena");
	else
		ShowMessage("La Cola no est? llena");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Tipo val = StrToInt(InputBox("Entrada","Ingrese valor: ","0"));
	Q.Meter(val);
	Edit1->Text = Q.toString();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Tipo x;
	Q.Sacar(x);
	ShowMessage("El elemento extraido es: "+IntToStr(x));
	Edit1->Text=Q.toString();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	ShowMessage("La cantidad de elementos es:" + IntToStr(Q.Cant()));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Q.Borrar();
	Edit1->Text=Q.toString();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	ShowMessage("El primer elemento de la Cola es: " + IntToStr(Q.Primero()));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Tipo s;
	s=Q.SacarUltimo();
	ShowMessage("El elemento extraido es: "+IntToStr(s));
	//Edit1->Text=Q.toString();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Tipo z;
	z= StrToInt(InputBox("Entrada","Ingrese valor: ","0"));
	Q.SacarUnEle(z);
	ShowMessage("El elemento extraido es: "+IntToStr(z));
	Edit1->Text=Q.toString();

}
//---------------------------------------------------------------------------

