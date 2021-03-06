/*
 * Cantata
 *
 * Copyright (c) 2011-2014 Craig Drummond <craig.p.drummond@gmail.com>
 *
 * ----
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "filesettings.h"
#include "settings.h"

FileSettings::FileSettings(QWidget *p)
    : QWidget(p)
{
    setupUi(this);

    #ifdef Q_OS_MAC
    expandingSpacer->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);
    #endif
}

void FileSettings::load()
{
    storeCoversInMpdDir->setChecked(Settings::self()->storeCoversInMpdDir());
    storeLyricsInMpdDir->setChecked(Settings::self()->storeLyricsInMpdDir());
    storeBackdropsInMpdDir->setChecked(Settings::self()->storeBackdropsInMpdDir());
}

void FileSettings::save()
{
    Settings::self()->saveStoreCoversInMpdDir(storeCoversInMpdDir->isChecked());
    Settings::self()->saveStoreLyricsInMpdDir(storeLyricsInMpdDir->isChecked());
    Settings::self()->saveStoreBackdropsInMpdDir(storeBackdropsInMpdDir->isChecked());
}

