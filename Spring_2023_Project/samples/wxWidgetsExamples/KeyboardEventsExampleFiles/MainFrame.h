#pragma once 
#include <wx/wx.h> //imports the most commonly used wx.h files

class MainFrame : public wxFrame
{
//public method for creating frames with only a title variable sets other paramaters to default. 
public: 
    MainFrame(const wxString& title); 

private: 
    //all key events must take wxKeyEvent as a param 
    void OnKeyEvent(wxKeyEvent& evt); 
};