# TDF

### Compile

Mac / Linux / Cygwin

```
make
```

Windows

```
mingw32-make main
```

### Points of Interest

Look at [`main.c`](https://github.com/SamyBencherif/TDF/blob/master/main.c) to see "client-code", where a test program is put together and executed.

Check out [`object-model.h`](https://github.com/SamyBencherif/TDF/blob/master/object-model.h) to see most of the behind the scenes stuff.

Peruse [`device-config.h`](https://github.com/SamyBencherif/TDF/blob/master/device-config.h) to gain an understanding of available test instructions / signals / modes / devices.

Finally, and this one is important for low-level implementation. Have a look at [`device-ins.h`](](https://github.com/SamyBencherif/TDF/blob/master/device-ins.h) to see where hardware level code would go.

### TODO / notes

A lot of these header files need to be split into source files which contain implementations and header files that contain function signatures.

### Contact

Please leave an issue on this repo if you have questions. Otherwise, if you are in the organization, you can contact me via Slack.
