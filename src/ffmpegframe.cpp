//
// Created by Owen Carey on 7/28/23.
//

#include "../include/ffmpegframe.h"
#include <wx/filedlg.h>

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
    // Set layout and other components...
    outputDirectoryCtrl = new wxDirPickerCtrl(this, wxID_ANY);
    outputFileNameCtrl = new wxTextCtrl(this, wxID_ANY);
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
