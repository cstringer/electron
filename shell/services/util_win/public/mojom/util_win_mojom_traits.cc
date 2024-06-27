// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "shell/services/util_win/public/mojom/util_win_mojom_traits.h"

#include <utility>

#include "base/notreached.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "mojo/public/cpp/base/file_path_mojom_traits.h"
#include "mojo/public/cpp/base/string16_mojom_traits.h"
#include "mojo/public/cpp/base/wstring_mojom_traits.h"

namespace mojo {

// static
util_win::mojom::SelectFileDialogType EnumTraits<
    util_win::mojom::SelectFileDialogType,
    ui::SelectFileDialog::Type>::ToMojom(ui::SelectFileDialog::Type input) {
  switch (input) {
    case ui::SelectFileDialog::Type::SELECT_NONE:
      return util_win::mojom::SelectFileDialogType::kNone;
    case ui::SelectFileDialog::Type::SELECT_FOLDER:
      return util_win::mojom::SelectFileDialogType::kFolder;
    case ui::SelectFileDialog::Type::SELECT_UPLOAD_FOLDER:
      return util_win::mojom::SelectFileDialogType::kUploadFolder;
    case ui::SelectFileDialog::Type::SELECT_EXISTING_FOLDER:
      return util_win::mojom::SelectFileDialogType::kExistingFolder;
    case ui::SelectFileDialog::Type::SELECT_SAVEAS_FILE:
      return util_win::mojom::SelectFileDialogType::kSaveAsFile;
    case ui::SelectFileDialog::Type::SELECT_OPEN_FILE:
      return util_win::mojom::SelectFileDialogType::kOpenFile;
    case ui::SelectFileDialog::Type::SELECT_OPEN_MULTI_FILE:
      return util_win::mojom::SelectFileDialogType::kOpenMultiFile;
  }
  NOTREACHED_IN_MIGRATION();
  return util_win::mojom::SelectFileDialogType::kNone;
}

// static
bool EnumTraits<util_win::mojom::SelectFileDialogType,
                ui::SelectFileDialog::Type>::
    FromMojom(util_win::mojom::SelectFileDialogType input,
              ui::SelectFileDialog::Type* output) {
  switch (input) {
    case util_win::mojom::SelectFileDialogType::kNone:
      *output = ui::SelectFileDialog::Type::SELECT_NONE;
      return true;
    case util_win::mojom::SelectFileDialogType::kFolder:
      *output = ui::SelectFileDialog::Type::SELECT_FOLDER;
      return true;
    case util_win::mojom::SelectFileDialogType::kUploadFolder:
      *output = ui::SelectFileDialog::Type::SELECT_UPLOAD_FOLDER;
      return true;
    case util_win::mojom::SelectFileDialogType::kExistingFolder:
      *output = ui::SelectFileDialog::Type::SELECT_EXISTING_FOLDER;
      return true;
    case util_win::mojom::SelectFileDialogType::kSaveAsFile:
      *output = ui::SelectFileDialog::Type::SELECT_SAVEAS_FILE;
      return true;
    case util_win::mojom::SelectFileDialogType::kOpenFile:
      *output = ui::SelectFileDialog::Type::SELECT_OPEN_FILE;
      return true;
    case util_win::mojom::SelectFileDialogType::kOpenMultiFile:
      *output = ui::SelectFileDialog::Type::SELECT_OPEN_MULTI_FILE;
      return true;
  }
  NOTREACHED_IN_MIGRATION();
  return false;
}

// static
bool StructTraits<util_win::mojom::FileFilterSpecDataView, ui::FileFilterSpec>::
    Read(util_win::mojom::FileFilterSpecDataView input,
         ui::FileFilterSpec* out) {
  return input.ReadDescription(&out->description) &&
         input.ReadExtensionSpec(&out->extension_spec);
}

}  // namespace mojo
