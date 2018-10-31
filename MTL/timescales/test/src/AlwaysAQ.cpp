#include "iostream"

#include "array"
#include "csv.h"

#include "MonitorAlwaysAQ.hpp"

int main(int argc, char **argv){

    int p, q;
    bool output;

    if (argc < 1) {
        std::cout <<  "ERROR: No input file" << std::endl;
        return 0;
    }

    auto monitor = MonitorAlwaysAQ<int>();

    io::CSVReader<2> reader(argv[1]);
    reader.read_header(io::ignore_extra_column, "p", "q");
    
    while(reader.read_row(p, q)){
        monitor.update(p, q);
        output = monitor.output();
        if(not output){
            std::cout << "Violation at time " << monitor.now << std::endl;
        }
    }

    return 0;
}
