#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    wxPanel* panel = new wxPanel(this); 
    wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

    //you can bind the event to button, panel, or this(MyFrame) because of event propogation because of the parent
    //child relation the event will go up the chain so in this case if it isn't handled by button it would go to 
    //panel, and then frame, and if it isn't handled then it will go to the app class 

    //now because there are two buttons OnButtonClicked is called when either button is clicked, this is because the commandevents from 
    //button propogate to up to main frame 
    this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);

    //bind for the close event, this does not close the frame though when it is called because the frame is a sub class of wxFrame
    //so when it is handled by MainFrame the wxFrame class does not get to handle it to fix this call the skip method in the OnClose method 
    this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this); 

    //when you click on the buttons these are called but on OnAnyButtonClicked because they were handled before it went up the chain
    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

    //adding separate event handlers for button 1 and 2


    //calling create status bar which is a method inherited from wxFrame status bar is at bottom 
    CreateStatusBar(); 
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt){
    //logs into a message instead of the status bar
    wxLogMessage("Button Clicked"); 
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt){
    wxLogStatus("Button 1 Clicked");

    //if you do not want this event called this tells wxWidgets to continue propogation 
    evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt){
    wxLogStatus("Button 2 Clicked");

    //if you do not want this event called this tells wxWidgets to continue propogation 
    evt.Skip();
}

void MainFrame::OnClose(wxCloseEvent& evt){
    wxLogMessage("Frame Closed");
    evt.Skip();  
}