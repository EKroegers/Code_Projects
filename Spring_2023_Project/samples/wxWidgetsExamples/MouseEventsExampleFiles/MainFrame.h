#pragma once 
#include <wx/wx.h> //imports the most commonly used wx.h files

class MainFrame : public wxFrame
{
//public method for creating frames with only a title variable sets other paramaters to default. 
public: 
    MainFrame(const wxString& title); 

private:
    //event handler for mouse events
    void OnMouseEvent(wxMouseEvent& evt); 
};