#include "localdata.h"

//SEE https://stackoverflow.com/questions/1024114/location-of-ini-config-files-in-linux-unix
//and https://ploum.net/207-modify-your-application-to-use-xdg-folders/

ifstream file;
file.open("$XDG_DATA_HOME/example_folder/example_file", ios::binary);

