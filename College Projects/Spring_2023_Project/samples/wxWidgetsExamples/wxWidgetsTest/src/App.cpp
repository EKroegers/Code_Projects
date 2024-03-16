#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h> 

//Lets wxWidgets know what app represents the application using this macro 
wxIMPLEMENT_APP(App);

bool App::OnInit(){
    //Creates the window variable, and passes a title to it. 
    MainFrame* mainFrame = new MainFrame("Stock Market Simulator");

    //setting frame size and centering
    mainFrame->SetClientSize(800,600); 
    mainFrame->Center(); 

    //calling the show method on the frame because it does not display by default 
    mainFrame->Show(); 

    //returns true to tell wxWidgets to continue 
    return true; 
}