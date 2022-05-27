//programa de muesta para entender como funciona wxWidget


//1ero incluimos la libreria wx/wxprec
#include <wx/wxprec.h>


//para compiladores que aceptan pre-compilacion se  incluye wx/wx.h
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif



//creamos una clase que herede de wxApp en C++ para heredar desde una clase a otra se invoca escribiendo | : public <NOMBRE CLASE A HEREDAR>
class MiAplicacion : public wxApp
{
    public:
        virtual bool OnInit(); //metodo de tipo booleano y virtual (se declara virtual por que este se puede sobrecargar en otras clases) para invocar a la ventana MiVentana
};


//creamos la clase ventana donde vamos a definir, botones, listas, textbox, menues, controles en general 
class MiVentana : public wxFrame
{
public:
    MiVentana(const wxString & titulo,
                const wxPoint & pos,
                const wxSize & tamano); //constructor de la clase mi ventana

        void EnSalir(wxCommandEvent & evento);
        void EnSaludar(wxCommandEvent & evento);
        DECLARE_EVENT_TABLE()
private:
        wxPanel  *m_Panel;
        wxButton * m_btnSaludar;
        wxButton * m_btnSalir;
};


//tabla de eventos ojo esto es re importante, establece una relacion entre el identificador declarado y la accion que le pertenece
enum { ID_Salir = 1, ID_Saludar };
BEGIN_EVENT_TABLE(MiVentana, wxFrame)
	EVT_BUTTON(ID_Saludar, MiVentana::EnSaludar)
	EVT_BUTTON(ID_Salir, MiVentana::EnSalir)
END_EVENT_TABLE()

/*
    IMPORTANTE : la macro wxIMPLEMENT_APP() reemplaza a tener una funcion main desde donde llamar a nuestra clase MiAplicacion
    por ejemplo :

    int main()
    {
        Mi
        return 0;
    }
*/
wxIMPLEMENT_APP(MiAplicacion); //es como int main() blablablabla.....



// Implementacion o desarrollo de las funciones de cada clase, programamos toda la funcionalidad de las clases
bool MiAplicacion::OnInit()
{
   MiVentana * cuadro = new MiVentana("Hola, Mundo!",
					wxPoint(50,50),
					wxSize(300,200));
	cuadro->Show(TRUE);
	SetTopWindow(cuadro);
	return TRUE;
}


//declaracion o implementacion de las funciones y constructores  de la clase mi ventana
MiVentana::MiVentana(const wxString & titulo,
		const wxPoint & pos,
		const wxSize & tamano):
		wxFrame((wxFrame *) NULL, -1, titulo, pos, tamano)
{
	wxSize tamanoPanel = GetClientSize();
	m_Panel = new wxPanel(this, -1, wxPoint(0,0), tamanoPanel);
	int al = tamanoPanel.GetHeight();
	int an = tamanoPanel.GetWidth();

	m_btnSaludar = new wxButton(m_Panel,
				   ID_Saludar, _T("Saludos"),
				   wxPoint(an/2 - 80, al/2 - 35),
				   wxSize(70, 30));

	m_btnSalir = new wxButton(m_Panel,
				  ID_Salir, _T("Salir"),
				  wxPoint(an/2 + 10, al/2 - 35),
				  wxSize(70, 30));
}

//implementacion de las funciones, acciones de los botones
void MiVentana::EnSalir(wxCommandEvent & WXUNUSED(evento))
{
	Close(TRUE);
}

void MiVentana::EnSaludar(wxCommandEvent & WXUNUSED(evento))
{
	wxMessageBox("Hola, Mundo con wxWidgets!!!",
			"Hola, Mundo",
			wxOK | wxICON_INFORMATION,
			this);
}
