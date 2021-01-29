#!/bin/bash

# Prerequisites: install xidel
# download: http://videlibri.sourceforge.net/xidel.html#downloads
# Xpath format 2.0

# Common data from https://github.com/broderickhyman/ao-bin-dumps
# direct link: https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml

# Info regarding cluster zones (maps)
{ echo "Id,Name,Type" ; xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/fn:concat(@id, ",", @displayname, ",", @type)' 2> /dev/null | sed 's/PSG-/toDelete/2' | sed -E 's/[0-9]{4}/toDelete/2' | sed '/toDelete/d'; } > static-maps.csv

# Info regarding exits (portals)
{ echo "Origin,Destination" ; xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/exits/exit[ fn:matches(@targettype, "^Cluster$") ]/fn:concat(../../@id, ",", fn:substring-after(@targetid, "@"))' 2> /dev/null | sed -n -E '/^[0-9]{4};[0-9]{4}$/p'; } > static-portals.csv

# Alternate URL: https://raw.githubusercontent.com/broderickhyman/ao-bin-dumps/master/cluster/world.xml
