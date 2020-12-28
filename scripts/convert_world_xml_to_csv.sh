#!/bin/bash

# Prerequisites: install xidel
# download: http://videlibri.sourceforge.net/xidel.html#downloads
# Xpath format 2.0

# Common data from https://github.com/broderickhyman/ao-bin-dumps
# direct link: https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml

# Info regarding cluster zones (maps)
xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/fn:concat(@id, ";", @displayname, ";", @type)' 2> /dev/null

{ echo "Title1;Title2" ; xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/exits/exit[ fn:matches(@targettype, "^Cluster$") ]/fn:concat(../../@id, ";", fn:substring-after(@targetid, "@"))' 2> /dev/null | sed -n '/^[0-9][0-9]*;[0-9][0-9]*$/p' | tail; } > static-maps.csv

# Info regarding exits (portals)
xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/exits/exit[ fn:matches(@targettype, "^Cluster$") ]/fn:concat(../../@id, ";", fn:substring-after(@targetid, "@"))' 2> /dev/null | sed -n '/^[0-9][0-9]*;[0-9][0-9]*$/p'
