# qtm-calc

qtm-calc is a tool that allows you to calculate the final states and some operational characteristics of a multi-channel queuing system.

## Build

1. First of all make sure you have the Boost library installed on your system (see more [Boost installation on Windows](https://www.boost.org/doc/libs/1_75_0/more/getting_started/windows.html) or [Boost installation on *nix](https://www.boost.org/doc/libs/1_75_0/more/getting_started/unix-variants.html));

2. Clone this project and then cd to the project folder;

3. Configure the project using CMake:
```
cmake -B ./build -G <preferred generator>
```

4. Then run build command:
```
cmake --build ./build --config <Debug|Release>
```

5. You've done! The builded binary file available in the build directory.

## Usage

For this program to work, you need a json file with the specified basic characteristics of the queuing system of the following form:
```jsonc
{
    "channel_count": , // number of system channels
    "queue_size": , // number of places in the queue
    "la": , // input flow rate
    "mu": , // output flow rate
    "nu": , // impatience indicator (optional parameter)
    "n": // number of load sources (optional parameter)
}
```

The result will be placed in a json file with the following structure:
```jsonc
{
    "final_states": {
        "1": ,
        "2": ,
        "3": ,
        // further for each final state
    },
    "avg_queue": , // average queue length
    "ete": , // system efficiency
    "avg_time_queue": , // average queue time
    "perc_served_req": , // percentage of served requests 
    "count_served_req": , // average number of served requests
    "avg_count_req": // average number of requests
}

```

To run the program, enter:
```
qtm-calc <input json file> <output json file>
```

## License

This project is licensed under the [MIT License](LICENSE).

## Credits

My thanks to the developers of the Boost library.

Especial thanks to [IceArrow256](https://github.com/IceArrow256) and [HanGerrel](https://github.com/HanGerrel) for help in writing computing algorithms and code structuring.