demboyz
=======

we dem boyz

### What is it?

Demboyz is a command line tool to convert TF2 STV demos into a human readable json format. Demboyz runs on Linux, Windows, and OSX.
It supports the following conversions:

    .dem/.json <-> .dem/.json
    .dem/.json -> .con

    The .dem format is the TF2 STV demo format.
    The .json format is the demboyz streaming json demo format.
    The .con format is a log equal to what would be produced by TF2
    with netmessage/demmessage logs enabled.

### Potential Uses
* Exporting Stats: Parsing for player stats and motion throughout maps.
* Anticheat: Interpreting player net data for malicious behavior and cheating
* Anti-Anticheat: Modifying player net data to hide your malicious behaviour and cheating
* Censoring: Cover up rude communication by removing player voice and chat messages
* Social engineering: Make your friends seem rude by adding phony player voice and chat messages
* ConeBone69 revival: Change the names of all players to ConeBone69

### Usage

    ./demboyz mystvdemo.dem mystvdemo.json
    ./demboyz mystvdemo.dem mystvdemo.con
    ./demboyz mystvdemo.json mystvdemo.dem
    ./demboyz mystvdemo.json mystvdemo.con

In the first example, mystvdemo.dem will be read from the current working directory, while mystvdemo.json will be written to the current working directory.

## Compiling From Source

When following instructions below, the compiled binary will be output in the bin folder.


### Using Vagrant

    # Launch VM and build
    vagrant up

    # Patch VM and re-build
    vagrant provision

    # Manual build
    vagrant ssh
    cd /vagrant/premake
    ./gmake.sh && cd gmake
    make

    # Disconnect session and stop VM
    exit
    vagrant halt

### With Visual Studio 2013

    # Generate vs 2013 project
    cd premake
    vs2013.bat
    
Open generated VS solution at premake/vs2013/demboyz.sln
