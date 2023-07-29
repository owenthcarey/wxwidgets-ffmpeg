//
// Created by Owen Carey on 7/28/23.
//

#include "../include/ffmpegapp.h"

bool FfmpegApp::OnInit() {
    FfmpegFrame *frame = new FfmpegFrame();
    frame->Show();
    return true;
}
