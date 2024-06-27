// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_SERVICES_UTIL_WIN_PUBLIC_MOJOM_UTIL_WIN_MOJOM_TRAITS_H_
#define ELECTRON_SHELL_SERVICES_UTIL_WIN_PUBLIC_MOJOM_UTIL_WIN_MOJOM_TRAITS_H_

#include <string>

#include "base/files/file_path.h"
#include "shell/services/util_win/public/mojom/util_win.mojom-shared.h"
#include "ui/shell_dialogs/execute_select_file_win.h"

namespace mojo {

template <>
struct EnumTraits<util_win::mojom::SelectFileDialogType,
                  ui::SelectFileDialog::Type> {
  static util_win::mojom::SelectFileDialogType ToMojom(
      ui::SelectFileDialog::Type input);
  static bool FromMojom(util_win::mojom::SelectFileDialogType input,
                        ui::SelectFileDialog::Type* output);
};

template <>
struct StructTraits<util_win::mojom::FileFilterSpecDataView,
                    ui::FileFilterSpec> {
  static const std::u16string& description(const ui::FileFilterSpec& input) {
    return input.description;
  }
  static const std::u16string& extension_spec(const ui::FileFilterSpec& input) {
    return input.extension_spec;
  }

  static bool Read(util_win::mojom::FileFilterSpecDataView data,
                   ui::FileFilterSpec* output);
};

}  // namespace mojo

#endif  // ELECTRON_SHELL_SERVICES_UTIL_WIN_PUBLIC_MOJOM_UTIL_WIN_MOJOM_TRAITS_H_
