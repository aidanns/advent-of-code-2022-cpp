//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef DAY_ONE_PARSER_H
#define DAY_ONE_PARSER_H

#include <vector>
#include <fstream>

#include "Elf.h"

namespace AdventOfCode {

    class DayOneParser {
    public:
        [[nodiscard]] static std::vector<Elf> parseFile(const std::string& inputFilePath) ;
    };

} // AdventOfCode

#endif // DAY_ONE_PARSER_H
