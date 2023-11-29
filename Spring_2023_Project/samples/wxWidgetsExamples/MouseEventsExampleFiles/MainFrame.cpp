#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this); 
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100)); 
    
    
    //detects if the left mouse button is clicked 
    //to change to right change LEFT to Right 
    //to change to middle button change LEFT to MIDDLE
    //to change for double clicks change DOWN to DCLICK
    //panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);

    //for mouse movement 
    panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
    
    //with this button there when tracking mouse movement when you hover over the button the mouse movement within the button 
    //is not detected because the wxMouseEvent is not a command event so it does not propagate to handle this you must
    //explicetly call bind on it, but the position is relative to the control that the cusor is over 
    // when the cursor is over the button the cords are relative to the button 
    button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);

    //to fix flickering on the status bar put it in a variable and enable double buffering 
    wxStatusBar* statusBar = CreateStatusBar(); 
    statusBar->SetDoubleBuffered(true);
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt){
    //getting the mouse position from the evt variable 
    wxPoint mousePos = evt.GetPosition(); 

    //if you want to get the mouse position no matter the objectects you can use this method 
    //this gets the cords for the whole screen so it matters where the client is 
    //wxPoint mousePos = wxGetMousePosition(); 

    //if you want to convert from screen cords to client cords use this method 
    //mousePos = this->ScreenToClient(); 

    //if you want to convert from client cords to screen cords 
    //mousePos = this->ClientToScreen();

    //creating formatted string containing the position 
    wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y); 
    wxLogStatus(message); 
}