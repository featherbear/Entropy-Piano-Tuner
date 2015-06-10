/*****************************************************************************
 * Copyright 2015 Haye Hinrichsen, Christoph Wick
 *
 * This file is part of Entropy Piano Tuner.
 *
 * Entropy Piano Tuner is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Entropy Piano Tuner is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Entropy Piano Tuner. If not, see http://www.gnu.org/licenses/.
 *****************************************************************************/

#ifndef QTCONFIG_H
#define QTCONFIG_H

#include "core/config.h"

#include <QtGlobal>

// define mobile/desktop version defines
#if defined Q_OS_BLACKBERRY || defined Q_OS_ANDROID || defined Q_OS_IOS || defined Q_OS_WP
#define Q_OS_MOBILE
#else
#define Q_OS_DESKTOP
#endif

#if CONFIG_DIALOG_SIZE == 2
#   define SHOW_DIALOG(d) {(d)->showMaximized();}
#elif CONFIG_DIALOG_SIZE == 3
#   define SHOW_DIALOG(d) {(d)->showFullscreen();}
#else
#   define SHOW_DIALOG(d) {(d)->showNormal();}
#endif

// icons for menu?
#if __APPLE__
#   define CONFIG_MENU_ICONS 0
#else
#   define CONFIG_MENU_ICONS 1
#endif

// update check
#if defined Q_OS_DESKTOP && !defined Q_OS_MACX
#   define CONFIG_ENABLE_UPDATE_TOOL     1
#endif

#endif // QTCONFIG_H

