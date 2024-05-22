#include <iostream>
#include <stdexcept>
// #include <cstdio> // For the FILE handle
#include <memory>  // Don't forget to include this header for smart pointers
#include <fstream> // For std::fstream

#include <format>

class DatabaseConnection
{
private:
    // char *buffer;       // Raw pointer for database connection data
    std::unique_ptr<char[]> buffer;
    // std::FILE *logFile; // Raw FILE handle for logging
    std::fstream logFile;

public:
    DatabaseConnection() : buffer(std::make_unique<char[]>(1024)), logFile("dbLog.txt", std::ios::out | std::ios::app)
    {
        std::cout << "Attempting to open database connection." << std::endl;

        // If opening the log file fails, throw an exception
        if (!logFile)
        {
            throw std::runtime_error("Failed to open log file");
        }
        logFile << "Added text\n";
        //logFile << std::format("Length {}\n", logFile.tellg());
        int size = logFile.tellg();
        logFile << std::format("Length {}\n", size);

        // Simulate another potential issue after opening the file
        throw std::runtime_error("Failed to connect to database");
    }
    /*
    ~DatabaseConnection()
    {
        std::cout << "Closing database connection.\n";
        // delete[] buffer;      // Memory deallocation for the database connection data
        // std::fclose(logFile); // Closing the log file handle
    }
    */
};

void simulateDatabaseOperation()
{
    try
    {
        DatabaseConnection dbConn;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateDatabaseOperation();
    return 0;
}