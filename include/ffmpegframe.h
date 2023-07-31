//
// Created by Owen Carey on 7/28/23.
//

#ifndef WXWIDGETS_FFMPEG_FFMPEGFRAME_H
#define WXWIDGETS_FFMPEG_FFMPEGFRAME_H

#include <wx/filedlg.h>
#include <wx/filepicker.h>
#include <wx/wx.h>

class FfmpegFrame : public wxFrame {
public:
    FfmpegFrame();

private:
    wxFilePickerCtrl *filePickerCtrl;
    wxTextCtrl *resolutionCtrl;
    wxTextCtrl *bitrateCtrl;
    wxSlider *crfSlider;
    wxComboBox *formatCtrl;
    wxDirPickerCtrl *outputDirectoryCtrl;
    wxTextCtrl *outputFileNameCtrl;
    wxGauge *gauge;
    void OnCompress(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};


#endif //WXWIDGETS_FFMPEG_FFMPEGFRAME_H
