#pragma once 
#include <wx/wx.h> //imports the most commonly used wx.h files

class MainFrame : public wxFrame
{
//public method for creating frames with only a title variable sets other paramaters to default. 
public: 
    MainFrame(const wxString& title); 

private: 
    //event handler can be called whatever you would like but needs to take a param of class wxCommandEvent& 
    //which contains information about the event
    //most event handers take wxCommandEvent& variables, but some use different variables 
    void OnButtonClicked(wxCommandEvent& evt); 

    //event hander for when slider changes value 
    void OnSliderChanged(wxCommandEvent& evt);

    //event hander for when the text in textCtrl changes 
    void OnTextChanged(wxCommandEvent& evt);
};