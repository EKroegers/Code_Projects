#pragma once 
#include <wx/wx.h>

#include <wx/sizer.h>
#include <wx/plotctrl/plotctrl.h>


// Create a color picker control for the user to select the line color
m_colorPicker = new wxColourPickerCtrl(this, wxID_ANY);
inputSizer->Add(m_colorPicker);


class GraphFrame : public wxFrame
{
public:
    GraphFrame(const wxString& title);
    void SetCurveColor(int curveIndex, const wxColour& color);

private:
    wxPlotCtrl* m_plotCtrl;
    wxTextCtrl* m_textCtrl;
    wxButton* m_button;

    void OnButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(GraphFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, GraphFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

GraphFrame::GraphFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480))
{
    // Create the main sizer for the frame
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Create the plot control
    m_plotCtrl = new wxPlotCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPLOTCTRL_DRAWING_BUFFERED);

    // Create the text control and button for user input
    wxBoxSizer* inputSizer = new wxBoxSizer(wxHORIZONTAL);
    m_textCtrl = new wxTextCtrl(this, wxID_ANY);
    m_button = new wxButton(this, wxID_ANY, "Add Point");
    inputSizer->Add(m_textCtrl, wxSizerFlags().Expand().Proportion(1));
    inputSizer->Add(m_button);

    // Add the plot control and input controls to the main sizer
    mainSizer->Add(m_plotCtrl, wxSizerFlags().Expand().Proportion(1));
    mainSizer->Add(inputSizer, wxSizerFlags().Expand().Border(wxTOP, 10));

    // Set the main sizer for the frame
    SetSizer(mainSizer);
}

void GraphFrame::OnButtonClicked(wxCommandEvent& event)
{
    // Get the user input from the text control
    wxString userInput = m_textCtrl->GetValue();

    // Parse the user input as a double
    double userValue = 0.0;
    if (!userInput.ToDouble(&userValue))
    {
        wxMessageBox("Invalid input!", "Error");
        return;
    }

    // Get the selected color from the color picker control
    wxColour color = m_colorPicker->GetColour();

    // Add the user input as a new point on the plot
    int curveIndex = m_plotCtrl->GetCurveCount() - 1;
    m_plotCtrl->AddDataPoint(curveIndex, userValue, wxDateTime::Now());

    // Set the line color for the new curve
    SetCurveColor(curveIndex, color);
}

//main entry point that use wxWidgets library
wxIMPLEMENT_APP_NO_MAIN(MyApp);

class MyApp : public wxApp
{
public:
    virtual bool OnInit() //starts up application
    {
        GraphFrame* frame = new GraphFrame("Graph Demo"); //creates new instance of GraphFrame
        frame->Show();
        return true; //initialization works
    }
};



// Set the line color for each curve
SetCurveColor(0, wxColour(255, 0, 0)); // red
SetCurveColor(1, wxColour(0, 0, 255)); // blue


