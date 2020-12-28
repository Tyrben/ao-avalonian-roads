# ao-avalonian-roads

[![CMake](https://github.com/Tyrben/ao-avalonian-roads/workflows/CMake/badge.svg)](https://github.com/Tyrben/ao-avalonian-roads/actions)

Multiple tools to import info about Albion Online avalonian roads and portals, search for shortest paths, merge data...

This project is ment to work with any source of data as long as we can load it. Currently a system of Google Forms and Google Sheets are used to fill in informations regarding Avalonian portals and Avalonion roads. The interface is a Google webservice. But it can be easily extended to other source of information, online or offline.

One licence concern was taken in consideration: to work on information shared "around the table" (as SandBox says). It is the case. This software is more a tool than a frontend (where all eyes are focused).

[learn more...]()

## Build
The building system is based on cmake and any C++ compiler. It was tested on Linux and Windows but should work on other configurations too.

This projet is composed of a series of elements: static librairies, apps, tests... but the main element is the end user gps command line.

[learn more...]()

## Usage

    ao-avalonian-roads-gps command [--parameter=value ...]

### Command list

* `route`
  * `origin`: exact name of the map of origin
  * `destination`: exact name of the map of origin

### Example

    ao-avalonian-roads-gps route --origin="Bridgewatch" --destination="Casos-Aiagsum"

## Contributing

### Coding
The gps application inside this project is just one part, but the visible part. The choice of C++ was a question of available skills. But it can be transposed to any other ecosystem.

Free to you to participate to this project or to create your own. We would be glad to hear about your project in the future.

### Documentation - Promotion
This project is born in a small guild between few persons. It responds to some needs, but it was tought with a capacity of expansion and genericity.

Up to you to speak of this project around you, to fix our documentations, or to fork this project.

### Feedback
The Github issue system allows you to participate. You can write end-user feedbacks, bug reports, expectations...

Or write in-code reviews, remarks, retake proposals...

[learn more...](docs/CONTRIBUTING.md)

## Evolution
It is planed to be extended with a GUI. Maybe to make the bridge to [Portaler](https://github.com/Portaler-Zone/portaler-core), another ao mature project.
