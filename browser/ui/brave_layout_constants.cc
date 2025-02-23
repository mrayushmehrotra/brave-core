/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/brave_layout_constants.h"

#include "brave/browser/ui/tabs/features.h"
#include "chrome/browser/ui/layout_constants.h"
#include "ui/base/pointer/touch_ui_controller.h"

using tabs::features::HorizontalTabsUpdateEnabled;

// Returns a |nullopt| if the UI color is not handled by Brave.
absl::optional<int> GetBraveLayoutConstant(LayoutConstant constant) {
  const bool touch = ui::TouchUiController::Get()->touch_ui();
  // const bool hybrid = mode == ui::MaterialDesignController::MATERIAL_HYBRID;
  // const bool touch_optimized_material =
  //     ui::MaterialDesignController::touch_ui();
  // const bool newer_material =
  //     ui::MaterialDesignController::IsNewerMaterialUi();
  switch (constant) {
    case TAB_HEIGHT: {
      const int tab_height = HorizontalTabsUpdateEnabled() ? 36 : 30;
      return (touch ? 41 : tab_height) +
             GetLayoutConstant(TABSTRIP_TOOLBAR_OVERLAP);
    }
    case TABSTRIP_TOOLBAR_OVERLAP: {
      if (!HorizontalTabsUpdateEnabled()) {
        return absl::nullopt;
      }
      return 0;
    }
    case TAB_SEPARATOR_HEIGHT: {
      return 24;
    }
    case LOCATION_BAR_HEIGHT:
      return touch ? 36 : 34;
    default:
      break;
  }
  return absl::nullopt;
}
