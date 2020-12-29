# ao-avalonian-roads

[![CMake](https://github.com/Tyrben/ao-avalonian-roads/workflows/CMake/badge.svg)](https://github.com/Tyrben/ao-avalonian-roads/actions)

__ao-avalonian-roads-gps__ is a command line tool to search routes into Albion Online Avalonian roads.

To be functionnal, it uses 2 sources of data:
- the Royal continent and Black Zone map list and gate list
- a list of currently discovered Avalonian maps and bindings between them

It was tested successfully on Linux and Windows.

[learn more...](docs/more-info.md)

## Build
The building system is based on CMake and any C++ compiler. It was built on Linux and Windows but should work on other configurations too.

This projet is composed of a series of elements: static librairies, apps, tests... but the main element is the end user GPS command line, located in /app.

### Linux, WSL or Cygwin

    mkdir build
    cd build
    cmake ..
    make

### Windows Visual Studio

    mkdir build
    cd build
    cmake ..

Open the .sln in Visual Studio.

## Usage

    ao-avalonian-roads-gps command [--parameter=value ...]

### Command list

* `route`
  * `origin`: exact name of the map of origin
  * `destination`: exact name of the map of destination

### Example

    ao-avalonian-roads-gps route --origin="Bridgewatch" --destination="Casos-Aiagsum"

## Fill in information

This project is based on informations manually entered by the user (and co). Two forms are available (English version).

### Avalonian maps
[Form to fill in map info](https://docs.google.com/forms/d/e/1FAIpQLScVv3Lxkc8Ig-DpTYPW92ihbiDzNodOCFTfyFT0qQySbeywHg/viewform?usp=sf_link)

### Avalonian portals
[Form to fill in portals](https://docs.google.com/forms/d/e/1FAIpQLSdcBWO9uP78dlcKFj9s_kiUqFDD-Sl5X0OVbl3WwXdN7EwFqw/viewform?usp=sf_link)

## Contributing

You can contrubute to this project eather by coding, managing the project, writing documentation, promoting it outside or just by using it and making feedbacks.

Look at the project tab on GitHub, its where the project is managed. Also look at the Issues tab, it's where you can report a problem.

[learn more...](docs/CONTRIBUTING.md)

## Evolution
It is planed to extend it with a GUI. Also to make the bridge to [Portaler](https://github.com/Portaler-Zone/portaler-core), another ao mature project.
