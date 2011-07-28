/* $Id: image.cpp 48450 2011-02-08 20:55:18Z mordante $ */
/*
   Copyright (C) 2007 - 2011 by Mark de Wever <koraq@xs4all.nl>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2
   or at your option any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#define GETTEXT_DOMAIN "wesnoth-lib"

#include "gui/auxiliary/widget_definition/image.hpp"

#include "gui/auxiliary/log.hpp"

namespace gui2 {

timage_definition::timage_definition(const config& cfg) :
	tcontrol_definition(cfg)
{
	DBG_GUI_P << "Parsing image " << id << '\n';

	load_resolutions<tresolution>(cfg);
}

timage_definition::tresolution::tresolution(const config& cfg) :
	tresolution_definition_(cfg)
{
/*WIKI
 * @page = GUIWidgetDefinitionWML
 * @order = 1_image
 *
 * == Image ==
 *
 * @macro = image_description
 *
 * The definition of an image. The label field of the widget is used as the
 * name of file to show.
 *
 * The following states exist:
 * * state_enabled, the image is enabled.
 *
 */

	// Note the order should be the same as the enum tstate is image.hpp.
	state.push_back(tstate_definition(cfg.child("state_enabled")));
}

} // namespace gui2

