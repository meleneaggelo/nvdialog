/*
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2022 Aggelos Tselios
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "nvdialog_error.h"
#include <stdio.h>
#ifndef _WIN32
#include "backend/nvdialog_adw.h"
#include "backend/nvdialog_gtk.h"
#endif /* _WIN32 */

#if defined(_WIN32)
#include "backend/nvdialog_win32.h"
#endif /* _WIN32 */

#include "nvdialog.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct NvdDialogBox {
        void *window_handle;
        const char *msg;
        const char *content;
        NvdDialogType type;
};

int nvd_init(char *program) {
        int __argc__ = 1;
        char **__argv__ = {
            &program,
        };
#ifndef _WIN32
        if (!getenv("DISPLAY")) {
                nvd_set_error(NVD_NO_DISPLAY);
                NVD_PRINT_CURRENT_ERROR;
                return -1;
        }
        gtk_init(&__argc__, &__argv__);
#endif /* _WIN32 */
        return 0;
}

const char *nvd_open_file_dialog_new(const char *title,
                                     const char *file_extensions) {
#if !defined(_WIN32)
        const char *data = nvd_open_file_dialog_gtk(title, file_extensions);
        return data;
#else
        return nvd_open_file_dialog_win32(title, file_extensions);
#endif /* _WIN32 */
}

NvdDialogBox *nvd_dialog_box_new(const char *title, const char *message,
                                 NvdDialogType type) {
#if !defined(_WIN32)
        NvdDialogBox *dialog = nvd_create_gtk_dialog(title, message, type);
        if (!dialog) nvd_set_error(NVD_INTERNAL_ERROR);
        return dialog;
#else
        nvd_create_win32_dialog(title, message, type);
#endif /* _WIN32 */
}

NvdReply nvd_dialog_question_new(const char* title,
                                 const char *question,
                                 NvdQuestionButton button)
{
        #if !defined(_WIN32)
        return nvd_question_gtk(title, question, button);
        #else
        nvd_question_win32(title, question, button);
        #endif /* _WIN32 */
        return -1;
}