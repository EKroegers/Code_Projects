#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    //adding the wxWANTS_CHARS to the panel will allow for global key events to be handled 
    wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS); 
    wxButton* btn1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300,150), wxSize(200,100));
    wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300,350), wxSize(200,100));

    //detects if there is a key pressed 
    //if you press a key when there are buttons on the screen nothing will seems to happen because key events only
    //send to the control which only has focus and does not propagate you can change focus with arron keys or tab 

    //when you are focused on the first button and press a key the event will be handled, but a sound will be played, 
    //to get rid of this sound add the style wxWANTS_CHARS to the button that tells wxWidgets we want to handle events 
    //for all keys including tab and arrow keys this is not ideal because the functionallity of the tab/arrow key is disabled 
    //btn1->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

    //for global key press event no matter what the focus is on 
    panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

    //detects if a key was released
    //panel->Bind(wxEVT_KEY_UP, &MainFrame::OnKeyEvent, this);

    //detects if a key was pressed like wxEVT_KEY_DOWN but will do combinations like shift+a 
    //panel->Bind(wxEVT_CHAR, &MainFrame::OnKeyEvent, this);

    CreateStatusBar(); 
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt){
    //Uncomment block code to see checks for certain keys
    //how to check for certain keys 
    //Use uppercase characters otherwise it won't work and for special you need the keycode 
   /*if (evt.GetUnicodeKey() == 'A'){
        wxLogStatus("A was pressed");
    //checking for the home key using the wxWidgets enums for certain keys even though the code is 313 for WXK_HOME
    } else if (evt.GetKeyCode() == WXK_HOME){
        wxLogStatus("HOME was pressed");
    }
    return; */

    //to maintain the functionallity of the change of focus for the tab and arrow keys you can check if those buttons were 
    //pressed 
    if (evt.GetKeyCode() == WXK_TAB){
        //grabbing the window pointer
        wxWindow* window = (wxWindow*)evt.GetEventObject(); 
        //resetting the navigate 
        window->Navigate(); 
    }

    //there are two methods for getting what key was pressed
    //use this only for all printable characters so letters, numbers, and characters
    //for all other keys such as enter and capslock it returns WXK_NONE
    wxChar keyChar = evt.GetUnicodeKey(); 

    if (keyChar == WXK_NONE){
        //prints the key codes for other keys like enter, capslock, but some keys like arrows do not have key codes
        int keyCode = evt.GetKeyCode(); 
        wxLogStatus("Key Event %c", keyChar); 
    } else {
        //displays a message when the user presses a printable character on the keyboard
        wxLogStatus("Key Event %c", keyChar); 
    }

    
}
