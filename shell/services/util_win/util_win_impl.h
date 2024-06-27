// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_SERVICES_UTIL_WIN_UTIL_WIN_IMPL_H_
#define ELECTRON_SHELL_SERVICES_UTIL_WIN_UTIL_WIN_IMPL_H_

#include <memory>
#include <string>
#include <vector>

#include "base/files/file_path.h"
#include "shell/services/util_win/public/mojom/util_win.mojom.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/receiver.h"

class UtilWinImpl : public util_win::mojom::UtilWin {
 public:
  explicit UtilWinImpl(mojo::PendingReceiver<util_win::mojom::UtilWin> receiver);

  UtilWinImpl(const UtilWinImpl&) = delete;
  UtilWinImpl& operator=(const UtilWinImpl&) = delete;

  ~UtilWinImpl() override;

 private:
  // util_win::mojom::UtilWin:
  void CallExecuteSelectFile(ui::SelectFileDialog::Type type,
                             uint32_t owner,
                             const std::u16string& title,
                             const base::FilePath& default_path,
                             const std::vector<ui::FileFilterSpec>& filter,
                             int32_t file_type_index,
                             const std::u16string& default_extension,
                             CallExecuteSelectFileCallback callback) override;

  mojo::Receiver<chrome::mojom::UtilWin> receiver_;
};

#endif  // ELECTRON_SHELL_SERVICES_UTIL_WIN_UTIL_WIN_IMPL_H_
