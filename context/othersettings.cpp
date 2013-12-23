/*
 * Cantata
 *
 * Copyright (c) 2011-2013 Craig Drummond <craig.p.drummond@gmail.com>
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

#include "othersettings.h"
#include "settings.h"
#include "onoffbutton.h"

OtherSettings::OtherSettings(QWidget *p)
    : QWidget(p)
{
    setupUi(this);
    connect(wikipediaIntroOnly, SIGNAL(toggled(bool)), SLOT(toggleWikiNote()));
}

void OtherSettings::load()
{
    wikipediaIntroOnly->setChecked(Settings::self()->wikipediaIntroOnly());
    contextBackdrop->setChecked(Settings::self()->contextBackdrop());
    contextDarkBackground->setChecked(Settings::self()->contextDarkBackground());
    contextAlwaysCollapsed->setChecked(Settings::self()->contextAlwaysCollapsed());
    toggleWikiNote();
}

void OtherSettings::save()
{
    Settings::self()->saveWikipediaIntroOnly(wikipediaIntroOnly->isChecked());
    Settings::self()->saveContextBackdrop(contextBackdrop->isChecked());
    Settings::self()->saveContextDarkBackground(contextDarkBackground->isChecked());
    Settings::self()->saveContextAlwaysCollapsed(contextAlwaysCollapsed->isChecked());
}

void OtherSettings::toggleWikiNote()
{
    wikipediaIntroOnlyNote->setOn(!wikipediaIntroOnly->isChecked());
}
