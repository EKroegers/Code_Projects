#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    // wxWidgets if only has one child in the frame then it will make the child stretch to fill the whole frame so we need a panel to 
    // put the button in, now because this panel is the only child of the frame it will stretch to fill the whole frame and the 
    // button will go where we positioned it because we made the button a child of this class
    // origin of the app is top left corner and (x,y) values increase as you go (down, right) 
    wxPanel* panel = new wxPanel(this); 

    //Creating a button using the button_ID variable 
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));

    //Creating a slider using the SLIDER_ID variable 
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1)); 

    //Creating a slider using the SLIDER_ID variable 
    wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1)); 

    //Instead of using a event table we are going to use binds 
    //bind comes from a class wxEVT_HANDLER which every control inherits from 
    //Event handler can be a class method, a functor, or an ordinary function 
    //Every event creates multiple events so we can specify which one we are interested in by using an event tag 
    //We need a pointer to the method so that is why there is an & in front of the class name 
    //The last "this" is a pointer to the object that will handle the event so OnButtonClicked will be called on this instance of MyFrame
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    //to know what event tag to use look at documentation 
    slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this); 

    text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this); 

    //to remove bindings Unbind(takes same params as bind) 
    button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    //try and always use dynamic event handling it is more powerful and easier to read/code. 

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