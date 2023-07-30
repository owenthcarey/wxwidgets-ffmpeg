//
// Created by Owen Carey on 7/28/23.
//

#include "../include/ffmpegframe.h"

wxBEGIN_EVENT_TABLE(FfmpegFrame, wxFrame)
                EVT_BUTTON(wxID_EXECUTE, FfmpegFrame::OnCompress)
                EVT_BUTTON(wxID_EXIT, FfmpegFrame::OnExit)
wxEND_EVENT_TABLE()

FfmpegFrame::FfmpegFrame() : wxFrame(NULL, wxID_ANY,
                                     "wxWidgets FFmpeg Video Compressor",
                                     wxDefaultPosition, wxSize(800, 600)) {
    filePickerCtrl = new wxFilePickerCtrl(this, wxID_ANY);
    resolutionCtrl = new wxTextCtrl(this, wxID_ANY);
    bitrateCtrl = new wxTextCtrl(this, wxID_ANY);
    formatCtrl = new wxComboBox(this, wxID_ANY);
    outputDirectoryCtrl = new wxDirPickerCtrl(this, wxID_ANY);
    outputFileNameCtrl = new wxTextCtrl(this, wxID_ANY);

    wxButton *compressButton = new wxButton(this, wxID_EXECUTE, "Compress");
    wxButton *exitButton = new wxButton(this, wxID_EXIT, "Exit");

    wxFlexGridSizer *gridSizer = new wxFlexGridSizer(2, 5, 5);
    gridSizer->AddGrowableCol(1, 1);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Input File:"));
    gridSizer->Add(filePickerCtrl, 1, wxEXPAND);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Resolution:"));
    gridSizer->Add(resolutionCtrl, 1, wxEXPAND);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Bitrate:"));
    gridSizer->Add(bitrateCtrl, 1, wxEXPAND);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Format:"));
    gridSizer->Add(formatCtrl, 1, wxEXPAND);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Output Directory:"));
    gridSizer->Add(outputDirectoryCtrl, 1, wxEXPAND);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Output File Name:"));
    gridSizer->Add(outputFileNameCtrl, 1, wxEXPAND);

    wxBoxSizer *boxSizer = new wxBoxSizer(wxVERTICAL);
    boxSizer->Add(gridSizer, 1, wxALL | wxEXPAND, 15);
    boxSizer->Add(compressButton, 0, wxALL | wxALIGN_CENTER, 15);
    boxSizer->Add(exitButton, 0, wxALL | wxALIGN_CENTER, 15);
    SetSizer(boxSizer);
}

void FfmpegFrame::OnCompress(wxCommandEvent &WXUNUSED(event)) {
    wxString input = filePickerCtrl->GetPath();
    wxString outputDirectory = outputDirectoryCtrl->GetPath();
    wxString outputFileName = outputFileNameCtrl->GetValue();
    wxString output = outputDirectory + "/" + outputFileName + ".mp4";
    wxString command =
            "ffmpeg -i " + input + " -vcodec libx264 -crf 23 " + output;
    if (wxExecute(command, wxEXEC_SYNC) != -1) {
        wxMessageBox("Compression completed successfully!", "Info",
                     wxOK | wxICON_INFORMATION);
    } else {
        wxMessageBox(
                "Compression failed. Please check the console for more details.",
                "Error", wxOK | wxICON_ERROR);
    }
}

void FfmpegFrame::OnExit(wxCommandEvent &WXUNUSED(event)) {
    Close(true);
}
