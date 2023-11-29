#include "App.h"
#include "MainFrame.h"
#include "GraphFrame.h"
#include <wx/wx.h>

//Lets wxWidgets know what app represents the application
wxIMPLEMENT_APP(App);

bool App::OnInit(){
    //Creates the window variable, and passes a title to it. 
    MainFrame* mainFrame = new MainFrame("Stock Market Simulator");
    GraphFrame* graphFrame = new GraphFrame("Graph");

    //setting frame size (Final Size TBD) and centering
    mainFrame->SetClientSize(800,600); 
    mainFrame->Center(); 
    graphFrame->SetClientSize(800,600); 
    graphFrame->Center(); 

    //calling the show method on the frame because it does not display by default 
    mainFrame->Show();
    graphFrame->Show();  


    //returns true to tell wxWidgets to continue 
    return true; 
}