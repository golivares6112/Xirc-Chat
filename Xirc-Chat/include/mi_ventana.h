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

};

#endif


//declaracion o implementacion de las funciones y constructores  de la clase mi ventana
Mi_ventana::Mi_ventana(const wxString & titulo,
		const wxPoint & pos,
		const wxSize & tamano):
		wxFrame((wxFrame *) NULL, -1, titulo, pos, tamano)
{
	//create a panel to pass to our windows
	wxPanel *panel_top = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel_top ->SetBackgroundColour(wxColor(100, 100, 200));

	wxPanel *panel_bottom = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel_bottom->SetBackgroundColour(wxColor(100, 200, 200));

	wxPanel *panel_bottom_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel_bottom_right->SetBackgroundColour(wxColor(200, 200, 100));

	wxBoxSizer * sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(panel_top, 1, wxEXPAND | wxLeft | wxTop |wxRight, 10);

	wxBoxSizer *sizer_bottom = new wxBoxSizer(wxHORIZONTAL);

	sizer_bottom->Add(panel_bottom, 1, wxEXPAND | wxRight, 10);
	sizer_bottom->Add(panel_bottom_right, 0, wxEXPAND, 0);


	sizer->Add(sizer_bottom, 1, wxEXPAND | wxALL, 10);


	this->SetSizerAndFit(sizer);

}


