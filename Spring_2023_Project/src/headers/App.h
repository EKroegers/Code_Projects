#pragma once 
#include <wx/wx.h> 

class App : public wxApp
{   
    //overrides the OnInit function which will make the screens run 
    bool OnInit();
};