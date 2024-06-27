// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "shell/services/util_win/util_win_impl.h"

#include <objbase.h>

#include <shldisp.h>
#include <wrl/client.h>

#include <string>
#include <string_view>
#include <utility>

#include "base/files/file_enumerator.h"
#include "base/files/file_path.h"
#include "base/functional/bind.h"
#include "base/path_service.h"
#include "base/scoped_native_library.h"
#include "base/strings/utf_string_conversions.h"
#include "base/win/scoped_bstr.h"
#include "base/win/scoped_com_initializer.h"
#include "base/win/scoped_variant.h"
#include "base/win/win_util.h"
#include "ui/shell_dialogs/execute_select_file_win.h"

UtilWinImpl::UtilWinImpl(mojo::PendingReceiver<util_win::mojom::UtilWin> receiver)
    : receiver_(this, std::move(receiver)) {}

UtilWinImpl::~UtilWinImpl() = default;

void UtilWinImpl::CallExecuteSelectFile(
    ui::SelectFileDialog::Type type,
    uint32_t owner,
    const std::u16string& title,
    const base::FilePath& default_path,
    const std::vector<ui::FileFilterSpec>& filter,
    int32_t file_type_index,
    const std::u16string& default_extension,
    CallExecuteSelectFileCallback callback) {
  base::win::ScopedCOMInitializer scoped_com_initializer;

  base::win::EnableHighDPISupport();

  ui::ExecuteSelectFile(
      type, title, default_path, filter, file_type_index,
      base::UTF16ToWide(default_extension),
      reinterpret_cast<HWND>(base::win::Uint32ToHandle(owner)),
      std::move(callback));
}

