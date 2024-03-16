#include "MainFrame.h"
MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){
    //creates a panel object as a child of the frame class to be able to format other objects in the window 
    wxPanel* panel = new wxPanel(this); 

    //static text to tell the user what to do 
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY,
     "Enter the number of years you would like to run the simulation for (1-10), and then hit the enter button",
     wxPoint(120, 150));

    //adding a button it is center on the screen 
    button = new wxButton(panel, wxID_ANY, "Enter", wxPoint(350,250), wxSize(100, 35));

    //adding the spot for the user to input the number of years they would like the simulation to run 
    spinCtrl = new wxSpinCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(350, 200), wxSize(100, -1), wxSP_ARROW_KEYS, 1, 10, 1);

    //binding the button to the event handler 
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
    
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt){
    // Get the value of the spin control
    int value = spinCtrl->GetValue();

    // Displaying the value 
    wxMessageBox(wxString::Format("The value is %d", value), "Value");
}

