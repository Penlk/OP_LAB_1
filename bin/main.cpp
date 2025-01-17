#include <iostream>
#include "../lib/Parser.h"
#include "../lib/Functions.h"
#include "../lib/Structs/AllStructs.h"
#include "../lib/ParserLog.h"
#include <time.h>

int main(int argc, char* argv[])
{
    long long times = time(0);
    IsCommands flags;
    ValuesArgs args;

    if(Parse(argc, argv, flags, args))
        return 1;

    ParserLog(flags, args);
   
    //std::cout << list.length << " " << list.index;

    // log.getline(buf, 1000);
    // std::cout << buf << std::endl;
    // log.getline(buf, 1000);
    // std::cout << StringLength(buf) << std::endl;
    // std::cout << TranslateTime(31, "Feb", 1992, 2, 59, 59);
    if (args.pathFileOutput != nullptr) {
        std::cout << "output: " << flags.output << " values: " << args.pathFileOutput << '\n';
    }
    else {
        std::cout << "output: " << flags.output << " values: " << 0 << '\n';
    }
    if (args.pathFileLog != nullptr) {
        std::cout << "log: " << flags.log << " values: " << args.pathFileLog << '\n';
    }
    else {
        std::cout << "log: " << flags.log << " values: " << 0 << '\n';
    }
    std::cout << "print: " << flags.print << '\n';
    std::cout << "stats: " << flags.stats << " values: " << args.statsN << '\n';
    std::cout << "window: " << flags.window << " values: " << args.windowT << '\n';
    std::cout << "from: " << flags.from << " values: " << args.fromT << '\n';
    std::cout << "to: " << flags.to << " values: " << args.toT << "\n\n";
    std::cout << "ALLTIME: " << time(0) - times << std::endl;
    return 0;
}
