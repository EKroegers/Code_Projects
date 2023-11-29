#include "MainFrame.h"
#include <wx/wx.h>

//ENUM for custom ID's 
//ID's must 1) must be positive, 2) cannot be 0 or 1, 3) cannot be from wxID_LOWEST(4999) to wxID_HIGHEST(5999)
enum IDs{
    BUTTON_ID = 2,
    SLIDER_ID = 3,
    TEXT_ID = 4
};

//making the event table takes 2 params (class defining event table for, base class)
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    //needs to know the id of the button and the method to invoke
    //the event table only knows the ID of the button and does not even know the button exists
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)

    //calls event handler when slider value changes 
    EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)

    //calls event handler when the text in the text control changes 
    EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    // wxWidgets if only has one child in the frame then it will make the child stretch to fill the whole frame so we need a panel to 
    // put the button in, now because this panel is the only child of the frame it will stretch to fill the whole frame and the 
    // button will go where we positioned it because we made the button a child of this class
    // origin of the app is top left corner and (x,y) values increase as you go (down, right) 
    wxPanel* panel = new wxPanel(this); 

    //Creating a button using the button_ID variable 
    wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));

    //Creating a slider using the SLIDER_ID variable 
    wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1)); 

    //Creating a slider using the SLIDER_ID variable 
    wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1)); 

    //calling create status bar which is a method inherited from wxFrame status bar is at bottom 
    CreateStatusBar(); 


}

void MainFrame::OnButtonClicked(wxCommandEvent& evt){
    //when button is clicked displaying text in the status bar using wxLogStatus
    wxLogStatus("Button Clicked"); 
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt){
    //creating formatted string using wxFormatString method 
    //This displays some text and the slider value which is gotten from the event variable 
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt()); 

    //shows result in the status bar 
    wxLogStatus(str); 
}

void MainFrame::OnTextChanged(wxCommandEvent& evt){
    //creating formatted string using wxFormatString method 
    //This displays some text and the text variable 
    wxString str = wxString::Format("Text: %s", evt.GetString()); 

    //shows result in the status bar 
    wxLogStatus(str); 
}