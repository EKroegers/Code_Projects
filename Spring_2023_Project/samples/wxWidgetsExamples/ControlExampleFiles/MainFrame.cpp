#include "MainFrame.h"
#include <wx/spinctrl.h> //just for spin control 
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title) {
    // wxWidgets if only has one child in the frame then it will make the child stretch to fill the whole frame so we need a panel to 
    // put the button in, now because this panel is the only child of the frame it will stretch to fill the whole frame and the 
    // button will go where we positioned it because we made the button a child of this class
    // origin of the app is top left corner and (x,y) values increase as you go (down, right) 
    wxPanel* panel = new wxPanel(this); 

    // Button (reference to parent, id value, text in button, position of top left corner of button, size of button px)
    wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150,50), wxSize(100, 35));

    // CheckBox(reference to parent, id value, text to the right of the box, position)
    wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550,55));

    //Static text (reference to parent, id value, text, position) 
    wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(120, 150)); 

    //Text Control (reference to parent, id value, initial text, position, size) (-1 means default) wxSize default is wxSize(-1,-1)
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200,-1));

    //Slider (reference to parent, id value, slider initial value, slider minimun value, slider max value, position, size)
    wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0 , 100, wxPoint(100, 250), wxSize(200, -1));

    //Gauge (reference to parent, id value, range for gauge, position, size) not interactable vaule set from code
    wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));

    //setting gauge value to 50 
    gauge->SetValue(50);

    //setting choices for the user to choose the amount the bar is set using wxArrayString class but can also use a 
    //normal array if you want 
    wxArrayString choices; 
    choices.Add("Item A"); 
    choices.Add("Item B"); 
    choices.Add("Item C"); 

    //using wxChoice control to choose between the above options 
    //Choice (reference to parent, id value, position, size, array to choose from (if use normal array must pass number of strings and the 
    //array itself))
    wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);

    //sets default selection by using the index in the array of the default item you want to be selected
    choice->Select(0);

    //Spin Control (allows users to select a number within a given range)
    //(reference to parent, id value, inital text, position, size, (can also do min, max, and initial values but using defaults here)
    wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

    //List box (reference to parent, id value, position, size, array to choose from (if use normal array must pass number of strings and the 
    //array itself)) this is dynamic so strings can be added and removed at run time 
    wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

    //Radio Box (reference to parent, id value, title, position, size, array of choices)
    wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);

    //we Dynamically allocated all these controls using the new oporator which is how it should be never allocate 
    //on the stack like this wxButton button2(panel, wxID_ANY, "Button2"); b/c can cause problems 

    //do not have to worry about deallocating the memory for these controls because the main frame will be deleted and it will
    //delete all of the children and its children etc. 
}