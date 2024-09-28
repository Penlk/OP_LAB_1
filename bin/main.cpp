#include <iostream>
#include "../lib/Parser.h"
#include "../lib/Functions.h"
#include "../lib/WorkCommands.h"
#include "../lib/Structs/AllStructs.h"
#include <fstream>

int main(int argc, char* argv[])
{
    IsCommands flags;
    ValuesArgs args;
    Parse(argc, argv, flags, args);

    std::ifstream log;
    log.open(args.pathFileLog);
    char buf[1000];
    log.getline(buf, 1000);
    std::cout << buf << std::endl;
    log.getline(buf, 1000);
    std::cout << StringLength(buf) << std::endl;
    log.close();
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
    std::cout << "to: " << flags.to << " values: " << args.toT << '\n';
    return 0;
}
