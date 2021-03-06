Logger {#logger_guide}
======

Aynchronous logging is built into the YAGE library, which can be used to log events in the game
and also debug the game by using the debug output that the game engine produces. This can help
if for example, a texture is being loaded.

Log levels
----------

The logger has five different levels that can be assigned to a message. These are, from lowest to
highest severity, DEBUG, INFO, WARNING, ERROR and FATAL, which are of type @ref yage::LogLevel. 
Messages that the developer then wants to write to the logs can take any of these severities 
and the developer can then decide what the minimum severity is that 
the logger should log. By default, the logger will log anything that is above @ref yage::LogLevel::INFO.

Using the Logger in your Game
-----------------------------

There are a few preprocessor definitions to make the use of the logger as simple as possible.
First of all, there is a definition to get the instance of the current global logger, which
can then be used to set a different minimum display level. This definition is `yLogger`, and an
example of how to use it to change the default output level can be seen below

```
yLogger.setLevel(yage::LogLevel::ERROR);
```

The above code changes the global logger so that it will only output things that are an error or
fatal and make the engine crash.


Other preprocessor definitions are `yLogDebug`, `yLogInfo`, `yLogWarning`, `yLogError` and
`yLogFatal`. These return an object that is similar to a buffer, but belongs to the main
global logger `yLogger`. These are the definitions that should be used to print somehting
to the main logger. For example

```
yLogWarning << "This is a warning";
```

will print the message "This is a warning" with the severity of `LogLevel::WARNING`.
