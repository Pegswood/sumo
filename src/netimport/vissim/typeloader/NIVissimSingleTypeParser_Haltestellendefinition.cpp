/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2018 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    NIVissimSingleTypeParser_Haltestellendefinition.cpp
/// @author  Daniel Krajzewicz
/// @author  Michael Behrisch
/// @date    Wed, 18 Dec 2002
/// @version $Id$
///
//
/****************************************************************************/


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <iostream>
#include <utils/common/TplConvert.h>
#include "../NIImporter_Vissim.h"
#include "../tempstructs/NIVissimClosures.h"
#include "NIVissimSingleTypeParser_Haltestellendefinition.h"


// ===========================================================================
// method definitions
// ===========================================================================
NIVissimSingleTypeParser_Haltestellendefinition::NIVissimSingleTypeParser_Haltestellendefinition(NIImporter_Vissim& parent)
    : NIImporter_Vissim::VissimSingleTypeParser(parent) {}


NIVissimSingleTypeParser_Haltestellendefinition::~NIVissimSingleTypeParser_Haltestellendefinition() {}


bool
NIVissimSingleTypeParser_Haltestellendefinition::parse(std::istream& from) {
    std::string tag;
    while (tag != "strecke") {
        tag = myRead(from);
    }
    while (tag != "laenge") {
        tag = myRead(from);
    }
    from >> tag;
    tag = readEndSecure(from);
    while (tag == "einsteiger" && tag != "DATAEND") {
        while (tag != "linie") {
            tag = myRead(from);
        }
        while (tag != "einsteiger" && tag != "DATAEND") {
            tag = readEndSecure(from);
        }
    }
    return true;
}



/****************************************************************************/

