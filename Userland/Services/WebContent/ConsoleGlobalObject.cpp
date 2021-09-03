/*
 * Copyright (c) 2021, Sam Atkins <atkinssj@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "ConsoleGlobalObject.h"
#include <LibWeb/Bindings/WindowObject.h>
#include <LibWeb/DOM/Document.h>
#include <LibWeb/DOM/Window.h>

namespace WebContent {

ConsoleGlobalObject::ConsoleGlobalObject(Web::Bindings::WindowObject& parent_object)
    : m_window_object(&parent_object)
{
}

ConsoleGlobalObject::~ConsoleGlobalObject()
{
}

void ConsoleGlobalObject::visit_edges(Visitor& visitor)
{
    Base::visit_edges(visitor);
    visitor.visit(m_window_object);
}

JS::Object* ConsoleGlobalObject::internal_get_prototype_of() const
{
    return m_window_object->internal_get_prototype_of();
}

bool ConsoleGlobalObject::internal_set_prototype_of(JS::Object* prototype)
{
    return m_window_object->internal_set_prototype_of(prototype);
}

bool ConsoleGlobalObject::internal_is_extensible() const
{
    return m_window_object->internal_is_extensible();
}

bool ConsoleGlobalObject::internal_prevent_extensions()
{
    return m_window_object->internal_prevent_extensions();
}

Optional<JS::PropertyDescriptor> ConsoleGlobalObject::internal_get_own_property(JS::PropertyName const& property_name) const
{
    if (auto result = m_window_object->internal_get_own_property(property_name); result.has_value())
        return result;

    return Base::internal_get_own_property(property_name);
}

bool ConsoleGlobalObject::internal_define_own_property(JS::PropertyName const& property_name, JS::PropertyDescriptor const& descriptor)
{
    return m_window_object->internal_define_own_property(property_name, descriptor);
}

bool ConsoleGlobalObject::internal_has_property(JS::PropertyName const& property_name) const
{
    return Object::internal_has_property(property_name) || m_window_object->internal_has_property(property_name);
}

JS::Value ConsoleGlobalObject::internal_get(JS::PropertyName const& property_name, JS::Value receiver) const
{
    if (m_window_object->has_own_property(property_name))
        return m_window_object->internal_get(property_name, (receiver == this) ? m_window_object : receiver);

    return Base::internal_get(property_name, receiver);
}

bool ConsoleGlobalObject::internal_set(JS::PropertyName const& property_name, JS::Value value, JS::Value receiver)
{
    return m_window_object->internal_set(property_name, value, (receiver == this) ? m_window_object : receiver);
}

bool ConsoleGlobalObject::internal_delete(JS::PropertyName const& property_name)
{
    return m_window_object->internal_delete(property_name);
}

JS::MarkedValueList ConsoleGlobalObject::internal_own_property_keys() const
{
    return m_window_object->internal_own_property_keys();
}

}