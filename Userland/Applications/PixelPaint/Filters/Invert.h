/*
 * Copyright (c) 2022, Tobias Christiansen <tobyase@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "Filter.h"

namespace PixelPaint::Filters {

class Invert final : public Filter {
public:
    virtual void apply() const override;
    virtual StringView filter_name() override { return "Invert"sv; }

    Invert(ImageEditor* editor)
        : Filter(editor) {};
};

}
