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
    // Input settings
    wxFlexGridSizer *inputSettingsSizer = new wxFlexGridSizer(2, 5, 5);
    inputSettingsSizer->AddGrowableCol(1, 1);

    filePickerCtrl = new wxFilePickerCtrl(this, wxID_ANY);
    inputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Input File:"));
    inputSettingsSizer->Add(filePickerCtrl, 1, wxEXPAND);

    // Output settings
    wxStaticBox* outputSettingsBox = new wxStaticBox(this, wxID_ANY, "Output Settings");
    wxStaticBoxSizer* outputSettingsSizer = new wxStaticBoxSizer(outputSettingsBox, wxVERTICAL);

    outputDirectoryCtrl = new wxDirPickerCtrl(this, wxID_ANY);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Output Directory:"));
    outputSettingsSizer->Add(outputDirectoryCtrl, 0, wxALL | wxEXPAND, 5);

    outputFileNameCtrl = new wxTextCtrl(this, wxID_ANY);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Output File Name:"));
    outputSettingsSizer->Add(outputFileNameCtrl, 0, wxALL | wxEXPAND, 5);

    resolutionCtrl = new wxTextCtrl(this, wxID_ANY);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Video Resolution:"), 0, wxALL, 5);
    outputSettingsSizer->Add(resolutionCtrl, 0, wxALL | wxEXPAND, 5);

    bitrateCtrl = new wxTextCtrl(this, wxID_ANY);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Video Bitrate:"), 0, wxALL, 5);
    outputSettingsSizer->Add(bitrateCtrl, 0, wxALL | wxEXPAND, 5);

    crfSlider = new wxSlider(this, wxID_ANY, 23, 0, 51);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Video CRF:"), 0, wxALL, 5);
    outputSettingsSizer->Add(crfSlider, 0, wxALL | wxEXPAND, 5);

    formatCtrl = new wxComboBox(this, wxID_ANY);
    outputSettingsSizer->Add(new wxStaticText(this, wxID_ANY, "Video Format:"), 0, wxALL, 5);
    outputSettingsSizer->Add(formatCtrl, 0, wxALL | wxEXPAND, 5);

    // Group all sizers together
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(inputSettingsSizer, 1, wxALL | wxEXPAND, 15);
    mainSizer->Add(outputSettingsSizer, 1, wxALL | wxEXPAND, 15);
    wxButton *compressButton = new wxButton(this, wxID_EXECUTE, "Compress");
    mainSizer->Add(compressButton, 0, wxALL | wxALIGN_CENTER, 15);
    wxButton *exitButton = new wxButton(this, wxID_EXIT, "Exit");
    mainSizer->Add(exitButton, 0, wxALL | wxALIGN_CENTER, 15);
    SetSizer(mainSizer);
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
