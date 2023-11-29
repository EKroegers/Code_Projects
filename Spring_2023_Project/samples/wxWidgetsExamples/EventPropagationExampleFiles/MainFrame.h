#pragma once 
#include <wx/wx.h> //imports the most commonly used wx.h files

class MainFrame : public wxFrame
{
//public method for creating frames with only a title variable sets other paramaters to default. 
public: 
    MainFrame(const wxString& title); 

private: 
    //event handler for all buttons 
    void OnAnyButtonClicked(wxCommandEvent& evt); 

    //separate event handlers for button 1 and 2 
    void OnButton1Clicked(wxCommandEvent& evt);
    void OnButton2Clicked(wxCommandEvent& evt);

    //event handler that handles when the window is closed
    void OnClose(wxCloseEvent& evt); 
};