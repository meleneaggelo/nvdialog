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

#ifndef __nvdialog_h__
#define __nvdialog_h__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "nvdialog_types.h"

#define NVDIALOG_VERSION_MAJOR 0
#define NVDIALOG_VERSION_MINOR 1
#define NVDIALOG_VERSION_PATCH 1

/**
 * @brief Returns the version of nvdialog currently linked with.
 * For a compile time alternative implementation see the
 * NVDIALOG_VERSION_MAJOR, NVDIALOG_VERSION_MINOR and NVDIALOG_VERSION_PATCH
 * constants.
 */
NvdVersion nvd_get_version();

#ifndef __nvdialog_core_included__
#include "nvdialog_core.h"
#include "nvdialog_dialog.h"
#include "nvdialog_types.h"
#include "nvdialog_error.h"
#endif  /* __nvdialog_core_included__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __nvdialog_h__ */