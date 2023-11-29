
#include "GraphFrame.h"
#include <wx/wx.h>



GraphFrame::GraphFrame(const wxString& title, const std::vector<double>& data, double daily_return)
    : wxFrame(nullptr, wxID_ANY, title), m_daily_return(daily_return)
{
    // Create a panel as a child of the frame
    wxPanel* panel = new wxPanel(this);

    // Create a vertical box sizer for the panel
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // Create a plot control and add it to the sizer
    wxPlotCtrl* plotCtrl = new wxPlotCtrl(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPLOTCTRL_DRAWING_BUFFERED);
    vbox->Add(plotCtrl, wxSizerFlags().Expand().Proportion(1));

    // Set the background color of the plot control
    plotCtrl->SetBackgroundColour(wxColour(255, 255, 255));

    // Create a horizontal box sizer for the user input controls
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    // Create a text control for the user input and add it to the sizer
    wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY);
    hbox->Add(textCtrl, wxSizerFlags().Expand().Proportion(1));

    // Create a button for adding the user input as a point on the plot and add it to the sizer
    wxButton* addButton = new wxButton(panel, wxID_ANY, "Add Point");
    hbox->Add(addButton, wxSizerFlags());

    // Add the user input sizer to the main sizer
    vbox->Add(hbox, wxSizerFlags().Expand().Border(wxTOP, 10));

    // Set the panel sizer
    panel->SetSizer(vbox);

    // Bind the button to the event handler
    addButton->Bind(wxEVT_BUTTON, &GraphFrame::OnAddPoint, this);

    // Draw the graph
    wxClientDC dc(panel);
    dc.SetBackground(wxBrush(plotCtrl->GetBackgroundColour()));
    dc.Clear();
    DrawGraph(dc, data);
}


void GraphFrame::OnAddPoint(wxCommandEvent& event)
{
    // Get the user input from the text control
    wxString userInput = dynamic_cast<wxTextCtrl*>(FindWindowById(wxID_ANY)) ->GetValue();

    // Parse the user input as a double
    double userValue = 0.0;
    if (!userInput.ToDouble(&userValue))
    {
        wxMessageBox("Invalid input!", "Error");
        return;
    }

    // Add the user input as a new point on the plot
    wxPlotCtrl* plotCtrl = dynamic_cast<wxPlotCtrl*>(FindWindowById(wxID_ANY));
    plotCtrl->AddDataPoint(plotCtrl->GetCurveCount() - 1, userValue, wxDateTime::Now());
}->GetCurveCount() - 1, userValue, wxDateTime::Now());
}

void GraphFrame::DrawGraph(wxDC& dc, const std::vector<double>& data)
{
    int w, h;
    dc.GetSize(&w, &h);

    // Calculate the minimum and maximum values of the data
    double min_val = *std::min_element(data.begin(), data.end());
    double max_val = *std::max_element(data.begin(), data.end());

    // Calculate the y-scale of the graph
    double y_scale = (h - 40) / (max_val - min_val);

    // Calculate the x-scale of the graph
    double x_scale = (w - 40) / (data.size() - 1);

    // Calculate the daily return of the stock
    double daily_return = (data.back() - data.front()) / data.front() * 100.0;

    // Set the pen and brush colors based on the daily return
    wxPen pen(m_daily_return >= 0 ? wxColour(0, 255, 0) : wxColour(255, 0, 0), 1);
    wxBrush brush(m_daily_return >= 0 ? wxColour(0, 255, 0) : wxColour(255, 0, 0), wxBRUSHSTYLE_TRANSPARENT);

    dc.SetPen(pen);
    dc.SetBrush(brush);

    // Draw the graph line
    dc.DrawLines(data.size(), GetGraphPoints(data, min_val, y_scale, x_scale));

    // Draw the x and y axis
    dc.DrawLine(20, h - 20, w - 20, h - 20);
    dc.DrawLine(20, 20, 20, h - 20);
}

//addedfor .h file
void GraphFrame::SetCurveColor(int curveIndex, const wxColour& color)
{
    m_plotCtrl->SetCurveColour(curveIndex, color);
}

// Set the pen and brush colors based on the daily return
wxPen pen(wxColour(0, 0, 0), 1);
wxBrush brush(m_daily_return >= 0 ? wxColour(0, 255, 0) : wxColour(255, 0, 0));

dc.SetPen(pen);
dc.SetBrush(brush);
