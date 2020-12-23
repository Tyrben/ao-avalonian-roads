#!/bin/bash

# Prerequisites: install xidel
#http://videlibri.sourceforge.net/xidel.html#downloads

# Data commun from https://github.com/broderickhyman/ao-bin-dumps
# direct link: https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml

xidel world.xml -e 'concat(/world/clusters/cluster[@id="1206"]/@id , ";", /world/clusters/cluster[@id="1206"]/@displayname)'

xidel /mnt/d/git/autres/ao-bin-dumps/cluster/world.xml -e 'concat(/world/clusters/cluster[number(@id)<9999]/@displayname, ";", /world/clusters/cluster[number(@id)<9999]/@id)'

#xpath 2.0
xidel /mnt/d/git/autres/ao-bin-dumps/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^[0-9]{4}$") ]/@id'

# Info regarding cluster zones (maps)
xidel /mnt/d/git/autres/ao-bin-dumps/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^(PSG-)?[0-9]{4}$") ]/fn:concat(@id, ";", @displayname, ";", @type)' 2> /dev/null

# Info regarding exists (portals)
xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^[0-9]{4}$") ]/exits/exit[fn:matches(@targettype, "^Cluster$")]/fn:concat(../../@id, ";", fn:substring-after(@targetid, "@"))'

xidel https://github.com/broderickhyman/ao-bin-dumps/raw/master/cluster/world.xml -e '/world/clusters/cluster[ fn:matches(@id, "^[0-9]{4}$") ]/exits/exit[ fn:matches(@targettype, "^Cluster$") ]/fn:concat(../../@id, ";", fn:substring-after(@targetid, "@"))' 2> /dev/null | sed -n '/^[0-9][0-9]*;[0-9][0-9]*$/p'

#TODO PSG-0000 is correct, that are the passages (also maps)
