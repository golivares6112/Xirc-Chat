#include "../include/mi_ventana.h"

class Myapp : public wxApp
{
    public:
        virtual bool OnInit(); //metodo de tipo booleano y virtual (se declara virtual por que este se puede sobrecargar en otras clases) para invocar a la ventana MiVentana
};

bool Myapp::OnInit()
{
   Mi_ventana * frame = new Mi_ventana("Layouts Testing",
					wxPoint(600,200),
					wxSize(640,480));
	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}



wxIMPLEMENT_APP(Myapp);




