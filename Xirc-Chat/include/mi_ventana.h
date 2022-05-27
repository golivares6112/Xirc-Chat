#ifndef MI_VENTANA_H
#define MI_VENTANA_H


#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class Mi_ventana : public wxFrame
{
public:
    Mi_ventana(const wxString & titulo,
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


#endif

enum { ID_Salir = 1, ID_Saludar };
BEGIN_EVENT_TABLE(Mi_ventana, wxFrame)
	EVT_BUTTON(ID_Saludar, Mi_ventana::EnSaludar)
	EVT_BUTTON(ID_Salir, Mi_ventana::EnSalir)
END_EVENT_TABLE()

//declaracion o implementacion de las funciones y constructores  de la clase mi ventana
Mi_ventana::Mi_ventana(const wxString & titulo,
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
void Mi_ventana::EnSalir(wxCommandEvent & WXUNUSED(evento))
{
	Close(TRUE);
}

void Mi_ventana::EnSaludar(wxCommandEvent & WXUNUSED(evento))
{
	wxMessageBox("Hola, Mundo con wxWidgets!!!",
			"Hola, Mundo",
			wxOK | wxICON_INFORMATION,
			this);
}

