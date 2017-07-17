# Logger
- generic Logger C++ tool
- log to console, file, both or nothing

using:
- namespace `logging`

- set Logger to the required Logger:  
    `Logger::makeLogger("file", "../log.txt");`
    
- the debug level is the minimal level for debug output  
    `Logger::setDebugLevel(Logger::INTERMEDIATE);`
    
- log with `out << "log"`

- change local debug level for all following output:  
    `out << Logger::HIGH << "high debug level \n";`
