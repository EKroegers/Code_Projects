#pragma once 
#include <wx/wx.h>
#include <wx/spinctrl.h> 

class MainFrame : public wxFrame
{
public:
    //Constructor for the main screen the variable that is passed will be displayed as the title
    MainFrame(const wxString& title); 

private: 
    //the button and spin control variables declaration 
    wxSpinCtrl* spinCtrl; 
    wxButton* button; 
    
    //event handler for the button 
    void OnButtonClicked(wxCommandEvent& evt);
};